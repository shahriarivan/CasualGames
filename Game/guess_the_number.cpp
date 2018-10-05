#include<bits/stdc++.h>
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
int show[5000],i=0,flag,range;
char player_1[100],player_2[100];

//prototypes of UD functions for 1P game(starts)

void GTN_Rules(void)
{
    system("cls");

    printf("\n\nRules of the game:\n");
    printf("------------------\n\n");

    printf("The game starts with the computer randomly choosing an integer which will remainhidden to the player currently playing. The range in which the number exists    will be given to the player.\n\n");
    printf("The player will have to guess the number by giving inputs each time.  The playerhas 10 seconds to give input or else he loses a turn. After a certain number of failed attempts, the player will be given three hints about the number of which he can choose to take one hint.\n\n");
    printf("In case of 1P game, the player must guess the number before his allotted number of turns are exhausted in order to win the game.\n\n");
    printf("Similar Rules are applied for 2P game. In this case, the player who guessed the number correctly first will be the winner.\n\n");

    printf("\n\n>>>Press any button to return to menu screen<<<");

    getch();
}

void show_hintsTimer(int the_num,int count,int range);
int showTimer(double sec,int count);
void even_odd(int the_num,int range);
void last_digit(int the_num,int range);
void is_prime(int the_num,int range);
//prototypes of UD functions for 1P game(ends)

//prototypes of UD functions for 2P game(starts)
void display(int range);
void omit(int the_num,int input,int range);
int hidden_divisor();
int hidden_number();
void delay(double sec);
void showTimer_for_p1(char *player_1,char *player_2);
void showTimer_for_p2(char *player_1,char *player_2);
int toss(char *player_1,char *player_2);
//prototypes of UD functions for 2P game(ends)

///1P game starts
void GTN_1P()
{
    load_game();
    for(int i=0;i<5000;i++)
    {
        show[i]=0;
    }

    int input,count=0,range,the_num,turns;

    the_num=hidden_number();
    //printf("%d\n",the_num);
    if(the_num<=1000){
        range=1000;
        cout<<"Your number is in the range of 1 to 1000. Can you guess it within 9 turns?\n\n";
        turns = 9;
    }
    else if(the_num>1000 && the_num<=2000){
        range=2000;
        cout<<"Your number is in the range of 1 to 2000. Can you guess it within 10 turns?\n\n";
        turns = 10;
    }
    else if(the_num>2000){
        range=5000;
        cout<<"Your number is in the range of 1 to 5000. Can you guess it within 11 turns?\n\n";
        turns = 11;
    }
    delay(2.0);
    display(range);
    cout<<"Press enter key to continue......";
    getchar();
    while(1){
        showTimer(10.0,count);
        scanf("%d",&input);
        if(the_num==input){
            count++;
            cout<<"Well done !!!\n";
            break;
        }
        count++;
        cout<<"Sorry !! Incorrect !!Try again.\n\n";

        if(input<the_num){
            cout<<"Your number is bigger than "<<input<<endl;
            delay(2.0);

            omit(the_num,input,range);
            display(range);
        }
        else{
            cout<<"Your number is smaller than "<<input<<endl;
            delay(2.0);

            omit(the_num,input,range);
            display(range);
        }
        if((count==7 && range==5000)||(count==6 && range==2000)||(count==5 && range==1000)){
            show_hintsTimer(the_num,count,range);
        }
        else
        {
            delay(3.0);
        }
    }


    printf("\nTotal turns used: %d\n",count);
    if(count>turns)
    {
        printf("\nYou failed to find the number within %d turns! You lose!\n",turns);
        a[1]++;
    }
    else
    {
        printf("\nYou found the number within %d turns! You win!\n",turns);
        a[0]++;
    }
    printf("\nPress any key to end game");
    save_stats();
    getch();
}
///1P game ends

//user defined functions for 1P game(starts)

int showTimer(double sec,int count)
{
    int total=0;
    int set_time=sec;// can be changed later
    while(1)
    {
       if(total%60<10)
            printf("Give your move: \t\t\t\t\t\t%d:0%d\n\n",total/60,total%60);
        else
            printf("Give your move: \t\t\t\t\t\t%d:%d\n\n",total/60,total%60);
        if(kbhit())
        {
            //system("cls");
            return total;
        }
        delay(1.0);
        system("cls");
        total++;
        if(total==(double)set_time+1.0)
        {
            //delay(2.2);
            system("cls");
            cout<<"Sorry !! You have lost one move.Your next move ::\n";
            count++;
            delay(2.5);
            total=showTimer(10.0,count);
            system("cls");
        }
    }

}
void show_hintsTimer(int the_num,int count,int range)
{
    int total=0;
    int set_time=10;
    char ch;
    printf("W A I T !!!\nHere are some hints for you.\n\n (1) EVEN-ODD TEST\n (2) REVEAL THE LAST DIGIT\n (3) IS THE NUMBER A PRIME OR NOT\n");
    delay(2.5);
    cout<<"\nYou have 10 seconds to choose.Starting now.....\n";
    delay(2.2);
    while(1)
    {
       if(total%60<10){
            cout<<"Press 1 or 2 or 3\n";
            printf("\t\t\t\t\t\t%d:0%d\n\n",total/60,total%60);
       }
        else{
            cout<<"Press 1 or 2 or 3\n";
            printf("\t\t\t\t\t\t%d:%d\n\n",total/60,total%60);
        }
        if(kbhit())
        {
            //system("cls");
            break;
        }
        delay(1.0);
        system("cls");
        total++;
        if(total==(double)set_time+1.0)
        {
            delay(2.2);
            system("cls");
            cout<<"Sorry !! Time's Up.You have lost one move.";
            count++;
            showTimer(10.0,count);
        }
    }
    ch=getch();
    switch(ch)
    {
        case '1' : even_odd(the_num,range);
                   break;
        case '2' : last_digit(the_num,range);
                   break;
        case '3' : is_prime(the_num,range);
                   break;
        default  : break;

    }
    cout<<"Remaining numbers are::\n\n";
    display(range);
    delay(3.0);
}
void even_odd(int the_num,int range)
{
    if(the_num%2==0)
        printf("It is an E V E N number\n");
    else
        printf("It is an O D D number\n");
    delay(4.0);


}
void last_digit(int the_num,int range)
{
    printf("The last digit of the hidden number is : %d\n",the_num%10);
    delay(4.0);

}
void is_prime(int the_num,int range)
{
    int potaka=0;
    for(int i=2;i<=sqrt(the_num);i++){
        if(the_num%i==0){
            potaka=1;
            break;
        }
    }
    if(potaka==0)
        printf("Yes, the number is a prime.\n");
    else
        printf("No, the number is not a prime.\n");
    delay(4.0);


}
//user defined functions for 1P game(ends)


///2P game starts
void GTN_2P()
{
    load_game();
    for(int j=0;j<5000;j++)
    {
        show[j]=0;
    }

    //for naming of players
    cout<<"Write down your names::\n\n\nP L A Y E R  1  :: ";

    char player_1[100],player_2[100];
    int var,input;
    scanf(" %[^\n]",player_1);

    cout<<"\n\nP L A Y E R  2  :: ";
    scanf(" %[^\n]",player_2);
    system("cls");

    //for toss
    cout<<"Now who will play first?? So we will do a random toss here.\n\n\n";
    delay(1.5);
    var=toss(player_1,player_2);

    // hidden number generation part
    int range,the_num;

    the_num=hidden_number();
    //printf("%d\n",the_num); /// ####"the hidden number"####

    // range selection part
    if(the_num<=1000)
    {
        range=1000;
        cout<<"Your number is in the range of 1 to 1000. Can you guess it?\n\n";
    }
    else if(the_num>1000 && the_num<=2000)
    {
        range=2000;
        cout<<"Your number is in the range of 1 to 2000. Can you guess it?\n\n";
    }
    else if(the_num>2000)
    {
        range=5000;
        cout<<"Your number is in the range of 1 to 5000.Can you guess it?\n\n";
    }

    //displaying & beginning of the game
    delay(3.0);
    display(range);
    cout<<"\nPress any key to continue     ";
    getch();

    //game starts here
    if(var==0)  //toss winner is player 1
    {
        for(;;)
        {
            if(i%2==0)  //  player 1 's move
            {
                showTimer_for_p1(player_1,player_2);

                if(flag==0) continue;

                cin>>input;
                if(input==the_num)
                {
                    printf("Congratulations and well Done, %s. You are the winner\n\n\n",player_1);
                    getch();
                    a[0]++;
                    a[4]++;
                    break;
                }
                else
                {
                    omit(the_num,input,range);
                    display(range);
                    delay(3.0);
                }
            }
            else    //  player 2 's move
            {
                showTimer_for_p2(player_1,player_2);

                if(flag==0) continue;

                cin>>input;
                if(input==the_num)
                {
                    printf("Congratulations and well Done, %s. You are the winner\n\n\n",player_2);
                    getch();
                    a[3]++;
                    a[1]++;
                    break;
                }
                else
                {
                    omit(the_num,input,range);
                    display(range);
                    delay(3.0);
                }
            }
        }
    }
    else    //toss winner is player 2
    {
        for(;;)
        {
            if(i%2==0)  //  player 2 's move
            {
                showTimer_for_p2(player_1,player_2);

                if(flag==0) continue;

                cin>>input;
                if(input==the_num)
                {
                    printf("Congratulations and well Done, %s. You are the winner\n\n\n",player_2);
                    a[3]++;
                    a[1]++;
                    getch();
                    break;
                }
                else
                {
                    omit(the_num,input,range);
                    display(range);
                    delay(3.0);
                }
            }
            else    //  player 1 's move
            {
                showTimer_for_p1(player_1,player_2);

                if(flag==0) continue;

                cin>>input;
                if(input==the_num)
                {
                    printf("Congratulations and well Done, %s. You are the winner\n\n\n",player_1);
                    a[0]++;
                    a[4]++;
                    getch();
                    break;

                }
                else
                {
                    omit(the_num,input,range);
                    display(range);
                    delay(3.0);
                }
            }

        }
    }
    save_stats();
}
///2P game ends


//user defined functions for 2P game(starts)
void display(int range)
{
    for(int i=0; i<range; i++)
    {
        if(show[i]==0)
        {
            printf("%d ",i+1);
            if((i+1)%25==0)
                printf("\n");
        }
        else
        {
            printf("X ");
            if((i+1)%25==0)
                printf("\n");
        }

    }
    printf("\n");
}
void omit(int the_num,int input,int range)
{
    if(input<the_num)
    {
        for(int i=0; i<input; i++)
        {
            show[i]=1;
        }
    }
    else if(input>the_num)
    {
        for(int i=input-1; i<range; i++)
        {
            show[i]=1;
        }
    }
}
int hidden_divisor()
{
    int hidden_divisor;
    srand(time(NULL));
    hidden_divisor=rand()%3;
    if(hidden_divisor==0)
        return 1000;
    else if(hidden_divisor==1)
        return 2000;
    else
        return 5000;
}
int hidden_number()
{
    int get=hidden_divisor();
    srand(time(NULL));
    int hidden_number=rand()%get;
    return hidden_number;
}
void delay(double sec)
{
    clock_t start,current;
    start = clock();
    current = clock();
    while((double)(current-start)/CLOCKS_PER_SEC < sec)
        current = clock();
}
int toss(char *player_1,char *player_2)
{
    int var;
    srand(time(NULL));
    var = rand();
    var%=2;
    if(var==0)
    {
        cout<<"Player 1 won the toss. ";
        printf("\" %s \" will move first.\n\n",player_1);

    }
    else
    {
        cout<<"Player 2 won the toss. ";
        printf("\" %s \" will move first.\n\n",player_2);

    }
    return var;
}
void showTimer_for_p1(char *player_1,char *player_2)
{

    int total=0;
    int set_time=10;// can be changed later
    while(1)
    {
        printf("%s's guess ::",player_1);
        if(total%60<10)
            printf("\t\t\t\t\t\t%d:0%d\n\n",total/60,total%60);
        else
            printf("\t\t\t\t\t\t%d:%d\n\n",total/60,total%60);
        if(kbhit())
        {
            system("cls");
            printf("%s's guess ::",player_1);
            flag=1;
            i++;
            break;
        }
        delay(1.0);
        system("cls");
        total++;
        if(total==(double)set_time+1.0)
        {

            printf("Sorry !! Time's up. %s's turn now.\n\n",player_2);
            flag=0;
            delay(2.2);
            system("cls");
            i++;
            break;
        }
    }
}
void showTimer_for_p2(char *player_1,char *player_2)
{

    int total=0;
    int set_time=10;// can be changed later
    while(1)
    {
        printf("%s's guess ::",player_2);
        if(total%60<10)
            printf("\t\t\t\t\t\t%d:0%d\n\n",total/60,total%60);
        else
            printf("\t\t\t\t\t\t%d:%d\n\n",total/60,total%60);
        if(kbhit())
        {
            system("cls");
            printf("%s's guess ::",player_2);
            flag=1;
            i++;
            break;
        }
        delay(1.0);
        system("cls");
        total++;
        if(total==(double)set_time+1.0)
        {

            printf("Sorry !! Time's up. %s's turn now.\n\n",player_1);
            flag=0;
            delay(2.2);
            system("cls");
            i++;
            break;
        }
    }
}
//user defined functions for 2P game(ends)

