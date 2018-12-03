#include "myQPoint.h"

double myQPoint::x() const
{
	return _x;
}

double myQPoint::y() const
{
	return _y;
}

void myQPoint::setCoords(const double &x, const double &y)
{
	_x = x;
	_y = y;
}

double myQPoint::dist2(const myQPoint &v) const
{
	double dx = _x - v._x;
	double dy = _y - v._y;
	return dx * dx + dy * dy;
}

double myQPoint::dist(const myQPoint &v) const
{
	return sqrt(dist2(v));
}

double myQPoint::norm2() const
{
	return _x * _x + _y * _y;
}

bool almost_equal(const myQPoint& p1, const myQPoint& p2, int ulp /*= 2 */)
{
	return almost_equal(p1.x(), p2.x(), ulp) && almost_equal(p1.y(), p2.y(), ulp);
}

bool myQPoint::operator==(const myQPoint& other) const
{
	return _x == other.x() && _y == other.y();
}
