#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include"menu.h"
#include"hand_cricket.h"

using namespace std;

int a[18];

void reset_stats(void)
{
     FILE *fp;

    fp = fopen("Statistics.txt","w");
    int i;

    for(i=0;i<18;i++)
    {
        fprintf(fp,"0 ");
    }

    fclose(fp);
}

void save_stats(void)
{
     FILE *fp;

    fp = fopen("Statistics.txt","w");

    for(int i=0;i<18;i++)
    {
        fprintf(fp,"%d ",a[i]);
    }

    fclose(fp);
}


void get_stats(void)
{
    FILE *fp;

    fp = fopen("Statistics.txt","r");

    int i=0;

    while(fscanf(fp,"%d",&a[i])!=EOF)
    {
        i++;
    }

    fclose(fp);

}

void GTN_display_stats(void)
{
    system("cls");
    printf("\t\t\tGUESS THE NUMBER STATISTICS\n\n");
    printf("\nPlayer 1\n\n");
    printf("Times Won :  %d\n\n",a[0]);
    printf("Times Lost :  %d\n\n",a[1]);
    //printf("Times Drawn :  %d\n\n",a[2]);

    printf("\n\n");

    printf("\nPlayer 2\n\n");
    printf("Times Won :  %d\n\n",a[3]);
    printf("Times Lost :  %d\n\n",a[4]);
    //printf("Times Drawn :  %d\n\n",a[5]);

    getch();

}

void MP_display_stats(void)
{
    system("cls");
    printf("\t\t\tMARBLE PICK STATISTICS\n\n");
    printf("\nPlayer 1\n\n");
    printf("Times Won :  %d\n\n",a[6]);
    printf("Times Lost :  %d\n\n",a[7]);
    //printf("Times Drawn :  %d\n\n",a[8]);

    printf("\n\n");

    printf("\nPlayer 2\n\n");
    printf("Times Won :  %d\n\n",a[9]);
    printf("Times Lost :  %d\n\n",a[10]);
    //printf("Times Drawn :  %d\n\n",a[11]);

    getch();

}

void HC_display_stats()
{
    system("cls");
    printf("\t\t\tHAND CRICKET STATISTICS\n\n");
    printf("\nPlayer 1\n\n");
    printf("Times Won :  %d\n\n",a[12]);
    printf("Times Lost :  %d\n\n",a[13]);
    printf("Times Drawn :  %d\n\n",a[14]);

    printf("\n\n");

    printf("\nPlayer 2\n\n");
    printf("Times Won :  %d\n\n",a[15]);
    printf("Times Lost :  %d\n\n",a[16]);
    printf("Times Drawn :  %d\n\n",a[17]);

    getch();

}

