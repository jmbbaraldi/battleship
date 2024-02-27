#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela() {
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]) {

    //Popula o tabuleiro com água
    int linha, coluna;
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }
}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10]) {

    //Exibe o tabuleiro
    int linha, coluna;
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            //cout << " " << tabuleiro[linha][coluna];
            cout << " " << mascara[linha][coluna];
        }
        cout << "\n";
    }
}

void posicionaBarcos(char tabuleiro[10][10]) {

    int i, quantidade = 10, quantidadePosicionada = 0;

    while(quantidadePosicionada < quantidade) {
        int linhaAleatoria = rand() % 10; //Linha de posicionamento é aleatória
        int colunaAleatoria = rand() % 10; //Coluna de posicionamento é aleatória

        if(tabuleiro[linhaAleatoria][colunaAleatoria] == 'A') {
            tabuleiro[linhaAleatoria][colunaAleatoria] = 'P';

            //Aumenta a quantidade posicionada
            quantidadePosicionada++;
        }
    }
}

void jogo() {

    ///Variáveis gerais
    char tabuleiro[10][10], mascara[10][10];            //Tabuleiro do jogo
    int linha, coluna;                                  //Auxiliares de navegação
    int linhaJogada, colunaJogada;                      //Posição escolhida pelo jogador
    int estadoDeJogo = 1;                               //1 =  jogo acontecendo; 0 = fim de jogo

    //Inicia o tabuleiro com água
    iniciaTabuleiro(tabuleiro, mascara);

    //Posiciona os barcos aleatoriamente
    posicionaBarcos(tabuleiro);

    while(estadoDeJogo == 1) {

        limpaTela();

        //Exibe o tabuleiro
        exibeTabuleiro(tabuleiro, mascara);

        cout << "\nDigite uma linha: ";
        cin >> linhaJogada;
        cout << "\nDigite uma coluna: ";
        cin >> colunaJogada;

        //Revela o que está no tabuleiro
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
    }

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

    srand((unsigned)time(NULL));

    menuInicial();

    return 0;
}
