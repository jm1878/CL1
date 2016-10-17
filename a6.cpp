#include<bits/stdc++.h>
using namespace std;

struct Point
{
float x;
float y;
};
int dist(Point a,Point b)
{

return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
cout<<"enter the number of nodes";
int n;
cin>>n;
Point a[n];
cout<<"enter the  number of clusters ";

int c;
cin>>c;
Point clu[c];

for(int i=0;i<n;i++)
{
cout<<"enter coo-otnate of "<<i<<" th node \t "<<endl;
cin>>a[i].x;

cin>>a[i].y;

}


cout<<"*************************************"<<endl;
for(int i=0;i<c;i++)
{
cout<<"enter coo-otnate of "<<i<<" th cluster \t "<<endl;
cin>>clu[i].x;

cin>>clu[i].y;

}



int flag=0;
do{
flag=0;
int count3=0;
cout<<"Itertaioon "<<count3<<endl;
count3++;
 
Point tp;
tp.x=-1;
tp.y=-1;
Point c1[c][n];

for(int i=0;i<c;i++)
{for(int j=0;j<n;j++)
{
c1[i][j]=tp;
}

}

int cluster[n];
int cluster2[n];

int index;

int min;
for(int i=0;i<n;i++)
{

min=99999;

    for(int j=0;j<c;j++)
    {

    if(dist(a[i],clu[j])<min)
    {
    min=dist(a[i],clu[j]);
    index=j;
    cluster[i]=j;
    }



    }


c1[index][i]=a[i];
}


for(int i=0;i<c;i++)
{
cout<<"cluster no "<<i<<endl;
    for(int j=0;j<n;j++)
    {
        if(c1[i][j].x!=tp.x && c1[i][j].y!=tp.y)
        {
            cout<<c1[i][j].x<<"  "<<c1[i][j].y<<endl;

        }

    }


}

for(int i=0;i<c;i++)
{
int m=i;
float x1=clu[i].x;
float y1=clu[i].y;
clu[i].x=0;
clu[i].y=0;
int count=0;
    for(int j=0;j<n;j++)
    {
        if(c1[i][j].x!=tp.x && c1[i][j].y!=tp.y)

        {
            clu[i].x+=c1[i][j].x;
        
            clu[i].y+=c1[i][j].y;
            count++;
        }




 
    }

if(count>=1){
clu[m].x=clu[m].x/count;
clu[m].y=clu[m].y/count;}
else
{
clu[m].x=x1/1;
clu[m].y=y1/1;

}


}
cout<<"************************************************"<<endl;

//for(int i=0;i<c;i++)
//cout<<clu[i].x<<" "<<clu[i].y<<endl;

for(int i=0;i<n;i++)
{

min=99999;

    for(int j=0;j<c;j++)
    {

    if(dist(a[i],clu[j])<min)
    {
    min=dist(a[i],clu[j]);
//cout<<"min "<<a[i].x<<" "<<clu[j].x<<" "<<min<<endl;
    index=j;
    cluster2[i]=j;

    }



    }


}


for(int i=0;i<n;i++)
{
//cout<<cluster[i]<< "  "<<cluster2[i]<<endl;
if(cluster[i]!=cluster2[i])
    flag=1;




}


}while(flag);

return 0;
}
