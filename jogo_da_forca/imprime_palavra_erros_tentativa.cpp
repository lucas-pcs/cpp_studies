#include "imprime_palavra_erros_tentativa.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>

extern std::string palavra_secreta;
extern std::map<char,bool> chutou;
extern std::vector<char> palavras_ja_chutadas;
extern int numero_de_tentativas;

void imprime_palavra(){
    std::cout << "Palavra Secreta: ";
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            std::cout << letra << " ";
        }
        else{
            std::cout << "_" << " ";
        }
    }
    std::cout << std::endl;
}

void imprime_erros(){
    std::cout << "Palavras já chutadas: ";
    for(char letra : palavras_ja_chutadas){
        std::cout << letra << " ";
    }
    std::cout << std::endl;
}

void imprime_tentativa(){
    std::cout << "Tentativa: " << numero_de_tentativas << std::endl;
}