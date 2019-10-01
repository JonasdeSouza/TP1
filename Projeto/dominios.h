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
            void SetNome(string); /**< Invoca o método Validar, se não existir excecao, armazena o dado referente a nome na string nome  @param nome @see Validar*/
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
            void SetTelefone(string); /**< Invoca o metodo Validar, caso não exista erros, armazena o dado referente a telefone na string telefone @param telefone @see Validar*/
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
            void SetEmail(string); /**< Invoca o metodo validar, caso nao exista erros, armazena o dado referente a email na string email @param email @see Validar @see email*/             
            string GetEmail(); /**< Retorna a string email @return email */
            string GetExcecao(); /**< Retorna a string excecao @return excecao @see Validar*/
    };

/** \brief Responsavel por armazenar e validar a string senha*/
    class Senha{
        private:
            string senha; /**< Armazena o dado recebido por SetSenha @see SetSenha*/
            string excecao; /**< Armazena a mensagem de erro retornada por Validar, se houver @see Validar*/
        public:
            int Validar(string) throw (invalid_argument); /**< Valida o dado recebido por SetSenha, onde senha tem formato XXXXX e X pode ser alfanumérico, #, $, % ou & @see SetSenha @return excecao*/ 
            void SetSenha(string); /**< Invoca o metodo Validar, e espera o retorno, caso não haja excecao lançada, armazena o dado referente a senha na string senha @see Validar @param senha */
            string GetSenha();  /**< Retorna a string senha @return senha*/
            string GetExcecao(); /**< Retorna a string excecao @return excecao */
    };

/** \brief Responsavel por armazenar e validar a string cpf*/
    class Cpf{
        private:
            string cpf; /**< Armazena o dado recebido por SetCpf @see SetCpf*/
            string excecao; /**< Armazena a mensagem de erro retornada por Validar, se houver @see Validar*/
        public:
            int Validar(string) throw (invalid_argument); /**< Valida o dado recebido por SetCpf, onde Cpf tem o formato XXX.XXX.XXX-XX e X é numerico*/ 
            int ValidarDigitoVerificador(string) throw (invalid_argument); /**< Valida o digito verificador via algoritmo Modulo 11 */
            void SetCpf(string);  /**< Invoca o metodo Validar, e espera o retorno, caso não haja excecao lançada, armazena o dado referente a cpf na string cpf @see Validar @param cpf */
            string GetCpf(); /**< Retorna a string cpf @return cpf*/
            string GetExcecao(); /**< Retorna a string argumento @return argumento*/
    };


//-----------------------------------------------------------------------------------------------

/** \brief Responsavel por armazenar e validar o inteiro bagagem */
    class Bagagem {
        private:
            int bagagem; /**< Armazena o dado recebido por SetBagagem @see SetBagagem*/
            string excecao; /**< Armazena a mensagem de erro retornada por Validar, se houver @see Validar*/

        public:
            int Validar(int) throw (invalid_argument); /**< Valida o dado recebido por SetBagagem, onde bagagem pode ser numerico até 4 @see Validar @param bagagem @return excecao*/ 
            void SetBagagem(int); /**< Invoca o metodo Validar, caso nao haja excecao, armazena o dado referente a quantidade de bagagens no inteiro bagagem @see Validar @param bagagem*/
            int GetBagagem(); /**< Retorna o inteiro bagagem @return bagagem*/
            string GetExcecao(); /**< Retorna a string argumento @return argumento*/
    };

/** \brief Responsavel por armazenar e validar o char assento */
    class Assento{
        private:
            char assento; /**< Armazena o dado recebido por SetAssento @see SetAssento */
            string excecao; /**< Armazena a mensagem de erro retornada por Validar, se houver @see Validar*/
        public:
            int Validar(char) throw (invalid_argument); /**< Valida o dado recebido por SetAssento, somente assume a forma de char 'T' ou 'D' @see SetAssento @param assento @return excecao*/
            void SetAssento(char); /**< Invoca o metodo Validar, caso não haja lançamento de excecao, armazena o dado referente a preferencia de assento no char assento @see Validar @param assento*/ 
            char GetAssento(); /**< Retorna o char assento @return assento*/
            string GetExcecao();  /**< Retorna a string argumento @return argumento*/
    };

/** \brief Responsavel por armazenar e validar o inteiro codigoreserva */
    class CodigoReserva{
        private:
            int codigoreserva; 
            string excecao;
        public:
            int Validar(int) throw (invalid_argument); /**< Valida o dado recebido por SetCodigoReserva, formatado em XXXXX, onde X é número @param codigoreserva @return excecao @see SetCodigoReserva*/
            void SetCodigoReserva(int); /**< Invoca o metodo Validar, caso não haja erro, armazena o dado referente a código de reserva, em um inteiro codigoreserva @param codigoreserva @see Validar*/
            int GetCodigoReserva(); /**< Retorna o valor do inteiro codigoreserva @return codigoreserva*/
            string GetExcecao(); /**< Retorna o valor da string excecao @return excecao, onde fica alocada a excecao lancada pelo metodo Validar @see Validar*/
    };

//-----------------------------------------------------------------------------------------------------

/** \brief Responsavel por armazenar e validar o inteiro codigocarona */
    class CodigoCarona{
        private:
            int codigocarona; 
            string excecao;
        public:
            int Validar(int) throw (invalid_argument); /**< Valida o dado recebido por SetCodigoCarona, onde codigocarona esta formatado como XXXX, onde X é número @see SetCodigoCarona @param codigocarona @return excecao onde ficam alocados as excecoes do metodo*/
            void SetCodigoCarona(int); /**< Invoca o metodo Validar, se nao houver excecoes, armazena em um inteiro o valor referente a codigo de carona @see Validar @param codigocarona*/
            int GetCodigoCarona(); /**< Retorna o valor de codigocarona @return codigocarona um inteiro que guarda o valor validado de SetCodigoCarona*/ 
            string GetExcecao(); /**< Retorna a string excecao @return excecao */
    };

/** \brief Responsavel por armazenar e validar a string cidadeorigem*/
    class CidadeOrigem{
        private:
            string cidadeorigem;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument); /**< Valida a string cidadeorigem recebida por SetCidadeOrigem, onde cidadeorigem pode ter ate 10 caracteres que podem ser: letra, ponto ou espaco @param cidadeorigem @return excecao @see SetCidadeOrigem */ 
            void SetCidadeOrigem(string); /**< Invoca o metodo Validar, se nao houver excecoes, armazena o dado referente a cidade de origem na string cidadeorigem @param cidadeorigem @see Validar*/
            string GetCidadeOrigem(); /**< Retorna a string cidadeorigem @return cidadeorigem*/
            string GetExcecao(); /**< Retorna a string excecao @return excecao string onde fica alocada a mensagem de erro lancada pelo metodo Validar @see Validar*/
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

    class Data{
        private:
            string data;
            string excecao;
        public:
            int Validar(string) throw (invalid_argument);
            /** Metodo para validacao da data
             *. retornando 0 em caso de sucesso e -1 em
             *  caso de falha.
             *
             * \param string Data.
             * \return int 0 para sucesso -1 para falha.
             *
             */
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
            /** Metodo para validacao da duracao
             *. retornando 0 em caso de sucesso e -1 em
             *  caso de falha.
             *
             * \param string Duracao co trajeto.
             * \return int 0 para sucesso -1 para falha.
             *
             */
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
            /** Metodo para validacao do numero de vagas
             *. retornando 0 em caso de sucesso e -1 em
             *  caso de falha.
             *
             * \param string Numero de vagas.
             * \return int 0 para sucesso -1 para falha.
             *
             */
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
            /** Metodo para validacao do preco do trajeto
             *. retornando 0 em caso de sucesso e -1 em
             *  caso de falha.
             *
             * \param string Preco do trajeto.
             * \return int 0 para sucesso -1 para falha.
             *
             */
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
            /** \brief A classe banco e responsavel por armazenar o codigo de banco financeiro.
             *
             *  Codigo de Banco: sequancia de 3 digitos numericos de 0-9 usados para
             *  identificar qual o banco do usuario.
             */

            int Validar(int) throw (invalid_argument);
            /** Metodo para validacao do codigo do banco financeiro
             *. retornando 0 em caso de sucesso e -1 em
             *  caso de falha.
             *
             * \param string Numero do codigo financeiro.
             * \return int 0 para sucesso -1 para falha.
             *
             */
            void SetCodigoBanco(int);
            /** \brief Metodo responsavel por armazenar o codigo
              *   do banco financeiro caso seja valido.
              *
              * \param Numero do banco financeiro.
              */
            int GetCodigoBanco();
            /** \brief Metodo responsavel por retornar o codigo do banco financeiro.
             *
             * \return Numero do banco financeiro armazenado.
             */
            string GetExcecao();
            /** \brief Metodo responsavel por retornar o erro que foi
             *  encontrado ao fazer a validacao do codigo do banco
             *  financeiro.
             *
             * \return Erro de validacao.
             *
             */
    };

    class Agencia{
        private:
            string agencia;
            string excecao;
        public:
            /** \brief A classe Agencia e responsavel por armazenar o numero da agencia do banco.
             *
             *  Numero da agencia do banco: representa uma sequencia de 5 digitos numericos
             *  de 0 ate 9 usados para identificar a agencia do banco do usuario.
             *  O ultimo digito e um digito verificador calculado pelo algoritmo
             *  de Luhn e e separado pelo caractere "-".
             */

            int Validar(string) throw (invalid_argument);
            /** \brief Metodo para validacao do numero da agencia
             *. do banco retornando 0 em caso de sucesso e -1 em
             *  caso de falha.
             *
             * \param string Numero da agencia do banco.
             * \return int 0 para sucesso -1 para falha.
             *
             */
            void SetAgencia(string);
            /** \brief Metodo responsavel por armazenar o numero
              *   da agencia do banco caso seja valido.
              *
              * \param Numero da agencia do banco.
              */
            string GetAgencia();
            /** \brief Metodo responsavel por retornar o numero da agencia do banco.
             *
             * \return Numero da agencia do banco armazenado.
             */
            string GetExcecao();
            /** \brief Metodo responsavel por retornar o erro que foi
             *  encontrado ao fazer a validacao do numero da agencia do
             *  banco.
             *
             * \return Erro de validacao.
             *
             */
    };

    class Conta{
        private:
            string conta;
            string excecao;
        public:
            /** \brief A classe conta e responsavel por armazenar o numero da conta bancaria.
            *
            *  Numero da conta: representa uma sequencia de 7 digitos numericos
            *  de 0 ate 9 usados para identificar a conta bancaria do usuario.
            *  O ultimo digito e um digito verificador calculado pelo algoritmo
            *  de Luhn e e separado pelo caractere "-".
            */
            int Validar(string) throw (invalid_argument);
            /** \brief Metodo para validacao do numero da
             *. conta bancaria retornando 0 em caso de
             *  sucesso e -1 em caso de falha.
             *
             * \param Numero da conta bancaria.
             * \return 0 para sucesso -1 para falha.
             *
             */
            void SetConta(string);
             /** \brief Metodo responsavel por armazenar o numero
              *   da conta bancaria caso seja valido.
              *
              * \param Numero da conta bancaria.
              */
            string GetConta();
            /** \brief Metodo responsavel por retornar o numero da conta bancaria.
             *
             * \return Numero da conta armazenado.
             */
            string GetExcecao();
            /** \brief Metodo responsavel por retornar o erro que foi
             *  encontrado ao fazer a validacao do numero da conta
             *  bancaria.
             *
             * \return Erro de validacao.
             *
             */
    };

#endif
