#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

//Cabe�alhos de fun��es
void menuInicial();


void limpaTela() {
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]) {

    //Popula o tabuleiro com �gua
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
        int linhaAleatoria = rand() % 10; //Linha de posicionamento � aleat�ria
        int colunaAleatoria = rand() % 10; //Coluna de posicionamento � aleat�ria

        if(tabuleiro[linhaAleatoria][colunaAleatoria] == 'A') {
            tabuleiro[linhaAleatoria][colunaAleatoria] = 'P';

            //Aumenta a quantidade posicionada
            quantidadePosicionada++;
        }
    }
}

void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem) {
    //Verifica quantos pontos adicionar
    switch(tabuleiro[linhaJogada][colunaJogada]) {
        case 'P':
            *pontos = *pontos + 10;
            *mensagem = "Voce acertou um barco pequeno! (10 pts)";
            break;
        case 'A':
            *mensagem = "Voce acertou a agua!";
            break;
    }
}

void jogo() {

    ///Vari�veis gerais
    char tabuleiro[10][10], mascara[10][10];            //Tabuleiro do jogo
    int linha, coluna;                                  //Auxiliares de navega��o
    int linhaJogada, colunaJogada;                      //Posi��o escolhida pelo jogador
    int estadoDeJogo = 1;                               //1 =  jogo acontecendo; 0 = fim de jogo
    int pontos = 0;                                     //Pontua��o do jogador
    int tentativas = 0, maxDeTentativas = 5;            //Tentativas do jogador
    int opcao;                                          //Op��es de fim de jogo
    string mensagem = "Bem-vindo ao jogo!";             //Feedback para o jogador

    //Inicia o tabuleiro com �gua
    iniciaTabuleiro(tabuleiro, mascara);

    //Posiciona os barcos aleatoriamente
    posicionaBarcos(tabuleiro);

    while(tentativas < maxDeTentativas) {

        limpaTela();

        //Exibe o tabuleiro
        exibeTabuleiro(tabuleiro, mascara);

        cout << "\nPontos: " << pontos << " | Tentativas Restantes: " << maxDeTentativas - tentativas;
        cout << "\n" << mensagem;
        cout << "\nDigite uma linha: ";
        cin >> linhaJogada;
        cout << "\nDigite uma coluna: ";
        cin >> colunaJogada;

        //Verifica a jogada
        verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);

        //Revela o que est� no tabuleiro
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];

        tentativas++;
    }

    limpaTela();

    cout << "Fim de jogo, o que deseja fazer? ";
    cout << "\n1- Jogar novamente";
    cout << "\n2- Ir para o menu inicial";
    cout << "\n3- Sair\n";
    cin >> opcao;
    switch(opcao) {
        case 1:
            jogo();
            break;
        case 2:
            menuInicial();
            break;
        case 3:
            break;
    }
}

void menuInicial() {
    //Op��o escolhida pelo usu�rio
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
            //Informa��es do jogo
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
