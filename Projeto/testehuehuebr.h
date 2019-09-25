#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.h"
#incluide <string>

using namespace std;

class TUAssento(
    private:
        const static string VALOR_INVALIDO = A;
        const static string VALOR_VALIDO = D;
        Assento *assento;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUBagagem(
    private:
        const static int VALOR_INVALIDO = 5;
        const static int VALOR_VALIDO = 1;
        Bagagem *bagagem;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUCodigo_Banco(
    private:
        const static string VALOR_INVALIDO = E23A56;
        const static string VALOR_VALIDO = 123;
        Banco *codigo;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUCodigo_Carona(
    private:
        const static string VALOR_INVALIDO = A23;
        const static string VALOR_VALIDO = 5467;
        CodigoCarona *codigo;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUCodigo_Reserva(
    private:
        const static string VALOR_INVALIDO = 123R;
        const static string VALOR_VALIDO = 84965;
        CodigoReserva *codigo;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUCidade(
    private:
        const static string VALOR_INVALIDO = .brasilia;
        const static string VALOR_VALIDO = brasilia;
        Cidade *cidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUCpf(
    private:
        const static string VALOR_INVALIDO = 123.ARD.456012.18;
        const static string VALOR_VALIDO = 123.456.789-00;
        Cpf *cpf;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUData(
    private:
        const static string VALOR_INVALIDO = 45/30/3456;
        const static *** VALOR_VALIDO = 18/05/2020;
        Data *data;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUDuracao(
    private:
        const static int VALOR_INVALIDO = 49;
        const static int VALOR_VALIDO = 5;
        Duracao *duracao;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUEstado(
    private:
        const static string VALOR_INVALIDO = KT;
        const static string VALOR_VALIDO = DF;
        Estado *estado;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUEmail(
    private:
        const static string VALOR_INVALIDO = abcdefghijklmnopqrstuvxwyz@abcdefghijklmnopqrstuvxwyz;
        const static *** VALOR_VALIDO = joao@gmail.com;
        Email *Email;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUNome(
    private:
        const static string VALOR_INVALIDO = .Clodoaldo;
        const static string VALOR_VALIDO = Washingtonilda;
        Nome *nome;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUNumero_Agencia(
    private:
        const static string VALOR_INVALIDO = 633;
        const static string VALOR_VALIDO = 4598;
        Agencia * agencia;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUNumero_Conta(
    private:
        const static string VALOR_INVALIDO = 6312;
        const static string VALOR_VALIDO = 123456;
        Conta *numero;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUPreco(
    private:
        const static float VALOR_INVALIDO = 0;
        const static float VALOR_VALIDO = 35,50;
        Preco *Preco;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUTelefone(
    private:
        const static string VALOR_INVALIDO = 61-00-940028922;
        const static string VALOR_VALIDO = 55-61-940028922;
        Telefone *telefone;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUSenha(
    private:
        const static string VALOR_INVALIDO = 11111;
        const static string VALOR_VALIDO = 123A5;
        Senha *senha;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

class TUVagas(
    private:
        const static int VALOR_INVALIDO = 8;
        const static int VALOR_VALIDO = 2;
        Vagas *vagas;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
);

#endif // TESTES_H_INCLUDED
