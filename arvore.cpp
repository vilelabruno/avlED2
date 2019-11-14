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
        return raiz->Remove(valor, raiz, NULL);
    }
    return false;
}

No * Arvore::Captura_Maximo() {
    return raiz->Captura_Maximo(raiz, NULL);
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

No *No::Captura_Maximo(No *raiz, No* maior) {
    if (raiz) {
        if (raiz->dado > maior->dado) {
            Captura_Maximo(raiz->esq, raiz);
            Captura_Maximo(raiz->dir, raiz);
        } else {
            Captura_Maximo(raiz->esq, maior);
            Captura_Maximo(raiz->dir, maior);
        }
    } else {
        return maior;
    }
}

bool No::Remove(int valor, No *raiz, No *Pai) {
    if (raiz->dado > valor)
        return raiz->Remove(valor, raiz->esq, raiz);
    if (raiz->dado < valor)
        return raiz->Remove(valor, raiz->dir, raiz);

    if (raiz->dado == valor) {
        if (raiz->dir == NULL and raiz->esq == NULL) {
            if (raiz->dado > Pai->dado) {
                // filho dir
                Pai->dir = NULL; // exclusão
                return true;
            } else {
                // filho esq
                Pai->esq = NULL;
                return true;
            }
        }
        if (raiz->dir != NULL and raiz->esq == NULL) {
            // apenas um filho, remove o nó e coloca o filho no lugar
            if (raiz->dado > Pai->dado) {
                // filho dir
                Pai->dir = raiz->dir; // exclusão
                return true;
            } else {
                // filho esq
                Pai->esq = raiz->dir;
                return true;
            }
        }
        if (raiz->dir == NULL and raiz->esq != NULL) {
            // apenas um filho, remove o nó e coloca o filho no lugar
            if (raiz->dado > Pai->dado) {
                // filho dir
                Pai->dir = raiz->esq; // exclusão
                return true;
            } else {
                // filho esq
                Pai->esq = raiz->esq;
                return true;
            }
        }
        if (raiz->dir != NULL and raiz->esq != NULL) {
            // o no possui dois filhos, substituir pelo maior nó da sub-arvore esquerda
            No *n = raiz->esq; //guarda maior a esquerda
            No *n_pai = raiz; // guarda pai do maior a esquerda
            while (n->dir != NULL) {
                n = n->dir;
                n_pai = n;
            }
            
            if (Pai == NULL) {
                // REMOÇÃO DA RAIZ
//                n->esq = raiz->esq;
//                n->dir = raiz->dir;
//                n_pai->dir = NULL;
            } else {
                // REMOÇÃO DO MEIO DA ARVORE
                if (raiz->dado > Pai->dado) {
                    // filho dir
                    Remove(n->dado,raiz, Pai);
                    Pai->dir = n;
                    n->esq = raiz->esq;
                    n->dir = raiz->dir;
                    return true;
                } else {
                    // filho esq
                    Remove(n->dado,raiz, Pai);
                    Pai->esq = n;
                    n->esq = raiz->esq;
                    n->dir = raiz->dir;
                    return true;
                }
            }
        }
    }
}