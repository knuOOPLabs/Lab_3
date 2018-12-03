#pragma once

#include "Point.h"
#include "Node.h"

enum ROTATION { CLOCKWISE = 0, COUNTER_CLOCKWISE };

class CVertex : public CNode, public Point
{
public:

	CVertex(double x, double y);
	CVertex(Point&);
	
	CVertex *getNextV() const;
	CVertex *getPrevV() const;
	
	CVertex *neighbor(ROTATION rotation) const;
	
	Point point() const;
	
	CVertex *insert(CVertex* _new);
	CVertex *remove();
	void splice(CVertex*);
	CVertex *split(CVertex*);
	friend class Polygon;
};

