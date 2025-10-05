#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "struct.h"
#include "funcoes.h"

void menu(int *quant){
    Node *lista = NULL;
    int escolha;
    do{
        printf("Digite\n1 para cadastrar um novo contato\n2 para listar contatos\n3 para buscar contatos\n4 para excluir contatos\n0 para sair\n");
        scanf("%i", &escolha);
        switch (escolha){
        case 1://cadastro = feito
            int c;//variavel para limpar o buffer
            while ((c = getchar()) != '\n' && c != EOF); 
            lista = cadastro(lista, quant);
            break;
        case 2://listagem = não feito
            listagem(lista);
            break;
        case 3://busca = não feito
            //busca(lista);
            break;
        case 4://excluir = não feito
            //excluir(lista);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Escolha invalida\n");
            break;
        }
    }while(escolha != 0);
}