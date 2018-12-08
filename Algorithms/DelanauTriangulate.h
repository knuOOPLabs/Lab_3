#pragma once

#include <QVector>
#include <QPolygon>
#include "QTriangle.h"


class CDelanauTriangulate
{
public:
	CDelanauTriangulate();
	CDelanauTriangulate(const QVector<const QPointF *> & pointers);
	~CDelanauTriangulate();

	void downPoints(const QVector<const QPointF *> & pointers);

	QVector<QTriangle *> triangles() const;
	QVector<QEdge *> edges() const;

	QVector<QTriangle *> triangulate();

private:

	QVector<const QPointF *> _pointers;
	QVector<QEdge *> _edges;
	QVector<QTriangle *> _triangles;
};

