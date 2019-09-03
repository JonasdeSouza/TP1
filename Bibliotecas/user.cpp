#include "user.h"
using namespace std;

void Usuario::SetNome(string Nome){
    this->Nome = Nome;
}

void Usuario::SetTelefone(string Telefone){
    this->Telefone = Telefone;
}

void Usuario::SetEmail(string Email){
    this->Email = Email;
}

void Usuario::SetSenha(string Senha){
    this->Senha = Senha;
}

void Usuario::SetCpf(string Cpf){
    this->Cpf = Cpf;
}

string Usuario::GetNome(){
    return this->Nome;
}

string Usuario::GetTelefone(){
    return this->Telefone;
}

string Usuario::GetEmail(){
    return this->Email;
}

string Usuario::GetSenha(){
    return this->Senha;
}

string Usuario::GetCpf(){
    return this->Cpf;
}
