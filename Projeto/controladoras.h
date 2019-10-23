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
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrAprCarona:public IAprCarona {
    private:
        IServCarona *refServCarona;
    public:
        void setIServCarona(IServCarona *refServCarona){
            this->refServCarona = refServCarona;
        }
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrServAutenticacao:public IServCarona {
    private:
        const string TRIGGER_FALHA = "joao@gmail.com";
        const string TRIGGER_ERRO_SISTEMA = "jonas@gmail.com";
    public:
        bool Autenticar(const Email&, const Senha&) throw(runtime_error);

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrServUsuario:public IServCarona {
    private:

    public:

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CntrServCarona:public IServCarona {
    private:

    public:

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif // CONTROLADORAS_H_INCLUDED