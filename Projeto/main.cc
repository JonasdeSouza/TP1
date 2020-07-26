/**
    c++11
    Propurse: Sistema de caronas para a matéria de
    Tecnicas de Programacao 1, Professor Fernando Alburquerque

    @author Jonas de Souza Fagundes e Joao Pedro Magalhaes Maciel
    @version 1.0 01/10/2019
*/

#include <iostream>
#include "dominios.h"
#include "entidades.h"
#include "controladoras.h"
#include "interfaces.h"
#include <curses.h>

using namespace std;

int main(){

   CntrAprInicializacao A;
    CntrAprAutenticacao *B;
    CntrAprCarona *C;
    CntrAprUsuario *D;
    CntrServAutenticacao *E;
    CntrServCarona *F;
    CntrServUsuario *G;
    B = new CntrAprAutenticacao();
    C = new CntrAprCarona();
    D = new CntrAprUsuario();
    E = new CntrServAutenticacao();
    F = new CntrServCarona();
    G = new CntrServUsuario();
    A.setIAprAutenticacao(B);
    A.setIAprCarona(C);
    A.setIAprUsuario(D);
    B->setIServAutenticacao(E);
    C->setIServCarona(F);
    D->setIServUsuario(G);
    A.Start();
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;
    delete G;

    return 0;
}


