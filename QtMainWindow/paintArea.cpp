#include "paintArea.h"
#include <QBoxLayout>
#include <QPainter>

paintArea::paintArea(QWidget * parent)
	: QWidget(parent)
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
}

void paintArea::resizeEvent(QResizeEvent *event)
{

}

void paintArea::mousePressEvent(QMouseEvent* event )
{
	points.push_back(QPointF(event->pos()));
	update();
}
