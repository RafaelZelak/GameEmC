#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define Rkey 100
#include <limits.h>
#include "GameLib.h"
#include "GameSpriteLib.h"
#include "GameMenuLib.h"

int hp_up = 1, fase_var = 1, boss_var = 1, h = 1,hp = 20,hp_inimigo = 10,countdown = 3,inimigo_hp = 1,batalha_var = 1, batalha_var_2 = 1, batalha_var_3 = 1,fase=1,escolha, atk1 = 1, atk2 = 2, atk3 = 4;


//Menu
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void change_color(int color)
{
    int color_code = 15;
    if(color <= 255 && color >= 1)
    {
        color_code = color;
    }
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, color_code);
}

void sair()
{
int tecla_sair;
int opcao_sair = 1;
system("cls");
gotoxy(50,10);
printf("Vai realmente fugir?");
change_color(192);
gotoxy(50,16);
printf("  SIM  ");
change_color(12);
gotoxy(64,16);
printf("  NAO  ");
while(tecla_sair != 13){

    gotoxy(0,0);
    tecla_sair = getch();

    if(opcao_sair == 1){
        if (GetAsyncKeyState(VK_LEFT)&1){

        }else if (GetAsyncKeyState(VK_RIGHT)&1){
            change_color(12);
            gotoxy(50,16);
            printf("  SIM  ");
            gotoxy(64,16);
            change_color(192);
            printf("  NAO  ");
            change_color(12);
            opcao_sair = 2;
            }
    }if(opcao_sair == 2){
        if (GetAsyncKeyState(VK_LEFT)&1){
            change_color(192);
            gotoxy(50,16);
            printf("  SIM  ");
            change_color(12);
            gotoxy(64,16);
            printf("  NAO  ");
            opcao_sair = 1;

        }else if (GetAsyncKeyState(VK_RIGHT)&1){
            }
    }
}
if(opcao_sair == 1){
    system("cls");
    gotoxy(55,12);
    printf("MEDROSO");
    h = 2;
}else if(opcao_sair == 2){
    system("cls");
    menu();
}
}
void menu()
{
system("color 0C");

char tecla, exit;
int opcao = 1;

titulo();

change_color(192);
gotoxy(52,16);
printf("   JOGAR   ");
change_color(12);
gotoxy(52,18);
printf(" CONTROLES ");
gotoxy(52,20);
printf("   FUGIR   ");



while(tecla != 13){

    gotoxy(0,0);
    tecla = getch();

    if(opcao == 1){
        if (GetAsyncKeyState(VK_UP)&1){
            change_color(12);
            gotoxy(52,16);
            printf("   JOGAR   ");
            gotoxy(52,18);
            printf(" CONTROLES ");
            gotoxy(52,20);
            change_color(192);
            printf("   FUGIR   ");
            change_color(12);
            opcao = 3;
        }else if (GetAsyncKeyState(VK_DOWN)&1){
            change_color(12);
            gotoxy(52,16);
            printf("   JOGAR   ");
            change_color(192);
            gotoxy(52,18);
            printf(" CONTROLES ");
            change_color(12);
            gotoxy(52,20);
            printf("   FUGIR   ");
            opcao = 2;
            }
    }if(opcao == 2){
        if (GetAsyncKeyState(VK_UP)&1){
            change_color(192);
            gotoxy(52,16);
            printf("   JOGAR   ");
            change_color(12);
            gotoxy(52,18);
            printf(" CONTROLES ");
            gotoxy(52,20);
            printf("   FUGIR   ");
            opcao = 1;

        }else if (GetAsyncKeyState(VK_DOWN)&1){
            change_color(12);
            gotoxy(52,16);
            printf("   JOGAR   ");
            gotoxy(52,18);
            printf(" CONTROLES ");
            change_color(192);
            gotoxy(52,20);
            printf("   FUGIR   ");
            change_color(12);
            opcao = 3;
            }
    }if(opcao == 3){

            if (GetAsyncKeyState(VK_UP)&1){
            change_color(12);
            gotoxy(52,16);
            printf("   JOGAR   ");
            change_color(192);
            gotoxy(52,18);
            printf(" CONTROLES ");
            change_color(12);
            gotoxy(52,20);
            printf("   FUGIR   ");
            opcao = 2;

        }else if (GetAsyncKeyState(VK_DOWN)&1){
            change_color(192);
            gotoxy(52,16);
            printf("   JOGAR   ");
            change_color(12);
            gotoxy(52,18);
            printf(" CONTROLES ");
            gotoxy(52,20);
            printf("   FUGIR   ");
            opcao = 1;
            }
    }
}
if(opcao == 1){

    gotoxy(5,20);
    h = 3;
    return 0;

}if(opcao == 2){
    system("cls");
    controle();
    gotoxy(0,0);
    getchar();
    system("cls");


}if(opcao == 3){
    sair();


}
tecla = 1;
gotoxy(5,20);

}

//Game
void atk_boss()
{

//gera um numero aleatorio entre 0 - 3
    srand(time(0));
    int val_atk = rand() % 5;

//ataque do inimigo de acordo com o valor gerado na variavel (val_atk)

//atk simples caso a variavel esteja em 0
    if(val_atk == 0){

        hp = hp-2;
        boss_garra();
        Sleep(200);
        boss_atk_0();
        gotoxy(41,18);
        printf("O INIMIGO UTILIZOU UM ATAQUE SIMPLES");
//atk forte caso a variavel esteja em 1
    }else if(val_atk == 1){

        hp = hp-4;
        boss_mordida();
        gotoxy(43,18);
        printf("O INIMIGO UTILIZOU UM ATAQUE FORTE");
//defesa caso a variavel esteja em 2
    }else if(val_atk == 2){

            hp_inimigo = hp_inimigo+3;
            boss_cura();
            gotoxy(56,18);
        printf("O BOSS SE CUROU");
//inimigo não faz caso a variavel esteja em 3
        }else if(val_atk == 3){

        boss_atk_1();
        gotoxy(56,18);
        printf("O INIMIGO N/ FEZ NADA");
    }


}
void boss()
{
    system("mode con cols=120 lines=28");
    int a;
    int k;

    int opcao = 1, tecla;


    system("cls");
    for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(0, a);
  }
//Parede horizontal superior
    for(a = 1; a < 120; a++){
    printf("%c",219);
    gotoxy(a, 0);
  }

//Parede horizontal inferior
    for(a = 1; a < 120; a++){
    printf("%c",219);
    gotoxy(a, 23);
  }

//Parede canto direito
    for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(79, a);
  }
//menu
    for(a = 1; a < 80; a++){
    printf("%c",219);
    gotoxy(a, 16);
  }
    for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(119, a);
    }
  //Ataque
    gotoxy(6,7);
    gotoxy(85,2);
    printf("Ataque Basico: 1 ATK");
    gotoxy(85,4);
    printf ("Ataque Forte: 2 ATK");

    gotoxy(85,6);
    printf("Ataque Especial: 4 ATK");
    gotoxy(85,8);
    printf ("Recuperar vida");

    personagem_atk_0();

    if(countdown <= 0){
    gotoxy(82,12);
    printf ("Countdown do 'Ataque Especial' - [0]");
    }else{
    gotoxy(82,12);
    printf("Countdown do 'Ataque Especial' - [%d]", countdown);
    }



//loop batalha

while(hp_inimigo > 0){
  boss_atk_0();
  gotoxy(61,21);
  printf ("HP BOSS: %d/20 ",hp_inimigo);
  gotoxy(3,3);
  atk_boss();
  gotoxy(3,21);
  printf("HP: %d/20",hp);
  gotoxy(3,18);
  printf("[                             ]");


gotoxy(81,2);
printf("->");

while(tecla != 13){

    gotoxy(0,0);
    tecla = getch();

    if(opcao == 1){
        if (GetAsyncKeyState(VK_UP)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("->");
            opcao = 4;
        }else if (GetAsyncKeyState(VK_DOWN)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("->");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("  ");
            opcao = 2;
            }
    }if(opcao == 2){
        if (GetAsyncKeyState(VK_UP)&1){
            gotoxy(81,2);
            printf("->");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("  ");
            opcao = 1;

        }else if (GetAsyncKeyState(VK_DOWN)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("->");
            gotoxy(81,8);
            printf("  ");

            opcao = 3;
            }
    }if(opcao == 3){

            if (GetAsyncKeyState(VK_UP)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("->");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("  ");
            opcao = 2;

        }else if (GetAsyncKeyState(VK_DOWN)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("->");
            opcao = 4;
        }
            }if (opcao == 4){

            if (GetAsyncKeyState(VK_UP)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("->");
            gotoxy(81,8);
            printf("  ");
            opcao = 3;

        }else if (GetAsyncKeyState(VK_DOWN)&1){
            gotoxy(81,2);
            printf("->");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("  ");
            opcao = 1;
            }

    }
}



  if(opcao == 1){
    gotoxy(3,18);
    printf("[  DANTE DEU UM ATAQUE FRACO  ]");
    countdown--;
    hp_inimigo--;
    boss_atk_0();
    personagem_atk_1();
    gotoxy(61,21);
    printf ("HP BOSS: %d/20 ",hp_inimigo);
    gotoxy(19,25);

    system("pause");
    boss();
    system("cls");

  }else if(opcao == 2){
    gotoxy(3,18);
    printf("[  DANTE DEU UM ATAQUE FORTE  ]");
    countdown--;
    boss_atk_0();
    hp_inimigo = hp_inimigo-2;
    personagem_atk_2();
    gotoxy(61,21);
    printf ("HP BOSS: %d/20 ",hp_inimigo);
    gotoxy(19,25);

    system("pause");
    boss();
    system("cls");

  }else if(opcao == 4){
    gotoxy(3,18);
    printf("[      DANTE SE CUROU         ]");
    boss_atk_0();
    personagem_cura();
    countdown--;
    if(hp >= 20){
        gotoxy(3,19);
        printf("A sua vida encontra-se cheia");
        gotoxy(19,25);
    }else{
        hp = hp + 4;
    }
    gotoxy(61,21);
    printf ("HP BOSS: %d/20 ",hp_inimigo);
    gotoxy(19,25);

    system("pause");
    boss();
    system("cls");


  }else if(opcao == 3){
    gotoxy(3,18);
    printf("[DANTE DEU UM ATAQUE ESPECIAL ]");
    boss_atk_0();
    if(countdown <= 0){
        hp_inimigo = hp_inimigo-4;
        personagem_atk_4();
        countdown = 3;
        gotoxy(61,21);
        printf ("HP INIMIGP: %d/10 ",hp_inimigo);
        gotoxy(19,25);
    }else{
        gotoxy(3,19);
        printf("A habilidade esta em countdown, espere mais %d rodadas",countdown);
        gotoxy(19,25);
    }

    system("pause");
    boss();
    system("cls");
        }else{
        gotoxy(3,22);
        printf("Ataque n/ existente               ");
        gotoxy(19,24);
        system("pause");
        batalha();
        system("cls");
        }
    hp = 20;
    circulo1();
        }
    }
void sprite_inimigo_circulo1()
{
//função para os inimigos aparecerem no cenário

    if(hp_up == 1){
    gotoxy(30,12);
    printf("%c",3);
    }else if(hp_up == 0){
    gotoxy(30,12);
    printf("");
    }
    if(batalha_var == 0){
    gotoxy(20, 21);
    printf("");
    }if(batalha_var == 1){
    gotoxy(20, 21);
    printf("%c",190);
    }if(batalha_var_2 == 0){
    gotoxy(40, 2);
    printf("");
    }if(batalha_var_2 == 1){
    gotoxy(40, 2);
    printf("%c",190);
    }if(batalha_var_3 == 0){
    gotoxy(60, 21);
    printf("");
    }if(batalha_var_3 == 1){
    gotoxy(60, 21);
    printf("%c",190);
    }
if(boss_var == 1){
change_color(132);
gotoxy(67,3);
printf("/%c__/%c",92,92);
gotoxy(66,4);
printf("| %c  / |",92);
gotoxy(66,5);
printf("| 0  0 |");
gotoxy(67,6);
printf("%c .. /",92);
gotoxy(68,7);
printf("%c__/",92);
change_color(135);
}else if(boss_var == 0){

}
}
void circulo1()
{

if(fase_var == 1){
    Fase1();
}else if(fase_var == 2){
    system("cls");
    Fase2();
}

}
void atk_inimigo()
{
//rng para o ataque do inimigo
//gera um numero aleatorio entre 0 - 3
    srand(time(0));
    int val_atk = rand() % 4;

//ataque do inimigo de acordo com o valor gerado na variavel (val_atk)

//atk simples caso a variavel esteja em 0
    if(val_atk == 0){

        hp--;
        inimigo_atk_0();
        Sleep(200);
        inimigo_atk_1();
        gotoxy(41,18);
        printf("O INIMIGO UTILIZOU UM ATAQUE SIMPLES");
//atk forte caso a variavel esteja em 1
    }else if(val_atk == 1){

        hp = hp-3;
        inimigo_atk_0();
        inimigo_atk_2();
        gotoxy(43,18);
        printf("O INIMIGO UTILIZOU UM ATAQUE FORTE");
//defesa caso a variavel esteja em 2
    }else if(val_atk == 2){

            hp_inimigo++;
            inimigo_atk_0();
            inimigo_def();
            gotoxy(56,18);
        printf("O INIMIGO SE DEFENDEU");
//inimigo não faz caso a variavel esteja em 3
        }else if(val_atk == 3){

        gotoxy(56,18);
        printf("O INIMIGO N/ FEZ NADA");
    }


}
void up()
{
char tecla;
int opcao = 1;
gotoxy(30,12);
change_color(143);
printf(" ESCOLHA SEU UPGRADE");
change_color(15);
gotoxy(30,16);
printf("   ATAQUE BASICO    ");
change_color(143);
gotoxy(30,18);
printf("    ATAQUE FORTE    ");
gotoxy(30,20);
printf("   ATAQUE ESPECIAL  ");



while(tecla != 13){

    gotoxy(0,0);
    tecla = getch();

    if(opcao == 1){
        if (GetAsyncKeyState(VK_UP)&1){
            change_color(143);
            gotoxy(30,16);
            printf("   ATAQUE BASICO    ");
            gotoxy(30,18);
            printf("    ATAQUE FORTE    ");
            gotoxy(30,20);
            change_color(15);
            printf("   ATAQUE ESPECIAL  ");
            change_color(143);
            opcao = 3;
        }else if (GetAsyncKeyState(VK_DOWN)&1){
            change_color(143);
            gotoxy(30,16);
            printf("   ATAQUE BASICO    ");
            change_color(15);
            gotoxy(30,18);
            printf("    ATAQUE FORTE    ");
            change_color(143);
            gotoxy(30,20);
            printf("   ATAQUE ESPECIAL  ");
            opcao = 2;
            }
    }if(opcao == 2){
        if (GetAsyncKeyState(VK_UP)&1){
            change_color(15);
            gotoxy(30,16);
            printf("   ATAQUE BASICO    ");
            change_color(143);
            gotoxy(30,18);
            printf("    ATAQUE FORTE    ");
            gotoxy(30,20);
            printf("   ATAQUE ESPECIAL  ");
            opcao = 1;

        }else if (GetAsyncKeyState(VK_DOWN)&1){
            change_color(143);
            gotoxy(30,16);
            printf("   ATAQUE BASICO    ");
            gotoxy(30,18);
            printf("    ATAQUE FORTE    ");
            change_color(15);
            gotoxy(30,20);
            printf("   ATAQUE ESPECIAL  ");
            change_color(143);
            opcao = 3;
            }
    }if(opcao == 3){

            if (GetAsyncKeyState(VK_UP)&1){
            change_color(143);
            gotoxy(30,16);
            printf("   ATAQUE BASICO    ");
            change_color(15);
            gotoxy(30,18);
            printf("    ATAQUE FORTE    ");
            change_color(143);
            gotoxy(30,20);
            printf("   ATAQUE ESPECIAL  ");
            opcao = 2;

        }else if (GetAsyncKeyState(VK_DOWN)&1){
            change_color(15);
            gotoxy(30,16);
            printf("   ATAQUE BASICO    ");
            change_color(143);
            gotoxy(30,18);
            printf("    ATAQUE FORTE    ");
            gotoxy(30,20);
            printf("   ATAQUE ESPECIAL  ");
            opcao = 1;
            }
    }
}
    if(opcao == 1){
        atk1 = 2;
    }else if(opcao == 2){
        atk2 = 3;
    }else if(opcao == 3){
        atk3 = 5;
    }
}
void personagem()
{



    int x,a,d=2,cx[300]={2,2},cy[300]={2,2},t=1,upgrade;
    char tecla='a';
    char run;
    gotoxy(2,2);
    printf("%c",219);

    do
    {
        sprite_inimigo_circulo1();

        while(tecla != 's' &&! (tecla=kbhit()))
        {
            //Apaga o caractere de traz
            for(x = t; x > 0; x--)
            {
                cx[x] = cx[x-1];
                cy[x] = cy[x-1];
            }
            //Bug personagem anda em qualquer tecla
            //Movimentação
             gotoxy(0,0);
             run=getch();

             if(d==0)cx[0]--;
             if(d==1)cy[0]--;
             if(d==2)cx[0]++;
             if(d==3)cy[0]++;


             gotoxy(cx[t],cy[t]);
             printf(" ");
             gotoxy(cx[0],cy[0]);
             printf("%c",219);

            //Velocidade do personagem
             Sleep(1);

            //Colisão Limite
             if(cy[0]==23)cy[0]--;
             if(cx[0]==79)cx[0]--;
             if(cy[0]==0)cy[0]++;
             if(cx[0]==0)cx[0]++;


             if(fase == 1){
             //paredes internas
             if(cx[0]==20){
                if(cy[0]>=1 && cy[0]<=19){

                    if(d == 2){cx[0]--;}
                    if(d == 0){cx[0]++;}
                }
             }
             if(cx[0]==40){
                if(cy[0]>=4 && cy[0]<=24){

                    if(d == 2){cx[0]--;}
                    if(d == 0){cx[0]++;}
                }
             }
            if(cx[0]==60){
                if(cy[0]>=1 && cy[0]<=19){

                    if(d == 2){cx[0]--;}
                    if(d == 0){cx[0]++;}
                }
             }

                //teleporte testes
                gotoxy(5,5);
                printf("O");
                if(cy[0]==5){
                if(cx[0]>=5 && cx[0]<=5){cx[0] = 65;cy[0] = 15;}
                }


                if(cy[0]==2){
                if(cx[0]>=60 && cx[0]<=70){fase = 2;}
            }

        //Ativador inimigo 1
             if(batalha_var == 1){
                if(cx[0]==20){
                    if(cy[0]>=19 && cy[0]<=22){system("cls"); batalha(); batalha_var = 0; }
                }
             }
        //Ativador inimigo 2
             if(batalha_var_2 == 1){
                if(cx[0]==40){system("cls"); hp_inimigo = 10;batalha(); batalha_var_2 = 0;}
             }
        //Ativador inimigo 3
             if(batalha_var_3 == 1){
                if(cx[0]==60){system("cls"); hp_inimigo = 10;batalha(); batalha_var_3 = 0;}
             }
        //Ativador boss

         if(boss_var == 1){
            if(cy[0]==9){
                if(cx[0]>=60 && cx[0]<=90){system("cls"); hp_inimigo = 1; boss(); boss_var = 0;}
            }
         }

         //ativador  cura
         if(hp_up == 1){
            if(cx[0]== 30 ){
                    if(cy[0] == 12){
                        hp = 20;
                        hp_up = 0;
                    }
                }
         }

        }else if(fase == 2){

                system("cls");
                up();
                fase_var = 2; circulo1(); cx[0] = 1; cy[0] = 12; fase = 0;batalha_var_3 = 10;batalha_var_2 = 10;batalha_var = 10;hp_up = 10;

        }

    }

         if(tecla!='s')tecla=getch();
         if(tecla=='K')d=0;
         if(tecla=='H')d=1;
         if(tecla=='M')d=2;
         if(tecla=='P')d=3;
         //Limite Tela
         if(cy[0]==0||cy[0]==23||cx[0]==0||cx[0]==79)tecla='s';

    }while(tecla != 's');


}
void batalha()
{
    system("mode con cols=120 lines=28");

    int a;
    int k;

    int tecla, opcao = 1;


    system("cls");
    for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(0, a);
  }
//Parede horizontal superior
    for(a = 1; a < 120; a++){
    printf("%c",219);
    gotoxy(a, 0);
  }

//Parede horizontal inferior
    for(a = 1; a < 120; a++){
    printf("%c",219);
    gotoxy(a, 23);
  }

//Parede canto direito
    for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(79, a);
  }
//menu
    for(a = 1; a < 80; a++){
    printf("%c",219);
    gotoxy(a, 16);
  }
    for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(119, a);
    }
  //Ataque
    gotoxy(6,7);
    gotoxy(85,2);
    printf("Ataque Basico: 1 ATK");
    gotoxy(85,4);
    printf ("Ataque Forte: 2 ATK");

    gotoxy(85,6);
    printf("Ataque Especial: 4 ATK");
    gotoxy(85,8);
    printf ("Recuperar vida");

    personagem_atk_0();

    if(countdown <= 0){
    gotoxy(82,12);
    printf ("Countdown do 'Ataque Especial' - [0]");
    }else{
    gotoxy(82,12);
    printf("Countdown do 'Ataque Especial' - [%d]", countdown);
    }



//loop batalha

while(hp_inimigo > 0){
  inimigo_atk_0();
  gotoxy(61,21);
  change_color(132);
  printf ("HP INIMIGP: %d/10 ",hp_inimigo);
  change_color(135);
  gotoxy(3,3);
  atk_inimigo();
  gotoxy(3,21);
  change_color(132);
  printf("HP: %d/20",hp);
  change_color(135);

  gotoxy(3,18);
  printf("[                             ]");


gotoxy(81,2);
printf("->");

while(tecla != 13){

    gotoxy(0,0);
    tecla = getch();

    if(opcao == 1){
        if (GetAsyncKeyState(VK_UP)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("->");
            opcao = 4;
        }else if (GetAsyncKeyState(VK_DOWN)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("->");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("  ");
            opcao = 2;
            }
    }if(opcao == 2){
        if (GetAsyncKeyState(VK_UP)&1){
            gotoxy(81,2);
            printf("->");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("  ");
            opcao = 1;

        }else if (GetAsyncKeyState(VK_DOWN)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("->");
            gotoxy(81,8);
            printf("  ");

            opcao = 3;
            }
    }if(opcao == 3){

            if (GetAsyncKeyState(VK_UP)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("->");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("  ");
            opcao = 2;

        }else if (GetAsyncKeyState(VK_DOWN)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("->");
            opcao = 4;
        }
            }if (opcao == 4){

            if (GetAsyncKeyState(VK_UP)&1){
            gotoxy(81,2);
            printf("  ");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("->");
            gotoxy(81,8);
            printf("  ");
            opcao = 3;

        }else if (GetAsyncKeyState(VK_DOWN)&1){
            gotoxy(81,2);
            printf("->");
            gotoxy(81,4);
            printf("  ");
            gotoxy(81,6);
            printf("  ");
            gotoxy(81,8);
            printf("  ");
            opcao = 1;
            }

    }
}



  if(opcao == 1){
    gotoxy(3,18);
    printf("[  DANTE DEU UM ATAQUE FRACO  ]");
    countdown--;
    hp_inimigo = hp_inimigo - atk1;
    personagem_atk_1();
    gotoxy(61,21);
    change_color(132);
    printf ("HP INIMIGP: %d/10 ",hp_inimigo);
    change_color(135);
    gotoxy(19,25);

    system("pause");
    batalha();
    system("cls");

  }else if(opcao == 2){
    gotoxy(3,18);
    printf("[  DANTE DEU UM ATAQUE FORTE  ]");
    countdown--;
    hp_inimigo = hp_inimigo - atk2;
    personagem_atk_2();
    gotoxy(61,21);
    change_color(132);
    printf ("HP INIMIGP: %d/10 ",hp_inimigo);
    change_color(135);
    gotoxy(19,25);

    system("pause");
    batalha();
    system("cls");

  }else if(opcao == 4){
    gotoxy(3,18);
    printf("[      DANTE SE CUROU         ]");
    personagem_cura();
    countdown--;
    if(hp >= 20){
        gotoxy(3,19);
        printf("A sua vida encontra-se cheia");
        gotoxy(19,25);
    }else{
        hp = hp + 4;
    }
    gotoxy(61,21);
    change_color(132);
    printf ("HP INIMIGP: %d/10 ",hp_inimigo);
    change_color(135);
    gotoxy(19,25);

    system("pause");
    batalha();
    system("cls");


  }else if(opcao == 3){
    gotoxy(3,18);
    printf("[DANTE DEU UM ATAQUE ESPECIAL ]");
    if(countdown <= 0){
        hp_inimigo = hp_inimigo - atk3;
        personagem_atk_4();
        countdown = 3;
        gotoxy(61,21);
        change_color(132);
        printf ("HP INIMIGP: %d/10 ",hp_inimigo);
        change_color(135);
        gotoxy(19,25);
    }else{
        gotoxy(3,19);
        printf("A habilidade esta em countdown, espere mais %d rodadas",countdown);
        gotoxy(19,25);
    }

    system("pause");
    batalha();
    system("cls");
        }else{
        gotoxy(3,22);
        printf("Ataque n/ existente               ");
        gotoxy(19,24);
        system("pause");
        batalha();
        system("cls");
        }
    hp = 20;
    circulo1();
        }
    }
int main()
{
    SetConsoleTitle(" THE UNBORN ");
    system("mode con cols=120 lines=28");
    do{
    menu();
    }while(h == 1);
    if(h == 2){
        gotoxy(10,25);
        return;
    }if(h == 3){
        hist();

    }

    system("cls");
    circulo1();
    personagem();
    getchar();
}
