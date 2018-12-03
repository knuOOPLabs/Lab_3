#include "addPointsMenu.h"

#include <QVBoxLayout>

addPointsMenu::addPointsMenu()
	: QGroupBox()
{
	setTitle("Add Points");

	prand = new optRandPoints();
	pdown = new optDownPoints();
	pcoord = new optCoordPoints();

	QVBoxLayout * pLOut = new QVBoxLayout();
	pLOut->setMargin(10);
	pLOut->addWidget(prand);
	pLOut->addWidget(pdown);
	pLOut->addWidget(pcoord);

	setLayout(pLOut);
}

addPointsMenu::~addPointsMenu()
{
}
