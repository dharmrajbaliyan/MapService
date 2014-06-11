// =====================================================================================
// 
//       Filename:  Cell.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  Friday 26 July 2013 01:00:38  IST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  lplay (tc), 
//        Company:  
// 
// =====================================================================================

class Cell {
	private:	
		double lat1, lng1, lat2, lng2;
		float height, width;
		int id;
	public:	
		Cell(int id, double lat1, double lng1, double lat2, double lng2, float w, float h) 
				: id(id), 
				lat1(lat1), lng1(lng1),  
				lat2(lat2), lng2(lng2), 
				height(h), width(w) {
		} 
		int getID() const {
			return id;
		}
		bool contains(const Cell& cell) const {
				bool ret = false;
				if( (cell.lat1>=lat1 && cell.lat1 <= lat2) 
					&& (cell.lat2>=lat1 && cell.lat2 <= lat2)
					&& (cell.lng1>=lng1 && cell.lng1 <= lng2)			
					&& (cell.lng2>=lng1 && cell.lng2 <= lng2))	
				{
					ret = true;
				}		
				return ret;
		}	

		bool contains(const double lat, const double lng) const {
			bool ret = false;
			if(this->lat1 <= lat && this->lat2 >= lat && this->lng1 <= lng && this->lng2 >= lng) {
				ret = true;
			}
			return ret;
		}
		
		bool intersect(const Cell& cell) {
			//if (RectA.X1 < RectB.X2 && RectA.X2 > RectB.X1 &&
			//    RectA.Y1 < RectB.Y2 && RectA.Y2 > RectB.Y1) 
			assert(lat1<lat2);
			assert(cell.lat1<cell.lat2);
			bool ret = false;
			if(lat1 < cell.lat2 && lat2 > cell.lat1 && lng1 < cell.lng2 && lng2 > cell.lng1) ret = true;

			return ret;
		}


	void dump() {
		printf("%lf %lf %lf %lf %f %f\n", lat1, lng1, lat2, lng2, height, width);
	}
};


