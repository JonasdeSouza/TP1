#ifndef USER_H
#define USER_H
#include <string>
#include <stdexcept>
using namespace std;

    class Nome{
        private:
            string nome;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetNome(string);
            string GetNome();
    };

    class Telefone{
        private:
            string telefone;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetTelefone(string);
            string GetTelefone();
    };

    class Email{
        private:
            string email;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetEmail(string);
            string GetEmail();
    };

    class Senha{
        private:
            string senha;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetSenha(string);
            string GetSenha();
    };

    class Cpf{
        private:
            string cpf;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            int ValidarDigitoVerificador(string) throw (invalid_argument);
            void SetCpf(string);
            string GetCpf();
    };

    class User{
        private:
            Nome nome;
            Telefone telefone;
            Email email;
            Senha senha;
            Cpf cpf;
        public:
            void CadastrarUsuario(string, string, string, string, string);
            void Imprime();
    };

//-----------------------------------------------------------------------------------------------

    class Bagagem {
        private:
            int bagagem;
            string argumento;

        public:
            int Validar(int) throw (invalid_argument); 
            void SetBagagem(int);
            int GetBagagem();
    };

    class Assento{
        private:
            char assento;
            string argumento;
        public:
            int Validar(char) throw (invalid_argument);
            void SetAssento(char);
            char GetAssento();
    };

    class CodigoReserva{
        private:
            int codigoreserva;
            string argumento;
        public:
            int Validar(int) throw (invalid_argument);
            void SetCodigoReserva(int);
            int GetCodigoReserva();
    };

    class Booking{
        private:
            CodigoReserva codigo;
            Assento assento;
            Bagagem bagagem;
        public:
            void ReservarCarona(int, int, char);
            void Imprime();
    };

//-----------------------------------------------------------------------------------------------------

    class CodigoCarona{
        private:
            int codigocarona;
            string argumento;
        public:
            int Validar(int) throw (invalid_argument);
            void SetCodigoCarona(int);
            int GetCodigoCarona();
    };

    class CidadeOrigem{
        private:
            string cidadeorigem;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetCidadeOrigem(string);
            string GetCidadeOrigem();
    };

    class CidadeDestino{
        private:
            string cidadedestino;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetCidadeDestino(string);
            string GetCidadeDestino();
    };

    class EstadoOrigem{
        private:
            string estadoorigem;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetEstadoOrigem(string);
            string GetEstadoOrigem();
    };

    class EstadoDestino{
        private:
            string estadodestino;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetEstadoDestino(string);
            string GetEstadoDestino();
    };

    class Data{
        private:
            string data;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetData(string);
            string GetData();
    };

    class Duracao{
        private:
            int duracao;
            string argumento;
        public:
            int Validar(int) throw (invalid_argument);
            void SetDuracao(int);
            int GetDuracao();
    };

    class Vagas{
        private:
            int vagas;
            string argumento;
        public:
            int Validar(int) throw (invalid_argument);
            void SetVagas(int);
            int GetVagas();
    };

    class Preco{
        private:
            string preco;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetPreco(string);
            string GetPreco();
    };

    class Ride{
        private:
            CodigoCarona codigocarona;
            CidadeOrigem cidadeorigem;
            CidadeDestino cidadedestino;
            EstadoOrigem estadoorigem;
            EstadoDestino estadodestino;
            Data data;
            Duracao duracao;
            Vagas vagas;
            Preco preco;
        public:
            void CadastrarCarona(int, int, int, string, string, string, string, string, string);
            void Imprime();
    };

//---------------------------------------------------------------------------------

    class Banco{
        private:
            int codigobanco;
            string argumento;
        public:
            int Validar(int) throw (invalid_argument);
            void SetCodigoBanco(int);
            int GetCodigoBanco();
    };

    class Agencia{
        private:
            string agencia;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetAgencia(string);
            string GetAgencia();
    };

    class Conta{
        private:
            string conta;
            string argumento;
        public:
            int Validar(string) throw (invalid_argument);
            void SetConta(string);
            string GetConta();
    };

    class Account{
        private:
            Banco banco;
            Agencia agencia;
            Conta conta;
        public:
            void CadastrarInfoBancarias(int, string, string);
            void Imprime();
    };
#endif
