/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<cstdlib>
#include"arvore.h"

using namespace std;

Arvore::Arvore() {
    raiz = NULL;
    qtde = 0;
}

Arvore::~Arvore() {

}

void Arvore::Pre_Ordem() {
    raiz->Pre_Ordem(raiz);
}

void Arvore::Pos_Ordem() {
    raiz->Pos_Ordem(raiz);
}

void Arvore::Em_Ordem() {
    raiz->Em_Ordem(raiz);
}

void Arvore::Insere(int valor) {
    No *n = new No(valor);
    raiz->Insere(raiz, n);
}

bool Arvore::Busca(int valor) {
    return raiz->Busca(valor, raiz);
}

bool Arvore::Remove(int valor) {
    if (raiz->Busca(valor, raiz)) {
        return raiz->Remove(valor, raiz);
    }
    return false;
}

No::No(int valor) {
    dado = valor;
    esq = NULL;
    dir = NULL;
}

No::~No() {

}

No * No::Insere(No *raiz, No * n) {
    if (raiz == NULL)
        return n;
    if (raiz->dado > n->dado)
        raiz->esq = Insere(raiz->esq, n);
    else
        raiz->dir = Insere(raiz->dir, n);
    return raiz;
}

void No::Pre_Ordem(No *raiz) {
    if (raiz) {
        cout << raiz->dado << " ";
        Pre_Ordem(raiz->esq);
        Pre_Ordem(raiz->dir);
    }
}

void No::Pos_Ordem(No *raiz) {
    if (raiz) {
        Pos_Ordem(raiz->esq);
        Pos_Ordem(raiz->dir);
        cout << raiz->dado << " ";
    }
}

void No::Em_Ordem(No *raiz) {
    if (raiz) {
        Em_Ordem(raiz->esq);
        cout << raiz->dado << " ";
        Em_Ordem(raiz->dir);
    }
}

bool No::Busca(int valor, No *raiz) {
    if (raiz) {
        if (raiz->dado == valor)
            return true;
        if (raiz->dado > valor)
            return Busca(valor, raiz->esq);
        else
            return Busca(valor, raiz->dir);
    } else return false;
}

bool No::Busca_Pai(int valor, No* raiz) {
    return false;
}

bool No::Remove(int valor, No *raiz, No *Pai) {
    if (raiz->dado > valor)
        return raiz->Remove(valor, raiz->esq, raiz);
    if (raiz->dado < valor)
        return raiz->Remove(valor, raiz->dir, raiz);
    
    if (raiz->dado == valor) {
        if(raiz->dir == NULL and raiz->esq == NULL){
            // nenhum filho, apenas remove
            
        }
        if((raiz->dir != NULL and raiz->esq == NULL) or
           (raiz->dir == NULL and raiz->esq != NULL)){
            // apenas um filho, remove o nó e coloca o filho no lugar
        }
        if(raiz->dir != NULL and raiz->esq != NULL){
            // o no possui dois filhos, duas opções:
            //    a) substituir pelo maior nó da sub-arvore esquerda
            //    b) substituir pelo menor nó da sub-arvore direita
        }
    }
}





