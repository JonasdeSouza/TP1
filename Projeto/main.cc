#include <iostream>
#include "dominios.h"
#include "entidades.h"

using namespace std;

int main(){
    User usuarion;
    Booking reservara;
    Ride caronana;
    Account contaa;

    usuarion.CadastrarUsuario("Jonas de Souzaaaaaaaaaa", "55-61-9981374541", "jonasdes..ouza@gmail.com", "salvv", "838.536.900-66");
    reservara.ReservarCarona(123456, 5, 'M');
    caronana.CadastrarCarona(6, 50, 822317, "Brasiliaaaaaaaaa", "AA", "Sao Pauloaaaaaaaaaaa", "BB", "29/02/2019", "5.100,00" );
    contaa.CadastrarInfoBancarias(2800, "1234-0", "7126-1");

    usuarion.Imprime();
    cout << "\n" << "---------" << "\n";
    reservara.Imprime();
    cout << "\n" << "---------" << "\n";
    caronana.Imprime();
    cout << "\n" << "---------" << "\n";
    contaa.Imprime();
    cout << "\n" << "---------" << "\n";
    return 0;
}
