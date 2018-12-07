#include "QTriangle.h"

QTriangle::QTriangle(const QPointF & p1, const QPointF & p2, const QPointF & p3)
	: _isBad(false)
{
	_p1 = new QPointF(p1);
	_p2 = new QPointF(p2);
	_p3 = new QPointF(p3);

	_edge1 = new QEdge();
	_edge2 = new QEdge();
	_edge3 = new QEdge();

	_edge1->setPoints(*_p1, *_p2);
	_edge2->setPoints(*_p2, *_p3);
	_edge3->setPoints(*_p3, *_p1);

	_polygon = new QPolygonF();
	*_polygon << p1 << p2 << p3;
}

QTriangle::~QTriangle()
{
	if (_p1 != nullptr) delete _p1;
	if (_p2 != nullptr) delete _p2;
	if (_p3 != nullptr) delete _p3;
	if (_edge1 != nullptr) delete _edge1;
	if (_edge2 != nullptr) delete _edge2;
	if (_edge3 != nullptr) delete _edge3;
	if (_polygon != nullptr) delete _polygon;
}

QPointF QTriangle::p1() const
{
	if (_p1 == nullptr)	throw std::logic_error("triangle is not build");
	return *_p1;
}

QPointF QTriangle::p2() const
{
	if (_p1 == nullptr)	throw std::logic_error("triangle is not build");
	return *_p2;
}

QPointF QTriangle::p3() const
{
	if (_p1 == nullptr)	throw std::logic_error("triangle is not build");
	return *_p3;
}

QEdge QTriangle::edge1() const
{
	if (_p1 == nullptr)	throw std::logic_error("triangle is not build");
	return *_edge1;
}

QEdge QTriangle::edge2() const
{
	if (_p1 == nullptr)	throw std::logic_error("triangle is not build");
	return *_edge2;
}

QEdge QTriangle::edge3() const
{
	if (_p1 == nullptr)	throw std::logic_error("triangle is not build");
	return *_edge3;
}

QPolygonF QTriangle::polygon() const
{
	if (_p1 == nullptr)	throw std::logic_error("triangle is not build");
	return *_polygon;
}

bool QTriangle::isBad() const
{
	return _isBad;
}

void QTriangle::makeBad(const bool res)
{
	_isBad = res;
}

bool QTriangle::hasPoint(const QPointF & point) const
{
	return almost_equal(*_p1, point) || almost_equal(*_p2, point) || almost_equal(*_p3, point);
}

bool QTriangle::hasCircleCircum(const QPointF & point) const
{
	const double ab = norm2(*_p1)
		, cd = norm2(*_p2)
		, ef = norm2(*_p3);

	const double circ_x = (ab * (_p3->y() - _p2->y()) + cd * (_p1->y() - _p3->y()) + ef * (_p2->y() - _p1->y()))
		/ (_p1->x() * (_p3->y() - _p2->y()) + _p2->x() * (_p1->y() - _p3->y()) + _p3->x() * (_p2->y() - _p1->y()))
		
		, circ_y = (ab * (_p3->x() - _p2->x()) + cd * (_p1->x() - _p3->x()) + ef * (_p2->x() - _p1->x()))
		/ (_p1->y() * (_p3->x() - _p2->x()) + _p2->y()* (_p1->x() - _p3->x()) + _p3->y()* (_p2->x() - _p1->x()));



	const QPointF circ(half(circ_x), half(circ_y));
	const double circ_radius = dist(*_p1, circ) * dist(*_p1, circ);
	const double distance = dist(point, circ) * dist(point, circ);

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
	return	(*_p1 == other.p1() || *_p1 == other.p2() || *_p1 == other.p3()) &&
		(*_p2 == other.p1() || *_p2 == other.p2() || *_p2 == other.p3()) &&
		(*_p3 == other.p1() || *_p3 == other.p2() || *_p3 == other.p3());
}

