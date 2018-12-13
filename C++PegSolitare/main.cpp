#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//{}
using namespace std;
/* Printing the board where X are the invalidad places in board
'O' are Peg and '*' the free spaces*/
void PrintBoard(int board[7][7])
{
    for(int i=0; i<= 6;i++)
    {
        for(int j=0; j<= 6;j++)
        {
            //This if can be change for a switch
            if(board[i][j]==2)
            {
                 printf("%c\t", 'X');
            }
            else  if(board[i][j]==1)
            {
                 printf("%c\t", '*');
            }
            else
                printf("%c\t",'0');
        }
         printf("\n");
    }
}
bool ValidateWinGame(int WinBoard[7][7])
{

    if(WinBoard[3][3]==1)
    {
     for(int i=0; i<= 6;i++)
      {
        for(int j=0; j<= 6;j++)
        {
          if(WinBoard[i][j]==1 )
            {
                if(i == 3 && j==3){

                }
                else
                return false;
            }
        }
      }
    }

    else
        return false;

  return true;

}

bool ValidateWinGame1(int Board[7][7], char location, int i, int j)
   {
       int validation = false;
       switch (location)
       {
        case 'S':
            if(i > 1 && Board[i-2][j] ==1 && Board[i-1][j] ==1 )
            {
                printf("Se puede mover abajo %d %d %d\n", i,j, Board[i-2][j] );
                validation = true;
            }
            break;
        case 'N':
            if( i < 5 && Board[i+2][j] ==1 && Board[i+1][j] ==1 )
            {
                printf("Se puede mover arriba %d %d %d\n", i,j, Board[i+2][j] );
                validation = true;
            }
            break;
        case 'E':
         if(j > 1 && Board[i][j-2] ==1 && Board[i][j-1] ==1 )
            {
                printf("Se puede mover derecha %d %d %d\n", i,j, Board[i][j-2]);
                validation = true;
            }
        break;
        case 'W':
             if( j < 5 && Board[i][j+2] ==1 && Board[i][j+2] ==1 )
            {
                printf("Se puede mover izquierda %d %d %d\n", i,j, Board[i][j+2] );
                validation = true;
            }
            break;
        break;


       }
       return validation;

   }
//int (*a)[2]
void SetMt(int a[2][2])
{
    int j  =1;
    a[0][0] = 100;
    a[1][1]= 4;
}



void MoveSouth()
{

}

void SerchEmptySpace(int board[7][7])
{
    int N=0, S=0, E =0, W=0;
    for(int i=0; i<= 6;i++)
    {
        for(int j=0; j<= 6;j++)
        {
            if(board[i][j]==0 )
            {
               // PosisionarValido(board[7][7],'N');
              // printf("Se encontro un espacio vacio e i: %d y j: %d \n", i, j);
               //S = ValidateWinGame1(board,'S',i,j) ;
               //N = ValidateWinGame1(board,'N',i,j) ;
               E = ValidateWinGame1(board,'E',i,j) ;
               // printf("Es valido o no el movimiento %d\n", S);

            }

        }

    }

}
int main()
{

    printf("Hola \n");
    double prueba [5][32][6500];

    int board[7][7]={
       {2,2,1,1,0,2,2 },
       {2,2,1,1,1,2,2 },
       {1,1,1,1,1,1,1 },
       {1,1,0,0,1,1,0 },
       {1,1,0,1,1,1,1 },
       {2,2,1,1,1,2,2 },
       {2,2,1,1,0,2,2 }
    };

    printf("Imprimiendo i6 y j4 = %d \n", board[6][4]);
    int WinBoard[7][7]={
       {2,2,0,0,0,2,2 },
       {2,2,0,0,0,2,2 },
       {0,0,0,0,0,0,0 },
       {0,0,0,1,1,0,0 },
       {0,0,0,0,0,0,0 },
       {2,2,0,0,0,2,2 },
       {2,2,0,0,0,2,2 }
    };
    PrintBoard(WinBoard);

    bool validation = ValidateWinGame(WinBoard);
    cout << "Hello world!" << endl;
    printf("%s\n", validation ? "true" : "false");

    //printf("%c",219);

    // creamos una matriz:
    int z[2][2]; // sz 2


    SetMt(z);
    printf("%d\n", z[0][0]); // Salida: 24
    PrintBoard(board);
    SerchEmptySpace(board);

    getchar();
    return 0;
}
