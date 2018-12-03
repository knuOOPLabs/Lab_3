#pragma once

#include <QGroupBox>
#include <QPushButton>
#include <QTextEdit>

class optRandPoints : public QGroupBox
{
	Q_OBJECT

public:
	optRandPoints();
	~optRandPoints();

private:

	QTextEdit * pPointsNum;
	QPushButton * pGenButt;
};
