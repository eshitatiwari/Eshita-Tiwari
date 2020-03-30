#include<stdio.h>
struct children
{
	int uniqueid;
	int time;
	int timewaiting;
	int tat;
};
void taken(struct children list[],int a);
void schedule(struct children list[],int a);
void TAT(struct children list[],int b);
void output(struct children list[],int a);
void waittime(struct children list[],int b);

int main()
{
	struct children info[20];
	int no,i;
	char c='n';
	do
	{
		printf("Please enter how many students wants to eat:");
		scanf("%d",&no);
		taken(info,no);
	    schedule(info,no);
	    waittime(info,no);
	    TAT(info,no);
	    output(info,no);
	    printf(" press 'y' to continue");
	    scanf("%s",&c);
	}while(c=='y');
	return 0;
}
void taken(struct children list[80],int a)
{
	int x;
	for(x=0;x<a;x++)
	{
		printf("\n\nEnter all the data for the student number #%d", x+1);
		printf("\nEnter your registration number:");
		scanf("%d",&list[x].uniqueid);
		printf("Enter time taken for food in minutes :");
		scanf("%d",&list[x].time);
	}
}
void output(struct children list[80],int a)
{
	int i;
	int avgwt=0;
	int avgtat=0;
	int twt=0;
	int ttat=0;
	printf("\n\n\t\t         OUTPUT on basics of LRTF\n");
	    printf("\n\t\t\t|***************************************************************|");
    printf("\n\t\t\t|Student id\tFoodTakenTime\tWaitingTime\tTurnAroundTime  |");
    printf("\n\t\t\t|***************************************************************|");  
	for(i=0;i<a;i++)
	{
	printf("\n\t\t\t|%d\t\t%d\t\t%d\t\t%d\t\t|", list[i].uniqueid, list[i].time,list[i].timewaiting,list[i].tat);
	          printf("\a\n\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
	 twt=twt+list[i].timewaiting;
	 ttat=ttat+list[i].tat;
	  }  
	  printf("\n\n\t\t\tTotal Waiting Time is: = %d",twt);
	printf("\n\t\t\tTotal Turn around Time is: = %d\n\n",ttat);
	printf("\n\n\t\t\tAverage Waiting Time is: = %d",twt/a);
	printf("\n\t\t\tAverage Turn around Time is: = %d\n\n",ttat/a);	 
}
void schedule(struct children list[80],int a)
{
	int i,j;
	struct children t;
	for(i=0;i<a;i++)
	{
		for(j=0;j<(a-1-i);j++)
		{
			if(list[j].time<list[j+1].time)
			{
				 t = list[j];
                list[j] = list[j + 1];
                list[j + 1] = t;

			}
		else if(list[j].time==list[j+1].time)	
		{
			if(list[j].uniqueid>list[j+1].uniqueid)
			{
				t = list[j];
                list[j] = list[j + 1];
                list[j + 1] = t;

			}
		}
		}
	}
}
void waittime(struct children list[80],int b)
{
	int x,t;
	list[0].timewaiting=0;
	for(x=1;x<b;x++)
	{
		list[x].timewaiting=list[x-1].timewaiting+list[x-1].time;
	}
}
void TAT(struct children list[80], int b)
{
	int j,total;
    
    for(j=0;j<b;j++)
    {
        list[j].tat=list[j].timewaiting+list[j].time;
    }
}




