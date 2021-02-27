#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#pragma warn -rch
time_t start,end;
int arr[4][4]={
		{1,4,15,7},
		{8,10,2,11},
		{14,3,6,13},
		{12,9,5,0}
	      };
void display()
{
	int i,j;
	for(i=1;i<=8;i++)
	printf("\n");

	for(i=0;i<4;i++)
	{
		for(j=1;j<=3;j++)
		printf("\t");
		for(j=0;j<4;j++)
		if(arr[i][j]==0)
		printf(" \t");
		else
		printf("%d\t",arr[i][j]);
		printf("\n");
	}
}
int check()
{
int i,j,irr[4][4]={
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,0}
		  };
for(i=0;i<4;i++)
for(j=0;j<4;j++)
if(arr[i][j]!=irr[i][j])
{
return 0;
break;
}
time(&end);
return 1;
}
 int main()
{
	int row=3,col=3,t,ch;
	int d=0;
	printf("Important Instructions:\n1. Solve the puzzle in less than 2 minutes to win.\n2. Use arrow keys to arrange the given numbers in proper ascending order.");
	display();
	time(&start);
	while(!check())
	{
		ch=_getch();
		switch(ch)
		{
			case 80:if(row==0)
					 {
						printf("\a");
						break;
					 }
					 t=arr[row][col];
					 arr[row][col]=arr[row-1][col];
					 arr[row-1][col]=t;
					 row--;
					 system("cls");
					 display();
					 break;
			case 77:if(col==0)
					 {
						printf("\a");
						break;
					 }
					 t=arr[row][col];
					 arr[row][col]=arr[row][col-1];
					 arr[row][col-1]=t;
					 col--;
					 system("cls");
					 display();
					 break;
			case 72:if(row==3)
					 {
						printf("\a");
						break;
					 }
					 t=arr[row][col];
					 arr[row][col]=arr[row+1][col];
					 arr[row+1][col]=t;
					 row++;
					 system("cls");
					 display();
					 break;
			case 75:if(col==3)
					 {
						printf("\a");
						break;
					 }
					 t=arr[row][col];
					 arr[row][col]=arr[row][col+1];
					 arr[row][col+1]=t;
					 col++;
					 system("cls");
					 display();
					 break;
			case 28||1:exit(0);
		}
	}
	d=(int)difftime(end,start);
	if(d/60<=2)
	printf("\n\n\t\t\tCONGRATULATIONS! YOU WON.");
	else
	printf("\n\n\t\t\tSORRY! YOU LOST.");
	printf("\n\t\t\tELAPSED TIME: %d min %d sec",d/60,d%60);
	printf("\n\n\t\t\tPRESS ENTER KEY TO EXIT.");
	_getch();
	return 0;
}
