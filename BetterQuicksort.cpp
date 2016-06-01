#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;

/*****************平均情况下线性时间的选择算法**********************/
int Randomizedpatition(int *arr ,int p,int r)
{
    srand((unsigned)time(0));
    int x,i,j,tmp;

    x = rand()%(r-p+1) + 1;
    swap (arr[x],arr[r]);

    int pivot = arr[r];
    i = p -1;
    for (j = p; j <= r-1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[j],arr[j]);
        }
    }
    swap(arr[r],arr[i+1]);
    return i+1;
}

int Randomizedselect(int *arr,int p,int r,int i)
{
    if (p==r)
        return arr[p];
    
    int q = Randomizedpatition(arr,p,r);

    int k = q-p+1;
    if(k < i)
        return Randomizedselect(arr,q+1,r,i-k);
    else if (k==i)
        return arr[q];
    else
        return Randomizedselect(arr,p,q-1,i);
}

void QuickSort(int *A,int p,int r)
{
    if( p>=r)
        return;
    int i = (r-p+1)/2;
    int x = Randomizedselect(A,p,r,i);
    
    QuickSort(A,p,p+i-2);
    QuickSort(A,p+i,r);
}

int main()
{
    int length_A,i;
    cin>>length_A;
    int *A = new int[length_A+1];
    for(i=1;i<=length_A;i++)
        a[i] = rand() % 100;
    for(i=1;i<=length_A;i++)
        cout<<A[i]<<' ';
    cout<<endl;

    QuickSort(A,1,length_A);
    for(i=1;i<=length_A;i++)
        cout<<A[i]<<' ';
    cout<<endl;
    delete []A;
    return 0;
}
