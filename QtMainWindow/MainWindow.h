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

private:
	
	paintArea * pPaintArea;
	modeMenu * pModeMenu;
	addPointsMenu * pAddPointsMenu;
};
