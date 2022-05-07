
#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
char ch1='X',ch2='O',R[9]={'1','2','3','4','5','6','7','8','9'};
char rec1[5],rec2[5];
void interface()
{  int i;
     printf("\t\t\t\t********************** TIC TAC TOE **********************\n");
     printf("\t\t\t\t                 **********************          \n\n\n\n");
     printf("\n\t\t\t\t\t\t");
     for(i=0;i<26;i++)
     { printf("=");
       Sleep(20);
     }
     printf("\n\t\t\t\t\t\t");
     for(i=0;i<26;i++)
     { printf("=");
       Sleep(20);
     }
     printf("\n\t\t\t\t\t\t");
     printf("==");
      printf("  X   ");
     Sleep(20);

     printf("==");

     Sleep(20);
     printf("  O   ");
     Sleep(20);
     printf("==");
     Sleep(20);
     printf("      ");
     Sleep(20);
     printf("==");
     printf("\n\t\t\t\t\t\t");
     for(i=0;i<3;i++)
     { printf("==\t");
       Sleep(20);
     }
     printf("==");
     printf("\n\t\t\t\t\t\t");
     for(i=0;i<26;i++)
     { printf("=");
       Sleep(20);
     }
     printf("\n\t\t\t\t\t\t");
     printf("==");
      printf("      ");
     Sleep(20);

     printf("==");

     Sleep(20);
     printf("  X   ");
     Sleep(20);
     printf("==");
     Sleep(20);
     printf("  O   ");
     Sleep(20);
     printf("==");
     printf("\n\t\t\t\t\t\t");
     for(i=0;i<3;i++)
     { printf("==\t");
       Sleep(20);
     }
     printf("==");
     printf("\n\t\t\t\t\t\t");
     for(i=0;i<26;i++)
     { printf("=");
       Sleep(20);
     }
      printf("\n\t\t\t\t\t\t");
     printf("==");
      printf("      ");
     Sleep(20);

     printf("==");

     Sleep(20);
     printf("  X   ");
     Sleep(20);
     printf("==");
     Sleep(20);
     printf("  O   ");
     Sleep(20);
     printf("==");
      printf("\n\t\t\t\t\t\t");
     for(i=0;i<3;i++)
     { printf("==\t");
       Sleep(20);
     }
     printf("==");
     printf("\n\t\t\t\t\t\t");
     for(i=0;i<26;i++)
     { printf("=");
       Sleep(20);
     }
     printf("\n\t\t\t\t\t\t");
     for(i=0;i<26;i++)
     { printf("=");
       Sleep(20);
     }
     printf("\n\n\t\t\t\t\t\t");
     printf("    *START THE GAME !*");
     getchar();
     system("cls");

}
void rules()
{
    int i;
    printf("\t\t\t\t********************** TIC TAC TOE **********************\n");
    printf("\t\t\t\t                 **********************          \n\n\n\n");
    printf("\n\t\t\t\t\t\t");
    printf("\t*RULES*");
    printf("\n\t\t\t\t\t\t");
    printf("       ---------");
    printf("\n\t\t\t\t\t\t");
    printf("       ---------");
    printf("\n\n\n\n\t\t");
    printf("1. The game is played on a grid that's 3 squares by 3 squares . ");
    printf("\n\n\t\t");
    printf("2. You are X, your friend is O. Players take turns putting their marks in empty squares .");
    printf("\n\n\t\t");
    printf("3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner .");
    printf("\n\n\t\t");
    printf("4. When all 9 squares are full,the game is over.\n\n\t\tIf no player has 3 marks in a row, the game ends in a tie .\n\n");
    printf("\n\n\n\t\t\t\t");
    for(i=0;i<5;i++)
     {  printf("\t(^_^)");
       Sleep(500);
     }
    printf("\n\n\t\t\t\t\t\t   ");
    printf("Press any key !\n");
    getchar();
    system("cls");

}
int verify_game_state(char board[3][3])
   {
     int i;
     for(i=0;i<3;i++)
       if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
        if(board[i][0]==ch1)
         return -1;
        else if(board[i][0]==ch2)
               return 1;
     for(i=0;i<3;i++)
       if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
         if(board[0][i]==ch1)
           return -1;
         else if(board[0][i]==ch2)
               return 1;

     if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        if(board[0][0]==ch1)
          return -1;
        else if(board[0][0]==ch2)
               return 1;

     if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        if(board[0][2]==ch1)
           return -1;
        else if(board[0][2]==ch2)
               return 1;
     return 0;
   }
int empty_board(char board[3][3])
    { for(int i=0;i<3;i++)
       {for(int j=0;j<3;j++)
        { for(int k=0;k<9;k++)
            if(board[i][j]==R[k])
             return 1;
        }
      }
      return 0;
    }
int num_empty_board(char board[3][3])
{ int cpp=0;
   for(int i=0;i<3;i++)
       {for(int j=0;j<3;j++)
        { for(int k=0;k<9;k++)
            if(board[i][j]==R[k])
             cpp++;
        }
      }
      return cpp;

}
int minimax(char board[3][3],int depth,int ismax)
{
    if(verify_game_state(board)==1)
        return (num_empty_board(board)+1)*1;
    else if(verify_game_state(board)==-1)
           return(num_empty_board(board)+1)*-1;
         else if(!empty_board)
                 return 0;
    if(ismax)
    {
        int best=-1000;
        for(int i=0;i<3;i++)
        { for(int j=0;j<3;j++)
          { for(int k=0;k<9;k++)
              { if(board[i][j]==R[k])
                  { board[i][j]=ch2;
                    best=max(best,minimax(board,depth+1,!ismax));
                    board[i][j]=R[k];
                  }
              }
          }

        }
      return best;
    }else
    {
        int best=1000;
        for(int i=0;i<3;i++)
        {for(int j=0;j<3;j++)
         { for(int k=0;k<9;k++)
            { if(board[i][j]==R[k])
               { board[i][j]=ch1;
                 best=min(best,minimax(board,depth+1,!ismax));
                 board[i][j]=R[k];
               }
            }
          }
        }
      return best;
}
}
char find_move(char board[3][3])
{
   int bestval=-1000,move,s;
   for(int i=0;i<3;i++)
   { for(int j=0;j<3;j++)
       { for(int k=0;k<9;k++)
           { if(board[i][j]==R[k])
             {
               board[i][j]=ch2;
               move=minimax(board,0,0);
               board[i][j]=R[k];
               if(move>bestval)
               {
                 bestval=move;
                 s=R[k];
               }
             }
           }
       }
   }
 return s;
}
void human(int num ,char rec[5] , int compt,char board[3][3],char ch)
{
  printf("\n\n\n\t\t\t");
  printf("player %d : ",num);
  scanf(" %c",&rec[compt]);
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
       if(rec[compt]==board[i][j])
          {
            board[i][j]=ch;
            break;
          }
}
void random_move(char board[3][3],char recc[5],char recs[5],int cb)
{
    int n;
    for(int k=0;k<9;k++)
       if(recc[cb]==R[k])
      { R[k]=R[k+1];

      }
      n=rand()%9;
      recs[cb]=R[n];
      printf("\n\t\t\t");
      printf("player 2 : %c ",recs[cb]);
      Sleep(300);
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        if(recs[cb]==board[i][j])
          {
            board[i][j]=ch2;
            break;
          }

}
void cpu(char board[3][3],char ch)
{
   int val;
   printf("\n\n\n\t\t\t");
   printf("CPU    : ");
   val=find_move(board);
   for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
       if(val==board[i][j])
          {
            board[i][j]=ch;
            break;
          }
   printf(" %c",val);
   Sleep(1000);
}
   void all()
   {

       //choice
       int rnd,mode,i,j,k,scr1=0,scr2=0,f1,W[20];

       printf("\t\t\t\t********************** TIC TAC TOE **********************\n");
       printf("\t\t\t\t                 **********************          \n\n\n\n");
       printf("\n\t\t\t\t\t\t");
       printf("\n\t\t\t\t\t\t");
       printf("  choose MODE ");
       printf("\n\n\n\t\t\t\t\t\t");
       printf("  *1*P1 VS P2 \n");
       printf("\n\t\t\t\t\t\t");
       printf("  *2*P1 VS CPU\n");

       scanf("%d",&mode);
       Sleep(600);

      printf("\n\n\t\t\t\t\t\t     ");
      printf("Rounds  ");
      printf("\n\t\t\t\t\t\t        ");
      scanf("%d",&rnd);
      printf("\n\n\t\t\t\t\t\t");
      printf("     LOADING...");
      printf("\n\n\t\t\t");
      for(i=0;i<32;i++)
       {  printf("\xdb ");
          Sleep(200);
       }
      system("cls");
     //main page
     for(int y=0;y<rnd;y++)
     { char T[3][3]={ '1', '2', '3','4', '5', '6' , '7', '8', '9' };
       int cpt=0;
       do{
          printf("\t\t\t\t********************** TIC TAC TOE **********************\n");
          printf("\t\t\t\t                 **********************          \n\n\n\n");
          printf("\n\t\t\t\t\t\t");
          printf("\n\t\t\t\t\t\t\t");
          printf("  ROUND %d ",y+1);
          printf("\n\t\t\t\t\t\t");
          for(i=0;i<3;i++)
           {  printf("\n\t\t\t\t\t\t");
              for(k=0;k<26;k++)
                printf("-");
              printf("\n\t\t\t\t\t\t");
              for(j=0;j<3;j++)
                printf("|   %c   |", T[i][j]);
              printf("\n\t\t\t\t\t\t");
              for(k=0;k<26;k++)
                printf("-");
           }
           human(1,rec1,cpt,T,ch1);
           if(mode==1)
           {
            if(cpt!=4 /*&& w!=ch1*/ )
            {
               human(2,rec2,cpt,T,ch2);
            }
            }
            else if(mode==2)
            {
              if(cpt ==0 /*&& w!=ch1*/ )
               {
                  random_move(T,rec1,rec2,cpt);
               }else if(cpt!=4)
                {
                  cpu(T,ch2);
                }
            }

            verify_game_state(T);
            if(verify_game_state(T)==1 || verify_game_state(T)==-1 || !empty_board )
                break;
            cpt++;
            system("cls");
       }while(cpt<=4);
       system("cls");
       printf("\t\t\t\t********************** TIC TAC TOE **********************\n");
       printf("\t\t\t\t                 **********************          \n\n\n\n");
       printf("\n\t\t\t\t\t\t");
       printf("\n\t\t\t\t\t\t");
       for(i=0;i<3;i++)
        {   printf("\n\t\t\t\t\t\t");
          for(k=0;k<26;k++)
          printf("-");
          printf("\n\t\t\t\t\t\t");
          for(j=0;j<3;j++)
          printf("|   %c   |", T[i][j]);
          printf("\n\t\t\t\t\t\t");
          for(k=0;k<26;k++)
          printf("-");
        }
         printf("\n\n\n\t\t\t\t\t\t");
        if(verify_game_state(T)==-1)
         { printf("   PLAYER 1 WINS ROUND %d \n",y+1);
           scr1++;
           W[y]=1;
         }
        else if(verify_game_state(T)==1)
         { printf("   PLAYER 2 WINS ROUND %d \n",y+1);
           scr2++;
           W[y]=2;
         }
        else
        {
          printf("   EQUAL RESULTS \n");
          W[y]=3;
        }
        Sleep(2000);
        system("cls");

     }
     if(scr1>scr2)
     {
        printf("\t\t\t\t********************** TIC TAC TOE **********************\n");
        printf("\t\t\t\t                 **********************          \n\n\n\n");
        printf("\n\n\n\t\t\t\t\t   ");
        printf("\xdb\xdb\xdb\xdb\xdb\xdb\xbb  \xdb\xdb\xbb    \xdb\xdb\xbb    \xdb\xdb\xbb\xdb\xdb\xbb\xdb\xdb\xdb\xbb   \xdb\xdb\xbb");
        printf("\n\t\t\t\t\t   ");
        printf("\xdb\xdb\xc9\xcd\xcd\xdb\xdb\xbb\xdb\xdb\xdb\xba    \xdb\xdb\xba    \xdb\xdb\xba\xdb\xdb\xba\xdb\xdb\xdb\xdb\xbb  \xdb\xdb\xba");
        printf("\n\t\t\t\t\t   ");
        printf("\xdb\xdb\xdb\xdb\xdb\xdb\xc9\xbc\xc8\xdb\xdb\xba    \xdb\xdb\xba \xdb\xbb \xdb\xdb\xba\xdb\xdb\xba\xdb\xdb\xc9\xdb\xdb\xbb \xdb\xdb\xba");
        printf("\n\t\t\t\t\t   ");
        printf("\xdb\xdb\xc9\xcd\xcd\xcd\xbc  \xdb\xdb\xba    \xdb\xdb\xba\xdb\xdb\xdb\xbb\xdb\xdb\xba\xdb\xdb\xba\xdb\xdb\xba\xc8\xdb\xdb\xbb\xdb\xdb\xba");
        printf("\n\t\t\t\t\t   ");
        printf("\xdb\xdb\xba      \xdb\xdb\xba    \xc8\xdb\xdb\xdb\xc9\xdb\xdb\xdb\xc9\xbc\xdb\xdb\xba\xdb\xdb\xba \xc8\xdb\xdb\xdb\xdb\xba");
        printf("\n\t\t\t\t\t   ");
        printf("\xc8\xcd\xbc      \xc8\xcd\xbc     \xc8\xcd\xcd\xbc\xc8\xcd\xcd\xbc \xc8\xcd\xbc\xc8\xcd\xbc  \xc8\xcd\xcd\xcd\xbc");

     }else if(scr1<scr2)
        {
          printf("\t\t\t\t********************** TIC TAC TOE **********************\n");
          printf("\t\t\t\t                 **********************          \n\n\n\n");
          printf("\n\n\n\t\t\t\t\t   ");
          printf("\xdb\xdb\xdb\xdb\xdb\xdb\xbb \xdb\xdb\xdb\xdb\xdb\xdb\xbb     \xdb\xdb\xbb    \xdb\xdb\xbb\xdb\xdb\xbb\xdb\xdb\xdb\xbb   \xdb\xdb\xbb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xbb");
          printf("\n\t\t\t\t\t   ");
          printf("\xdb\xdb\xc9\xcd\xcd\xdb\xdb\xbb\xc8\xcd\xcd\xcd\xcd\xdb\xdb\xbb    \xdb\xdb\xba    \xdb\xdb\xba\xdb\xdb\xba\xdb\xdb\xdb\xdb\xbb  \xdb\xdb\xba\xdb\xdb\xc9\xcd\xcd\xcd\xcd\xbc");
          printf("\n\t\t\t\t\t   ");
          printf("\xdb\xdb\xdb\xdb\xdb\xdb\xc9\xbc \xdb\xdb\xdb\xdb\xdb\xc8\xbc    \xdb\xdb\xba \xdb\xbb \xdb\xdb\xba\xdb\xdb\xba\xdb\xdb\xc9\xdb\xdb\xbb \xdb\xdb\xba\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xbb");
          printf("\n\t\t\t\t\t   ");
          printf("\xdb\xdb\xc9\xcd\xcd\xcd\xbc \xdb\xdb\xdb\xc9\xcd\xcd\xbc     \xdb\xdb\xba\xdb\xdb\xdb\xbb\xdb\xdb\xba\xdb\xdb\xba\xdb\xdb\xba\xc8\xdb\xdb\xbb\xdb\xdb\xba\xc8\xcd\xcd\xcd\xcd\xdb\xdb\xba");
          printf("\n\t\t\t\t\t   ");
          printf("\xdb\xdb\xba     \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xbb    \xc8\xdb\xdb\xdb\xc9\xdb\xdb\xdb\xc9\xbc\xdb\xdb\xba\xdb\xdb\xba \xc8\xdb\xdb\xdb\xdb\xba\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xba");
          printf("\n\t\t\t\t\t   ");
          printf("\xc8\xcd\xbc     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xbc     \xc8\xcd\xcd\xbc\xc8\xcd\xcd\xbc \xc8\xcd\xbc\xc8\xcd\xbc  \xc8\xcd\xcd\xbc\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");

        }else
         {
           printf("\t\t\t\t********************** TIC TAC TOE **********************\n");
           printf("\t\t\t\t                 **********************          \n\n\n\n");
           printf("\n\n\n\t\t\t\t\t   ");
           printf("\xdb\xdb\xdb\xdb\xdb\xdb\xbb \xdb\xdb\xdb\xdb\xdb\xdb\xbb  \xdb\xdb\xdb\xdb\xdb\xbb \xdb\xdb\xbb    \xdb\xdb\xbb    \xdb\xdb\xbb");
           printf("\n\t\t\t\t\t   ");
           printf("\xdb\xdb\xc9\xcd\xcd\xdb\xdb\xbb\xdb\xdb\xc9\xcd\xcd\xdb\xdb\xbb\xdb\xdb\xc9\xcd\xcd\xdb\xdb\xbb\xdb\xdb\xba    \xdb\xdb\xba    \xdb\xdb\xba");
           printf("\n\t\t\t\t\t   ");
           printf("\xdb\xdb\xba  \xdb\xdb\xba\xdb\xdb\xdb\xdb\xdb\xdb\xc9\xbc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xba\xdb\xdb\xba \xdb\xbb \xdb\xdb\xba    \xdb\xdb\xba");
           printf("\n\t\t\t\t\t   ");
           printf("\xdb\xdb\xba  \xdb\xdb\xba\xdb\xdb\xc9\xcd\xcd\xdb\xdb\xbb\xdb\xdb\xc9\xcd\xcd\xdb\xdb\xba\xdb\xdb\xba\xdb\xdb\xdb\xbb\xdb\xdb\xba    \xc8\xcd\xbc");
           printf("\n\t\t\t\t\t   ");
           printf("\xdb\xdb\xdb\xdb\xdb\xdb\xc9\xbc\xdb\xdb\xba  \xdb\xdb\xba\xdb\xdb\xba  \xdb\xdb\xba\xc8\xdb\xdb\xdb\xc9\xdb\xdb\xdb\xc9\xbc    \xdb\xdb\xbb");
           printf("\n\t\t\t\t\t   ");
           printf("\xc8\xcd\xcd\xcd\xcd\xcd\xbc \xc8\xcd\xbc  \xc8\xcd\xbc\xc8\xcd\xbc  \xc8\xcd\xbc \xc8\xcd\xcd\xbc\xc8\xcd\xcd\xbc     \xc8\xcd\xbc");
         }
         printf("\n\n\n\t\t\t\t\t\t   ");
         for(i=0;i<24;i++)
           printf("-");
         printf("\n\t\t\t\t\t\t   ");
         printf("|  Round   ||  Winner  |");
         printf("\n\t\t\t\t\t\t   ");
         for(i=0;i<24;i++)
           printf("=");
         printf("\n\t\t\t\t\t\t   ");
        for(int y=0;y<rnd;y++)
        { if(W[y]==1)
            printf("|   %d      ||     P1   |",y+1);
          else if(W[y]==2)
              printf("|   %d      ||     P2   |",y+1);
          else
              printf("|   %d      ||    Draw  |",y+1);
         printf("\n\t\t\t\t\t\t   ");
         for(i=0;i<24;i++)
           printf("-");
         printf("\n\t\t\t\t\t\t   ");
        }

    }
int main() {
   //primal state test
   //empty board
   //verify game state
   // minimax function recursive
    char T[3][3]={ '1', '2', '3' , '4', '5', '6' , '7', '8', '9' };
    int f1;
    system("color B");
    interface();
    rules();
    do{
      all();
      printf("\n\n\n\t\t\t\t\t\t\t*1*PLAY AGAIN !\n\n\t\t\t\t\t\t\t*3*QUIT ");
      scanf("%d",&f1);
      system("cls");
    }while(f1==1);






    return 0;
}

