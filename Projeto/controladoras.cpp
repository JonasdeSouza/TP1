#include "controladoras.h"
#include "dominios.h"
#include "entidades.h"
#include "curses.h"
#include <cstring>
#include "telas.h"
#include "persistencia.h"
//--------------------------------------------------------------------------------------------------------------------------------------------
int CntrAprInicializacao::Start() throw(runtime_error){
    TelaInicializacao TLInicializacao;
    return TLInicializacao.TelaIncial();
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprAutenticacao::Autenticar(Email& usuario) throw(runtime_error){
    Email email;
    Senha senha;
    bool resultado;

    while(true) {

        try {
            TelaAutenticar TLAutenticacao;
            TLAutenticacao.TelaAutenticacao(email, senha);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    try{
        resultado = refServAutenticacao->Autenticar(usuario, email, senha);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::Cadastrar() throw(runtime_error){
    User user;
    Account acc1,acc2;
    bool resultado;

    while(true) {

        try {
            TelaUsuario TLCadastro;
            TLCadastro.TelaCadastro(user, acc1, acc2);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    try{
        resultado = refServUsuario->Cadastrar(user, acc1, acc2);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
}
//---------------------------------------------------------------------------------------------------------------------------------------------
int CntrAprUsuario::Perfil() throw(runtime_error){
    TelaUsuario TLPerfil;
    return TLPerfil.TelaOptUsuario();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::AlterarDados(Email& usuario) throw(runtime_error){
    User user;
    Account acc1,acc2;
    bool resultado;

    while(true) {

        try {
            TelaUsuario TLDados;
            TLDados.TelaAlterarDados(user, acc1, acc2);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    try{
        resultado = refServUsuario->AlterarDados(usuario, user, acc1, acc2);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::ExcluirConta(Email& usuario) throw(runtime_error){
    Senha senha;
    bool resultado;

    while(true) {

        try {
            TelaUsuario TLExcluirConta;
            TLExcluirConta.TelaExcluirDados(senha);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    try{
        resultado = refServUsuario->ExcluirConta(usuario,senha);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::VisualizarDados() throw(runtime_error){
    User usuario;
    Account acc,acc2;
    try{
        resultado = refServUsuario->VisualizarDados(usuario,acc,acc2);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    TelaUsuario TLVisualizarDados;
    TLVisualizarDados.TelaVisualizarDados(usuario,acc,acc2);
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
int CntrAprCarona::Carona() throw(runtime_error){
    TelaCarona TLCarona;
    return TLCarona.TelaOptCarona();
}
//--------------------------------------------------------------------------------------------------------------------------------------------
int CntrAprCarona::Reserva() throw(runtime_error){
    TelaReserva TLReserva;
    return TLReserva.TelaOptReserva();
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprCarona::CadastrarCarona(Email& usuario) throw(runtime_error){
    Ride carona;
    bool resultado;

    while(true) {

        try {
            TelaCarona TLCadastroCarona;
            TLCadastroCarona.TelaCadastrarCarona(carona);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    try{
        resultado = refServCarona->CadastrarCarona(usuario,carona);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprCarona::DescadastrarCarona() throw(runtime_error){
    Ride carona;
    bool resultado;

    while(true) {

        try {
            TelaCarona TLDescadastroCarona;
            TLDescadastroCarona.TelaDescadastrarCarona(carona);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    try{
        resultado = refServCarona->DescadastrarCarona(carona);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprCarona::ListarReservas() throw(runtime_error){

}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprCarona::CadastrarReserva(Email& usuario) throw(runtime_error){
    Booking reserva;
    bool resultado;

    while(true) {

        try {
            TelaReserva TLCadastroReserva;
            TLCadastroReserva.TelaCadastrarReserva(reserva);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    try{
        resultado = refServCarona->CadastrarReserva(usuario,reserva);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
}

//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprCarona::DescadastrarReserva(Email& email) throw(runtime_error){
    bool resultado;

    while(true) {

        try {
            TelaReserva TLDescadastroReserva;
            TLDescadastroReserva.TelaDescadastrarReserva();
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem TLMensagem;
            TLMensagem.TelaMsg("Dado em formato incorreto.");
        }
    }
    try{
        resultado = refServCarona->DescadastrarReserva(email);
    }
    catch(runtime_error){
        TelaMensagem TLMensagem;
        TLMensagem.TelaMsg("Erro no banco de dados;");
    }
    return resultado;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
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
bool CntrServUsuario::Cadastrar(User& user,Account& acc1,Account& acc2) throw(runtime_error){
    CmdCadastroUsuario Cmd;
    Cmd.CmdCadastroUser(user);
    Cmd.executar();
    Cmd.CmdCadastroAccount(user,acc1);
    Cmd.executar();
    Cmd.CmdCadastroAccount(user,acc2);
    Cmd.executar();
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServUsuario::VisualizarDados(User& user, Account& acc, Account& acc2) throw(runtime_error){
    Cpf CpfDB;
    Nome NomeDB;
    Telefone TelefoneDB;
    Conta Conta1DB,Conta2DB;
    Banco Banco1DB,Banco2DB;
    Agencia Agencia1DB,Agencia2DB;
    CmdVisualizarDados Cmd;

    Cmd.CmdGetCpf(email);
    Cmd.executar();
    CpfDB.SetCpf(Cmd.GetResultCpf());
    Cmd.CmdGetNome(email);
    Cmd.executar();
    NomeDB.SetNome(Cmd.GetResultNome());
    Cmd.CmdGetTelefone(email);
    Cmd.executar();
    TelefoneDB.SetTelefone(Cmd.GetResultTelefone());
    Cmd.CmdGetConta1(email);
    Cmd.executar();
    Conta1DB.SetConta(Cmd.GetResultConta1());
    Cmd.CmdGetBanco1(email);
    Cmd.executar();
    Banco1DB.SetCodigoBanco(Cmd.GetResultBanco1());
    Cmd.CmdGetAgencia1(email);
    Cmd.executar();
    Agencia1DB.SetAgencia(Cmd.GetResultAgencia1());
    Cmd.CmdGetConta2(email);
    Cmd.executar();
    Conta2DB.SetConta(Cmd.GetResultConta2());
    Cmd.CmdGetBanco2(email);
    Cmd.executar();
    Banco2DB.SetCodigoBanco(Cmd.GetResultBanco2());
    Cmd.CmdGetAgencia2(email);
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

}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServUsuario::AlterarDados(Email& usuario, User& user, Account& acc1, Account& acc2) throw(runtime_error){
    CmdAtualizacaoDados Cmd;

    Cmd.CmdAtualizarUser(usuario,user);
    Cmd.executar();
    Cmd.CmdAtualizarAccount(usuario,acc1);
    Cmd.executar();
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServUsuario::ExcluirConta(Email& usuario, Senha& senha) throw(runtime_error){
    string SenhaDB;
    CmdExclusaoConta Cmd;

    Cmd.CmdConfirmSenha(usuario);
    Cmd.executar();
    SenhaDB = Cmd.getResultado();
    if(SenhaDB==senha.GetSenha()){
        Cmd.CmdExcluirConta(usuario);
        return 1;
    }
        else{
            return 0;
        }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServCarona::CadastrarCarona(Email& usuario, Ride& carona) throw(runtime_error){
    CmdCadastroCarona Cmd;

    Cmd.CmdCadastrarCarona(usuario,carona);
    Cmd.executar();
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServCarona::DescadastrarCarona(Ride ride) throw(runtime_error){
    CmdDescadastroCarona Cmd;

    Cmd.CmdDescadastrarCarona(ride);
    Cmd.executar();
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServCarona::ListarReservas() throw(runtime_error){

}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServCarona::CadastrarReserva(Email& usuario,Booking& reserva) throw(runtime_error){
    CmdCadastroReserva Cmd;

    Cmd.CmdCadastrarReserva(usuario,reserva);
    Cmd.executar();
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServCarona::DescadastrarReserva(Email email) throw(runtime_error){
    CmdDescadastroReserva Cmd;

    Cmd.CmdDescadastrarReserva(email);
    Cmd.executar();
    return 1;
}
