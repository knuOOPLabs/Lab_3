#pragma once

#include "myQPoint.h"
//#include "qgeometry.h"

class QEdge
{
public:
	//using VertexType = Vector2<T>;
	QEdge() : _p1(0, 0), _p2(0, 0) {}
	QEdge(const myQPoint &p1, const myQPoint &p2) : _p1(p1), _p2(p2), _isBad(false) {};
	QEdge(const QEdge &e) : _p1(e.p1()), _p2(e.p2()), _isBad(false) {};

	myQPoint p1() const;
	myQPoint p2() const;

	void setPoints(const myQPoint &p1, const myQPoint &p2);

	bool isBad() const;
	void makeBad(const bool res);

	friend bool almost_equal(const QEdge & e1, const QEdge & e2);

private:

	myQPoint _p1;
	myQPoint _p2;

	bool _isBad;
};


inline bool operator == (const QEdge & e1, const QEdge & e2)
{
	return 	(e1.p1() == e2.p1() && e1.p2() == e2.p2()) ||
		(e1.p1() == e2.p2() && e1.p2() == e2.p1());
}

//template <class T>
//inline bool almost_equal(const Edge<T> & e1, const Edge<T> & e2)
//{
//	return	(almost_equal(e1.p1, e2.p1) && almost_equal(e1.p2, e2.p2)) ||
//		(almost_equal(e1.p1, e2.p2) && almost_equal(e1.p2, e2.p1));
//}






