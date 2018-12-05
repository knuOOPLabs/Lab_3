#include "MainWindow.h"

#include <QBoxLayout>
MainWindow::MainWindow()
{
	pPaintArea = new paintArea();
	pPaintArea->setStyleSheet("background-color:white;");
	pModeMenu = new modeMenu();
	pAddPointsMenu = new addPointsMenu();

	QHBoxLayout * pupper = new QHBoxLayout();
	pupper->setMargin(5);
	pupper->addWidget(pAddPointsMenu, 1);
	pupper->addWidget(pPaintArea, 10);

	QVBoxLayout * pmainLOut = new QVBoxLayout();
	pmainLOut->setMargin(10);
	pmainLOut->addLayout(pupper);
	pmainLOut->addWidget(pModeMenu);

	//QGridLayout *pLOut = new QGridLayout();
	//pLOut->setMargin(20);
	//pLOut->addWidget(pAddPointsMenu, 0, 0, 4, 1);
	//pLOut->addWidget(pPaintArea, 0, 1, 4, 5);
	//pLOut->addWidget(pModeMenu, 4, 0, 1, 6);
	
	setLayout(pmainLOut);
}




