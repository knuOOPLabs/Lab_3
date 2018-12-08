#include "DelanauTriangulate.h"

#include <thread>
#include <chrono>

CDelanauTriangulate::CDelanauTriangulate(const QVector<const QPointF *> * pointers, QVector<QTriangle *> * triangles)
	: _pointers(pointers)
	, _triangles(triangles)
{}

CDelanauTriangulate::~CDelanauTriangulate()
{
}

void CDelanauTriangulate::triangulate()
{
	double minX = (*_pointers)[0]->x();
	double minY = (*_pointers)[0]->y();
	double maxX = minX;
	double maxY = minY;

	for (std::size_t i = 0; i < _pointers->size(); ++i)
	{
		if ((*_pointers)[i]->x() < minX) minX = (*_pointers)[i]->x();
		if ((*_pointers)[i]->y() < minY) minY = (*_pointers)[i]->y();
		if ((*_pointers)[i]->x() > maxX) maxX = (*_pointers)[i]->x();
		if ((*_pointers)[i]->y() > maxY) maxY = (*_pointers)[i]->y();
	}

	const double dx = maxX - minX;
	const double dy = maxY - minY;
	const double deltaMax = std::max(dx, dy);
	const double midx = half(minX + maxX);
	const double midy = half(minY + maxY);

	const QPointF p1(midx - 10 * deltaMax, midy - deltaMax);
	const QPointF p2(midx, midy + 10 * deltaMax);
	const QPointF p3(midx + 10 * deltaMax, midy - deltaMax);


	QTriangle *supertriangle = new QTriangle(p1, p2, p3);

	_triangles->push_back(supertriangle);

	for (auto p = _pointers->begin(); p != _pointers->end(); p++)
	{
		QVector<QEdge> polygon;

		for (auto & t : *_triangles)
		{
			if (t->hasCircleCircum(**p))
			{
				t->makeBad(true);
				polygon.push_back(t->edge1());
				polygon.push_back(t->edge2());
				polygon.push_back(t->edge3());
			}
		}

		_triangles->erase(std::remove_if(_triangles->begin(), _triangles->end(), [](QTriangle *t) { return t->isBad(); }), _triangles->end());

		for (auto e1 = polygon.begin(); e1 != polygon.end(); ++e1)
		{
			for (auto e2 = e1 + 1; e2 != polygon.end(); ++e2)
			{
				if (almost_equal(*e1, *e2))
				{
					e1->makeBad(true);
					e2->makeBad(true);
				}
			}
		}

		polygon.erase(std::remove_if(polygon.begin(), polygon.end(), [](QEdge &e) { return e.isBad(); }), polygon.end());

		for (const auto e : polygon)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(40));
			QTriangle * newTriangle = new QTriangle(e.p1(), e.p2(), **p);
			_triangles->push_back(newTriangle);
		}

	}

	_triangles->erase(std::remove_if(_triangles->begin(), _triangles->end(),
		[p1, p2, p3](QTriangle *t) { return t->hasPoint(p1) || t->hasPoint(p2) || t->hasPoint(p3);	})
		, _triangles->end());
}
