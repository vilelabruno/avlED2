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

    //Controle de arquivo (Abrindo arquivo e fazendo sua leitura)
    ofstream outFile;
    ifstream arvore;
    bool status;
    int tam = 0;
    char op;
    int dado;

    Arvore *arv = new Arvore;

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
                        } else {
                            arvore >> dado;
                            arv->Insere(dado);
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
return 0;
}

