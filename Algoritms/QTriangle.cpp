#include "QTriangle.h"

QTriangle::QTriangle(const myQPoint & _p1, const myQPoint & _p2, const myQPoint & _p3)
	: _p1(_p1) 
	, _p2(_p2)
	, _p3(_p3)
	, _edge1(_p1, _p2)
	, _edge2(_p2, _p3)
	, _edge3(_p3, _p1)
	, _isBad(false)
{

}

QTriangle::~QTriangle()
{

}

myQPoint QTriangle::p1() const
{
	return _p1;
}

myQPoint QTriangle::p2() const
{
	return _p2;
}

myQPoint QTriangle::p3() const
{
	return _p3;
}

QEdge QTriangle::edge1() const
{
	return _edge1;
}

QEdge QTriangle::edge2() const
{
	return _edge2;
}

QEdge QTriangle::edge3() const
{
	return _edge3;
}

bool QTriangle::isBad() const
{
	return _isBad;
}

void QTriangle::makeBad(const bool res)
{
	_isBad = res;
}

bool QTriangle::hasPoint(const myQPoint & point) const
{
	return almost_equal(_p1, point) || almost_equal(_p2, point) || almost_equal(_p3, point);
}

bool QTriangle::hasCircleCircum(const myQPoint & point) const
{
	const double ab = _p1.norm2()
		, cd = _p2.norm2()
		, ef = _p3.norm2();

	const double circ_x = (ab * (_p3.y() - _p2.y()) + cd * (_p1.y() - _p3.y()) + ef * (_p2.y() - _p1.y()))
		/ (_p1.x() * (_p3.y() - _p2.y()) + _p2.x() * (_p1.y() - _p3.y()) + _p3.x() * (_p2.y() - _p1.y()))
		
		, circ_y = (ab * (_p3.x() - _p2.x()) + cd * (_p1.x() - _p3.x()) + ef * (_p2.x() - _p1.x()))
		/ (_p1.y() * (_p3.x() - _p2.x()) + _p2.y()* (_p1.x() - _p3.x()) + _p3.y()* (_p2.x() - _p1.x()));



	const myQPoint circ(half(circ_x), half(circ_y));
	const double circ_radius = _p1.dist(circ) * _p1.dist(circ);
	const double distance = point.dist(circ) * point.dist(circ);


	return distance <= circ_radius;
}

bool almost_equal(const QTriangle &t1, const QTriangle &t2)
{
	return	(almost_equal(t1.p1(), t2.p1()) || almost_equal(t1.p1(), t2.p2()) || almost_equal(t1.p1(), t2.p3())) &&
		(almost_equal(t1.p2(), t2.p1()) || almost_equal(t1.p2(), t2.p2()) || almost_equal(t1.p2(), t2.p3())) &&
		(almost_equal(t1.p3(), t2.p1()) || almost_equal(t1.p3(), t2.p2()) || almost_equal(t1.p3(), t2.p3()));
}

bool QTriangle::operator==(const QTriangle & other)
{
	return	(_p1 == other.p1() || _p1 == other.p2() || _p1 == other.p3()) &&
		(_p2 == other.p1() || _p2 == other.p2() || _p2 == other.p3()) &&
		(_p3 == other.p1() || _p3 == other.p2() || _p3 == other.p3());
}

