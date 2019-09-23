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
    } else (cout << "Erro no campo Usuario: " << argumento);
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
                    throw invalid_argument("Existencia de ponto em lugar invalido\n");
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
            if (Nome[i] < 'A' || Nome[i] > 'z')
            {
                if(Nome[i] != ' ')
                {
                    erro--;
                    throw invalid_argument("Existencia de numeros\n");
                }
            }
        }
    }
    catch (invalid_argument& ErroNome)
    {
        argumento = ErroNome.what();
    }
    return erro;
}

void Telefone::SetTelefone(string Telefone)
{
    int validar = Validar(Telefone);
    if (validar == 0)
    {
        telefone = Telefone;
    } else (cout << "Erro no campo Usuario: " << argumento);
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
            throw invalid_argument("Tamanho de Telefone Invalido\n");
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
        argumento = ErroTelefone.what();
    }
    return erro;
}

void Email::SetEmail(string Email)
{
    int erro = Validar(Email);
    if (erro == 0)
    {
        email = Email;
    } else (cout << "Erro no campo Usuario: " << argumento);
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
        argumento = ErroEmail.what();
    }

    return erro;
}


void Senha::SetSenha(string Senha)
{
    int erro = Validar(Senha);
    if(erro == 0)
    {
        senha = Senha;
    } else (cout << "Erro no campo Usuario: " << argumento);
}

int Senha::Validar(string Senha) throw (invalid_argument)
{
    int erro= {0};
    int i, j;
    int TamanhoMax= {5};
    try
    {
        if(Senha.size() != TamanhoMax)
        {
            erro--;
            throw invalid_argument("Senha com tamanho invalido\n");
        }
        for(i=0; i<Senha.size(); i++)
        {
            if(Senha[i] < 'A' || Senha[i] > 'z' )
            {
                if(Senha[i] < '0' || Senha[i] > '9')
                {
                    if(Senha[i] != '#')
                    {
                        if(Senha[i] != '$')
                        {
                            if(Senha[i] != '%')
                            {
                                if(Senha[i] != '&')
                                {
                                    erro--;
                                    throw invalid_argument("Caractere invalido\n");
                                }
                            }
                        }
                    }

                }
            }
            for(j=i+1; j<Senha.size(); j++)
            {
                if(Senha[i] == Senha[j])
                {
                    erro--;
                    throw invalid_argument("Caracteres repetidos\n");
                }
            }
        }
    }

    catch (invalid_argument& ErroSenha)
    {
        argumento = ErroSenha.what();
    }
    return erro;
}

void Cpf::SetCpf(string Cpf)
{
    int validar = Validar(Cpf);
    if(validar == 0)
    {
        cpf = Cpf;
    } else (cout << "Erro no campo Usuario: " << argumento);
}

int Cpf::Validar(string Cpf) throw (invalid_argument)
{
    int TamanhoPermitido = {14};
    int erro= {0};
    try
    {
        erro = ValidarDigitoVerificador(Cpf);
        if(Cpf.size() != TamanhoPermitido)
        {
            erro--;
            throw invalid_argument("Tamanho invalido");
        }
        if(Cpf[3] != '.' || Cpf[7] != '.' || Cpf[11] != '-')
        {
            erro--;
            throw invalid_argument("CPF com formatacao invalida");
        }

    }
    catch (invalid_argument& ErroCpf)
    {
        argumento = ErroCpf.what();
    }
    return erro;
}

int Cpf::ValidarDigitoVerificador(string Cpf) throw (invalid_argument)
{
    int PrimeiroDigito= {0}, SegundoDigito= {0}, i, j, erro= {0}, ConverterAscii= {48};
    string CpfNumericoSemDigitoVerificador, DigitoVerificador;

    try
    {
        CpfNumericoSemDigitoVerificador = Cpf;
        CpfNumericoSemDigitoVerificador.erase(3,1);
        CpfNumericoSemDigitoVerificador.erase(6,1);
        CpfNumericoSemDigitoVerificador.erase(9);
        DigitoVerificador = Cpf;
        DigitoVerificador.erase(0, 12);

        j= CpfNumericoSemDigitoVerificador.size()+1;
        for(i=0; i< CpfNumericoSemDigitoVerificador.size(); i++)
        {
            PrimeiroDigito += (CpfNumericoSemDigitoVerificador[i]-ConverterAscii)*j;
            j--;
        }
        PrimeiroDigito = ((PrimeiroDigito*10)%11)+ConverterAscii;
        if(PrimeiroDigito == Cpf[12])
        {
            CpfNumericoSemDigitoVerificador.insert(CpfNumericoSemDigitoVerificador.end(), PrimeiroDigito);
        }
        else
        {
            erro--;
            throw (invalid_argument("CPF invalido\n"));
        }
        j= CpfNumericoSemDigitoVerificador.size()+1;
        for(i=0; i< CpfNumericoSemDigitoVerificador.size(); i++)
        {
            SegundoDigito += (CpfNumericoSemDigitoVerificador[i]-ConverterAscii)*j;
            j--;
        }
        SegundoDigito = ((SegundoDigito*10)%11)+ConverterAscii;
        if(SegundoDigito == Cpf[13])
        {
            CpfNumericoSemDigitoVerificador.insert(CpfNumericoSemDigitoVerificador.end(), SegundoDigito);
        }
        else
        {
            erro--;
            throw (invalid_argument("CPF invalido\n"));
        }
    }
    catch (invalid_argument& VerificaCpf)
    {
        argumento = VerificaCpf.what();
    }
    return erro;
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
    int validar = Validar(Bagagem);
    if (validar == 0){
        bagagem = Bagagem;
    } else (cout << "Erro no campo Reserva: " << argumento);
}

int Bagagem::Validar(int Bagagem) throw (invalid_argument)
{
    int erro={0};
    int BagagemMax={4};
    try 
    {
        if(Bagagem < 0 || Bagagem > BagagemMax)
        {
            erro--;
            throw invalid_argument("Numero invalido de bagagens\n");
        }
    }    
    catch (invalid_argument& ErroBagagem)
    {
        argumento = ErroBagagem.what();
    }
    return erro;
}

void Assento::SetAssento(char Assento)
{
    int validar = Validar(Assento);
    if(validar == 0)
    {
        assento = Assento;
    } else (cout << "Erro no campo Reserva: " << argumento);
}

int Assento::Validar(char Assento) throw (invalid_argument)
{
    int erro={0};
    try
    {
        if(Assento != 'D' || Assento != 'T')
        {
            erro--;
            throw invalid_argument("Assento Incorreto\n");
        }
    }
    catch(invalid_argument& ErroAssento)
    {
        argumento = ErroAssento.what();
    }
    return erro;
} 

void CodigoReserva::SetCodigoReserva(int Codigo)
{
    int validar = Validar(Codigo);
    if(validar == 0){
        codigoreserva = Codigo;
    } else (cout << "Erro no campo Codigo: " << argumento);
}

int CodigoReserva::Validar(int Codigo) throw (invalid_argument)
{
    int erro={0}, TamanhoMax={99999};
    try
    {
        if(Codigo < 0 || Codigo > TamanhoMax)
        {
            erro--;
            throw invalid_argument("Codigo de Reserva invalido\n");
        }
    }
    catch(invalid_argument& ErroCodigo)
    {
        argumento = ErroCodigo.what();
    }
    return erro;
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

void CidadeOrigem::SetCidadeOrigem(string CidadeOrigem)
{
    cidadeorigem = CidadeOrigem;
}

int CidadeOrigem::Validar(CidadeOrigem) throw (invalid_argument)
{
    int i, erro={0}, TamanhoMax={10}, ponto={CidadeOrigem.find('.')}, espaco={CidadeOrigem.find(' ')};
    try
    {
        if (CidadeOrigem.size() > TamanhoMax)
        {
            erro--;
            throw invalid_argument("Cidade de Origem com tamanho maior que o permitido\n")
        }
        if (CidadeOrigem[espaco] == CidadeOrigem[espaco+1])
        {
            erro--;
            throw invalid_argument("Dois espacos consecutivos");
        }
        if (CidadeOrigem[ponto-1] < 'A' || CidadeOrigem[ponto-1] > 'z')
        {
            erro--;
            throw invalid_argument("")
        }
        for(i=0; i<CidadeOrigem.size(); i++){
            if (CidadeOrigem[i] < 'A' || CidadeOrigem[i] > 'z')
            {
                if (CidadeOrigem[i] != '.')
                {
                    if (CidadeOrigem[i] != ' ')
                    {
                        erro--;
                        throw invalid_argument("Caractere invalido");
                    }
                }
            }
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void CidadeDestino::SetCidadeDestino(string CidadeDestino)
{
    cidadedestino = CidadeDestino;
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

string CidadeOrigem::GetCidadeOrigem()
{
    return cidadeorigem;
}

string CidadeDestino::GetCidadeDestino()
{
    return cidadedestino;
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

