#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "le_arquivo.hpp"
#include "imprime_inicio.hpp"
#include "verifica_se_enforcou_ou_acertou.hpp"
#include "imprime_palavra_erros_tentativa.hpp"
#include "chuta.hpp"
#include "sorteia_palavra.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

// --- Variaveis
string palavra_secreta;
const int NUMERO_DE_TENTATIVAS_MAXIMO = 12;
int numero_de_tentativas = 1;
bool nao_enforcou = true;
bool nao_acertou = true;
char chute;

// -- Estrutura que irá conter se determinado caracter já foi chutado pelo usuário e não está contido na palavra
vector<char> palavras_ja_chutadas;

// -- Estrutura que irá conter se determinado caracter já foi chutado pelo usuário e está contido na palavra
map<char,bool> chutou;

int main(){

    imprime_inicio();
    sorteia_palavra();

    while(nao_enforcou && nao_acertou){

        imprime_tentativa();
        chuta();
        imprime_palavra();
        imprime_erros();
        verifica_se_acertou();
        verifica_se_enforcou();
        cout << endl;

    }

    return 0;
}