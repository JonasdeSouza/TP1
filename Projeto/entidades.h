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
            void CadastrarUsuario(string, string, string, string, string); /**< Metodo para cadastrar usuario, recebe 5 strings e invoca o metodo Set de cada uma delas @param nome, email, telefone, senha, cpf */
            void Imprime(); /**< Imprime na tela todos os valores dos dominios pertencentes a entidade User alocados em memoria @see CadastrarUsuario()*/ 
            void SetNome(const Nome &nome){ /** Funcao para a entidade User ter acesso ao metodo SetNome da classe Nome @param nome @see SetNome()*/
                this->nome = nome;
            }
            Nome GetNome() const { /** Funcao para a entidade User ter acesso ao metodo GetNome da classe Nome @return nome @see GetNome()*/
                return nome;
            }

            void SetTelefone(const Telefone &telefone){  /** Funcao para a entidade User ter acesso ao metodo SetTelefone da classe Telefone @param telefone @see SetTelefone()*/
                this->telefone = telefone;
            }
            Telefone GetTelefone() const { /** Funcao para a entidade User ter acesso ao metodo GetTelefone da classe Telefone @return telefone @see GetTelefone()*/
                return telefone;
            }

            void SetEmail(const Email &email){  /** Funcao para a entidade Email ter acesso ao metodo SetEmail da classe Email @param email @see SetEmail()*/
                this->email = email;
            }
            Email GetEmail() const { /** Funcao para a entidade User ter acesso ao metodo GetEmail da classe Email @return email @see GetEmail()*/
                return email;
            }

            void SetSenha(const Senha &senha){  /** Funcao para a entidade User ter acesso ao metodo SetSenha da classe Senha @param senha @see SetSenha()*/
                this->senha = senha;
            }
            Senha GetSenha() const { /** Funcao para a entidade User ter acesso ao metodo GetSenha da classe Senha @return senha @see GetSenha()*/
                return senha;
            }

            void SetCpf(const Cpf &cpf){  /** Funcao para a entidade User ter acesso ao metodo SetCpf da classe Cpf @param cpf @see SetCpf()*/
                this->cpf = cpf;
            }
            Cpf GetCpf() const { /** Funcao para a entidade User ter acesso ao metodo GetCpf da classe Cpf @return cpf @see GetCpf()*/
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
