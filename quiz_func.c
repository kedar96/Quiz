#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <malloc.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include"quiz.h"
#include <sys/stat.h>


void quizType(int qType)
{
	char buff[10000];
	questionType q[50]; //to store questions
	//int fEasy,fMed,fHard;
	int f1;	
	int flag=0;
	int size;
	char ans;
	int i=0,j=0,k=0;
	int choice,r;
	int total=0;
	if(qType==1)
	{
		f1= open("easyQ.txt", O_RDONLY);
	}
	else if(qType==2)
	{
		f1= open("mediumQ.txt", O_RDONLY);
	}
	else
	{
		f1= open("hardQ.txt", O_RDONLY);			
	}	
	if (f1 < 0) 
    	{
    		perror("error");
       		exit(1);
	}
	
	size=read(f1, buff, sizeof(buff));
    //  	printf("the file's length is %d\n",size);
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
		//	printf("%s",q[k].fullQues);
		//	printf("%c",q[k].corrAns);
			k++;
		//	printf("\n\n");
		}			
	}
	printf("\n\t******You can only answer using  the options a/b/c/d or A/B/C/D ******\n");
	printf("\n******Any other option choosen will be automatically marked as INCORRECT answer******\n");
	printf("\n\t******--->N0TE +4 for corect answer and -1 for incorrect******\n\n");
	for(int i=0;i<5;i++)
	{
		printf("%d)%s",i+1,q[i].fullQues);
		printf("enter your answer\n");
		getchar();		
		scanf("%c",&ans);
		ans=tolower(ans);
		if(ans==q[i].corrAns)
		{
			total=total+4;
			printf("\n******CORRECT ANSWER******\n\n");
		}
		else
		{
			total=total-1;
			printf("\n******INCORRECT, The right answer is '%c'******\n\n",q[i].corrAns);
		}
	}
	printf("\nYour final score is %d (out of 40)\n",total);
}
