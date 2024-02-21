#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void limpaTela() {
    system("CLS");
}

void menuInicial() {
    //Opção escolhida pelo usuário
    int opcao = 0;

    while ( opcao < 1 || opcao > 3) {
        limpaTela();
        cout << "Bem-vindo ao Jogo";
        cout << "\n1- Jogar";
        cout << "\n2- Sobre";
        cout << "\n3- Sair";
        cout << "\nEscolha uma opcao e tecle ENTER: ";
        cin >> opcao;

        switch(opcao) {
        case 1:
            //Inicia o jogo
            break;

        case 2:
            //Informações do jogo
            break;

        case 3:
            //Sai do jogo
            cout << "Ate mais!";
            break;

        }
    }
}

int main() {

    menuInicial();

    return 0;
}
