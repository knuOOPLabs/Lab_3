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
#include "QTriangle.h"


class paintArea : public QWidget
{
	Q_OBJECT

public:
	paintArea(QWidget * parent = 0);
	paintArea(QVector<QPointF *> &, QVector<QTriangle *> &, QWidget * parent = 0);
	~paintArea();
	
	QSize minimumSizeHint() const override;
	QSize sizeHint() const override;


public slots:
	void setPaintDel(bool);
	void setPaintVor(bool);
	void setPaintShell(bool);
	void setPaintCircl(bool);

	//void newAsigment(QVector<QPointF *>, QVector<QTriangle *>);

signals:
	void addPoint();

private:

	bool _paintDel
		, _paintVor
		, _paintShell
		, _paintCircl;

	QVector<QPointF *> * _points;
	QVector<QTriangle *> * _triangles;

	void paintRect(QPaintEvent *event);
	void paintPoints(QPaintEvent *event);
	void paintDel(QPaintEvent *event);
	void paintVor(QPaintEvent *event);
	void paintShell(QPaintEvent *event);
	void paintCircl(QPaintEvent *event);

	void buildDel();

protected:

	void paintEvent(QPaintEvent *event) override;
	void mousePressEvent(QMouseEvent* ре) override;
};
