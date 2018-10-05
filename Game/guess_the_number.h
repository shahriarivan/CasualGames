#ifndef GUESS_THE_NUMBER_H_INCLUDED
#define GUESS_THE_NUMBER_H_INCLUDED

void show_hintsTimer(int the_num,int count,int range);

int showTimer(double sec,int count);

void even_odd(int the_num,int range);

void last_digit(int the_num,int range);

void is_prime(int the_num,int range);



void display(int range);

void omit(int the_num,int input,int range);

int hidden_divisor();

int hidden_number();

void delay(double sec);

void showTimer_for_p1(char *player_1,char *player_2);

void showTimer_for_p2(char *player_1,char *player_2);

int toss(char *player_1,char *player_2);

void GTN_1P();

void GTN_2P();

void GTN_Rules();

#endif // GUESS_THE_NUMBER_H_INCLUDED
