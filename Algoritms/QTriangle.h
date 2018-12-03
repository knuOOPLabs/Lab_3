#pragma once

//#include <QLineF>
#include "Edge.h"
#include <fstream>

class QTriangle
{
public:
	QTriangle() : _p1(0.0, 0.0), _p2(0.0, 0.0), _p3(0.0, 0.0) {}
	QTriangle(const myQPoint & _p1, const myQPoint & _p2, const myQPoint & _p3);
	~QTriangle();

	myQPoint p1() const;
	myQPoint p2() const;
	myQPoint p3() const;

	QEdge edge1() const;
	QEdge edge2() const;
	QEdge edge3() const;

	bool isBad() const;

	void makeBad(const bool res);

	bool hasPoint(const myQPoint & point) const;
	bool hasCircleCircum(const myQPoint & point) const;

	bool operator == (const QTriangle & other);
	//friend std::ostream &operator << (std::ostream & res, const QTriangle & tr);

	friend bool almost_equal(const QTriangle &t1, const QTriangle &t2);

private:
	myQPoint _p1, _p2, _p3;
	QEdge _edge1, _edge2, _edge3;
	bool _isBad;
};

//template <class T>
//inline bool almost_equal(const Triangle<T> &t1, const Triangle<T> &t2)
//{
//	return	(almost_equal(t1.p1, t2.p1) || almost_equal(t1.p1, t2.p2) || almost_equal(t1.p1, t2.p3)) &&
//		(almost_equal(t1.p2, t2.p1) || almost_equal(t1.p2, t2.p2) || almost_equal(t1.p2, t2.p3)) &&
//		(almost_equal(t1.p3, t2.p1) || almost_equal(t1.p3, t2.p2) || almost_equal(t1.p3, t2.p3));
//}