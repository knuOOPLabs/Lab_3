#pragma once

#include <QGroupBox>
#include <QPushButton>
#include <QTextEdit>


class optCoordPoints : public QGroupBox
{
	Q_OBJECT

public:
	optCoordPoints();
	~optCoordPoints();

public slots:


private:

	QPushButton * pAdd;
	QTextEdit * pX;
	QTextEdit * pY;
};
