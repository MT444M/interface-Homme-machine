
// ProjetView.cpp : implementation of the CProjetView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Projet.h"
#endif

#include "ProjetDoc.h"
#include "ProjetView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProjetView

IMPLEMENT_DYNCREATE(CProjetView, CView)

BEGIN_MESSAGE_MAP(CProjetView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CProjetView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CProjetView construction/destruction

CProjetView::CProjetView() noexcept
{
	// TODO: add construction code here

}

CProjetView::~CProjetView()
{
}

COLORREF CProjetView::Color(int k) {
	switch (k)
	{
	case 0:
		return RGB(0, 0, 0);
		break;
	case 1:
		return RGB(255, 0, 0);
		break;
	case 2:
		return RGB(0, 255, 0);
		break;
	case 3:
		return RGB(255, 255, 0);
		break;
	case 4:
		return RGB(0, 0, 255);
		break;
	case 5:
		return RGB(128, 255, 255);
		break;
	default:
		return RGB(255, 255, 255);
		break;
	}
}


/* Dessiner les cercles colorés sur le plateau */
void CProjetView::dessiner_Objet(CDC* pDC) {
	
	CProjetDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(rect);

	/* Définir les coordonnées de départ et les dimensions des cercles */
	/*
	int x_debut = 100;
	int y_debut = 100;
	int diametre = 50;
	*/
	int espace = 5; // ajout de l'espace entre les cercles
	int x_debut = 100; // + espace; // ajustement des coordonnées x_debut pour inclure l'espace
	int y_debut = 100; //+ espace; // ajustement des coordonnées y_debut pour inclure l'espace
	int diametre = 50 - 2*espace; // ajustement du diamètre pour inclure l'espace
	int pixel = 50;

	srand(time(NULL));  // Initialiser le générateur de nombres aléatoires avec l'heure actuelle
	if (pDoc->pPlateauDoc != NULL)
	{
		/* Dessiner les cercles */
		for (int i = 0; i < pDoc->pPlateauDoc->getTaille_x(); i++) {
			for (int j = 0; j < pDoc->pPlateauDoc->getTaille_x(); j++) {
				int couleur = (i + j + rand()) % (pDoc->pPlateauDoc->getNbr_p() + 1);  // +1 pour inclure la couleur blanche 
				CBrush brush(Color(couleur));
				CBrush* poldBrush = pDC->SelectObject(&brush);
				pDC->Ellipse(x_debut + i * diametre + i * espace, y_debut + j * diametre + j * espace, x_debut + (i + 1) * diametre + i * espace, y_debut + (j + 1) * diametre + j * espace);				pDC->SelectObject(poldBrush);
				pDC->SelectObject(poldBrush);

				if (pDC->GetPixel(100 + i * pixel + pixel / 2, 100 + j * pixel + pixel / 2) == Color(couleur)) {
					pDoc->pPlateauDoc->remplir_plateau(1);
				}
			}
		}
	}
	ReleaseDC(pDC);
}


BOOL CProjetView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CProjetView drawing

void CProjetView::OnDraw(CDC* pDC)
{
	CProjetDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(rect);

	CPen penRect;
	penRect.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&penRect);

	pDC->Rectangle(100, 100, 70 * 8, 70 * 8);

	/* Dessiner les cercles sur le plateau */
	dessiner_Objet(pDC);
	
}


// CProjetView printing


void CProjetView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CProjetView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProjetView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProjetView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CProjetView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CProjetView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CProjetView diagnostics

#ifdef _DEBUG
void CProjetView::AssertValid() const
{
	CView::AssertValid();
}

void CProjetView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjetDoc* CProjetView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjetDoc)));
	return (CProjetDoc*)m_pDocument;
}
#endif //_DEBUG


// CProjetView message handlers


void CProjetView::OnLButtonDown(UINT nFlags, CPoint point)
{


	CView::OnLButtonDown(nFlags, point);
}
