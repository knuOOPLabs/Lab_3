#pragma once

#include <QVector>
#include <QPointF>
#include <QPolygonF>


class Grehem
{
public:
	Grehem(const QVector<const QPointF *> * pointers, QPolygonF * cnvxShell);
	void GrehemMethod();

private:
	const QVector<const QPointF *> * _pointers;
	
	const QPointF *pstartPoint;
	int * coeffsTable;
	QPolygonF * _cnvxShell;
	const QPointF * findLowest() const;

	int pointPartition(int * coeffs, const int & lower, const int & higher);

	void pointQuickSort(int * coeffs, const int & lower, const int & higher);

	void swapcoeffs(const int & first, const int & second) const;
};

