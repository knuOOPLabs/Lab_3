#pragma once

#include <QtWidgets/QWidget>
#include <QMainWindow>
#include <QList>
#include <QVector>

#include "modeMenu.h"
#include "paintArea.h"
#include "addPointsMenu.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow();

public slots:
	void rebuild();
	void build();
	void genPoints();


private:
	paintArea * pPaintArea;
	modeMenu * pModeMenu;
	addPointsMenu * pAddPointsMenu;

	QVector<const QPointF *> _points;
	QVector<QTriangle *> _triangles;
	QPolygonF _cnvxShell;

	void buildDelanau();
	void buildVorony();
	void buildShell();
};
