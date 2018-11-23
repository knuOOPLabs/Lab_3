#pragma once

#include <QtWidgets/QWidget>
#include "ui_Lab_3.h"

class Lab_3 : public QWidget
{
	Q_OBJECT

public:
	Lab_3(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab_3Class ui;
};
