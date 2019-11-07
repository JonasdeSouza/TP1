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
        void Start() throw(runtime_error);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrAprAutenticacao:public IAprAutenticacao {
    private:
        IServAutenticacao *refServAutenticacao;
    public:
        void setIServAutenticacao(IServAutenticacao *refServAutenticacao){
            this->refServAutenticacao = refServAutenticacao;
        }
        bool Autenticar() throw(runtime_error);
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
        bool Perfil() throw(runtime_error);
        bool AlterarDados() throw(runtime_error);
        bool ExcluirConta() throw(runtime_error);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrAprCarona:public IAprCarona {
    private:
        IServCarona *refServCarona;
    public:
        void setIServCarona(IServCarona *refServCarona){
            this->refServCarona = refServCarona;
        }
        bool Carona() throw(runtime_error);
        bool Reserva() throw(runtime_error);
        bool CadastrarCarona() throw(runtime_error);
        bool DescadastrarCarona() throw(runtime_error);
        bool ListarReservas() throw(runtime_error);
        bool CadastrarReserva() throw(runtime_error);
        bool DescadastrarReserva() throw(runtime_error);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrServAutenticacao:public IServAutenticacao {
    private:
        const string TRIGGER_FALHA = "joao@gmail.com";
        const string TRIGGER_ERRO_SISTEMA = "jonas@gmail.com";
    public:
        bool Autenticar(Email&,Senha&) throw(runtime_error);

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrServUsuario:public IServUsuario {
    private:

    public:
        bool Cadastrar(Nome&,Email&,Cpf&,Telefone&,Banco&,Agencia&,Conta&,Banco&,Agencia&,Conta&,Senha&) throw(runtime_error);
        bool ExcluirConta() throw(runtime_error);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrServCarona:public IServCarona {
    private:

    public:

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif // CONTROLADORAS_H_INCLUDED
