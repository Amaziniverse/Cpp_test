// MutexDemo1.cpp : Defines the entry point for the console application.
//
// �P Event ������: ���� Mutex �O�_�i�H���s�i�J

#include "stdafx.h"
#include "MutexDemo1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

#include <iostream>
using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{

		HANDLE hMutex=CreateMutex(NULL,FALSE,NULL);
	    WaitForSingleObject(hMutex,INFINITE);

	    // �A���i�J
	    WaitForSingleObject(hMutex,INFINITE);
	    cout << "Mutex �ϥΦ��ƻ��W" << endl;
     
		ReleaseMutex(hMutex);
		ReleaseMutex(hMutex);
/*
	// =========================  ����@�U Event =========================
	    HANDLE hEvent=CreateEvent(NULL,FALSE,TRUE,NULL);
	    WaitForSingleObject(hMutex,INFINITE);

	    // �L�k�i�J
	    WaitForSingleObject(hEvent,INFINITE);
	    cout << "�L�k�i�J" << endl;
	// =========================  End =========================
*/
	return 0;
}
