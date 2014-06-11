#pragma once
#include <list>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include "Cell.h"

struct Strip {
	double beginLatitude;
	double endLatitude;
	std::list<Cell> cells;
	Strip(double beginLat, double endLat):beginLatitude(beginLat), endLatitude(endLat) {}
};

class MapSearch {
	private:
		std::vector<Strip> strips;
		void initMap(FILE* fh);	
		int findStrip(const double lat) const;
		std::vector<int> findStrips(double lat1, double lat2) const;
		double computeStep(const double lat, const double lng, const float r) const;

	public:
		MapSearch(std::string dataFile);
		Cell findCell(const double lat, const double lng) const;
		int findCellIndex(const double lat, const double lng) const;
		std::vector<Cell> findCells(const double lat, const double lng, const float radius) const;
		std::vector<int> findCellsIndex(const double lat, const double lng, const float radius) const;
		void dump() const;

};
