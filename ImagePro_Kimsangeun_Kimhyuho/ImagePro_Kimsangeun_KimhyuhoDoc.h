
// ImagePro_Kimsangeun_KimhyuhoDoc.h: CImageProKimsangeunKimhyuhoDoc 클래스의 인터페이스
//


#pragma once


class CImageProKimsangeunKimhyuhoDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImageProKimsangeunKimhyuhoDoc() noexcept;
	DECLARE_DYNCREATE(CImageProKimsangeunKimhyuhoDoc)

// 특성입니다.
public:
	unsigned char  inputImg[256][256];
	unsigned char inputImg2[256][256];
	unsigned char  resultImg[256][256];

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CImageProKimsangeunKimhyuhoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	void PixelAdd();
	
	void PixelSub();
	void PixelMUL();
	void PixelDIV();
	void PixelHistoEq();
	void PixelTwoImageAdd();
	void LoadTwoImages();
	void PixelTwoImageSUB();
	void Reversimg();
	void ConStr();
	void OnOnbinarization();
};

