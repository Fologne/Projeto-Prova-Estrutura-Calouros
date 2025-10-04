#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "struct.h"
#include "funcoes.h"

void cadastro(Node *lista, int quant){
    printf("Digite o nome do contato que deseja cadastrar");
    char nome[41];
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("Digite o telefone do contato ddd, sem espaços ou simbolos");
    char telefone[12];
    scanf("%s", telefone);
    printf("Digite o email do contato");
    char email[41];
    scanf("%s", email);
    printf("Digite a cidade do contato");
    char cidade[41];
    fgets(cidade, sizeof(cidade), stdin);
    cidade[strcspn(cidade, "\n")] = '\0';
    printf("Digite o estado da cidade, formato MT, SP e etc.");
    char estado[3];
    scanf("%s", estado);
}