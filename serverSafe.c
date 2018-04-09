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

    if(socketFileDescriptor < 0)
    {
        fprintf(stderr,"Erro Ao iniciar Socket");
        exit(1);
    }


    enderecoServidor.sin_family = AF_INET;
    enderecoServidor.sin_addr.s_addr = htonl(INADDR_ANY);
    enderecoServidor.sin_port = htons(porta);
    printf("porta = %i\n",enderecoServidor.sin_port);
    printf("addr = %i\n",enderecoServidor.sin_addr.s_addr);


    bind(socketFileDescriptor, (struct sockaddr*)&enderecoServidor , sizeof(enderecoServidor));

    if(listen(socketFileDescriptor, 10) == -1)
    {
        printf("Failed to listen\n");
        exit(-1);
    }
    String msg = newString("Fala Fiote");

    printf("msg = %s\n",msg.array);
    printf("tamanho = %i\n",msg.size);

    char oi = 64;
    while(1)
    {
        oi = oi + 1;
        socketAceitoFileDescriptor = accept(socketFileDescriptor, (struct sockaddr*)NULL ,NULL);
        buffer[10] = oi;
        write(socketAceitoFileDescriptor,buffer,strlen(buffer));


        close(socketAceitoFileDescriptor);
        //sleep(1);
    }


    return 0;
}