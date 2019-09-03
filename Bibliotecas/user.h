#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class Usuario {
    private:
        string Nome, Telefone, Email, Senha, Cpf;

    public:

        void SetNome(string Nome);
        string GetNome();

        void SetTelefone(string Telefone);
        string GetTelefone();

        void SetEmail(string Email);
        string GetEmail();

        void SetSenha(string Senha);
        string GetSenha();

        void SetCpf(string Cpf);
        string GetCpf();


};

#endif
