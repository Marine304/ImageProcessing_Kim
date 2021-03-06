
// ImagePro_Kimsangeun_KimhyuhoView.cpp: CImageProKimsangeunKimhyuhoView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImagePro_Kimsangeun_Kimhyuho.h"
#endif

#include "ImagePro_Kimsangeun_KimhyuhoDoc.h"
#include "ImagePro_Kimsangeun_KimhyuhoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define TWO_IMAGES      1 
#define THREE_IMAGES    2 



// CImageProKimsangeunKimhyuhoView

IMPLEMENT_DYNCREATE(CImageProKimsangeunKimhyuhoView, CScrollView)

BEGIN_MESSAGE_MAP(CImageProKimsangeunKimhyuhoView, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProKimsangeunKimhyuhoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_PIXEL_ADD, &CImageProKimsangeunKimhyuhoView::OnPixelAdd)
	ON_COMMAND(ID_PIXEL_SUB, &CImageProKimsangeunKimhyuhoView::OnPixelSub)
	ON_COMMAND(ID_PIXEL_MUL, &CImageProKimsangeunKimhyuhoView::OnPixelMul)
	ON_COMMAND(ID_PIXEL_DIV, &CImageProKimsangeunKimhyuhoView::OnPixelDiv)
	ON_COMMAND(ID_PIXEL_HISTO_EQ, &CImageProKimsangeunKimhyuhoView::OnPixelHistoEq)
	ON_COMMAND(ID_PIXEL_TWO_IMAGE_ADD, &CImageProKimsangeunKimhyuhoView::OnPixelTwoImageAdd)
	ON_COMMAND(ID_PIXEL_TWO_IMAGE_SUB, &CImageProKimsangeunKimhyuhoView::OnPixelTwoImageSub)
	ON_COMMAND(ReversImg, &CImageProKimsangeunKimhyuhoView::OnReversimg)
	ON_COMMAND(ID_CON_STR, &CImageProKimsangeunKimhyuhoView::OnConStr)
	ON_COMMAND(ID_OnBinarization, &CImageProKimsangeunKimhyuhoView::OnOnbinarization)
END_MESSAGE_MAP()

// CImageProKimsangeunKimhyuhoView 생성/소멸

CImageProKimsangeunKimhyuhoView::CImageProKimsangeunKimhyuhoView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProKimsangeunKimhyuhoView::~CImageProKimsangeunKimhyuhoView()
{
}

BOOL CImageProKimsangeunKimhyuhoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CImageProKimsangeunKimhyuhoView 그리기

void CImageProKimsangeunKimhyuhoView::OnDraw(CDC* pDC)
{
	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int y = 0; y<256; y++)    	//Original Image 출력
		for (int x = 0; x<256; x++) {
			pDC->SetPixel(x, y, RGB(pDoc->inputImg[y][x],
				pDoc->inputImg[y][x], pDoc->inputImg[y][x]));
		}
	for (int y = 0; y<256; y++) 		//Result Image 출력
		for (int x = 0; x<256; x++) {
			pDC->SetPixel(x + 300, y, RGB(pDoc->resultImg[y][x],
				pDoc->resultImg[y][x], pDoc->resultImg[y][x]));
		}
	for (int y = 0; y<256; y++)       // 입력 영상 출력 
		for (int x = 0; x<256; x++)
			pDC->SetPixel(x, y, RGB(pDoc->inputImg[y][x],
				pDoc->inputImg[y][x],
				pDoc->inputImg[y][x]));
	if (viewMode == THREE_IMAGES) {
		for (int y = 0; y<256; y++)       // 두번째 입력 영상 출력 
			for (int x = 0; x<256; x++)
				pDC->SetPixel(x + 300, y, RGB(pDoc->inputImg2[y][x],
					pDoc->inputImg2[y][x],
					pDoc->inputImg2[y][x]));

		for (int y = 0; y<256; y++)       // 결과 영상 출력 
			for (int x = 0; x<256; x++)
				pDC->SetPixel(x + 600, y, RGB(pDoc->resultImg[y][x],
					pDoc->resultImg[y][x],
					pDoc->resultImg[y][x]));

	}
	else {
		for (int y = 0; y<256; y++)       // 결과 영상 출력 
			for (int x = 0; x<256; x++)
				pDC->SetPixel(x + 300, y, RGB(pDoc->resultImg[y][x],
					pDoc->resultImg[y][x],
					pDoc->resultImg[y][x]));
	}


}




void CImageProKimsangeunKimhyuhoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = 2048;     // 수정된 코드 
	sizeTotal.cy = 1024;     // 수정된 코드 
	SetScrollSizes(MM_TEXT, sizeTotal);

}


// CImageProKimsangeunKimhyuhoView 인쇄


void CImageProKimsangeunKimhyuhoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProKimsangeunKimhyuhoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProKimsangeunKimhyuhoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProKimsangeunKimhyuhoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CImageProKimsangeunKimhyuhoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProKimsangeunKimhyuhoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProKimsangeunKimhyuhoView 진단

#ifdef _DEBUG
void CImageProKimsangeunKimhyuhoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImageProKimsangeunKimhyuhoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImageProKimsangeunKimhyuhoDoc* CImageProKimsangeunKimhyuhoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProKimsangeunKimhyuhoDoc)));
	return (CImageProKimsangeunKimhyuhoDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageProKimsangeunKimhyuhoView 메시지 처리기


void CImageProKimsangeunKimhyuhoView::OnPixelAdd()
{
	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->PixelAdd();

	Invalidate(FALSE);
	viewMode = TWO_IMAGES;

}


void CImageProKimsangeunKimhyuhoView::OnPixelSub()
{
	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->PixelSub();

	Invalidate(FALSE);
	viewMode = TWO_IMAGES;
}


void CImageProKimsangeunKimhyuhoView::OnPixelMul()
{
	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->PixelMUL();

	Invalidate(FALSE);
	viewMode = TWO_IMAGES;
}


void CImageProKimsangeunKimhyuhoView::OnPixelDiv()
{
	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->PixelDIV();

	Invalidate(FALSE);
	viewMode = TWO_IMAGES;
}


void CImageProKimsangeunKimhyuhoView::OnPixelHistoEq()
{
	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->PixelHistoEq();  // CImageProDoc 클래스의 PixelHistoEq() 호출 
	Invalidate(FALSE);      //화면 갱신.   
	viewMode = TWO_IMAGES;
}


void CImageProKimsangeunKimhyuhoView::OnPixelTwoImageAdd()
{
	
	
	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->PixelTwoImageAdd();
		Invalidate(FALSE);
		viewMode = THREE_IMAGES;
	

}


void CImageProKimsangeunKimhyuhoView::OnPixelTwoImageSub()
{

	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->PixelTwoImageSUB();
	Invalidate(FALSE);
	viewMode = THREE_IMAGES;

}


void CImageProKimsangeunKimhyuhoView::OnReversimg()
{
	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->Reversimg();  // CImageProDoc 클래스의 PixelHistoEq() 호출 
	Invalidate(FALSE);      //화면 갱신.   
	viewMode = TWO_IMAGES;
}


void CImageProKimsangeunKimhyuhoView::OnConStr()
{
	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->ConStr();  // CImageProDoc 클래스의 PixelHistoEq() 호출 
	Invalidate(FALSE);      //화면 갱신.   
	viewMode = TWO_IMAGES;
}


void CImageProKimsangeunKimhyuhoView::OnOnbinarization()
{
	CImageProKimsangeunKimhyuhoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnOnbinarization();  // CImageProDoc 클래스의 PixelHistoEq() 호출 
	Invalidate(FALSE);      //화면 갱신.   
	viewMode = TWO_IMAGES;
}
