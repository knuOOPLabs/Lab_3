#include "MainWindow.h"

#include <QBoxLayout>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>

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
	connect(pAddPointsMenu->randButt()->genButt(), SIGNAL(clicked()), this, SLOT(genPoints()));

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

void MainWindow::genPoints()
{
	int pointsNum = pAddPointsMenu->randButt()->pointsNum()->toPlainText().toInt();

	srand(time(NULL));

	_points.clear();

	for (int i = 0; i < pointsNum; ++i)
	{
		QPointF * pnewPoint = new QPointF(50 + rand() % (pPaintArea->size().width() - 50), 50 + rand() % (pPaintArea->size().height() - 50));
		_points.push_back(pnewPoint);
	}
	build();
}

void MainWindow::buildDelanau()
{
	if (_points.size() > 2)
	{
		
		_triangles.clear();
		CDelanauTriangulate del(&_points, &_triangles);

		std::thread th(&CDelanauTriangulate::triangulate, del);
		th.detach();
	}
}

void MainWindow::buildVorony()
{

}

void MainWindow::buildShell()
{
	if (_points.size() > 2)
	{
		_cnvxShell.clear();
		Grehem greh(&_points, &_cnvxShell);
		std::thread th(&Grehem::GrehemMethod, greh);
		th.detach();
	}
}

