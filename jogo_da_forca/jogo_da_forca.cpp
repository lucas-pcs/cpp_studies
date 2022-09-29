#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

// --- Variaveis
string PALAVRA_SECRETA;
const int NUMERO_DE_TENTATIVAS_MAXIMO = 12;
int numero_de_tentativas=1;
bool nao_enforcou = true;
bool nao_acertou = true;
char chute;

/* string caracteres_adivinhados(PALAVRA_SECRETA.size(),'_'); */

// -- Estrutura que irá conter se determinado caracter já foi chutado pelo usuário e não está contido na palavra
vector<char> palavras_ja_chutadas;

// -- Estrutura que irá conter se determinado caracter já foi chutado pelo usuário e está contido na palavra
map<char,bool> chutou;

void verifica_se_enforcou(){
    if(numero_de_tentativas == NUMERO_DE_TENTATIVAS_MAXIMO + 1){
        nao_enforcou = false;
        cout << "Fim de jogo, você enforcou!" << endl;
    }
}

void verifica_se_acertou(){
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return;
        }
    }
    nao_acertou = false;
    cout << "Fim de jogo, você acertou!" << endl;
}

// --- Retorna true se o chute está contido na palavra e false caso contrário.
bool verifica_chute(char chute){
    for(char letra : PALAVRA_SECRETA){
        if(letra == chute){
            return true;
        }
    }
    return false;

/*     bool verifica = false;
    int i = 0;
    // --- Verifica e constroi a palavra adivinhada até o momento
     while(i < PALAVRA_SECRETA.size()){
        if(chute == PALAVRA_SECRETA[i]){
            caracteres_adivinhados[i] = chute;
            verifica = true;
        }
        i = i + 1;
    } 
    return verifica; */

    /* loop usando novo for do c++11, não printa na tela o estado atual da palavra a ser adivinhada e nem contempla o caso de palavras repetidas
    for(char interador : PALAVRA_SECRETA){
        if(chute == interador){
            return true;
        }
    }
    return false;
    */
}

// --- Adiciona o chute no vetor de chutes, que será usado para imprimir a palavra e os erros
void chuta(){
    cout << "Digite seu chute: ";

    char chute;
    cin >> chute;
    numero_de_tentativas += 1;

    if(verifica_chute(chute)){
        chutou[chute] = true;
        cout << "Seu chute está contido na palavra secreta" << endl;
    }
    else{
        palavras_ja_chutadas.push_back(chute);
        cout << "Seu chute não está contido na palavra secreta" << endl;
    }
}

void imprime_palavra(){
    cout << "Palavra Secreta: ";
    for(char letra : PALAVRA_SECRETA){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_" << " ";
        }
    }
    cout << endl;
}

void imprime_erros(){
    cout << "Palavras já chutadas: ";
    for(char letra : palavras_ja_chutadas){
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_tentativa(){
    cout << "Tentativa: " << numero_de_tentativas << endl;
}

void imprime_inicio(){
    cout << "**************************************" << endl;
    cout << "***** Bem vindo ao jogo da forca *****" << endl;
    cout << "**************************************" << endl;
    cout << endl;
}

// --- lendo o arquivo de texto que irá conter todas as palavras disponíveis para o jogo
vector<string> le_arquivo(){
    ifstream arquivo;
    arquivo.open("palavras.txt");

    int numero_de_palavras;
    arquivo >> numero_de_palavras;
    cout << "O número de palavras no arquivo é: " << numero_de_palavras << endl;

/*     ifstream arquivo = ifstream("palavras.txt");
    int numero_de_palavras;
    arquivo >> numero_de_palavras;
    cout << numero_de_palavras << endl; */

    vector<string> palavras;
    string palavra_lida;

    for(int i = 0; i < numero_de_palavras; i++){
        arquivo >> palavra_lida;
        palavras.push_back(palavra_lida);
        cout << palavras[i] << endl;
    }

    return palavras;
}

int main(){

    imprime_inicio();

    le_arquivo();

    while(nao_enforcou && nao_acertou){

        imprime_tentativa();
        chuta();
        imprime_palavra();
        imprime_erros();
        verifica_se_acertou();
        verifica_se_enforcou();
        cout << endl;


/*         cout << "Tentativa: " << numero_de_tentativas << " Digite seu chute: ";

        cin >> chute;
        numero_de_tentativas += 1;
        
        cout << endl;
        cout << "Seu chute foi: " << chute << endl; */
        
/*         if(verifica_chute(chute)){
            cout << "Seu chute está contido na palavra secreta" << endl;
            // cout << "Os caracteres adivinhados até agora foram: " << caracteres_adivinhados << endl;
        }
        else{
            cout << "Seu chute não está contido na palavra secreta" << endl;
            // cout << "Os caracteres adivinhados até agora foram: " << caracteres_adivinhados << endl;
        }
        cout << endl; */

/*         // -- Verifica se o usuário acertou todos os caracteres da palavra
        nao_acertou = false;
        for(char iterador : caracteres_adivinhados){
            if(iterador == '_'){
                nao_acertou = true;
                break;
            }
        }
        if(nao_acertou == false){
            cout << "Fim de jogo, você acertou a palavra, parabens!" << endl;
        } */
    }

    return 0;
}