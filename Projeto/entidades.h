#ifndef ENTIDADES_H
#define ENTIDADES_H
#include <string>
#include <stdexcept>
#include "dominios.h"
using namespace std;

class User{ /**< /brief Entidade que lida com usuários */
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
            void ReservarCarona(int, int, char); /**< Metodo para reservar uma carona, recebe 2 int e um char e invoca o metodo set de cada um separamente @param codigo, assento, bagagem @see SetCodigoReserva(), SetAssento(), SetBagagem()*/
            void Imprime(); /**< Imprime todos os arumentos da classe Booking */
            void SetCodigoReserva(const CodigoReserva &codigo){ /** Funcao para a entidade Booking ter acesso ao metodo SetCodigoReserva da classe CodigoReserva @param codigo @see SetCodigoReserva()*/ 
                this->codigo = codigo;
            }
            CodigoReserva GetCodigoReserva() const { /** Funcao para a entidade Booking ter acesso ao metodo GetCodigoReserva da classe CodigoReserva @return codigo @see GetCodigoReserva()*/ 
                return codigo;
            }

            void SetAssento(const Assento &assento){ /** Funcao para a entidade Booking ter acesso ao metodo SetAssento da classe Assento @param assento @see SetAssento()*/ 
                this->assento = assento;
            }
            Assento GetAssento() const { /** Funcao para a entidade Booking ter acesso ao metodo GetAssento da classe Assento @return assento @see GetAssento()*/
                return assento;
            }

            void SetBagagem(const Bagagem &bagagem){ /** Funcao para a entidade Booking ter acesso ao metodo SetBagagem da classe Bagagem @param bagagem @see SetBagagem()*/ 
                this->bagagem = bagagem;
            }
            Bagagem GetBagagem() const { /** Funcao para a entidade Booking ter acesso ao metodo GetBagagem da classe Bagagem @return bagagem @see GetBagagem()*/
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
            void CadastrarCarona(int, int, int, string, string, string, string, string, string); /**< Recebe 3 int e 6 strings para efetuar o cadastro de uma carona, chama o Set de cada uma indivudalmente*/
            void Imprime(); /**< Imprime todos os argumentos alocados em memoria da classe Ride */
            void SetCodigoCarona(const CodigoCarona &codigocarona){ /** Funcao para a entidade Ride ter acesso ao metodo SetCodigoCarona da classe CodigoCarona @param codigocarona @see SetCodigoCarona()*/ 
                this->codigocarona = codigocarona;
            }
            CodigoCarona GetCodigoCarona() const { /** Funcao para a entidade Ride ter acesso ao metodo SetCodigoCarona da classe CodigoCarona @param codigocarona @see SetCodigoCarona()*/ 
                return codigocarona;
            }

            void SetCidadeOrigem(const CidadeOrigem &cidadeorigem){ /** Funcao para a entidade Ride ter acesso ao metodo SetCidadeOrigem da classe CidadeOrigem @param cidadeorigem @see SetCidadeOrigem()*/ 
                this->cidadeorigem = cidadeorigem;
            }
            CidadeOrigem GetCidadeOrigem() const { /** Funcao para a entidade Ride ter acesso ao metodo SetCidadeOrigem da classe CidadeOrigem @param cidadeorigem @see SetCidadeOrigem()*/ 
                return cidadeorigem;
            }

            void SetCidadeDestino(const CidadeDestino &cidadedestino){ /** Funcao para a entidade Ride ter acesso ao metodo SetCidadeDestino da classe CidadeDestino @param cidadedestino @see SetCidadeDestino()*/ 
                this->cidadedestino = cidadedestino;
            }
            CidadeDestino GetCidadeDestino() const { /** Funcao para a entidade Ride ter acesso ao metodo SetCidadeDestino da classe CidadeDestino @param cidadedestino @see SetCidadeDestino()*/ 
                return cidadedestino;
            }

            void SetEstadoOrigem(const EstadoOrigem &estadoorigem){ /** Funcao para a entidade Ride ter acesso ao metodo SetEstadoOrigem da classe EstadoOrigem @param estadoorigem @see SetEstadoOrigem()*/ 
                this->estadoorigem = estadoorigem;
            }
            EstadoOrigem GetEstadoOrigem() const { /** Funcao para a entidade Ride ter acesso ao metodo SetEstadoOrigem da classe EstadoOrigem @param estadoorigem @see SetEstadoOrigem()*/ 
                return estadoorigem;
            }

            void SetEstadoDestino(const EstadoDestino &estadodestino){ /** Funcao para a entidade Ride ter acesso ao metodo SetEstadoDestino da classe EstadoDestino @param estadodestino @see SetEstadoDestino()*/ 
                this->estadodestino = estadodestino;
            }
            EstadoDestino GetEstadoDestino() const { /** Funcao para a entidade Ride ter acesso ao metodo SetEstadoDestino da classe EstadoDestino @param estadodestino @see SetEstadoDestino()*/ 
                return estadodestino;
            }

            void SetData(const Data &data){ /** Funcao para a entidade Ride ter acesso ao metodo SetData da classe Data @param data @see SetData()*/ 
                this->data= data;
            }
            Data GetData() const { /** Funcao para a entidade Ride ter acesso ao metodo SetData da classe Data @param data @see SetData()*/ 
                return data;
            }

            void SetPreco(const Preco &preco){ /** Funcao para a entidade Ride ter acesso ao metodo SetPreco da classe Preco @param preco @see SetPreco()*/ 
                this->preco = preco;
            }
            Preco GetPreco() const { /** Funcao para a entidade Ride ter acesso ao metodo SetPreco da classe Preco @param preco @see SetPreco()*/ 
                return preco;
            }

            void SetVagas(const Vagas &vagas){ /** Funcao para a entidade Ride ter acesso ao metodo SetVagas da classe Vagas @param vagas @see SetVagas()*/ 
                this->vagas= vagas;
            }
            Vagas GetVagas() const { /** Funcao para a entidade Ride ter acesso ao metodo SetVagas da classe Vagas @param vagas @see SetVagas()*/ 
                return vagas;
            }

            void SetDuracao(const Duracao &duracao){ /** Funcao para a entidade Ride ter acesso ao metodo SetDuracao da classe Duracao @param duracao @see SetDuracao()*/ 
                this->duracao= duracao;
            }
            Duracao GetDuracao() const { /** Funcao para a entidade Ride ter acesso ao metodo SetDuracao da classe Duracao @param duracao @see SetDuracao()*/ 
                return duracao;
            }
    };

    class Account{
        private:
            Banco banco;
            Agencia agencia;
            Conta conta;
        public:
            void CadastrarInfoBancarias(int, string, string); /**< Recebe um int e duas strings e chama o Set de cada uma @param banco, agencia, conta @see SetBanco(), SetConta(), SetAgencia()*/
            void Imprime();/**< Imprime todos os argumentos armazenados em memoria da classe Account*/
            void SetBanco(const Banco &banco){ /** Funcao para a entidade Account ter acesso ao metodo SetBanco da classe Banco @param banco @see SetBanco()*/
                this->banco = banco;
            }
            Banco GetBanco() const { /** Funcao para a entidade Account ter acesso ao metodo GetBanco da classe Banco @param banco @see GetBanco()*/
                return banco;
            }

            void SetAgencia(const Agencia &agencia){ /** Funcao para a entidade Account ter acesso ao metodo SetAgencia da classe Agencia @param agencia @see SetAgencia()*/
                this->agencia= agencia;
            }
            Agencia GetAgencia() const { /** Funcao para a entidade Account ter acesso ao metodo GetAgencia da classe Agencia @param agencia @see GetAgencia()*/
                return agencia;
            }

            void SetConta(const Conta &conta){ /** Funcao para a entidade Account ter acesso ao metodo SetConta da classe Conta @param conta @see SetConta()*/
                this->conta = conta;
            }
            Conta GetConta() const { /** Funcao para a entidade Account ter acesso ao metodo GetConta da classe Conta @param conta @see GetConta()*/
                return conta;
            }
    };
#endif
