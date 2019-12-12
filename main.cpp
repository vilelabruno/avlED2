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

    //Controle de arquivo (Abrindo arquivo e fazendo sua leitura)
    int control = 1; // 0 for test read file, 1 for manual insertion
    if (control) {
//        arv->Insere(1);
//        arv->Insere(2);
//        arv->Insere(3);
        arv->Insere(15);
        arv->Insere(7);
        arv->Insere(30);
        arv->Insere(30);
        arv->Insere(31);
        arv->Insere(29);
        arv->Insere(1);
        arv->Insere(2);
        arv->Insere(5);
        arv->Insere(8);
        arv->Insere(4);
        cout << arv->Remove(15) << " ";
        //    cout << arv->Busca(16) << " ";
        arv->Insere(99);
    } else {
        ofstream outFile;
        ifstream arvore;
        bool status;
        int tam = 0;
        char op;
        int dado;

        status = readFile(arvore, "arquivo.txt");
        //Teste de abertura de arquivo
        if (!status) {
            cout << "Arquivo não pode ser aberto para leitura." << endl;
            cout << "Programa terminando..." << endl;
        } else {
            //Leitura do arquivo
            while (!arvore.eof()) {
                arvore >> op;
                switch (op) {
                        //inserir, remover, buscar e estado
                    case 'i':
                    {
                        arvore >> tam;
                        for (int i = 0; i < tam; i++) {
                            if (i == 0) {
                                arvore >> dado;
                                arv->raiz = new No(dado);
                                cout << dado;
                            } else {
                                arvore >> dado;
                                arv->Insere(dado);
                                cout << dado;
                            }

                        }
                        break;
                    }
                    case 'r':
                        break;
                    case 'b':
                    {
                        arvore >> tam;
                        for (int i = 0; i < tam; i++) {
                            arvore >> dado;
                            cout << arv->Busca(dado) << " ";
                        }
                        break;
                    }
                    case 'e':
                        break;
                    default:
                        break;
                }
            }
        }
    }
    arv->Estado();
    return 0;
}

