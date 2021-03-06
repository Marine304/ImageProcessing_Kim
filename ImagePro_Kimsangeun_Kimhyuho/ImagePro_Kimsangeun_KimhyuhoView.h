
// ImagePro_Kimsangeun_KimhyuhoView.h: CImageProKimsangeunKimhyuhoView 클래스의 인터페이스
//

#pragma once


class CImageProKimsangeunKimhyuhoView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CImageProKimsangeunKimhyuhoView() noexcept;
	DECLARE_DYNCREATE(CImageProKimsangeunKimhyuhoView)

// 특성입니다.

public:
	CImageProKimsangeunKimhyuhoDoc* GetDocument() const;
	int viewMode;
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CImageProKimsangeunKimhyuhoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPixelAdd();
	afx_msg void OnPixelSub();
	afx_msg void OnPixelMul();
	afx_msg void OnPixelDiv();
	afx_msg void OnPixelHistoEq();
	afx_msg void OnPixelTwoImageAdd();
	afx_msg void OnPixelTwoImageSub();
	afx_msg void OnReversimg();
	afx_msg void OnConStr();
	afx_msg void OnOnbinarization();
};

#ifndef _DEBUG  // ImagePro_Kimsangeun_KimhyuhoView.cpp의 디버그 버전
inline CImageProKimsangeunKimhyuhoDoc* CImageProKimsangeunKimhyuhoView::GetDocument() const
   { return reinterpret_cast<CImageProKimsangeunKimhyuhoDoc*>(m_pDocument); }
#endif

