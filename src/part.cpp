#include "data.h"

Data::Part::Part()
{
	resetBoundingBox();
}

void Data::Part::resetBoundingBox()
{
	Eigen::Vector3f min, max;
	min << 100.0, 100.0, 100.0;
	max << -100.0, -100.0, -100.0;
	boundingBox = Eigen::AlignedBox3f(min, max);
}

void Data::Part::recalculateBoundingBox(Data::Vertex* vertex)
{
	if (vertex->pos[0] < boundingBox.min()[0]) {
		boundingBox.min()[0] = vertex->pos[0];
	}
	if (vertex->pos[1] < boundingBox.min()[1]) {
		boundingBox.min()[1] = vertex->pos[1];
	}
	if (vertex->pos[2] < boundingBox.min()[2]) {
		boundingBox.min()[2] = vertex->pos[2];
	}
	if (vertex->pos[0] > boundingBox.max()[0]) {
		boundingBox.max()[0] = vertex->pos[0];
	}
	if (vertex->pos[1] > boundingBox.max()[1]) {
		boundingBox.max()[1] = vertex->pos[1];
	}
	if (vertex->pos[2] > boundingBox.max()[2]) {
		boundingBox.max()[2] = vertex->pos[2];
	}
}
