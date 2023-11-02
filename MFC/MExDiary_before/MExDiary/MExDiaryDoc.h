
// MExDiaryDoc.h: CMExDiaryDoc 클래스의 인터페이스
//


#pragma once

#define MAXDATESIZE 80
#define MAXSUBJECTSIZE 256
#define MAXCONTENTSIZE 1024

class CMExDiaryDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CMExDiaryDoc() noexcept;
	DECLARE_DYNCREATE(CMExDiaryDoc)

// 특성입니다.
public:
	char m_strDate[MAXDATESIZE + 1];		//for date saving
	char m_strSubject[MAXSUBJECTSIZE + 1];	//for subject saving
	char m_strContent[MAXCONTENTSIZE + 1];	// for contents saving

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
	virtual ~CMExDiaryDoc();
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
	void CMExDiaryDoc::SetSubject(char* subject);
	void CMExDiaryDoc::SetContent(char* content);
	void CMExDiaryDoc::SetDate(char* date);
	char* CMExDiaryDoc::GetDate();
	char* CMExDiaryDoc::GetSubject();
	char* CMExDiaryDoc::GetContent();

	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
};
