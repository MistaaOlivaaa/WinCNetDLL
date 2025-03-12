#include <windows.h>
#include <stdio.h>


BOOL WINAPI DllMain(HINSTANCE hinstDLL, WORD reason,LPVOID lpvreserved)
{
        if(reason ==  DLL_PROCESS_ATTACH)
        {
                printf("Hello from Oliver DLL");
        }

        return TRUE;
}

