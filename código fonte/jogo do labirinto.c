/************************************
*   File:   jogo do labirinto.c     *
*   Author: William Torres          *
*************************************/

/**         INCLUSAO DE BIBLIOTECAS */

#include <stdio.h>//Biblioteca p/ funcao printf e putchar
#include <stdlib.h>//"" p/ funcao rand( ) - gerar numeros aleatorios (passos e distribuicaoo das armadilhas, tochas e o tesouro
#include <conio.h>//""p/ getch ( ) - ler as teclas digitadas pelo usuario, com proposito de faze-lo percorrer o mapa(matriz)
#include <time.h>//""p/ complementacao da funcao srand(time(NULL))
#include <windows.h>//""p/ funcao sleep(1) - esperar algum tempo e o programa voltar a executar as proximas linhas
#include "menu.h"//p/ mostrar opcoes iniciais aos jogadores
#include "messages.h"

void sorteio_passos(int *passos)/**Funcao p/ sortear quantos passos serao realizados pelos jogadores*/
{	do
	{
		*passos=rand()%11;
	}while(*passos > 10 || *passos < 3 );
	/**Valor sorteado deve estar entre 3 e 10, sendo a condicao verdadeira, o laco termina **/
}
void show_map(int mapa2[12][12])
{	int i,j;
    system("cls");
	system("color b");
    messages(1,0);
    /** 0 --- PAREDE HORIZONTAL
        1 --- NADA
        2 --- ARMADILHAS
        3 --- TOCHAS
        4 --- TESOURO
        5 --- PLAYER 1
        6 --- PLAYER 2
        7 --- ESPACO VAZIO
        8 --- PAREDE VERTICAL
        9 --- POSICAO INICIAL
       10 --- PLAYER 1 E 2 JUNTOS
       21 --- ARMADILHA REVELADA
       22 --- ARMADILHA ENCONTRADA
       31 --- TOCHA REVELADA
       33 --- TOCHA ENCONTRADA
       41 --- TESOURO REVELADO
       44 --- TESOURO ENCONTRADO
       54 --- TESOURO ENCONTRADO PELO PLAYER 1
       64 --- TESOURO ENCONTRADO PELO PLAYER 2
    **/
    for(i=0;i<12;i++)
    {
        for(j=0;j<12;j++)
        {
            printf("\t");
            if(mapa2[i][j]==0)
                printf("  ==  ");
            if(mapa2[i][j]==1||mapa2[i][j]==2||mapa2[i][j]==3||mapa2[i][j]==4)
                printf("  --  ");
            if(mapa2[i][j]==21 || mapa2[i][j]==22)
                printf(" TRAP ");
            if(mapa2[i][j]==31)
                printf(" FOGO ");
            if(mapa2[i][j]==41 || mapa2[i][j]==44)
                printf(" OURO ");
            if(mapa2[i][j]==54)
                printf(" *P1* ");
            if( mapa2[i][j]==64)
                printf(" *P2* ");
            if(mapa2[i][j]==5)
                printf("  P1  ");
            if(mapa2[i][j]==6)
                printf("  P2  ");
            if(mapa2[i][j]==7)
                printf("      ");
            if(mapa2[i][j]==8)
                printf("  ||  ");
            if(mapa2[i][j]==9)
                printf("  <>  ");
            if(mapa2[i][j]==10)
                printf(" P1P2 ");
        }
        putchar('\n');
    }
}

void tocha(int *x,int *y,int mapa2[][12])
{
    /**     *****   ALGORITMO DA TOCHA  *****
    *           Foi colocado abaixo de todos os outros if's, para evitar erros no comportamento da matriz.
    *           Estava com alguns bugs gráficos                                                 */
    int i,j;
    i=*x;
    j=*y;
    if(mapa2[i][j]==33)
    {
        printf("FOGO");
        mapa2[i][j]=31;
    /** Abaixo do jogador   */
        i++;
            if(mapa2[i][j]==1 || mapa2[i][j]==7)
                mapa2[i][j]=7;
            if(mapa2[i][j]==3 || mapa2[i][j]==31)
                mapa2[i][j]=31;
            if(mapa2[i][j]==2 || mapa2[i][j]==21)
                mapa2[i][j]=21;
            if(mapa2[i][j]==4 || mapa2[i][j]==41)
                mapa2[i][j]=41;
            if(mapa2[i][j]==0)
                mapa2[i][j]=0;
            if(mapa2[i][j]==8)
                mapa2[i][j]=8;
            if(mapa2[i][j]==5)
                mapa2[i][j]=5;
            if(mapa2[i][j]==6)
                mapa2[i][j]=6;
            if(mapa2[i][j]==9)
                mapa2[i][j]=9;
            if(mapa2[i][j]==10)
                mapa2[i][j]=10;
        i--;
    /** Em cima do jogador  */
        i--;
            if(mapa2[i][j]==1 || mapa2[i][j]==7)
                mapa2[i][j]=7;
            if(mapa2[i][j]==3 || mapa2[i][j]==31)
                mapa2[i][j]=31;
            if(mapa2[i][j]==2 || mapa2[i][j]==21)
                mapa2[i][j]=21;
            if(mapa2[i][j]==4 || mapa2[i][j]==41)
                mapa2[i][j]=41;
            if(mapa2[i][j]==0)
                mapa2[i][j]=0;
            if(mapa2[i][j]==8)
                mapa2[i][j]=8;
            if(mapa2[i][j]==5)
                mapa2[i][j]=5;
            if(mapa2[i][j]==6)
                mapa2[i][j]=6;
            if(mapa2[i][j]==9)
                mapa2[i][j]=9;
            if(mapa2[i][j]==10)
                mapa2[i][j]=10;
        i++;
        /** A esquerda do jogador  */
        j++;
            if(mapa2[i][j]==1 || mapa2[i][j]==7)
                mapa2[i][j]=7;
            if(mapa2[i][j]==3 || mapa2[i][j]==31)
                mapa2[i][j]=31;
            if(mapa2[i][j]==2 || mapa2[i][j]==21)
                mapa2[i][j]=21;
            if(mapa2[i][j]==4 || mapa2[i][j]==41)
                mapa2[i][j]=41;
            if(mapa2[i][j]==0)
                mapa2[i][j]=0;
            if(mapa2[i][j]==8)
                mapa2[i][j]=8;
            if(mapa2[i][j]==5)
                mapa2[i][j]=5;
            if(mapa2[i][j]==6)
                mapa2[i][j]=6;
            if(mapa2[i][j]==9)
                mapa2[i][j]=9;
            if(mapa2[i][j]==10)
                mapa2[i][j]=10;
        j--;
    /** A DIREITA do jogador  */
        j--;
            if(mapa2[i][j]==1)
                mapa2[i][j]=7;
            if(mapa2[i][j]==7)
                mapa2[i][j]=7;
            if(mapa2[i][j]==3 || mapa2[i][j]==31)
                mapa2[i][j]=31;
            if(mapa2[i][j]==2 || mapa2[i][j]==21)
                mapa2[i][j]=21;
            if(mapa2[i][j]==4 || mapa2[i][j]==41)
                mapa2[i][j]=41;
            if(mapa2[i][j]==0)
                mapa2[i][j]=0;
            if(mapa2[i][j]==8)
                mapa2[i][j]=8;
            if(mapa2[i][j]==5)
                mapa2[i][j]=5;
            if(mapa2[i][j]==6)
                mapa2[i][j]=6;
            if(mapa2[i][j]==9)
                mapa2[i][j]=9;
            if(mapa2[i][j]==10)
                mapa2[i][j]=10;
        j++;
    }
}

void distribuicao(int mapa1[][12])/**Funcao p/ distribuir as armadilhas, tochas e o ouro dentro do mapa
Foi criada uma funcao, para os elementos nao alterarem durante a execucao do programa */
{
    int trap=0,num_trap=0,where_trap=0;//trap = armadilhas, num_trap = numero de armadilhas
                                       //where_trap = chance de conter uma armadilha naquele elemento da matriz [i][j]
    int tochas=0,num_tocha=0,where_tocha=0;//mesma logica das armadilhas
    int ouro=0,where_ouro=0;//ouro = tesouro
                            //mesma logica das armadilhas, mas podendo conter somente um ouro no mapa, e PRECISA TER UM tesouro
    int i, j;
    mapa1[1][1]=9;
    mapa1[1][10]=9;
    mapa1[10][1]=9;
    mapa1[10][10]=9;
     //ARMADILHAS
    do      //laco para o numero de armadilhas nao passar de 32
    {num_trap=rand()%33;
	}while(num_trap>32);
    for(i=1;i<11;i++)
        for(j=1;j<11;j++)
        {
            do      //laco para sortear a chance de cair uma armmadilha num elemento da matriz
                    //nao podendo exceder 100
            {
                where_trap=rand()%101;
            }while(where_trap>101);
            //Quando sortear um valor entre 0 e 100, ir� fazer a an�lise abaixo
            //Para uma trap ser colocada em um elemento da matriz, o numero sorteado precisa ser entre 0 e 25
            //O numero de traps colocadas nao deve exceder o numero sorteado de traps
            if(where_trap <= 25 && where_trap > 0 && trap < num_trap && mapa1[i][j] == 1)
            {
                //Sendo tudo verdadeiro, colocaremos a tocha naquela posicao e adicionaremos +1 na variavel trap
                //ou seja, o loop nao precisara ser realizado mais alguma vez
                mapa1[i][j]=2;
                trap++;
            }
        }

    //TOCHAS
    do      //laco para o numero de tochas nao passar de 5
    {num_tocha=rand()%6;
	}while(num_tocha>5);
    for(i=2;i<10;i++)
        for(j=1;j<11;j++)
        {do      //laco para sortear a chance de cair uma tocha num elemento da matriz nao podendo exceder 100
            {where_tocha=rand()%101;
            }while(where_tocha>101);
            /**Quando sortear um valor entre 0 e 100, irao fazer a analise abaixo**/
            /**Para uma tocha ser colocada em um elemento da matriz, o numero sorteado precisa ser entre 0 e 15
                O numero tochas colocadas nao deve exceder o numero sorteado de tochas
                E nao pode colocar uma tocha se j� colocarmos uma tocha antes naquele local*/
            if(where_tocha <= 15 && where_tocha > 0 && tochas < num_tocha && mapa1[i][j] == 1)
            {   /**Sendo tudo verdadeiro, colocaremos a tocha naquela posicao e adicionaremos +1 na variavel tochas
                    ou seja, o loop nao precisaria ser realizado mais alguma vez**/
                mapa1[i][j]=3;
                tochas++;
            }
        }

    //OURO
    do
    {for(i=2;i<10;i++)
        for(j=1;j<11;j++)
            {
            do
            {where_ouro=rand()%101;
            }while(where_ouro>101);
            if(where_ouro == 1 && ouro < 1 && mapa1[i][j] == 1)
                {   mapa1[i][j]=4;
                    ouro++;
                }
            }
	}while(ouro<1);
}

void HP_system(int *hp1, int *hp2)
{
    printf("\n\t  ***Player I*** \t\t\t\t\t\t\t     ***Player II***\n\t    **HP:%d/5** \t\t\t\t\t\t\t\t\t**HP:%d/5**\n\n",*hp1,*hp2);
}

void movimentacao1(int *hp1, int *hp2,int *ouro, int *x,int *y,int mapa1[][12])
/** Funcao p/ movimentar o player 1 */
{    //*x, *y  Essa variaveis sao as coordenadas do player e serao de extrema importancia para a movimentacao.

/** Estou utilizando ponteiros em x e y, para nao mostrar na tela mais de 1x P1 ou P2(se fosse o caso)
 *  Isso estava acontecendo quando, ao terminar os passos do jogador I, depois os passos do jogador II.
 *  Ao voltar para esse procedimento, estava atualizando a posicao do jogador, e mostrando 2 P1 no mesmo mapa,o  que nao eh o objetivo  */

    char tecla1=0; // Essa variavel ira receber os valores w,a,s,d para controlar o player 1
    int passos=0;/*Variavel passos ira armazenar o valor sorteado, e servira para o controle do laco de repeticao */
    sorteio_passos(&passos);//Sorteio de quantos passos poderao ser dados pelo jogador - sempre de 3 a 10
    show_map(mapa1);
    HP_system(hp1,hp2);//Sempre ira mostrar quantos pontos de vida(HP) cada jogador possui
    printf("Player 1: Eu posso dar %d passos\n",passos);
    while(passos > 0 && *ouro != 1 && *hp1 > 0 && *ouro != 2 && *hp2 > 0)
/** Quando a variavel passos chegar em 0, termina o laco e o termina o turno
    Ou se o jogador encontrar o ouro tambem terminara o laco    */
        {   tecla1=getch();
            // Se lembra da variavel que ia pegar w,a,s,d? pronto aqui � onde ela recebe o valor
            /******Com o valor adquirido voce tera 4 ifs diferentes, 1 pra cada letra.******/

            if(tecla1 == 'w' || tecla1 == 'W' || tecla1 == 's' || tecla1 == 'S' || tecla1 == 'a' || tecla1 == 'A' || tecla1 == 'd' || tecla1 == 'D')
            {
            /** Esse e o if para cima, se queremos que o Player suba devemos mexer no x diminuindo,
             ** pode parecer confuso, ou n, vc ter que diminuir para subir, mas vai fazer sentido */
                if(tecla1 == 'w' || tecla1 == 'W')
                {   (*x)--;
                    if(mapa1[(*x)][(*y)]==0)
                    {  (*x)++;
                        passos++;//Tentativa de fazer com que o jogador nao perca nenhum passo ao ir para a parede, nao testei ainda
						printf("\a");
                    }
                    if(mapa1[(*x)+1][(*y)]==10)
                    {
                        mapa1[(*x)][(*y)]=5;
                        mapa1[((*x)+1)][(*y)]=6;
                    }
                    if(mapa1[(*x)][(*y)]==1)
                    {   mapa1[*x][*y]=5;
                        mapa1[((*x)+1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==2 || mapa1[(*x)][(*y)]==21)
                    {   mapa1[*x][*y]=22;
                        mapa1[((*x)+1)][(*y)]=7;
                        *hp1=*hp1-1;
                        messages(2,1);

                    }
                    if(mapa1[(*x)][(*y)]==3 || mapa1[(*x)][(*y)]==31)
                    {   mapa1[*x][*y]=33;
                        mapa1[((*x)+1)][(*y)]=7;
                        messages(3,1);
                        tocha(x,y,mapa1);
                    }
                    if(mapa1[(*x)][(*y)]==4 || mapa1[(*x)][(*y)]== 41)
                    {   mapa1[*x][*y]=54;
                        mapa1[((*x)+1)][(*y)]=7;
                        *ouro=1;
                    }
                    if(mapa1[(*x)][(*y)]==6)
                    {   mapa1[*x][*y]=10;
                        mapa1[((*x)+1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==7)
                    {   mapa1[*x][*y]=5;
                        mapa1[((*x)+1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==9)
                    {   mapa1[*x][*y]=5;
                        mapa1[((*x)+1)][(*y)]=7;
                    }

                }// fim do if cima

		/* Ja esse eh o if para descer, seguindo a mesma l�gica do anterior por�m agora
		 * aumentando o x
		 */
                if(tecla1 == 's' || tecla1 == 'S')
                {   (*x)++;
                    if(mapa1[(*x)][(*y)]==0)
                    {   passos++;
                        (*x)--;
						printf("\a");
                    }
                    if(mapa1[(*x)-1][(*y)]==10)
                    {
                        mapa1[(*x)][(*y)]=5;
                        mapa1[((*x)-1)][(*y)]=6;
                    }
                    if(mapa1[(*x)][(*y)]==1)
                    {   mapa1[*x][*y]=5;
                        mapa1[((*x)-1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==2 || mapa1[(*x)][(*y)]==21)
                    {   mapa1[*x][*y]=22;
                        mapa1[((*x)-1)][(*y)]=7;
                        *hp1=*hp1-1;
                        messages(2,1);
                    }
                    if(mapa1[(*x)][(*y)]==3 || mapa1[(*x)][(*y)]==31)
                    {   mapa1[*x][*y]=33;
                        mapa1[((*x)-1)][(*y)]=7;
                        messages(3,1);
                        tocha(x,y,mapa1);
                    }
                    if(mapa1[(*x)][(*y)]==4 || mapa1[(*x)][(*y)]==41)
                    {   mapa1[*x][*y]=54;
                        mapa1[((*x)-1)][(*y)]=7;
                        *ouro=1;
                    }
                    if(mapa1[(*x)][(*y)]==6)
                    {   mapa1[*x][*y]=10;
                        mapa1[((*x)-1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==7)
                    {   mapa1[*x][*y]=5;
                        mapa1[((*x)-1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==9)
                    {   mapa1[*x][*y]=5;
                        mapa1[((*x)-1)][(*y)]=7;
                    }
                }// fim do if baixo

		/* Esse eh o if para ir para a esquerda como est�
		 * se deslocando na horizontal mexe-se no y, diminuindo
		 */
                if(tecla1 == 'a' || tecla1 == 'A')
                {
                    (*y)--;
                    if(mapa1[(*x)][(*y)]==8)
                    {  (*y)++;
                        passos++;
						printf("\a");
                    }
                    if(mapa1[(*x)][(*y)+1]==10)
                    {
                        mapa1[(*x)][(*y)]=5;
                        mapa1[((*x))][(*y)+1]=6;
                    }
                    if(mapa1[(*x)][(*y)]==1)
                    {   mapa1[*x][*y]=5;
                        mapa1[((*x))][(*y)+1]=7;
                    }
                    if(mapa1[(*x)][(*y)]==2 || mapa1[(*x)][(*y)]==21)
                    {   mapa1[*x][*y]=22;
                        mapa1[((*x))][(*y)+1]=7;
                        *hp1=*hp1-1;
                        messages(2,1);
                    }
                    if(mapa1[(*x)][(*y)]==3 || mapa1[(*x)][(*y)]==31)
                    {   mapa1[*x][*y]=33;
                        mapa1[((*x))][(*y)+1]=7;
                        messages(3,1);
                        tocha(x,y,mapa1);
                    }
                    if(mapa1[(*x)][(*y)]==4 || mapa1[(*x)][(*y)]==41)
                    {   mapa1[*x][*y]=54;
                        mapa1[((*x))][(*y)+1]=7;
                        *ouro=1;
                    }
                    if(mapa1[(*x)][(*y)]==6)
                    {   mapa1[*x][*y]=10;
                        mapa1[((*x))][(*y)+1]=7;
                    }
                    if(mapa1[*x][*y]==7)
                    {   mapa1[*x][*y]=5;
                        mapa1[*x][(*y)+1]=7;
                    }
                    if(mapa1[(*x)][(*y)]==9)
                    {   mapa1[*x][*y]=5;
                        mapa1[((*x))][(*y)+1]=7;
                    }
                }// fim do if esquerda

            /* Esse eh o ultimo if, aponta para a direita, apenas mexemos no y aumentando-o */
                if(tecla1 == 'd' || tecla1 == 'D')
            {
                (*y)++;
                if(mapa1[(*x)][(*y)]==8)
                {  (*y)--;
                    passos++;
					printf("\a");
                }
                if(mapa1[(*x)][(*y)-1]==10)
                {
                    mapa1[(*x)][(*y)]=5;
                    mapa1[((*x))][(*y)-1]=6;
                }
                if(mapa1[(*x)][(*y)]==1)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x))][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==2 || mapa1[(*x)][(*y)]==21)
                {   mapa1[*x][*y]=22;
                    mapa1[((*x))][(*y)-1]=7;
                    *hp1=*hp1-1;
                    messages(2,1);
                }
                if(mapa1[(*x)][(*y)]==3 || mapa1[(*x)][(*y)]==31)
                {   mapa1[*x][*y]=33;
                    mapa1[((*x))][(*y)-1]=7;
                    messages(3,1);
                    tocha(x,y,mapa1);
                }
                if(mapa1[(*x)][(*y)]==4 || mapa1[(*x)][(*y)]==41)
                {   mapa1[*x][*y]=54;
                    mapa1[((*x))][(*y)-1]=7;
                    *ouro=1;
                }
                if(mapa1[(*x)][(*y)]==6)
                {   mapa1[*x][*y]=10;
                    mapa1[((*x))][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==7)
                {
                    mapa1[(*x)][(*y)]=5;
                    mapa1[(*x)][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==9)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x))][(*y)-1]=7;
                }
            }
            passos--;
            show_map(mapa1);//Apos o jogador ter digitado algo, temos que imprimir a matriz novamente com as modificacoes realizadas - Nova posicao do jogador
            HP_system(hp1,hp2);
            printf("Player 1 tem mais %d passos...\n",passos);//Mostrar ao jogador quantos passos restantes ele tem
            }
			else printf("\a");
        }
}

void movimentacao2(int *hp1,int *hp2, int *ouro, int *x,int *y,int mapa1[][12])
/** Funcao p/ movimentar o player 2 */
{    //*x, *y  Essa variaveis sao as coordenadas do player e serao de extrema importancia para a movimentacao.
    int tecla1=0; // Essa variavel ira receber os valores 8,4,5,7 para controlar o player 2
    int passos=0;/** Variavel passos ira armazenar o valor sorteado, e servira para o controle do laco de repeticao */
    sorteio_passos(&passos);
    system("cls");
    show_map(mapa1);
    HP_system(hp1,hp2);//Sempre ira mostrar quantos pontos de vida(HP) cada jogador possui
    printf("Player 2: Eu posso dar %d passos\n",passos);
    while(passos > 0 && *ouro != 1 && *hp1 > 0 && *ouro != 2 && *hp2 > 0)
    /** Quando a variavel passos chegar em 0, termina o laco e o termina o turno
    Ou se o jogador encontrar o ouro tambem terminara o laco    */
        {
            tecla1=getch()-'0';
             // Se lembra da variavel que ia pegar 8,4,5,6? pronto aqui ? onde ela recebe o valor
            /******Com o valor adquirido voce tera 4 ifs diferentes 1 pra cada letra.******/
            if(tecla1 == 8 || tecla1 == 5 || tecla1 == 4 || tecla1 == 6)
            {
                /** Esse eh o if para cima, se queremos que o Player suba devemos mexer no x diminuindo,
                 ** pode parecer confuso, ou n, vc ter que diminuir para subir, mas vai fazer sentido */
                if(tecla1 == 8)
                {   (*x)--;
                    if(mapa1[(*x)][(*y)]==0)
                    {  (*x)++;
                        passos++;//Com esse if, o jogador nao saira da area "livre" para jogar
						printf("\a");
                    }
                    if(mapa1[((*x)+1)][(*y)]==10)
                    {
                        mapa1[(*x)][(*y)]=6;
                        mapa1[((*x)+1)][(*y)]=5;
                    }
                    if(mapa1[(*x)][(*y)]==1)
                    {   mapa1[*x][*y]=6;
                        mapa1[((*x)+1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==2 || mapa1[(*x)][(*y)]== 21)
                    {   mapa1[*x][*y]=22;
                        mapa1[((*x)+1)][(*y)]=7;
                        *hp2=*hp2-1;
                        messages(2,2);
                    }
                    if(mapa1[(*x)][(*y)]==3 || mapa1[(*x)][(*y)]== 31)
                    {   mapa1[*x][*y]=33;
                        mapa1[((*x)+1)][(*y)]=7;
                        messages(3,2);
                        tocha(x,y,mapa1);
                    }
                    if(mapa1[(*x)][(*y)]==4 || mapa1[(*x)][(*y)]== 41)
                    {   mapa1[*x][*y]=64;
                        mapa1[((*x)+1)][(*y)]=7;
                        *ouro=2;
                    }
                    if(mapa1[(*x)][(*y)]==5)
                    {   mapa1[*x][*y]=10;
                        mapa1[((*x)+1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==7)
                    {   mapa1[*x][*y]=6;
                        mapa1[((*x)+1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==9)
                    {   mapa1[*x][*y]=6;
                        mapa1[((*x)+1)][(*y)]=7;
                    }
                }// fim do if cima

            /** Ja esse eh o if para descer, seguindo a mesma logica do anterior porem agora aumentando o x		*/
                if(tecla1 == 5)
                {   (*x)++;
                    if(mapa1[(*x)][(*y)]==0)
                    {   (*x)--;
                        passos++;
						printf("\a");
                    }
                    if(mapa1[((*x)-1)][(*y)]==10)
                    {
                        mapa1[(*x)][(*y)]=6;
                        mapa1[((*x)-1)][(*y)]=5;
                    }
                    if(mapa1[(*x)][(*y)]==1)
                    {   mapa1[*x][*y]=6;
                        mapa1[((*x)-1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==2 || mapa1[(*x)][(*y)]== 21)
                    {   mapa1[*x][*y]=22;
                        mapa1[((*x)-1)][(*y)]=7;
                        *hp2=*hp2-1;
                        messages(2,2);
                    }
                    if(mapa1[(*x)][(*y)]==3 || mapa1[(*x)][(*y)]== 31)
                    {   mapa1[*x][*y]=33;
                        mapa1[((*x)-1)][(*y)]=7;
                        messages(3,2);
                        tocha(x,y,mapa1);
                    }
                    if(mapa1[(*x)][(*y)]==4 || mapa1[(*x)][(*y)]==41)
                    {   mapa1[*x][*y]=64;
                        mapa1[((*x)-1)][(*y)]=7;
                        *ouro=2;
                    }
                    if(mapa1[(*x)][(*y)]==5)
                    {   mapa1[*x][*y]=10;
                        mapa1[((*x)-1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==7)
                    {   mapa1[*x][*y]=6;
                        mapa1[((*x)-1)][(*y)]=7;
                    }
                    if(mapa1[(*x)][(*y)]==9)
                    {   mapa1[*x][*y]=6;
                        mapa1[((*x)-1)][(*y)]=7;
                    }
                }// fim do if baixo

            /** Esse eh o if para ir para a esquerda como esta
            ** se deslocando na horizontal mexe-se no y, diminuindo */
                if(tecla1 == 4)
                {
                    (*y)--;
                    if(mapa1[(*x)][(*y)]==8)
                    {  (*y)++;
                        passos++;
						printf("\a");
                    }
                    if(mapa1[(*x)][(*y)+1]==10)
                    {
                        mapa1[(*x)][(*y)]=6;
                        mapa1[((*x))][(*y)+1]=5;
                    }
                    if(mapa1[(*x)][(*y)]==1)
                    {   mapa1[*x][*y]=6;
                        mapa1[((*x))][(*y)+1]=7;
                    }
                    if(mapa1[(*x)][(*y)]==2 || mapa1[(*x)][(*y)]==21)
                    {   mapa1[*x][*y]=22;
                        mapa1[((*x))][(*y)+1]=7;
                        *hp2=*hp2-1;
                        messages(2,2);
                    }
                    if(mapa1[(*x)][(*y)]==3 || mapa1[(*x)][(*y)]==31)
                    {   mapa1[*x][*y]=33;
                        mapa1[((*x))][(*y)+1]=7;
                        messages(3,2);
                        tocha(x,y,mapa1);
                    }
                    if(mapa1[(*x)][(*y)]==4 || mapa1[(*x)][(*y)]==41)
                    {   mapa1[*x][*y]=44;
                        mapa1[((*x))][(*y)+1]=7;
                        *ouro=2;
                        break;
                    }
                    if(mapa1[(*x)][(*y)]==5)
                    {   mapa1[*x][*y]=10;
                        mapa1[((*x))][(*y)+1]=7;
                    }
                    if(mapa1[*x][*y]==7)
                    {   mapa1[*x][*y]=6;
                        mapa1[*x][(*y)+1]=7;
                    }
                    if(mapa1[(*x)][(*y)]==9)
                    {   mapa1[*x][*y]=6;
                        mapa1[((*x))][(*y)+1]=7;
                    }
                }// fim do if esquerda

            /* Esse eh o ultimo if, aponta para a direita, apenas mexemos no y aumentando-o */
                if(tecla1 == 6)
                {
                    (*y)++;
                    if(mapa1[(*x)][(*y)]==8)
                    {  (*y)--;
                        passos++;
						printf("\a");
                    }
                    if(mapa1[((*x))][(*y)-1]==10)
                    {
                        mapa1[(*x)][(*y)]=6;
                        mapa1[((*x))][(*y)-1]=5;
                    }
                    if(mapa1[(*x)][(*y)]==1)
                    {   mapa1[*x][*y]=6;
                        mapa1[((*x))][(*y)-1]=7;
                    }
                    if(mapa1[(*x)][(*y)]==2 || mapa1[(*x)][(*y)]==21)
                    {   mapa1[*x][*y]=22;
                        mapa1[((*x))][(*y)-1]=7;
                        *hp2=*hp2-1;
                        messages(2,2);
                }
                if(mapa1[(*x)][(*y)]==3 || mapa1[(*x)][(*y)]==31)
                {   mapa1[*x][*y]=33;
                    mapa1[((*x))][(*y)-1]=7;
                    messages(3,2);
                    tocha(x,y,mapa1);
                }
                if(mapa1[(*x)][(*y)]==4 || mapa1[(*x)][(*y)]==41)
                {   mapa1[*x][*y]=64;
                    mapa1[((*x))][(*y)-1]=7;
                    *ouro=2;
                }
                if(mapa1[(*x)][(*y)]==5)
                {   mapa1[*x][*y]=10;
                    mapa1[((*x))][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==7)
                {
                    mapa1[(*x)][(*y)]=6;
                    mapa1[(*x)][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==9)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x))][(*y)-1]=7;
                }
                }
            passos--;
            show_map(mapa1);//Apos o jogador ter digitado algo, temos que imprimir a matriz novamente
            HP_system(hp1,hp2);
            printf("Player 2 tem mais %d passos...\n",passos);//Mostrar ao jogador quantos passos restantes ele tem
            }
            else
                printf("\a");
        }
}

void escolha_player(int player)
{
    int i;
    printf("Jogador %d, onde deseja comecar a jogar?\n",player);
	printf("||  ==   ==   ==   ==   ==   ==   ==  ==  ==  ==  ||\n||  1    --   --   --   --   --   --  --  --  2   ||\n");
	for(i = 0 ; i < 8 ; i++)
/** Este laco eh so para economizar linhas, como temos 8 linhas que serao repetidas, por que nao usar um laco?  */
            printf("||  --   --   --   --   --   --   --  --  --  --  ||\n");
	printf("||  3    --   --   --   --   --   --  --  --  4   ||\n||  ==   ==   ==   ==   ==   ==   ==  ==  ==  ==  ||\n");
}

void map()
{
    int x=1,y=1,w=1,z=10;
/** X e Y = Coordenadas do Player I
    W e Z = Coordenadas do Player II                    */
    int init_x = x, init_y = y, init_w = w, init_z = z;
/** init_x e init_y = Coordenadas iniciais do Player I
 *  init_w e  init_z = Coordendas iniciais do Player II */
    int user1=0,user2=0;
/** user1 e user2 = Variaveis para fazer os jogadores escolherem onde irao comecar a jogar */
    int ouro=0;
/** Variaveis para encerrar o jogo */
/** Iremos enviar o endereco da variavel 'ouro' para os dois jogadores.
 ** Se o Jogador I encontrar o tesouro, a variavel recebe 1.
 ** Se o Jogador II encontrar o tesouro, a variavel recebe 2.           */
    int hp1=5,hp2=5;
/** Para controlar o hp dos jogadores   */
	int mapa1[12][12]=//numero de linhas e colunas da matriz
	{
    {8,0,0,0,0,0,0,0,0,0,0,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,0,0,0,0,0,0,0,0,0,0,8},    };
    distribuicao(mapa1);
/** Este eh o procedimento somente para mostrar o mapa ao jogador, escolhi criar ele, porque estava ocupando muitas linhas
    O numero (1) como argumento eh p/ as mensagens serem direcionadas ao player I           */
    system("cls");
    escolha_player(1);
    scanf("%d",&user1);//user1=getch() - '0';
/** Se o player I escolher algumnumero entre 1 e 4, ira alterar as variaveis x e y(Coordendas do jogador I)
    */

if(user1 == 1 || user1 == 2 || user1 == 3 || user1 == 4)
    {   if(user1==1)
        {   x=1;
            y=1;
        }
        if(user1==2)
        {   x=1;
            y=10;
        }
        if(user1==3)
        {   x=10;
            y=1;
        }
        if(user1==4)
        {   x=10;
            y=10;
        }
    }
/** Se o Jogador digitar algum valor errado, ele ira iniciar o jogo a partir das coordenadas padr�o */
    else if(user1 != 1 || user1 != 2 || user1 != 3 || user1 != 4)
    {   x=1;
        y=1;
		user1=1;
    }
    system("cls");
    escolha_player(2);
	scanf("%d",&user2);
/** Mesma coisa do algoritmo acima, porem a posicao escolhida tem de ser diferente da escolhida pelo jogador 1
 *  Se o jogador 1 digitar algum valor invalido, ele comecara da linha 1 e coluna 1
 *  Logo, o Jogador II nao podera comecar nessa posicao                             */
	if(user2 != user1 && user2 == 1 || user2 == 2 || user2 == 3 || user2 == 4)
    {   if(user2==1)
        {   w=1;
            z=1;
        }
        if(user2==2)
        {   w=1;
            z=10;
        }
        if(user2==3)
        {   w=10;
            z=1;
        }
        if(user2==4)
        {   w=10;
            z=10;

        }
    }
	else
	{
	user2=2;
	}

	if(user2==user1){
		if(user1==2)
		{
		w=1;
		z=1;
		user2=1;
		}
		else
		{
		w=1;
		z=10;
		}


	}
	init_x=x;   init_y=y;   init_w = w; init_z=z;
/*  Enviar o init_x e etc como argumento para a funcao show_map(), para mostrar onde os jogadores escolheram iniciar */
    mapa1[init_x][init_y]=5;
    mapa1[init_w][init_z]=6;
	while(ouro != 1 && ouro != 2 && hp1 > 0 && hp2 > 0)
	{
	    show_map(mapa1);
        movimentacao1(&hp1,&hp2,&ouro,&x,&y,mapa1);
/**     Enviaremos o endereco das variavel HP para a movimentacao dos dois jogadores
 **		porque precisaremos para mostrar na tela do usuario a quantidade de HP que cada um possui
 **		com a funcao HP_system() que PRECISA de 2 ponteiros para os HPs   */
        if(ouro == 1 || hp1 == 0)
            break;
        movimentacao2(&hp1,&hp2,&ouro,&w,&z,mapa1);
    }
    if(ouro == 1 || hp2 == 0)
    {   if(ouro == 1)
            {   messages(4,1);
                messages(5,1);
            }
        if(hp2 == 0)
            messages(5,1);
    }
    if(ouro == 2 || hp1 == 0)
    {   if(ouro == 2)
            {   messages(4,2);
                messages(5,2);
            }
        if(hp1 == 0)
            messages(5,2);
    }
    system("color 7");
}

int main()
{
    srand(time(NULL));/** Enquanto o programa nao estiver pronto, deixe esta linha do jeito que esta
                          Esta linha vai deixar os elementos da matriz totalmente aleatorios.          */
    char user='0';
    do
    {   fflush(stdin);
        system("cls");
        menu(&user);
        if(user == 'a' || user == 'A')
            map();
        if(user == 'e' || user == 'E')
            break;
    }while(1);
    putchar('\n');
    system("pause");
    return 1;
}

