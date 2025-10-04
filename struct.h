typedef struct no{
    int id;
    char nome[41];
    char telefone[13];
    char email[41];
    char cidade[41];
    char estado[3];
    struct no *next;
}Node;