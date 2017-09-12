// ShellWindows.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <Windows.h>
#include <WinBase.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <atlbase.h>


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int N = 64;
	char comando[N];
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	for (;;) {
		cout << "sh:> ";
		cin.getline(comando, N);
		if (strcmp(comando, "exit") == 0) break;

		// Conversion de char[] a TCHAR*
		USES_CONVERSION;
		TCHAR* comandoT = A2T(comando);

		// Inicia el proceso hijo. 
		if (!CreateProcess(NULL,   // No module name (use command line)
			comandoT,        // Command line
			NULL,           // Process handle not inheritable
			NULL,           // Thread handle not inheritable
			FALSE,          // Set handle inheritance to FALSE
			0,              // No creation flags
			NULL,           // Use parent's environment block
			NULL,           // Use parent's starting directory 
			&si,            // Pointer to STARTUPINFO structure
			&pi)           // Pointer to PROCESS_INFORMATION structure
			)
		{
			printf("Fallo de CreateProcess  (%d).\n", GetLastError());
			return 0;
		}

		// Espera hasta que el proceso hijo finalize
		WaitForSingleObject(pi.hProcess, INFINITE);

		// Cierra los handles de process y thread. 
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	return 0;
}
