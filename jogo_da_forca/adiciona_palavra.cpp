#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "le_arquivo.hpp"

void adiciona_palavra(){
    std::cout << "Digite a palavra a ser adicionada, em letras maiusculas" << std::endl;
    std::string palavra_a_ser_adicionada;
    std::cin >> palavra_a_ser_adicionada;

    std::vector<std::string> palavras = le_arquivo();
    palavras.push_back(palavra_a_ser_adicionada);

    std::ofstream arquivo;
    arquivo.open("palavras.txt");

    if(!arquivo.is_open()){
        std::cout << "Não foi possível encontrar o banco de palavras" << std::endl;
        exit(0);
    }

    arquivo << palavras.size() << std::endl;

    for(std::string palavra : palavras){
        arquivo << palavra << std::endl;
    }

    arquivo.close();
}