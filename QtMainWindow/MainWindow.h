#pragma once

#include <QtWidgets/QWidget>
#include <QMainWindow>
#include <QList>
#include <QVector>

#include "modeMenu.h"
#include "paintArea.h"
#include "addPointsMenu.h"
#include "DelanauTriangulate.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow();

public slots:
	void rebuild();
	void build();

private:
	paintArea * pPaintArea;
	modeMenu * pModeMenu;
	addPointsMenu * pAddPointsMenu;

	QVector<QPointF *> _points;
	QVector<QTriangle *> _triangles;

	void buildDelanau();
	void buildVorony();
	void buildShell();
};
