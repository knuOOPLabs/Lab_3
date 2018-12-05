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

	const QPushButton * getButtDel() const;
	const QPushButton * getButtVor() const;
	const QPushButton * getButtShell() const;
	const QPushButton * getButtCircl() const;

private:

	QPushButton * pDlnTr;
	QPushButton * pVrnDiagr;
	QPushButton * pCnvxShell;
	QPushButton * pCircle;

	//void propsToButt(QPushButton * butt);	
};
