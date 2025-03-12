#include <windows.h>
#include <stdio.h>

int main()
{
        HANDLE handle = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, L"SharedMemory");
    if (handle == NULL) 
    {
        printf("CreateFileMapping failed (%d)\n", GetLastError());
        return 1;
    }

LPVOID address = MapViewOfFile(handle, FILE_MAP_ALL_ACCESS, 0, 0, 4096);
    if (address == NULL) 
    {
        printf("MapViewOfFile failed (%d)\n", GetLastError());
        CloseHandle(handle);
        return 1;
    }
}