#include <iostream>
#include <stdlib.h>

/*
Autor: Adilson Luiz
Date: 25/05/2020
Professo: Ricardo Luis Balieiro*/



// Prótotipos of functions
float calcPercentValuer(float valuer, float realValuer);
int getMenuOptions(float trioEletrico, float arCondicionado, float direHidraulica, float completo);
void printResultToClient(float valorTotalCompra, int* totalOptions);
void initArray(int* arrayToEmpy);
void openGit(void);

using namespace std;

int main() {

    float carro, trioEletrico, arCondicionado, direHidraulica, completo, ipi, descCompleto, vTotalCompra; // Var declaradas para armazena calculos.
    bool finish{false}; // Determina o fim do looping de opções.
    int* totalEscolhido = (int*) malloc(sizeof(int) * 4); // Realiza o somatorio das opções escolidas.
    initArray(totalEscolhido);
    int op{0};

    cout << "Informe o valor do carro: ";
    cin >> carro;

    // Processamento
    ipi = calcPercentValuer(0.8, carro);
    trioEletrico = calcPercentValuer(0.2, carro) + ipi;
    arCondicionado = direHidraulica = calcPercentValuer(0.2, carro);
    completo = trioEletrico + arCondicionado + direHidraulica + ipi;
    descCompleto = (completo * 3.5)/100;

    do {
        op = getMenuOptions(trioEletrico, arCondicionado, direHidraulica, completo);
        switch(op) {
        case 1:
            vTotalCompra += trioEletrico;
            totalEscolhido[0]++;
            break;
        case 2:
            vTotalCompra += arCondicionado;
            totalEscolhido[1]++;
            break;
        case 3:
            vTotalCompra += direHidraulica;
            totalEscolhido[2]++;
            break;
        case 4:
            vTotalCompra += completo;
            totalEscolhido[3]++;
            break;


        }
    }while(op != 0);
    printResultToClient(vTotalCompra, &totalEscolhido[0]);
    openGit();

    return 0;
}


float calcPercentValuer(float percentValuer, float valuer) {

    return valuer * percentValuer;
}


int getMenuOptions(float trioEletrico, float arCondicionado, float direHidraulica, float completo) {
        int option;
        cout << "[0] - Sair do Programa." << endl;
        cout << "[1] - Trio Elétrico, valor R$" << trioEletrico << endl;
        cout << "[2] - Ar Condicionado, valor R$" << arCondicionado << endl;
        cout << "[3] - Direcao Hidraulica, valor R$" << direHidraulica << endl;
        cout << "[4] - Completo, valor R$:" << completo << endl;
        cout << "Opcao: ";
        cin >> option;
        return option;
}


void printResultToClient(float valorTotalCompra, int* totalOptions) {
    /*Foi utilizado a aritmetica de ponteiros para andar pela memoria com computador*/
    system("cls || clear");
    cout << "Valor total da compra ficou em R$" << valorTotalCompra << endl;
    cout << "Relatorio com total de opcoes escolhidas." << endl;
    cout << "\tTrio Eletrico: " << *totalOptions << endl;
    totalOptions++;
    cout << "\tAr Condicionado: " << *totalOptions << endl;
    totalOptions++;
    cout << "\tDirecao Hidraulica: " << *totalOptions << endl;
    totalOptions++;
    cout << "\tCompleto: " << *totalOptions << endl;


}


void initArray(int* arrayToEmpy) {


    for(int i = 0; i <=3; i++) {
        *arrayToEmpy = 0;
        arrayToEmpy++;
    }

}


void openGit(void) {
    //string gitPortifolio  = "https://github.com/ShellAndPython";

    system("start iexplore https://github.com/ShellAndPython");


}
