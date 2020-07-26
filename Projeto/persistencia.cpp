#include "persistencia.h"
#include <string>
#include <string.h>
#include "conio.h"
#include <sqlite3.h>
using namespace std;

list<ElementoResultado> ComandoSQL::listaResultado;

//-------------------------------------------------------------------------------------------------------------------------------
void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}
//-------------------------------------------------------------------------------------------------------------------------------
void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}
//-------------------------------------------------------------------------------------------------------------------------------
void ComandoSQL::conectar() throw (runtime_error) {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw runtime_error("Erro na conexao ao banco de dados");
}
//-------------------------------------------------------------------------------------------------------------------------------
void ComandoSQL::desconectar() throw (runtime_error) {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw runtime_error("Erro na desconexao ao banco de dados");
}
//-------------------------------------------------------------------------------------------------------------------------------
void ComandoSQL::executar() throw (runtime_error) {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
        if(rc != SQLITE_OK){
                if (mensagem){
                        throw runtime_error(mensagem);
                }
                throw runtime_error("Erro na execucao do comando SQL");
        }
        desconectar();
}
//-------------------------------------------------------------------------------------------------------------------------------
int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed=0;
      ElementoResultado elemento;
      int i;
      for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdAutenticacao::CmdAutenticar(Email email) {
        comandoSQL = "SELECT SENHA FROM Usuarios WHERE EMAIL =\"";
        comandoSQL += email.GetEmail() + "\"";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdAutenticacao::getResultado() throw (runtime_error) {
        ElementoResultado resultado;
        string senha;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha = resultado.getValorColuna();

        return senha;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdCadastroUsuario::CmdCadastroUser(User user) {
        comandoSQL = "INSERT INTO Usuarios VALUES (";
        comandoSQL += "\"" + user.GetCpf().GetCpf() + "\",";
        comandoSQL += "\"" + user.GetNome().GetNome() + "\",";
        comandoSQL += "\"" + user.GetEmail().GetEmail() + "\",";
        comandoSQL += "\"" + user.GetTelefone().GetTelefone() + "\",";
        comandoSQL += "\"" + user.GetSenha().GetSenha() + "\");";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdCadastroUsuario::CmdCadastroAccount(User user, Account acc, Account acc2) {
        comandoSQL = "INSERT INTO Conta VALUES (";
        comandoSQL += "\"" + user.GetEmail().GetEmail() + "\",";
        int CmdCodigo = acc.GetBanco().GetCodigoBanco();
        comandoSQL += "\"" + to_string(CmdCodigo) + "\",";
        comandoSQL += "\"" + acc.GetAgencia().GetAgencia() + "\",";
        comandoSQL += "\"" + acc.GetConta().GetConta();
        if(acc2.GetAgencia().GetAgencia().empty() != 1){
            int CmdCodigo = acc.GetBanco().GetCodigoBanco();
            comandoSQL += "\",\"" + to_string(CmdCodigo) + "\",";
            comandoSQL += "\"" + acc.GetAgencia().GetAgencia() + "\",";
            comandoSQL += "\"" + acc.GetConta().GetConta() + "\");";
        } else {
            comandoSQL += "\",NULL,NULL,NULL);";
        }
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdAtualizacaoDados::CmdAtualizarUser(Email usuario, User user) {
        comandoSQL = "UPDATE Usuarios SET";
        comandoSQL += " NOME = \"" + user.GetNome().GetNome();
        comandoSQL += "\", TELEFONE = \"" + user.GetTelefone().GetTelefone();
        comandoSQL += "\", SENHA = \"" + user.GetSenha().GetSenha();
        comandoSQL += "\" WHERE EMAIL = \"" + usuario.GetEmail() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdAtualizacaoDados::CmdAtualizarAccount(Email usuario, Account acc1) {
        comandoSQL = "UPDATE Conta ";
        comandoSQL += "SET CONTA = \"" + acc1.GetConta().GetConta();
        int CmdCodigoBanco = acc1.GetBanco().GetCodigoBanco();
        comandoSQL += "\", BANCO = \"" + to_string(CmdCodigoBanco);
        comandoSQL += "\", AGENCIA = \"" + acc1.GetAgencia().GetAgencia();
        comandoSQL += "\" WHERE EMAIL = \"" + usuario.GetEmail() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdExclusaoConta::CmdConfirmSenha(Email usuario) {
        comandoSQL = "SELECT SENHA FROM Usuarios WHERE EMAIL = \"";
        comandoSQL += usuario.GetEmail() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdExclusaoConta::getResultado() throw (runtime_error) {
        ElementoResultado resultado;
        string senha;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha = resultado.getValorColuna();

        return senha;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdExclusaoConta::CmdExcluirConta(Email usuario) {
        comandoSQL = "DELETE FROM Usuarios WHERE EMAIL = \"";
        comandoSQL += usuario.GetEmail() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdCadastroCarona::CmdCadastrarCarona(Email usuario, Ride ride){
    CmdVisualizarDados GetNome;
    GetNome.CmdGetNome(usuario);
    GetNome.executar();
    string aux = GetNome.GetResultNome();
    comandoSQL = "INSERT INTO Caronas VALUES(";
    comandoSQL += "\"" + aux + "\",";
    comandoSQL += "\"" + usuario.GetEmail() + "\",";
    int CmdCodigoCarona = ride.GetCodigoCarona().GetCodigoCarona();
    comandoSQL += "\"" + to_string(CmdCodigoCarona) + "\",";
    comandoSQL += "\"" + ride.GetEstadoOrigem().GetEstadoOrigem() + "\",";
    comandoSQL += "\"" + ride.GetCidadeOrigem().GetCidadeOrigem() + "\",";
    comandoSQL += "\"" + ride.GetEstadoDestino().GetEstadoDestino() + "\",";
    comandoSQL += "\"" + ride.GetCidadeDestino().GetCidadeDestino() + "\",";
    comandoSQL += "\"" + ride.GetData().GetData() + "\",";
    int CmdDuracao = ride.GetDuracao().GetDuracao();
    comandoSQL += "\"" + to_string(CmdDuracao) + "\",";
    int CmdVagas = ride.GetVagas().GetVagas();
    comandoSQL += "\"" + to_string(CmdVagas) + "\",";
    comandoSQL += "\"" + ride.GetPreco().GetPreco() + "\");";
    cout << comandoSQL;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdDescadastroCarona::CmdDescadastrarCarona(Ride ride) {
        comandoSQL = "DELETE FROM Caronas WHERE \"CODIGO CARONA\" =(";
        int CmdCodigoCarona = ride.GetCodigoCarona().GetCodigoCarona();
        comandoSQL += "\"" + to_string(CmdCodigoCarona) + "\");";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarReservas::CmdGetNome(CodigoCarona cd) {
        comandoSQL = "SELECT NOME FROM Caronas WHERE \"CODIGO CARONA\" = \"";
        comandoSQL += cd.GetCodigoCarona() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarReservas::GetResultNome() throw (runtime_error) {
        ElementoResultado resultado;
        string nome;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        nome = resultado.getValorColuna();

        return nome;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarReservas::CmdGetEmail(CodigoCarona cd) {
        comandoSQL = "SELECT EMAIL FROM Caronas WHERE \"CODIGO CARONA\" = \"";
        comandoSQL += cd.GetCodigoCarona() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarReservas::GetResultEmail() throw (runtime_error) {
        ElementoResultado resultado;
        string email;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        email = resultado.getValorColuna();

        return email;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarReservas::CmdGetCodreserv(CodigoCarona cd) {
        comandoSQL = "SELECT \"CODIGO RESERVA\" FROM Caronas WHERE \"CODIGO CARONA\" = \"";
        comandoSQL += cd.GetCodigoCarona() + "\";";
}
void CmdVisualizarCodCarona::CmdGetcodcarona(Email usuario) {
        comandoSQL = "SELECT \"CODIGO CARONA\" FROM Caronas WHERE EMAIL = \"";
        comandoSQL += usuario.GetEmail() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarCodCarona::GetResultcodcarona() throw (runtime_error) {
        ElementoResultado resultado;
        string senha;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha = resultado.getValorColuna();

        return senha;
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarReservas::GetResultCodreserv() throw (runtime_error) {
        ElementoResultado resultado;
        string cdreserv;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        cdreserv = resultado.getValorColuna();

        return cdreserv;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarReservas::CmdGetAssento(CodigoCarona cd) {
        comandoSQL = "SELECT ASSENTO FROM Caronas WHERE \"CODIGO CARONA\" = \"";
        comandoSQL += cd.GetCodigoCarona() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarReservas::GetResultAssento() throw (runtime_error) {
        ElementoResultado resultado;
        string assento;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        assento = resultado.getValorColuna();

        return assento;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarReservas::CmdGetBagagem(CodigoCarona cd) {
        comandoSQL = "SELECT BAGAGEM FROM Caronas WHERE \"CODIGO CARONA\" = \"";
        comandoSQL += cd.GetCodigoCarona() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarReservas::GetResultBagagem() throw (runtime_error) {
        ElementoResultado resultado;
        string bagagem;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        bagagem = resultado.getValorColuna();

        return bagagem;
}
//--------------------------------------------------------------------------------------------------------------------------------
void CmdCadastroReserva::CmdCadastrarReserva(Email usuario,Booking reserva,Ride ride){
        comandoSQL = "INSERT INTO Reservas VALUES (";
        comandoSQL += "\"" + usuario.GetEmail() + "\",";
        int CmdCodigoCarona = ride.GetCodigoCarona().GetCodigoCarona();
        comandoSQL += "\"" + to_string(CmdCodigoCarona) + "\",";
        int CmdCodigoReserva = reserva.GetCodigoReserva().GetCodigoReserva();
        comandoSQL += "\"" + to_string(CmdCodigoReserva) + "\",";
        char CmdAssento = reserva.GetAssento().GetAssento();
        string CmdAssento2;
        CmdAssento2.push_back(CmdAssento);
        comandoSQL += "\"" + CmdAssento2 + "\",";
        int CmdBagagem = reserva.GetBagagem().GetBagagem();
        comandoSQL += "\"" + to_string(CmdBagagem) + "\");";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdDescadastroReserva::CmdDescadastrarReserva(Email usuario){
        comandoSQL = "DELETE FROM Reservas WHERE EMAIL = ";
        comandoSQL += "\"" + usuario.GetEmail() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarDados::CmdGetCpf(Email usuario) {
        comandoSQL = "SELECT CPF FROM Usuarios WHERE EMAIL = \"";
        comandoSQL += usuario.GetEmail() + "\";";
        cout << comandoSQL << "\n";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarDados::GetResultCpf() throw (runtime_error) {
        ElementoResultado resultado;
        string cpf;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        cpf = resultado.getValorColuna();

        return cpf;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarDados::CmdGetNome(Email usuario) {
       comandoSQL = "SELECT NOME FROM Usuarios WHERE EMAIL = \"";
        comandoSQL += usuario.GetEmail() + "\";";
        cout << comandoSQL << "\n";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarDados::GetResultNome() throw (runtime_error) {
        ElementoResultado resultado;
        string nome;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        nome = resultado.getValorColuna();

        return nome;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarDados::CmdGetTelefone(Email usuario) {
       comandoSQL = "SELECT TELEFONE FROM Usuarios WHERE EMAIL = \"";
        comandoSQL += usuario.GetEmail() + "\";";
        cout << comandoSQL << "\n";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarDados::GetResultTelefone() throw (runtime_error) {
        ElementoResultado resultado;
        string telefone;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        telefone = resultado.getValorColuna();

        return telefone;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarDados::CmdGetConta1(Email usuario) {
        comandoSQL = "SELECT CONTA FROM Conta WHERE EMAIL = \"";
        comandoSQL += usuario.GetEmail() + "\";";
        cout << comandoSQL << "\n";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarDados::GetResultConta1() throw (runtime_error) {
        ElementoResultado resultado;
        string conta1;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        conta1 = resultado.getValorColuna();

        return conta1;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarDados::CmdGetBanco1(Email usuario) {
        comandoSQL = "SELECT BANCO FROM Conta WHERE EMAIL = \"";
        comandoSQL += usuario.GetEmail() + "\";";
        cout << comandoSQL << "\n";
}
//-------------------------------------------------------------------------------------------------------------------------------
int CmdVisualizarDados::GetResultBanco1() throw (runtime_error) {
        ElementoResultado resultado;
        int banco1;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        banco1 = atoi(resultado.getValorColuna().c_str());

        return banco1;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarDados::CmdGetAgencia1(Email usuario) {
        comandoSQL = "SELECT AGENCIA FROM Conta WHERE EMAIL = \"";
         comandoSQL += usuario.GetEmail() + "\";";
        cout << comandoSQL << "\n";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarDados::GetResultAgencia1() throw (runtime_error) {
        ElementoResultado resultado;
        string agencia1;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        agencia1 = resultado.getValorColuna();

        return agencia1;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarDados::CmdGetConta2(Email usuario) {
        comandoSQL = "SELECT CONTA2 FROM Conta WHERE EMAIL = \"";
        comandoSQL += usuario.GetEmail() + "\";";
        cout << comandoSQL << "\n";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarDados::GetResultConta2() throw (runtime_error) {
        ElementoResultado resultado;
        string conta2;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        conta2 = resultado.getValorColuna();

        return conta2;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarDados::CmdGetBanco2(Email usuario) {
        comandoSQL = "SELECT BANCO2 FROM Conta WHERE EMAIL = \"";
        comandoSQL += usuario.GetEmail() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
int CmdVisualizarDados::GetResultBanco2() throw (runtime_error) {
        ElementoResultado resultado;
        int banco2;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        banco2 = atoi(resultado.getValorColuna().c_str());

        return banco2;
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarDados::CmdGetAgencia2(Email usuario) {
        comandoSQL = "SELECT AGENCIA2 FROM Conta WHERE EMAIL = \"";
         comandoSQL += usuario.GetEmail() + "\";";
}
//-------------------------------------------------------------------------------------------------------------------------------
string CmdVisualizarDados::GetResultAgencia2() throw (runtime_error) {
        ElementoResultado resultado;
        string agencia2;

        if (listaResultado.empty())
                throw runtime_error("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        agencia2 = resultado.getValorColuna();

        return agencia2;
}
