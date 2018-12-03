#include "optCoordPoints.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

optCoordPoints::optCoordPoints()
	: QGroupBox()
{
	setTitle("Add by Coords");

	pX = new QTextEdit();
	pY = new QTextEdit();
	pAdd = new QPushButton("Add");

	QHBoxLayout * pCoords = new QHBoxLayout();
	pCoords->setMargin(5);
	pCoords->addWidget(pX);
	pCoords->addWidget(pY);

	QVBoxLayout * pLOut = new QVBoxLayout();
	pLOut->setMargin(15);

	pLOut->addLayout(pCoords);
	pLOut->addWidget(pAdd);

	setLayout(pLOut);
}

optCoordPoints::~optCoordPoints()
{
}
