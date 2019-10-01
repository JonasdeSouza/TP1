#ifndef TESTES_H
#define TESTES_H

#include "dominios.h"
#include "entidades.h"
#include <string>

using namespace std;

class Run{
    public:
        Run();
};
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

class TUAssento{
    private:
        const static char VALOR_VALIDO = 'D';
        const static char VALOR_INVALIDO = 'A';
        Assento *assento;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int FALHA = -1;
        const static int SUCESSO = 0;
        int Run();
        string GetExcecao();
};

class TUBagagem{
    private:
        const static int VALOR_INVALIDO = 5;
        const static int VALOR_VALIDO = 1;
        Bagagem *bagagem;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUCodigoBanco{
    private:
        const static int VALOR_INVALIDO = 321321;
        const static int VALOR_VALIDO = 123;
        Banco *codigo;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUCodigoCarona{
    private:
        const static int VALOR_INVALIDO = 10000;
        const static int VALOR_VALIDO = 5467;
        CodigoCarona *codigo;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUCodigoReserva{
    private:
        const static int VALOR_INVALIDO = 9999999999;
        const static int VALOR_VALIDO = 84965;
        CodigoReserva *codigo;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUCidadeOrigem{
    private:
        string VALOR_INVALIDO = ".brasilia";
        string VALOR_VALIDO = "brasilia";
        CidadeOrigem *cidadeorigem;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUCidadeDestino{
    private:
        string VALOR_INVALIDO = ".brasilia";
        string VALOR_VALIDO = "brasilia";
        CidadeDestino *cidadedestino;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUCpf{
    private:
        string VALOR_INVALIDO = "123.ARD.456012.18";
        string VALOR_VALIDO = "048.236.901-92";
        Cpf *cpf;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUData{
    private:
        string VALOR_INVALIDO = "45/30/3456";
        string VALOR_VALIDO = "18/05/2020";
        Data *data;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUDuracao{
    private:
        const static int VALOR_INVALIDO = 49;
        const static int VALOR_VALIDO = 5;
        Duracao *duracao;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUEstadoOrigem{
    private:
        string VALOR_INVALIDO = "KT";
        string VALOR_VALIDO = "DF";
        EstadoOrigem *estadoorigem;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUEstadoDestino{
    private:
        string VALOR_INVALIDO = "KT";
        string VALOR_VALIDO = "DF";
        EstadoDestino *estadodestino;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUEmail{
    private:
        string VALOR_INVALIDO = "abcdefghijklmnopqrstuvxwyz@abcdefghijklmnopqrstuvxwyz";
        string VALOR_VALIDO = "joao@gmail.com";
        Email *email;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUNome{
    private:
        string VALOR_INVALIDO = ".Clodoaldo";
        string VALOR_VALIDO = "Washingtonilda";
        Nome *nome;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUAgencia{
    private:
        string VALOR_INVALIDO = "633";
        string VALOR_VALIDO = "1234-4";
        Agencia * agencia;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUConta{
    private:
        string VALOR_INVALIDO = "6312";
        string VALOR_VALIDO = "123456-6";
        Conta *numero;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUPreco{
    private:
        string VALOR_INVALIDO = "0";
        string VALOR_VALIDO = "35,50";
        Preco *preco;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUTelefone{
    private:
        string VALOR_INVALIDO = "61-00-940028922";
        string VALOR_VALIDO = "55-61-940028922";
        Telefone *telefone;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUSenha{
    private:
        string VALOR_INVALIDO = "11111";
        string VALOR_VALIDO = "123A5";
        Senha *senha;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUVagas{
    private:
        const static int VALOR_INVALIDO = 8;
        const static int VALOR_VALIDO = 2;
        Vagas *vagas;
        int estado;
        string excecao;
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int Run();
        string GetExcecao();
};

class TUUser{
    private:
        User *user;
        int estado;
        string NOME_VALIDO = "joao";
        string NOME_INVALIDO = "jota2";
        string TELEFONE_VALIDO = "55-61-984851645";
        string TELEFONE_INVALIDO = "55-00-998123723";
        string SENHA_VALIDA = "a1b2c";
        string SENHA_INVALIDA = "123456";
        string EMAIL_VALIDO = "usuario@padrao.com";
        string EMAIL_INVALIDO = "usuario..@nao..com";
        string CPF_VALIDO = "048.236.901-92";
        string CPF_INVALIDO = "098.324.871-00";
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        int Run();
        const static int SUCESSO = 0;
        const static int FALHA = -1;
};

class TUBooking{
    private:
        Booking *booking;
        int estado;
        const static int CODIGO_VALIDO = 1234;
        const static int CODIGO_INVALIDO = 12345;
        const static int BAGAGEM_VALIDA = 2;
        const static int BAGAGEM_INVALIDA = 5;
        char ASSENTO_VALIDO = 'D';
        char ASSENTO_INVALIDO = 'A';
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        int Run();
        const static int SUCESSO = 0;
        const static int FALHA = -1;
};

class TURide{
    private:
        Ride *ride;
        int estado;
        const static int CODIGO_VALIDO = 1234;
        const static int CODIGO_INVALIDO = 12345;
        const static int VAGAS_VALIDA = 2;
        const static int VAGAS_INVALIDA = 5;
        const static int DURACAO_VALIDA = 24;
        const static int DURACAO_INVALIDA = 50;
        string ESTADO_DESTINO_VALIDO = "DF";
        string ESTADO_DESTINO_INVALIDO = "AA";
        string ESTADO_ORIGEM_VALIDO = "AC";
        string ESTADO_ORIGEM_INVALIDO = "BB";
        string CIDADE_DESTINO_VALIDA = "Brasilia";
        string CIDADE_DESTINO_INVALIDA = ".Brasilia";
        string CIDADE_ORIGEM_VALIDA = "Sao Paulo";
        string CIDADE_ORIGEM_INVALIDA = ".Saop pualo";
        string DATA_VALIDA = "12/02/2019";
        string DATA_INVALIDA = "29/02/2019";
        string PRECO_VALIDO = "4.000,00";
        string PRECO_INVALIDO = "6.000,00";
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        int Run();
        const static int SUCESSO = 0;
        const static int FALHA = -1;
};

class TUAccount{
    private:
        Account *account;
        int estado;
        const static int CODIGO_VALIDO = 170;
        const static int CODIGO_INVALIDO = 1234;
        string CONTA_VALIDA = "123456-6";
        string CONTA_INVALIDA = "123456-7";
        string AGENCIA_VALIDA = "1234-4";
        string AGENCIA_INVALIDA = "1234-7";
        void SetUp();
        void TearDown();
        void TestarCenarioSucesso();
        void TestarCenarioFalha();
    public:
        int Run();
        const static int SUCESSO = 0;
        const static int FALHA = -1;
};
#endif // TESTES_H_INCLUDED
