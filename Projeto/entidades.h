#ifndef ENTIDADES_H
#define ENTIDADES_H
#include <string>
#include <stdexcept>
#include "dominios.h"
using namespace std;

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

class Booking{
        private:
            CodigoReserva codigo;
            Assento assento;
            Bagagem bagagem;
        public:
            void ReservarCarona(int, int, char);
            void Imprime();
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
