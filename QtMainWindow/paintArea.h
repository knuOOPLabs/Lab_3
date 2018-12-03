#pragma once

#include <QWidget>

class paintArea : public QWidget
{
	Q_OBJECT

public:
	paintArea(QWidget * parent = 0);
	~paintArea();
	
	QSize minimumSizeHint() const override;
	QSize sizeHint() const override;

};
