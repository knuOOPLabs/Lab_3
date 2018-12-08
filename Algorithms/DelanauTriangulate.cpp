#include "DelanauTriangulate.h"



CDelanauTriangulate::CDelanauTriangulate() {}


CDelanauTriangulate::CDelanauTriangulate(const QVector<const QPointF *> & pointers)
	:_pointers(_pointers)
{}

CDelanauTriangulate::~CDelanauTriangulate()
{
}

void CDelanauTriangulate::downPoints(const QVector<const  QPointF *> & pointers)
{
	_pointers.clear();
	_pointers = pointers;
}


QVector<QTriangle *> CDelanauTriangulate::triangles() const
{
	return _triangles;
}

QVector<QEdge *> CDelanauTriangulate::edges() const
{
	return _edges;
}

QVector<QTriangle *> CDelanauTriangulate::triangulate()
{
	//QVector<QTriangle *> _triangles;
	_edges.clear();
	if (_pointers.size() >= 3)
	{
		// Determinate the super triangle
		double minX = _pointers[0]->x();
		double minY = _pointers[0]->y();
		double maxX = minX;
		double maxY = minY;

		for (std::size_t i = 0; i < _pointers.size(); ++i)
		{
			if (_pointers[i]->x() < minX) minX = _pointers[i]->x();
			if (_pointers[i]->y() < minY) minY = _pointers[i]->y();
			if (_pointers[i]->x() > maxX) maxX = _pointers[i]->x();
			if (_pointers[i]->y() > maxY) maxY = _pointers[i]->y();
		}

		const double dx = maxX - minX;
		const double dy = maxY - minY;
		const double deltaMax = std::max(dx, dy);
		const double midx = half(minX + maxX);
		const double midy = half(minY + maxY);

		const QPointF p1(midx - 20 * deltaMax, midy - deltaMax);
		const QPointF p2(midx, midy + 20 * deltaMax);
		const QPointF p3(midx + 20 * deltaMax, midy - deltaMax);

		//std::cout << "Super triangle " << std::endl << Triangle(p1, p2, p3) << std::endl;

		// Create a list of triangles, and add the super triangle in it
		QTriangle *supertriangle = new QTriangle(p1, p2, p3);

		_triangles.push_back(supertriangle);

		for (auto p = _pointers.begin(); p != _pointers.end(); p++)
		{
			//std::cout << "Traitement du point " << *p << std::endl;
			//std::cout << "_triangles contains " << _triangles.size() << " elements" << std::endl;

			QVector<QEdge> polygon;

			for (auto & t : _triangles)
			{
				if (t->hasCircleCircum(**p))
				{
					t->makeBad(true);
					polygon.push_back(t->edge1());
					polygon.push_back(t->edge2());
					polygon.push_back(t->edge3());
				}
			}

			_triangles.erase(std::remove_if(_triangles.begin(), _triangles.end(), [](QTriangle *t) { return t->isBad(); }), _triangles.end());

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
				QTriangle * newTriangle = new QTriangle(e.p1(), e.p2(), **p);
				_triangles.push_back(newTriangle);
			}

		}

		_triangles.erase(std::remove_if(_triangles.begin(), _triangles.end(),
			[p1, p2, p3](QTriangle *t) { return t->hasPoint(p1) || t->hasPoint(p2) || t->hasPoint(p3);	})
			, _triangles.end());

		for (const auto t : _triangles)
		{
			_edges.push_back(&(t->edge1()));
			_edges.push_back(&(t->edge2()));
			_edges.push_back(&(t->edge3()));
		}
	}
	return _triangles;
}
