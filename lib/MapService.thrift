namespace cpp around7.mapservice

service MapService {
	i32 findCell(1:double lat,  2:double lng);
	list<i32> findCells(1:double lat, 2:double lng, 3:double radius);
}

struct TCell {
1:	double lat1;
2:	double lng1; 
3:	double lat2; 
4:	double lng2;
5:	double height;
6:	double width;
}
