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


public slots:
	void setPaintDel(bool);
	void setPaintVor(bool);
	void setPaintShell(bool);
	void setPaintCircl(bool);

	//setPaintDel(true)));
	//setPaintVor(true)));
	//setPaintShell(true)));
	//setPaintCirlc(true)));
private:

	bool _paintDel
		, _paintVor
		, _paintShell
		, _paintCircl;

	QVector<QPointF> points;

	void paintDel();
	void paintVor();
	void paintShell();
	void paintCircl();

protected:

	void paintEvent(QPaintEvent *event) override;
	void mousePressEvent(QMouseEvent* ре) override;
};
