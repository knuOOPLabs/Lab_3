#include "MainWindow.h"

#include <QBoxLayout>

#include "DelanauTriangulate.h"
#include "Grehem.h"

MainWindow::MainWindow()
{
	pPaintArea = new paintArea(_points, _triangles, _cnvxShell);
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

	// setup modeMenu
	connect(pModeMenu->getButtDel(), SIGNAL(toggled(bool)), pPaintArea, SLOT(setPaintDel(bool)));
	connect(pModeMenu->getButtVor(), SIGNAL(toggled(bool)), pPaintArea, SLOT(setPaintVor(bool)));
	connect(pModeMenu->getButtShell(), SIGNAL(toggled(bool)), pPaintArea, SLOT(setPaintShell(bool)));
	connect(pModeMenu->getButtCircl(), SIGNAL(toggled(bool)), pPaintArea, SLOT(setPaintCircl(bool)));

	//setup random points
	connect(pAddPointsMenu->randButt()->genButt(), SIGNAL(clicked()), pPaintArea, SLOT(genPoints()));

	// build new diagrams my adding new point by mouse clicking
	connect(pPaintArea, SIGNAL(addPoint()), this, SLOT(build()));

}

void MainWindow::rebuild()
{
	build();
}

void MainWindow::build()
{
	buildDelanau();
	buildVorony();
	buildShell();

	pPaintArea->update();
}

void MainWindow::buildDelanau()
{
	_triangles.clear();

	CDelanauTriangulate del;
	del.downPoints(_points);

	_triangles = del.triangulate();
}

void MainWindow::buildVorony()
{

}

void MainWindow::buildShell()
{
	_cnvxShell.clear();
	Grehem greh(&_points);

	_cnvxShell = greh.GrehemMethod();
}

