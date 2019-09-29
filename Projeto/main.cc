#include <iostream>
#include "dominios.h"
#include "entidades.h"
#include "testehuehuebr.h"

using namespace std;

int main(){
    //User usuarion;
    //Booking reservara;
    //Ride caronana;
    //Account contaa;

    //usuarion.CadastrarUsuario("Jonas de Souza", "55-61-998137441", "jonasdesouza@gmail.com", "salve", "048.236.901-92");
    //reservara.ReservarCarona(1234, 2, 'D');
    //caronana.CadastrarCarona(2, 21, 8223, "Brasilia", "DF", "Sao Paulo", "SP", "22/02/2019", "5.000,00" );
    //contaa.CadastrarInfoBancarias(170, "1234-4", "123456-6");

    //usuarion.Imprime();
    //cout << "\n" << "---------" << "\n";
    //reservara.Imprime();
    //cout << "\n" << "---------" << "\n";
    //caronana.Imprime();
    //cout << "\n" << "---------" << "\n";
    //contaa.Imprime();
    //cout << "\n" << "---------" << "\n";

    TUTelefone teste;

    switch(teste.Run()){
        case TUNome::SUCESSO: cout << "SUCESSO";
                                break;
        case TUNome::FALHA  : cout << "FALHA" << "\n" << teste.GetExcecao();
                                break;
    }
    

    return 0;
}
