#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "struct.h"
#include "funcoes.h"
#include "ordena.h"

void swap(Node *a, Node *b) {
    int tempId = a->id;
    a->id = b->id;
    b->id = tempId;
    char temp[41];
    strcpy(temp, a->nome);
    strcpy(a->nome, b->nome);
    strcpy(b->nome, temp);
    strcpy(temp, a->telefone);
    strcpy(a->telefone, b->telefone);
    strcpy(b->telefone, temp);
    strcpy(temp, a->email);
    strcpy(a->email, b->email);
    strcpy(b->email, temp);
    strcpy(temp, a->cidade);
    strcpy(a->cidade, b->cidade);
    strcpy(b->cidade, temp);
    strcpy(temp, a->estado);
    strcpy(a->estado, b->estado);
    strcpy(b->estado, temp);
}


void _quick_alfabeto(Node *head, Node *end, int crescente){
    if (!head || head == end || head == end->next)
        return;
    Node *pivo = head;
    Node *i = head;
    Node *j = head->next;
    while(j != end->next){
        int cmp = strcasecmp(j->nome, pivo->nome);
        if((crescente && cmp < 0) || (!crescente && cmp > 0)){
            i = i->next;
            swap(i, j);
        }
        j = j->next;
    }
    swap(head, i);
    _quick_alfabeto(head, i, crescente);
    _quick_alfabeto(i->next, end, crescente);
    
}

Node *quick_alfabeto(Node *lista, int crescente){
    Node *end = lista;
    while(end->next) end = end->next;
    _quick_alfabeto(lista, end, crescente); 
    return lista;
}

void _quick_ID(Node *head, Node *end){
    if (!head || head == end || head == end->next) return;
    Node *pivo = head;
    Node *i = head;
    Node *j = head->next;
    while(j != end->next){
        if(j->id < pivo->id){
            i = i->next;
            swap(i, j);
        }
        j = j->next;
    }
    swap(head, i);
    _quick_ID(head, i);
    _quick_ID(i->next, end);
}

Node *quick_ID(Node *lista){
    Node *end = lista;
    while(end->next) end = end->next;
    _quick_ID(lista, end); 
    return lista;
}

void _quick_cidade(Node *head, Node *end){
    if (!head || head == end || head == end->next)
        return;
    Node *pivo = head;
    Node *i = head;
    Node *j = head->next;
    while(j != end->next){
        int cmp = strcasecmp(j->cidade, pivo->cidade);
        if((cmp < 0)){
            i = i->next;
            swap(i, j);
        }
        j = j->next;
    }
    swap(head, i);
    _quick_cidade(head, i);
    _quick_cidade(i->next, end);
    
}

Node *quick_cidade(Node *lista){
    Node *end = lista;
    while(end->next) end = end->next;
    _quick_cidade(lista, end); 
    return lista;
}

void _quick_estado(Node *head, Node *end){
    if (!head || head == end || head == end->next)
        return;
    Node *pivo = head;
    Node *i = head;
    Node *j = head->next;
    while(j != end->next){
        int cmp = strcasecmp(j->estado, pivo->estado);
        if((cmp < 0)){
            i = i->next;
            swap(i, j);
        }
        j = j->next;
    }
    swap(head, i);
    _quick_estado(head, i);
    _quick_estado(i->next, end);
    
}

Node *quick_estado(Node *lista){
    Node *end = lista;
    while(end->next) end = end->next;
    _quick_estado(lista, end); 
    return lista;
}