
// RFIDDlg.cpp: 
//
#include "is_d2xx.h"
#include "pch.h"
#include "framework.h"
#include "RFID.h"
#include "RFIDDlg.h"
#include "afxdialogex.h"

// sound 
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "mmsystem.h"
#pragma comment(lib,"winmm.lib") 

// for image load 
#include "atlimage.h"

// for use DB
#include "mysql/mysql.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CRFIDDlg 대화 상자 


CRFIDDlg::CRFIDDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RFID_DIALOG, pParent)
	, m_strRfid(_T(""))
	, m_strName(_T(""))
	, m_strAuthor(_T(""))
	, m_strDes(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
CRFIDDlg::~CRFIDDlg()
{
	OnDisconnect();
//	mysql_close(conn);
}

void CRFIDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strRfid);
	DDX_Text(pDX, IDC_EDIT2, m_strName);
	DDX_Text(pDX, IDC_EDIT3, m_strAuthor);
	DDX_Text(pDX, IDC_EDIT4, m_strDes);
	DDX_Control(pDX, IDC_testpic, m_pictest);
}

BEGIN_MESSAGE_MAP(CRFIDDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRFIDDlg::OnConnect)
	ON_BN_CLICKED(IDC_BUTTON3, &CRFIDDlg::OnReadOnce)
	ON_BN_CLICKED(IDC_BUTTON2, &CRFIDDlg::OnDisconnect)
	ON_EN_CHANGE(IDC_EDIT2, &CRFIDDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CRFIDDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CRFIDDlg::OnEnChangeEdit4)
	ON_STN_CLICKED(IDC_testpic, &CRFIDDlg::OnStnClickedtestpic)
END_MESSAGE_MAP()


// CRFIDDlg 메시지 처리기

BOOL CRFIDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CRFIDDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CRFIDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CRFIDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRFIDDlg::OnConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		//열린 포트번호 찾기
	if (is_GetDeviceNumber(&usbnumber) == IS_OK)
	{
		printf("FTDI USB To Serial 연결된 개수 : %d\n", usbnumber);
		if (is_GetSerialNumber(0, readSerialNumber) == IS_OK)
		{
			if (memcmp(changeSerialNumber, readSerialNumber, sizeof(changeSerialNumber) != 0))
			{
				if (is_SetSerialNumber(0, changeSerialNumber) == IS_OK)
				{
					printf(" USB To Serial Number 를 변경 하였습니다.\n");
					printf(" FTDI SerialNumber :  %s \n", changeSerialNumber);
				}
			}
			else
				printf(" FTDI SerialNumber :  %s \n", changeSerialNumber);
		}
	}

	//열린 포트번호로 연결
	unsigned long portNumber;                                      //기기 연결
	if (is_GetCOMPort_NoConnect(0, &portNumber) == IS_OK)
	{
		printf("COM Port : %d\n", portNumber);
	}
	if (is_OpenSerialNumber(&ftHandle, readSerialNumber, 115200) != IS_OK)
	{
		printf("USB To Serial과 통신 연결 실패했습니다.\n");
		//return -1;
	}
	else 
	{
		printf("Serial포트 %d와 통신 연결 성공했습니다.\n", portNumber);
		printf("RFID 카드를 통해 책 정보를 읽어들이세요.\n");
		CRect rect;
		m_pictest.GetWindowRect(rect);
		CDC* dc;
		dc = m_pictest.GetDC();
		CImage Image;
		Image.Load(_T("img\\start.bmp"));
		Image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);
		ReleaseDC(dc);
	}

	Sleep(100);
	flag_r = 0;
}


void CRFIDDlg::OnReadOnce()		// 1번 읽기 
{
	CString temp, temp1 = _T("");

	CString ID5c = _T("c1 5a 69 cb 50 01 04 e0 ");		// linux
	CString ID5e = _T("e8 fa 68 cb 50 01 04 e0 ");		// c++
	CString ID45 = _T("53 cc b9 15 ");		// openCV
	CString ID4c = _T("c3 5a a1 15 ");		// do it android 

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//ISO15693 read once
	if (flag_r == 0)
	{
		if (is_WriteReadCommand(ftHandle, CM1_ISO15693, CM2_ISO15693_ACTIVE + BUZZER_OFF,
			writeLength, wirteData, &readLength, readData) == IS_OK)
		{
			int i;
			printf("ISO 15693 UID : ");
			for (i = 0; i < readLength; i++)
			{
				printf("%02x ", readData[i]);
				temp.Format(_T("%02x "), readData[i]);
				temp1 += temp;
			}

			m_strRfid = temp1;
			UpdateData(FALSE);		

			printf("\nprint book information\n\n");

			// Connect mysql
			MYSQL* conn;
			MYSQL* conn_result;
			unsigned int timeout_sec = 1;

			conn = mysql_init(NULL);
			mysql_options(conn, MYSQL_OPT_CONNECT_TIMEOUT, &timeout_sec);
			conn_result = mysql_real_connect(conn, "127.0.0.1", "root", "1234", "mysql", 3306, NULL, 0);

			if (NULL == conn_result)
			{
				printf("DB 연결 실패.\n");
			}

			else
			{
				printf("DB 연결 성공.\n");

				char query[1024];
				MYSQL_RES* result;
				MYSQL_ROW row;
				CString name = _T("");
				CString author = _T("");
				CString des = _T("");
				CString cover = _T("");
				
				if (m_strRfid == ID5c)		// Linux
				{
					sprintf_s(query, 1024, "SELECT * FROM rfid WHERE Num = 1");

					if (mysql_query(conn, query))
					{
						printf("읽어들이지 못했습니다.\n");
					}

					result = mysql_store_result(conn);

					// unsigned int fields = mysql_num_fields(result);    
					// DB에서 읽어오는 정보가 많을 경우 쓴다. 

					row = mysql_fetch_row(result);

					if (row != nullptr)
					{
						name = row[1];
						author = row[2];
						des = row[3];
						cover = row[4];

						CRect rect;
						m_pictest.GetWindowRect(rect);
						CDC* dc;
						dc = m_pictest.GetDC();
						CImage Image;
						Image.Load(cover);
						Image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);
						ReleaseDC(dc);

						m_strName = name;
						m_strAuthor = author;
						m_strDes = des;

						UpdateData(FALSE);

						mysql_free_result(result);
						mysql_close(conn);
					}
				}

				if (m_strRfid == ID5e)		// C++
				{
					sprintf_s(query, 1024, "SELECT * FROM rfid WHERE Num = 2");

					if (mysql_query(conn, query))
					{
						printf("읽어들이지 못했습니다.\n");
					}

					result = mysql_store_result(conn);  

					row = mysql_fetch_row(result);

					if (row != nullptr)
					{
						name = row[1];
						author = row[2];
						des = row[3];
						cover = row[4];

						CRect rect;
						m_pictest.GetWindowRect(rect);
						CDC* dc;
						dc = m_pictest.GetDC();
						CImage Image;
						Image.Load(cover);
						Image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);
						ReleaseDC(dc); 

						m_strName = name;
						m_strAuthor = author;
						m_strDes = des;

						UpdateData(FALSE);

						mysql_free_result(result);
						mysql_close(conn);
					}
				}
			}
		}


		//ISO14443A read once
		if (is_WriteReadCommand(ftHandle, CM1_ISO14443AB, CM2_ISO14443A_ACTIVE + BUZZER_OFF,
			writeLength, wirteData, &readLength, readData) == IS_OK)
		{
			int i;
			printf("ISO 14443AB UID : ");
			for (i = 0; i < readLength; i++)
			{
				printf("%02x ", readData[i]);
				temp.Format(_T("%02x "), readData[i]);
				temp1 += temp;
			}
			m_strRfid = temp1;
			UpdateData(FALSE);

			printf("\nprint book information\n\n");

			// Connect mysql
			MYSQL* conn;
			MYSQL* conn_result;
			unsigned int timeout_sec = 1;

			conn = mysql_init(NULL);
			mysql_options(conn, MYSQL_OPT_CONNECT_TIMEOUT, &timeout_sec);
			conn_result = mysql_real_connect(conn, "127.0.0.1", "root", "1234", "mysql", 3306, NULL, 0);

			if (NULL == conn_result)
			{
				printf("DB 연결 실패.\n");
			}

			else
			{
				printf("DB 연결 성공.\n");

				char query[1024];
				MYSQL_RES* result;
				MYSQL_ROW row;
				CString name = _T("");
				CString author = _T("");
				CString des = _T("");
				CString cover = _T("");

				if (m_strRfid == ID45)		// OpenCV
				{
					sprintf_s(query, 1024, "SELECT * FROM rfid WHERE Num = 3");

					if (mysql_query(conn, query))
					{
						printf("읽어들이지 못했습니다.\n");
					}

					result = mysql_store_result(conn);

					// unsigned int fields = mysql_num_fields(result);    
					// DB에서 읽어오는 정보가 많을 경우 쓴다. 

					row = mysql_fetch_row(result);

					if (row != nullptr)
					{
						name = row[1];
						author = row[2];
						des = row[3];
						cover = row[4];

						CRect rect;
						m_pictest.GetWindowRect(rect);
						CDC* dc;
						dc = m_pictest.GetDC();
						CImage Image;
						Image.Load(cover);
						Image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);
						ReleaseDC(dc);

						m_strName = name;
						m_strAuthor = author;
						m_strDes = des;

						UpdateData(FALSE);

						mysql_free_result(result);
						mysql_close(conn);
					}
				}

				if (m_strRfid == ID4c)		// Android
				{
					sprintf_s(query, 1024, "SELECT * FROM rfid WHERE Num = 4");

					if (mysql_query(conn, query))
					{
						printf("읽어들이지 못했습니다.\n");
					}

					result = mysql_store_result(conn);

					row = mysql_fetch_row(result);

					if (row != nullptr)
					{
						name = row[1];
						author = row[2];
						des = row[3];
						cover = row[4];

						CRect rect;
						m_pictest.GetWindowRect(rect);
						CDC* dc;
						dc = m_pictest.GetDC();
						CImage Image;
						Image.Load(cover);
						Image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);
						ReleaseDC(dc);

						m_strName = name;
						m_strAuthor = author;
						m_strDes = des;

						UpdateData(FALSE);

						mysql_free_result(result);
						mysql_close(conn);
					}
				}
			}
		}
	}
} 


void CRFIDDlg::OnDisconnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		// 무선파워를 끊는 함수 
	is_RfOff(ftHandle);

	if (is_Close(ftHandle) == IS_OK)
	{
		printf("연결을 종료합니다. ");
	}
}


void CRFIDDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRFIDDlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRFIDDlg::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRFIDDlg::OnStnClickedtestpic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
