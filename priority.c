#include<stdio.h>
#include<conio.h>
int main(){
	int n,i,k,bt[20],wt[20],tat[20],temp,p[20],pri[20];
	float wtavg,tatavg;
	printf("\nEnter number of processes -- ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p[i]=i;
		printf("\nEnter the burst time and priority number for process %d -- ",i);
		scanf("%d %d",&bt[i],&pri[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(k=i+1;k<=n;k++)
		{
			if(pri[i]>pri[k])
			{
				temp=p[i];
				p[i]=p[k]; 
				p[k]=temp;
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				temp=pri[i];
				pri[i]=pri[k];
				pri[k]=temp;
			}
		}
	}
	wt[1]=wtavg=0;
	tat[1]=tatavg=bt[1];
	for(i=2;i<=n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		wtavg+=wt[i];
		tatavg+=tat[i];
	}
		printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
	for(i=1;i<=n;i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%d\n",p[i],pri[i],bt[i],wt[i],tat[i]);
	}
	printf("\nAverage waiting time -- %f",wtavg/n);
	printf("\nAverage turnaround time -- %f",tatavg/n);
}