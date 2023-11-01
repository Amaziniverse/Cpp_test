// DlgTest.cpp: 구현 파일
//

#include "pch.h"
#include "MExDlg.h"
#include "afxdialogex.h"
#include "DlgTest.h"


// CDlgTest 대화 상자

IMPLEMENT_DYNAMIC(CDlgTest, CDialog)

CDlgTest::CDlgTest(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIGTEST, pParent)
	, m_bCheckButton(FALSE)
	, m_strEdit(_T(""))
{
}

CDlgTest::~CDlgTest()
{
}

void CDlgTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_bCheckButton);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);  //DDX_Text connect
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	DDX_Control(pDX, IDC_SLIDER1, m_Slidectrl1);
	DDX_Control(pDX, IDC_SLIDER2, m_Slidectrl2);
	//  DDX_Control(pDX, IDC_SLIDER3, m_Slidectrl);
	DDX_Control(pDX, IDC_SLIDER3, m_Slidectrl3);
	DDX_Control(pDX, IDC_PIC, m_stcPicControl);
}


BEGIN_MESSAGE_MAP(CDlgTest, CDialog)
	ON_BN_CLICKED(IDC_CHECK1, &CDlgTest::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgTest::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgTest::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTest::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgTest::OnEnChangeEdit1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CDlgTest::OnSelchangeList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlgTest::OnSelchangeCombo1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CDlgTest::OnCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CDlgTest::OnCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CDlgTest::OnCustomdrawSlider3)
//	ON_EN_CHANGE(IDC_EDIT2, &CDlgTest::OnChangeEdit2)
//	ON_EN_CHANGE(IDC_EDIT3, &CDlgTest::OnChangeEdit3)
//	ON_EN_CHANGE(IDC_EDIT4, &CDlgTest::OnChangeEdit4)
//ON_EN_CHANGE(IDC_EDIT4, &CDlgTest::OnEnChangeEdit4)
ON_BN_CLICKED(IDC_BUTTON2, &CDlgTest::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgTest 메시지 처리기


void CDlgTest::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);			// 현재 키값을 바뀔 때마다 가져오다 
	// UpdateData(False)인 경우 맨 아래로 와야 한다. 
	CString message;
	message.Format(_T("Check button press value:%d"),m_bCheckButton);
		AfxMessageBox(message);

}


void CDlgTest::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("Radio Button 1 Press"));	
}


void CDlgTest::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("Radio Button 2 Press"));
}


void CDlgTest::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("Button 1 Press"));
}


void CDlgTest::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL CDlgTest::OnInitDialog()
{
	// TODO: 여기에 구현 코드 추가.
	CDialog::OnInitDialog();		// 함수명은 동일하지만 상속받은 함수라
								// 부모를 명확히 구분하기 위해 명시해두었다. 
	m_strEdit = _T("Hello World");
	UpdateData(FALSE);

	CString data;
	for (int i = 1; i < 11; i++)		// 등록만 하고 출력하라는 내용은 없는 상태
									// 그럼 출력이 안 될까요? 됩니다.
	{
		data.Format(_T("List data%d"), i);
		m_ListBox.AddString(data);
		data.Format(_T("Combo data%d"), i);
		m_ComboBox.AddString(data);
	}
	m_Slidectrl1.SetRange(1899, 2023, TRUE);
	m_Slidectrl1.SetPos(1899);			// 시작 지점 ! 

	m_Slidectrl2.SetRange(1, 12, TRUE);
	m_Slidectrl2.SetPos(1);

	m_Slidectrl3.SetRange(1, 31, TRUE);
	m_Slidectrl3.SetPos(1);

	return TRUE;
}


void CDlgTest::OnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = m_ListBox.GetCurSel();	//Search the current position
	CString data;
	m_ListBox.GetText(num, data);	//get character at select position
	AfxMessageBox(data);	//output message box 
}


void CDlgTest::OnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = m_ComboBox.GetCurSel();
	CString data;
	m_ComboBox.GetLBText(num, data);
	AfxMessageBox(data);
}


void CDlgTest::OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int position;
	position = m_Slidectrl1.GetPos();
	SetDlgItemInt(IDC_EDIT2, position);

	*pResult = 0;
} // 현재 설정한 값을 보여주기 위해 TRUE를 써야 하는데 여기서는 쓰지 않았다. 
	// ctrl로 받는 것은 Update Data를 안 해도 된다. 자동으로 연결되니까.



void CDlgTest::OnCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int position;
	position = m_Slidectrl2.GetPos();
	SetDlgItemInt(IDC_EDIT3, position);

	*pResult = 0;
}


void CDlgTest::OnCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int position;
	position = m_Slidectrl3.GetPos();
	SetDlgItemInt(IDC_EDIT4, position);

	*pResult = 0;
}


void CDlgTest::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRect rect;//픽쳐 컨트롤의 크기를 저장할 CRect 객체
	m_stcPicControl.GetWindowRect(rect);//GetWindowRect를 사용해서 픽쳐 컨트롤의 크기를 받는다.
	CDC* dc; //픽쳐 컨트롤의 DC를 가져올  CDC 포인터
	dc = m_stcPicControl.GetDC(); //픽쳐 컨트롤의 DC를 얻는다.
	CImage image;//불러오고 싶은 이미지를 로드할 CImage 
	image.Load(_T("5.bmp"));//이미지 로드

	image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);//이미지를 픽쳐 컨트롤 크기로 조정
	ReleaseDC(dc);//DC 해제
}
