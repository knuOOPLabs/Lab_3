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

	const QTextEdit * pointsNum() const;
	const QPushButton * genButt() const;

public slots:
	void getPoints(QVector<QPointF> &);

private:

	QTextEdit * pPointsNum;
	QPushButton * pGenButt;
};
