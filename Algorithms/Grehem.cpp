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
	int j = 0;
	for (int i = 1; i < _pointers->size(); i++)
	{
		if (res->y() < (*_pointers)[i]->y())
		{
			res = (*_pointers)[i];
			j = i;
		}
	}
	swapcoeffs(j, 0);

	return res;
}

bool Grehem::cmpQPointF(const QPointF * p1, const QPointF * p2) const
{
	return rotate(*pstartPoint, *p1, *p2) < 0;

	//if (p1->x() > pstartPoint->x())
	//{
	//	if (p2->x() > pstartPoint->x()) return sin(*pstartPoint, *p1) > sin(*pstartPoint, *p2);
	//	else return false;
	//}
	//else
	//{
	//	if (p2->x() > pstartPoint->x()) return true;
	//	else return sin(*pstartPoint, *p1) < sin(*pstartPoint, *p2);;
	//}
}

bool Grehem::checkNextPoint()
{
	// check for all vector if p2  in our result vector
	return true;
}

int Grehem::pointPartition(int * coeffs, const int & lower, const int & higher)
{
	const QPointF * p1 = (*_pointers)[coeffsTable[higher]];
	int i = lower;
	for (int j = lower; j < higher; ++j)
	{
		if (rotate(*pstartPoint, *p1, *(*_pointers)[coeffsTable[j]]) > 0)
		{
			if (i != j)
			{
				swapcoeffs(i, j);
			}
			++i;
		}
	}

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
	QPolygonF cnvxShell;

	if (_pointers->size() > 2)
	{
		pstartPoint = findLowest();

		pointQuickSort(coeffsTable, 1, _pointers->size() - 1);

		//QVector<QPointF> res;
		cnvxShell << *(*_pointers)[coeffsTable[0]] << *(*_pointers)[coeffsTable[1]];

		//res.push_back(*(*_pointers)[coeffsTable[0]]);
		//res.push_back(*(*_pointers)[coeffsTable[1]]);


		for (size_t i = 2; i < _pointers->size(); ++i)
		{
			int j = cnvxShell.size();
			while(j > 1 && rotate(cnvxShell[j - 2], cnvxShell[j - 1], *(*_pointers)[coeffsTable[i]]) > 0)
			{
				cnvxShell.pop_back();
				j--;
			}

			cnvxShell.push_back((*(*_pointers)[coeffsTable[i]]));
		}
	}
	return cnvxShell;
}

