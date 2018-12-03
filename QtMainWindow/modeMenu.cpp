#include "modeMenu.h"

modeMenu::modeMenu(): QGroupBox()
{
	setTitle("Mode");

	pDlnTr = new QPushButton("Delanau Triangulate");
	pVrnDiagr = new QPushButton("Vorony Diagram");
	pCnvxShell = new QPushButton("Convex Shell");
	pCircle = new QPushButton("Circles");

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

void modeMenu::propsToButt(QPushButton * butt)
{

}
