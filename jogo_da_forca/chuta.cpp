#include <iostream>
#include <vector>
#include <map>

#include "chuta.hpp"
#include "verifica_chute.hpp"

extern int numero_de_tentativas;
extern std::map<char,bool> chutou;
extern std::vector<char> palavras_ja_chutadas;

// --- Adiciona o chute no vetor de chutes, que será usado para imprimir a palavra e os erros
void chuta(){
    std::cout << "Digite seu chute: ";

    char chute;
    std::cin >> chute;
    numero_de_tentativas += 1;

    if(verifica_chute(chute)){
        chutou[chute] = true;
        std::cout << "Seu chute está contido na palavra secreta" << std::endl;
    }
    else{
        palavras_ja_chutadas.push_back(chute);
        std::cout << "Seu chute não está contido na palavra secreta" << std::endl;
    }
}
