#include <iostream>
#include <string>
#include <stdexcept>
#include "dominios.h"
#include "testehuehuebr.h"
using namespace std;

void TUAssento::SetUp(){
    assento = new Assento();
    estado = SUCESSO;
}

void TUAssento::TearDown(){
    delete assento;
}

string TUAssento::GetExcecao()
{
    return excecao;
}

void TUAssento::TestarCenarioSucesso(){
    try
    {
        assento->SetAssento(VALOR_VALIDO);
        if (assento->GetAssento() != VALOR_VALIDO){
            estado = FALHA;
            excecao = assento->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUAssento::TestarCenarioFalha(){
    try{
        assento->SetAssento(VALOR_INVALIDO);
        if(assento->GetAssento() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = assento->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUAssento::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUBagagem::SetUp(){
    bagagem = new Bagagem();
    estado = SUCESSO;
}

void TUBagagem::TearDown(){
    delete bagagem;
}

string TUBagagem::GetExcecao()
{
    return excecao;
}

void TUBagagem::TestarCenarioSucesso(){
    try
    {
        bagagem->SetBagagem(VALOR_VALIDO);
        if (bagagem->GetBagagem() != VALOR_VALIDO){
            estado = FALHA;
            excecao = bagagem->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUBagagem::TestarCenarioFalha(){
    try{
        bagagem->SetBagagem(VALOR_INVALIDO);
        if(bagagem->GetBagagem() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = bagagem->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUBagagem::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUCodigoBanco::SetUp(){
    codigo = new Banco();
    estado = SUCESSO;
}

void TUCodigoBanco::TearDown(){
    delete codigo;
}

string TUCodigoBanco::GetExcecao()
{
    return excecao;
}

void TUCodigoBanco::TestarCenarioSucesso(){
    try
    {
        codigo->SetCodigoBanco(VALOR_VALIDO);
        if (codigo->GetCodigoBanco() != VALOR_VALIDO){
            estado = FALHA;
            excecao = codigo->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUCodigoBanco::TestarCenarioFalha(){
    try{
        codigo->SetCodigoBanco(VALOR_INVALIDO);
        if(codigo->GetCodigoBanco() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = codigo->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUCodigoBanco::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUCodigoCarona::SetUp(){
    codigo = new CodigoCarona();
    estado = SUCESSO;
}

void TUCodigoCarona::TearDown(){
    delete codigo;
}

string TUCodigoCarona::GetExcecao()
{
    return excecao;
}

void TUCodigoCarona::TestarCenarioSucesso(){
    try
    {
        codigo->SetCodigoCarona(VALOR_VALIDO);
        if (codigo->GetCodigoCarona() != VALOR_VALIDO){
            estado = FALHA;
            excecao = codigo->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUCodigoCarona::TestarCenarioFalha(){
    try{
        codigo->SetCodigoCarona(VALOR_INVALIDO);
        if(codigo->GetCodigoCarona() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = codigo->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUCodigoCarona::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUCodigoReserva::SetUp(){
    codigo = new CodigoReserva();
    estado = SUCESSO;
}

void TUCodigoReserva::TearDown(){
    delete codigo;
}

string TUCodigoReserva::GetExcecao()
{
    return excecao;
}

void TUCodigoReserva::TestarCenarioSucesso(){
    try
    {
        codigo->SetCodigoReserva(VALOR_VALIDO);
        if (codigo->GetCodigoReserva() != VALOR_VALIDO){
            estado = FALHA;
            excecao = codigo->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUCodigoReserva::TestarCenarioFalha(){
    try{
        codigo->SetCodigoReserva(VALOR_INVALIDO);
        if(codigo->GetCodigoReserva() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = codigo->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUCodigoReserva::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUCidadeOrigem::SetUp(){
    cidadeorigem = new CidadeOrigem();
    estado = SUCESSO;
}

void TUCidadeOrigem::TearDown(){
    delete cidadeorigem;
}

string TUCidadeOrigem::GetExcecao()
{
    return excecao;
}

void TUCidadeOrigem::TestarCenarioSucesso(){
    try
    {
        cidadeorigem->SetCidadeOrigem(VALOR_VALIDO);
        if (cidadeorigem->GetCidadeOrigem() != VALOR_VALIDO){
            estado = FALHA;
            excecao = cidadeorigem->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUCidadeOrigem::TestarCenarioFalha(){
    try{
        cidadeorigem->SetCidadeOrigem(VALOR_INVALIDO);
        if(cidadeorigem->GetCidadeOrigem() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = cidadeorigem->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUCidadeOrigem::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUCidadeDestino::SetUp(){
    cidadedestino = new CidadeDestino();
    estado = SUCESSO;
}

void TUCidadeDestino::TearDown(){
    delete cidadedestino;
}

string TUCidadeDestino::GetExcecao()
{
    return excecao;
}

void TUCidadeDestino::TestarCenarioSucesso(){
    try
    {
        cidadedestino->SetCidadeDestino(VALOR_VALIDO);
        if (cidadedestino->GetCidadeDestino() != VALOR_VALIDO){
            estado = FALHA;
            excecao = cidadedestino->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUCidadeDestino::TestarCenarioFalha(){
    try{
        cidadedestino->SetCidadeDestino(VALOR_INVALIDO);
        if(cidadedestino->GetCidadeDestino() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = cidadedestino->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUCidadeDestino::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUCpf::SetUp(){
    cpf = new Cpf();
    estado = SUCESSO;
}

void TUCpf::TearDown(){
    delete cpf;
}

string TUCpf::GetExcecao()
{
    return excecao;
}

void TUCpf::TestarCenarioSucesso(){
    try
    {
        cpf->SetCpf(VALOR_VALIDO);
        if (cpf->GetCpf() != VALOR_VALIDO){
            estado = FALHA;
            excecao = cpf->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUCpf::TestarCenarioFalha(){
    try{
        cpf->SetCpf(VALOR_INVALIDO);
        if(cpf->GetCpf() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = cpf->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUCpf::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUData::SetUp(){
    data = new Data();
    estado = SUCESSO;
}

void TUData::TearDown(){
    delete data;
}

string TUData::GetExcecao()
{
    return excecao;
}

void TUData::TestarCenarioSucesso(){
    try
    {
        data->SetData(VALOR_VALIDO);
        if (data->GetData() != VALOR_VALIDO){
            estado = FALHA;
            excecao = data->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUData::TestarCenarioFalha(){
    try{
        data->SetData(VALOR_INVALIDO);
        if(data->GetData() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = data->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUData::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUDuracao::SetUp(){
    duracao = new Duracao();
    estado = SUCESSO;
}

void TUDuracao::TearDown(){
    delete duracao;
}

string TUDuracao::GetExcecao()
{
    return excecao;
}

void TUDuracao::TestarCenarioSucesso(){
    try
    {
        duracao->SetDuracao(VALOR_VALIDO);
        if (duracao->GetDuracao() != VALOR_VALIDO){
            estado = FALHA;
            excecao = duracao->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUDuracao::TestarCenarioFalha(){
    try{
        duracao->SetDuracao(VALOR_INVALIDO);
        if(duracao->GetDuracao() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = duracao->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUDuracao::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUEstadoOrigem::SetUp(){
    estadoorigem = new EstadoOrigem();
    estado = SUCESSO;
}

void TUEstadoOrigem::TearDown(){
    delete estadoorigem;
}

string TUEstadoOrigem::GetExcecao()
{
    return excecao;
}

void TUEstadoOrigem::TestarCenarioSucesso(){
    try
    {
        estadoorigem->SetEstadoOrigem(VALOR_VALIDO);
        if (estadoorigem->GetEstadoOrigem() != VALOR_VALIDO){
            estado = FALHA;
            excecao = estadoorigem->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUEstadoOrigem::TestarCenarioFalha(){
    try{
        estadoorigem->SetEstadoOrigem(VALOR_INVALIDO);
        if(estadoorigem->GetEstadoOrigem() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = estadoorigem->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUEstadoOrigem::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUEstadoDestino::SetUp(){
    estadodestino = new EstadoDestino();
    estado = SUCESSO;
}

void TUEstadoDestino::TearDown(){
    delete estadodestino;
}

string TUEstadoDestino::GetExcecao()
{
    return excecao;
}

void TUEstadoDestino::TestarCenarioSucesso(){
    try
    {
        estadodestino->SetEstadoDestino(VALOR_VALIDO);
        if (estadodestino->GetEstadoDestino() != VALOR_VALIDO){
            estado = FALHA;
            excecao = estadodestino->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUEstadoDestino::TestarCenarioFalha(){
    try{
        estadodestino->SetEstadoDestino(VALOR_INVALIDO);
        if(estadodestino->GetEstadoDestino() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = estadodestino->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUEstadoDestino::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUEmail::SetUp(){
    email = new Email();
    estado = SUCESSO;
}

void TUEmail::TearDown(){
    delete email;
}

string TUEmail::GetExcecao()
{
    return excecao;
}

void TUEmail::TestarCenarioSucesso(){
    try
    {
        email->SetEmail(VALOR_VALIDO);
        if (email->GetEmail() != VALOR_VALIDO){
            estado = FALHA;
            excecao = email->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUEmail::TestarCenarioFalha(){
    try{
        email->SetEmail(VALOR_INVALIDO);
        if(email->GetEmail() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = email->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUEmail::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUNome::SetUp(){
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::TearDown(){
    delete nome;
}

string TUNome::GetExcecao()
{
    return excecao;
}

void TUNome::TestarCenarioSucesso(){
    try
    {
        nome->SetNome(VALOR_VALIDO);
        if (nome->GetNome() != VALOR_VALIDO){
            estado = FALHA;
            excecao = nome->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUNome::TestarCenarioFalha(){
    try{
        nome->SetNome(VALOR_INVALIDO);
        if(nome->GetNome() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = nome->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUNome::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUAgencia::SetUp(){
    agencia = new Agencia();
    estado = SUCESSO;
}

void TUAgencia::TearDown(){
    delete agencia;
}

string TUAgencia::GetExcecao()
{
    return excecao;
}

void TUAgencia::TestarCenarioSucesso(){
    try
    {
        agencia->SetAgencia(VALOR_VALIDO);
        if (agencia->GetAgencia() != VALOR_VALIDO){
            estado = FALHA;
            excecao = agencia->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUAgencia::TestarCenarioFalha(){
    try{
        agencia->SetAgencia(VALOR_INVALIDO);
        if(agencia->GetAgencia() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = agencia->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUAgencia::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUConta::SetUp(){
    numero = new Conta();
    estado = SUCESSO;
}

void TUConta::TearDown(){
    delete numero;
}

string TUConta::GetExcecao()
{
    return excecao;
}

void TUConta::TestarCenarioSucesso(){
    try
    {
        numero->SetConta(VALOR_VALIDO);
        if (numero->GetConta() != VALOR_VALIDO){
            estado = FALHA;
            excecao = numero->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUConta::TestarCenarioFalha(){
    try{
        numero->SetConta(VALOR_INVALIDO);
        if(numero->GetConta() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = numero->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUConta::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUPreco::SetUp(){
    preco = new Preco();
    estado = SUCESSO;
}

void TUPreco::TearDown(){
    delete preco;
}

string TUPreco::GetExcecao()
{
    return excecao;
}

void TUPreco::TestarCenarioSucesso(){
    try
    {
        preco->SetPreco(VALOR_VALIDO);
        if (preco->GetPreco() != VALOR_VALIDO){
            estado = FALHA;
            excecao = preco->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUPreco::TestarCenarioFalha(){
    try{
        preco->SetPreco(VALOR_INVALIDO);
        if(preco->GetPreco() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = preco->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUPreco::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUTelefone::SetUp(){
    telefone = new Telefone();
    estado = SUCESSO;
}

void TUTelefone::TearDown(){
    delete telefone;
}

string TUTelefone::GetExcecao()
{
    return excecao;
}

void TUTelefone::TestarCenarioSucesso(){
    try
    {
        telefone->SetTelefone(VALOR_VALIDO);
        if (telefone->GetTelefone() != VALOR_VALIDO){
            estado = FALHA;
            excecao = telefone->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUTelefone::TestarCenarioFalha(){
    try{
        telefone->SetTelefone(VALOR_INVALIDO);
        if(telefone->GetTelefone() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = telefone->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUTelefone::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUSenha::SetUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::TearDown(){
    delete senha;
}

string TUSenha::GetExcecao()
{
    return excecao;
}

void TUSenha::TestarCenarioSucesso(){
    try
    {
        senha->SetSenha(VALOR_VALIDO);
        if (senha->GetSenha() != VALOR_VALIDO){
            estado = FALHA;
            excecao = senha->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUSenha::TestarCenarioFalha(){
    try{
        senha->SetSenha(VALOR_INVALIDO);
        if(senha->GetSenha() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = senha->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUSenha::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}

void TUVagas::SetUp(){
    vagas = new Vagas();
    estado = SUCESSO;
}

void TUVagas::TearDown(){
    delete vagas;
}

string TUVagas::GetExcecao()
{
    return excecao;
}

void TUVagas::TestarCenarioSucesso(){
    try
    {
        vagas->SetVagas(VALOR_VALIDO);
        if (vagas->GetVagas() != VALOR_VALIDO){
            estado = FALHA;
            excecao = vagas->GetExcecao();
        }
    }
    catch(invalid_argument excecao)
    {
        estado = FALHA;
    }
    
}

void TUVagas::TestarCenarioFalha(){
    try{
        vagas->SetVagas(VALOR_INVALIDO);
        if(vagas->GetVagas() == VALOR_INVALIDO){
            estado = FALHA;        
            excecao = vagas->GetExcecao();
        }
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

int TUVagas::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}