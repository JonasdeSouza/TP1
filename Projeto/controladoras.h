#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrAprInicializacao {
    private:
        IAprAutenticacao *refAprAutenticacao;
        IAprUsuario *refAprUsuario;
        IAprCarona *refAprCarona;
    public:
        void setIAprAutenticacao(IAprAutenticacao *refAprAutenticacao){
            this->refAprAutenticacao = refAprAutenticacao;
        }
        void setIAprUsuario(IAprUsuario *refAprUsuario){
            this->refAprUsuario = refAprUsuario;
        }
        void setIAprCarona(IAprCarona *refAprCarona){
            this->refAprCarona = refAprCarona;
        }
        int Start() throw(runtime_error);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrAprAutenticacao:public IAprAutenticacao {
    private:
        IServAutenticacao *refServAutenticacao;
    public:
        void setIServAutenticacao(IServAutenticacao *refServAutenticacao){
            this->refServAutenticacao = refServAutenticacao;
        }
        bool Autenticar(Email&) throw(runtime_error);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrAprUsuario:public IAprUsuario {
    private:
        IServUsuario *refServUsuario;
    public:
        void setIServUsuario(IServUsuario *refServUsuario){
            this->refServUsuario = refServUsuario;
        }
        bool Cadastrar() throw(runtime_error);
        int Perfil() throw(runtime_error);
        bool VisualizarDados() throw(runtime_error);
        bool AlterarDados(Email&) throw(runtime_error);
        bool ExcluirConta(Email&) throw(runtime_error);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrAprCarona:public IAprCarona {
    private:
        IServCarona *refServCarona;
    public:
        void setIServCarona(IServCarona *refServCarona){
            this->refServCarona = refServCarona;
        }
        int Carona() throw(runtime_error);
        int Reserva() throw(runtime_error);
        bool CadastrarCarona(Email&) throw(runtime_error);
        bool DescadastrarCarona() throw(runtime_error);
        bool ListarReservas() throw(runtime_error);
        bool CadastrarReserva(Email&) throw(runtime_error);
        bool DescadastrarReserva(Email&) throw(runtime_error);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrServAutenticacao:public IServAutenticacao {
    public:
        bool Autenticar(Email&,Email&,Senha&) throw(runtime_error);

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrServUsuario:public IServUsuario {
    public:
        bool Cadastrar(User& ,Account& ,Account&) throw(runtime_error);
        bool Perfil() throw(runtime_error);
        bool VisualizarDados(User&,Account&,Account&) throw(runtime_error);
        bool AlterarDados(Email&, User&, Account&, Account&) throw(runtime_error);
        bool ExcluirConta(Email&,Senha&) throw(runtime_error);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrServCarona:public IServCarona {
    public:
        bool CadastrarCarona(Email&,Ride&) throw(runtime_error);
        bool DescadastrarCarona(Ride ride) throw(runtime_error);
        bool ListarReservas() throw(runtime_error);
        bool CadastrarReserva(Email&,Booking&) throw(runtime_error);
        bool DescadastrarReserva(Email) throw(runtime_error);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif // CONTROLADORAS_H_INCLUDED
