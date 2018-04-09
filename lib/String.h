typedef struct String
{
    char* array;
    int size;
    int(*length)(char*);
    char*(*copy)(char*,struct String);
    int(*equals)(struct String,char*);
}String;

int String_tamanho(char* string)
{
    int i=0;
    while (*(string + i) != '\0')
    {
        i++;
    }
    return i;
}
char* String_copy(char* msg, String string)
{
    int i;
    for(i=0;i<string.size;i++)
    {
        *(msg + i) = *(string.array + i);
    }
    *(msg + i) = '\0';
    return msg;
}

String newString(char* inicializador)
{
    String novaString;

    novaString.array = inicializador;
    novaString.length = &String_tamanho;
    novaString.copy = &String_copy;
    novaString.size = novaString.length(novaString.array);

    return novaString;
}