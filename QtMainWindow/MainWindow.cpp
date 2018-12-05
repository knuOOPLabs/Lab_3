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
	
	setLayout(pmainLOut);

	connect(pModeMenu->getButtDel(), SIGNAL(toggled(bool)), pPaintArea, SLOT(setPaintDel(bool)));
	connect(pModeMenu->getButtVor(), SIGNAL(toggled(bool)), pPaintArea, SLOT(setPaintVor(bool)));
	connect(pModeMenu->getButtShell(), SIGNAL(toggled(bool)), pPaintArea, SLOT(setPaintShell(bool)));
	connect(pModeMenu->getButtCircl(), SIGNAL(toggled(bool)), pPaintArea, SLOT(setPaintCircl(bool)));

	//connect(pModeMenu->getButtDel(), SIGNAL(toggled(false)), pPaintArea, SLOT(setPaintDel(false)));
	//connect(pModeMenu->getButtVor(), SIGNAL(toggled(false)), pPaintArea, SLOT(setPaintVor(false)));
	//connect(pModeMenu->getButtShell(), SIGNAL(toggled(false)), pPaintArea, SLOT(setPaintShell(false)));
	//connect(pModeMenu->getButtCircl(), SIGNAL(toggled(false)), pPaintArea, SLOT(setPaintCircl(false)));
}




