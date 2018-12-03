#include "DelanauTriangulate.h"



CDelanauTriangulate::CDelanauTriangulate() {}


CDelanauTriangulate::CDelanauTriangulate(const QVector<myQPoint > &_pointers)
	:pointers(_pointers)
{}

CDelanauTriangulate::~CDelanauTriangulate()
{
}

void CDelanauTriangulate::build()
{
	//List<Polygon*> *triangles = new List<Polygon*>;
	//triangles;

	// Determinate the super triangle
	double minX = pointers[0].x();
	double minY = pointers[0].y();
	double maxX = minX;
	double maxY = minY;

	for (std::size_t i = 0; i < pointers.size(); ++i)
	{
		if (pointers[i].x() < minX) minX = pointers[i].x();
		if (pointers[i].y() < minY) minY = pointers[i].y();
		if (pointers[i].x() > maxX) maxX = pointers[i].x();
		if (pointers[i].y() > maxY) maxY = pointers[i].y();
	}

	const double dx = maxX - minX;
	const double dy = maxY - minY;
	const double deltaMax = std::max(dx, dy);
	const double midx = half(minX + maxX);
	const double midy = half(minY + maxY);

	const myQPoint p1(midx - 20 * deltaMax, midy - deltaMax);
	const myQPoint p2(midx, midy + 20 * deltaMax);
	const myQPoint p3(midx + 20 * deltaMax, midy - deltaMax);

	//std::cout << "Super triangle " << std::endl << Triangle(p1, p2, p3) << std::endl;

	// Create a list of triangles, and add the super triangle in it
	triangles.push_back(QTriangle(p1, p2, p3));

	for (auto p = pointers.begin(); p != pointers.end(); p++)
	{
		//std::cout << "Traitement du point " << *p << std::endl;
		//std::cout << "_triangles contains " << _triangles.size() << " elements" << std::endl;

		QVector<QEdge> polygon;

		for (auto & t : triangles)
		{
			//std::cout << "Processing " << std::endl << *t << std::endl;

			if (t.hasCircleCircum(*p))
			{
				//std::cout << "Pushing bad triangle " << *t << std::endl;
				t.makeBad(true);
				polygon.push_back(t.edge1());
				polygon.push_back(t.edge2());
				polygon.push_back(t.edge3());
			}
			else
			{
				//std::cout << " does not contains " << *p << " in his circum center" << std::endl;
			}
		}

		triangles.erase(std::remove_if(triangles.begin(), triangles.end(), [](QTriangle &t) { return t.isBad(); }), triangles.end());

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

		polygon.erase(std::remove_if(polygon.begin(), polygon.end(), [](QEdge &e) {
			return e.isBad();
		}), polygon.end());

		for (const auto e : polygon)
			triangles.push_back(QTriangle(e.p1(), e.p2(), *p));

	}

	triangles.erase(std::remove_if(triangles.begin(), triangles.end(), [p1, p2, p3](QTriangle &t) {
		return t.hasPoint(p1) || t.hasPoint(p2) || t.hasPoint(p3);
	}), triangles.end());

	for (const auto t : triangles)
	{
		edges.push_back(t.edge1());
		edges.push_back(t.edge2());
		edges.push_back(t.edge3());
	}
}
