#ifndef DOMINIOS_H
#define DOMINIOS_H
#include <string>
#include <stdexcept>
using namespace std;

class Nome{
        private:
            string nome; 
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetNome(string);
            string GetNome();
            string GetErro();
            string GetExcecao();
    };

    class Telefone{
        private:
            string telefone;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetTelefone(string);
            string GetTelefone();
            string GetExcecao();
    };

    class Email{
        private:
            string email;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetEmail(string);
            string GetEmail();
            string GetExcecao();
    };

    class Senha{
        private:
            string senha;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetSenha(string);
            string GetSenha();
            string GetExcecao();
    };

    class Cpf{
        private:
            string cpf;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            int ValidarDigitoVerificador(string) throw (invalid_argument);
            void SetCpf(string);
            string GetCpf();
            string GetExcecao();
    };


//-----------------------------------------------------------------------------------------------

    class Bagagem {
        private:
            int bagagem;
            string excecao;

        public:
            int Validar(int) throw (invalid_argument);
            void SetBagagem(int);
            int GetBagagem();
            string GetExcecao();
    };

    class Assento{
        private:
            char assento;
            string excecao;
        public:
            int Validar(char) throw (invalid_argument);
            void SetAssento(char);
            char GetAssento();
            string GetExcecao();
    };

    class CodigoReserva{
        private:
            int codigoreserva;
            string excecao;
        public:
            int Validar(int) throw (invalid_argument);
            void SetCodigoReserva(int);
            int GetCodigoReserva();
            string GetExcecao();
    };

//-----------------------------------------------------------------------------------------------------

    class CodigoCarona{
        private:
            int codigocarona;
            string excecao;
        public:
            int Validar(int) throw (invalid_argument);
            void SetCodigoCarona(int);
            int GetCodigoCarona();
            string GetExcecao();
    };

    class CidadeOrigem{
        private:
            string cidadeorigem;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetCidadeOrigem(string);
            string GetCidadeOrigem();
            string GetExcecao();
    };

    class CidadeDestino{
        private:
            string cidadedestino;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetCidadeDestino(string);
            string GetCidadeDestino();
            string GetExcecao();
    };

    class EstadoOrigem{
        private:
            string estadoorigem;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetEstadoOrigem(string);
            string GetEstadoOrigem();
            string GetExcecao();
    };

    class EstadoDestino{
        private:
            string estadodestino;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetEstadoDestino(string);
            string GetEstadoDestino();
            string GetExcecao();
    };

    class Data{
        private:
            string data;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetData(string);
            string GetData();
            string GetExcecao();
    };

    class Duracao{
        private:
            int duracao;
            string excecao;
        public:
            int Validar(int) throw (invalid_argument);
            void SetDuracao(int);
            int GetDuracao();
            string GetExcecao();
    };

    class Vagas{
        private:
            int vagas;
            string excecao;
        public:
            int Validar(int) throw (invalid_argument);
            void SetVagas(int);
            int GetVagas();
            string GetExcecao();
    };

    class Preco{
        private:
            string preco;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            int ConverterPreco(string);
            void SetPreco(string);
            string GetPreco();
            string GetExcecao();
    };

//---------------------------------------------------------------------------------

    class Banco{
        private:
            int codigobanco;
            string excecao;
        public:
            int Validar(int) throw (invalid_argument);
            void SetCodigoBanco(int);
            int GetCodigoBanco();
            string GetExcecao();
    };

    class Agencia{
        private:
            string agencia;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetAgencia(string);
            string GetAgencia();
            string GetExcecao();
    };

    class Conta{
        private:
            string conta;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            void SetConta(string);
            string GetConta();
            string GetExcecao();
    };

#endif
