// =====================================================================================
// 
//       Filename:  GeoRectangle.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  Thursday 25 July 2013 01:27:15  IST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  lplay (tc), 
//        Company:  around7 
// 
// =====================================================================================

class GeoRectangle {
	private:
		double lat1, lng1;
		double lat2, lng2;
		GeoRectangle(){}
	public:
		GeoRectangle(double lat1, double lng1, double lat2, double lng2):lat1(lat1), lng1(lng1), lat2(lat2), lng2(lng2) {
		}

		bool contains(const GeoRectangle& rec) const {
			bool ret = false;
			if( (rec.lat1>=lat1 && rec.lat1 <= lat2) 
				&& (rec.lat2>=lat1 && rec.lat2 <= lat2)
				&& (rec.lng1>=lng1 && rec.lng1 <= lng2)			
				&& (rec.lng2>=lng1 && rec.lng2 <= lng2))	
			{
				ret = true;
			}		
			return ret;
		}


};
