#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include"quiz.h"
#include <sys/stat.h>
#include <signal.h>

int main()
{
	int fEasy,fMed,fHard;
	int flag=0;
	char name[30];
	int size;
	char ans;
	int i=0,j=0,k=0;
	int choice,r;
		//Print Introduction
		//system("cls");
	printf("\n************************************************************\n");
	printf("\nWelcome to the 'ADK ONLINE QUIZ'\n");		
	printf("\n************************************************************\n");
	printf("\nPlease enter your name\n");
	scanf("%s",name);		
	
		printf("\n************************************************************\n");
		printf("\nCHOOSE THE DIFFICULTY LEVEL\n");
		printf("\n************************************************************\n");
		printf("\n1: EASY LEVEL (10 Seconds)\n");
		printf("\n2: MEDIUM LEVEL (15 Seconds)\n");
		printf("\n3: HARD LEVEL (20 Seconds)\n");
		printf("\n4: Exit\n");
	do{		
		printf("\nEnter Your Choice:");
		choice=getvalidint();		
		printf("\n************************************************************\n");
		srand(time(NULL));
		switch(choice)
		{
			case 1: 
				quizType(choice);
				break;

			case 2: 
				quizType(choice);
				break;
		
			case 3:	
				quizType(choice); 
				break;

			case 4: exit(-1);

			default:printf("\nInvalid!!!");
		}

	}while(1);

}





