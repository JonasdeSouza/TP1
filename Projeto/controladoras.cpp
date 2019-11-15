#include "controladoras.h"
#include "dominios.h"
#include "entidades.h"
#include "curses.h"
#include <cstring>
#include "telas.h"
#include "persistencia.h"
//--------------------------------------------------------------------------------------------------------------------------------------------
void CntrAprInicializacao::Start() throw(runtime_error){
    TelaInicializacao TLInicializacao;
    bool resultado,resultado2;
    Email email;
    User usuario;
    Account acc1,acc2;
    Senha senha;
    TelaMensagem TLMensagem;
    while(true){
        switch(TLInicializacao.TelaIncial()){
            case 1:
                resultado = refAprAutenticacao->Autenticar(email);
;                while(resultado==1){
                    do{
                        switch (TLInicializacao.TelaOpt()){
                            case 1:
                                resultado2 = refAprCarona->Carona(email);
                                break;
                            case 2:
                                resultado2 = refAprCarona->Reserva(email);
                                break;
                            case 3:
                                resultado2 = refAprUsuario->Perfil(email,usuario,acc1,acc2,senha);
                                break;
                        }
                    }while(resultado2==0);
                }
                break;
            case 2:
                resultado = refAprUsuario->Cadastrar();
                if(resultado==1){
                        TLMensagem.TelaMsg("Conta cadastrada com sucesso!");
                }
                else{
                TLMensagem.TelaMsg("Falha no cadastro!");
                }
                break;
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprAutenticacao::Autenticar(Email& usuario) throw(runtime_error){
    Email email;
    Senha senha;
    bool resultado,resultTela;
    TelaMensagem TLMensagem;

   while(true) {

        try {
          TelaAutenticar TLAutenticacao;
            resultTela = TLAutenticacao.TelaAutenticacao(email, senha);
            break;
        }
        catch (const invalid_argument &exp) {
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    if(resultTela==0){
        return 0;
    }
    else{
        try{
            resultado = refServAutenticacao->Autenticar(usuario, email, senha);
            if(resultado==1){
                TLMensagem.TelaMsg("Autenticado com sucesso!");
            }
            else{
                TLMensagem.TelaMsg("Falha de autenticacao!");
            }
        }
        catch(runtime_error){
            TLMensagem.TelaMsg("Erro no banco de dados;");
        }
        return resultado;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::Cadastrar() throw(runtime_error){
    User user;
    Account acc1,acc2;
    bool resultado,resulTela;
    TelaMensagem TLMensagem;

    while(true) {

        try {
            TelaUsuario TLCadastro;
            resulTela = TLCadastro.TelaCadastro(user, acc1, acc2);
            break;
        }
        catch (const invalid_argument &exp) {
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    if(resulTela==0){
        return 0;
    }
    else{
    try{
        resultado = refServUsuario->Cadastrar(user, acc1, acc2);
    }
    catch(runtime_error &exp){
        string str = exp.what();
        TLMensagem.TelaMsg(str);
    }
    return resultado;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::Perfil(Email& email,User& usuario,Account& acc1, Account& acc2, Senha& senha) throw(runtime_error){
    TelaUsuario TLPerfil;
    bool resultado;
    TelaMensagem TLMensagem;

    switch (TLPerfil.TelaOptUsuario()){
        case 0:
            return 0;
        case 1:
            TLPerfil.TelaVisualizarDados(usuario, acc1, acc2);
            usuario.SetEmail(email);
            resultado = refServUsuario->VisualizarDados(usuario,acc1,acc2);
            if(resultado==0){
                TLMensagem.TelaMsg("Erro na visualizacao de dados!");
            }
            return resultado;
        case 2:
            TLPerfil.TelaAlterarDados(usuario, acc1, acc2);
            resultado = refServUsuario->AlterarDados(email, usuario, acc1, acc2);
            if(resultado==1){
                TLMensagem.TelaMsg("Dados alterados com sucesso!");
            }
            else{
                TLMensagem.TelaMsg("Erro na alteracao de dados!");
            }
            return resultado;
        case 3:
            TLPerfil.TelaExcluirDados(senha);
            resultado = refServUsuario->ExcluirConta(email, senha);
            if(resultado==1){
                TLMensagem.TelaMsg("Conta excluida com sucesso!");
                CntrAprInicializacao Goback;
                Goback.Start();
            }
            else{
                TLMensagem.TelaMsg("Erro na exclusao de conta!");
            }
            return resultado;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::AlterarDados(Email& usuario) throw(runtime_error){
    User user;
    Account acc1,acc2;
    bool resultado,resultela;

    while(true) {

        try {
            TelaUsuario TLDados;
            resultela = TLDados.TelaAlterarDados(user, acc1, acc2);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    if(resultela==0){
        return 0;
    }
    else{
    try{
        resultado = refServUsuario->AlterarDados(usuario, user, acc1, acc2);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::ExcluirConta(Email& usuario) throw(runtime_error){
    Senha senha;
    bool resultado,resultela;

    while(true) {

        try {
            TelaUsuario TLExcluirConta;
            resultela = TLExcluirConta.TelaExcluirDados(senha);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    if(resultela==0){
        return 0;
    }
    else{
    try{
        resultado = refServUsuario->ExcluirConta(usuario,senha);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::VisualizarDados(User& usuario, Account& acc, Account& acc2) throw(runtime_error){

    bool resultado;

    try{
        resultado = refServUsuario->VisualizarDados(usuario,acc,acc2);
        TelaUsuario TLVisualizarDados;
        TLVisualizarDados.TelaVisualizarDados(usuario,acc,acc2);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
//bool CntrAprCarona::Carona(Email& usuario) throw(runtime_error){
  //  TelaCarona TLCarona;
   // User user;
   // Ride ride;
   // Booking reserva;
    //bool resultado;
    //TelaMensagem TLMensagem;

    //switch(TLCarona.TelaOptCarona()){
     //   case 0:
      //      return 0;
       // case 1:
        //    TLCarona.TelaCadastrarCarona(ride);
         //   resultado = refServCarona->CadastrarCarona(usuario, ride);
          //  if(resultado==1){
           //     TLMensagem.TelaMsg("Carona cadastrada com sucesso!");
           // }
            //else{
             //   TLMensagem.TelaMsg("Erro no cadastramento da carona!");
           // }
            //return resultado;
       // case 2:
        //    TLCarona.TelaDescadastrarCarona(ride);
         //   resultado = refServCarona->DescadastrarCarona(ride);
         //   if(resultado==1){
          //      TLMensagem.TelaMsg("Carona descadastrada com sucesso!");
           // }
          //  else{
           //     TLMensagem.TelaMsg("Erro no descadastramento da carona!");
           // }
            //return resultado;
        //case 3:
         //   resultado = refServCarona->ListarReservas(user,ride,reserva,usuario);
         //   if(resultado==0){
          //      TLMensagem.TelaMsg("Erro na visualiza��o de reservas da carona!");
           // }
     //      / return resultado;
   // }
//}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprCarona::Reserva(Email& usuario) throw(runtime_error){
    TelaReserva TLReserva;
    bool resultado;
    TelaMensagem TLMensagem;
    Booking booking;
    Ride ride;

    switch(TLReserva.TelaOptReserva()){
        case 0:
            return 0;
        case 1:
            TLReserva.TelaCadastrarReserva(booking);
            resultado = refServCarona->CadastrarReserva(usuario,booking);
            if(resultado==1){
                TLMensagem.TelaMsg("Reserva Cadastrada com sucesso!");
            }
            else{
                TLMensagem.TelaMsg("Erro no cadastro da reserva!");
            }
            return resultado;
        case 2:
            TLReserva.TelaDescadastrarReserva();
            resultado = refServCarona->DescadastrarReserva(usuario);
            if(resultado==1){
                TLMensagem.TelaMsg("Reserva descadastrada com sucesso!");
            }
            else{
                TLMensagem.TelaMsg("Erro no descadastramento de reserva!");
            }
            return resultado;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprCarona::CadastrarCarona(Email& usuario) throw(runtime_error){
    Ride carona;
    bool resultado,resultela;

    while(true) {

        try {
            TelaCarona TLCadastroCarona;
            resultela = TLCadastroCarona.TelaCadastrarCarona(carona);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    if(resultela==0){
        return 0;
    }
    else{
    try{
        resultado = refServCarona->CadastrarCarona(usuario,carona);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprCarona::DescadastrarCarona() throw(runtime_error){
    Ride carona;
    bool resultado,resultela;

    while(true) {

        try {
            TelaCarona TLDescadastroCarona;
            resultela = TLDescadastroCarona.TelaDescadastrarCarona(carona);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    if(resultela==0){
        return 0;
    }
    else{
    try{
        resultado = refServCarona->DescadastrarCarona(carona);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprCarona::CadastrarReserva(Email& usuario) throw(runtime_error){
    Booking reserva;
    bool resultado,resultela;

    while(true) {

        try {
            TelaReserva TLCadastroReserva;
            resultela = TLCadastroReserva.TelaCadastrarReserva(reserva);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    if(resultela==0){
        return 0;
    }
    else{
    try{
        resultado = refServCarona->CadastrarReserva(usuario,reserva);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprCarona::DescadastrarReserva(Email& email) throw(runtime_error){
    bool resultado,resultela;

    while(true) {

        try {
            TelaReserva TLDescadastroReserva;
            resultela = TLDescadastroReserva.TelaDescadastrarReserva();
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    if(resultela==0){
        return 0;
    }
    else{
    try{
        resultado = refServCarona->DescadastrarReserva(email);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
    }
}
bool CntrServAutenticacao::Autenticar(Email& usuario,Email& email,Senha& senha) throw(runtime_error){
    string SenhaDB;
    CmdAutenticacao Cmd;

    Cmd.CmdAutenticar(email);
    Cmd.executar();
    SenhaDB = Cmd.getResultado();
    if(SenhaDB==senha.GetSenha()){
        usuario.SetEmail(email.GetEmail());
        return 1;
    }
        else{
            return 0;
        }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServUsuario::Cadastrar(User& user, Account& acc1, Account& acc2) throw(runtime_error)
{
    CmdCadastroUsuario Cmd;
    Cmd.CmdCadastroUser(user);
    Cmd.executar();
    Cmd.CmdCadastroAccount(user,acc1,acc2);
    Cmd.executar();
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServUsuario::VisualizarDados(User& user, Account& acc, Account& acc2) throw(runtime_error)
{
    Cpf CpfDB;
    Nome NomeDB;
    Telefone TelefoneDB;
    Conta Conta1DB,Conta2DB;
    Banco Banco1DB,Banco2DB;
    Agencia Agencia1DB,Agencia2DB;
    CmdVisualizarDados Cmd;

    Cmd.CmdGetCpf(user.GetEmail());
    Cmd.executar();
    CpfDB.SetCpf(Cmd.GetResultCpf());
    Cmd.CmdGetNome(user.GetEmail());
    Cmd.executar();
    NomeDB.SetNome(Cmd.GetResultNome());
    Cmd.CmdGetTelefone(user.GetEmail());
    Cmd.executar();
    TelefoneDB.SetTelefone(Cmd.GetResultTelefone());
    Cmd.CmdGetConta1(user.GetEmail());
    Cmd.executar();
    Conta1DB.SetConta(Cmd.GetResultConta1());
    Cmd.CmdGetBanco1(user.GetEmail());
    Cmd.executar();
    Banco1DB.SetCodigoBanco(Cmd.GetResultBanco1());
    Cmd.CmdGetAgencia1(user.GetEmail());
    Cmd.executar();
    Agencia1DB.SetAgencia(Cmd.GetResultAgencia1());
    Cmd.CmdGetConta2(user.GetEmail());
    Cmd.executar();
    Conta2DB.SetConta(Cmd.GetResultConta2());
    Cmd.CmdGetBanco2(user.GetEmail());
    Cmd.executar();
    Banco2DB.SetCodigoBanco(Cmd.GetResultBanco2());
    Cmd.CmdGetAgencia2(user.GetEmail());
    Cmd.executar();
    Agencia2DB.SetAgencia(Cmd.GetResultAgencia2());
    user.SetCpf(CpfDB);
    user.SetNome(NomeDB);
    user.SetTelefone(TelefoneDB);
    acc.SetConta(Conta1DB);
    acc.SetBanco(Banco1DB);
    acc.SetAgencia(Agencia1DB);
    acc2.SetConta(Conta2DB);
    acc2.SetBanco(Banco2DB);
    acc2.SetAgencia(Agencia2DB);

    return 1;
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServUsuario::AlterarDados(Email& usuario, User& user, Account& acc1, Account& acc2) throw(runtime_error)
{
    CmdAtualizacaoDados Cmd;

    Cmd.CmdAtualizarUser(usuario,user);
    Cmd.executar();
    Cmd.CmdAtualizarAccount(usuario,acc1);
    Cmd.executar();
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServUsuario::ExcluirConta(Email& usuario, Senha& senha) throw(runtime_error)
{
    string SenhaDB;
    CmdExclusaoConta Cmd;

    Cmd.CmdConfirmSenha(usuario);
    Cmd.executar();
    SenhaDB = Cmd.getResultado();
    if(SenhaDB==senha.GetSenha())
    {
        Cmd.CmdExcluirConta(usuario);
        Cmd.executar();
        return 1;
    }
    else
    {
        return 0;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServCarona::CadastrarCarona(Email& usuario, Ride& carona) throw(runtime_error)
{
    CmdCadastroCarona Cmd;

    Cmd.CmdCadastrarCarona(usuario,carona);
    Cmd.executar();
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServCarona::DescadastrarCarona(Ride ride) throw(runtime_error)
{
    CmdDescadastroCarona Cmd;

    Cmd.CmdDescadastrarCarona(ride);
    Cmd.executar();
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServCarona::CadastrarReserva(Email& usuario,Booking& reservan) throw(runtime_error)
{
    Ride ride;
    CodigoCarona codigocarona;

    CmdCadastroReserva Cmd;
    Cmd.CmdCadastrarReserva(usuario,reservan,ride);
    Cmd.executar();
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServCarona::ListarReservas(User& usuario, Ride& Carona, Booking& Reserva, Email& aux) throw(runtime_error)
{
    Nome NomeDB;
    CodigoCarona codigocarona;
    CodigoReserva codigoreservaDB;
    Assento assentoDB;
    Bagagem bagagemDB;
    CmdVisualizarReservas Cmd;
    CmdVisualizarCodCarona Cmd2;

    Cmd2.CmdGetcodcarona(usuario.GetEmail());
    Cmd2.executar();
    codigocarona.SetCodigoCarona(atoi(Cmd2.GetResultcodcarona().c_str()));
    Carona.SetCodigoCarona(codigocarona);
    Cmd.CmdGetNome(Carona.GetCodigoCarona());
    Cmd.executar();
    NomeDB.SetNome(Cmd.GetResultNome());
    Cmd.CmdGetEmail(Carona.GetCodigoCarona());
    Cmd.executar();
    aux.SetEmail(Cmd.GetResultEmail());
    Cmd.CmdGetCodreserv(Carona.GetCodigoCarona());
    Cmd.executar();
    codigoreservaDB.SetCodigoReserva(atoi(Cmd.GetResultCodreserv().c_str()));
    Cmd.CmdGetAssento(Carona.GetCodigoCarona());
    assentoDB.SetAssento(atoi(Cmd.GetResultAssento().c_str()));
    Cmd.CmdGetBagagem(Carona.GetCodigoCarona());
    Cmd.executar();
    bagagemDB.SetBagagem(atoi(Cmd.GetResultBagagem().c_str()));
    return 1;

}
bool CntrAprCarona::ListarReservas(User& user,Ride& ride,Booking& reserva,Email& aux) throw(runtime_error){
    bool resultado;
    TelaCarona TLListarReservas;
    TLListarReservas.TelaListaReservas(user,ride,reserva,aux);
    return resultado;
}
bool CntrAprCarona::Carona(Email& usuario) throw(runtime_error){
    TelaCarona TLCarona;
    CntrAprCarona A;
    User user;
    Ride ride;
    Booking reserva;
    bool resultado;
    TelaMensagem TLMensagem;

    switch(TLCarona.TelaOptCarona()){
        case 0:
            return 0;
        case 1:
            TLCarona.TelaCadastrarCarona(ride);
            resultado = refServCarona->CadastrarCarona(usuario, ride);
            if(resultado==1){
                TLMensagem.TelaMsg("Carona cadastrada com sucesso!");
            }
            else{
                TLMensagem.TelaMsg("Erro no cadastramento da carona!");
            }
            return resultado;
        case 2:
            TLCarona.TelaDescadastrarCarona(ride);
            resultado = refServCarona->DescadastrarCarona(ride);
            if(resultado==1){
                TLMensagem.TelaMsg("Carona descadastrada com sucesso!");
            }
            else{
                TLMensagem.TelaMsg("Erro no descadastramento da carona!");
            }
            return resultado;
        case 3:
            user.SetEmail(usuario);
            Email aux;
            resultado = refServCarona->ListarReservas(user,ride,reserva,aux);
            A.ListarReservas(user,ride,reserva,aux);
            if(resultado==0){
                TLMensagem.TelaMsg("Erro na visualizacao de reservas da carona!");
            }
            return resultado;
    }
}

bool CntrServCarona::DescadastrarReserva(Email email) throw(runtime_error)
{
    CmdDescadastroReserva Cmd;

    Cmd.CmdDescadastrarReserva(email);
    Cmd.executar();
    return 1;
}
