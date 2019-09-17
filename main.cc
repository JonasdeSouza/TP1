#include <iostream>
#include "user.h"

using namespace std;

int main(){
    User usuarion;
    Booking reservara;
    Ride caronana;
    Account contaa;

    usuarion.CadastrarUsuario("jonas", "01-02-000000000", "jonasdesouza28@gmail.com", "salve123", "123456789" );
    //reservara.ReservarCarona(123456, 2, 'D');
    //caronana.CadastrarCarona(1, 22, 8317, "Brasilia", "DF", "Sao Paulo", "SP", "25/10/2019", "5,000.00" );
    //contaa.CadastrarInfoBancarias(280, "123879-0", "7126-1");

    usuarion.Imprime();
    //cout << "\n" << "---------" << "\n";
    //reservara.Imprime();
    //cout << "\n" << "---------" << "\n";
    //caronana.Imprime();
    //cout << "\n" << "---------" << "\n";
    //contaa.Imprime();
    //cout << "\n" << "---------" << "\n";
    return 0;
}
