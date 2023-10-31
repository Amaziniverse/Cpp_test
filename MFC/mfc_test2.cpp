// CriticalSection �ϥνd��
// �O�ѤF, �]�w multi-thread ������ C/C++ run-time library
//                                                                       ������

#include <windows.h>
#include <process.h>        // for _beginthreadex(...)

#include <tchar.h>
#include <iostream>
using namespace std;


// ============ �]�w Critical Section �ܼ� =============
const int MAX_TIMES = 100;
CRITICAL_SECTION g_cs; 
// ============ End ===============================

int g_nIndex = 0;
DWORD g_dwTimes[MAX_TIMES];


unsigned int __stdcall FirstThread(void *p);
unsigned int __stdcall SecondThread(void *p);


int _tmain(int argc, _TCHAR* argv[])
{
	// Step 1: �� Critical Section �i���l�ƪ��ʧ@
	InitializeCriticalSection( &g_cs);

	HANDLE hThread[2];

	// Step 2: �إ� FristThread 
	unsigned int thread1_Id;
	hThread[0]=(HANDLE)_beginthreadex(NULL,0,FirstThread,NULL,0,&thread1_Id);

	// Step 3: �إ� SecondThread 
	// hThread[1]=(HANDLE) _beginthread(SecondThread,0,NULL);
	unsigned int thread2_Id;
	hThread[1]=(HANDLE)_beginthreadex(NULL,0,SecondThread,NULL,0,&thread2_Id);
	
	WaitForMultipleObjects(2,hThread,TRUE,INFINITE);

	printf("�Ы����N�����}");
	getchar();
	// Step 4: �R�� CriticalSection
	DeleteCriticalSection (&g_cs); 

	// Step 5: �R�� thread �� Handle
	BOOL bOk=CloseHandle(hThread[0]);
	bOk=CloseHandle(hThread[1]);
	return 0;
}

unsigned int __stdcall FirstThread(void *p){
	bool bQuit=false;
	while (!bQuit) {
		EnterCriticalSection( &g_cs);               // �i�J Critical Section
		if(g_nIndex < MAX_TIMES){	
			g_dwTimes[g_nIndex] = GetTickCount();
			printf("\n=========== FirstThread ===========\n");
			printf("�ثe g_nIndex= %d, �g�J�Ȭ�= %d\n",g_nIndex,g_dwTimes[g_nIndex]);
			g_nIndex++;
		}else{
			bQuit=TRUE;
		}
		LeaveCriticalSection( &g_cs);               // ���} Critical Section	
	}
	return 0;
}

unsigned int __stdcall SecondThread(void *p){
	bool bQuit=false;
	while (!bQuit) {
		EnterCriticalSection( &g_cs);                 // �i�J Critical Section
		if(g_nIndex < MAX_TIMES){
			g_nIndex++;
			g_dwTimes[g_nIndex - 1] = GetTickCount(); 
			printf("\n---- > SecondThread \n");
			printf("�ثe g_nIndex= %d, �g�J�Ȭ�= %d\n",g_nIndex,g_dwTimes[g_nIndex - 1]);
		}else{
			bQuit=TRUE;
		}
		LeaveCriticalSection( &g_cs);                 // ���} Critical Section
	}
	return 0;
}

