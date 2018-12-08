#pragma once

#include <QVector>
#include <QPolygon>
#include "QTriangle.h"


class CDelanauTriangulate
{
public:
	CDelanauTriangulate(const QVector<const QPointF *> * pointers, QVector<QTriangle *> * triangles);
	~CDelanauTriangulate();
	
	void triangulate();

private:

	const QVector<const QPointF *> *_pointers;
	QVector<QTriangle *> *_triangles;
};

