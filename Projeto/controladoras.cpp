#include "controladoras.h"
#include "dominios.h"
#include "entidades.h"
#include "curses.h"
#include <cstring>
//--------------------------------------------------------------------------------------------------------------------------------------------
void CntrAprInicializacao::Start() throw(runtime_error){
    bool resultado;

        if(dado==1){
            resultado = refAprAutenticacao->Autenticar();
        }
            else
                if(dado==2){
                    resultado = refAprUsuario->Cadastrar();
                }
        if(resultado == 1){
        do{
            initscr();
            getmaxyx(stdscr,linha,coluna);
            mvprintw(linha/2,(coluna-strlen(campo4))/2,"%s",campo1);
            mvprintw(linha/2 + 2,(coluna-strlen(campo5))/2,"%s",campo2);
            mvprintw(linha/2 + 2,(coluna-strlen(campo6))/2,"%s",campo3);
            mvprintw(linha/2 + 2,(coluna-strlen(campo3))/2,"%s",campo4);
            scanw("%d", &dado2);
            clear();
            endwin();
            if(dado2!=1 && dado2!=2 && dado2!=3){
            initscr();
            getmaxyx(stdscr,linha,coluna);
            mvprintw(linha/2,(coluna-strlen(menserro))/2,"%s", menserro);
            noecho();
            getch();
            echo();
            clear();
            endwin();
            }
            }while(dado2!=1 && dado2!=2 && dado2!=3);
            if(dado2==1){
                resultado = refAprCarona->Carona();
                }
                    else
                        if(dado2==2){
                            resultado = refAprCarona->Reserva();
                        }
                            else{
                                resultado = refAprUsuario->Perfil();
                            }
            }
                else
                    if(resultado==0){
                        dado2=0;
                }
    }while(dado2!=1 && dado2!=2);
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprAutenticacao::Autenticar() throw(runtime_error){
    Email email;
    Senha senha;
    char campo1[]="Digite o email: ";
    char campo2[]="Digite a senha: ";
    char campo3[]="Digite 1 para continuar ou 0 para voltar:";
    char menserro[]="Dados Incorretos!";
    char dado1[80];
    char dado2[80];
    int dado3;
    int linha,coluna;
    bool resultado;

    try{
        while(true){
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2-5,(coluna-strlen(campo1))/2,"%s",campo1);
        getstr(dado1);
        mvprintw(linha/2-3,(coluna-strlen(campo2))/2,"%s",campo2);
        getstr(dado2);
        mvprintw(linha/2-1,(coluna-strlen(campo3))/2,"%s",campo3);
        scanw("%d",&dado3);
        clear();
        endwin();
        email.SetEmail(dado1);
        senha.SetSenha(dado2);
        break;
        }
    }
    catch(const invalid_argument &exp){
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2,(coluna-strlen(menserro))/2,"%s",menserro);
        noecho();
        getch();
        echo();
        clear();
        endwin();
    }
    if(dado3==0){
        return 0;
    }
        else{
            resultado = refServAutenticacao->Autenticar(email,senha);
            return resultado;
        }
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::Cadastrar() throw(runtime_error){
    Nome nome;
    Email email;
    Cpf cpf;
    Telefone telefone;
    Banco codbanco1,codbanco2;
    Agencia numagencia1,numagencia2;
    Conta numconta1,numconta2;
    Senha senha;
    char campo1[]="Digite o nome: ";
    char campo2[]="Digite o email: ";
    char campo3[]="Digite o cpf: ";
    char campo4[]="Digite o telefone: ";
    char campo5[]="Digite o codigo de banco: ";
    char campo6[]="Digite o numero da agencia: ";
    char campo7[]="Digite o numero da conta: ";
    char campo8[]="Digite o codigo de banco(opcional): ";
    char campo9[]="Digite o numero da agencia(opcional): ";
    char campo10[]="Digite o numero da conta(opcional): ";
    char campo11[]="Digite a senha: ";
    char campo12[]="Digite 1 para continuar ou 0 para voltar:";
    char menserro[]="Dados Incorretos!";
    char dado1[80];
    char dado2[80];
    char dado3[80];
    char dado4[80];
    char dado6[80];
    char dado7[80];
    char dado9[80];
    char dado10[80];
    char dado11[80];
    int dado5,dado8,dado12;
    int linha,coluna;
    bool resultado;

    try{
        while(true){
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2-11,(coluna-strlen(campo1))/2,"%s",campo1);
        getstr(dado1);
        mvprintw(linha/2-9,(coluna-strlen(campo2))/2,"%s",campo2);
        getstr(dado2);
        mvprintw(linha/2-7,(coluna-strlen(campo3))/2,"%s",campo3);
        getstr(dado3);
        mvprintw(linha/2-5,(coluna-strlen(campo4))/2,"%s",campo3);
        getstr(dado4);
        mvprintw(linha/2-3,(coluna-strlen(campo5))/2,"%s",campo3);
        scanw("%d",&dado5);
        mvprintw(linha/2-1,(coluna-strlen(campo6))/2,"%s",campo3);
        getstr(dado6);
        mvprintw(linha/2+1,(coluna-strlen(campo7))/2,"%s",campo3);
        getstr(dado7);
        mvprintw(linha/2+3,(coluna-strlen(campo8))/2,"%s",campo3);
        scanw("%d",&dado8);
        mvprintw(linha/2+5,(coluna-strlen(campo9))/2,"%s",campo3);
        getstr(dado9);
        mvprintw(linha/2+7,(coluna-strlen(campo10))/2,"%s",campo3);
        getstr(dado10);
        mvprintw(linha/2+9,(coluna-strlen(campo11))/2,"%s",campo3);
        getstr(dado11);
        mvprintw(linha/2+11,(coluna-strlen(campo12))/2,"%s",campo3);
        scanw("%d",&dado12);
        clear();
        endwin();
        nome.SetNome(dado1);
        email.SetEmail(dado2);
        cpf.SetCpf(dado3);
        telefone.SetTelefone(dado4);
        codbanco1.SetCodigoBanco(dado5);
        numagencia1.SetAgencia(dado6);
        numconta1.SetConta(dado7);
        codbanco2.SetCodigoBanco(dado8);
        numagencia2.SetAgencia(dado9);
        numconta2.SetConta(dado10);
        senha.SetSenha(dado11);
        break;
        }
    }
    catch(const invalid_argument &exp){
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2,(coluna-strlen(menserro))/2,"%s",menserro);
        noecho();
        getch();
        echo();
        clear();
        endwin();
    }
    if(dado12==0){
        return 0;
    }
        else{
            resultado = refServUsuario->Cadastrar(nome,email,cpf,telefone,codbanco1,numagencia1,numconta1,codbanco2,numagencia2,numconta2,senha);
            return resultado;
        }
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::Perfil() throw(runtime_error){
    char campo1[]="1-ALTERAR DADOS DE USUARIO.";
    char campo2[]="2-EXCLUIR CONTA.";
    char campo3[]="Digite o numero da opcao desejada:";
    char menserro[]="Opcao invalida!";
    int dado;
    bool resultado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
        mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"%s",campo2);
        mvprintw(linha/2 + 2,(coluna-strlen(campo3))/2,"%s",campo3);
        scanw("%d", &dado);
        clear();
        endwin();
        if(dado!=1 && dado!=2 && dado!=3){
            initscr();
            getmaxyx(stdscr,linha,coluna);
            mvprintw(linha/2,(coluna-strlen(menserro))/2,"%s", menserro);
            noecho();
            getch();
            echo();
            clear();
            endwin();
        }
    }while(dado!=1 && dado!=2);
    if(dado==1){
        resultado = 0;
    }
        else{
            resultado = 1;
        }
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::AlterarDados() throw(runtime_error){
    Nome nome;
    Email email;
    Cpf cpf;
    Telefone telefone;
    Banco codbanco1,codbanco2;
    Agencia numagencia1,numagencia2;
    Conta numconta1,numconta2;
    Senha senha;
    char campo1[]="Digite o nome: ";
    char campo2[]="Digite o email: ";
    char campo3[]="Digite o cpf: ";
    char campo4[]="Digite o telefone: ";
    char campo5[]="Digite o codigo de banco: ";
    char campo6[]="Digite o numero da agencia: ";
    char campo7[]="Digite o numero da conta: ";
    char campo8[]="Digite o codigo de banco(opcional): ";
    char campo9[]="Digite o numero da agencia(opcional): ";
    char campo10[]="Digite o numero da conta(opcional): ";
    char campo11[]="Digite a senha: ";
    char campo12[]="Digite 1 para continuar ou 0 para voltar:";
    char menserro[]="Dados Incorretos!";
    char dado1[80];
    char dado2[80];
    char dado3[80];
    char dado4[80];
    char dado6[80];
    char dado7[80];
    char dado9[80];
    char dado10[80];
    char dado11[80];
    int dado5,dado8,dado12;
    int linha,coluna;
    bool resultado;

    try{
        while(true){
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2-11,(coluna-strlen(campo1))/2,"%s",campo1);
        getstr(dado1);
        mvprintw(linha/2-9,(coluna-strlen(campo2))/2,"%s",campo2);
        getstr(dado2);
        mvprintw(linha/2-7,(coluna-strlen(campo3))/2,"%s",campo3);
        getstr(dado3);
        mvprintw(linha/2-5,(coluna-strlen(campo4))/2,"%s",campo3);
        getstr(dado4);
        mvprintw(linha/2-3,(coluna-strlen(campo5))/2,"%s",campo3);
        scanw("%d",&dado5);
        mvprintw(linha/2-1,(coluna-strlen(campo6))/2,"%s",campo3);
        getstr(dado6);
        mvprintw(linha/2+1,(coluna-strlen(campo7))/2,"%s",campo3);
        getstr(dado7);
        mvprintw(linha/2+3,(coluna-strlen(campo8))/2,"%s",campo3);
        scanw("%d",&dado8);
        mvprintw(linha/2+5,(coluna-strlen(campo9))/2,"%s",campo3);
        getstr(dado9);
        mvprintw(linha/2+7,(coluna-strlen(campo10))/2,"%s",campo3);
        getstr(dado10);
        mvprintw(linha/2+9,(coluna-strlen(campo11))/2,"%s",campo3);
        getstr(dado11);
        mvprintw(linha/2+11,(coluna-strlen(campo12))/2,"%s",campo3);
        scanw("%d",&dado12);
        clear();
        endwin();
        nome.SetNome(dado1);
        email.SetEmail(dado2);
        cpf.SetCpf(dado3);
        telefone.SetTelefone(dado4);
        codbanco1.SetCodigoBanco(dado5);
        numagencia1.SetAgencia(dado6);
        numconta1.SetConta(dado7);
        codbanco2.SetCodigoBanco(dado8);
        numagencia2.SetAgencia(dado9);
        numconta2.SetConta(dado10);
        senha.SetSenha(dado11);
        break;
        }
    }
    catch(const invalid_argument &exp){
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2,(coluna-strlen(menserro))/2,"%s",menserro);
        noecho();
        getch();
        echo();
        clear();
        endwin();
    }
    if(dado12==0){
        return 0;
    }
        else{
            resultado = refServUsuario->AlterarDados(nome,email,cpf,telefone,codbanco1,numagencia1,numconta1,codbanco2,numagencia2,numconta2,senha);
            return resultado;
        }
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool CntrAprUsuario::ExcluirConta() throw(runtime_error){

}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServAutenticacao::Autenticar(Email &email,Senha &senha) throw(runtime_error){
    cout << endl << "FUNCAO AUTENTICAR DA CAMADA DE SERVICO CHAMADA" << endl;
    if(email.GetEmail()==TRIGGER_FALHA){
        return 0;
    }
        else
            if(email.GetEmail()==TRIGGER_ERRO_SISTEMA){
                throw runtime_error("Erro de sistema.");
            }
            else{
                return 1;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServUsuario::Cadastrar(Nome&nome,Email&email,Cpf&cpf,Telefone&telefone,Banco&codbanco1,Agencia&numagencia1,Conta&numconta1,Banco&codbanco2,Agencia&numagencia2,Conta&numconta2,Senha&senha) throw(runtime_error){
    cout << endl << "FUNCAO CADASTRAR DA CAMADA DE SERVICO CHAMADA" << endl;
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
bool CntrServUsuario::ExcluirConta() throw(runtime_error){
    cout << endl << "FUNCAO EXCLUIR DA CAMADA DE SERVICO CHAMADA" << endl;
    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
