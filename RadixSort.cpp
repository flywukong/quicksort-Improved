//如何在O(n)时间内，对0到n^2-1之间的n个整数进行排序


//把整数转换为n进制再排序，每个数有两位，每位的取值范围是[0..n-1]，再进行基数排序



#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int length_A,n,radix,digit=2;

void Print(int *A, int len )
{
    for(int i =1; i <= len;i++)
    {
        if(i)cout<<' ';
        else cout<<"==> A = {";
        cout<<A[i];
    }
    cout<<"}"<<endl;
}

void Counting_Sort(int *A,int *B,int k)
{
    int i,j;

    int *C = new int[k+1];
    for(i = 0 ; i <= k;i++)
        C[i] = 0;
    for(i = 0 ; i <=k ; i++)
        C[i] = C[i] + C[i-1];
    for(i = 1; i <= length_A; j++)
        B[i] = 0;
    for( j = length_A; j >=1 ; j--)
    {
        B[C[A[j]]]= A[j];
        C[A[j]]--;
    }
    delete C;
}

void Stable_Sort(int *A,int *B,int k,int d)
{
    int i,j;
    
    int *C = new int[ k+1];
    for (i=0; i <= k; i++)
            C[i] = 0;
    int *D = new int[length_A+1];

    for(j=1; j<=length_A; j++)
    {
        D[j] = A[j] % (int)pow(10*1.0,d) / (int)pow(10*1.0,d-1);
        C[D[j]] ++;
    }
    for(i=1; i<=k; i++)
        C[i] = C[i] + C[i-1];
    for(i=1; i<= length_A; i++)
        B[i] = 0;
    for(j = length_A; j >= 1;j--)
    {
        B[C[D[j]]] = A[j];
        C[D[j]] --;
    }

    delete []C;
    delete []D;
}


void Radix_Sort(int *A,int *B)
{
    int i,j;
    for(i=1;i<=digit;i++)
    {
        Stable_Sort(A,B,9,i);
        for(j=1; j<=length_A; j++)
              A[j]=B[j];
    }
}

int main() 
{
        cin>>length_A>>digit;
        int *A = new int[length_A+1];
        int *B = new int[length_A+1];
        
        for(int i = 1;i <= length_A; i++)
        {
            A[i] = 0;
            while(A[i] < (int)pow(10.0,digit-1))
                A[i] = rand() % (int)pow(10.0,digit);
        }

        Print(A,length_A);
        
        Radix_Sort(A,B);
        Print(A,length_A);
        return 0;
}


            
        





