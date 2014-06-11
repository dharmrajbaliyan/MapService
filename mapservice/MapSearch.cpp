#include "MapSearch.h"
#include "GeoLocation.h"
#include <map>
#include <cassert>

using namespace std;

MapSearch::MapSearch(string dataFile) {
	FILE* fh = fopen(dataFile.c_str(), "r");
	if(fh == NULL) {
		assert(0);
	}
	initMap(fh);
}

void MapSearch::initMap(FILE* fh) {
	assert(fh != NULL);
	map<double, int> stripIdx;
	int count = 0;
	char line[1024] = {0};	
	while(fgets(line, 1024, fh)) {
		double lat1, lng1, lat2, lng2;
	   	float w;
		int id = 0;
		sscanf(line ,"%d %lf %lf %lf %lf %f", &id, &lat1, &lng1, &lat2, &lng2, &w);
		
		Cell cell(id, lat1, lng1, lat2, lng2, w, w);
		map<double, int>::const_iterator itr = stripIdx.find(lat1);
		if(itr != stripIdx.end()) {
			strips[itr->second].cells.push_back(cell);
		} else {
			Strip strip(lat1, lat2);
			strip.cells.push_back(cell);
			strips.push_back(strip);
			stripIdx[lat1] = count;
			++count;
		}
	}
}
vector<int> MapSearch::findStrips(const double lat1, const double lat2) const {
	if(lat1 > lat2) {
		printf("lat1 cannot be greater than lat2\n");
		assert(0);
	}	
	if(lat1 > 180 || lat1 < -180 || lat2 > 180 || lat2 < -180) {
		printf("Latitude range is [-180, 180], input is %lf %lf\n", lat1, lat2);
		assert(0);
	}
	int idx = findStrip(lat1);
	printf("%s found strip %d\n", __FUNCTION__, idx);
	vector<int> result;
	if(idx == -1) {
		//return empty result and log error
		printf("no strip found which intersect with %lf %lf\n", lat1, lat2);
	} else { 
		result.push_back(idx);	
		//find if any strip before idx fits in 
		for(int i=idx-1; i>=0; --i) {
			if(lat1 > strips[i].endLatitude) break;
			result.push_back(i);	
		}
		//find if any stip after idx fits in
		for(int i=idx+1; i<strips.size(); ++i) {
			if(lat2 < strips[i].endLatitude) break;
			result.push_back(i);	
		}
	}
	printf("Total strips computed for %lf %lf is %d\n", lat1, lat2, result.size());
	return result;
}

int MapSearch::findStrip(const double lat) const {
	int stripIdx = -1;
	int s=0, e=strips.size();
	while(s<=e) {
		int m = s + (e-s)/2;
		if(strips[m].beginLatitude <= lat && strips[m].endLatitude>=lat) {
			stripIdx = m;
			break;
		} else if(strips[m].beginLatitude > lat) {
			e = m-1;
		} else {
			s = m+1;
		}
	}

	if(stripIdx == -1) {
		printf("It is really weird, we mapped whole earth and still for latitude strip not found : %lf \n", lat);
	}
	
	return stripIdx;; 
}

int MapSearch::findCellIndex(const double lat, const double lng) const {
	Cell cell = findCell(lat, lng);
	return cell.getID();
}
Cell MapSearch::findCell(const double lat, const double lng) const {
	Cell ret(0, 0, 0, 0, 0, 0, 0);
	bool found = false;
    int stripIdx = findStrip(lat);
	if(stripIdx == -1) return ret;	
	//We found a strip, continue to find cell
	const list<Cell>& cells = strips[stripIdx].cells;
	list<Cell>::const_iterator itr = cells.begin();
	while(itr != cells.end()) {
		const Cell& cell = *itr;
		if(cell.contains(lat, lng)) {
			ret = cell;
			found = true;
			break;
		}
		++itr;
	}
	if(!found) {
		printf("It is wierd, we found strip on earth but could not find cell: %d %lf %lf\n", stripIdx, lat, lng);
	}
	return ret;
}

double MapSearch::computeStep(const double lat, const double lng, const float r) const{
	double epsillon = 1e-3;	
	for(double step=0; step < r; step+=1e-6) {
		double d = GeoLocation::getDistance(lat, lng, lat+step, lng+step);
			if(d <= r + epsillon && d >= r - epsillon) {
				return step;
			}
			if(d > r ) {
				printf("Worng comparisons\n");
				return -1.0;	
			}

	}
}
vector<int> MapSearch::findCellsIndex(const double lat, const double lng, const float radius) const {
	vector<int> ret;
	vector<Cell> cells = findCells(lat, lng, radius);
	for(size_t i=0; i<cells.size(); ++i) {
		ret.push_back(cells[i].getID());
	}
	return ret;
}
vector<Cell> MapSearch::findCells(const double lat, const double lng, const float radius) const {
	double step = computeStep(lat, lng, sqrt(2*radius*radius));
	//form bounding rectangle
	double lat1 = lat - step;
	double lat2 = lat + step;
	double lng1 = lng - step;
	double lng2 = lng + step;
	Cell rec(-1, lat1, lng1, lat2, lng2, 2*radius, 2*radius);

	vector<int> stripIndexes = findStrips(lat1, lat2); 
	vector<Cell> result;
	for(int i=0; i<stripIndexes.size(); ++i) {
		int idx = stripIndexes[i];
		const list<Cell>& cells = strips[idx].cells;
		list<Cell>::const_iterator itr = cells.begin();
		while(itr != cells.end()){
			const Cell& tmp = *itr;	
			//if(rec.contains(tmp) || tmp.contains(rec)) result.push_back(tmp);
			if(rec.intersect(tmp)) result.push_back(tmp);
			++itr;				
		}		
	}	
	return result;
}
void MapSearch::dump() const{
	int cellCount = 0;	
	for(size_t i=0; i<strips.size(); ++i) {
		const Strip& strip = strips[i];
		printf("%lf %lf \n", strip.beginLatitude, strip.endLatitude);
		cellCount += strip.cells.size();
	}
	printf("Total strips on earth : %d\n", strips.size());
	printf("Total cells on earth : %d\n", cellCount);
}

#ifdef UT
int main(int argc, char** argv) {
	if(argc < 2) {
		printf("data file\n");
		return 1;
	}
	
	printf("Data file: %s\n", argv[1]);
	MapSearch m(argv[1]);		
	m.dump();
	//Cell* cell = m.findCell(12.9758266, 77.67150809999998);	
	vector<Cell> cells = m.findCells(12.9758266, 77.67150809999998, 100);	
	printf("Total cells with radius %d of %lf %lf is %d\n", 100, 12.9758266, 77.67150809999998, cells.size());
	for(size_t i=0; i<cells.size(); ++i) {
		cells[i].dump();
	}
}
#endif

/*
 //HOP search algo 
 int s = 0, e = strips.size();
	int idx = -1;
	//this is not binary search, this is hop search
    while(s<=e) {	
		int hop = 1;
		for(int i=s; i<e; i+=hop) {
			if(lat2 < strips[i].beginLatitude) break;
			if((strips[i].beginLatitude > lat1 && strips[i].beginLatitude < lat2)
				|| (lat1 > strips[i].beginLatitude && lat1 < strips[i].endLatitude)) {			
				idx = i;
				break;
			}
			s = hop-1;
			int t = hop*2;
			e = t<e?t:e;
			hop=t;
		}		
		if(idx != -1) break;
	}	
 */
