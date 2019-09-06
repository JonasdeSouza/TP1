#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

    class Nome{
        private:
            string nome;
        public:
            void SetNome(string Nome);
            string GetNome();
    };

    class Telefone{
        private:
            string telefone;
        public:
            void SetTelefone(string Telefone);
            string GetTelefone();
    };

    class Email{
        private:
            string email;
        public:
            void SetEmail(string Email);
            string GetEmail();
    };

    class Senha{
        private:
            string senha;
        public:
            void SetSenha(string Senha);
            string GetSenha();
    };

    class Cpf{
        private:
            string cpf;
        public:
            void SetCpf(string Cpf);
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
            void CadastrarUsuario(string nome, string telefone, string email, string senha, string cpf);
            void Imprime();
    };

//-----------------------------------------------------------------------------------------------

    class Bagagem {
        private:
            int bagagem;

        public:
            void SetBagagem(int Bagagem);
            int GetBagagem();
    };

    class Assento{
        private:
            char assento;
        public:
            void SetAssento(char Assento);
            char GetAssento();
    };

    class CodigoReserva{
        private:
            int codigoreserva;
        public:
            void SetCodigoReserva(int CodigoReserva);
            int GetCodigoReserva();
    };

    class Booking{
        private:
            CodigoReserva codigo;
            Assento assento;
            Bagagem bagagem;
        public:
            void ReservarCarona(int codigoreserva, int bagagem, char assento);
            void Imprime();
    };

//-----------------------------------------------------------------------------------------------------

    class CodigoCarona{
        private:
            int codigocarona;
        public:
            void SetCodigoCarona(int CodigoCarona);
            int GetCodigoCarona();
    };

    class CidadeOrigem{
        private:
            string cidadeorigem;
        public:
            void SetCidadeOrigem(string CidadeOrigem);
            string GetCidadeOrigem();
    };

    class CidadeDestino{
        private:
            string cidadedestino;
        public:
            void SetCidadeDestino(string CidadeDestino);
            string GetCidadeDestino();
    };

    class EstadoOrigem{
        private:
            string estadoorigem;
        public:
            void SetEstadoOrigem(string EstadoOrigem);
            string GetEstadoOrigem();
    };

    class EstadoDestino{
        private:
            string estadodestino;
        public:
            void SetEstadoDestino(string EstadoDestino);
            string GetEstadoDestino();
    };

    class Data{
        private:
            string data;
        public:
            void SetData(string data);
            string GetData();
    };

    class Duracao{
        private:
            int duracao;
        public:
            void SetDuracao(int Duracao);
            int GetDuracao();
    };

    class Vagas{
        private:
            int vagas;
        public:
            void SetVagas(int Vagas);
            int GetVagas();
    };

    class Preco{
        private:
            string preco;
        public:
            void SetPreco(string preco);
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
            void CadastrarCarona(int vagas, int duracao, int codigocarona, string cidadeorigem, string estadoorigem, string cidadedestino, string estadodestino, string data, string preco);
    };

//---------------------------------------------------------------------------------

    class Banco{
        private:
            int codigobanco;
        public:
            void SetCodigoBanco(int CodigoBanco);
            int GetCodigoBanco();
    };

    class Agencia{
        private:
            string agencia;
        public:
            void SetAgencia(string Agencia);
            string GetAgencia();
    };

    class Conta{
        private:
            string conta;
        public:
            void SetConta(string Conta);
            string GetConta();
    };

    class Account{
        private:
            Banco banco;
            Agencia agencia;
            Conta conta;
        public:
            void CadastrarInfoBancarias(int codigobanco, string agencia, string conta);
    };
#endif
