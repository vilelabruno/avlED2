/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2019.1.08.041
 *
 * Created on 31 de Outubro de 2019, 16:15
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "arvore.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Arvore *arv = new Arvore;

//    arv->Insere(10);
    arv->raiz = new No(15); //TODO resolve a raiz

    //arv->Insere(15);
    arv->Insere(7);
    arv->Insere(30);
    arv->Insere(31);
    arv->Insere(29);
    arv->Insere(1);
    arv->Insere(2);
    arv->Insere(5);
    arv->Insere(8);
    arv->Insere(4);

    
    cout << arv->Remove(30) << " ";
//    cout << arv->Busca(16) << " ";
    
    
    arv->Insere(99);
//    cout << arv->Captura_Maximo();
    
    
//    cout << "Estado inicial da arvore(pos): " << endl;
//    arv->Pos_Ordem();
//    cout << endl << endl;
//
//    cout << "Estado inicial da arvore(pre): " << endl;
//    arv->Pre_Ordem();
//    cout << endl << endl;
//
//    cout << "Estado inicial da arvore(em): " << endl;
//    arv->Em_Ordem();
//    cout << endl;

    return 0;
}

