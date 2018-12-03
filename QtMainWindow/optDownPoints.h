#pragma once

#include <QGroupBox>
#include <QPushButton>
#include <QTextEdit>

class optDownPoints : public QGroupBox
{
	Q_OBJECT

public:
	optDownPoints();
	~optDownPoints();

private:

	QPushButton * pDown;
	QTextEdit * pPath;

};
