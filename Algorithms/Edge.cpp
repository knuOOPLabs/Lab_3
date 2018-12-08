#include "Edge.h"


bool QEdge::isBad() const
{
	return _isBad;
}

void QEdge::makeBad(const bool res)
{
	_isBad = res;
}

bool almost_equal(const QEdge & e1, const QEdge & e2)
{
	return	(almost_equal(e1.p1(), e2.p1()) && almost_equal(e1.p2(), e2.p2())) ||
		(almost_equal(e1.p1(), e2.p2()) && almost_equal(e1.p2(), e2.p1()));
}

