#pragma once
#include "qgeometry.h"

#include <iostream>
#include <cmath>

class myQPoint
{
public:
	myQPoint() :_x(0), _y(0) {}
	myQPoint(const double &x, const double &y) : _x(x), _y(y) {}

	myQPoint(const myQPoint &other) : _x(other.x()), _y(other.y()) {}

	double x() const;
	double y() const;

	void setCoords(const double &x, const double &y);

	double dist2(const myQPoint &v) const;	//	reworked as a friend function	+
	double dist(const myQPoint &v) const;	//	reworked as a friend function	+
	double norm2() const;					//	reworked as a friend function	+

	bool operator == (const myQPoint& other) const;

	//friend double dist(const myQPoint & p1, const myQPoint & p2);
	friend bool almost_equal(const myQPoint& p1, const myQPoint& p2, int ulp = 2 );	//	reworked as a friend function	+

private:
	double _x, _y;
};

//template <>
//float myQPoint<float>::dist(const myQPoint<float> &v) const { return hypotf(x - v.x, y - v.y); }
//
//template <>
//double myQPoint<double>::dist(const myQPoint<double> &v) const { return hypot(x - v.x, y - v.y); }

//template<typename T>
//std::ostream &operator << (std::ostream &str, myQPoint<T> const &point)
//{
//	return str << "Point x: " << point.x << " y: " << point.y;
//}

//template<typename T>
//bool operator == (const myQPoint<T>& v1, const myQPoint<T>& v2)
//{
//	return (v1.x == v2.x) && (v1.y == v2.y);
//}

//template<class T>
//typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
//almost_equal(const myQPoint<T>& v1, const myQPoint<T>& v2, int ulp = 2)
//{
//	return almost_equal(v1.x, v2.x, ulp) && almost_equal(v1.y, v2.y, ulp);
//}

