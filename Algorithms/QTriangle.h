#pragma once

//#include <QLineF>
#include "Edge.h"
#include <fstream>
#include <QPolygon>

class QTriangle
{
public:
	QTriangle() : _p1(nullptr), _p2(nullptr), _p3(nullptr), _edge1(nullptr), _edge2(nullptr), _edge3(nullptr), _polygon(nullptr){}
	QTriangle(const QPointF & p1, const QPointF & p2, const QPointF & p3);
	~QTriangle();

	QPointF p1() const;
	QPointF p2() const;
	QPointF p3() const;

	QEdge edge1() const;
	QEdge edge2() const;
	QEdge edge3() const;

	QPolygonF polygon() const;

	bool isBad() const;
	void makeBad(const bool res);

	bool hasPoint(const QPointF & point) const;
	bool hasCircleCircum(const QPointF & point) const;

	bool operator == (const QTriangle & other);

	friend bool almost_equal(const QTriangle &t1, const QTriangle &t2);

private:
	QPointF *_p1, *_p2, *_p3;
	QEdge *_edge1, *_edge2, *_edge3;
	QPolygonF *_polygon;
	bool _isBad;
};