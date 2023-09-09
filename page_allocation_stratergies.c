#include<stdio.h>
int i=0,j=0,k=0,i1=0,m,n,rs[30],flag=1;
int q[20],p[50],c=0,c1,d,f,r,t,b[20],c2[20];
    int pages[50], frame[10], hit = 0, count[50], time[50];
    int page,  maxTime, temp;
void fifo()
{


printf("FIFO page replacement algorithm....\\n");
printf("enter the no. of frames:");
scanf("%d",&n);
printf("enter the reference string:");
while(1)
{
scanf("%d",&rs[i]);
if(rs[i]==0)
break;
i++;
}
m=i;
for(j=0;j<n;j++)
p[j]=0;
for(i=0;i<m;i++)

{
flag=1;
for(j=0;j<n;j++)
if(p[j]==rs[i]) {
printf("data already in page....\n");
flag=0;
break; }
if(flag==1) {
p[i1]=rs[i];
i1++;
k++;
if(i1==n)
i1=0;
for(j=0;j<n;j++) {
printf("\n page %d:%d",j+1,p[j]);
if(p[j]==rs[i])
printf("*"); }
printf("\n\n");
}}
printf("total no page faults=%d",k); }

void lru()
{
printf("Enter no of pages:");
scanf("%d",&n);
printf("Enter the reference string:");
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("Enter no of frames:");
scanf("%d",&f);
q[k]=p[k];
printf("\n\t%d\n",q[k]);
c++;
k++;
for(i=1;i<n;i++)
{
c1=0;
for(j=0;j<f;j++)
{
if(p[i]!=q[j])
c1++;

}
if(c1==f)
{c++;
if(k<f)
{q[k]=p[i];
k++;
for(j=0;j<k;j++)
printf("\t%d",q[j]);
printf("\n");
}
else
{for(r=0;r<f;r++)
{c2[r]=0;
for(j=i
-1;j<n;j--
)
{if(q[r]!=p[j])
c2[r]++;
else
break; }}
for(r=0;r<f;r++)
b[r]=c2[r];
for(r=0;r<f;r++) {
for(j=r;j<f;j++) {
if(b[r]<b[j]) {
t=b[r];
b[r]=b[j];
b[j]=t; }}}
for(r=0;r<f;r++) {
if(c2[r]==b[0])
q[r]=p[i];
printf("\t%d",q[r]);
}
printf("\n");
}}}
printf("\nThe no of page faults is %d",c);
}



void optimal()
{
    
    int p;
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the number of pages: ");
    scanf("%d", &p);
    
    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
    }
    
    for(i = 0; i < 50; i++)
    {
        count[i] = 0;
    }
    
    printf("Enter page numbers: \n");
    for(i = 0; i < p; i++)
    {
        scanf("%d", &pages[i]);
    }
    
    printf("\n");
    
    for(i = 0; i < p; i++)
    {
        count[pages[i]]++;
        time[pages[i]] = i;
        flag = 1;
        
        if (i >= f)
        {
            for(j = 0; j < f; j++)
            {
                if (frame[j] == pages[i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        
        if (flag)
        {
            if (i < f)
            {
                frame[i] = pages[i];
            }
            else
            {
                maxTime = -1;
                for(j = 0; j < f; j++)
                {
                    if (time[frame[j]] > maxTime)
                    {
                        maxTime = time[frame[j]];
                        temp = j;
                    }
                }
                frame[temp] = pages[i];
            }
        }
        
        printf("Frame: ");
        for(j = 0; j < f; j++)
        {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }
    
    printf("Page hit = %d\n", hit);
    
    
}


int main()
{
	fifo();
	lru();
	optimal();
	return 0;
}
