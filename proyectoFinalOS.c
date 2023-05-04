#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

char tablero_atacar_jugador1[10][10];
char tablero_jugador1[10][10];
char tablero_atacar_jugador2[10][10];
char tablero_jugador2[10][10];

//Funcion para hundir barcos
bool barcos_hundidos(char matriz[10][10], char symbol){

int barcos=0;
  int i,j;
  for(i=0;i<10;i++){

    for(j=0;j<10;j++){
      if(matriz[i][j]==symbol){
          barcos++;       
      }    
    }
  }
  if(barcos==10){
    return true;
    } else {
    return false; 
  }
}

void creacionTablero() //Genera el tablero con '*' para el jugador 1 y con '+' para el jugador 2
{
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tablero_jugador1[i][j] = '*';
      tablero_jugador2[i][j] = '*';
      tablero_atacar_jugador1[i][j] = '*';
      tablero_atacar_jugador2[i][j] = '*';
    }
  }
}
void imprimir_tablero(char tablero[][10]) // CONTROLAR EL MOVIMIENTO DE LOS PROCESOS
{
  /*------------------------------------------------------------------------------------
    Quite los procesos porque daban cosas bien raras, solamente creo que se debería de         
    controlar la salida de cada procesos para que salga en orden.
    -----------------------------------------------------------------------------------*/
    for (int n = 0; n < 10; n++) 
    {
      printf("   %d", n);
    }
  printf("\n\n");
    for (int i = 0; i < 10; i++) 
    {
      printf("%d  ", i);
      for (int j = 0; j < 10; j++) {
        printf("%c   ", tablero[i][j]);
      }
      printf("\n\n\n");
    }
}

int game()   //Funcion juego, lleva todo el mecanismo del juego
{  
  system("clear");
  creacionTablero();    //Se crean los tableros "vacíos"
  int counter = 0;
  int x = 0;
  int y = 0;
  int score_jugador1, score_jugador2;
  char orientacion;
  
  printf("Jugador 1, coloca tus naves: \n\n\n");
  imprimir_tablero(tablero_jugador1);
  for(int i = 4; i>=1; i--)    //Bucle anidado que logra guardar los barcos de los jugadores
  {
    printf("Barco de %d unidades\n\n", i);
    printf("Posición del barco %d en el tablero: (h = horizontal. v = vertical)\n", i);
    scanf(" %c", &orientacion);
    system("clear");
    imprimir_tablero(tablero_jugador1);
    printf("coordenada en x del barco de %d unidades: ", i);
    scanf(" %d", &x );
    printf("coordenada en y del barco de %d unidades: ", i); 
    scanf(" %d", &y );
    tablero_jugador1[x][y]='/';
    system("clear");
    imprimir_tablero(tablero_jugador1);
        //Si el barco será horizontal, solamente pide coordenadas en y
    if (orientacion == 'h') 
    {
        for (int j =2; j<=i; j++ )    //Se llenan los diferentes tipos de barcos
        {
            printf("coordenada en y del barco de %d unidades: ", i);
            scanf(" %d", &y );
            tablero_jugador1[x][y]='/';
            system("clear");
            imprimir_tablero(tablero_jugador1);
        } 
    }
        //Si el barco será horizontal, solamente pide coordenadas en y
    if (orientacion == 'v')
    {
      for (int j =2; j<=i; j++ )    //Se llenan los diferentes tipos de barcos
      {
        printf("coordenada en x del barco de %d unidades: ", i);
        scanf(" %d", &x );
        tablero_jugador1[x][y]='/';
        system("clear");
        imprimir_tablero(tablero_jugador1);
        } 
    }

  }
        //Empieza el llenado de los barcos del jugador 2
  system("clear");
    printf("Jugador 2, coloca tus naves: \n\n\n");
    imprimir_tablero(tablero_jugador2);
    for(int i = 4; i>=1; i--)    //Bucle anidado que logra guardar los barcos de los jugadores
  {
    printf("Barco de %d unidades\n\n", i);
    printf("Posición del barco %d en el tablero: (h = horizontal. v = vertical)\n", i);
    scanf(" %c", &orientacion);
    printf("coordenada en x del barco de %d unidades: ", i);
    scanf(" %d", &x );
    printf("coordenada en y del barco de %d unidades: ", i); 
    scanf(" %d", &y );
    tablero_jugador2[x][y]='|'; 
    system("clear");
    imprimir_tablero(tablero_jugador2);
    if (orientacion == 'h')
    {
        for (int j =2; j<=i; j++ )    //Se llenan los diferentes tipos de barcos
        {
            printf("coordenada en y del barco de %d unidades: ", i);
            scanf(" %d", &y );
            tablero_jugador2[x][y]='|';
            system("clear");
            imprimir_tablero(tablero_jugador2);
        } 
    }
    if (orientacion == 'v')
    {
      for (int j =2; j<=i; j++ )    //Se llenan los diferentes tipos de barcos
      {
        printf("coordenada en x del barco de %d unidades: ", i);
        scanf(" %d", &x );
        tablero_jugador2[x][y]='|';
        system("clear");
        imprimir_tablero(tablero_jugador2);
      } 
    }
  }

  score_jugador1 = 0;
  score_jugador2 = 0;

  //Jugador 2
  //Eliminación de barcos:
  while(true){
    
  
  system("clear");
  printf("puntos del jugador 1: %d\n\n", score_jugador1);
  printf("Fase eliminación---Jugador 2---\n\n");
  printf("Tablero de los barcos del Jugador2\n\n");
  imprimir_tablero(tablero_jugador2);
  printf("-----------------------------------\n\n");
  printf("Tablero de ataque jugador 2\n\n");
  imprimir_tablero(tablero_atacar_jugador2);
  printf("Inicio de la eliminación de barcos\n\n");
  printf("Turno del jugador 2\n\n");
  int coordenadax;
  int coordenaday;
   printf("Ingresa la coordenada x\n");
   scanf("%d",&coordenadax);
   printf("Ingresa la coordenada y\n");
   scanf("%d",&coordenaday);
    if(tablero_jugador1[coordenadax][coordenaday]=='/'){
      system("clear");
      printf("Le has dado a un barco\n");
      score_jugador2 += 100;
      tablero_atacar_jugador2[coordenadax][coordenaday]='X';
      imprimir_tablero(tablero_atacar_jugador2);
      printf("Has ganado 100 puntos :)\n");
      printf("Tu puntaje actual es: %d\n\n\n", score_jugador2);
      sleep(2);
      if(barcos_hundidos(tablero_atacar_jugador2,  'X')){
        printf("Felicidades jugador 2, has ganado\n");
        break;
      }
    }
    else{
      system("clear");
      printf("En el agua\n");
      tablero_atacar_jugador2[coordenadax][coordenaday]='O';
      imprimir_tablero(tablero_atacar_jugador2);
      score_jugador2 -= 50;
      printf("Has perdido 50 puntos :(\n\n");
      printf("Tu puntaje actual es: %d\n\n\n", score_jugador2);
      sleep(15);
      
    }
    
  
    
    //Jugador 1
    system("clear");
    printf("puntos del jugador 2: %d\n\n", score_jugador2);
    printf("Turno del jugador1\n");
    printf("Fase eliminación---Jugador 1---\n\n");
    printf("Tablero de los barcos del Jugador1\n\n");
    imprimir_tablero(tablero_jugador1);
    printf("-----------------------------------\n\n");
    printf("Tablero de ataque jugador 1\n\n");
    imprimir_tablero(tablero_atacar_jugador1);
    printf("Inicio de la eliminación de barcos\n\n");
    printf("Turno del jugador 1\n\n");
  
      int coordenada1x;
      int coordenada1y;
      printf("Ingresa la coordenada x\n");
      scanf("%d",&coordenada1x);
      printf("Ingresa la coordenada y\n");
      scanf("%d", &coordenada1y);
      if(tablero_jugador2[coordenada1x][coordenaday] =='|'){
        system("clear");
        printf("Le has dado a un barco\n\n");
        score_jugador1 += 100;
        tablero_atacar_jugador1[coordenada1x][coordenada1y]='X';
        imprimir_tablero(tablero_atacar_jugador1);
        printf("Has ganado 100 puntos :)\n\n");
        printf("Tu puntaje actual es: %d\n\n", score_jugador1);
        sleep(5);
        if(barcos_hundidos(tablero_atacar_jugador1,'X')){
          printf("Felicidades jugador 1, has ganado\n");
          break;
        }
      }
      else{
        system("clear");
        printf("En el agua\n\n");
        tablero_atacar_jugador1[coordenada1x][coordenada1y]='O';
        imprimir_tablero(tablero_atacar_jugador1);
        score_jugador1 -= 50;
        printf("Has perdido 50 puntos :(\n");
        printf("Tu puntaje actual es: %d\n", score_jugador1);
        sleep(15);
      }
    
    }
   
  return 0;
}

int instructionsUpdt() 
{
  int m;
  FILE *fp;
  char line[100];

  // Abrir el archivo para lectura
  fp = fopen("instrucciones.txt", "r");
  if (fp == NULL) {
      printf("Error al abrir el archivo.\n");
      return 1;
  }

  // Leer y mostrar el contenido línea por línea
  while (fgets(line, 100, fp) != NULL) {
      printf("%s", line);
  }

  // Cerrar el archivo
  fclose(fp);
  printf("\n\nPresiona cualquier numero para volver al menù principal\n\n");
  scanf("%d", &m);
  if (m != 0) { 

    // Obtener los argumentos del programa
    char *args[] = {"./main", NULL};

    // Reiniciar el programa con los mismos argumentos
    execvp(args[0], args);
  }
}

void sig_al(int signum) {
  kill(getpid(), SIGKILL);
}

int main() {
  system("clear");
  int n = 0;
  int status;
  pid_t pid;
  printf("---Bienvenido a Batalla Naval--- \n\n\n");
  printf("1: Jugar\n\n");
  printf("2: Como se juega?\n\n");
  printf("3: Salir\n\n");
  scanf("%d", &n);

  switch (n) {
  case 1:
    pid = fork();
    if(pid==0){
        game();
        return 0;
    }
    waitpid(pid,&status,0);
    break;
  case 2:
    system("clear");
    pid = fork();
    if(pid==0){
    instructionsUpdt();
    return 0;
    }
    waitpid(pid,&status,0);
    break;
  case 3:
    system("clear");
    pid = fork();
    if(pid==0){
    signal(SIGALRM, sig_al);
    printf("Saliendo del juego...");
    alarm(2);
    printf("\n\nGRACIAS POR JUGAR!");;
    return 0;
    }
    waitpid(pid,&status,0);
    break;
  }
}

