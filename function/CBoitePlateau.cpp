// CBoitePlateau.cpp : implementation file
//

#include "pch.h"
#include "Projet.h"
#include "CBoitePlateau.h"
#include "afxdialogex.h"


// CBoitePlateau dialog

IMPLEMENT_DYNAMIC(CBoitePlateau, CDialog)

CBoitePlateau::CBoitePlateau(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_Pixel_x(32)
	, m_Pixel_y(32)
	, m_Taille_x(8)
	, m_taille_y(8)
	, m_Nbr_p(6)
{

}

CBoitePlateau::~CBoitePlateau()
{
}

void CBoitePlateau::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PIXEL_X, m_Pixel_x);
	DDX_Text(pDX, IDC_PIXEL_Y, m_Pixel_y);
	DDX_Text(pDX, IDC_TAILLE_X, m_Taille_x);
	DDX_Text(pDX, IDC_TAILLE_Y, m_taille_y);
	DDX_Text(pDX, IDC_N_PIERRE, m_Nbr_p);
}


BEGIN_MESSAGE_MAP(CBoitePlateau, CDialog)
	ON_EN_CHANGE(IDC_TAILLE_Y, &CBoitePlateau::OnEnChangeTailleY)
END_MESSAGE_MAP()


// CBoitePlateau message handlers


void CBoitePlateau::OnEnChangeTailleY()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
