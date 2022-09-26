#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    cout << "***************************" << endl;
    cout << "*** Jogo da Adivinhação ***" << endl;
    cout << "***************************" << endl;

// --- Seleção do nível de dificuldade
    int numero_de_tentativas;
    char nivel_de_dificuldade;

    cout << "Selecione um nível de Dificuldade:" << endl;
    cout << "(F) - Fácil / (M) - Médio / (D) - Difícil" << endl;

    cin >> nivel_de_dificuldade;

    switch(nivel_de_dificuldade){
        case 'F':
        {
            numero_de_tentativas = 15;
            break;
        }
        case 'M':
        {
            numero_de_tentativas = 10;
            break;
        }
        case 'D':
        {
            numero_de_tentativas = 5;
            break;
        }
        default:
        {
            cout << "O nível de dificuldade selecionado é inválido" << endl;
            return -1;
        }
    }

// --- Geração do número aleatório entre 0 e 100
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
   
// ---   cout << "o numero secreto é: " << NUMERO_SECRETO << endl;
    
// --- Jogo e sistema de pontuação
    int numero_chutado;
    double pontuacao = 1000;

    for(int i=1; i<=numero_de_tentativas; i++){
        cout << "Tentativa: " << i << endl;
        cout << "Digite seu chute: ";
        cin >> numero_chutado;
        if(numero_chutado == NUMERO_SECRETO){
            cout << endl;
            cout << "Parabéns, você zerou o jogo" << endl;
            break;
        }
        else{
            pontuacao = pontuacao - abs(numero_chutado - NUMERO_SECRETO)/2.0;
            if(numero_chutado < NUMERO_SECRETO)
            {
                cout << "O número chutado é menor que o número secreto" << endl;
                cout << endl;
            }
            else{
                cout << "O número chutado é maior que o número secreto" << endl;
                cout << endl;
            }
        }
        
    }

// --- Fim de jogo
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuação foi de: " << pontuacao << " pontos." << endl;
    cout << "Fim de jogo." << endl;

    return 0;
}