#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

//Cabeçalhos de funções
void menuInicial();


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

void exibeMapa() {
    //Mapa indicador de colunas
    int i;
    for(i = 0; i < 10; i++) {
        if(i == 0) {
            cout << "     ";
        }
        cout << i << " ";
    }
    cout << "\n";
    for(i = 0; i < 10; i++) {
        if(i == 0) {
            cout << "     ";
        }
        cout << "| ";
    }
    cout << "\n";
}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10]) {

    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };

    //Exibe o tabuleiro
    int linha, coluna;
    for (linha = 0; linha < 10; linha++) {
        cout << linha << " - ";
        for (coluna = 0; coluna < 10; coluna++) {
            //cout << " " << tabuleiro[linha][coluna];
            switch(mascara[linha][coluna]) {
                case 'A':
                    cout << blue << " " << mascara[linha][coluna] << normal;
                    break;
                case 'P':
                    cout << green << " " << mascara[linha][coluna] << normal;
                    break;
                default:
                    cout << " " << mascara[linha][coluna];
                    break;
            }
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

void jogo(string nomeDoJogador) {

    ///Variáveis gerais
    char tabuleiro[10][10], mascara[10][10];            //Tabuleiro do jogo
    int linha, coluna;                                  //Auxiliares de navegação
    int linhaJogada, colunaJogada;                      //Posição escolhida pelo jogador
    int estadoDeJogo = 1;                               //1 =  jogo acontecendo; 0 = fim de jogo
    int pontos = 0;                                     //Pontuação do jogador
    int tentativas = 0, maxDeTentativas = 5;            //Tentativas do jogador
    int opcao;                                          //Opções de fim de jogo
    string mensagem = "Bem-vindo ao jogo!";             //Feedback para o jogador

    //Inicia o tabuleiro com água
    iniciaTabuleiro(tabuleiro, mascara);

    //Posiciona os barcos aleatoriamente
    posicionaBarcos(tabuleiro);

    while(tentativas < maxDeTentativas) {

        limpaTela();

        //Exibe o mapa
        exibeMapa();

        //Exibe o tabuleiro
        exibeTabuleiro(tabuleiro, mascara);

        cout << "\nPontos: " << pontos << " | Tentativas Restantes: " << maxDeTentativas - tentativas;
        cout << "\n" << mensagem;

        //Verificação de dados
        linhaJogada = -1;
        colunaJogada = -1;

        while( (linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada > 9) ) {
            cout << "\n" << nomeDoJogador << ", digite uma linha: ";
            cin >> linhaJogada;
            cout << "\n" << nomeDoJogador << ", digite uma coluna: ";
            cin >> colunaJogada;
        }


        //Verifica a jogada
        verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);

        //Revela o que está no tabuleiro
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];

        tentativas++;
    }

    cout << "Fim de jogo, o que deseja fazer? ";
    cout << "\n1- Jogar novamente";
    cout << "\n2- Ir para o menu inicial";
    cout << "\n3- Sair\n";
    cin >> opcao;
    switch(opcao) {
        case 1:
            jogo(nomeDoJogador);
            break;
        case 2:
            menuInicial();
            break;
        case 3:
            break;
    }
}

void menuInicial() {
    //Opção escolhida pelo usuário
    int opcao = 0;

    string nomeDoJogador;                               //Nome do susuário

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
            cout << "Qual o sue nome? \n";
            cin >> nomeDoJogador;
            //Inicia o jogo
            jogo(nomeDoJogador);
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
