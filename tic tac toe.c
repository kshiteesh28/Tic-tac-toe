//TIC TAC TOE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct name
{
    char name[20];
}pn;

void delay(int); //used in time delay function (1000ms==1s)
void menu(int,pn*);
void game_mode(pn *);
void PvP_game_play(pn *);
void PvC_game_play(pn *);
void game_help();
int win_condition(char ch[],pn *playerName);
void PvP_player_names(pn *);
void PvC_player_name(pn *);
void board(pn *playerName,char ch[],int num,char alpha);
void name_swap(pn *);

int main()
{
    pn *playerName;
    playerName=(pn*)malloc(2*sizeof(pn)); //dynamic memory allocation in heap
    int choice;
    srand(time(0)); //used for generating random sequence of numbers
    menu(choice,playerName);

    return 0;
}
void menu(int choice,pn *playerName)
{
    do{
        printf("           ((^-^))           W.E.L.C.O.M.E      ((^-^))                        \n");delay(800);
        printf("                  ########     ######        ####                         \n");delay(400);
        printf("                     ##          ##        ##                            \n");delay(400);
        printf("                     ##          ##        ##                            \n");delay(400);
        printf("                     ##          ##        ##                            \n");delay(400);
        printf("                     ##        ######        ####                         \n");delay(800);
        printf("                                                                         \n");
        printf("                  ########     ######       ####                             \n");delay(400);
        printf("                     ##        ##  ##     ##                                \n");delay(400);
        printf("                     ##        ##  ##     ##                                \n");delay(400);
        printf("                     ##        ######     ##                                \n");delay(400);
        printf("                     ##        ##  ##       ####                             \n");delay(800);
        printf("                                                                             \n");
        printf("                   ########     ######     ######                            \n");delay(400);
        printf("                      ##        ##  ##     ##                                \n");delay(400);
        printf("                      ##        ##  ##     ######                            \n");delay(400);
        printf("                      ##        ##  ##     ##                                \n");delay(400);
        printf("                      ##        ######     ######                            \n");delay(800);
        printf("                                                                             \n");
        printf(""
               "\n\n\n"
               "Hellooooooooooooo!!!!!\n"
               "\n\n"
               "1.Play  \n"
               "2.Help  \n"
               "3.Exit  \n"
               "Click on the option of your choice:");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
            case 1:game_mode(playerName);break;
            case 2:game_help();break;
            case 3:exit(0);
            default:printf("\n Enter the given options only:\n\n");
        }

      }while(choice!=3);
}
void game_mode(pn *playername)
{
    int choice;

    do
    {
        printf("\n      Game Mode     \n\n");
        printf("\n1. Player VS Player"
               "\n2. Player VS Computer"
               "\n3. return to menu"
               "\n4. Exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
            case 1:PvP_player_names(playername); //to collect player names
                   PvP_game_play(playername);break;

            case 2:PvC_player_name(playername);
                   PvC_game_play(playername);break;
            case 3:menu(choice,playername);
            case 4:exit(0);
            default:printf("\nEnter given options only!\n\n\n");
        }
    }while(choice!=4);
}

void game_help() //to display instructions
{
    system("cls");
    printf("\t\tHOW TO PLAY?\n\n");
    printf("1. The board is of size 3 cross 3\n");
    printf("2. The boxes are numbered from 1 to 9.\n");
    printf("3. Player 1: X\t Player 2: O\n");
    printf("4. Player will get a chance alternatively.\n");
    printf("5. Enter a valid choice from 1-9.\n");
    printf("6. Do not enter a number if that is replaced by 'X' or 'O'.\n");
    printf("7. The first player to get 3 of his/her marks in a row (up, down, across, or diagonally) is the winner.\n\n");
    printf("\n\n Warning : Do not enter any key \nThis page will automatically return back to home page in 10 seconds !!\n"
           "\nHave a good game play !!\n");
    delay(10000);
    system("cls");
    return;
}

void board(pn *playerName,char ch[],int num,char XO) //displays the game board
{
    ch[num]=XO;
    system("cls");
    printf("          TIC TAC TOE         ");
    printf("\n\n\n");
    printf("    %s - 'X'  \t  %s - 'O'  \n\n\n",playerName[0].name,playerName[1].name);

    printf("             1 | 2 | 3       \n");
    printf("           -------------    \n");
    printf("             4 | 5 | 6       \n");
    printf("           -------------    \n");
    printf("             7 | 8 | 9       \n\n");

    printf("             %c | %c | %c       \n",ch[1],ch[2],ch[3]);
    printf("           -------------     \n");
    printf("             %c | %c | %c       \n",ch[4],ch[5],ch[6]);
    printf("           -------------     \n");
    printf("             %c | %c | %c       \n",ch[7],ch[8],ch[9]);
}

void PvP_game_play(pn *playerName)
{
    int number=0,choice;
    char array[11]= "           ";
    char XO=' ';
    board(playerName,array,number,XO);

    for(int i=1;i<=5;i++)
    {
       if(win_condition(array,playerName)==0)
        break;
       else
       {
        printf("\n %s enter your number:",playerName[0].name);
        scanf("%d",&number);
        while(number>9 || number<1 || array[number]!=' ')
        {
            printf("\n Invalid !!"
                   "\n Enter your number again:");
            scanf("%d",&number);
        }
        XO='X';
        board(playerName,array,number,XO);
       }
       if(win_condition(array,playerName)==0)
        break;
       else
       {
        printf("\n %s enter your number:",playerName[1].name);
        scanf("%d",&number);
        while(number>9 || number<1 || array[number]!=' ')
        {
            printf("\n Invalid !!"
                   "\n Enter your number again:");
            scanf("%d",&number);
        }
        XO='O';
        board(playerName,array,number,XO);
       }
    }
       do
       {
        printf("\n Do yo want to"
               "\n 1.Have a rematch?"
               "\n 2.Return to game mode"
               "\n 3.exit?");
        printf("\n click your choice:");
        scanf("%d",&choice);
        system("cls");

        switch(choice)
        {
            case 1:name_swap(playerName); //swaps name as second player gets first turn in next round
                   PvP_game_play(playerName);break;
            case 2:game_mode(playerName);
            case 3:exit(0);
            default:printf("\nEnter given options only!");
        }
       }while(choice!=3);
}

void PvC_game_play(pn *playerName)
{
    int number=0,choice;
    char array[11]= "           ";
    char XO=' ';
    board(playerName,array,number,XO);

    for(int i=1;i<=5;i++)
    {
       if(win_condition(array,playerName)==0)
        break;
       else
       {
        printf("\n %s enter your number:",playerName[0].name);
        scanf("%d",&number);
        while(number>9 || number<1 || array[number]!=' ')
        {
            printf("\n Invalid !!"
                   "\n Enter your number again:");
            scanf("%d",&number);
        }
        XO='X';
        board(playerName,array,number,XO);
       }
       if(win_condition(array,playerName)==0)
        break;
       else
       {
        number=(rand()%(9-1+1))+1;
        while(number>9 || number<1 || array[number]!=' ')
        {
            number=(rand()%(9-1+1))+1;
        }
        XO='O';
        board(playerName,array,number,XO);
       }
    }
       do
       {
        printf("\n Do yo want to"
               "\n 1.Have a rematch?"
               "\n 2.Return to game mode"
               "\n 3.exit?");
        printf("\n click your choice:");
        scanf("%d",&choice);
        system("cls");

        switch(choice)
        {
            case 1:PvC_game_play(playerName);break;
            case 2:game_mode(playerName);;
            case 3:exit(0);
            default:printf("\nEnter given options only!");
        }
       }while(choice!=3);
}
void PvC_player_name(pn *playerName)
{
    printf("\n     Player VS Computer     \n");
    printf("\nEnter name of player:");
    scanf("%s",(playerName+0)->name);
    strcpy((playerName+1)->name,"Computer");
}

void PvP_player_names(pn *playerName)
{
    printf("\n     Player VS Player     \n");
    for(int i=0;i<=1;++i)
    {
        printf("\nEnter name of player %d:",i+1);
        scanf("%s",(playerName+i)->name);
    }
}
int win_condition(char ch[],pn *playerName) //checks for win condition in rows,columns and diagonals respectively
{
   if((ch[1]=='X' && ch[2]=='X' && ch[3]=='X')||(ch[4]=='X' && ch[5]=='X' && ch[6]=='X')||(ch[7]=='X' && ch[8]=='X' && ch[9]=='X')||
      (ch[1]=='X' && ch[4]=='X' && ch[7]=='X')||(ch[2]=='X' && ch[5]=='X' && ch[8]=='X')||(ch[3]=='X' && ch[6]=='X' && ch[9]=='X')||
      (ch[1]=='X' && ch[5]=='X' && ch[9]=='X')||(ch[3]=='X' && ch[5]=='X' && ch[7]=='X'))

   {
       printf("\n  %s is the winner!! \n",(playerName+0)->name);return 0;
   }
   else if((ch[1]=='O' && ch[2]=='O' && ch[3]=='O')||(ch[4]=='O' && ch[5]=='O' && ch[6]=='O')||(ch[7]=='O' && ch[8]=='O' && ch[9]=='O')||
           (ch[1]=='O' && ch[4]=='O' && ch[7]=='O')||(ch[2]=='O' && ch[5]=='O' && ch[8]=='O')||(ch[3]=='O' && ch[6]=='O' && ch[9]=='O')||
           (ch[1]=='O' && ch[5]=='O' && ch[9]=='O')||(ch[3]=='O' && ch[5]=='O' && ch[7]=='O'))

    {
        printf("\n %s is the winner!! \n",(playerName+1)->name);return 0;
    }
  else if(ch[1]!=' ' && ch[2]!=' ' && ch[3]!=' ' && ch[4]!=' ' && ch[5]!=' ' && ch[6]!=' ' && ch[7]!=' ' && ch[8]!=' ' && ch[9]!=' ')
  {
      printf("\n It's a draw game !! \n");return 0;
  }

  return 1;
}
void delay(int ms)
{
    clock_t timedelay =ms + clock();
    while(timedelay>clock());
}
void name_swap(pn *playername)
{
    pn temp;
    temp=playername[0];
    playername[0]=playername[1];
    playername[1]=temp;
}
