#include "telas.h"
//-----------------------------------------------------------------------------------------------------------------------------------
int TelaInicializacao::TelaIncial(){
    char campo1[]="1-ENTRAR.";
    char campo2[]="2-CADASTRAR.";
    char campo3[]="Digite o numero da opcao desejada:";
    char msgerro[]="Opcao invalida!"
    int dado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2-5,(coluna-strlen(campo1))/2,"%s",campo1);
        mvprintw(linha/2-3,(coluna-strlen(campo2))/2,"%s",campo2);
        mvprintw(linha/2-1,(coluna-strlen(campo3))/2,"%s",campo3);
        scanw("%d", &dado);
        clear();
        endwin();
        if(dado!=1 && dado!=2){
            initscr();
            getmaxyx(stdscr,linha,coluna);
            mvprintw(linha/2,(coluna-strlen(msgerro))/2,"%s",msgerro);
            noecho();
            getch();
            echo();
            clear();
            endwin();
        }
    }while(dado!=1 && dado!=2);
    return dado;

}
//-----------------------------------------------------------------------------------------------------------------------------------
int TelaInicializacao::TelaOpt(){
    char campo1[]="1-MINHAS CARONAS.";
    char campo2[]="2-MINHAS RESERVAS.";
    char campo3[]="3-MEU PERFIL.";
    char campo4[]="Digite o numero da opcao desejada:";
    char msgerro[]="Opcao invalida!"
    int dado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
        mvprintw(linha/2 - 2,(coluna-strlen(campo2))/2,"%s",campo2);
        mvprintw(linha/2 - 4,(coluna-strlen(campo3))/2,"%s",campo3);
        mvprintw(linha/2 - 6,(coluna-strlen(campo4))/2,"%s",campo4);
        scanw("%d", &dado);
        clear();
        endwin();
        if(dado!=1 && dado!=2 && dado!=3){
            initscr();
            getmaxyx(stdscr,linha,coluna);
            mvprintw(linha/2,(coluna-strlen(msgerro))/2,"%s", msgerro);
            noecho();
            getch();
            echo();
            clear();
            endwin();
        }
    }while(dado!=1 && dado!=2 && dado!=3);
    return dado;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaAutenticar::TelaAutenticacao(Email* email, Senha* senha) throw(invalid_argument){
    char campo1[]="Digite o email: ";
    char campo2[]="Digite a senha: ";
    char campo3[]="Digite 1 para continuar ou 0 para voltar:";
    char dado1[80];
    char dado2[80];
    int dado;
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2-5,(coluna-strlen(campo1))/2,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/2-3,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/2-1,(coluna-strlen(campo3))/2,"%s",campo3);
    scanw("%d",&dado);
    clear();
    endwin();
    if(dado==1){
        email->SetEmail(dado1);
        senha->SetSenha(dado2);
    }
        else{
            break;
        }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaUsuario::TelaCadastro(User* user, Account* account1, Account* account2) throw(invalid_argument){
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
    char campo13[]="Deseja cadastra uma segunda conta bancaria?Digite 1 para confirmar 0 para cancelar:";
    char dado1[80];
    char dado2[80];
    char dado3[80];
    char dado4[80];
    char dado6[80];
    char dado7[80];
    char dado9[80];
    char dado10[80];
    char dado11[80];
    int dado5,dado8,dado12,dado13;
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/2,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/2,(coluna-strlen(campo3))/2,"%s",campo3);
    getstr(dado3);
    mvprintw(linha/2,(coluna-strlen(campo4))/2,"%s",campo4);
    getstr(dado4);
    mvprintw(linha/2,(coluna-strlen(campo5))/2,"%s",campo5);
    scanw("%d",&dado5);
    mvprintw(linha/2,(coluna-strlen(campo6))/2,"%s",campo6);
    getstr(dado6);
    mvprintw(linha/2,(coluna-strlen(campo7))/2,"%s",campo7);
    getstr(dado7);
    mvprintw(linha/2,(coluna-strlen(campo13))/2,"%s",campo13);
    scanw("%d",&dado13);
    mvprintw(linha/2,(coluna-strlen(campo8))/2,"%s",campo8);
    scanw("%d",&dado8);
    mvprintw(linha/2,(coluna-strlen(campo9))/2,"%s",campo9);
    getstr(dado9);
    mvprintw(linha/2,(coluna-strlen(campo10))/2,"%s",campo10);
    getstr(dado10);
    mvprintw(linha/2,(coluna-strlen(campo11))/2,"%s",campo11);
    getstr(dado11);
    mvprintw(linha/2,(coluna-strlen(campo12))/2,"%s",campo12);
    scanw("%d",&dado12);
    clear();
    endwin();
    if(dado12==1){
        user->SetNome(dado1);
        user->SetEmail(dado2);
        user->SetCpf(dado3);
        user->SetTelefone(dado4);
        account1->SetCodigoBanco(dado5);
        account1->SetAgencia(dado6);
        account1->SetConta(dado7);
        if(dadp13==1){
            account2->SetCodigoBanco(dado8);
            account2->SetAgencia(dado9);
            account2->SetConta(dado10);
        }
        user->SetSenha(dado11);
    }
        else{
            break;
        }
}
//-----------------------------------------------------------------------------------------------------------------------------------
int TelaUsuario::TelaOptUsuario(){
    char campo1[]="1-VISUALIZAR DADOS.";
    char campo2[]="2-ALTERAR DADOS.";
    char campo3[]="3-EXCLUIR CONTA.";
    char campo4[]="Digite o numero da opcao desejada:";
    char msgerro[]="Opcao invalida!"
    int dado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
        mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"%s",campo2);
        mvprintw(linha/2 + 4,(coluna-strlen(campo3))/2,"%s",campo3);
        mvprintw(linha/2 + 6,(coluna-strlen(campo4))/2,"%s",campo4);
        scanw("%d", &dado);
        clear();
        endwin();
        if(dado!=1 && dado!=2 && dado!=3){
            initscr();
            getmaxyx(stdscr,linha,coluna);
            mvprintw(linha/2,(coluna-strlen(msgerro))/2,"%s", msgerro);
            noecho();
            getch();
            echo();
            clear();
            endwin();
        }
    }while(dado!=1 && dado!=2 && dado!=3);
    return dado;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaUsuario::TelaVisualizarDados(User* user, Account* account1, Account* account2){
    char campo1[]="Seu nome: ";
    char campo2[]="Seu email: ";
    char campo3[]="Seu cpf: ";
    char campo4[]="Seu telefone: ";
    char campo5[]="Seu codigo de banco: ";
    char campo6[]="Seu numero da agencia: ";
    char campo7[]="Seu numero da conta: ";
    char campo8[]="Seu codigo de banco(opcional): ";
    char campo9[]="Seu numero da agencia(opcional): ";
    char campo10[]="Seu numero da conta(opcional): ";
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(5,(coluna-strlen(campo1))/2,"%s",campo1);
    mvprintw(7,(coluna-strlen(campo2))/2,"%s",campo2);
    mvprintw(5,(coluna-strlen(campo1))/2,"%s",campo1);x
    mvprintw(9,(coluna-strlen(campo3))/2,"%s",campo3);
    mvprintw(5,(coluna-strlen(campo1))/2,"%s",campo1);x
    mvprintw(11,(coluna-strlen(campo4))/2,"%s",campo4);
    mvprintw(5,(coluna-strlen(campo1))/2,"%s",campo1);x
    mvprintw(13,(coluna-strlen(campo5))/2,"%s",campo5);
    mvprintw(5,(coluna-strlen(campo1))/2,"%s",campo1);x
    mvprintw(15,(coluna-strlen(campo6))/2,"%s",campo6);
    mvprintw(17,(coluna-strlen(campo7))/2,"%s",campo7);
    mvprintw(19,(coluna-strlen(campo13))/2,"%s",campo13);
    mvprintw(21,(coluna-strlen(campo8))/2,"%s",campo8);
    mvprintw(23,(coluna-strlen(campo9))/2,"%s",campo9);
    mvprintw(25,(coluna-strlen(campo10))/2,"%s",campo10);
    mvprintw(27,(coluna-strlen(campo11))/2,"%s",campo11);
    mvprintw(29,(coluna-strlen(campo12))/2,"%s",campo12);
    clear();
    endwin();
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaUsuario::TelaAlterarDados(User* user, Account* account1, Account* account2) throw(invalid_argument){
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
    char campo13[]="Deseja cadastra uma segunda conta bancaria?Digite 1 para confirmar 0 para cancelar:";
    char dado1[80];
    char dado2[80];
    char dado3[80];
    char dado4[80];
    char dado6[80];
    char dado7[80];
    char dado9[80];
    char dado10[80];
    char dado11[80];
    int dado5,dado8,dado12,dado13;
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/2,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/2,(coluna-strlen(campo3))/2,"%s",campo3);
    getstr(dado3);
    mvprintw(linha/2,(coluna-strlen(campo4))/2,"%s",campo4);
    getstr(dado4);
    mvprintw(linha/2,(coluna-strlen(campo5))/2,"%s",campo5);
    scanw("%d",&dado5);
    mvprintw(linha/2,(coluna-strlen(campo6))/2,"%s",campo6);
    getstr(dado6);
    mvprintw(linha/2,(coluna-strlen(campo7))/2,"%s",campo7);
    getstr(dado7);
    mvprintw(linha/2,(coluna-strlen(campo13))/2,"%s",campo13);
    scanw("%d",&dado13);
    mvprintw(linha/2,(coluna-strlen(campo8))/2,"%s",campo8);
    scanw("%d",&dado8);
    mvprintw(linha/2,(coluna-strlen(campo9))/2,"%s",campo9);
    getstr(dado9);
    mvprintw(linha/2,(coluna-strlen(campo10))/2,"%s",campo10);
    getstr(dado10);
    mvprintw(linha/2,(coluna-strlen(campo11))/2,"%s",campo11);
    getstr(dado11);
    mvprintw(linha/2,(coluna-strlen(campo12))/2,"%s",campo12);
    scanw("%d",&dado12);
    clear();
    endwin();
    if(dado12==1){
        user->SetNome(dado1);
        user->SetEmail(dado2);
        user->SetCpf(dado3);
        user->SetTelefone(dado4);
        account1->SetCodigoBanco(dado5);
        account1->SetAgencia(dado6);
        account1->SetConta(dado7);
        if(dadp13==1){
            account2->SetCodigoBanco(dado8);
            account2->SetAgencia(dado9);
            account2->SetConta(dado10);
        }
        user->SetSenha(dado11);
    }
        else{
            break;
        }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaUsuario::TelaExcluirDados(Senha* senha) throw(invalid_argument){
    char campo1[]="Digite a senha: ";
    char campo3[]="Digite 1 para continuar ou 0 para voltar:";
    char dado1[80];
    int dado;
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/2-2,(coluna-strlen(campo3))/2,"%s",campo3);
    scanw("%d",&dado);
    clear();
    endwin();
    if(dado==1){
        senha->SetSenha(dado1);
    }
        else{
            break;
        }
}
//-----------------------------------------------------------------------------------------------------------------------------------
int TelaCarona::TelaOptCarona(){
    char campo1[]="1-CADASTRAR CARONA.";
    char campo2[]="2-DESCADASTRAR CARONA.";
    char campo3[]="3-RESERVAS DA CARONA.";
    char campo4[]="Digite o numero da opcao desejada:";
    char msgerro[]="Opcao invalida!"
    int dado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
        mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"%s",campo2);
        mvprintw(linha/2 + 4,(coluna-strlen(campo3))/2,"%s",campo3);
        mvprintw(linha/2 + 6,(coluna-strlen(campo4))/2,"%s",campo4);
        scanw("%d", &dado);
        clear();
        endwin();
        if(dado!=1 && dado!=2 && dado!=3){
            initscr();
            getmaxyx(stdscr,linha,coluna);
            mvprintw(linha/2,(coluna-strlen(msgerro))/2,"%s", msgerro);
            noecho();
            getch();
            echo();
            clear();
            endwin();
        }
    }while(dado!=1 && dado!=2 && dado!=3);
    return dado;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaCarona::TelaCadastrarCarona(Ride* ride) throw(invalid_argument){
    char campo1[]="Digite o codigo da carona: ";
    char campo2[]="Digite o estado de origem: ";
    char campo3[]="Digite a cidade de origem: ";
    char campo4[]="Digite o estado de destino: ";
    char campo5[]="Digite a cidade de destino: ";
    char campo6[]="Digite a data de partida: ";
    char campo7[]="Digite a duracao do percusso: ";
    char campo8[]="Digite a quantidade de vagas disponiveis: ";
    char campo9[]="Digite o preco: ";
    char campo10[]="Digite 1 para continuar ou 0 para voltar:";
    char dado2[80];
    char dado3[80];
    char dado4[80];
    char dado5[80];
    char dado6[80];
    char dado9[80];
    char dado10[80];
    int dado1,dado7,dado8,dado10;
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
    scanw("%d",&dado1);
    mvprintw(linha/2,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/2,(coluna-strlen(campo3))/2,"%s",campo3);
    getstr(dado3);
    mvprintw(linha/2,(coluna-strlen(campo4))/2,"%s",campo4);
    getstr(dado4);
    mvprintw(linha/2,(coluna-strlen(campo5))/2,"%s",campo5);
    getstr(dado5);
    mvprintw(linha/2,(coluna-strlen(campo6))/2,"%s",campo6);
    getstr(dado6);
    mvprintw(linha/2,(coluna-strlen(campo7))/2,"%s",campo7);
    scanw("%d",&dado7);
    mvprintw(linha/2,(coluna-strlen(campo8))/2,"%s",campo8);
    scanw("%d",&dado8);
    mvprintw(linha/2,(coluna-strlen(campo9))/2,"%s",campo9);
    getstr(dado9);
    mvprintw(linha/2,(coluna-strlen(campo10))/2,"%s",campo10);
    scanw("%d",&dado10);
    clear();
    endwin();
    if(dado10==1){
        ride->SetCodigoCarona(dado1);
        ride->SetEstadoOrigem(dado2);
        ride->SetCidadeOrigem(dado3);
        ride->SetEstadoDestino(dado4);
        ride->SetCidadeDestino(dado5);
        ride->SetData(dado6);
        ride->SetDuracao(dado7);
        ride->SetVagas(dado8);
        ride->SetPreco(dado9);
    }
        else{
            break;
        }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaCarona::TelaDescadastrarCarona(Ride* ride){
    char campo1[]="Codigo da carona: ";
    char campo2[]="Digite 1 para continuar ou 0 para voltar:";
    int dado1,dado2;
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
    scanw("%d",&dado1);
    mvprintw(linha/2-2,(coluna-strlen(campo2))/2,"%s",campo2);
    scanw("%d",&dado2);
    clear();
    endwin();
    if(dado2==1){
        ride->SetCodigoCarona(dado1)
    }
        else{
            break;
        }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaCarona::TelaListaReservas(Ride* ride){

}
//-----------------------------------------------------------------------------------------------------------------------------------
int TelaReserva::TelaOptReserva(){
    char campo1[]="1-CADASTRAR RESERVA.";
    char campo2[]="2-DESCADASTRAR RESERVA.";
    char campo3[]="3-VISUALIZAR RESERVA.";
    char campo4[]="Digite o numero da opcao desejada:";
    char msgerro[]="Opcao invalida!"
    int dado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
        mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"%s",campo2);
        mvprintw(linha/2 + 4,(coluna-strlen(campo3))/2,"%s",campo3);
        mvprintw(linha/2 + 6,(coluna-strlen(campo4))/2,"%s",campo4);
        scanw("%d", &dado);
        clear();
        endwin();
        if(dado!=1 && dado!=2 && dado!=3){
            initscr();
            getmaxyx(stdscr,linha,coluna);
            mvprintw(linha/2,(coluna-strlen(msgerro))/2,"%s", msgerro);
            noecho();
            getch();
            echo();
            clear();
            endwin();
        }
    }while(dado!=1 && dado!=2 && dado!=3);
    return dado;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaReserva::TelaVisualizarReserva(Email* email){

}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaReserva::TelaCadastrarReserva(Booking* booking) throw(invalid_argument){
    char campo1[]="Digite o codigo da reserva: ";
    char campo2[]="Digite a preferencia de assento(D/T): ";
    char campo3[]="Digite o numero de bagagens: ";
    char campo4[]="Digite 1 para continuar ou 0 para voltar:";
    char dado2;
    int dado1,dado3,dado4;
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
    scanw("%d",&dado1);
    mvprintw(linha/2-2,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/2-4,(coluna-strlen(campo3))/2,"%s",campo3);
    scanw("%d",&dado3);
    mvprintw(linha/2-6,(coluna-strlen(campo4))/2,"%s",campo4);
    scanw("%d",&dado4);
    clear();
    endwin();
    if(dado4==1){
        booking->SetCodigoReserva(dado1);
        booking->SetAssento(dado2);
        booking->SetBagagem(dado3);
    }
        else{
            break;
        }
}
//-----------------------------------------------------------------------------------------------------------------------------------
int TelaReserva::TelaDescadastrarReserva(){
    char campo1[]="Deseja mesmo cancelar sua reserva? ";
    char campo2[]="Digite 1 para continuar ou 0 para voltar:";
    int dado2;
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
    mvprintw(linha/2-2,(coluna-strlen(campo2))/2,"%s",campo2);
    scanw("%d",&dado2);
    clear();
    endwin();
    return dado2;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaMensagem::TelaMsg(string str){
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(str))/2,"%s", str);
    noecho();
    getch();
    echo();
    clear();
    endwin();
}















