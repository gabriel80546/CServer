#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include "lib/objetos.h"



int main()
{
    int i;
    int porta = 5000;

    int socketFileDescriptor;
    int socketAceitoFileDescriptor;

    char buffer[1024] = {'S','o','u',' ','e','u',' ','d','o',' ',' ',' ','S','e','r','v','i',
                         'd','o','r',' ','M','a','i','s',' ','u','m','a',' ','v','e','z','\0'};

    socketFileDescriptor = socket(AF_INET ,SOCK_STREAM , 0);
    struct sockaddr_in enderecoServidor;

    enderecoServidor.sin_family = AF_INET;
    enderecoServidor.sin_addr.s_addr = htonl(INADDR_ANY);
    enderecoServidor.sin_port = htons((uint16_t)porta);

    bind(socketFileDescriptor, (struct sockaddr*)&enderecoServidor , sizeof(enderecoServidor));

    listen(socketFileDescriptor, 10) == -1;

    char oi = 0;
    while(1)
    {
        oi = oi + 1;
        socketAceitoFileDescriptor = accept(socketFileDescriptor, (struct sockaddr*)NULL ,NULL);
        buffer[10] = oi;
        write(socketAceitoFileDescriptor,buffer,strlen(buffer));
        close(socketAceitoFileDescriptor);
    }


    return 0;
}