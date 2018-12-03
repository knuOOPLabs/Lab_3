#pragma once

#include <QVector>
#include "QTriangle.h"


class CDelanauTriangulate
{
public:
	CDelanauTriangulate();
	CDelanauTriangulate(const QVector<myQPoint> &_pointers);
	~CDelanauTriangulate();

private:

	void build();

	const QVector<myQPoint > pointers;
	QVector<QEdge> edges;
	QVector<QTriangle> triangles;
};

