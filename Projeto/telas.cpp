#include "telas.h"
//-----------------------------------------------------------------------------------------------------------------------------------
int TelaInicializacao::TelaIncial(){
    char campo1[]="1-ENTRAR.";
    char campo2[]="2-CADASTRAR.";
    char campo3[]="Digite o numero da opcao desejada:";
    char msgerro[]="Opcao invalida!";
    int dado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2-5,9,"%s",campo1);
        mvprintw(linha/2-3,9,"%s",campo2);
        mvprintw(linha/2-1,9,"%s",campo3);
        scanw("%d", &dado);
        clear();
        endwin();
        if(dado!=1 && dado!=2){
            initscr();
            getmaxyx(stdscr,linha,coluna);
            mvprintw(linha/2,9,"%s",msgerro);
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
    char msgerro[]="Opcao invalida!";
    int dado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2-6,9,"%s",campo1);
        mvprintw(linha/2-4,9,"%s",campo2);
        mvprintw(linha/2-2,9,"%s",campo3);
        mvprintw(linha/2,9,"%s",campo4);
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
void TelaAutenticar::TelaAutenticacao(Email& email, Senha& senha) throw(invalid_argument){
    char campo1[]="Digite o email: ";
    char campo2[]="Digite a senha: ";
    char campo3[]="Digite 1 para continuar ou 0 para voltar:";
    char dado1[80];
    char dado2[80];
    int dado;
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2-5,9,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/2-3,9,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/2-1,9,"%s",campo3);
    scanw("%d",&dado);
    clear();
    endwin();
    if(dado==1){
        email.SetEmail(dado1);
        senha.SetSenha(dado2);
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaUsuario::TelaCadastro(User& user, Account& account1, Account& account2) throw(invalid_argument){
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
    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    Cpf cpf;
    Banco banco,banco2;
    Agencia agencia,agencia2;
    Conta conta,conta2;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2-12,9,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/2-10,9,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/2-8,9,"%s",campo3);
    getstr(dado3);
    mvprintw(linha/2-6,9,"%s",campo4);
    getstr(dado4);
    mvprintw(linha/2-4,9,"%s",campo5);
    scanw("%d",&dado5);
    mvprintw(linha/2-2,9,"%s",campo6);
    getstr(dado6);
    mvprintw(linha/2,9,"%s",campo7);
    getstr(dado7);
    mvprintw(linha/2+2,9,"%s",campo13);
    scanw("%d",&dado13);
    mvprintw(linha/2+4,9,"%s",campo8);
    scanw("%d",&dado8);
    mvprintw(linha/2+6,9,"%s",campo9);
    getstr(dado9);
    mvprintw(linha/2+8,9,"%s",campo10);
    getstr(dado10);
    mvprintw(linha/2+10,9,"%s",campo11);
    getstr(dado11);
    mvprintw(linha/2+12,9,"%s",campo12);
    scanw("%d",&dado12);
    clear();
    endwin();
    if(dado12==1){
        nome.SetNome(dado1);
        user.SetNome(nome);
        email.SetEmail(dado2);
        user.SetEmail(email);
        cpf.SetCpf(dado3);
        user.SetCpf(cpf);
        telefone.SetTelefone(dado4);
        user.SetTelefone(telefone);
        banco.SetCodigoBanco(dado5);
        account1.SetBanco(banco);
        agencia.SetAgencia(dado6);
        account1.SetAgencia(agencia);
        conta.SetConta(dado7);
        account1.SetConta(conta);
        if(dado13==1){
            banco2.SetCodigoBanco(dado8);
            account2.SetBanco(banco2);
            agencia2.SetAgencia(dado9);
            account2.SetAgencia(agencia2);
            conta2.SetConta(dado10);
            account2.SetConta(conta2);
        }
        senha.SetSenha(dado11);
        user.SetSenha(senha);
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
int TelaUsuario::TelaOptUsuario(){
    char campo1[]="1-VISUALIZAR DADOS.";
    char campo2[]="2-ALTERAR DADOS.";
    char campo3[]="3-EXCLUIR CONTA.";
    char campo4[]="Digite o numero da opcao desejada:";
    char msgerro[]="Opcao invalida!";
    int dado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2-6,9,"%s",campo1);
        mvprintw(linha/2-4,9,"%s",campo2);
        mvprintw(linha/2-2,9,"%s",campo3);
        mvprintw(linha/2,9,"%s",campo4);
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
void TelaUsuario::TelaVisualizarDados(User& user, Account& account1, Account& account2){
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
    mvprintw(linha/2-10,9,"%s",campo1+user.GetNome().GetNome());
    mvprintw(linha/-8,9,"%s",campo2+user.GetEmail().GetEmail());
    mvprintw(linha/2-6,9,"%s",campo3+user.GetCpf().GetCpf());
    mvprintw(linha/2-4,9,"%s",campo4+user.GetTelefone().GetTelefone());
    mvprintw(linha/2-2,9,"%s",campo5+account1.GetBanco().GetCodigoBanco());
    mvprintw(linha/2,9,"%s",campo6+account1.GetAgencia().GetAgencia());
    mvprintw(linha/2+2,9,"%s",campo7+account1.GetConta().GetConta());
    mvprintw(linha/2+4,9,"%s",campo8+account2.GetBanco().GetCodigoBanco());
    mvprintw(linha/2+6,9,"%s",campo9+account2.GetAgencia().GetAgencia());
    mvprintw(linha/2+8,9,"%s",campo9+account2.GetConta().GetConta());
    noecho();
    getch();
    echo();
    clear();
    endwin();
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaUsuario::TelaAlterarDados(User& user, Account& account1, Account& account2) throw(invalid_argument){
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
    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    Cpf cpf;
    Banco banco,banco2;
    Agencia agencia,agencia2;
    Conta conta,conta2;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2-12,9,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/2-10,9,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/2-8,9,"%s",campo3);
    getstr(dado3);
    mvprintw(linha/2-6,9,"%s",campo4);
    getstr(dado4);
    mvprintw(linha/2-4,9,"%s",campo5);
    scanw("%d",&dado5);
    mvprintw(linha/2-2,9,"%s",campo6);
    getstr(dado6);
    mvprintw(linha/2,9,"%s",campo7);
    getstr(dado7);
    mvprintw(linha/2+2,9,"%s",campo13);
    scanw("%d",&dado13);
    mvprintw(linha/2+4,9,"%s",campo8);
    scanw("%d",&dado8);
    mvprintw(linha/2+6,9,"%s",campo9);
    getstr(dado9);
    mvprintw(linha/2+8,9,"%s",campo10);
    getstr(dado10);
    mvprintw(linha/2+10,9,"%s",campo11);
    getstr(dado11);
    mvprintw(linha/2+12,9,"%s",campo12);
    scanw("%d",&dado12);
    clear();
    endwin();
    if(dado12==1){
        nome.SetNome(dado1);
        user.SetNome(nome);
        email.SetEmail(dado2);
        user.SetEmail(email);
        cpf.SetCpf(dado3);
        user.SetCpf(cpf);
        telefone.SetTelefone(dado4);
        user.SetTelefone(telefone);
        banco.SetCodigoBanco(dado5);
        account1.SetBanco(banco);
        agencia.SetAgencia(dado6);
        account1.SetAgencia(agencia);
        conta.SetConta(dado7);
        account1.SetConta(conta);
        if(dado13==1){
            banco2.SetCodigoBanco(dado8);
            account2.SetBanco(banco2);
            agencia2.SetAgencia(dado9);
            account2.SetAgencia(agencia2);
            conta2.SetConta(dado10);
            account2.SetConta(conta2);
        }
        senha.SetSenha(dado11);
        user.SetSenha(senha);
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaUsuario::TelaExcluirDados(Senha& senha) throw(invalid_argument){
    char campo1[]="Digite a senha: ";
    char campo3[]="Digite 1 para continuar ou 0 para voltar:";
    char dado1[80];
    int dado;
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2-1,9,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/2+1,9,"%s",campo3);
    scanw("%d",&dado);
    clear();
    endwin();
    if(dado==1){
        senha.SetSenha(dado1);
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
int TelaCarona::TelaOptCarona(){
    char campo1[]="1-CADASTRAR CARONA.";
    char campo2[]="2-DESCADASTRAR CARONA.";
    char campo3[]="3-RESERVAS DA CARONA.";
    char campo4[]="Digite o numero da opcao desejada:";
    char msgerro[]="Opcao invalida!";
    int dado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2-3,9,"%s",campo1);
        mvprintw(linha/2-1,9,"%s",campo2);
        mvprintw(linha/2+1,9,"%s",campo3);
        mvprintw(linha/2+3,9,"%s",campo4);
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
void TelaCarona::TelaCadastrarCarona(Ride& ride) throw(invalid_argument){
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
    int dado1,dado7,dado8,dado10;
    int linha,coluna;
    CodigoCarona codigocarona;
    CidadeOrigem cidadeorigem;
    CidadeDestino cidadedestino;
    EstadoOrigem estadoorigem;
    EstadoDestino estadodestino;
    Data data;
    Duracao duracao;
    Vagas vagas;
    Preco preco;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2-9,9,"%s",campo1);
    scanw("%d",&dado1);
    mvprintw(linha/2-7,9,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/2-5,9,"%s",campo3);
    getstr(dado3);
    mvprintw(linha/2-3,9,"%s",campo4);
    getstr(dado4);
    mvprintw(linha/2-1,9,"%s",campo5);
    getstr(dado5);
    mvprintw(linha/2+1,9,"%s",campo6);
    getstr(dado6);
    mvprintw(linha/2+3,9,"%s",campo7);
    scanw("%d",&dado7);
    mvprintw(linha/2+5,9,"%s",campo8);
    scanw("%d",&dado8);
    mvprintw(linha/2+7,9,"%s",campo9);
    getstr(dado9);
    mvprintw(linha/2+9,9,"%s",campo10);
    scanw("%d",&dado10);
    clear();
    endwin();
    if(dado10==1){
        codigocarona.SetCodigoCarona(dado1);
        ride.SetCodigoCarona(codigocarona);
        estadoorigem.SetEstadoOrigem(dado2);
        ride.SetEstadoOrigem(estadoorigem);
        cidadeorigem.SetCidadeOrigem(dado3);
        ride.SetCidadeOrigem(cidadeorigem);
        estadodestino.SetEstadoDestino(dado4);
        ride.SetEstadoDestino(estadodestino);
        cidadedestino.SetCidadeDestino(dado5);
        ride.SetCidadeDestino(cidadedestino);
        data.SetData(dado6);
        ride.SetData(data);
        duracao.SetDuracao(dado7);
        ride.SetDuracao(duracao);
        vagas.SetVagas(dado8);
        ride.SetVagas(vagas);
        preco.SetPreco(dado9);
        ride.SetPreco(preco);
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaCarona::TelaDescadastrarCarona(Ride& ride){
    char campo1[]="Codigo da carona: ";
    char campo2[]="Digite 1 para continuar ou 0 para voltar:";
    int dado1,dado2;
    int linha,coluna;
    CodigoCarona codigocarona;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2-2,9,"%s",campo1);
    scanw("%d",&dado1);
    mvprintw(linha/2,9,"%s",campo2);
    scanw("%d",&dado2);
    clear();
    endwin();
    if(dado2==1){
        codigocarona.SetCodigoCarona(dado1);
        ride.SetCodigoCarona(codigocarona);
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaCarona::TelaListaReservas(Ride& ride){





}
//-----------------------------------------------------------------------------------------------------------------------------------
int TelaReserva::TelaOptReserva(){
    char campo1[]="1-CADASTRAR RESERVA.";
    char campo2[]="2-DESCADASTRAR RESERVA.";
    char campo3[]="3-VISUALIZAR RESERVA.";
    char campo4[]="Digite o numero da opcao desejada:";
    char msgerro[]="Opcao invalida!";
    int dado;
    int linha,coluna;

    do{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2-3,9,"%s",campo1);
        mvprintw(linha/2-1,9,"%s",campo2);
        mvprintw(linha/2+1,9,"%s",campo3);
        mvprintw(linha/2+3,9,"%s",campo4);
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
void TelaReserva::TelaVisualizarReserva(Email& email){





}
//-----------------------------------------------------------------------------------------------------------------------------------
void TelaReserva::TelaCadastrarReserva(Booking& booking) throw(invalid_argument){
    char campo1[]="Digite o codigo da reserva: ";
    char campo2[]="Digite a preferencia de assento(D/T): ";
    char campo3[]="Digite o numero de bagagens: ";
    char campo4[]="Digite 1 para continuar ou 0 para voltar:";
    char dado2;
    int dado1,dado3,dado4;
    int linha,coluna;
    CodigoReserva codigoreserva;
    Assento assento;
    Bagagem bagagem;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2-3,9,"%s",campo1);
    scanw("%d",&dado1);
    mvprintw(linha/2-1,9,"%s",campo2);
    scanw("%c",&dado2);
    mvprintw(linha/2+1,9,"%s",campo3);
    scanw("%d",&dado3);
    mvprintw(linha/2+3,9,"%s",campo4);
    scanw("%d",&dado4);
    clear();
    endwin();
    if(dado4==1){
        codigoreserva.SetCodigoReserva(dado1);
        booking.SetCodigoReserva(codigoreserva);
        assento.SetAssento(dado2);
        booking.SetAssento(assento);
        bagagem.SetBagagem(dado3);
        booking.SetBagagem(bagagem);
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
    mvprintw(linha/2-1,9,"%s",campo1);
    mvprintw(linha/2+1,9,"%s",campo2);
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
    mvprintw(linha/2,9,"%s",str.c_str());
    noecho();
    getch();
    echo();
    clear();
    endwin();
}
