#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string.h>
#include <comdef.h>

int killProcessByName(const char *filename)
{
	int retValue = 0;
	/*snapshot for all running processes*/
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 pEntry;
	/*initializing size - needed for using Process32First*/
	pEntry.dwSize = sizeof(pEntry);
	BOOL hRes = Process32First(hSnapShot, &pEntry);
	/*while first process in pEntry exists*/
	while (hRes)
	{
		/*create const char for string comparison*/
		_bstr_t b(pEntry.szExeFile);
		if (strcmp(b, filename) == 0)
		{
			/*get terminate handle for process, by ID*/
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
				(DWORD)pEntry.th32ProcessID);
			if (hProcess != NULL)
			{
				/*terminate process*/
				retValue = TerminateProcess(hProcess, 9);
				CloseHandle(hProcess);
			}
		}
		/*next process*/
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	CloseHandle(hSnapShot);
	return retValue;
}
int main()
{
	printf("%d\n", killProcessByName("notepad.exe"));
	system("pause");
	return 0;
}
