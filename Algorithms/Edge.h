#pragma once

#include "myQPoint.h"
//#include "qgeometry.h"

class QEdge : public QLineF
{
public:

	bool isBad() const;					//	will be realized as vector of bad QLineF
	void makeBad(const bool res);		//	will be realized as vector of bad QLineF

	friend bool almost_equal(const QEdge & e1, const QEdge & e2);	//	REWORKED as friend

private:

	//myQPoint _p1;
	//myQPoint _p2;

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






