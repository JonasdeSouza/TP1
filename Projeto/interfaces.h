#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;
 //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServAutenticacao;
class IServUsuario;
class IservCarona;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IAprAutenticacao {
public:
    virtual void setIServAutenticacao(IServAutenticacao *) = 0;
    virtual ~IAprAutenticacao(){}
    virtual bool Autenticar() throw(runtime_error) = 0;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServAutenticacao {
public:
    virtual ~IServAutenticacao(){}
    virtual bool Autenticar (Email&,Senha&) throw(runtime_error) = 0;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IAprUsuario {
public:
    virtual void setIServUsuario(IServUsuario *) = 0;
    virtual ~IAprUsuario(){}
    virtual bool Cadastrar() throw(runtime_error) = 0;
    virtual bool Perfil() throw(runtime_error) = 0;
    virtual bool AlterarDados() throw(runtime_error) = 0;
    virtual bool ExcluirConta() throw(runtime_error) = 0;
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServUsuario {
public:
    virtual ~IServUsuario(){}
    virtual bool Cadastrar(Nome&,Email&,Cpf&,Telefone&,Banco&,Agencia&,Conta&,Banco&,Agencia&,Conta&,Senha&) throw(runtime_error) = 0;
    virtual bool ExcluirConta() throw(runtime_error) = 0;
    virtual bool AlterarDados(Nome&,Email&,Cpf&,Telefone&,Banco&,Agencia&,Conta&,Banco&,Agencia&,Conta&,Senha&) throw(runtime_error) = 0;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServCarona {
    public:
    virtual ~IServCarona(){}
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IAprCarona {
    public:
    virtual void setIServCarona(IServCarona *) = 0;
    virtual ~IAprCarona(){}
    virtual bool Carona() throw(runtime_error) = 0;
    virtual bool CadastrarCarona() throw(runtime_error) = 0;
    virtual bool DescadastrarCarona() throw(runtime_error) = 0;
    virtual bool ListarReservas() throw(runtime_error) = 0;
    virtual bool Reserva() throw(runtime_error) = 0;
    virtual bool CadastrarReserva() throw(runtime_error) = 0;
    virtual bool DescadastrarReserva() throw(runtime_error) = 0;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif // INTERFACES_H_INCLUDED
