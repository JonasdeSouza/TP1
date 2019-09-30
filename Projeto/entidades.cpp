#include <iostream>
#include <string>
#include <stdexcept>
#include "dominios.h"
#include "entidades.h"
using namespace std;

void User::CadastrarUsuario(string nome, string telefone, string email, string senha, string cpf)
{

    this->nome.SetNome(nome);
    this->telefone.SetTelefone(telefone);
    this->email.SetEmail(email);
    this->senha.SetSenha(senha);
    this->cpf.SetCpf(cpf);

}

void User::Imprime()
{
    string nome1, telefone1, email1, senha1, cpf1;
    nome1 = nome.GetNome();
    telefone1 = telefone.GetTelefone();
    email1 = email.GetEmail();
    senha1 = senha.GetSenha();
    cpf1 = cpf.GetCpf();

    cout << nome1 << "\n" << telefone1 << "\n" << email1 << "\n" << senha1 << "\n" << cpf1;
}

//User::~User()
//{
 //   delete email;
  //  delete telefone;
   // delete nome;
   // delete cpf;
    //delete senha;
//}

void Booking::ReservarCarona(int codigoreserva, int bagagem, char assento)
{

    this->assento.SetAssento(assento);
    this->codigo.SetCodigoReserva(codigoreserva);
    this->bagagem.SetBagagem(bagagem);

}

void Booking::Imprime()
{
    int codreserv, bag;
    char assento1;

    codreserv = codigo.GetCodigoReserva();
    bag = bagagem.GetBagagem();
    assento1 = assento.GetAssento();

    cout << codreserv << "\n" << bag << "\n" << assento1 << "\n";
}

void Ride::CadastrarCarona(int vagas, int duracao, int codigocarona, string cidadeorigem, string estadoorigem, string cidadedestino, string estadodestino, string data, string preco)
{

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

void Ride::Imprime()
{
    int vag, duration, codcarona;
    string cidadorigem, estadorigem, cidaddestino, estaddestino, dataa, precoa;

    vag = vagas.GetVagas();
    duration = duracao.GetDuracao();
    codcarona = codigocarona.GetCodigoCarona();
    cidadorigem = cidadeorigem.GetCidadeOrigem();
    estadorigem = estadoorigem.GetEstadoOrigem();
    cidaddestino = cidadedestino.GetCidadeDestino();
    estaddestino = estadodestino.GetEstadoDestino();
    dataa = data.GetData();
    precoa = preco.GetPreco();

    cout << vag << "\n" << duration << "\n" << codcarona << "\n" << cidadorigem << "\n" << estadorigem << "\n" << cidaddestino << "\n" << estaddestino << "\n" << dataa << "\n" << precoa;
}

void Account::CadastrarInfoBancarias(int codigobanco, string agencia, string conta)
{
    this->banco.SetCodigoBanco(codigobanco);
    this->agencia.SetAgencia(agencia);
    this->conta.SetConta(conta);
}

void Account::Imprime()
{
    int codbanco;
    string agency, acount;

    codbanco = banco.GetCodigoBanco();
    agency = agencia.GetAgencia();
    acount = conta.GetConta();

    cout << "\n" << codbanco << "\n" << agency << "\n" << acount;
}
