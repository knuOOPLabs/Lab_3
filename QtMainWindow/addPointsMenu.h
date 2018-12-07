#pragma once

#include <QGroupBox>

#include "optRandPoints.h"
#include "optDownPoints.h"
#include "optCoordPoints.h"


class addPointsMenu : public QGroupBox
{
	Q_OBJECT

public:
	addPointsMenu();
	~addPointsMenu();

	const optRandPoints * randButt() const;
	const optDownPoints * downButt() const;
	const optCoordPoints * coordButt() const;

private:

	optRandPoints * prand;
	optDownPoints * pdown;
	optCoordPoints * pcoord;
};
