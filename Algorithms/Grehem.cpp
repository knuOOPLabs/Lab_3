#include "Grehem.h"
#include <QLineF>
#include <cmath>

int compareQPointF(const void * p1, const void * p2);

//int Grehem::pointAngleType() 
//{
//	int fi = (p2.y - p1.y) * (p3.x - p2.x) -
//		(p2.x - p1.x) * (p3.y - p2.y);
//	if (fi == 0) return 0;     
//	return (fi > 0) ? 2 : 1;      
//}

QPointF Grehem::findLowest(const QVector<QPointF *> * _pointers)
{
	QPointF res = *(*_pointers)[0];
	size_t j = 0;
	for (size_t i = 1; i < _pointers->size(); i++)
	{
		if (res.y() < (*_pointers)[i]->y())
		{
			res = *(*_pointers)[i];
			j = i;
		}
	}

	//_pointers.remove(j);
	//_pointers.push_front(&res);

	return res;
}

int compareQPointF(const void * p2, const void * p3)
{
	//QLineF l1(_p1, )
	//QLineF l2(_p1, b);
	//
	//if (l1.angle() < l2.angle()) return 1;
	//else if (l1.angle() > l2.angle()) return -1;
	//else
	//{
	//	if (abs(a.x() - _p1.x()) < abs(b.x() - _p1.x())) return 1;
	//	else if (abs(a.x() - _p1.x()) > abs(b.x() - _p1.x())) return-1;
	//}
	//
	//return 0;
}

bool Grehem::cmp(const QPointF & p1, const QPointF & p2)
{
	return p1.x() < p2.x() || p1.x() == p2.x() && p1.y() > p2.y();
}

bool Grehem::cw(const QPointF & p1, const QPointF & p2, const QPointF & p3)
{
	return p1.x()*(p2.y() - p3.y()) + p2.x()*(p3.y() - p1.y()) + p3.x()*(p1.y() - p2.y()) < 0;
}

bool Grehem::ccw(const QPointF & p1, const QPointF & p2, const QPointF & p3)
{
	return p1.x()*(p2.y() - p3.y()) + p2.x()*(p3.y() - p1.y()) + p3.x()*(p1.y() - p2.y()) > 0;
}

void Grehem::findNextPoint()
{
	// probegaemsya po cukly i nahodim point s naimenhim fi p3 = that.point
}

bool Grehem::checkNextPoint()
{
	// check for all vector if p2  in our result vector
	return true;
}

int Grehem::pointPartition(QVector<QPointF *> * _pointers, const QPointF & leadPoint, const int & lower, const int & higher)
{

}

void Grehem::pointQuickSort(QVector<QPointF *> * _pointers, const QPointF & leadPoint, const int & lower, const int & higher)
{

}

QPolygonF Grehem::GrehemMethod(QVector<QPointF *> _pointers)
{
	_p1 = findLowest(&_pointers);	// find first pointer
	

	//qsort(&_pointers, _pointers.size(), sizeof(QPointF), compareQPointF);
	// проверяем по циклу
	{
		//step 2
		findNextPoint();
		// now we have p3

		// step 3 checking p3

		if (pointAngleType() == 1)
		{
			// input p1  in result vector
			p1 = p2;
			p2 = p3;
		}
		else if (pointAngleType() == 0)
		{
			p2 = p3;
		}
		else if (pointAngleType() == 2)
		{
			p2 = p3;
		}
		else
		{
			throw " Can't find fi for three points";
		}
	}
	// input p2 in result vector
}

