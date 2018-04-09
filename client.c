#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "lib/objetos.h"

int main()
{
    String msg = newString("fala");

    printf("msg = %s\n",msg.array);
    printf("saze = %i\n",msg.size);

    return 0;
}