#ifndef PERSISTENCIA_H_INCLUDED
#define PERSISTENCIA_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <list>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------
class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};
//-------------------------------------------------------------------------------------------------------------------------------
class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar() throw (runtime_error);
        void desconectar() throw (runtime_error);
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
             nomeBancoDados = "DataBase.db";
        }
        void executar() throw (runtime_error);
};
//-------------------------------------------------------------------------------------------------------------------------------
class CmdAutenticacao:public ComandoSQL {
public:
        void CmdAutenticar(Email);
        string getResultado() throw (runtime_error);
};
//-------------------------------------------------------------------------------------------------------------------------------
class CmdCadastroUsuario:public ComandoSQL{
    public:
        void CmdCadastroUser(User user);
        void CmdCadastroAccount(User user, Account acc, Account acc2);
};
//-------------------------------------------------------------------------------------------------------------------------------
class CmdAtualizacaoDados:public ComandoSQL{
    public:
        void CmdAtualizarUser(Email usuario, User user);
        void CmdAtualizarAccount(Email usuario, Account acc1);
};
//-------------------------------------------------------------------------------------------------------------------------------
class CmdExclusaoConta:public ComandoSQL{
    public:
        void CmdConfirmSenha(Email email);
        string getResultado() throw (runtime_error);
        void CmdExcluirConta(Email email);
};
//-------------------------------------------------------------------------------------------------------------------------------
class CmdCadastroCarona:public ComandoSQL{
    public:
        void CmdCadastrarCarona(Email usuario, Ride ride);
};
//-------------------------------------------------------------------------------------------------------------------------------
class CmdDescadastroCarona:public ComandoSQL{
    public:
        void CmdDescadastrarCarona(Ride ride);
};
//-------------------------------------------------------------------------------------------------------------------------------
class CmdVisualizarReservas:public ComandoSQL{
    public:
        void CmdGetNome(CodigoCarona codigocarona);
        string GetResultNome() throw(runtime_error);
        void CmdGetEmail(CodigoCarona codigocarona);
        string GetResultEmail() throw(runtime_error);
        void CmdGetCodreserv(CodigoCarona codigocarona);
        string GetResultCodreserv() throw(runtime_error);
        void CmdGetAssento(CodigoCarona codigocarona);
        string GetResultAssento() throw(runtime_error);
        void CmdGetBagagem(CodigoCarona codigocarona);
        string GetResultBagagem() throw(runtime_error);
};
class CmdVisualizarCodCarona:public ComandoSQL{
public:
    void CmdGetcodcarona(Email usuario);
        string GetResultcodcarona() throw(runtime_error);
};
//-------------------------------------------------------------------------------------------------------------------------------
class CmdCadastroReserva:public ComandoSQL{
    public:
        void CmdCadastrarReserva(Email usuario,Booking reserva,Ride ride);
};
//-------------------------------------------------------------------------------------------------------------------------------
class CmdDescadastroReserva:public ComandoSQL{
    public:
        void CmdDescadastrarReserva(Email usuario);
};
//-------------------------------------------------------------------------------------------------------------------------------
class CmdVisualizarDados:public ComandoSQL{
    public:
        void CmdGetCpf(Email email);
        string GetResultCpf() throw(runtime_error);
        void CmdGetNome(Email email);
        string GetResultNome() throw(runtime_error);
        void CmdGetTelefone(Email email);
        string GetResultTelefone() throw(runtime_error);
        void CmdGetConta1(Email email);
        string GetResultConta1() throw(runtime_error);
        void CmdGetBanco1(Email email);
        int GetResultBanco1() throw(runtime_error);
        void CmdGetAgencia1(Email email);
        string GetResultAgencia1() throw(runtime_error);
        void CmdGetConta2(Email email);
        string GetResultConta2() throw(runtime_error);
        void CmdGetBanco2(Email email);
        int GetResultBanco2() throw(runtime_error);
        void CmdGetAgencia2(Email email);
        string GetResultAgencia2() throw(runtime_error);
};

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}

#endif // PERSISTENCIA_H_INCLUDED
