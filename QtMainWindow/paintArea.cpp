#include "paintArea.h"
#include <QBoxLayout>
#include <QPainter>

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
}

void paintArea::setPaintVor(bool res)
{
	_paintVor = res;
}

void paintArea::setPaintShell(bool res)
{
	_paintShell = res;
}

void paintArea::setPaintCircl(bool res)
{
	_paintCircl = res;
}

void paintArea::paintDel()
{

}

void paintArea::paintVor()
{

}

void paintArea::paintShell()
{

}

void paintArea::paintCircl()
{

}

void paintArea::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setBrush(QBrush(Qt::white));
	painter.setPen(QPen(Qt::white));
	painter.drawRect(event->rect());


	painter.setBrush(QBrush(Qt::black));
	painter.setPen(QPen(Qt::black));
	for (int i = 0; i < points.size(); ++i)
	{
		painter.drawPoint(points[i]);
	}

	if (_paintDel) paintDel();
	if (_paintVor) paintVor();
	if (_paintShell) paintShell();
	if (_paintCircl) paintCircl();
}

void paintArea::mousePressEvent(QMouseEvent* event )
{
	points.push_back(QPointF(event->pos()));
	update();
}
