#include<stdio.h>
#include<time.h>
#include<string>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include"menu.h"
#include"hand_cricket.h"
#include"stats.h"

using namespace std;

extern int a[18];

string str_lower(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            s[i]+=32;
    }

    return s;
}

int play_pl(void)
{
    int num;
    char ch;
    printf("\nEnter any number between 1 to 6: ");
    ch = getch();
    num=ch-48;

    while(num<0||num>6)
    {
        printf("\nInvalid number!\nEnter any number between 1 to 6: ");
        scanf("%d",&num);
    }

    return num;
}

int play_pc(void)
{
    int num;
    srand(time(NULL));
    num = rand()%7;
    if(num==0)
    {
        num++;
    }

    return num;
}

void HC_Rules(void)
{
    system("cls");

    printf("\n\nRules of the game:\n");
    printf("------------------\n\n");

    printf("The game of Hand Cricket starts with fixing the number of overs. A toss is\nconducted to determine the player who gets to choose between \"Batting\" and \n\"Bowling\". The toss is carried out by letting Player 1 call \"Even\" or \"Odd\".\n");
    printf("\nAfter that, each player plays a number between 1 to 6 which will be \nadded and the sum will be checked to see whether it is even or odd, and the tosswinner is determined based on his call. \nThe toss winner chooses between \"batting\" or \"bowling\".\n");
    printf("\nThe batsman will have to achieve runs by giving numbers between 1 to 6 on each \nball. The bowler also gives a number between 1 to 6, and if it matches with the number given by the batsman, the batsman is out, otherwise the number given by\nthe batsman will add to his score. Each innings continues until \nthe batsman is out or the number of over is finished.\n");
    printf("\nThe player with the higher number of runs after both innings wins.\nOtherwise it\'s a draw.");


    printf("\n\n>>>Press any button to return to menu screen<<<");

    getch();
}

void score_board(int mode, int bat_bowl, int innings, int balls, int current_overs, int overs, int run_p1, int run_p2)
{
    char top=220,left=221,right=222,bottom=223,mid=196;
    string name1,name2;
    if(mode==1)
    {
        name1 = "Player 1";
        name2 = "Computer";
    }
    else
    {
        name1 = "Player 1";
        name2 = "Player 2";
    }

    printf("\n\n\n\n\n");

    printf("\t");                                   //Top line
    for(int i=0;i<31;i++)
        printf("%c",top);
    printf("\n");

    printf("\t%c",left);
    if(innings==1)
        printf("         1st INNINGS         %c\n",right);
    else
        printf("         2nd INNINGS         %c\n",right);

    printf("\t%c",left);
    if(bat_bowl==1)
    {
        if(innings==1)
            cout<<"       "<<name1<<" batting      ";
        else
            cout<<"       "<<name2<<" batting      ";
    }
    else
    {
        if(innings==1)
            cout<<"       "<<name2<<" batting      ";
        else
            cout<<"       "<<name1<<" batting      ";
    }
    printf("%c\n",right);

    printf("\t%c",left);                        //Partition
    for(int i=0;i<29;i++)
        printf("%c",mid);
    printf("%c\n",right);

    if(bat_bowl==1)                             //Display Runs
    {
        printf("\t%c Total runs : ",left);
        if(innings==1)
        {
            printf("%d",run_p1);
            printf("              ");
            for(int div=10;run_p1/div!=0;div*=10)
            printf("\b");
        }
        else
        {
            printf("%d",run_p2);
            printf("              ");
            for(int div=10;run_p2/div!=0;div*=10)
            printf("\b");
        }
        printf("%c\n",right);
    }
    else
    {
        printf("\t%c Total runs : ",left);
        if(innings==1)
        {
            printf("%d",run_p2);
            printf("              ");
            for(int div=10;run_p2/div!=0;div*=10)
            printf("\b");
        }
        else
        {
            printf("%d",run_p1);
            printf("              ");
            for(int div=10;run_p1/div!=0;div*=10)
            printf("\b");
        }
        printf("%c\n",right);
    }

    printf("\t%c",left);                        //Empty Line
    for(int i=0;i<29;i++)
        printf(" ");
    printf("%c\n",right);

    if(innings==2)                          //Required Runs
    {
        printf("\t%c Required runs : ",left);
        if(bat_bowl==1)
        {
            printf("%d",run_p1-run_p2+1);
            printf("           ");
            for(int div=10;(run_p1-run_p2+1)/div!=0;div*=10)
            printf("\b");
        }
        else
        {
            printf("%d",run_p2-run_p1+1);
            printf("           ");
            for(int div=10;(run_p2-run_p1+1)/div!=0;div*=10)
            printf("\b");
        }

        printf("%c\n",right);
    }


    printf("\t%c",left);                        //Again empty line
    for(int i=0;i<29;i++)
        printf(" ");
    printf("%c\n",right);

    printf("\t%c Overs : %d.%d/%d.0",left,current_overs,balls,overs);
    printf("             ");
    for(int div=10;overs/div!=0;div*=10)
        printf("\b");
    for(int div=10;current_overs/div!=0;div*=10)
        printf("\b");
    printf("%c\n",right);

     printf("\t%c",left);
    for(int i=0;i<29;i++)
        printf(" ");
    printf("%c\n",right);

    printf("\t");                               //Bottom line
    for(int i=0;i<31;i++)
        printf("%c",bottom);
    printf("\n");

    getch();

}

void HC_1P(void)
{
    load_game();

    int pl, pc, toss_p1, toss_pc, toss_win=0, bat_bowl, overs, current_overs, balls, run_p1=0, run_pc=0, innings;
    string call;

    printf("Set the number of overs: ");
    scanf("%d",&overs);
    system("cls");

    printf("Player 1 call \"Even\" or \"Odd\"\n\nType \"Even\" or \"Odd\": ");
    getchar();
    getline(cin,call);
    call = str_lower(call);
    while(call!="even"&&call!="odd")
    {
        printf("\nInvalid Call! Type \"Even\" or \"Odd\": ");
        getline(cin,call);
    }
    system("cls");

    toss_p1 = play_pl();
    toss_pc = play_pc();
    if(call=="even"&&(toss_p1+toss_pc)%2==0)
    {
        toss_win = 1;
    }
    else if(call=="odd"&&(toss_p1+toss_pc)%2==1)
    {
        toss_win = 1;
    }

    if(toss_win==1)
    {
        system("cls");
        printf("\nPlayer 1 played %d\nComputer played %d\n",toss_p1,toss_pc);
        printf("\nPlayer 1 won the toss!\nPress 1 for \"batting\" or 2 for \"bowling\"\n");
        scanf("%d",&bat_bowl);
        while(bat_bowl<1||bat_bowl>2)
        {
            printf("Invalid choice!\nPress 1 for \"batting\" or 2 for \"bowling\"\n");
            scanf("%d",&bat_bowl);
        }
        if(bat_bowl==1)     //Player 1 bats first
        {
            printf("Player 1 will bat first\n");
            getch();
            system("cls");

            innings = 1;

            balls = 0;
            current_overs=0;
            while(1)
            {
                pl = play_pl();
                pc = play_pc();
                system("cls");

                printf("\nPlayer 1 played %d\n\nComputer played %d",pl,pc);
                if(pl==pc)
                {
                    printf("\nPlayer 1 is out!\nTarget set by Player 1: %d",run_p1+1);
                    getch();
                    break;
                }
                else
                {
                    run_p1+=pl;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs)
                {
                    break;
                }
                score_board(1, bat_bowl, innings, balls, current_overs, overs, run_p1, run_pc);
            }

            innings++;
            system("cls");

            balls=0;
            current_overs=0;
            while(1)
            {
                pl = play_pl();
                pc = play_pc();
                system("cls");

                printf("\nPlayer 1 played %d\n\nComputer played %d",pl,pc);
                if(pl==pc)
                {
                    printf("\nComputer is out!");
                    getch();
                    break;
                }
                else
                {
                    run_pc+=pc;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs||run_pc>run_p1)
                {
                    break;
                }
                score_board(1, bat_bowl, innings, balls, current_overs, overs, run_p1, run_pc);
            }

            system("cls");
            printf("TOTAL RUNS\n\nPlayer 1: %d\n\nComputer: %d",run_p1,run_pc);
            if(run_p1>run_pc)
            {
                printf("\n\n\n\t\tPLAYER 1 WINS!");
                a[12]++;
            }
            else if(run_p1<run_pc)
            {
                printf("\n\n\n\t\tCOMPUTER WINS!");
                a[13]++;
            }
            else
            {
                printf("\n\n\n\t\tDRAW GAME!");
                a[14]++;
            }

        }
        else
        {
            printf("Player 1 will bowl first\n");
            getch();
            system("cls");

            innings=1;

            balls=0;
            current_overs=0;
            while(1)
            {
                pl = play_pl();
                pc = play_pc();
                system("cls");

                printf("\nPlayer 1 played %d\n\nComputer played %d",pl,pc);
                if(pl==pc)
                {
                    printf("\nComputer is out!\nTarget set by Computer: %d",run_pc+1);
                    getch();
                    break;
                }
                else
                {
                    run_pc+=pc;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs)
                {
                    break;
                }
                score_board(1, bat_bowl, innings, balls, current_overs, overs, run_p1, run_pc);
            }

            innings++;
            system("cls");

            balls = 0;
            current_overs=0;
            while(1)
            {
                pl = play_pl();
                pc = play_pc();
                system("cls");

                printf("\nPlayer 1 played %d\n\nComputer played %d",pl,pc);
                if(pl==pc)
                {
                    printf("\nPlayer 1 is out!");
                    getch();
                    break;
                }
                else
                {
                    run_p1+=pl;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs||run_p1>run_pc)
                {
                    break;
                }
                score_board(1, bat_bowl, innings, balls, current_overs, overs, run_p1, run_pc);
            }

            system("cls");
            printf("TOTAL RUNS\n\nPlayer 1: %d\n\nComputer: %d",run_p1,run_pc);
            if(run_p1>run_pc)
            {
                printf("\n\n\n\t\tPLAYER 1 WINS!");
                a[12]++;
            }
            else if(run_p1<run_pc)
            {
                printf("\n\n\n\t\tCOMPUTER WINS!");
                a[13]++;
            }
            else
            {
                printf("\n\n\n\t\tDRAW GAME!");
                a[14]++;
            }
        }
    }
    else
    {
        system("cls");
        printf("\nPlayer 1 played %d\nComputer played %d\n",toss_p1,toss_pc);
        printf("\nComputer won the toss!\n");

        srand(time(NULL));
        bat_bowl = rand()%2;
        bat_bowl++;
        if(bat_bowl==2)
        {
            printf("Computer will bat first\n");
            getch();
            system("cls");

            innings=1;

            balls=0;
            current_overs=0;
            while(1)
            {
                pl = play_pl();
                pc = play_pc();
                system("cls");

                printf("\nPlayer 1 played %d\n\nComputer played %d",pl,pc);
                if(pl==pc)
                {
                    printf("\nComputer is out!\nTarget set by Computer: %d",run_pc+1);
                    getch();
                    break;
                }
                else
                {
                    run_pc+=pc;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs)
                {
                    break;
                }
                score_board(1, bat_bowl, innings, balls, current_overs, overs, run_p1, run_pc);
            }

            innings++;
            system("cls");

            balls = 0;
            current_overs=0;
            while(1)
            {
                pl = play_pl();
                pc = play_pc();
                system("cls");

                printf("\nPlayer 1 played %d\n\nComputer played %d",pl,pc);
                if(pl==pc)
                {
                    printf("\nPlayer 1 is out!");
                    getch();
                    break;
                }
                else
                {
                    run_p1+=pl;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }


                if(current_overs==overs||run_p1>run_pc)
                {
                    break;
                }
                score_board(1, bat_bowl, innings, balls, current_overs, overs, run_p1, run_pc);
            }

            system("cls");
            printf("TOTAL RUNS\n\nPlayer 1: %d\n\nComputer: %d",run_p1,run_pc);
            if(run_p1>run_pc)
            {
                printf("\n\n\n\t\tPLAYER 1 WINS!");
                a[12]++;
            }
            else if(run_p1<run_pc)
            {
                printf("\n\n\n\t\tCOMPUTER WINS!");
                a[13]++;
            }
            else
            {
                printf("\n\n\n\t\tDRAW GAME!");
                a[14]++;
            }
        }
        else
        {
            printf("Computer will bowl first\n");
            getch();
            system("cls");

            innings = 1;

            balls = 0;
            current_overs=0;
            while(1)
            {
                pl = play_pl();
                pc = play_pc();
                system("cls");

                printf("\nPlayer 1 played %d\n\nComputer played %d",pl,pc);
                if(pl==pc)
                {
                    printf("\nPlayer 1 is out!\nTarget set by Player 1: %d",run_p1+1);
                    getch();
                    break;
                }
                else
                {
                    run_p1+=pl;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs)
                {
                    break;
                }
                score_board(1, bat_bowl, innings, balls, current_overs, overs, run_p1, run_pc);
            }

            innings++;
            system("cls");

            balls=0;
            current_overs=0;
            while(1)
            {
                pl = play_pl();
                pc = play_pc();
                system("cls");

                printf("\nPlayer 1 played %d\n\nComputer played %d",pl,pc);
                if(pl==pc)
                {
                    printf("\nComputer is out!");
                    getch();
                    break;
                }
                else
                {
                    run_pc+=pc;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs||run_pc>run_p1)
                {
                    break;
                }
                score_board(1, bat_bowl, innings, balls, current_overs, overs, run_p1, run_pc);
            }

            system("cls");
            printf("TOTAL RUNS\n\nPlayer 1: %d\n\nComputer: %d",run_p1,run_pc);
            if(run_p1>run_pc)
            {
                printf("\n\n\n\t\tPLAYER 1 WINS!");
                a[12]++;
            }
            else if(run_p1<run_pc)
            {
                printf("\n\n\n\t\tCOMPUTER WINS!");
                a[13]++;
            }
            else
            {
                printf("\n\n\n\t\tDRAW GAME!");
                a[14]++;
            }

        }
    }


    save_stats();
    getch();
}


void HC_2P(void)
{
    load_game();

    int p1, p2, toss_p1, toss_p2, toss_win=0, bat_bowl, overs, current_overs, balls, run_p1=0, run_p2=0, innings;
    string call;

    printf("Set the number of overs: ");
    scanf("%d",&overs);
    system("cls");

    printf("Player 1 call \"Even\" or \"Odd\"\n\nType \"Even\" or \"Odd\": ");
    getchar();
    getline(cin,call);
    call = str_lower(call);
    while(call!="even"&&call!="odd")
    {
        printf("\nInvalid Call! Type \"Even\" or \"Odd\": ");
        getline(cin,call);
    }
    system("cls");

    printf("\n\nPlayer 1\n\n");
    toss_p1 = play_pl();
    printf("\n\nPlayer 2\n\n");
    toss_p2 = play_pl();
    if(call=="even"&&(toss_p1+toss_p2)%2==0)
    {
        toss_win = 1;
    }
    else if(call=="odd"&&(toss_p1+toss_p2)%2==1)
    {
        toss_win = 1;
    }

    if(toss_win==1)
    {
        system("cls");
        printf("\nPlayer 1 played %d\nPlayer 2 played %d\n",toss_p1,toss_p2);
        printf("\nPlayer 1 won the toss!\nPress 1 for \"batting\" or 2 for \"bowling\"\n");
        scanf("%d",&bat_bowl);
        while(bat_bowl<1||bat_bowl>2)
        {
            printf("Invalid choice!\nPress 1 for \"batting\" or 2 for \"bowling\"\n");
            scanf("%d",&bat_bowl);
        }
        if(bat_bowl==1)     //Player 1 bats first
        {
            printf("Player 1 will bat first\n");
            getch();
            system("cls");

            innings = 1;

            balls = 0;
            current_overs=0;
            while(1)
            {
                p1 = play_pl();
                p2 = play_pl();
                system("cls");

                printf("\nPlayer 1 played %d\n\nPlayer 2 played %d",p1,p2);
                if(p1==p2)
                {
                    printf("\nPlayer 1 is out!\nTarget set by Player 1: %d",run_p1+1);
                    getch();
                    break;
                }
                else
                {
                    run_p1+=p1;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs)
                {
                    break;
                }
                score_board(2, bat_bowl, innings, balls, current_overs, overs, run_p1, run_p2);
            }

            innings++;
            system("cls");

            balls=0;
            current_overs=0;
            while(1)
            {
                p1 = play_pl();
                p2 = play_pl();
                system("cls");

                printf("\nPlayer 1 played %d\n\nPlayer 2 played %d",p1,p2);
                if(p1==p2)
                {
                    printf("\nPlayer 2 is out!");
                    getch();
                    break;
                }
                else
                {
                    run_p2+=p2;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs||run_p2>run_p1)
                {
                    break;
                }
                score_board(2, bat_bowl, innings, balls, current_overs, overs, run_p1, run_p2);
            }

            system("cls");
            printf("TOTAL RUNS\n\nPlayer 1: %d\n\nPlayer 2: %d",run_p1,run_p2);
            if(run_p1>run_p2)
            {
                printf("\n\n\n\t\tPLAYER 1 WINS!");
                a[16]++;
            }
            else if(run_p1<run_p2)
            {
                printf("\n\n\n\t\tPLAYER 2 WINS!");
                a[15]++;
            }
            else
            {
                printf("\n\n\n\t\tDRAW GAME!");
                a[17]++;
            }

        }
        else
        {
            printf("Player 1 will bowl first\n");
            getch();
            system("cls");

            innings=1;

            balls=0;
            current_overs=0;
            while(1)
            {
                p1 = play_pl();
                p2 = play_pl();
                system("cls");

                printf("\nPlayer 1 played %d\n\nPlayer 2 played %d",p1,p2);
                if(p1==p2)
                {
                    printf("\nPlayer 2 is out!\nTarget set by Player 2: %d",run_p2+1);
                    getch();
                    break;
                }
                else
                {
                    run_p2+=p2;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs)
                {
                    break;
                }
                score_board(2, bat_bowl, innings, balls, current_overs, overs, run_p1, run_p2);
            }

            innings++;
            system("cls");

            balls = 0;
            current_overs=0;
            while(1)
            {
                p1 = play_pl();
                p2 = play_pl();
                system("cls");

                printf("\nPlayer 1 played %d\n\nPlayer 2 played %d",p1,p2);
                if(p1==p2)
                {
                    printf("\nPlayer 1 is out!");
                    getch();
                    break;
                }
                else
                {
                    run_p1+=p1;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs||run_p1>run_p2)
                {
                    break;
                }
                score_board(2, bat_bowl, innings, balls, current_overs, overs, run_p1, run_p2);
            }

            system("cls");
            printf("TOTAL RUNS\n\nPlayer 1: %d\n\nPlayer 2: %d",run_p1,run_p2);
            if(run_p1>run_p2)
            {
                printf("\n\n\n\t\tPLAYER 1 WINS!");
                a[16]++;
            }
            else if(run_p1<run_p2)
            {
                printf("\n\n\n\t\tPlayer 2 WINS!");
                a[15]++;
            }
            else
            {
                printf("\n\n\n\t\tDRAW GAME!");
                a[17]++;
            }
        }
    }
    else
    {
        system("cls");
        printf("\nPlayer 1 played %d\nPlayer 2 played %d\n",toss_p1,toss_p2);

        printf("\nPlayer 2 won the toss!\nPress 1 for \"batting\" or 2 for \"bowling\"\n");
        scanf("%d",&bat_bowl);
        while(bat_bowl<1||bat_bowl>2)
        {
            printf("Invalid choice!\nPress 1 for \"batting\" or 2 for \"bowling\"\n");
            scanf("%d",&bat_bowl);
        }

        if(bat_bowl==1)     //value of bat_bowl is used to determine the order of batting and bowling for player 1, so the input of player 2 is modified internally
            bat_bowl=2;
        else
            bat_bowl=1;

        if(bat_bowl==2)
        {
            printf("Player 2 will bat first\n");
            getch();
            system("cls");

            innings=1;

            balls=0;
            current_overs=0;
            while(1)
            {
                p1 = play_pl();
                p2 = play_pl();
                system("cls");

                printf("\nPlayer 1 played %d\n\nPlayer 2 played %d",p1,p2);
                if(p1==p2)
                {
                    printf("\nPlayer 2 is out!\nTarget set by Player 2: %d",run_p2+1);
                    getch();
                    break;
                }
                else
                {
                    run_p2+=p2;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs)
                {
                    break;
                }
                score_board(2, bat_bowl, innings, balls, current_overs, overs, run_p1, run_p2);
            }

            innings++;
            system("cls");

            balls = 0;
            current_overs=0;
            while(1)
            {
                p1 = play_pl();
                p2 = play_pl();
                system("cls");

                printf("\nPlayer 1 played %d\n\nPlayer 2 played %d",p1,p2);
                if(p1==p2)
                {
                    printf("\nPlayer 1 is out!");
                    getch();
                    break;
                }
                else
                {
                    run_p1+=p1;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }


                if(current_overs==overs||run_p1>run_p2)
                {
                    break;
                }
                score_board(2, bat_bowl, innings, balls, current_overs, overs, run_p1, run_p2);
            }

            system("cls");
            printf("TOTAL RUNS\n\nPlayer 1: %d\n\nPlayer 2: %d",run_p1,run_p2);
            if(run_p1>run_p2)
            {
                printf("\n\n\n\t\tPLAYER 1 WINS!");
                a[16]++;
            }
            else if(run_p1<run_p2)
            {
                printf("\n\n\n\t\tPlayer 2 WINS!");
                a[15]++;
            }
            else
            {
                printf("\n\n\n\t\tDRAW GAME!");
                a[17]++;
            }
        }
        else
        {
            printf("Player 2 will bowl first\n");
            getch();
            system("cls");

            innings = 1;

            balls = 0;
            current_overs=0;
            while(1)
            {
                p1 = play_pl();
                p2 = play_pl();
                system("cls");

                printf("\nPlayer 1 played %d\n\nPlayer 2 played %d",p1,p2);
                if(p1==p2)
                {
                    printf("\nPlayer 1 is out!\nTarget set by Player 1: %d",run_p1+1);
                    getch();
                    break;
                }
                else
                {
                    run_p1+=p1;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs)
                {
                    break;
                }
                score_board(2, bat_bowl, innings, balls, current_overs, overs, run_p1, run_p2);
            }

            innings++;
            system("cls");

            balls=0;
            current_overs=0;
            while(1)
            {
                p1 = play_pl();
                p2 = play_pl();
                system("cls");

                printf("\nPlayer 1 played %d\n\nPlayer 2 played %d",p1,p2);
                if(p1==p2)
                {
                    printf("\nPlayer 2 is out!");
                    getch();
                    break;
                }
                else
                {
                    run_p2+=p2;
                }

                balls++;
                if(balls==6)
                {
                    balls=0;
                    current_overs++;
                }

                if(current_overs==overs||run_p2>run_p1)
                {
                    break;
                }
                score_board(2, bat_bowl, innings, balls, current_overs, overs, run_p1, run_p2);
            }

            system("cls");
            printf("TOTAL RUNS\n\nPlayer 1: %d\n\nPlayer 2: %d",run_p1,run_p2);
            if(run_p1>run_p2)
            {
                printf("\n\n\n\t\tPLAYER 1 WINS!");
                a[16]++;
            }
            else if(run_p1<run_p2)
            {
                printf("\n\n\n\t\tPlayer 2 WINS!");
                a[15]++;
            }
            else
            {
                printf("\n\n\n\t\tDRAW GAME!");
                a[17]++;
            }

        }
    }


    save_stats();
    getch();
}
