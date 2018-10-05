#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"menu.h"
#include"guess_the_number.h"
#include"marble_pick.h"
#include"hand_cricket.h"
#include"stats.h"
#include<windows.h>

using namespace std;

extern int a[18];

int main()
{
    system("mode 80,140");
    system("color fc");

    get_stats();
    //printf("%d %d %d %d\n",a[0],a[1],a[2],a[17]);
    //getch();


    int choice=1;


    while(choice)
    {
        choice = TitleScreen(choice);
        if(choice==1)
        {
            choice = 1;
            while(choice!=4)
            {
                choice = GuessTheNumber(choice);
                switch(choice){
                case 1: GTN_1P();
                        break;
                case 2: GTN_2P();
                        break;
                case 3: GTN_Rules();
                        break;
                case 4: printf("\n\n");
                }
            }

        }
        else if(choice==2)
        {
            choice = 1;
            while(choice!=4)
            {
                choice = MarblePick(choice);
                switch(choice){
                case 1: MP_1P();
                        break;
                case 2: MP_2P();
                        break;
                case 3: MP_Rules();
                        break;
                case 4: printf("\n\n");
                }
            }
        }
        else if(choice==3)
        {
            choice = 1;
            while(choice!=4)
            {
                choice = HandCricket(choice);
                switch(choice){
                case 1: HC_1P();
                        break;
                case 2: HC_2P();
                        break;
                case 3: HC_Rules();
                        break;
                case 4: printf("\n\n");
                }
            }
        }
        else if(choice==4)
        {
            choice = 1;
            while(choice!=4)
            {
                choice = stats(choice);
                switch(choice){
                case 1: GTN_display_stats();
                        break;
                case 2: MP_display_stats();
                        break;
                case 3: HC_display_stats();
                        break;
                case 4: printf("\n\n");
                }
            }
        }
        else
        {
            printf("\n\n");
            break;
        }
        choice = 1;


    }

    return 0;
}
