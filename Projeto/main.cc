#include <iostream>
#include "user.h"

using namespace std;

int main(){
    User usuarion;
    Booking reservara;
    Ride caronana;
    Account contaa;

    //usuarion.CadastrarUsuario("Jonas de Souzaaaaaaaaaa", "55-61-9981374541", "jonasdes..ouza@gmail.com", "salvv", "838.536.900-66");
    //reservara.ReservarCarona(123456, 5, 'D');
    caronana.CadastrarCarona(6, 50, 822317, "Brasiliaaaaaaaaa", "AA", "Sao Pauloaaaaaaaaaaa", "BB", "29/02/2019", "5.000,00" );
    //contaa.CadastrarInfoBancarias(280, "123879-0", "7126-1");

    //usuarion.Imprime();
    //cout << "\n" << "---------" << "\n";
    //reservara.Imprime();
    //cout << "\n" << "---------" << "\n";
    caronana.Imprime();
    //cout << "\n" << "---------" << "\n";
    //contaa.Imprime();
    //cout << "\n" << "---------" << "\n";
    return 0;
}
