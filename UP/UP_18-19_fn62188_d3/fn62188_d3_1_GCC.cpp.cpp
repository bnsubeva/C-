/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author  Bella Sabeva
* @idnumber 62188
* @task 1
* @compiler GCC
*
*/

#include <iostream>
#include <windows.h>
using namespace std;
void Space(int num){
    for(int i=0;i<num;i++)
        cout<<" ";
}
int strlen(char* str)
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}
int main() {
char arr1[50]="H   H   EEEEE   L       L          O   ";
char arr2[50]="H   H   E       L       L        O   O ";
char arr3[50]="HHHHH   EEEEE   L       L       O     O";
char arr4[50]="H   H   E       L       L        O   O ";
char arr5[50]="H   H   EEEEE   LLLLL   LLLLL      O   ";
int n=strlen(arr3);

 for(int z=0;z<=n;z++)
 {
     system("CLS");
     for(int i=0;i<=10;i++)
         {
            cout<<endl;

         }
 for(int i=z;i>=0;i--)
 {
     cout<<arr1[n-i];
 }
 cout<<endl;
  for(int i=z;i>=0;i--)
 {
     cout<<arr2[n-i];
 }
 cout<<endl;
  for(int i=z;i>=0;i--)
 {
     cout<<arr3[n-i];
 }
 cout<<endl;
  for(int i=z;i>=0;i--)
 {
     cout<<arr4[n-i];
 }
 cout<<endl;
  for(int i=z;i>=0;i--)
 {
     cout<<arr5[n-i];
 }
 Sleep(100);
 }


    {
    for(int j=0;j<80-n-1;j++){
        system("CLS");
        for(int i=0;i<=10;i++)
         {
            cout<<endl;

         }
        Space(j);
    cout<<"H   H   EEEEE   L       L          O"<<endl;
    Sleep(1);
    Space(j);
     cout<<"H   H   E       L       L        O   O"<<endl;
     Sleep(1);
     Space(j);
    cout<<"HHHHH   EEEEE   L       L       O     O"<<endl;
    Sleep(1);
    Space(j);
    cout<<"H   H   E       L       L        O   O"<<endl;
    Sleep(1);
    Space(j);
    cout<<"H   H   EEEEE   LLLLL   LLLLL      O"<<endl;
    Sleep(100);
    }
    }
int space=78-n;
for(int t=n;t>=0;t--)
 {
     system("CLS");
     for(int i=0;i<=10;i++)
         {
            cout<<endl;

         }
        Space(space);
 for(int i=0;i<=t;i++)
 {
     cout<<arr1[i];
 }
 cout<<endl;
  Space(space);
  for(int i=0;i<=t;i++)
 {
     cout<<arr2[i];
 }
 cout<<endl;
  Space(space);
  for(int i=0;i<=t;i++)
 {
     cout<<arr3[i];
 }
 cout<<endl;
  Space(space);
  for(int i=0;i<=t;i++)
 {
     cout<<arr4[i];
 }
 cout<<endl;
  Space(space);
  for(int i=0;i<=t;i++)
 {
     cout<<arr5[i];
 }
 Sleep(100);
 space++;
 }
system("CLS");
}



