


/*#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
int main()
{
            WSADATA wsadata;
            WSAStartup(MAKEWORD(2, 2) , &wsadata);
            SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
            
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = 0;
            addr.sin_port = htons(8080);
            bind(s, &addr, sizeof(addr));

            listen(s, 10);

            char request[256] = {0};
            SOCKET client = accept(s, 0, 0);
            recv(client, request, 256, 0);

            //get / [FIle] ...

            if(memcmp(request, "GET / ", 6) == 0)
            {
                    FILE* f = fopen("index.html", "r");
                    char buffer[256] = {0};
                    fread(buffer, 1, 256, f);
                    send(client, buffer, 256, 0);
                    

            }


}*/

#include <winsock2.h>
#include <stdio.h>

int main()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    // Corrected bind call with proper casting
    if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        printf("Bind failed with error: %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return 1;
    }

    listen(s, 10);

    printf("Server is running on port 8080...\n");

    while (1) {
        char request[256] = {0};
        SOCKET client = accept(s, 0, 0);
        recv(client, request, 256, 0);

        if (memcmp(request, "GET / ", 6) == 0)
        {
            FILE* f = fopen("index.html", "r");
            if (f == NULL) {
                printf("Failed to open file\n");
                return 1;
            }

            char buffer[256] = {0};
            fread(buffer, 1, 256, f);
            send(client, buffer, 256, 0);

            fclose(f);
        }

        closesocket(client);
    }

    closesocket(s);
    WSACleanup();
    return 0;
}

