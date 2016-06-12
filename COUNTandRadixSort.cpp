//如何在O(n)时间内，对0到n^2-1之间的n个整数进行排序


//把整数转换为n进制再排序，每个数有两位，每位的取值范围是[0..n-1]，再进行基数排序



#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int length_A,n,radix,digit=2;

void Print(int *A, int len )
{
    for(int i =1; i < len;i++)
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
        D[j] = A[j] % (int)pow(radix*1.0,d) / (int)pow(radix*1.0,d-1);
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
        Stable_Sort(A,B,radix-1,i);
        for(j=1; j<=length_A; j++)
              A[j]=B[j];
    }
}

int main() 
{
        cin >> n;
        length_A = n;
        int *A = new int[n+2];
        int *B = new int[n+1];
            
        bool flag[1000] = {0};
        int i;
        for(i=1; i<=n; i++)
        {
            do
            {
                A[i] = rand() % (n*n);
            }while(flag[A[i]]);
            flag[A[i]] = 1;
        }
        Print(A,n);
        radix = n;
        Radix_Sort(A,B);
        Print(A,n);
        return 0;
}


            
        





