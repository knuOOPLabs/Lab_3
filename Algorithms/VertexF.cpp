#include "VertexF.h"



CVertex::CVertex(double x, double у) :
	Point(x, у)
{
}

CVertex::CVertex(Point &p) :
	Point(p)
{
}

CVertex *CVertex::getNextV() const
{
	return (CVertex*)_next;
}

CVertex *CVertex::getPrevV() const
{
	return (CVertex*)_prev;
}

CVertex *CVertex::neighbor(ROTATION rotation) const
{
	return ((rotation == CLOCKWISE) ? getNextV() : getPrevV());
}

Point CVertex::point() const
{
	return  *((Point*)this);
}

CVertex *CVertex::insert(CVertex *v)
{
	return (CVertex *)(CNode::insert(v));
}

CVertex *CVertex::remove()
{
	return (CVertex *)(CNode::remove());
}
void CVertex::splice(CVertex *b)
{
	CNode::splice(b);
}

CVertex *CVertex::split(CVertex *b)
{	                    // занесение bр перед вершиной b
	CVertex *bр = b->getPrevV()->insert(new CVertex(b->point()));
	insert(new CVertex(point()));
	// занесение ар после текущей вершины
	splice(bр);
	return bр;
}