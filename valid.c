/*
*Author		: Kedar
*Program	:To create a file which contains validation function.
*Date		:21/06/2017
*Modified Date	:21/06/2017
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define max 100

int getvalidint(){

int length,i,count;
short int flag=0;

char str[max];

//printf("Enter the String\n");
do{
scanf("%s",str);

length=strlen(str);

	if(str[0]== '+' || str[0]== '-' || isdigit(str[0]))
		flag=1;

		if(flag==1)
		{	
			for(i=1;i<length;i++)
			 {
				if(str[i]<= '0' || str[i]>= '9')
				 {
					flag=0;			
					break;
		     		 }
		         }
		}
	
		if (flag==1)
		{
			//printf("valid");
			return atoi(str);
		}//if

		else
		{
			printf("invalid integer, please enter again\n");			
		}


}while(1);





}//main

char getvalidres(){
char t;

do{
getchar();
scanf("%c",&t);
t=toupper(t);
//printf("%c",t);

if(t=='Y' || t=='N')
{
break;
}

else

printf("Invalid Response. Please Enter (Y/N) \n");

}while(1);//do


return t;
}

























