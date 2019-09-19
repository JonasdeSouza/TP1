#include <iostream>
#include <string>
#include <stdexcept>
#include "user.h"
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

void Nome::SetNome(string Nome)
{
    int erro = Validar(Nome);
    if (erro == 0)
    {
        nome = Nome;
    }
}

int Nome::Validar(string Nome) throw (invalid_argument)
{
    int erro= {0}, i;
    try
    {
        if (Nome.size() > 20 ||Nome.size() < 1)
        {
            erro--;
            throw invalid_argument("Nome muito grande\n");
        }
        else if (erro == 0)
        {
            int found = Nome.find('.');
            if (found != -1)
            {
                if (Nome[found-1] <= 'A' || Nome[found-1] >= 'z')
                {
                    erro--;
                    throw invalid_argument("Existencia de ponto em lugar inválido\n");
                }
            }
        }
        else
        {
            int found = Nome.find(' ');
            if (Nome[found] == Nome[found+1])
            {
                erro--;
                throw invalid_argument("Existencia de dois espacos consecutivos\n");
            }
        }
        for(i=0; i<Nome.size(); i++)
        {
            if (Nome[i] <= 'A' || Nome[i] >= 'z')
            {
                erro--;
                throw invalid_argument("Existencia de numeros\n");
            }
        }
    }
    catch (invalid_argument& ErroNome)
    {
        cout << "Erro no campo nome: " << ErroNome.what();
    }
    return erro;
}

void Telefone::SetTelefone(string Telefone)
{
    int erro = Validar(Telefone);
    if (erro == 0)
    {
        telefone = Telefone;
    }
}

int Telefone::Validar(string Telefone) throw (invalid_argument)
{
    int Tamanho= {15};
    int erro= {0};
    try
    {
        if(Telefone.size() != Tamanho)
        {
            erro--;
            throw invalid_argument("Tamanho de Telefone Inválido\n");
        }
        if(Telefone[0] == '0' && Telefone[1] == '0' || Telefone[3] == '0' && Telefone[4] == '0')
        {
            erro--;
            throw invalid_argument("Codigo de pais e/ou DDD igual a zero\n");
        }
        if (Telefone[6] == '0' && Telefone[7] == '0' && Telefone[8] == '0' && Telefone[9] == '0' && Telefone[10] == '0' && Telefone[11] == '0' && Telefone[12] == '0' && Telefone[13] == '0' && Telefone[14] == '0')
        {
            erro--;
            throw invalid_argument("Numero de telefone igual a zero\n");
        }
        if (Telefone[0] < '0' || Telefone[0] > '9' || Telefone[1] < '0' || Telefone[1] > '9' || Telefone[3] < '0' || Telefone[3] > '9' || Telefone[4] < '0' || Telefone[4] > '9' || Telefone[6] < '0' || Telefone[6] > '9' || Telefone[7] < '0' || Telefone[7] > '9' || Telefone[8] < '0' || Telefone[8] > '9' || Telefone[9] < '0' || Telefone[9] > '9' || Telefone[10] < '0' || Telefone[10] > '9' || Telefone[11] < '0' || Telefone[11] > '9' || Telefone[12] < '0' || Telefone[12] > '9' || Telefone[13] < '0' || Telefone[13] > '9' || Telefone[14] < '0' || Telefone[14] > '9')
        {
            erro--;
            throw invalid_argument("Existencia de caracteres diferentes de numeros\n");
        }
    }
    catch (invalid_argument& ErroTelefone)
    {
        cout << "Erro no campo telefone: " << ErroTelefone.what();
    }

}

void Email::SetEmail(string Email)
{
    int erro = Validar(Email);
    if (erro == 0)
    {
        email = Email;
    }
}

int Email::Validar(string Email) throw (invalid_argument)
{
    int TamanhoMax= {20};
    int erro= {0};
    int arroba = Email.find('@');
    int ponto = Email.find('.');
    int i;
    try
    {
        if(Email.size() > 2*TamanhoMax)
        {
            erro--;
            throw invalid_argument("Email muito grande\n");
        }
        else if (arroba == -1 || arroba > TamanhoMax+1)
        {
            erro--;
            throw invalid_argument("Campo local maior que o permitido\n");
        }
        else if (Email[0] == '.' || Email[arroba-1] == '.' || Email[arroba+1] == '.' || Email[ponto+1] == '.')
        {
            erro--;
            throw invalid_argument("Ponto em local invalido ou pontos consecutivos\n");
        }
        for (i=0; i < Email.size(); i++)
        {
            if (Email[i] < 'a' || Email[i] > 'z')
            {
                if (Email[i] != '.' && Email[i] != '@')
                {
                    erro--;
                    throw invalid_argument("Caractere invalido\n");
                }
            }
        }
    }
    catch (invalid_argument& ErroEmail)
    {
        cout << "Erro no campo Email: " << ErroEmail.what();
    }

    return erro;
}


void Senha::SetSenha(string Senha)
{
    int erro = Validar(Senha);
    if(erro == 0)
    {
        senha = Senha;
    }
}

int Senha::Validar(string Senha) throw (invalid_argument)
{
    int erro= {0};
    int i, j;
    int TamanhoMax= {5};
    try
    {
        if(Senha.size() > TamanhoMax)
        {
            erro--;
            throw invalid_argument("Senha muito grande\n");
        }
        for(i=0; i<Senha.size(); i++)
        {
            if(isalnum(Senha[i]) == false)
            {
                if(Senha[i] != '#' || Senha[i] != '$' || Senha[i] != '%' || Senha[i] != '&')
                {
                    erro--;
                    throw invalid_argument("Caractere invalido");
                }
            }
            for(j=i+1; j<Senha.size(); j++)
            {
                if(Senha[i] == Senha[j])
                {
                    erro--;
                    throw invalid_argument("Caracteres repetidos");
                }
            }
        }
    }

    catch (invalid_argument& ErroSenha)
    {
        cout << "Erro no campo Senha: " << ErroSenha.what();
    }
    return erro;
}

void Cpf::SetCpf(string Cpf)
{
    cpf = Cpf;
}

string Nome::GetNome()
{
    return nome;
}

string Telefone::GetTelefone()
{
    return telefone;
}

string Email::GetEmail()
{
    return email;
}

string Senha::GetSenha()
{
    return senha;
}

string Cpf::GetCpf()
{
    return cpf;
}

//-----------------------------------------------------------------------------------------

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

void Bagagem::SetBagagem(int Bagagem)
{
    bagagem = Bagagem;
}

void Assento::SetAssento(char Assento)
{
    assento = Assento;
}

void CodigoReserva::SetCodigoReserva(int Codigo)
{
    codigoreserva = Codigo;
}

int Bagagem::GetBagagem()
{
    return bagagem;
}

char Assento::GetAssento()
{
    return assento;
}

int CodigoReserva::GetCodigoReserva()
{
    return codigoreserva;
}

//------------------------------------------------------------

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

void Vagas::SetVagas(int Vagas)
{
    vagas = Vagas;
}

void Duracao::SetDuracao(int Duracao)
{
    duracao = Duracao;
}

void CodigoCarona::SetCodigoCarona(int CodigoCarona)
{
    codigocarona = CodigoCarona;
}

void CidadeOrigem::SetCidadeOrigem(string CidadeOrigem)
{
    cidadeorigem = CidadeOrigem;
}

void CidadeDestino::SetCidadeDestino(string CidadeDestino)
{
    cidadedestino = CidadeDestino;
}

void EstadoOrigem::SetEstadoOrigem(string EstadoOrigem)
{
    estadoorigem = EstadoOrigem;
}

void EstadoDestino::SetEstadoDestino(string EstadoDestino)
{
    estadodestino = EstadoDestino;
}

void Data::SetData(string Data)
{
    data = Data;
}

void Preco::SetPreco(string Preco)
{
    preco = Preco;
}

int Vagas::GetVagas()
{
    return vagas;
}

int Duracao::GetDuracao()
{
    return duracao;
}

int CodigoCarona::GetCodigoCarona()
{
    return codigocarona;
}

string CidadeOrigem::GetCidadeOrigem()
{
    return cidadeorigem;
}

string CidadeDestino::GetCidadeDestino()
{
    return cidadedestino;
}

string EstadoOrigem::GetEstadoOrigem()
{
    return estadoorigem;
}

string EstadoDestino::GetEstadoDestino()
{
    return estadodestino;
}

string Data::GetData()
{
    return data;
}

string Preco::GetPreco()
{
    return preco;
}

//-------------------------------------------------------------------------------------------

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

void Banco::SetCodigoBanco(int CodigoBanco)
{
    codigobanco = CodigoBanco;
}

void Agencia::SetAgencia(string Agencia)
{
    agencia = Agencia;
}

void Conta::SetConta(string Conta)
{
    conta = Conta;
}

int Banco::GetCodigoBanco()
{
    return codigobanco;
}

string Agencia::GetAgencia()
{
    return agencia;
}

string Conta::GetConta()
{
    return conta;
}

