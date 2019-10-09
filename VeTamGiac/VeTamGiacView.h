
// VeTamGiacView.h : interface of the CVeTamGiacView class
//

#pragma once
#include "PhimBam.h"
#include "HCN.h"
#include "VeHinh.h"
#include "Tamgiac.h"

class CVeTamGiacView : public CView
{
protected: // create from serialization only
	CVeTamGiacView() noexcept;
	DECLARE_DYNCREATE(CVeTamGiacView)

// Attributes
public:
	CVeTamGiacDoc* GetDocument() const;
	PhimBam b2, b4;
	CClientDC* pdc;
	CPoint p1, p2;

	int control;
	VeHinh* ph[20];
	int n;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CVeTamGiacView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in VeTamGiacView.cpp
inline CVeTamGiacDoc* CVeTamGiacView::GetDocument() const
   { return reinterpret_cast<CVeTamGiacDoc*>(m_pDocument); }
#endif

