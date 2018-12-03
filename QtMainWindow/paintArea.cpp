#include "paintArea.h"
#include <QBoxLayout>

paintArea::paintArea(QWidget * parent)
	: QWidget(parent)
{
	setMinimumSize(50, 50);

	//setStyleSheet("background-color:white;");

	//QVBoxLayout *playout = new QVBoxLayout();
	//playout->addWidget(this);
	//setLayout(playout);
}

paintArea::~paintArea()
{
}

QSize paintArea::minimumSizeHint() const
{
	return QSize(50, 50);
}

QSize paintArea::sizeHint() const
{
	return QSize(100, 100);
}
