#pragma once

#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>

class modeMenu : public QGroupBox
{
	Q_OBJECT

public:
	modeMenu();
	~modeMenu();

	


private:

	QPushButton * pDlnTr;
	QPushButton * pVrnDiagr;
	QPushButton * pCnvxShell;
	QPushButton * pCircle;

	void propsToButt(QPushButton * butt);	
};
