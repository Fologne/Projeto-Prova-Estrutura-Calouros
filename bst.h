#pragma once

typedef struct bst{
    char nome[41];
    Node *ref; 
    struct bst *left;
    struct bst *right;
}BST;
