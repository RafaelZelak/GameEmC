#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

//boss final, vulgo lúcifer

void Fase1()
{
system("mode con cols=80 lines=25");
system("color 87");
  int a;
  gotoxy(50, 50);
  printf("%c",130);

//

  for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(0, a);
  }
//Parede horizontal superior
    for(a = 0; a < 80; a++){
    printf("%c",219);
    gotoxy(a, 0);
  }

//Parede horizontal inferior
    for(a = 0; a < 80; a++){
    printf("%c",219);
    gotoxy(a, 23);
  }

//sala1
//Parede vertical direita 1
  for(a = 1; a < 20; a++){
    printf("%c",219);
    gotoxy(20, a);

  }
//Sala 2
//Parede vertical direita 2
  for(a = 4; a < 24; a++){
    printf("%c",219);
    gotoxy(40, a);
  }
//Sala 3
//Parede vertical direita 3
  for(a = 1; a < 20; a++){
    printf("%c",219);
    gotoxy(60, a);
  }
//Parede canto direito
  for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(79, a);
  }

}
Fase2()
{

system("mode con cols=80 lines=24");
system("color 87");
  int a;
  gotoxy(50, 50);
  printf("%c",130);

//Parede horizontal superior
    for(a = 0; a < 80; a++){
    printf("%c",219);
    gotoxy(a, 8);
  }

//Parede horizontal inferior
    for(a = 0; a < 81; a++){
    printf("%c",219);
    gotoxy(a, 14);
  }
}


#endif // GAMELIB_H_INCLUDED
