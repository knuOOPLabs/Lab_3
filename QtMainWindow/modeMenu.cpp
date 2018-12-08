#include "modeMenu.h"

modeMenu::modeMenu(): QGroupBox()
{
	setTitle("Mode");

	pDlnTr = new QPushButton("Delanau Triangulate");
	pVrnDiagr = new QPushButton("Vorony Diagram");
	pCnvxShell = new QPushButton("Convex Shell");
	pCircle = new QPushButton("Circles");

	pDlnTr->setCheckable(true);
	pVrnDiagr->setCheckable(true);
	pCnvxShell->setCheckable(true);
	pCircle->setCheckable(true);

	pDlnTr->setChecked(true);

	QHBoxLayout *pLOut = new QHBoxLayout();

	pLOut->setMargin(15);

	pLOut->addWidget(pDlnTr);
	pLOut->addWidget(pVrnDiagr);
	pLOut->addWidget(pCnvxShell);
	pLOut->addWidget(pCircle);
	
	setLayout(pLOut);
}

modeMenu::~modeMenu()
{
}

const QPushButton * modeMenu::getButtDel() const
{
	return pDlnTr;
}

const QPushButton * modeMenu::getButtVor() const
{
	return pVrnDiagr;
}

const QPushButton * modeMenu::getButtShell() const
{
	return pCnvxShell;
}

const QPushButton * modeMenu::getButtCircl() const
{
	return pCircle;
}

//void modeMenu::propsToButt(QPushButton * butt)
//{
//
//}
