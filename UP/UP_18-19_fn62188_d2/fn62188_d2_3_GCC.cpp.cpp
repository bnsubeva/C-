/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author <Bella Sabeva>
* @idnumber <62188>
* @task <3>
* @compiler < GCC>
*
*/

#include<iostream>
using namespace std;
bool isPalindrom(int arr[],int n)
{
    int count=0;
     for(int i=0;i<n/2;i++)
     {
         if(arr[i]!=arr[n-i-1])
            count++;
     }
     if(count==0)
        return true;
     else
        return false;


}
int countMDigits(int M)
{
    int count=0;
    while(M!=0)
    {
        M=M/10;
        count++;
    }
    return count;
}
void  countFunction(const int* arr,int M)
{
    if(arr==nullptr) return;
     for(int i=0;i<6;i++)
    {
         for(int j=0;j<6;j++)
         {
             if(arr[i*6+j]<0||arr[i*6+j]>9)
             {
                cout<<"Error!";
                return;
             }
         }
    }

    int arrM[6];
    /* ako M ima poveche ot 6 cifri nqma da se subira v reda ili kolonata */
    int n=countMDigits(M);
     for(int i=n-1;i>=0;i--)
     {
         arrM[i]=(M%10);
         M=M/10;
     }
     if(arrM==nullptr) return;

 int count=0;
for(int j=0;j<6;j++)
{
    for(int i=0;i<6;i++)
    {
        if (arr[i*6+j]==arrM[0])
        {
            if (n<=(6-i))
            {
                int currentI=i;
                int currentCount=0;
                 for(int t=0;t<n;t++)
                 {
                     if (arr[currentI*6+j]==arrM[t])
                     {
                     currentI++;
                      currentCount++;
                 }
                 if(currentCount==n)
                 {
                     count++;
                 }
            }
        }
    }
}
}


for(int j=0;j<6;j++)
{
    for(int i=0;i<6;i++)
    {
        if (arr[i*6+j]==arrM[n-1])
        {
            if (n<=(6-i))
            {
                int currentI=i;
                int currentCount=0;
                 for(int t=n-1;t>=0;t--)
                 {
                     if (arr[currentI*6+j]==arrM[t])
                     {
                     currentI++;
                      currentCount++;
                 }
                 if(currentCount==n)
                 {
                     count++;
                 }
            }
        }
    }
}
}

for(int i=0;i<6;i++)
{
    for(int j=0;j<6;j++)
    {
        if (arr[i*6+j]==arrM[0])
        {
            if (n<=(6-j))
            {
                int currentJ=j;
                int currentCount=0;
                 for(int t=0;t<n;t++)
                 {
                     if (arr[i*6+currentJ]==arrM[t])
                     {
                      currentJ++;
                      currentCount++;
                 }
                 if(currentCount==n)
                 {
                     count++;
                 }
            }
        }
    }
}
}

for(int i=0;i<6;i++)
{
    for(int j=0;j<6;j++)
    {
        if (arr[i*6+j]==arrM[n-1])
        {
            if (n<=(6-j))
            {
                int currentJ=j;
                int currentCount=0;
                 for(int t=n-1;t>=0;t--)
                 {
                     if (arr[i*6+currentJ]==arrM[t])
                     {
                      currentJ++;
                      currentCount++;
                 }
                 if(currentCount==n)
                 {
                     count++;
                 }
            }
        }
    }
}
}
if(isPalindrom(arrM,n)==1)
{
    count=count/2;
}
if(n==1)
{
    count=count/2;
}
//ako M e palindrom  broim 2 puti ednno sreshtane //
 cout<<count;
}

int main ()
{
    int arr[6][6];
    int M;
    cout<<" M= ";
    cin>>M;
    if(!cin)
    {
        return 1;
    }
    cout<<"Input array.."<<endl;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            cin>>arr[i][j];
            if(!cin)
            {
                return 1;
            }
        }
    }
     countFunction((int*)arr,M);


    return 0;
}
