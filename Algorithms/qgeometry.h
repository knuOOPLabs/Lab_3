#include <cmath>
#include <limits>
#include <QPoint>
#include <QLine>


inline bool almost_equal(double x, double y, int ulp = 2);

template<class T>
T half(T x) {}

template <>
inline float half(float x) { return 0.5f * x; }

template <>
inline double half(double x) { return 0.5 * x; }

double dist2(const QPointF &p1, const QPointF &p2);	//	from myQPiont

double dist(const QPointF &p1, const QPointF &p2);	//	from myQPiont

double norm2(const QPointF &p1);					//	from myQPiont

bool almost_equal(const QPointF& p1, const QPointF& p2, int ulp = 2);	//	reworked as a friend function from myQPiont

bool almost_equal(const QLineF & l1, const QLineF & l2, int ulp = 2);	//	REWORKED as a friend function from QEdge

inline bool operator == (const QLineF & l1, const QLineF & l2);