#pragma once


// CBoitePlateau dialog

class CBoitePlateau : public CDialog
{
	DECLARE_DYNAMIC(CBoitePlateau)

public:
	CBoitePlateau(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CBoitePlateau();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_Pixel_x;
	int m_Pixel_y;
	int m_Taille_x;
	afx_msg void OnEnChangeTailleY();
	int m_taille_y;
	int m_Nbr_p;
};
