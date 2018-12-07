#pragma once

#include <QVector>
#include <QPolygon>
#include "QTriangle.h"


class CDelanauTriangulate
{
public:
	CDelanauTriangulate();
	CDelanauTriangulate(const QVector<QPointF *> & pointers);
	~CDelanauTriangulate();

	void downPoints(const QVector<QPointF *> & pointers);

	QVector<QTriangle *> triangles() const;
	QVector<QPointF *> pointers() const;
	QVector<QEdge *> edges() const;

	QVector<QTriangle *> triangulate();

private:

	

	QVector<QPointF *> _pointers;
	QVector<QEdge *> _edges;
	QVector<QTriangle *> _triangles;
};

