#include "persistencia.h"

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
                if (mensagem)
                        delete(mensagem);
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
        comandoSQL = "SELECT SENHA FROM Usuarios WHERE EMAIL = ";
        comandoSQL += email.GetEmail();
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
        comandoSQL += "'" + user.GetCpf().GetCpf() + "', ";
        comandoSQL += "'" + user.GetNome().GetNome() + "', ";
        comandoSQL += "'" + user.GetEmail().GetEmail() + "', ";
        comandoSQL += "'" + user.GetTelefone().GetTelefone() + "', ";
        comandoSQL += "'" + user.GetSenha().GetSenha() + "')";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdCadastroUsuario::CmdCadastroAccount(User user, Account acc) {
        comandoSQL = "INSERT INTO Conta VALUES (";
        comandoSQL += "'" + user.GetEmail().GetEmail() + "', ";
        comandoSQL += "'" + acc.GetConta().GetConta() + "', ";
        //comandoSQL += "'" + acc.GetBanco().GetCodigoBanco() + "', ";
        comandoSQL += "'" + acc.GetAgencia().GetAgencia() + "')";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdAtualizacaoDados::CmdAtualizarUser(Email usuario, User user) {
        comandoSQL = "UPDATE Usuarios ";
        comandoSQL += "SET CPF = '" + user.GetCpf().GetCpf();
        comandoSQL += "', NOME = '" + user.GetNome().GetNome();
        comandoSQL += "', EMAIL = '" + user.GetEmail().GetEmail();
        comandoSQL += "', TELEFONE = '" + user.GetTelefone().GetTelefone();
        comandoSQL += "', SENHA = '" + user.GetSenha().GetSenha();
        comandoSQL += "' WHERE EMAIL = " + usuario.GetEmail();
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdAtualizacaoDados::CmdAtualizarAccount(Email usuario, Account acc1) {
        comandoSQL = "UPDATE Conta ";
        comandoSQL += "SET CONTA = '" + acc1.GetConta().GetConta();
        comandoSQL += "', BANCO = '" + acc1.GetBanco().GetCodigoBanco();
        comandoSQL += "', AGENCIA = '" + acc1.GetAgencia().GetAgencia();
        comandoSQL += "' WHERE EMAIL = " + usuario.GetEmail();
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdExclusaoConta::CmdConfirmSenha(Email usuario) {
        comandoSQL = "SELECT SENHA FROM Usuarios WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
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
        comandoSQL = "DELETE FROM Usuarios WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdCadastroCarona::CmdCadastrarCarona(Email usuario, Ride ride){
        comandoSQL = "INSERT INTO Caronas VALUES (";
        comandoSQL += "'" + usuario.GetEmail() + "', ";
//        comandoSQL += "'" + ride.GetCodigoCarona().GetCodigoCarona() + "', ";
        comandoSQL += "'" + ride.GetEstadoOrigem().GetEstadoOrigem() + "', ";
        comandoSQL += "'" + ride.GetCidadeOrigem().GetCidadeOrigem() + "', ";
        comandoSQL += "'" + ride.GetEstadoDestino().GetEstadoDestino() + "', ";
        comandoSQL += "'" + ride.GetCidadeDestino().GetCidadeDestino() + "', ";
        comandoSQL += "'" + ride.GetData().GetData() + "', ";
//        comandoSQL += "'" + ride.GetDuracao().GetDuracao() + "', ";
//        comandoSQL += "'" + ride.GetVagas().GetVagas() + "', ";
        comandoSQL += "'" + ride.GetPreco().GetPreco() + "')";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdDescadastroCarona::CmdDescadastrarCarona(Ride ride) {
        comandoSQL = "DELETE FROM Caronas WHERE CODIGO CARONA = ";
        comandoSQL +=ride.GetCodigoCarona().GetCodigoCarona();
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdCadastroReserva::CmdCadastrarReserva(Email usuario,Booking reserva){
        comandoSQL = "INSERT INTO Reservas VALUES (";
        comandoSQL += "'" + usuario.GetEmail() + "', ";
//        comandoSQL += "'" + reserva.GetCodigoReserva().GetCodigoReserva() + "', ";
//        comandoSQL += "'" + reserva.GetAssento().GetAssento() + "', ";
//        comandoSQL += "'" + reserva.GetBagagem().GetBagagem() + "')";
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdDescadastroReserva::CmdDescadastrarReserva(Email usuario){
        comandoSQL = "DELETE FROM Reservas WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
}
//-------------------------------------------------------------------------------------------------------------------------------
void CmdVisualizarDados::CmdGetCpf(Email usuario) {
        comandoSQL = "SELECT CPF FROM Usuarios WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
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
        comandoSQL = "SELECT NOME FROM Usuarios WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
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
        comandoSQL = "SELECT TELEFONE FROM Usuarios WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
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
        comandoSQL = "SELECT CONTA FROM Conta WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
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
        comandoSQL = "SELECT CPF FROM Usuarios WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
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
        comandoSQL = "SELECT CPF FROM Usuarios WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
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
        comandoSQL = "SELECT CONTA FROM Conta WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
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
        comandoSQL = "SELECT CPF FROM Usuarios WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
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
        comandoSQL = "SELECT CPF FROM Usuarios WHERE EMAIL = ";
        comandoSQL += usuario.GetEmail();
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
