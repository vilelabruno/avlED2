/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvore.h
 * Author: 2019.1.08.041
 *
 * Created on 31 de Outubro de 2019, 16:16
 */

#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

using namespace std;


class Arvore{
public:
    Arvore();
    ~Arvore();
    void Pre_Ordem();
    void Pos_Ordem();
    void Em_Ordem();
    void Insere(int valor);
    bool Busca(int valor);
    bool Remove(int valor);
    No *raiz;
    int qtde;
};

class No{       //Nó da Árvore
public:
    No(int valor);  //Construtor
    ~No();          //Destrutor
    void Pre_Ordem(No *raiz);
    void Pos_Ordem(No *raiz);
    void Em_Ordem(No *raiz);
    bool Busca(int valor, No *raiz);
    No *Busca_Pai(int valor, No *raiz);
    bool Remove(int valor, No *raiz);
    bool Remove_Atual(No * atual);
    No *Insere(No *raiz, No *n);
    int dado;
    No *esq, *dir;
};

#endif /* ARVORE_H */

