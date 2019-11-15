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
    virtual bool Autenticar(Email&) throw(runtime_error) = 0;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServAutenticacao {
public:
    virtual ~IServAutenticacao(){}
    virtual bool Autenticar (Email&,Email&,Senha&) throw(runtime_error) = 0;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IAprUsuario {
public:
    virtual void setIServUsuario(IServUsuario *) = 0;
    virtual ~IAprUsuario(){}
    virtual bool Cadastrar() throw(runtime_error) = 0;
    virtual bool Perfil(Email&, User&, Account&, Account&, Senha&) throw(runtime_error) = 0;
    virtual bool VisualizarDados(User&, Account&, Account&) throw(runtime_error) = 0;
    virtual bool AlterarDados(Email&) throw(runtime_error) = 0;
    virtual bool ExcluirConta(Email&) throw(runtime_error) = 0;
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServUsuario {
public:
    virtual ~IServUsuario(){}
    virtual bool Cadastrar(User& ,Account&, Account&) throw(runtime_error) = 0;
    virtual bool ExcluirConta(Email&,Senha&) throw(runtime_error) = 0;
    virtual bool VisualizarDados(User&, Account&, Account&) throw(runtime_error) = 0;
    virtual bool AlterarDados(Email&,User& ,Account& ,Account&) throw(runtime_error) = 0;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServCarona {
    public:
    virtual ~IServCarona(){}
    virtual bool CadastrarCarona(Email&,Ride&) throw(runtime_error) = 0;
    virtual bool DescadastrarCarona(Ride) throw(runtime_error) = 0;
    virtual bool ListarReservas(User&, Ride&, Booking&,Email&) throw(runtime_error) = 0;
    virtual bool CadastrarReserva(Email&,Booking&) throw(runtime_error) = 0;
    virtual bool DescadastrarReserva(Email) throw(runtime_error) = 0;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IAprCarona {
    public:
    virtual void setIServCarona(IServCarona *) = 0;
    virtual ~IAprCarona(){}
    virtual bool Carona(Email&) throw(runtime_error) = 0;
    virtual bool CadastrarCarona(Email&) throw(runtime_error) = 0;
    virtual bool DescadastrarCarona() throw(runtime_error) = 0;
    virtual bool ListarReservas(User&,Ride&,Booking&,Email&) throw(runtime_error) = 0;
    virtual bool Reserva(Email&) throw(runtime_error) = 0;
    virtual bool CadastrarReserva(Email&) throw(runtime_error) = 0;
    virtual bool DescadastrarReserva(Email&) throw(runtime_error) = 0;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif // INTERFACES_H_INCLUDED
