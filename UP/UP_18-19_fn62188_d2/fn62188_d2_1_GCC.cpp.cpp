/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author <Bella Sabeva>
* @idnumber <62188>
* @task <1>
* @compiler <GCC>
*
*/

#include<iostream>
#include<cmath>
using namespace std;
void changeArray(int arr[],int L,int M)
{
    int coppyArr[100];
    for(int i=0;i<L;i++)

    {
    coppyArr[i]=arr[i];
        }

    if(M>0)
    {
       for(int i=0;i<M;i++)
       {
           arr[i]=coppyArr[L-M+i];
       }
        for(int i=0;i<L-M;i++)
        {
            arr[i+M]=coppyArr[i];

        }
}
else if(M<0)
{
    M=abs(M);
    for(int i=0;i<M;i++)
       {
           arr[L-M+i]=coppyArr[i];
       }
     for(int i=0;i<L-M;i++)
        {
            arr[i]=coppyArr[i+M];

        }
}
}
int main ()
{
    int MAX_ELEMENTS=100;
    int arr[MAX_ELEMENTS];
    int Length;
    cout<<"Input Length!"<<endl;
    do
    {
    cin>>Length;
    }
    while(Length>100||Length<0);
    if(!cin)
    {
        return 1;
    }
    int M;
    cout<<"Input M!"<<endl;
    cin>>M;
     if(!cin)
    {
        return 1;
    }
    if(abs(M)>=Length)
    {
        cout<<"Error!";
        return 1;
    }
    cout<<"Input Array!"<<endl;
    for(int i=0;i<Length;i++)
    {
        cin>>arr[i];
        if(!cin)
        {
            return 1;
        }
    }
    changeArray(arr,Length,M);
    cout<<"New array is.."<<endl;
    for(int i=0;i<Length;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
