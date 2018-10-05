#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include"menu.h"
#include"hand_cricket.h"
#include"guess_the_number.h"
#include"marble_pick.h"
#include"stats.h"

using namespace std;

void load_game(void)
{
    system("cls");
    printf("\n\t\tLOADING GAME  ");
    for(int i=0;i<20;i++)
    {
        printf("%c",219);
        delay(0.1);
    }

    printf("\n\n\t\tLOADED SUCCESSFULLY");
    getchar();
    system("cls");
}

int TitleScreen(int choice)
{
    char ch=10;
    while(ch!=13){
        system("cls");

        //TITLE SCREEN
            printf("\n");
            printf("\n\t\t\t\t  **************");
            printf("\n\t\t\t\t**              **");
            printf("\n\t\t\t      ***  TITLE SCREEN  ***");
            printf("\n\t\t\t\t**              **");
            printf("\n\t\t\t\t  **************");
            printf("\n");
            printf("\n\t\t     >>> Choose the game you want to play <<<\n");

     //Title menu
        if(choice==1)
        {
            printf("\n");
            printf("\n\t\t\t\t ------------------");
            printf("\n\t\t\t\t| Guess The Number |");
            printf("\n\t\t\t\t ------------------");
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("\n\t\t\t\t  Guess The Number");
            printf("\n");
        }
        if(choice == 2)
        {
            printf("\n");
            printf("\n\t\t\t\t  -------------");
            printf("\n\t\t\t\t | Marble Pick |");
            printf("\n\t\t\t\t  -------------");
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("\n\t\t\t\t   Marble Pick");
            printf("\n");
        }
        if(choice == 3)
        {
            printf("\n");
            printf("\n\t\t\t\t ----------------");
            printf("\n\t\t\t        |  Hand Cricket  |");
            printf("\n\t\t\t\t ----------------");
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("\n\t\t\t\t   Hand Cricket");
            printf("\n");
        }
        if(choice == 4)
        {
            printf("\n");
            printf("\n\t\t\t          --------------");
            printf("\n\t\t\t         |  Statistics  |");
            printf("\n\t\t\t          --------------");
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("\n\t\t\t            Statistics");
            printf("\n");
        }
        if(choice == 5)
        {
            printf("\n");
            printf("\n\t\t\t             --------");
            printf("\n\t\t\t            |  Quit  |");
            printf("\n\t\t\t             --------");
        }
        else
        {
            printf("\n");
            printf("\n\t\t\t               Quit");
        }


        //printf("\n\n[ Use UP and DOWN arrow to select an option ]");
        ch = getch();
        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        if(choice<1)
            choice = 1;
        else if(choice>5)
            choice = 5;
    }
    return choice;

}

int HandCricket(int choice)
{
    char ch=10;
    while(ch!=13){
        system("cls");
        //Hand Cricket Title
            printf("\n");
            printf("\n\t\t\t\t  **************");
            printf("\n\t\t\t\t**              **");
            printf("\n\t\t\t      ***  Hand Cricket  ***");
            printf("\n\t\t\t\t**              **");
            printf("\n\t\t\t\t  **************");
            printf("\n");

    //Hand Cricket main menu
        if(choice==1)
        {
            printf("\n");
            printf("\n\t\t\t\t     ---------");
            printf("\n\t\t\t\t    | 1P Game |");
            printf("\n\t\t\t\t     ---------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t      1P Game");
            printf("\n\n");
        }
        if(choice == 2)
        {
            printf("\n");
            printf("\n\t\t\t\t     ---------");
            printf("\n\t\t\t\t    | 2P Game |");
            printf("\n\t\t\t\t     ---------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t      2P Game");
            printf("\n\n");
        }
        if(choice == 3)
        {
            printf("\n");
            printf("\n\t\t\t\t     ---------");
            printf("\n\t\t\t\t    |  Rules  |");
            printf("\n\t\t\t\t     ---------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t       Rules");
            printf("\n\n");
        }
        if(choice == 4)
        {
            printf("\n");
            printf("\n\t\t\t       ----------------------");
            printf("\n\t\t\t      | Back to Title Screen |");
            printf("\n\t\t\t       ----------------------");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t        Back to Title Screen");
        }

        //printf("\n\n[ Use UP and DOWN arrow to select an option ]");
        ch = getch();
        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        if(choice<1)
            choice = 1;
        else if(choice>4)
            choice = 4;
    }
    return choice;

}

int MarblePick(int choice)
{
    char ch=10;
    while(ch!=13){
        system("cls");
        //Marble Pick Title
            printf("\n");
            printf("\n\t\t\t\t  **************");
            printf("\n\t\t\t\t**              **");
            printf("\n\t\t\t      ***   Marble Pick  ***");
            printf("\n\t\t\t\t**              **");
            printf("\n\t\t\t\t  **************");
            printf("\n");

    //Marble Pick main menu
        if(choice==1)
        {
            printf("\n");
            printf("\n\t\t\t\t     ---------");
            printf("\n\t\t\t\t    | 1P Game |");
            printf("\n\t\t\t\t     ---------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t      1P Game");
            printf("\n\n");
        }
        if(choice == 2)
        {
            printf("\n");
            printf("\n\t\t\t\t     ---------");
            printf("\n\t\t\t\t    | 2P Game |");
            printf("\n\t\t\t\t     ---------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t      2P Game");
            printf("\n\n");
        }
        if(choice == 3)
        {
            printf("\n");
            printf("\n\t\t\t\t     ---------");
            printf("\n\t\t\t\t    |  Rules  |");
            printf("\n\t\t\t\t     ---------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t       Rules");
            printf("\n\n");
        }
        if(choice == 4)
        {
            printf("\n");
            printf("\n\t\t\t       ----------------------");
            printf("\n\t\t\t      | Back to Title Screen |");
            printf("\n\t\t\t       ----------------------");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t        Back to Title Screen");
        }

        //printf("\n\n[ Use UP and DOWN arrow to select an option ]");
        ch = getch();
        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        if(choice<1)
            choice = 1;
        else if(choice>4)
            choice = 4;
    }
    return choice;

}

int GuessTheNumber(int choice)
{
    char ch=10;
    while(ch!=13){
        system("cls");
        //Guess The Number Title
            printf("\n");
            printf("\n\t\t\t\t  *******************");
            printf("\n\t\t\t\t**                   **");
            printf("\n\t\t\t      ***   Guess The Number  ***");
            printf("\n\t\t\t\t**                   **");
            printf("\n\t\t\t\t  *******************");
            printf("\n");

    //Guess The Number main menu
        if(choice==1)
        {
            printf("\n");
            printf("\n\t\t\t\t      ---------");
            printf("\n\t\t\t\t     | 1P Game |");
            printf("\n\t\t\t\t      ---------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t       1P Game");
            printf("\n\n");
        }
        if(choice == 2)
        {
            printf("\n");
            printf("\n\t\t\t\t      ---------");
            printf("\n\t\t\t\t     | 2P Game |");
            printf("\n\t\t\t\t      ---------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t       2P Game");
            printf("\n\n");
        }
        if(choice == 3)
        {
            printf("\n");
            printf("\n\t\t\t\t      ---------");
            printf("\n\t\t\t\t     |  Rules  |");
            printf("\n\t\t\t\t      ---------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t        Rules");
            printf("\n\n");
        }
        if(choice == 4)
        {
            printf("\n");
            printf("\n\t\t\t        ----------------------");
            printf("\n\t\t\t       | Back to Title Screen |");
            printf("\n\t\t\t        ----------------------");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t         Back to Title Screen");
        }

        //printf("\n\n[ Use UP and DOWN arrow to select an option ]");
        ch = getch();
        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        if(choice<1)
            choice = 1;
        else if(choice>4)
            choice = 4;
    }
    return choice;

}

int stats(int choice)
{
    char ch=10;
    while(ch!=13){
        system("cls");

        //TITLE SCREEN
            printf("\n");
            printf("\n\t\t\t\t  **************");
            printf("\n\t\t\t\t**              **");
            printf("\n\t\t\t      ***   Statistics   ***");
            printf("\n\t\t\t\t**              **");
            printf("\n\t\t\t\t  **************");
            printf("\n");
            printf("\n\t>>> Choose the game whose statistics you wish to be displayed <<<\n");

     //Title menu
        if(choice==1)
        {
            printf("\n");
            printf("\n\t\t\t\t ------------------");
            printf("\n\t\t\t\t| Guess The Number |");
            printf("\n\t\t\t\t ------------------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t  Guess The Number");
            printf("\n\n");
        }
        if(choice == 2)
        {
            printf("\n");
            printf("\n\t\t\t\t  -------------");
            printf("\n\t\t\t\t | Marble Pick |");
            printf("\n\t\t\t\t  -------------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t   Marble Pick");
            printf("\n\n");
        }
        if(choice == 3)
        {
            printf("\n");
            printf("\n\t\t\t\t ----------------");
            printf("\n\t\t\t        |  Hand Cricket  |");
            printf("\n\t\t\t\t ----------------");
            printf("\n");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t\t   Hand Cricket");
            printf("\n\n");
        }
        if(choice == 4)
        {
            printf("\n");
            printf("\n\t\t\t       ----------------------");
            printf("\n\t\t\t      | Back to Title Screen |");
            printf("\n\t\t\t       ----------------------");
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t        Back to Title Screen");
        }

        printf("\n\n\t\t\t>>> Press X to clear statistics <<<");
        ch = getch();
        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        else if(ch=='x')
        {
            reset_stats();
            printf("\n\n\t\t\t\tStatistics cleared");
            get_stats();
            getch();
        }

        if(choice<1)
            choice = 1;
        else if(choice>4)
            choice = 4;
    }
    return choice;
}
