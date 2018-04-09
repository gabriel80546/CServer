#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

int main()
{
    int socketFileDescriptor;
    int i;
    for(i=0;i<20;i++)
    {
        printf("Vai A merda %i\n",i);
    }

    socketFileDescriptor = socket(AF_INET ,SOCK_STREAM , 0);

    if(socketFileDescriptor < 0)
    {
        fprintf(stderr,"Erro Ao iniciar Socket");
        exit(0);
    }


    return 0;
}