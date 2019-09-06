#include <iostream>
#include "user.h"
using namespace std;

void User::CadastrarUsuario(string nome, string telefone, string email, string senha, string cpf){

    this->nome.SetNome(nome);
    this->telefone.SetTelefone(telefone);
    this->email.SetEmail(email);
    this->senha.SetSenha(senha);
    this->cpf.SetCpf(cpf);

}

void User::Imprime(){
    string nome1, telefone1, email1, senha1, cpf1;
    nome1 = nome.GetNome();
    telefone1 = telefone.GetTelefone();
    email1 = email.GetEmail();
    senha1 = senha.GetSenha();
    cpf1 = cpf.GetCpf();

    cout << nome1 << "\n" << telefone1 << "\n" << email1 << "\n" << senha1 << "\n" << cpf1;
}

void Nome::SetNome(string Nome){
    Nome = nome;
}

void Telefone::SetTelefone(string Telefone){
    telefone = Telefone;
}

void Email::SetEmail(string Email){
    email = Email;
}

void Senha::SetSenha(string Senha){
    senha = Senha;
}

void Cpf::SetCpf(string Cpf){
    cpf = Cpf;
}

string Nome::GetNome(){
    return nome;
}

string Telefone::GetTelefone(){
    return telefone;
}

string Email::GetEmail(){
    return email;
}

string Senha::GetSenha(){
    return senha;
}

string Cpf::GetCpf(){
    return cpf;
}

//-----------------------------------------------------------------------------------------

void Booking::ReservarCarona(int codigoreserva, int bagagem, char assento){

    this->assento.SetAssento(assento);
    this->codigo.SetCodigoReserva(codigoreserva);
    this->bagagem.SetBagagem(bagagem);

}

void Booking::Imprime(){
    int codreserv, bag, assento1;

    codreserv = codigo.GetCodigoReserva();
    bag = bagagem.GetBagagem();
    assento1 = assento.GetAssento();

    cout << codreserv << "\n" << bag << "\n" << assento1 << "\n";
}

void Bagagem::SetBagagem(int Bagagem){
    bagagem = Bagagem;
}

void Assento::SetAssento(char Assento){
    assento = Assento;
}

void CodigoReserva::SetCodigoReserva(int Codigo){
    codigoreserva = Codigo;
}

int Bagagem::GetBagagem(){
    return bagagem;
}

char Assento::GetAssento(){
    return assento;
}

int CodigoReserva::GetCodigoReserva(){
    return codigoreserva;
}

//------------------------------------------------------------

void Ride::CadastrarCarona(int vagas, int duracao, int codigocarona, string cidadeorigem, string estadoorigem, string cidadedestino, string estadodestino, string data, string preco){

    this->vagas.SetVagas(vagas);
    this->duracao.SetDuracao(duracao);
    this->codigocarona.SetCodigoCarona(codigocarona);
    this->cidadeorigem.SetCidadeOrigem(cidadeorigem);
    this->estadoorigem.SetEstadoOrigem(estadoorigem);
    this->cidadedestino.SetCidadeDestino(cidadedestino);
    this->estadodestino.SetEstadoDestino(estadodestino);
    this->data.SetData(data);
    this->preco.SetPreco(preco);

}

void Vagas::SetVagas(int Vagas){
    vagas = Vagas;
}

void Duracao::SetDuracao(int Duracao){
    duracao = Duracao;
}

void CodigoCarona::SetCodigoCarona(int CodigoCarona){
    codigocarona = CodigoCarona;
}

void CidadeOrigem::SetCidadeOrigem(string CidadeOrigem){
    cidadeorigem = CidadeOrigem;
}

void CidadeDestino::SetCidadeDestino(string CidadeDestino){
    cidadedestino = CidadeDestino;
}

void EstadoOrigem::SetEstadoOrigem(string EstadoOrigem){
    estadoorigem = EstadoOrigem;
}

void EstadoDestino::SetEstadoDestino(string EstadoDestino){
    estadodestino = EstadoDestino;
}

void Data::SetData(string Data){
    data = Data;
}

void Preco::SetPreco(string Preco){
    preco = Preco;
}

int Vagas::GetVagas(){
    return vagas;
}

int Duracao::GetDuracao(){
    return duracao;
}

int CodigoCarona::GetCodigoCarona(){
    return codigocarona;
}

string CidadeOrigem::GetCidadeOrigem(){
    return cidadeorigem;
}

string CidadeDestino::GetCidadeDestino(){
    return cidadedestino;
}

string EstadoOrigem::GetEstadoOrigem(){
    return estadoorigem;
}

string EstadoDestino::GetEstadoDestino(){
    return estadodestino;
}

string Data::GetData(){
    return data;
}

string Preco::GetPreco(){
    return preco;
}

//-------------------------------------------------------------------------------------------

void Account::CadastrarInfoBancarias(int codigobanco, string agencia, string conta){
    this->banco.SetCodigoBanco(codigobanco);
    this->agencia.SetAgencia(agencia);
    this->conta.SetConta(conta);
}

void Banco::SetCodigoBanco(int CodigoBanco){
    codigobanco = CodigoBanco;
}

void Agencia::SetAgencia(string Agencia){
    agencia = Agencia;
}

void Conta::SetConta(string Conta){
    conta = Conta;
}

int Banco::GetCodigoBanco(){
    return codigobanco;
}

string Agencia::GetAgencia(){
    return agencia;
}

string Conta::GetConta(){
    return conta;
}

