#include "optDownPoints.h"

#include <QVBoxLayout>

optDownPoints::optDownPoints()
	: QGroupBox()
{
	setTitle("Download Points");

	pDown = new QPushButton("Download");
	pPath = new QTextEdit();

	QVBoxLayout * pLOut = new QVBoxLayout();
	pLOut->setMargin(15);

	pLOut->addWidget(pPath);
	pLOut->addWidget(pDown);

	setLayout(pLOut);
}

optDownPoints::~optDownPoints()
{
}
