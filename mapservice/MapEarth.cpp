#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cassert>

using namespace std;

double getDistance(double lat1, double lng1, double lat2, double lng2) {
	double R = 6373.00f;	
	double PI = 3.14159265f;
	double deg2radians = PI/180.0;
	lat1 *= deg2radians;
	lat2 *= deg2radians;
	lng1 *= deg2radians;
	lng2 *= deg2radians;

	double diffLat = lat2 - lat1;
	double diffLng = lng2 - lng1;
	double a = 	pow(sin(diffLat/2), 2) + cos(lat1)*cos(lat2)*pow(sin(diffLng/2), 2);	
	double c = 2*atan2(sqrt(a), sqrt(1-a));
	double d = R*c;
#ifdef DBG
	cout<<lat1<<" "<<lng1<<" "<<lat2<<" "<<lng2<<endl;
	cout<<diffLat<<" "<<diffLng<<endl;
	cout<<a<<endl;
	cout<<d<<endl;
#endif
	
	return d;
}

double getStep(double r, double lat, double lng) {
	double epsillon = 1e-3;	
	for(double step=0; step < 7; step+=1e-6) {
		double d = getDistance(lat, lng, lat+step, lng+step);
			if(d <= r + epsillon && d >= r - epsillon) {
				return step;
			}
			if(d >= r ) {
				//return step;
				break;
			}

	}
}

void generateSquares(double r, double step) {
	double epsillon = 1e-3;	
	int count = 0;
	FILE* fh = fopen("./earth-map", "w");
	for(double lat = -180.0f; lat<= 180.0f - step; lat+=step) {
		for(double lng = -180.0f; lng <= 180.0f -step; lng += step) {
			double d = getDistance(lat, lng, lat+step, lng+step);
			if(d <= r + epsillon && d >= r - epsillon) {
				//cout<<count<<"\t\t"<<lat<<" "<<lng<<" "<<lat+step<<" "<<lng+step<<endl;	
				fprintf(fh, "%d\t\t%lf %lf %lf %lf %lf\n", count, lat, lng, lat+step, lng+step, step);
			} else {
				step = getStep(r, lat, lng);	
				d = getDistance(lat, lng, lat+step, lng+step);
				assert(d<=r+epsillon && d>=r-epsillon);
				fprintf(fh, "%d\t\t%lf %lf %lf %lf %lf\n", count, lat, lng, lat+step, lng+step, step);
				//cout<<count<<"\t\t"<<lat<<" "<<lng<<" "<<lat+step<<" "<<lng+step<<endl;	
			} 
			++count;
		}
	}
	fflush(fh);
	fclose(fh);
}

#ifdef GENERATEDATA
int main(int argc, char** argv) {
	cout<<std::setprecision(9);	
	//cout<<getDistance(12.97582660f, 77.67150810f, 12.97380960f, 77.67365540f)<<endl;	
	double r = 19.79898987322333068322f;
	double step = getStep(r, -180 , -180);
	printf("Found step: %lf\n", step);
	printf("Generating squares...\n");
	generateSquares(r, step);
	cout<<getDistance(0, 0, 0.12586f, 0)<<endl;

}
#endif

