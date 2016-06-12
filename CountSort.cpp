#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

void CountingSort(int *A,int *B,int *Order,int N,int K)
{
    int *C = new int[K+1];
    int i;
    memset(C,0,sizeof(int)*(K+1));
    for(i=1;i<=N;i++)
        C[A[i]]++;
    for(i=2;i<=K;i++)
        C[i] += C[i-1];
    for(i=N;i>=1;i--)
    {
        B[C[A[i]]] = A[i];
        Order[C[A[i]]] = i;
        C[A[i]]--;
    }
}

int main()
{
    int *A,*B,*Order,N=15,K=10,i;
    A = new int[N+1];
    B = new int[N+1];
    Order = new int[N+1];
    for(i=1;i<=N;i++)
        A[i] = rand()%K +1;
    printf("Befoer CS:\n");
    for(i=1;i<=N;i++)
        cout<<A[i]<<" ";
    CountingSort(A,B,Order,N,K);
    printf("\nAfter CS:\n");
    for(i=1;i<=N;i++)
        cout<<B[i]<<" ";
    cout<<endl<<"Order:"<<endl;
    for(i=1;i<=N;i++)
        cout<<Order[i]<<" ";
    return 0;
}
