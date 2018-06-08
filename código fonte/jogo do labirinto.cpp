/******************************
*	File:Saturn Project	      *
*	Author: William Torres    *
*							  *
*							  *
******************************/

#include <stdio.h>//Biblioteca p/ printf e putchar
#include <stdlib.h>//Biblioteca necess�ria para gerar numeros aleatorios (passos e distribuicaoo das armadilhas, tochas e o tesouro
#include <conio.h>//Biblioteca para ler as teclas digitadas pelo usuario, com proposito de faze-lo percorrer o mapa(matriz)
#include <time.h>//Biblioteca para complementacao da funcao srand()
#include <windows.h>//sleep

void sorteio_passos(int *Passos)//Funcao para calcular quantos passos poderao ser realizados pelos jogadores
{
	*Passos=3+rand()%11;	//esta funcao sera substituida por srand(time(NULL)), para sempre ter numeros aleatorios a cada execucao
							//mas para saber se o jogo esta funcionando, iremos trabalhar com valores constantes
}

void sorteio_distribuicao(int mapa[12][12],int linhas, int colunas)
{	int num_trap=0,num_fire,where_gold;
	num_trap=rand()%33;
	printf("Serao impressas %d armadilhas\n",num_fire);
	for(int trap=0;trap<=num_trap;trap++)
	{	
		for(int walker=0;walker<trap;walker++)			//laco para distribuir as traps = 2
		{
			for(int i=2;i<10;i++)
				{
					for(int j=1;j<11;j++)
					{
						int where_trap=0;
						where_trap=rand()%101;
						if(where_trap<=25)
						mapa[i][j]=2;
						else j++;
					}
				}
		}
	}
	int num_tocha=0;
	num_tocha=rand()%16;
	printf("Serao impressas %d tochas\n",num_tocha);
	for(int tocha=0;tocha<=num_tocha;tocha++)
	{
		//for()laco para distruibuir as tochas = 3
	}
	int gold=1;
	where_gold=rand()%101;
	//	for()Laco para distribuir o tesouro = 4
}




void mapa()
{	
	int mapa[12][12]	// Modelo do labirito a ser percorrido, os caracteres 'X' serao as paredes que noa poderao ser atravessadas
/*	[i][j]
	[0][0] [0][1] [0][2] [0][3] [0][4] [0][5] [0][6] [0][7] [0][8] [0][9] [0][10] [0][11]
	[1][0] [1][1] [1][2] [1][3] [1][4] [1][5] [1][6] [1][7] [1][8] [1][9] [1][10] [1][11]
	[2][0] [2][1] [2][2] [2][3] [2][4] [2][5] [2][6] [2][7] [2][8] [2][9] [2][10] [2][11]
	[3][0] [3][1] [3][2] [3][3] [3][4] [3][5] [3][6] [3][7] [3][8] [3][9] [3][10] [3][11]
	[4][0] [4][1] [4][2] [4][3] [4][4] [4][5] [4][6] [4][7] [4][8] [4][9] [4][10] [4][11]
	[5][0] [5][1] [5][2] [5][3] [5][4] [5][5] [5][6] [5][7] [5][8] [5][9] [5][10] [5][11]
	[6][0] [6][1] [6][2] [6][3] [6][4] [6][5] [6][6] [6][7] [6][8] [6][9] [6][10] [6][11]
	[7][0] [7][1] [7][2] [7][3] [7][4] [7][5] [7][6] [7][7] [7][8] [7][9] [7][10] [7][11]
	[8][0] [8][1] [8][2] [8][3] [8][4] [8][5] [8][6] [8][7] [8][8] [8][9] [8][10] [8][11]
	[9][0] [9][1] [9][2] [9][3] [9][4] [9][5] [9][6] [9][7] [9][8] [9][9] [9][10] [9][11]
	[10][0] [10][1] [10][2] [10][3] [10][4] [10][5] [10][6] [10][7] [10][8] [10][9] [10][10] [10][11]
	[11][0] [11][1] [11][2] [11][3] [11][4] [11][5] [11][6] [11][7] [11][8] [11][9] [11][10] [11][11]	
*/	{
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    };
	for(int i=0;i<12;i++)
		{	
			for(int j=0;j<12;j++)
			{	
				if(mapa[i][j]==0)
					printf(" XX ");
				if(mapa[i][j]==1||mapa[i][j]==2||mapa[i][j]==3||mapa[i][j]==4)
					printf(" -- ");
			}
			putchar('\n');
		}
	sorteio_distribuicao(mapa,12,12);
//	system("cls");
	for(int i=0;i<12;i++)
		{	
			for(int j=0;j<12;j++)
			{	
				if(mapa[i][j]==0)
					printf(" XX ");
				if(mapa[i][j]==1||mapa[i][j]==2||mapa[i][j]==3||mapa[i][j]==4)
					printf(" %d  ",mapa[i][j]);
			}
			putchar('\n');
		}
}

void player1()
{
	
}


void player2()
{
	
}

void mensagens(int situacao_agora, int player, int passos)
//situacao_agora == recebera um valor inteiro para determinar qual mensagem sera mostrada
//player == int p/ identificar qual player || quantos passos serao dados e quantos restam
{
	switch(situacao_agora)
	{	
		case 1:
		{	printf("\t\t\tBem-vindo a caca ao Tesouro!\n\n\n");
			break;
		}
		case 2:
		{	printf("Player %d pode dar: %d passos",player,passos);
			break;
		}
		case 3:
		{	printf("Player %d encontrou uma tocha!",player);
			break;
		}
		case 4:
		{	printf("Player %d perdeu 1 Health Point",player);
			break;
		}
		case 5:
		{	printf("Player %d encontrou o tesouro!",player);
			break;
		}
		case 6:
		{	printf("Player %d GANHOU!! PARABENSS",player);
			break;
		}
	}
}
void jogo()//Funcao principal do jogo
{
	int passos,player;
	do
	{
		sorteio_passos(&passos);
		mensagens(1,0,0);
		mapa();
		mensagens(2,player,passos);
		break;
	}
	while(1);
}
int main()
{	
	//srand( (unsigned)time(NULL) );
	jogo();
	putchar('\n');
	system("pause");
	getch();
	return 1;
}
