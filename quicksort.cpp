#include<iostream>

using namespace std;

void Print（int *A, int len)
{
    for(int i =0; i <len;i++)
    {
        if(i）cout<<' ';
        else cout<<"==> A = {";
        cout<<A[i];
    }
    cout<<"}"<<endl;
}

int Partiton(int *A,int p,int r)
{
    int x = A[r];
    int i = p-1,j;
    for(j=p; j < r ; j++)
    {
        if(A[j] <= x)
        {
            i++;
            swap(A[i],A[j];
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void Quicksort(int *A,int p,int r)
{
    if(p<r)
    {
        int q = Partiton(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
}

/********************随机快排********************************/
//划分
int Random_Partition(int *A,int p,int r)
{
    int i = rand() % (r-p+1) + p;
    swap(A[r],A[i]);
    return Partiton(A,p,r);
}

void Random_Quicksort(int *A,int p,int r)
{
     if(p<r)
     {
        int q = Random_Partition（A,p,r);
        Random_Quicksort(A,p,q-1);
        Random_Quicksort(A,q+1,r);
     }
}
