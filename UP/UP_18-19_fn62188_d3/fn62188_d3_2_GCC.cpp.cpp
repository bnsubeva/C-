/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Bella Sabeva
* @idnumber <62188>
* @task <2>
* @compiler <GCC>
*
*/

#include<iostream>
using namespace std;
double* reverseMatrix(double Matrix[][3])
{
     double Matrix2[3][3];
     Matrix2[0][0]=Matrix[1][1]*Matrix[2][2]-Matrix[1][2]*Matrix[2][1];
     Matrix2[0][1]=-(Matrix[1][0]*Matrix[2][2]-Matrix[1][2]*Matrix[2][0]);
     Matrix2[0][2]=Matrix[1][0]*Matrix[2][1]-Matrix[1][1]*Matrix[2][0];

    Matrix2[1][0]=-(Matrix[0][1]*Matrix[2][2]-Matrix[0][2]*Matrix[2][1]);
    Matrix2[1][1]=Matrix[0][0]*Matrix[2][2]-Matrix[0][2]*Matrix[2][0];
    Matrix2[1][2]=-(Matrix[0][0]*Matrix[2][1]-Matrix[0][1]*Matrix[2][0]);

    Matrix2[2][0]=Matrix[0][1]*Matrix[1][2]-Matrix[0][2]*Matrix[1][1];
    Matrix2[2][1]=-(Matrix[0][0]*Matrix[1][2]-Matrix[0][2]*Matrix[1][0]);
    Matrix2[2][2]=Matrix[0][0]*Matrix[1][1]-Matrix[0][1]*Matrix[1][0];
    double detMatrix=0;
    for(int j=0;j<3;j++)
    {
        detMatrix=detMatrix+Matrix[0][j]*Matrix2[0][j];
    }
    if(detMatrix==0)
    {
         cout<<"Error";
    }

    double* reverseMatrix=new double[9];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            reverseMatrix[i*3+j]=Matrix2[j][i]/detMatrix;
        }
    }
     return reverseMatrix;

}
double* matrixEquation(double A[][3],double C[][3])
{
    double At[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            At[j][i]=A[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           At[i][j]=(-3)*At[i][j];
        }
    }
    double mult[3][3];
    for(int i = 0; i <3;i++)
	{
		for(int j = 0; j <3;j++)
		{
			mult[i][j] = 0;
		}
	}
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           for(int t=0;t<3;t++)
           {
           mult[i][j]+=At[i][t]*C[t][j];
           }
        }
    }
 /*5+A*/
 for(int i=0;i<3;i++)
 {
     A[i][i]=A[i][i]+5;
 }
double* X=new double[9];
double* reverseA=reverseMatrix(A);

for(int i = 0; i <3;i++)
	{
		for(int j = 0; j <3;j++)
		{
			 X[i*3+j] = 0;
		}
	}
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           for(int t=0;t<3;t++)
           {
            X[i*3+j]+=mult[i][t]*reverseA[t*3+j];
           }
        }
    }

return X;
}
int main()
{
    double A [3][3];
    double C[3][3];

    cout<<"A= ";
   for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>A[i][j];
            if(!cin)
            {
                return -1;
            }
        }
    }
cout<<"C= ";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>C[i][j];
            if(!cin)
            {
                return -1;
            }
        }
    }
     double* X=matrixEquation(A,C);

     cout<<"X= ";
     for(int i = 0; i <3;i++)
	{
		for(int j = 0; j <3;j++)
		{
			 cout<<X[i*3+j]<<" ";
		}
		cout<<endl;
		cout<<"   ";
	}
	delete []X;
    return 0;
}
