#pragma once

#include <cmath>
#include<iostream>
using namespace std;


class GeoLocation {
	static const double R = 6373.00f;	
	static const double PI = 3.14159265f;

	public:
		static double getDistance(double lat1, double lng1, double lat2, double lng2) {
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

};
