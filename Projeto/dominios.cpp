#include <iostream>
#include <string>
#include <stdexcept>
#include "dominios.h"
using namespace std;

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
        if(Assento != 'D')
        {
            if (Assento != 'T')
            {
            erro--;
            throw invalid_argument("Assento Incorreto\n");
            }
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

void CidadeOrigem::SetCidadeOrigem(string CidadeOrigem)
{
    int validar = Validar(CidadeOrigem);
    if (validar == 0){
        cidadeorigem = CidadeOrigem;
    } else (cout << "Erro no campo Cidade de Origem: " << argumento);
}

int CidadeOrigem::Validar(string CidadeOrigem) throw (invalid_argument)
{
    int i, erro={0}, TamanhoMax={10}, ponto={CidadeOrigem.find('.')}, espaco={CidadeOrigem.find(' ')};
    try
    {
        if (CidadeOrigem.size() > TamanhoMax)
        {
            erro--;
            throw invalid_argument("Cidade de Origem com tamanho maior que o permitido\n");
        }
        if (CidadeOrigem[espaco] == CidadeOrigem[espaco+1])
        {
            erro--;
            throw invalid_argument("Dois espacos consecutivos\n");
        }
        if(ponto != -1){
            if (CidadeOrigem[ponto-1] < 'A' || CidadeOrigem[ponto-1] > 'z')
            {
                erro--;
                throw invalid_argument("Ponto em local invalido\n");
             }
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
    catch(invalid_argument& ErroCidadeOrigem)
    {
        argumento = ErroCidadeOrigem.what();
    }
    return erro;
}

void CidadeDestino::SetCidadeDestino(string CidadeDestino)
{
    int validar = Validar(CidadeDestino);
    if (validar == 0){
        cidadedestino = CidadeDestino;
    } else (cout << "Erro no campo Cidade Destino: " << argumento);
}

int CidadeDestino::Validar(string CidadeDestino) throw (invalid_argument)
{
    int i, erro={0}, TamanhoMax={10}, ponto={CidadeDestino.find('.')}, espaco={CidadeDestino.find(' ')};
    try
    {
        if (CidadeDestino.size() > TamanhoMax)
        {
            erro--;
            throw invalid_argument("Cidade Destino com tamanho maior que o permitido\n");
        }
        if (CidadeDestino[espaco] == CidadeDestino[espaco+1])
        {
            erro--;
            throw invalid_argument("Dois espacos consecutivos\n");
        }
        if(ponto != -1){
            if (CidadeDestino[ponto-1] < 'A' || CidadeDestino[ponto-1] > 'z')
            {
                erro--;
                throw invalid_argument("Ponto em local invalido\n");
             }
        }
        for(i=0; i<CidadeDestino.size(); i++){
            if (CidadeDestino[i] < 'A' || CidadeDestino[i] > 'z')
            {
                if (CidadeDestino[i] != '.')
                {
                    if (CidadeDestino[i] != ' ')
                    {
                        erro--;
                        throw invalid_argument("Caractere invalido");
                    }
                }
            }
        }

    }
    catch(invalid_argument& ErroCidadeDestino)
    {
        argumento = ErroCidadeDestino.what();
    }
    return erro;
}

void Vagas::SetVagas(int Vagas)
{
    int validar = Validar(Vagas);
    if (validar == 0) {
        vagas = Vagas;
    } else (cout << "Erro no campo Vagas: " << argumento);
}

int Vagas::Validar(int Vagas) throw (invalid_argument)
{
    int VagasMax={4}, erro={0};
    try
    {
        if (Vagas > VagasMax)
        {
            erro--;
            throw invalid_argument("Numero de vagas maior que o permitido\n");
        }
    }
    catch(invalid_argument& ErroVagas)
    {
        argumento = ErroVagas.what();
    }
    return erro;
}

void Duracao::SetDuracao(int Duracao)
{
    int validar = Validar(Duracao);
    if (validar == 0){
        duracao = Duracao;
    } else (cout << "Erro no campo Duracao: " << argumento);
}

int Duracao::Validar(int Duracao) throw (invalid_argument)
{
    int DuracaoMin={1}, DuracaoMax={48}, erro={0};
    try
    {
        if (Duracao < DuracaoMin || Duracao > DuracaoMax)
        {
            erro--;
            throw invalid_argument("Duracao invalida\n");
        }
    }
    catch(invalid_argument& ErroDuracao)
    {
        argumento = ErroDuracao.what();
    }
    return erro;
}

void CodigoCarona::SetCodigoCarona(int CodigoCarona)
{
    int validar = Validar(CodigoCarona);
    if(validar == 0){
        codigocarona = CodigoCarona;
    } else (cout << "Erro no campo Codigo de Carona: " << argumento);
}

int CodigoCarona::Validar(int CodigoCarona) throw (invalid_argument)
{
    int erro={0}, TamanhoMin={1000}, TamanhoMax={9999};
    try
    {
        if(CodigoCarona < TamanhoMin || CodigoCarona > TamanhoMax)
        {
            erro--;
            throw invalid_argument("Codigo de carona de tamanho invalido\n");
        }
    }
    catch(invalid_argument& ErroCodigo)
    {
        argumento = ErroCodigo.what();
    }
    return erro;
}

void EstadoOrigem::SetEstadoOrigem(string EstadoOrigem)
{
    int validar = Validar(EstadoOrigem);
    if (validar == 0){
        estadoorigem = EstadoOrigem;
    } else (cout << "Erro no campo Estado de Origem: " << argumento);
}


int EstadoOrigem::Validar(string EstadoOrigem) throw (invalid_argument)
{
    int erro={0};
    try
    {
        if(EstadoOrigem != "DF" &&EstadoOrigem != "AC" &&EstadoOrigem != "AL" &&EstadoOrigem != "AP" &&EstadoOrigem != "AM" &&EstadoOrigem != "BA" &&EstadoOrigem != "CE" &&EstadoOrigem != "ES" &&EstadoOrigem != "GO" &&EstadoOrigem != "MA" &&EstadoOrigem != "MT" &&EstadoOrigem != "MS"&&EstadoOrigem != "MG" &&EstadoOrigem != "PA" &&EstadoOrigem != "PB" &&EstadoOrigem != "PR" &&EstadoOrigem != "PE" &&EstadoOrigem != "PI" &&EstadoOrigem != "RJ" &&EstadoOrigem != "RN" &&EstadoOrigem != "RS" &&EstadoOrigem != "RO" &&EstadoOrigem != "RR" &&EstadoOrigem != "SC" &&EstadoOrigem != "SP" &&EstadoOrigem != "SE" &&EstadoOrigem != "TO")
        {
            erro--;
            throw invalid_argument("Estado Invalido\n");
        }
    }
    catch(invalid_argument& ErroEstado)
    {
        argumento = ErroEstado.what();
    }
    return erro;
}

void EstadoDestino::SetEstadoDestino(string EstadoDestino)
{
    int validar = Validar(EstadoDestino);
    if(validar == 0){
        estadodestino = EstadoDestino;
    } else (cout << "Erro no campo Estado Destino: " << argumento);
}

int EstadoDestino::Validar(string EstadoDestino) throw (invalid_argument)
{
    int erro={0};
    try
    {
        if(EstadoDestino != "DF" &&EstadoDestino != "AC" &&EstadoDestino != "AL" &&EstadoDestino != "AP" &&EstadoDestino != "AM" &&EstadoDestino != "BA" &&EstadoDestino != "CE" &&EstadoDestino != "ES" &&EstadoDestino != "GO" &&EstadoDestino != "MA" &&EstadoDestino != "MT" &&EstadoDestino != "MS"&&EstadoDestino != "MG" &&EstadoDestino != "PA" &&EstadoDestino != "PB" &&EstadoDestino != "PR" &&EstadoDestino != "PE" &&EstadoDestino != "PI" &&EstadoDestino != "RJ" &&EstadoDestino != "RN" &&EstadoDestino != "RS" &&EstadoDestino != "RO" &&EstadoDestino != "RR" &&EstadoDestino != "SC" &&EstadoDestino != "SP" &&EstadoDestino != "SE" &&EstadoDestino != "TO")
        {
            erro--;
            throw invalid_argument("Estado Invalido\n");
        }
    }
    catch(invalid_argument& ErroEstado)
    {
        argumento = ErroEstado.what();
    }
    return erro;
}

void Data::SetData(string Data)
{
    int validar = Validar(Data);
    if (validar == 0){
        data = Data;
    } else (cout << "Erro no campo Data: " << argumento);
}

int Data::Validar(string Data) throw (invalid_argument)
{
    int erro={0}, ConverterAscii={48};
    try
    {
        if (Data[2] != '/' || Data[5] != '/')
        {
            erro--;
            throw invalid_argument("Formatacao de data invalida\n");
        }
        if (Data[0] < '0' || Data[0] > '3')
        {
            erro--;
            throw invalid_argument("Data invalida\n");
        }
        if (Data [0] == '3' && Data[1] > '1')
        {
            erro--;
            throw invalid_argument("Data invalida\n");
        }
        if (Data[3] < '0' || Data[3] > '1')
        {
            erro--;
            throw invalid_argument("Data invalida\n");
        }
        if (Data[4] < '0' || Data[4] > '9')
        {
            erro--;
            throw invalid_argument("Data invalida\n");
        }
        if (Data[3] == '1' && Data[4] > '2')
        {
            erro--;
            throw invalid_argument("Data invalida\n");
        }
        if (Data[6] != '2' || Data[7] != '0')
        {
            erro--;
            throw invalid_argument("Data invalida\n");
        }
        if (Data[8] < '0' || Data[8] > '9' || Data[9] < '0' || Data[9] > '9')
        {
            erro--;
            throw invalid_argument("Data invalida\n");
        }
        if (((Data[4]-ConverterAscii)%2 == 0))
        {
            if (Data[4] < '7')
            {
                if (Data [0] == '3' && Data[1] != '0')
                {
                    erro--;
                    throw invalid_argument("Data invalida\n");
                }
            }
            if (Data[4] > '7')
            {
                if (Data [0] == '3' && Data[1] != '1')
                {
                    erro--;
                    throw invalid_argument("Data invalida\n");
                }
            }
        }
        if (((Data[4]-ConverterAscii)%2 != 0))
        {
            if (Data[4] > '8')
            {
                if (Data [0] == '3' && Data[1] != '0')
                {
                    erro--;
                    throw invalid_argument("Data invalida\n");
                }
            }
            if (Data[4] < '8')
            {
                if (Data [0] == '3' && Data[1] != '1')
                {
                    erro--;
                    throw invalid_argument("Data invalida\n");
                }
            }
        }
        if (Data[4] == '2')
        {
            if (((Data[9]-ConverterAscii)%4) == 0)
            {
                if (Data[0] > '2')
                {
                    erro--;
                    throw invalid_argument("Data invalida\n");
                }
                if (Data[0] == '2' && Data[1] > '9')
                {
                    erro--;
                    throw invalid_argument("Data invalida\n");
                }
            }
            if (((Data[9]-ConverterAscii)%4) != 0)
            {
                if (Data[0] > '2')
                {
                    erro--;
                    throw invalid_argument("Data invalida\n");
                }
                if (Data[0] == '2' && Data[1] > '8')
                {
                    erro--;
                    throw invalid_argument("Data invalida\n");
                }
            }
        }
    }
    catch(invalid_argument& ErroData)
    {
        argumento = ErroData.what();
    }
    return erro;
}

void Preco::SetPreco(string Preco)
{
    int validar = Validar(Preco);
    if (validar == 0){
        preco = Preco;
   } else (cout << "Erro no campo Preco: " << argumento);
}

int Preco::Validar(string Preco) throw (invalid_argument)
{
    int preco={ConverterPreco(Preco)}, PrecoMin={100}, PrecoMax={500000}, erro={0};

    try
    {
        if (preco < PrecoMin || preco > PrecoMax)
        {
            erro--;
            throw invalid_argument("Preco invalido\n");
        }

    }
    catch(invalid_argument& ErroPreco)
    {
        argumento = ErroPreco.what();
    }

    return erro;
}

int Preco::ConverterPreco(string Preco)
{
    string StrPrecoNumerico;
    StrPrecoNumerico = Preco;
    int ponto = {StrPrecoNumerico.find('.')};
    if(ponto != -1)
    {
        StrPrecoNumerico.erase(ponto, 1);
    }
    int virgula = {StrPrecoNumerico.find(',')};
    if(virgula != -1)
    {
       StrPrecoNumerico.erase(virgula, 1);
    }
    int IntPrecoNumerico = stoi (StrPrecoNumerico,nullptr,0);
    return IntPrecoNumerico;
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

void Banco::SetCodigoBanco(int CodigoBanco)
{
    int validar = Validar(CodigoBanco);
    if (validar == 0){
        codigobanco = CodigoBanco;
    } else (cout << "Erro no campo Codigo do Banco: " << argumento);
}

int Banco::Validar(int CodigoBanco) throw (invalid_argument)
{
    int erro={0}, TamanhoMax={999}, TamanhoMin={100};
    try
    {
        if(CodigoBanco < TamanhoMin || CodigoBanco > TamanhoMax)
        {
            erro--;
            throw invalid_argument("Codigo de Banco invalido\n");
        }
    }
    catch(invalid_argument& ErroCodigo)
    {
        argumento = ErroCodigo.what();
    }
    return erro;
}


void Agencia::SetAgencia(string Agencia)
{
    int validar = Validar(Agencia);
    if (validar == 0){
        agencia = Agencia;
    } else (cout << "Erro no campo Numero da Agencia: " << argumento);
}

int Agencia::Validar(string Agencia) throw (invalid_argument)
{
    int Tamanho= {6};
    int erro= {0};
    int soma= {0},dobro;
    try
    {
        if(Agencia.size() != Tamanho)
        {
            erro--;
            throw invalid_argument("Tamanho de Numero da agencia Invalido\n");
        }
        if (Agencia[0] < '0' || Agencia[0] > '9' || Agencia[1] < '0' || Agencia[1] > '9' || Agencia[2] < '0' || Agencia[2] > '9' || Agencia[3] < '0' || Agencia[3] > '9' || Agencia[4] != '-' || Agencia[5] < '0' || Agencia[5] > '9'){
            erro--;
            throw invalid_argument("Existencia de caracteres invalidos\n");
        }
        if((((int)Agencia[0]-48) + (((((int)Agencia[1]-48)*2)/10) + ((((int)Agencia[1]-48)*2)%10)) + ((int)Agencia[2]-48) + (((((int)Agencia[3]-48)*2)/10) + ((((int)Agencia[3]-48)*2)%10)) + ((int)Agencia[5]-48)) % 10 != 0){
            erro--;
            throw invalid_argument("Digito verificador incorreto\n");
        }
    }
    catch (invalid_argument& ErroAgencia)
    {
        argumento = ErroAgencia.what();
    }
    return erro;
}


void Conta::SetConta(string Conta)
{
     int validar = Validar(Conta);
    if (validar == 0){
        conta = Conta;
    } else (cout << "Erro no campo Numero da Conta: " << argumento);
}

int Conta::Validar(string Conta) throw (invalid_argument)
{
    int Tamanho= {8};
    int erro= {0};
    try
    {
        if(Conta.size() != Tamanho)
        {
            erro--;
            throw invalid_argument("Tamanho de Numero da conta Invalido\n");
        }
        if (Conta[0] < '0' || Conta[0] > '9' || Conta[1] < '0' || Conta[1] > '9' || Conta[2] < '0' || Conta[2] > '9' || Conta[3] < '0' || Conta[3] > '9' || Conta[4] < '0' || Conta[4] > '9' || Conta[5] < '0' || Conta[5] > '9' || Conta[6] != '-' || Conta[7] < '0' || Conta[7] > '9'){
            erro--;
            throw invalid_argument("Existencia de caracteres invalidos\n");
        }
        if((((int)Conta[0]-48) + ((((int)Conta[1]-48)*2)/10 + (((int)Conta[1]-48)*2)%10) + ((int)Conta[2]-48) + ((((int)Conta[3]-48)*2)/10 + (((int)Conta[3]-48)*2)%10) + ((int)Conta[4]-48) + ((((int)Conta[5]-48)*2)/10 + (((int)Conta[5]-48)*2)%10) + ((int)Conta[7]-48)) % 10 != 0){
            erro--;
            throw invalid_argument("Digito verificador incorreto\n");
        }
    }
    catch (invalid_argument& ErroConta)
    {
        argumento = ErroConta.what();
    }
    return erro;
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

