#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <string.h>
#include <stdlib.h>
#include <curses.h>

class TelaInicializacao{
    public:
        int TelaIncial();
        int TelaOpt();
};

class TelaAutenticar{
    public:
        bool TelaAutenticacao(Email&, Senha&) throw(invalid_argument);

};

class TelaUsuario{
    public:
        int TelaCadastro(User&, Account&, Account&) throw(invalid_argument);
        int TelaOptUsuario();
        void TelaVisualizarDados(User&, Account&, Account&);
        int TelaAlterarDados(User&, Account&, Account&) throw(invalid_argument);
        int TelaExcluirDados(Senha&) throw(invalid_argument);
};

class TelaCarona{
    public:
        int TelaOptCarona();
        int TelaCadastrarCarona(Ride&) throw(invalid_argument);
        int TelaDescadastrarCarona(Ride&);
        void TelaListaReservas(User&,Ride&,Booking&,Email&);
        int TelaCodigoCarona(Ride&);
};

class TelaReserva{
    public:
        int TelaOptReserva();
        int TelaCadastrarReserva(Booking&) throw(invalid_argument);
        int TelaDescadastrarReserva();
};

class TelaMensagem{
    public:
        void TelaMsg(string);
};


#endif // TELAS_H_INCLUDED
