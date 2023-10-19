#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "adiciona_palavra.hpp"
#include "chuta.hpp"
#include "erros.hpp"
#include "imprime_palavra.hpp"
#include "le_arquivo.hpp"
#include "letra_existe.hpp"
#include "menu.hpp"
#include "nao_acertou.hpp"
#include "salva_arquivo.hpp"
#include "sorteia_palavra.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char>chutes_errados;

int main (){

    menu();

    palavra_secreta = sorteia_palavra();


    while (nao_acertou(palavra_secreta,chutou) && chutes_errados.size()<5){

        erros(chutes_errados);

        imprime_palavra(palavra_secreta, chutou);

        chuta(&chutou, &chutes_errados);
    }
    cout <<"Fim de Jogo !" <<endl;
    cout <<"A palavra secreta era : " <<palavra_secreta <<endl;
    if (nao_acertou(palavra_secreta, chutou)){
        cout << "Tente novamente !" <<endl;
    }
    else{
        cout << "Voce acertou a palavra secreta !" <<endl;

        cout << "Voce deseja adicionar uma nova palavra ? (S/N)" <<endl;
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }
    return 0;
}