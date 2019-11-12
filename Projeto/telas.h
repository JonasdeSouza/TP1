#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <string.h>
#include <stdlib.h>
#include "curses.h"

class TelaInicializacao{
    public:
        int TelaIncial();
        int TelaOpt();
};

class TelaAutenticar{
    public:
        void TelaAutenticacao(Email&, Senha&) throw(invalid_argument);

};

class TelaUsuario{
    public:
        void TelaCadastro(User&, Account&, Account&) throw(invalid_argument);
        int TelaOptUsuario();
        void TelaVisualizarDados(User&, Account&, Account&);
        void TelaAlterarDados(User&, Account&, Account&) throw(invalid_argument);
        void TelaExcluirDados(Senha&) throw(invalid_argument);
};

class TelaCarona{
    public:
        int TelaOptCarona();
        void TelaCadastrarCarona(Ride&) throw(invalid_argument);
        void TelaDescadastrarCarona(Ride&);
        void TelaListaReservas(Ride&);
};

class TelaReserva{
    public:
        int TelaOptReserva();
        void TelaVisualizarReserva(Email&);
        void TelaCadastrarReserva(Booking&) throw(invalid_argument);
        int TelaDescadastrarReserva();
};

class TelaMensagem{
    public:
        void TelaMsg(string);
};


#endif // TELAS_H_INCLUDED
