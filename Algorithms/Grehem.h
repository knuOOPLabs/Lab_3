#pragma once

#include <QVector>
#include <QPointF>
#include <QPolygonF>


class Grehem
{
public:
	Grehem(const QVector<const QPointF *> * pointers);
	QPolygonF GrehemMethod();

private:
	const QVector<const QPointF *> * _pointers;
	const QPointF *pstartPoint;
	int * coeffsTable;


	bool cmpQPointF(const QPointF * p2, const QPointF * p3) const;	//	true if p2 > p3

	const QPointF * findLowest() const;

	void findNextPoint();

	bool checkNextPoint();

	int & pointPartition(int * coeffs, const int & lower, const int & higher);

	void pointQuickSort(int * coeffs, const int & lower, const int & higher);

	void swapcoeffs(const int & first, const int & second) const;
};

