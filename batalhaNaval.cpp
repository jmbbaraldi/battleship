#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void limpaTela() {
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[10][10]) {

    //Popula o tabuleiro com água
    int linha, coluna;
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 'A';
        }
    }
}

void exibeTabuleiro(char tabuleiro[10][10]) {

    //Exibe o tabuleiro
    int linha, coluna;
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            cout << " " << tabuleiro[linha][coluna];
        }
        cout << "\n";
    }
}

void jogo() {

    ///Variáveis gerais
    char tabuleiro[10][10];         //Tabuleiro do jogo
    int linha, coluna;              //Auxiliares de navegação

    //Inicia o tabuleiro com água
    iniciaTabuleiro(tabuleiro);

    //Exibe o tabuleiro
    exibeTabuleiro(tabuleiro);
}

void menuInicial() {
    //Opção escolhida pelo usuário
    int opcao = 0;

    while ( opcao < 1 || opcao > 3) {
        limpaTela();
        cout << "Bem-vindo ao Jogo de Batalha Naval";
        cout << "\n1- Jogar";
        cout << "\n2- Sobre";
        cout << "\n3- Sair";
        cout << "\nEscolha uma opcao e tecle ENTER: ";
        cin >> opcao;

        switch(opcao) {
        case 1:
            //Inicia o jogo
            jogo();
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
