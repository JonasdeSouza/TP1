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
            void SetNome(const Nome &nome){
                this->nome = nome;
            }
            Nome GetNome() const {
                return nome;
            }

            void SetTelefone(const Telefone &telefone){
                this->telefone = telefone;
            }
            Telefone GetTelefone() const {
                return telefone;
            }

            void SetEmail(const Email &email){
                this->email = email;
            }
            Email GetEmail() const {
                return email;
            }

            void SetSenha(const Senha &senha){
                this->senha = senha;
            }
            Senha GetSenha() const {
                return senha;
            }

            void SetCpf(const Cpf &cpf){
                this->cpf = cpf;
            }
            Cpf GetCpf() const {
                return cpf;
            }
            //~User();
    };

class Booking{
        private:
            CodigoReserva codigo;
            Assento assento;
            Bagagem bagagem;
        public:
            void ReservarCarona(int, int, char);
            void Imprime();
            void SetCodigoReserva(const CodigoReserva &codigo){
                this->codigo = codigo;
            }
            CodigoReserva GetCodigoReserva() const {
                return codigo;
            }

            void SetAssento(const Assento &assento){
                this->assento = assento;
            }
            Assento GetAssento() const {
                return assento;
            }

            void SetBagagem(const Bagagem &bagagem){
                this->bagagem = bagagem;
            }
            Bagagem GetBagagem() const {
                return bagagem;
            }

            //~Booking();
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
            void SetCodigoCarona(const CodigoCarona &codigocarona){
                this->codigocarona = codigocarona;
            }
            CodigoCarona GetCodigoCarona() const {
                return codigocarona;
            }

            void SetCidadeOrigem(const CidadeOrigem &cidadeorigem){
                this->cidadeorigem = cidadeorigem;
            }
            CidadeOrigem GetCidadeOrigem() const {
                return cidadeorigem;
            }

            void SetCidadeDestino(const CidadeDestino &cidadedestino){
                this->cidadedestino = cidadedestino;
            }
            CidadeDestino GetCidadeDestino() const {
                return cidadedestino;
            }

            void SetEstadoOrigem(const EstadoOrigem &estadoorigem){
                this->estadoorigem = estadoorigem;
            }
            EstadoOrigem GetEstadoOrigem() const {
                return estadoorigem;
            }

            void SetEstadoDestino(const EstadoDestino &estadodestino){
                this->estadodestino = estadodestino;
            }
            EstadoDestino GetEstadoDestino() const {
                return estadodestino;
            }

            void SetData(const Data &data){
                this->data= data;
            }
            Data GetData() const {
                return data;
            }

            void SetPreco(const Preco &preco){
                this->preco = preco;
            }
            Preco GetPreco() const {
                return preco;
            }

            void SetVagas(const Vagas &vagas){
                this->vagas= vagas;
            }
            Vagas GetVagas() const {
                return vagas;
            }

            void SetDuracao(const Duracao &duracao){
                this->duracao= duracao;
            }
            Duracao GetDuracao() const {
                return duracao;
            }
    };

    class Account{
        private:
            Banco banco;
            Agencia agencia;
            Conta conta;
        public:
            void CadastrarInfoBancarias(int, string, string);
            void Imprime();
            void SetBanco(const Banco &banco){
                this->banco = banco;
            }
            Banco GetBanco() const {
                return banco;
            }

            void SetAgencia(const Agencia &agencia){
                this->agencia= agencia;
            }
            Agencia GetAgencia() const {
                return agencia;
            }

            void SetConta(const Conta &conta){
                this->conta = conta;
            }
            Conta GetConta() const {
                return conta;
            }
    };
#endif
