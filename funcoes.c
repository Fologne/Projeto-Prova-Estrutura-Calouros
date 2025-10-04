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
    printf("Digite o nome do contato que deseja cadastrar\n");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';
    printf("Digite o telefone do contato ddd, sem espacos ou simbolos\n");
    fgets(novo->telefone, sizeof(novo->telefone), stdin);
    novo->telefone[strcspn(novo->telefone, "\n")] = '\0';
    printf("Digite o email do contato\n");
    fgets(novo->email, sizeof(novo->email), stdin);
    novo->email[strcspn(novo->email, "\n")] = '\0';
    printf("Digite a cidade do contato\n");
    fgets(novo->cidade, sizeof(novo->cidade), stdin);
    novo->cidade[strcspn(novo->cidade, "\n")] = '\0';
    printf("Digite o estado da cidade, formato MT, SP e etc.\n");
    fgets(novo->estado, sizeof(novo->estado), stdin);
    novo->estado[strcspn(novo->estado, "\n")] = '\0';
    (*quant)++;
    novo->id = *quant;
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

void listaID(Node *lista){
    Node *aux = lista;
    while(aux != NULL){
        printf("ID: %i\nNome: %s\nTelefone: %s\nEmail: %s\n",aux->id, aux->nome, aux->telefone, aux->email);
        printf("Cidade: %s\n Estado: %s\n\n", aux->cidade, aux->estado);
        aux = aux->next;
    }
}

void listagem(Node *lista){
    printf("%i", *quant);
    if(!lista){
        printf("Agenda vazia\n");
        return;
    }
    int escolha;
    do{
        printf("Digite\n1 para listagem por ID\n2 para listagem por ordem alfabetica\n3 para listagem por ordem alfabetica decrescente\n4 para listagem por cidade\n5 para listagem por Estado");
        switch (escolha){
        case 1://ID = feito
            listaID(lista);
            break;
        case 2://alfabetica = não feito
            break;
        case 3://alfabetica decrescente = não feito
            break;
        case 4://cidade = não feito
            break;
        case 5://estado = não feito
            break;
        default:
            break;
        }
    }
    
}