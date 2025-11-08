#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "struct.h"
#include "funcoes.h"
#include "ordena.h"
#include "bst.h"

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

void listag(Node *lista){
    Node *aux = lista;
    while(aux != NULL){
        printf("ID: %i\nNome: %s\nTelefone: %s\nEmail: %s\n",aux->id, aux->nome, aux->telefone, aux->email);
        printf("Cidade: %s\n Estado: %s\n\n", aux->cidade, aux->estado);
        aux = aux->next;
    }
}

void listagem(Node *lista){
    if(!lista){
        printf("Agenda vazia\n");
        return;
    }
    int escolha;
    do{
        printf("Digite\n1 para listagem por ID\n2 para listagem por ordem alfabetica\n3 para listagem por ordem alfabetica decrescente\n4 para listagem por cidade\n5 para listagem por Estado\n0 para ir no menu\n");
        scanf("%i", &escolha);
        switch (escolha){
        case 1://ID = feito
            Node *ordenado = quick_ID(lista);
            listag(ordenado);
            break;
        case 2://alfabetica = feito
            Node *ordenado1 = quick_alfabeto(lista, 1);
            listag(ordenado1);
            break;
        case 3://alfabetica decrescente = feito
            Node *ordenado2 = quick_alfabeto(lista, 0);
            listag(ordenado2);
            break;
        case 4://cidade = feito
            Node *ordenado3 = quick_cidade(lista);
            listag(ordenado3);
            break;
        case 5://estado = feito
            Node *ordenado4 = quick_estado(lista);
            break;
        case 0:
            printf("Retornando ao menu...\n");
            break;
        default:
            printf("Escolha invalida");
            break;
        }
    }while(escolha != 0);
}

BST *inserirBST(BST *raiz, Node *lista){
    if (lista == NULL) 
        return raiz;
    if (raiz == NULL) {
        BST *novo = malloc(sizeof(BST));
        strcpy(novo->nome, lista->nome);
        novo->ref = lista;
        novo->left = novo->right = NULL;
        return novo;
    }
    int cmp = strcmp(lista->nome, raiz->nome);
    if (cmp < 0)
        raiz->left = inserirBST(raiz->left, lista);
    else if (cmp > 0)
        raiz->right = inserirBST(raiz->right, lista);
    return raiz;
}

Node *buscarBST(BST *raiz, char *nome) {
    if (raiz == NULL)
        return NULL;

    int cmp = strcmp(nome, raiz->nome);

    if (cmp == 0)
        return raiz->ref;
    else if (cmp < 0)
        return buscarBST(raiz->left, nome);
    else
        return buscarBST(raiz->right, nome);
}

BST *construirArvore(Node *lista){
    BST *raiz = NULL;
    for (Node *atual = lista; atual != NULL; atual = atual->next) {
        raiz = inserirBST(raiz, atual);
    }
    return raiz;
}

void busca(Node *lista){
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    char nome[41];
    printf("Digite o nome do contato que deseja buscar:\n");
    scanf("%40s", nome);
    BST *raiz = construirArvore(lista);
    Node *resultado = buscarBST(raiz, nome);
    if (resultado != NULL) {
        printf("ID: %d\n", resultado->id);
        printf("Nome: %s\n", resultado->nome);
        printf("Telefone: %s\n", resultado->telefone);
        printf("Email: %s\n", resultado->email);
        printf("Cidade: %s\n", resultado->cidade);
        printf("Estado: %s\n", resultado->estado);
    } else {
        printf("Contato nao encontrado.\n");
    }
}

void excluir(Node **lista){
    if(lista == NULL){
        printf("Lista vazia, cadastre novos contatos\n");
        return;
    }
    char nome[41];
    printf("Digite o nome do contato que deseja excluir:\n");
    scanf("%40s", nome);
    Node *atual = *lista;
    Node *anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Excluindo contato:\n");
            printf("ID: %d\n", atual->id);
            printf("Nome: %s\n", atual->nome);
            printf("Telefone: %s\n", atual->telefone);
            printf("Email: %s\n", atual->email);
            printf("Cidade: %s\n", atual->cidade);
            printf("Estado: %s\n", atual->estado);

            // Se for o primeiro nó
            if (anterior == NULL) {
                *lista = atual->next;
            } else {
                anterior->next = atual->next;
            }

            free(atual);
            printf("\nContato excluido com sucesso!\n");
            return;
        }

        anterior = atual;
        atual = atual->next;
    }
    printf("Contato nao encontrado.\n");
}
