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

private:

	QPushButton * pAdd;
	QTextEdit * pX;
	QTextEdit * pY;
};
