#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "le_arquivo.hpp"

// --- lendo o arquivo de texto que irá conter todas as palavras disponíveis para o jogo
std::vector<std::string> le_arquivo(){
    std::ifstream arquivo;
    arquivo.open("palavras.txt");

    if(!arquivo.is_open()){
        std::cout << "Não foi possível acessar o banco de palavras." << std::endl;
        exit(0);
    }

    int numero_de_palavras;
    arquivo >> numero_de_palavras;
    // cout << "O número de palavras no arquivo é: " << numero_de_palavras << endl;

/*     ifstream arquivo = ifstream("palavras.txt");
    int numero_de_palavras;
    arquivo >> numero_de_palavras;
    cout << numero_de_palavras << endl; */

    std::vector<std::string> palavras;
    std::string palavra_lida;

    for(int i = 0; i < numero_de_palavras; i++){
        arquivo >> palavra_lida;
        palavras.push_back(palavra_lida);
        // cout << palavras[i] << endl;
    }

    arquivo.close();
    return palavras;
}