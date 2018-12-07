#include "optRandPoints.h"

#include <QVBoxLayout>

optRandPoints::optRandPoints()
	: QGroupBox()
{
	setTitle("Generate Points");

	pGenButt = new QPushButton("Generate");
	pPointsNum = new QTextEdit();

	QVBoxLayout * pLOut = new QVBoxLayout();
	pLOut->setMargin(10);

	pLOut->addWidget(pPointsNum);
	pLOut->addWidget(pGenButt);

	setLayout(pLOut);

}

optRandPoints::~optRandPoints()
{
}

const QTextEdit * optRandPoints::pointsNum() const
{
	return pPointsNum;
}

const QPushButton * optRandPoints::genButt() const
{
	return pGenButt;
}

void optRandPoints::getPoints(QVector<QPointF> & vect)
{
	//unsigned int numOfPoints = QTextEdit::paste();
}
