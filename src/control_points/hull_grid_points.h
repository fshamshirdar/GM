#pragma once

#include "data.h"
#include "control_points.h"
#include <iostream>

class HullGridPoints: public ControlPointsMiner {
public:
	class HullGridPoint {
	public:
		Data::Vertex* vertex;
		float dist;
	public:
		HullGridPoint() {
			vertex = NULL;
			dist = 1000.0;
		}
	};

public:
	HullGridPoints(int nx, int ny, int nz);
	std::vector<ControlPointsMiner::ControlPoint*> findControlPoints(Data::Part* ref, Data::Part* target);
	std::vector<ControlPointsMiner::ControlPoint*> findCorrespondingPoints(HullGridPoints::HullGridPoint*** refPoints, HullGridPoints::HullGridPoint*** targetPoints, int n, int m);
	HullGridPoint*** findXZHullPoints(Data::Part* part, int n, int m);
	HullGridPoint*** findXYHullPoints(Data::Part* part, int n, int m);	
	HullGridPoint*** findYZHullPoints(Data::Part* part, int n, int m);

private:
	int nx, ny, nz;
};
