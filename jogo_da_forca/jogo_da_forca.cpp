#include <iostream>
#include <string>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
string caracteres_adivinhados(PALAVRA_SECRETA.size(),'_');



bool verifica_chute(char chute){
    bool verifica = false;
    int i = 0;

    // --- Verifica também no caso de palavras repetidas
    while(i < PALAVRA_SECRETA.size()){
        if(chute == PALAVRA_SECRETA[i]){
            caracteres_adivinhados[i] = chute;
            verifica = true;
        }
        i = i + 1;
    }

    return verifica;

    /* loop usando novo for do c++11, não printa na tela o estado atual da palavra a ser adivinhada e nem contempla o caso de palavras repetidas
    for(char interador : PALAVRA_SECRETA){
        if(chute == interador){
            return true;
        }
    }
    return false;
    */
}

int main(){

    cout << caracteres_adivinhados << endl;

    cout << "**************************************" << endl;
    cout << "***** Bem vindo ao jogo da forca *****" << endl;
    cout << "**************************************" << endl;

    bool nao_enforcou = true;
    bool nao_acertou = true;
    char chute;
    const int NUMERO_DE_TENTATIVAS_MAXIMO = 10;
    int numero_de_tentativas=1;

    while(nao_enforcou && nao_acertou){
        cout << "Tentativa: " << numero_de_tentativas << " Digite seu chute: ";

        cin >> chute;
        numero_de_tentativas += 1;
        
        cout << endl;
        cout << "Seu chute foi: " << chute << endl;
        
        if(verifica_chute(chute)){
            cout << "Seu chute está contido na palavra secreta" << endl;
            cout << "Os caracteres adivinhados até agora foram: " << caracteres_adivinhados << endl;
        }
        else{
            cout << "Seu chute não está contido na palavra secreta" << endl;
            cout << "Os caracteres adivinhados até agora foram: " << caracteres_adivinhados << endl;
        }
        cout << endl;

        // -- Verifica se o usuário acertou todos os caracteres da palavra
        nao_acertou = false;
        for(char iterador : caracteres_adivinhados){
            if(iterador == '_'){
                nao_acertou = true;
                break;
            }
        }
        if(nao_acertou == false){
            cout << "Fim de jogo, você acertou a palavra, parabens!" << endl;
        }

        // -- Verifica se o usuário enforcou
        if(numero_de_tentativas == NUMERO_DE_TENTATIVAS_MAXIMO + 1){
            nao_enforcou = false;
            cout << "Fim de jogo, você enforcou!" << endl;
        }
    }

    return 0;
}