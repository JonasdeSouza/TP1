#ifndef TESTES_H
#define TESTES_H

#include "dominios.h"
#include <string>

using namespace std;

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
        string VALOR_VALIDO = "123.456.789-00";
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

#endif // TESTES_H_INCLUDED
