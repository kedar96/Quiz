#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include"quiz.h"
#include <sys/stat.h>

int main()
{
	//char buff[10000];
	//questionType q[50]; //to store questions
	int fEasy,fMed,fHard;
	int flag=0;
	int size;
	char ans;
	int i=0,j=0,k=0;
	int choice,r;
	do
	{
		//Print Introduction
		printf("\n----------------------------------------------------------------------------\n");
		printf("\n*****CHOOSE THE DIFFICULTY LEVEL*****\n");
		printf("\n1: ******EASY LEVEL******\n");
		printf("\n2: ******MEDIUM LEVEL******\n");
		printf("\n3: ******HARD LEVEL******\n");
		printf("\n6: Exit\n");
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		printf("\n-----------------------------------------------------------------------------\n");
		srand(time(NULL));
		switch(choice)
		{
			case 1: 
				quizType(choice);
				/*
				fEasy = open("easyQ.txt", O_RDONLY);
			    	if (fEasy < 0) 
    				{
        				perror("error");
        				exit(1);
				}
				
				r = rand() % 50;
				fMed = open("mediumQ.txt", O_WRONLY);
				
				size=read(fEasy, buff, sizeof(buff));
      				printf("the file's length is %d\n",size);
				for(i=0;i<size;i++)
				{
					char *quest=malloc(200 * sizeof(char));
					if(buff[i]=='*')
					{
						j=0;
						while(buff[i+1]!='%')
						{
							i++;
							quest[j]=buff[i];
							j++;
						//	printf("i:%d j:%d\n",i,j);
						}
						i++;
						while(flag!=1)
						{
							if(buff[i]=='=')
							{		
								i++;
								ans=buff[i];
								flag=1;
							}
							else
							{
								i++;
							}
						}
						flag=0;
						q[k].corrAns=ans;
						strcpy(q[k].fullQues,quest);
						free(quest);
						printf("%s",q[k].fullQues);
						printf("%c",q[k].corrAns);
						k++;
						printf("\n\n");
					}
					
				}
			//	write(fMed, buff, 10);
				close(fEasy);
				*/
				break;

			case 2: 
				quizType(choice);
				break;
				

			case 3:	
				quizType(choice); 
				break;

			case 4: 
				    break;
			case 5:
				    break;

			case 6: exit(-1);

			default:printf("\nInvalid Choice");
		}

	}while(1);

}





