/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdbool.h>
#include <string>

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
    if (qtde == 0) {
        raiz = n;
        qtde++;
        return;
    }
    if (!Busca(valor)) {
        qtde++;
        raiz = raiz->Insere(raiz, n);
    }
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
    return raiz->Captura_Maximo(raiz);
}

No::No(int valor) {
    dado = valor;
    altura = 0;
    esq = NULL;
    pai = NULL;
    dir = NULL;
}

No::~No() {

}

int Altura(No *n) {
    return n == NULL ? -1 : n->altura;
}

No * No::RotacaoDir(No *n) {
    No *r = n->esq;
    n->esq = r->dir;
    r->dir = n;
    
    if(!n->esq && !n->esq){
        n->altura = 0;
    }else{
        if (Altura(n->esq) > Altura(n->dir)) {
            n->altura = n->esq->altura + 1;
        } else {
            n->altura = n->dir->altura + 1;
        }
    }

    if(!r->esq && !r->esq){
        r->altura = 0;
    }else{
        if (Altura(r->esq) > Altura(r->dir)) {
            r->altura = r->esq->altura + 1;
        } else {
            r->altura = r->dir->altura + 1;
        }
    }
    return r;
}

No * No::RotacaoEsq(No *n) {
    No *r = n->dir;
    n->dir = r->esq;
    r->esq = n;
        
    if(!n->esq && !n->esq){
        n->altura = 0;
    }else{
        if (Altura(n->esq) > Altura(n->dir)) {
            n->altura = n->esq->altura + 1;
        } else {
            n->altura = n->dir->altura + 1;
        }
    }

    if(!r->esq && !r->esq){
        r->altura = 0;
    }else{
        if (Altura(r->esq) > Altura(r->dir)) {
            r->altura = r->esq->altura + 1;
        } else {
            r->altura = r->dir->altura + 1;
        }
    }
    return r;
}

//No * No::RegulaFB(No *n, int lado){ // 1 esq 2 dir
//    if (lado == 1){
//        if (n->fb == 0){
//            n->fb = 1;
//            return n;
//        }else if (n->fb == 1){//dir ou esq-dir
//            if (n->esq->fb == 1){
//                n = RotacaoDir(n);
//                n->fb = 0;
//            }else if(n->esq->fb == -1){
//                n->esq = RotacaoEsq(n->esq);
//                n = RotacaoDir(n);
//                n->fb = 0;
//            }
//            return n;
//        }else if (n->fb == -1){
//            n->fb = 0;
//            return n;
//        }
//    }else{ 
//        if (n->fb == 0){
//            n->fb = -1;
//            return n;
//        }else if (n->fb == 1){
//            n->fb = 0;
//            return n;
//        }else if (n->fb == -1){
//            if (n->esq->fb == 1){
//                n = RotacaoEsq(n);
//            }else if(n->esq->fb == -1){
//                n->esq = RotacaoEsq(n->esq);
//                n = RotacaoDir(n);
//            }
//            return n;
//        }
//    }
//}

No * No::Insere(No *curr, No * n) {
    if (curr == NULL)
        return n;
    if (curr->dado > n->dado) { // inserção a esquerda
        curr->esq = Insere(curr->esq, n);
        int altura_dir = !curr->dir ? 0 : (curr->dir->altura + 1);
        int altura_esq = !curr->esq ? 0 : (curr->esq->altura + 1);


        if ((altura_esq - altura_dir) == 2) {
            if (n->dado < curr->esq->dado) {
                curr = RotacaoDir(curr);
            } else {
                curr->esq = RotacaoEsq(curr->esq);
                curr = RotacaoDir(curr);

            }
        }
        //        curr = RegulaFB(curr, 1);
    } else { // inserção a direita
        curr->dir = Insere(curr->dir, n);
        int altura_dir = !curr->dir ? 0 : (curr->dir->altura + 1);
        int altura_esq = !curr->esq ? 0 : (curr->esq->altura + 1);


        if ((altura_dir - altura_esq) == 2) {
            if (n->dado > curr->dir->dado) {
                curr = RotacaoEsq(curr);
            } else {
                curr->dir = RotacaoDir(curr->dir);
                curr = RotacaoEsq(curr);

            }
        }
        //        curr = RegulaFB(curr, 2);
    }
    if (curr->esq == NULL) {
        curr->altura = curr->dir->altura + 1;
    } else if (curr->dir == NULL) {
        curr->altura = curr->esq->altura + 1;
    } else if (curr->esq->altura > curr->dir->altura) {
        curr->altura = curr->esq->altura + 1;
    } else {
        curr->altura = curr->dir->altura + 1;
    }
    return curr;
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

No *No::Captura_Maximo(No* raiz) {
    if (raiz->dir == NULL) {
        return raiz;
    }
    if (raiz) {
        return Captura_Maximo(raiz->dir);
        //        return Captura_Maximo(raiz->esq, maior);
    }

}

bool No::Remove(int valor, No *raiz, No *pai) {
    if (raiz == NULL) {
        return false;
    }
    if (valor == raiz->dado) {
        No *aux = raiz;
        if (raiz->esq == NULL || raiz->dir == NULL) {
            //delete one child
            if (raiz->esq == NULL && raiz->dir == NULL) {
                // nao tem filho
                if (raiz->dado > pai->dado) {
                    // filho dir
                    pai->dir = NULL;
                    free(raiz);
                } else {
                    // filho esq
                    pai->esq = NULL;
                    free(raiz);
                }
                return true;
            } else if (raiz->dir == NULL) {
                // tem um filho a esquerda
                if (raiz->dado > pai->dado) {
                    // filho dir
                    pai->dir = raiz->esq;
                    free(raiz);
                } else {
                    // filho esq
                    pai->esq = raiz->esq;
                    free(raiz);
                }
                return true;
            } else if (raiz->esq == NULL) {
                // tem um filho a direita
                if (raiz->dado > pai->dado) {
                    // filho dir
                    pai->dir = raiz->dir;
                    free(raiz);
                } else {
                    // filho esq
                    pai->esq = raiz->dir;
                    free(raiz);
                }
                return true;
            }
        } else {
            //TODO problema qdo no for raiz da arv
            // tem dois filhos
            aux = Captura_Maximo(raiz->esq); // TEM QUE VE ESSA PORRA
            raiz->dado = aux->dado;
            raiz->esq->Remove(aux->dado, raiz->esq, raiz);
            free(aux);
            return true;
        }
    } else if (valor < raiz->dado) {
        return Remove(valor, raiz->esq, raiz);
    } else {
        return Remove(valor, raiz->dir, raiz);
    }
}


// =============== MANIPULAÇÃO DE ARQUIVOS================================================

bool writeFile(ofstream& file, string strFile) { // Abrir Arquivo para Escrita NO FINAL
    file.open(strFile, ios::ate | ios::app);
    return !(file.fail() || !file.is_open() || !file.good());
}

bool writeFileFinal(ofstream& file, string strFile) { // Abrir Arquivo para Escrita NO COMEÇO
    file.open(strFile);
    return !(file.fail() || !file.is_open() || !file.good());
}

bool readFile(std::ifstream &ifile, std::string strFile) { // Abrir Arquivo para Leitura
    ifile.open(strFile);
    return !(ifile.fail() || !ifile.is_open() || !ifile.good());
}