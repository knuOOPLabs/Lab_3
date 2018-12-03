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

private:

	optRandPoints * prand;
	optDownPoints * pdown;
	optCoordPoints * pcoord;
};
