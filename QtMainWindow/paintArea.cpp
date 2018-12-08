#include "paintArea.h"
#include <QBoxLayout>
#include <QPainter>
#include <random>
#include <ctime>

paintArea::paintArea(QVector<const QPointF *> & points, QVector<QTriangle *> & triangles, QPolygonF & cnvxShell, QWidget * parent)
	: QWidget(parent)
	, _paintDel(true)
	, _paintVor(false)
	, _paintShell(false)
	, _paintCircl(false)
{
	_points = &points;
	_triangles = &triangles;
	_cnvxShell = &cnvxShell;
}

paintArea::paintArea(QWidget * parent)
	: QWidget(parent)
	, _paintDel(true)
	, _paintVor(false)
	, _paintShell(false)
	, _paintCircl(false)
{

}

paintArea::~paintArea()
{
}

QSize paintArea::minimumSizeHint() const
{
	return QSize(50, 50);
}

QSize paintArea::sizeHint() const
{
	return QSize(100, 100);
}

void paintArea::setPaintDel(bool res)
{
	_paintDel = res;
	update();
}

void paintArea::setPaintVor(bool res)
{
	_paintVor = res;
	update();
}

void paintArea::setPaintShell(bool res)
{
	_paintShell = res;
	update();
}

void paintArea::setPaintCircl(bool res)
{
	_paintCircl = res;
	update();
}


void paintArea::paintRect(QPaintEvent *event)
{
	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setBrush(QBrush(Qt::white));
	painter.setPen(QPen(Qt::white));
	painter.drawRect(event->rect());
}

void paintArea::paintPoints(QPaintEvent *event)
{
	QPainter painter(this);

	QPen pen;
	pen.setWidth(3);
	pen.setColor(Qt::black);
	painter.setPen(pen);

	for (int i = 0; i < _points->size(); ++i)
	{
		//QPointF p = ;
		painter.drawPoint(*(*_points)[i]);
	}
}

void paintArea::paintDel(QPaintEvent *event)
{
	QPainter painter(this);

	QPen pen;
	pen.setWidth(1);
	pen.setColor(Qt::black);
	painter.setPen(pen);

	for (int i = 0; i < _triangles->size(); ++i)
	{
		painter.drawPolygon((*_triangles)[i]->polygon());
	}
}

void paintArea::paintVor(QPaintEvent *event)
{

}

void paintArea::paintShell(QPaintEvent *event)
{
	QPainter painter(this);

	QPen pen;
	pen.setWidth(2);
	pen.setColor(Qt::red);
	painter.setPen(pen);

	painter.drawPolygon(*_cnvxShell);
}

void paintArea::paintCircl(QPaintEvent *event)
{

}

void paintArea::paintEvent(QPaintEvent *event)
{	
	paintRect(event);
	paintPoints(event);
	if (_paintDel) paintDel(event);
	if (_paintVor) paintVor(event);
	if (_paintShell) paintShell(event);
	if (_paintCircl) paintCircl(event);
}

void paintArea::mousePressEvent(QMouseEvent* event )
{
	QPointF * newPoint = new QPointF(event->pos());
	_points->push_back(newPoint);
	emit addPoint();
	//update();
}
