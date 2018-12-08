#include "qgeometry.h"

double dist2(const QPointF &p1, const QPointF &p2)
{
	return (p1.x() - p2.x()) * (p1.x() - p2.x()) + (p1.y() - p2.y()) * (p1.y() - p2.y());
}

double dist(const QPointF &p1, const QPointF &p2)
{
	return sqrt(dist2(p1, p2));
}

float sin(const QPointF &p1, const QPointF &p2)
{
	return dist(p1, p2) / abs(p2.y() - p1.y());
}

double norm2(const QPointF &p1)
{
	return p1.x() * p1.x() + p1.y() * p1.y();
}

bool almost_equal(double x, double y, int ulp /*= 2*/)
{
	// the machine epsilon has to be scaled to the magnitude of the values used
	// and multiplied by the desired precision in ULPs (units in the last place)
	return std::abs(x - y) <= std::numeric_limits<double>::epsilon() * std::abs(x + y) * ulp
		// unless the result is subnormal
		|| std::abs(x - y) < std::numeric_limits<double>::min();
}

bool almost_equal(const QPointF& p1, const QPointF& p2, int ulp /*= 2*/)
{
	return almost_equal(p1.x(), p2.x(), ulp) && almost_equal(p1.y(), p2.y(), ulp);
}

bool almost_equal(const QLineF & l1, const QLineF & l2, int ulp /*= 2*/)
{
	return	(almost_equal(l1.p1(), l2.p1()) && almost_equal(l1.p2(), l2.p2())) ||
		(almost_equal(l1.p1(), l2.p2()) && almost_equal(l1.p2(), l2.p1()));
}

bool operator==(const QLineF & l1, const QLineF & l2)
{
	return 	(l1.p1() == l2.p1() && l1.p2() == l2.p2()) ||
		(l1.p1() == l2.p2() && l1.p2() == l2.p1());
}