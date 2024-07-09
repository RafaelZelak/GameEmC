#ifndef GAMEMENULIB_H_INCLUDED
#define GAMEMENULIB_H_INCLUDED
void titulo()
{
    gotoxy(49,2);
    printf("%c%c%c%c%c %c  %c %c%c%c%c",219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(49,3);
    printf("  %c   %c  %c %c",219,219,219,219);
    gotoxy(49,4);
    printf("  %c   %c%c%c%c %c%c%c",219,219,219,219,219,219,219,219);
    gotoxy(49,5);
    printf("  %c   %c  %c %c",219,219,219,219);
    gotoxy(49,6);
    printf("  %c   %c  %c %c%c%c%c",219,219,219,219,219,219,219);

    gotoxy(42,8);
    printf("%c  %c %c%c  %c %c%c%c  %c%c%c%c %c%c%c%c %c%c  %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(42,9);
    printf("%c  %c %c %c %c %c  %c %c  %c %c  %c %c %c %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(42,10);
    printf("%c  %c %c %c %c %c%c%c  %c  %c %c%c%c%c %c %c %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(42,11);
    printf("%c  %c %c %c %c %c  %c %c  %c %c %c  %c %c %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(42,12);
    printf("%c%c%C%c %c  %c%c %c%c%c  %c%c%c%c %c  %c %c  %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void controle()
{
    gotoxy(37,2);
    printf("%c%c%c%c %c%c%c%c %c%c  %c %c%c%c%c%c %c%c%c%c %c%c%c%c %c   %c%c%c%c %c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(37,3);
    printf("%c    %c  %c %c %c %c   %c   %c  %c %c  %c %c   %c    %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(37,4);
    printf("%c    %c  %c %c %c %c   %c   %c%c%c%c %c  %c %c   %c%c%c  %c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(37,5);
    printf("%c    %c  %c %c %c %c   %c   %c %c  %c  %c %c   %c       %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(37,6);
    printf("%c%c%c%c %c%c%c%c %c  %c%c   %c   %c  %c %c%c%c%c %c%c%c %c%c%c%c %c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

    gotoxy(48,9);
    printf("Andar para a Direita:   ->");
    gotoxy(48,11);
    printf("Andar para a Esquerda:  <-");
    gotoxy(48,13);
    printf("Andar para a Baixo:      %c ",25);
    gotoxy(48,15);
    printf("Andar para a Cima:       %c ",24);
    gotoxy(48,17);
    printf("Ataque Fraco:           [1]");
    gotoxy(48,19);
    printf("Ataque Forte:           [2]");
    gotoxy(48,21);
    printf("Ataqie Especial:        [3]");
    gotoxy(48,23);
    printf("Cura:                   [4]");
    gotoxy(54,26);
    printf("Voltar [ENTER]");
}

void hist()
{
    system("cls");
    gotoxy(52,2);
    printf("Hist%cria",162);
    gotoxy(8,8);
    printf("Dante ex participante da igreja ocultista, se viu em um dilema ao ter que fugir com sua mulher (Donati)");
    gotoxy(8,9);
    printf("gravida para nao ter que vender sua alma para o diabo junto de sua amada.");
    gotoxy(8,10);
    printf("porem ap%cs o nascimento perturbado de seu filho e com a morte de sua mulher durante o parto, ",162);
    gotoxy(8,11);
    printf("ele se viu em um impasse. Logo ele tenta vender a sua alma para trazer a sua mulher a vida,");
    gotoxy(8,12);
    printf("sacrificando sua vida para isso. Porem depois ser enganado pelo diabo e sua filha ser raptada pelo Diabo. ");
    gotoxy(8,13);
    printf("Ele tenta invadir o inferno em um ato de desespero, ");
    gotoxy(8,14);
    printf("utilizando os aprendizados e livros que ele possui graças ao culto.");

    gotoxy(38,25);
    printf("Pressione qualquer tecla para continuar.");
    gotoxy(0,0);
    getchar();
}

void dialogo_velho(){
    system("cls");
    system("color 87");
    gotoxy(15,5);
    printf("___");
    gotoxy(14,6);
    printf("/-   -%c",92);
    gotoxy(14,7);
    printf("|O   O|");
    gotoxy(14,8);
    printf("|_>_|");
    gotoxy(14,9);
    printf("/     %c",92);
    gotoxy(14,10);
    printf("|  _  |");
    gotoxy(12,11);
    printf("_%c     /_",92);
    gotoxy(11,12);
    printf("/   %c___/   %c",92,92);
    gotoxy(11,13);
    printf("|           |");
    gotoxy(11,14);
    printf("| |       | |");
    gotoxy(11,15);
    printf("| |       | |");
    gotoxy(11,16);
    printf("||       ||");
    gotoxy(11,17);
    printf("()|___|()");
    gotoxy(13,18);
    printf("|  | |  |");
    gotoxy(13,19);
    printf("|  | |  |");
    gotoxy(13,20);
    printf("|  | |  |");
    gotoxy(13,21);
    printf("|  | |  |");
    Sleep(500);
    int t;
    while(t != 6){
        Beep(500, 60);
        gotoxy(22,10);
        printf("Oh ignobil cavalheiro,");
        t++;
    }
    t = 1;
    Sleep(3000);
    while(t != 15){
        Beep(500, 60);
        gotoxy(22,10);
        printf("O que lhe traz em direcao de tao decreptas profundezas?");
        t++;
    }
    t = 1;
    Sleep(4500);
    while(t != 15){
        Beep(500, 60);
        gotoxy(22,10);
        printf("Nao importa, pegue esta pungente espada para proteger-lhe em sua turbulenta jornada");
        gotoxy(26,14);
        printf("           /%c",92);
        gotoxy(26,15);
        printf(" _         )( ________");
        gotoxy(26,16);
        printf("()///////(  )_______>");
        gotoxy(26,17);
        printf("           )(");
        gotoxy(26,18);
        printf("           %c/",92);
        t++;
    }
    t = 1;
    Sleep(4000);
    while(t != 10){
        Beep(500, 60);
        gotoxy(22,10);
        printf("nunca esqueça o nome dela que e Virgilio!                                             ");
        t++;
    }
    Sleep(4000);
    gotoxy(22,10);
    printf("                                                                                      ");
    Sleep(2000);
}

#endif // GAMEMENULIB_H_INCLUDED
