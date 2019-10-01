#ifndef DOMINIOS_H
#define DOMINIOS_H
#include <string>
#include <stdexcept>
using namespace std;

/** \brief Responsavel por armazenar e validar a string nome
    
 */
class Nome{ 
        private:
            string nome;   /**< Armazena o dado recebido por SetNome @see SetNome*/
            string excecao; /**< Armazena a excecao do método Validar, caso haja @see Validar*/
        public:
            int Validar(string) throw (invalid_argument); /**< Valida a string nome recebida do usuário e retorna para SetNome. Nome pode ter até 20 caracteres e não pode haver números @param nome @return excecao*/
            void SetNome(string); /**< Chama o método Validar, se não existir excecao, armazena o dado referente a nome na string nome  @param nome @see Validar*/
            string GetNome(); /**< Retorna a string nome @return nome*/
            string GetExcecao(); /**< Retorna a string excecao */
    };

/** \brief Responsavel por armazenar e validar a string telefone */
    class Telefone{
        private:
            string telefone; /**< Armazena o dado recebido por SetTelefone @see SetTelefone*/ 
            string excecao; /**< Armazena a mensagem de erro do metodo Validar, caso haja @see Validar*/
        public:
            int Validar(string) throw (invalid_argument); /**< Valida a string telefone recebida do usuario e retorna para SetTelefone. A string tem que ter um formato XX-XX-XXXXXXXXX, onde X é número e não pode ser 0 em todos os campos. @param telefone @return excecao*/
            void SetTelefone(string); /**< Chama o metodo Validar, caso não exista erros, armazena o dado referente a telefone na string telefone @param telefone @see Validar*/
            string GetTelefone(); /**< Retorna a string telefone @return telefone*/
            string GetExcecao(); /**< Retorna a string excecao */
    };

/** \brief Responsavel por armazenar e validar a string email*/
    class Email{
        private:
            string email; /**< Armazena o dado recebido por SetEmail @see SetEmail.*/
            string excecao; /**< Armazena a mensagem de erro do metodo validar @see Validar.*/
        public:
            int Validar(string) throw (invalid_argument); /**< Valida a string email recebida do usuario e retorna um erro, caso haja. Email tem formato local@dominio onde local tem, no maximo, 20 caracteres que podem ser letra ou ponto, assim tambem é domínio.*/  
            void SetEmail(string); 
            string GetEmail();
            string GetExcecao();
    };

/** \brief Responsavel por armazenar e validar a string senha*/
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

/** \brief Responsavel por armazenar e validar a string cpf*/
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

/** \brief Responsavel por armazenar e validar o inteiro bagagem */
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

/** \brief Responsavel por armazenar e validar o char assento */
    class Assento{
        private:
            char assento; /**< teste assento*/
            string excecao;
        public:
            int Validar(char) throw (invalid_argument);
            void SetAssento(char);
            char GetAssento();
            string GetExcecao();
    };

/** \brief Responsavel por armazenar e validar o inteiro codigoreserva */
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

/** \brief Responsavel por armazenar e validar o inteiro codigocarona */
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

/** \brief Responsavel por armazenar e validar a string cidadeorigem*/
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

/** \brief Responsavel por armazenar e validar a string cidadedestino*/
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

/** \brief Responsavel por armazenar e validar a string estadoorigem*/
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

/** \brief Responsavel por armazenar e validar a string estadodestino*/
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

/** \brief Responsavel por armazenar e validar a string data*/
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

/** \brief Responsavel por armazenar e validar o inteiro duracao */
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

/** \brief Responsavel por armazenar e validar o inteiro vagas*/
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

/** \brief Responsavel por armazenar e validar a string preco*/
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

/** \brief Responsavel por armazenar e validar o inteiro codigobanco */
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

/** \brief Responsavel por armazenar e validar a string agencia*/
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

/** \brief Responsavel por armazenar e validar a string conta*/
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
