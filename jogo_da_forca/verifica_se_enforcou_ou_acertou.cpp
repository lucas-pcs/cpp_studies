#include <iostream>
#include <map>
#include <string>
#include "verifica_se_enforcou_ou_acertou.hpp"
#include "adiciona_palavra.hpp"


extern int numero_de_tentativas;
extern bool nao_enforcou;
extern bool nao_acertou;
extern std::string palavra_secreta;
extern std::map<char,bool> chutou;
const int NUMERO_DE_TENTATIVAS_MAXIMO = 12;

void verifica_se_enforcou(){
    if(numero_de_tentativas == NUMERO_DE_TENTATIVAS_MAXIMO + 1){
        nao_enforcou = false;
        std::cout << "Fim de jogo, você enforcou!" << std::endl;
    }
}

void verifica_se_acertou(){
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return;
        }
    }
    nao_acertou = false;
    std::cout << "Fim de jogo, você acertou!" << std::endl;
    std::cout << "Você deseja adicionar uma palavra ao banco de palavras ? (S/N): ";
    char opcao;
    std::cin >> opcao;
    if(opcao == 'S'){
        adiciona_palavra();
    }
}