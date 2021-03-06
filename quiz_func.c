#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "quiz.h"
#include <signal.h>
#include <sys/stat.h>
#define buffSIZE 20000
#define ansSIZE 50

int breakflag = 1;


void handle();

void quizType(int qType)
{
	system("clear");
	int stdin_copy = dup(0);
	char buff[buffSIZE];
	questionType q[ansSIZE]; //to store questions

	int randomQuestionId[10];
	int f1, num = 0;
	int upper = 0;
	int flag = 0;
	int size;
	char ans;
	int i = 0, j = 0, k = 0;
	int choice, r;
	int total = 0;
	int AlarmTime=0;
	if (qType == 1)
	{
		f1 = open("easyQ.txt", O_RDONLY);
		AlarmTime = 10;
	}
	else if (qType == 2)
	{
		f1 = open("mediumQ.txt", O_RDONLY);
		AlarmTime = 15;
	}
	else
	{
		f1 = open("hardQ.txt", O_RDONLY);
		AlarmTime = 20;
	}
	if (f1 < 0)
	{

		perror("error");
		exit(1);
	}

	size = read(f1, buff, sizeof(buff));
	//printf("the file's length is %d\n", size);
	for (i = 0; i < size; i++)
	{
		char *quest = malloc(500 * sizeof(char));
		if (buff[i] == '*')
		{
			j = 0;
			while (buff[i + 1] != '%')
			{
				i++;
				quest[j] = buff[i];
				j++;
			}
			i++;
			while (flag != 1)
			{
				if (buff[i] == '=')
				{
					i++;
					ans = buff[i];
					flag = 1;
				}
				else
				{
					i++;
				}
			}
			flag = 0;
			q[k].corrAns = ans;
			strcpy(q[k].fullQues, quest);
			free(quest);
			k++;
		}
	}
	printf("\n***   Answer using a/b/c/d or A/B/C/D   ***\n");
	printf("\n*************************************************************************\n");
	printf("\n***   Any other option choosen will be directly marked as Incorrect   ***\n");
	printf("\n*************************************************************************\n");
	printf("\n***   >>N0TE: +4 for corect answer, -1 for incorrect   ***\n\n");
	printf("\n*************************************************************************\n");
	upper = k; //total questions

	num = rand() % upper;
	
	if (upper - num >= 10)
	{
		if (num == 0)
			num++;
	}
	else
	{
		num = num - 10;
	}

	for (int i = 0; i < 10; i++)
	{
		randomQuestionId[i] = num;
		num++;
	}

	for (int i = 0; i < 10; i++)
	{ // shuffle array
		int temp = randomQuestionId[i];
		int randomIndex = rand() % 10;

		randomQuestionId[i] = randomQuestionId[randomIndex];
		randomQuestionId[randomIndex] = temp;
	}

	signal(SIGALRM, handle);

	for (i = 0; i < 10; i++)
	{
		printf("%d)%s", i + 1, q[randomQuestionId[i]].fullQues);
		alarm(AlarmTime);
		printf("\nEnter your answer:");
		//getchar();
		scanf(" %c", &ans);
		alarm (0);
		
		dup2(stdin_copy, 0);
		ans = tolower(ans);

		if (!breakflag)
		{
			printf("\n\n Oops! Time up\n\n");
			breakflag = 1;
			continue;
		}

		if (ans == q[randomQuestionId[i]].corrAns)
		{
			total = total + 4;
			printf("\n++++   CORRECT ANSWER   ++++\n\n");
		}
		else
		{
			total = total - 1;
			printf("\n----   INCORRECT, The right answer is ' %c '   ----\n\n", q[randomQuestionId[i]].corrAns);
		}
	}
	printf("*************************************************************************\n");
	printf("\n<----    Your final score is %d (out of 40)    ---->\n", total);
	printf("\n*************************************************************************\n");
}

void handle()
{
	breakflag = 0;
	close(0);
}
