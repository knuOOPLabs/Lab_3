#include "Grehem.h"
#include "qgeometry.h"
#include <cmath>

Grehem::Grehem(const QVector<const QPointF *> * pointers) : _pointers(pointers) 
{
	coeffsTable = new int[_pointers->size()];
	for (size_t i = 0; i < _pointers->size(); ++i)
	{
		coeffsTable[i] = i;
	}
}


const QPointF * Grehem::findLowest() const
{
	const QPointF * res = (*_pointers)[0];
	int i = 1;
	for (; i < _pointers->size(); i++)
	{
		if (res->y() < (*_pointers)[i]->y())
		{
			res = (*_pointers)[i];
		}
	}
	swapcoeffs(i, 0);

	return res;
}

bool Grehem::cmpQPointF(const QPointF * p1, const QPointF * p2) const
{
	if (p1->x() > pstartPoint->x())
	{
		if (p2->x() > pstartPoint->x()) return sin(*pstartPoint, *p1) > sin(*pstartPoint, *p2);
		else return false;
	}
	else
	{
		if (p2->x() > pstartPoint->x()) return true;
		else return sin(*pstartPoint, *p1) < sin(*pstartPoint, *p2);;
	}
}

bool Grehem::checkNextPoint()
{
	// check for all vector if p2  in our result vector
	return true;
}

int & Grehem::pointPartition(int * coeffs, const int & lower, const int & higher)
{
	const QPointF * p1 = (*_pointers)[higher];
	int i = lower
		, tmp = 0;
	for (int j = lower; lower < higher; ++j)
	{
		if (cmpQPointF((*_pointers)[j], p1))
		{
			if (i != j)
			{
				swapcoeffs(i, j);
			}
			++i;
		}
	}
	//swap
	swapcoeffs(i, higher);

	return i;
}

void Grehem::pointQuickSort(int * coeffs, const int & lower, const int & higher)
{
	if (lower >= higher) return;

	int partition = pointPartition(coeffs, lower, higher);
	pointQuickSort(coeffs, lower, partition - 1);
	pointQuickSort(coeffs, partition + 1, higher);
}

void Grehem::swapcoeffs(const int & first, const int & second) const
{
	int tmp = coeffsTable[first];
	coeffsTable[first] = coeffsTable[second];
	coeffsTable[second] = tmp;
}

QPolygonF Grehem::GrehemMethod()
{
	pstartPoint = findLowest();

	pointQuickSort(coeffsTable, 1, _pointers->size());

	//qsort(&_pointers, _pointers.size(), sizeof(QPointF), compareQPointF);

	//{
	//	//step 2
	//	findNextPoint();
	//	// now we have p3
	//
	//	// step 3 checking p3
	//
	//	//if (pointAngleType() == 1)
	//	//{
	//	//	// input p1  in result vector
	//	//	//p1 = p2;
	//	//	//p2 = p3;
	//	//}
	//	//else if (pointAngleType() == 0)
	//	//{
	//	//	//p2 = p3;
	//	//}
	//	//else if (pointAngleType() == 2)
	//	//{
	//	//	//p2 = p3;
	//	//}
	//	//else
	//	//{
	//	//	throw " Can't find fi for three points";
	//	//}
	//}

	// input p2 in result vector
}

