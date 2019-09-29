#include <iostream>
#include "dominios.h"
#include "entidades.h"

using namespace std;

int main(){
    User usuarion;
    Booking reservara;
    Ride caronana;
    Account contaa;

<<<<<<< Updated upstream
    usuarion.CadastrarUsuario("Jonas de Souzaaaaaaaaaa", "55-61-9981374541", "jonasdes..ouza@gmail.com", "salvv", "838.536.900-66");
    reservara.ReservarCarona(123456, 5, 'M');
    caronana.CadastrarCarona(6, 50, 822317, "Brasiliaaaaaaaaa", "AA", "Sao Pauloaaaaaaaaaaa", "BB", "29/02/2019", "5.100,00" );
    contaa.CadastrarInfoBancarias(2800, "1234-0", "7126-1");
=======
    usuarion.CadastrarUsuario("Jonas de Souza", "55-61-998137441", "jonasdesouza@gmail.com", "salve", "048.236.901-92");
    reservara.ReservarCarona(1234, 2, 'D');
    caronana.CadastrarCarona(2, 21, 8223, "Brasilia", "DF", "Sao Paulo", "SP", "22/02/2019", "5.000,00" );
    contaa.CadastrarInfoBancarias(170, "1234-4", "123456-6");
>>>>>>> Stashed changes

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
