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
int rotacao = 0;
Arvore::Arvore() {
    raiz = NULL;
    qtde = 0;
    folhas = 0;
}

Arvore::~Arvore() {

}

void Arvore::Pre_Ordem() {
    raiz->Pre_Ordem(raiz);
}

void Arvore::Pos_Ordem() {
    raiz->Pos_Ordem(raiz);
}

void atualiza_altura(No * n) {
    int alt1 = n->esq ? n->esq->altura : 0;
    int alt2 = n->dir ? n->dir->altura : 0;
    n->altura = alt1 > alt2 ? alt1 + 1 : alt2 + 1;
}

void pre_ordem_altura(No *n) {
    if (n) {
        pre_ordem_altura(n->esq);
        pre_ordem_altura(n->dir);
        atualiza_altura(n);
    }
}

void Arvore::Estado() {
    int qtdf = raiz->QtdFolhas(raiz);
    cout << "_____________________________________________________" << endl;
    cout << endl << "Estado da arvore:" << endl << endl;
    cout << "Folhas                             : " << qtdf << endl;
    pre_ordem_altura(raiz);
    cout << "Nivel maximo                       : " << raiz->altura << endl;
    cout << "Nivel medio(maximo/2)              : " << raiz->altura / 2 << endl;
    cout << "Nos intermediarios(excluso a raiz) : " << (qtde - qtdf - 1) << endl;
    cout << "Rotacoes : " << rotacao << endl;
    cout << "_____________________________________________________" << endl;
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
        raiz = raiz->Remove(valor, raiz, NULL);
        return true;
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
    rotacao++;
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
    rotacao++;
    return r;
}

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
int No::QtdFolhas(No *n)  
{  
    if(n == NULL)      
        return 0;  
    if(n->esq == NULL && n->dir == NULL)  
        return 1;          
    else
        return QtdFolhas(n->esq)+  
            QtdFolhas(n->dir);  
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

No *No::Remove(int valor, No *raiz, No *pai) {
    if (raiz == NULL) {
        return NULL;
    }
    if (valor == raiz->dado) {
        No *aux = raiz;
        if (raiz->esq == NULL && raiz->dir == NULL) {
            return NULL;
        }else if (raiz->esq == NULL || raiz->dir == NULL) {
            //delete one child
            if (raiz->dir == NULL) {
                // tem um filho a esquerda
                raiz = raiz->esq;
            } else if (raiz->esq == NULL) {
                raiz = raiz->dir;
            }
        } else {
            //TODO problema qdo no for raiz da arv
            // tem dois filhos
            aux = Captura_Maximo(raiz->esq); // TEM QUE VE ESSA PORRA
            raiz->dado = aux->dado;
            raiz->esq = raiz->esq->Remove(aux->dado, raiz->esq, raiz);
            free(aux);
            //return true;
        }
    } else if (valor < raiz->dado) {
        raiz->esq = Remove(valor, raiz->esq, raiz);
    } else {
        raiz->dir = Remove(valor, raiz->dir, raiz);
    }
    if (raiz == NULL) return raiz;
    if (Altura(raiz->esq) > Altura(raiz->dir) ) {
        raiz->altura = Altura(raiz->esq) + 1;
    } else {
        raiz->altura = Altura(raiz->dir) + 1;
    }
    int altura_dir = !raiz->dir ? 0 : (raiz->dir->altura);
    int altura_esq = !raiz->esq ? 0 : (raiz->esq->altura);


    if ((altura_esq - altura_dir) == 2) {
        if ((Altura(raiz->esq->esq) - Altura(raiz->esq->dir)) == 1) {
            raiz = RotacaoEsq(raiz);
        } else {
            raiz->esq = RotacaoDir(raiz->esq);
            raiz = RotacaoEsq(raiz);
        }
    }else if ((altura_dir - altura_esq) == 2) {
        if ((Altura(raiz->dir->dir) - Altura(raiz->dir->esq)) == 1) {
            raiz = RotacaoDir(raiz);
        } else {
            raiz->dir = RotacaoEsq(raiz->dir);
            raiz = RotacaoDir(raiz);
        }
    }
    return raiz;
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