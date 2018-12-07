#pragma once

#include <QVector>
#include <QPointF>
#include <QPolygonF>


class Grehem
{
private:

	//int pointAngleType();

	//function: searching left point
	// parametres: vector with points
	QPointF findLowest(const QVector<QPointF *> * _pointers);

	bool cmp(const QPointF & a, const QPointF & b);

	bool cw(const QPointF & a, const QPointF & b, const QPointF & c);

	bool ccw(const QPointF & a, const QPointF & b, const QPointF & c);

	//function: searching left point
	// parametres: vector with points
	void findNextPoint();

	bool checkNextPoint();

	int pointPartition(QVector<QPointF *> * _pointers, const QPointF & leadPoint, const int & lower, const int & higher);

	void pointQuickSort(QVector<QPointF *> * _pointers, const QPointF & leadPoint, const int & lower, const int & higher);

	QPointF _p1, _p2, _p3;

public:

	

	// doing Grehem method
	// input points in vector
	QPolygonF GrehemMethod(QVector<QPointF *> _pointers);
};

