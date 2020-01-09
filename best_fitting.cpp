#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
#include<string.h>
struct memry
{
    int pid;
    int m;
    int tm;
}an[10];
int a[20][2],a1[20][3],a2[10],a3[10];
char a44[10][25];
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
clrscr();
cleardevice();
strcpy(a44[0],"Process Id =1");
strcpy(a44[1],"Process Id =2");
strcpy(a44[2],"Process Id =3");
strcpy(a44[3],"Process Id =4");
strcpy(a44[4],"Process Id =5");
strcpy(a44[5],"Process Id =6");
strcpy(a44[6],"Process Id =7");
strcpy(a44[7],"Process Id =8");
strcpy(a44[8],"Process Id =9");
strcpy(a44[9],"Process Id =10");
for(int i=0;i<10;i++)
    {
	an[i].pid=i+1;
cout<<"Enter the memory space reqd";
cin>>an[i].m;
cout<<"Enter the time reqd";
cin>>an[i].tm;
	a3[i]=0;
	a2[i]=0;    }
a[0][0]=0;
a[0][1]=1000;
int i1=1;
    int i2=0;
    int flag1=0;
    int krn=0;
    int min1=1000;
    int mik=200;
    do
{  clrscr();
	cleardevice();
	for(i=0;i<10;i++)//Memory allocation process
	{
	    min1=1000;
	    int fk=0;
	    if(a3[i]==0)
	    {
for(int k1=0;k1<i1;k1++)
		{
		    if((an[i].m<=(a[k1][1]-a[k1][0]))&&((a[k1][1]-a[k1][0])<=min1))
		    {
			min1=a[k1][1]-a[k1][0];
		      //	cout<<min1<<endl;
			a1[i2][0]=a[k1][0];
			a1[i2][1]=a1[i2][0]+an[i].m;
			a1[i2][2]=i;
			a[k1][0]=a1[i2][1];
		      // cout<<a[k1][0]<<endl;
			a3[i]=1;
			a2[i]=an[i].tm;
			fk=1;
		    }

		}
		if(fk==1)
		{
		 i2++;
		}
	    }
	}
/*for(int j=0;j<i2;j++)
	{
cout<<a1[j][0]<<" "<<a1[j][1]<<endl;
	}*/
//cout<<"Free Space"<<endl;
setcolor(WHITE);
rectangle(200,200,400,400);
for(int j1=0;j1<i2;j1++)
	{
for(int j111=a1[j1][0]+1;j111<a1[j1][1]-1;j111++)
{setcolor(GREEN);
line(200,(200+j111/5),400,(200+j111/5));  }
//cout<<a[j1][0]<<" "<<a[j1][1]<<endl;
setcolor(BLUE);
line(200,(200+a1[j1][0]/5),400,(200+a1[j1][0]/5));
line(200,(200+a1[j1][1]/5),400,(200+a1[j1][1]/5));
outtextxy(400,(200+(a1[j1][0]+a1[j1][1])/10),a44[(a1[j1][2])]);
	}
       //getch();
	int min=100;
	int fg=10;
	int fg1=10;
	for(i=0;i<10;i++)//Finding the process with lowest time
	{
	    if(a3[i]==1)
	    {
		if(a2[i]<min)
		{
fg=i;
		    fg1=i;
		    min=a2[i];
		}
	    }
	}
cout<<"Delay is"<<a2[fg];
	delay(a2[fg]*1000);
	int temp=a2[fg];
	a2[fg]=0;
	a3[fg]=2;
	for(i=0;i<10;i++)//Subtracting equivalent time from other processes active
	{
	    if(a3[i]==1)
	    {
		a2[i]=a2[i]-temp;
	    }
	}
for(int i7=0;i7<i2;i7++)//Deallocating memory
	{
	    if(a1[i7][2]==fg1)
	    {
	     a[i1][0]=a1[i7][0];
	     a[i1][1]=a1[i7][1];
	     i1++;
	     break;
	    }
	}
	int i10=0;
	int a4[20][3];
	for(i7=0;i7<i2;i7++)
	{
	    if(a1[i7][2]!=fg1)
	    {
		a4[i10][0]=a1[i7][0];
		a4[i10][1]=a1[i7][1];
		a4[i10][2]=a1[i7][2];
		i10++;
	    }
	}
	for(i7=0;i7<i10;i7++)
	{
	    a1[i7][0]=a4[i7][0];
	    a1[i7][1]=a4[i7][1];
	    a1[i7][2]=a4[i7][2];
	}
	i2=i10;
int dup[10];
int u=0;
int a5[20][2];
for(int ik=0;ik<i1;ik++)//Coalescing if possible
	{
	for(int ik1=ik+1;ik1<i1;ik1++)
	   {
	    if(a[ik][0]==a[ik1][1])
	    {
	     a[ik][0]=a[ik1][0];
	    }
	    if(a[ik][1]==a[ik1][0])
	    {
	     a[ik][1]=a[ik1][1];
	    }
	   }
	}
for(ik=0;ik<i1;ik++)//Coalescing if possible
	{
	for(int ik1=ik+1;ik1<i1;ik1++)
	   {
	    if(a[ik][0]==a[ik1][0])
	    {
	    a[ik1][0]=0;
	    a[ik1][1]=0;
	    }
	    if(a[ik][1]==a[ik1][1])
	    {
	    a[ik1][0]=0;
	    a[ik1][1]=0;
	    }

	   }
	}

/*	int u1=0;
for(int ig=0;ig<i1;ig++)
{    int fgg=0;
for(int kg=0;kg<u;kg++)
  {
   if(dup[kg]==ig)
fgg=1;
   }
   if(fgg==0)
   {
    a5[u1][0]=a[ig][0];
    a5[u1][1]=a[ig][1];
    u1++;
   }
  }
for(int kg=0;kg<u1;kg++)
  {
   a[kg][0]=a5[kg][0];
   a[kg][1]=a5[kg][i];
  }
  i1=u1;*/
krn+=1;
//cout<<"krn is "<<krn;
//getch();
}while(krn!=10);
}

