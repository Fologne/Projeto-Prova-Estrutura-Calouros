#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "struct.h"
#include "funcoes.h"

Node *cadastro(Node *lista, int *quant){
    Node *novo = malloc(sizeof(Node));
    if (novo == NULL){//verificar se a alocacao funcionou 
        printf("Erro de alocacao!\n");
        return lista;
    }
    printf("Digite o nome do contato que deseja cadastrar");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';
    printf("Digite o telefone do contato ddd, sem espaços ou simbolos");
    fgets(novo->telefone, sizeof(novo->telefone), stdin);
    novo->telefone[strcspn(novo->telefone, "\n")] = '\0';
    printf("Digite o email do contato");
    fgets(novo->email, sizeof(novo->email), stdin);
    novo->email[strcspn(novo->email, "\n")] = '\0';
    printf("Digite a cidade do contato");
    fgets(novo->cidade, sizeof(novo->cidade), stdin);
    novo->cidade[strcspn(novo->cidade, "\n")] = '\0';
    printf("Digite o estado da cidade, formato MT, SP e etc.");
    fgets(novo->estado, sizeof(novo->estado), stdin);
    novo->estado[strcspn(novo->estado, "\n")] = '\0';
    novo->id = *quant;
    (*quant)++;
    novo->next = NULL;
    if (lista == NULL) {
        return novo;
    } else {
        Node *aux = lista;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = novo;
        return lista;
    }
}