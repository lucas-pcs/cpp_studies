#include "verifica_chute.hpp"
#include <string>

extern std::string palavra_secreta;

// --- Retorna true se o chute está contido na palavra e false caso contrário.
bool verifica_chute(char chute){
    for(char letra : palavra_secreta){
        if(letra == chute){
            return true;
        }
    }
    return false;
}