#include<stdio.h>
#include<time.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include"menu.h"
#include"marble_pick.h"
#include"stats.h"
#include<math.h>

using namespace std;

extern int a[18];

void MP_Rules(void)
{
    system("cls");

    printf("\n\nRules of the game:\n");
    printf("------------------\n\n");

    printf("The game starts with an input for the total number of marbles and the max numberof marbles that can be picked in a turn.\n\n");
    printf("In case of 1P game, there are three difficulty levels to choose from :\n1) Easy\n2) Medium\n3) Hard\n\n");
    printf("In case of 2P game, there are two modes to choose from :\n1) Last marble picker is the winner\n2) Last marble picker is the loser\n\n");
    printf("Each turn, the player or the computer will pick a number of marbles not         exceeding the max number of marbles to be picked. After both the players\' turns are finished, the remaining number of marbles are displayed.\n\n");
    printf("The game ends when there are no remaining marbles and the winner is determined  based on the mode selected.\n\n");
    printf("Note: Only numerical inputs are allowed. Character inputs are not expected and  hence may lead to unexpected results.");

    printf("\n\n>>>Press any button to return to menu screen<<<");

    getch();
}

void MP_1P()
{
    load_game();

    int gm_mode,another,marble_num,pick,player_move,sum=0,i,j;
    char player[100];
    cout<<"\nEnter your name:: ";

    gets(player);
    cout<<'\n'<<"Hello "<<player<<" !!! My name is \"aeronox\".\n\nPlease select your game mode."<<"\n\nGame Mode::\n"<<endl<<"#   E A S Y\n\n##  M E D I U M\n\n### H A R D\n";
    cout<<"\npress 1 for EASY mode or 2 for MEDIUM mode or 3 for HARD mode\n";
    cin>>gm_mode;
    system("cls");
    cout<<"Set the total number of marbles:: ";
    cin>>marble_num;
corr00:
    if(marble_num<4)
    {
        cout<<"Invalid total marble number.You must take at least 4 marbles."<<endl;
        cin>>marble_num;

        goto corr00;
    }
    cout<<"\nSet the maximum pick-up number:: ";
    cin>>pick;
corr0:
    if(pick<=0 || pick>ceil((marble_num/4.0)))
    {
        cout<<"Invalid maximum pick-up.You must take at least 1 or at most "<<ceil(marble_num/4.0)<<" marbles."<<endl;
        cin>>pick;

        goto corr0;
    }
    system("cls");




    cout<<"=========================================================\n\nIn this game the last marble picker will be the winner\n\nYou can pick at least 1 or at most "<<pick<<" marbles\n\n\naeronox will move first\n=========================================================\n\n";
    getchar();
    getchar();
    system("cls");



    another=marble_num%(pick+1);
    if(gm_mode==3)
    {
        if(another==0)
        {
            cout<<"aeronox's move:: "<<(marble_num-1)%(pick+1)<<endl;
            for(j=(marble_num-1)%(pick+1); j<=marble_num; j+=pick+1)
            {
                cout<<endl<<player<<"'s move  :: ";
                cin>>player_move;
                system("cls");
corr1:
                if(player_move<=0 || player_move>pick)
                {
                    cout<<"Invalid pick-up.You must take at least 1 or at most "<<pick<<endl;
                    cin>>player_move;

                    goto corr1;
                }
                //system("cls");

                //cout<<sum<<endl;
                if(sum==marble_num-1) break;

                cout<<"aeronox's move:: "<<(pick+1)-player_move<<endl;
                if(j==(marble_num-1)%(pick+1))
                {
                    sum+=player_move+((marble_num-1)%(pick+1))+((pick+1)-player_move);
                }
                else
                    sum+=player_move+((pick+1)-player_move);

                printf("\nremaining marbles are:: %d\n",marble_num-sum);
                //system("cls");
            }
            printf("Congratulations!!! You have won the game.\n\n");

            a[6]++;
            getch();

        }
        else
        {
            cout<<"aeronox's move:: "<<(marble_num)%(pick+1)<<endl;
            sum+=(marble_num)%(pick+1);
            for(j=another+pick+1; j<=marble_num; j+=pick+1)
            {
                cout<<endl<<player<<"'s move  :: ";
                cin>>player_move;

corr2:
                if(player_move<=0 || player_move>pick)
                {
                    cout<<"Invalid pick-up.You must take at least 1 or at most "<<pick<<endl;
                    cin>>player_move;

                    goto corr2;
                }
                system("cls");

                cout<<"aeronox's move:: "<<(pick+1)-player_move<<endl;
                if(j==(marble_num)%(pick+1))
                {
                    sum+=player_move+((marble_num)%(pick+1))+((pick+1)-player_move)+(pick+1);
                }
                else
                    sum+=player_move+((pick+1)-player_move);
                printf("\n\t remaining marbles are:: %d\n",marble_num-sum);
            }
            //printf("\n\nSorry you have lost the game......Do not worry...Try to find 'the sequence'.....\nIf you do find it then you will find the mystery here & no matter you lose here you will be winner to you for this %c %c %c!!!\n\t\nThanks a lot for playing the game....Made and developed by MD.ARSHAD WASIF [ IUT CSE :: 1st YEAR ]-----------------------------------\n\n",2,3,2);
            printf("\nYou Lost! Better luck next time\n");

            a[7]++;
            getch();
        }
    }

    else if(gm_mode==2)
    {
        if(another==0)
        {
            cout<<"aeronox's move:: "<<(marble_num-1)%(pick+1)<<endl;
            for(j=(marble_num-1)%(pick+1); j<=marble_num; j+=pick+1)
            {
                cout<<endl<<player<<"'s move  :: ";
                cin>>player_move;
corr3:
                if(player_move<=0 || player_move>pick)
                {
                    cout<<"Invalid pick-up.You must take at least 1 or at most "<<pick<<endl;
                    cin>>player_move;

                    goto corr3;
                }
                system("cls");

                //cout<<sum<<endl;
                if(sum==marble_num-1) break;
                cout<<"aeronox's move:: "<<(pick+1)-player_move<<endl;
                if(j==(marble_num-1)%(pick+1))
                {
                    sum+=player_move+((marble_num-1)%(pick+1))+((pick+1)-player_move);
                }
                else
                    sum+=player_move+((pick+1)-player_move);
                printf("\n\t remaining marbles are:: %d\n",marble_num-sum);
            }
            printf("Congratulations!!! You have won the game.\n");

            a[6]++;
            getch();

        }
        else
        {
            cout<<"aeronox's move:: "<<(marble_num)%(pick+1)<<endl;
            sum+=(marble_num)%(pick+1);
            for(j=another+pick+1; j<=marble_num; j+=pick+1)
            {
                cout<<endl<<player<<"'s move  :: ";
                cin>>player_move;
                system("cls");
corr4:
                if(player_move<=0 || player_move>pick)
                {
                    cout<<"Invalid pick-up.You must take at least 1 or at most "<<pick<<endl;
                    cin>>player_move;

                    goto corr4;
                }
                cout<<"aeronox's move:: "<<(pick+1)-player_move<<endl;
                if(j==(marble_num)%(pick+1))
                {
                    sum+=player_move+((marble_num)%(pick+1))+((pick+1)-player_move)+(pick+1);
                }
                else
                    sum+=player_move+((pick+1)-player_move);
                printf("\n\t remaining marbles are:: %d\n",marble_num-sum);
            }
            //printf("\n\nSorry!!!!you have lost the game! ......Do not worry...Try to find \"the sequence\".....\nIf you do find it then you will find the mystery here & no matter you lose here you will be winner to you for this.Best of luck!!!   %c %c %c\n\t\nThanks a lot for playing the game....Made and developed by MD.ARSHAD WASIF [ IUT CSE :: 1st YEAR ]\n\n-----------------------------------\n\n",2,3,2);
            printf("\nYou Lost! Better luck next time\n");

            a[7]++;
            getch();
        }
    }


    else if(gm_mode==1)
    {
        cout<<"aeronox's move:: "<<(marble_num-1)%(pick+1)<<endl;
        for(j=(marble_num-1)%(pick+1); j<=marble_num; j+=pick+1)
        {
            cout<<endl<<player<<"'s move  :: ";
            cin>>player_move;
corr5:
            if(player_move<=0 || player_move>pick)
            {
                cout<<"Invalid pick-up.You must take at least 1 or at most "<<pick<<endl;
                cin>>player_move;

                goto corr5;
            }
            system("cls");

            //cout<<sum<<endl;
            if(sum==marble_num-1) break;
            cout<<"aeronox's move:: "<<(pick+1)-player_move<<endl;
            if(j==(marble_num-1)%(pick+1))
            {
                sum+=player_move+((marble_num-1)%(pick+1))+((pick+1)-player_move);
            }
            else
                sum+=player_move+((pick+1)-player_move);
            printf("\n\t\t remaining marbles are:: %d\n",marble_num-sum);
        }
        printf("\n\nCongratulations!!! You have won the game.\n");
        a[6]++;

        getch();

    }

    save_stats();

}

void MP_2P()
{
    load_game();

    int toss,count=0,total_picked=0,i,player1_pick=0,player2_pick=0,rem=100,wow,pick,marble_num;
    char name[100],name1[100];

    cout<<"Enter 1st player's name::  ";
    scanf(" %[^\n]",name);
    cout<<"\nEnter 2nd player's name::  ";
    scanf(" %[^\n]",name1);
    system("cls");
    cout<<"\nChoose your game mode::\n\n#  Last marble picker is winner\n\n## Last marble picker is a loser\n\n";
    cout<<"Press 1 for the first one or 2 for the second one\n";
    cin>>wow;
corr000:
    if(wow<1 || wow>2)
    {
        cout<<"Invalid choice. Press 1 or 2."<<endl;
        cin>>wow;

        goto corr000;
    }

    system("cls");
    /*cout<<"Now who will pick first?? It will be tossed.So player 1 write any positive number.Done?\n";
    cin>>toss;*/
    cout<<"Set the total number of marbles:: ";
    cin>>marble_num;

corr00:
    if(marble_num<4)
    {
        cout<<"Invalid total marble number.You must take at least 4 marbles."<<endl;
        cin>>marble_num;

        goto corr00;
    }
    cout<<"\nSet the maximum pick-up number:: ";
    cin>>pick;
corr0:
    if(pick<=0 || pick>ceil((marble_num/4.0)))
    {
        cout<<"Invalid maximum pick-up.You must take at least 1 or at most "<<ceil(marble_num/4.0)<<" marbles."<<endl;
        cin>>pick;

        goto corr0;
    }
    system("cls");

    cout<<"Now who will pick up first ? We will do a random toss here.\n\n";
    //toss=sqrtl(rand()+(rand()*rand()));
    srand(time(NULL));
    toss = rand();

    toss=toss%2;

    if(toss==0)
    {
        cout<<"Player 1 won the toss. ";
        cout<<name<<" will move first.\n";
    }
    else
    {
        cout<<"Player 2 won the toss. ";
        cout<<name1<<" will move first.\n";
    }

    cout<<"At least you can pick up 1 or at most "<<pick<<endl<<"\n\n";
    if(toss==0)
    {
        for(i=1;; i++)
        {
            if(rem<=0) break;
            if(i%2!=0)
            {
                printf("%s's turn:: ",name);
                cin>>player1_pick;
here:
                if(player1_pick>pick||player1_pick<=0)
                {
                    cout<<"Invalid pick-up.You must take at least 1 or at most "<<pick<<endl;
                    cin>>player1_pick;
                    if(player1_pick>pick||player1_pick<=0)
                        goto here;
                }
                count+=player1_pick;
                system("cls");
                cout<<"Total picked-up marbles::"<<" "<<count<<" & remaining marbles are::"<<marble_num-count<<endl<<"\n";
                rem=marble_num-count;
            }
            else
            {
                printf("%s's turn:: ",name1);
                cin>>player2_pick;
there:
                if(player2_pick>pick||player2_pick<=0)
                {
                    cout<<"Invalid pick-up.You must take at least 1 or at most "<<pick<<endl;
                    cin>>player2_pick;
                    if(player2_pick>pick||player2_pick<=0)
                        goto there;
                }
                count+=player2_pick;
                system("cls");
                cout<<"Total picked-up marbles::"<<" "<<count<<" & remaining marbles are::"<<marble_num-count<<endl<<"\n";
                rem=marble_num-count;
            }

        }
    }
    else if(toss==1)
    {
        for(i=1;; i++)
        {
            if(rem<=0) break;
            if(i%2!=0)
            {
                printf("%s's turn:: ",name1);
                cin>>player1_pick;
yes:
                if(player1_pick>pick||player1_pick<=0)
                {
                    cout<<"Invalid pick-up.You must take at least 1 or at most "<<pick<<endl;
                    cin>>player1_pick;
                    if(player1_pick>pick||player1_pick<=0)
                        goto yes;
                }
                count+=player1_pick;
                system("cls");
                cout<<"Total picked-up marbles::"<<" "<<count<<" & remaining marbles are::"<<marble_num-count<<endl<<"\n";
                rem=marble_num-count;
            }
            else
            {
                printf("%s's turn:: ",name);
                cin>>player2_pick;
no:
                if(player2_pick>pick||player2_pick<=0)
                {
                    cout<<"Invalid pick-up.You must take at least 1 or at most "<<pick<<endl;
                    cin>>player2_pick;
                    if(player2_pick>pick||player2_pick<=0)
                        goto no;
                }
                count+=player2_pick;
                system("cls");
                cout<<"Total picked-up marbles::"<<" "<<count<<" & remaining marbles are::"<<marble_num-count<<endl<<"\n";
                rem=marble_num-count;
            }
        }
    }
    //  cout<<" "<<i;
    if(wow==1 && rem<=0)
    {
        if(toss==0 && (i-1)%2!=0)
        {
            cout<<"\nplayer 1 wins......!!"<<"Congratulations"<<" "<<name<<" !!! \n";
            a[6]++;
            a[10]++;
        }
        else if(toss==0 && (i-1)%2==0)
        {
            cout<<"\nplayer 2 wins......!!"<<"Congratulations"<<" "<<name1<<" !!! \n";
            a[9]++;
            a[7]++;
        }
        else if(toss==1 && (i-1)%2!=0)
        {
            cout<<"\nplayer 2 wins......!!"<<"Congratulations"<<" "<<name1<<" !!! \n";
            a[9]++;
            a[7]++;
        }
        else if(toss==1 && (i-1)%2==0)
        {
            cout<<"\nplayer 1 wins......!!"<<"Congratulations"<<" "<<name<<" !!! \n";
            a[6]++;
            a[10]++;
        }
    }
    else if(wow==2 && rem<=0)
    {
        if(toss==0 && (i-1)%2!=0)
        {
            cout<<"\nplayer 2 wins......!!"<<"Congratulations"<<" "<<name1<<" !!! \n";
            a[9]++;
            a[7]++;
        }
        else if(toss==0 && (i-1)%2==0)
        {
            cout<<"\nplayer 2 wins......!!"<<"Congratulations"<<" "<<name<<" !!! \n";
            a[9]++;
            a[7]++;
        }
        else if(toss==1 && (i-1)%2!=0)
        {
            cout<<"\nplayer 1 wins......!!"<<"Congratulations"<<" "<<name<<" !!! \n";
            a[6]++;
            a[10]++;
        }
        else if(toss==1 && (i-1)%2==0)
        {
            cout<<"\nplayer 2 wins......!!"<<"Congratulations"<<" "<<name1<<" !!! \n";
            a[6]++;
            a[10]++;
        }
    }

    save_stats();
    getch();


    //printf("Thanks you to all for playing this game.\n\nMade & Developed by MD ARSHAD WASIF [ IUT CSE::1st YEAR] %c %c %c\n\n----------------------------------\n\n",2,3,2);

}
