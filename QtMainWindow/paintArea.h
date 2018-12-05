#pragma once

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QVector>
#include <QPoint>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>

class paintArea : public QWidget
{
	Q_OBJECT

public:
	paintArea(QWidget * parent = 0);
	~paintArea();
	
	QSize minimumSizeHint() const override;
	QSize sizeHint() const override;

private:

	QGraphicsScene * scene;
	QTimer * timer;

	QVector<QPointF> points;

	//paintEvent()

protected:

	void paintEvent(QPaintEvent *event) override;
	void resizeEvent(QResizeEvent *event);

	QGraphicsItemGroup * group;



	virtual void mousePressEvent(QMouseEvent* ре);
	//virtual void mouseReleaseEvent(QMouseEvent* ре);
	//virtual void mouseMoveEvent(QMouseEvent* ре);
};
