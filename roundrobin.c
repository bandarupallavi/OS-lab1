#include<stdio.h>
int main(){
  int i,j,n,wt[20],tat[20],bu[20],max,ct[20],t;
  float wtavg=0;tatavg=0;temp=0;
	printf("\nEnter the number of processes-- ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the burst time for process %d-- ",i);
		scanf("%d",&bu[i]);
		ct[i]=bu[i];
	}
	printf("\nEnter timeslice -- ");
	scanf("%d",&t);
	max=bu[1];
	for(i=2;i<=n;i++)
	if(max<bu[i])
	max=bu[i];
	for(j=1;j<=(max/t)+1;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(bu[i]!=0)
			{
				if(bu[i]<=t)
				{
					tat[i]=temp+bu[i];
					temp=temp+bu[i];
					bu[i]=0;
				}
				else{
					bu[i]=bu[i]-t;
					temp+=t;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
	    wt[i]=tat[i]-ct[i];
     	wtavg+=wt[i];
	    tatavg+=tat[i];
	}
	printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
	for(i=1;i<=n;i++)
	{
		printf("\nP%d\t%d\t%d\t%d\n",i,ct[i],wt[i],tat[i]);
	}
	printf("\nAverage waiting time -- %f",wtavg/n);
    printf("\nAverage waiting time -- %f",tatavg/n);

}