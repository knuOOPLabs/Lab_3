#include "Grehem.h"
#include "qgeometry.h"
#include <cmath>
#include <thread>
#include <chrono>

Grehem::Grehem(const QVector<const QPointF *> * pointers, QPolygonF * cnvxShell) 
	: _pointers(pointers)
	, _cnvxShell(cnvxShell)
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

void Grehem::GrehemMethod()
{
	pstartPoint = findLowest();
	pointQuickSort(coeffsTable, 1, _pointers->size() - 1);

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	*_cnvxShell << *(*_pointers)[coeffsTable[0]] << *(*_pointers)[coeffsTable[1]];

	for (size_t i = 2; i < _pointers->size(); ++i)
	{
		
		int j = _cnvxShell->size();
		while(j > 1 && rotate((*_cnvxShell)[j - 2], (*_cnvxShell)[j - 1], *(*_pointers)[coeffsTable[i]]) > 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			_cnvxShell->pop_back();
			j--;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		_cnvxShell->push_back((*(*_pointers)[coeffsTable[i]]));
	}
}

