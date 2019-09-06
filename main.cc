#include <iostream>
#include "user.h"
using namespace std;

int main(){
    User usuarion;
    Booking reservara;
    Ride caronana;
    Account contaa;

    usuarion.CadastrarUsuario("Jonas", "4002-8922", "jonasdesouza28@gmail.com", "salve123", "123456789" );
    reservara.ReservarCarona(123456, 2, 'D');
    caronana.CadastrarCarona(1, 22, 8317, "brasilia", "DF", "Sao Paulo", "SP", "25/10/2019", "5,000.00" );
    contaa.CadastrarInfoBancarias(280, "123879-0", "7126-1");

    usuarion.Imprime();
    cout << "\n" << "---------" << "\n";
    reservara.Imprime();
    return 0;
}
