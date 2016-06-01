
#include<iostream>
#include <stdlib.h>
using namespace std;

int t,length_A;
void Print(int *A,int len)
{
    for(int i = 0; i < len;i++)
        cout<<A[i]<<' ';
    cout<<endl;
}
    
/*******************最坏时间线性的选择*************/
int Select(int *A,int p,int r,int i);

template <class Type>
int  BubbleSort(Type *a,int p,int r,int k)
{
    bool exchange;
    for(int i=p;i<=r-1;i++)
    {
        exchange = false;
        for(int j = i+1;j<r;j++)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
                exchange = true;
            }
        }
        if(false == exchange)
        {
            break;
        }
    }
    return a[p+k];
}

void Insert(int *A,int start,int end)
{
    for(int i = start+1; i <= end; i++)
    {
        int j = i-1;

        int t = A[i];

        for (j=i-1 ; j>=start&&A[j]>t ;j--)
            A[j+1] = A[j];

        A[j+1] = t;
    }
}

int Find(int *A,int p ,int r)
{
    int i,j=0 ;
    int start,end, len = r-p+1;

    int *B = new int[len/5+10];
    //每5个元素一组，每组进行插入排序
    for( i = 1; i <= len;i++)
    {
        if( i%5 ==1)
            start = i+p-1;
        if( i%5 == 0 || i == len)
        {
            j++;
            end = i+p-1;
            B[j] = BubbleSort(A,start,end,2);
        } 
    }
    int ret = Select(B,1,j,(j+1)/2);

    return ret;
}

int partition(int *A,int p, int r)
{
     int x = A[r],i=p-1,j;
     
     for(int j = p; j < r ; j++)
     {
            if(A[j] <= x )
            {
                i++;
                swap(A[i],A[j]);
            }
     }
     swap (A[i+1],A[r]);
     return i+1;
}
int partition2(int *A,int p,int r,int f)
{
    int i;
    for(i=p; i<r; i++)
     //以这个中值为主元的划分，返回中值在整个数组A[1..len]的位置  
     ///因为主元是数组中的某个元素，划分好是这样的，A[p..q-1] <= f < A[q+1..r]
    {
        if(A[i]==f)
        {
            swap(A[i],A[r]);
            break;
        }
    }
       

}
int Select(int *A,int p ,int r,int i)
{
    if ( p == r)
        return A[p];
      //根据文中的算法，找到中值的中值 
    int f = Find(A,p,r);
     //以这个中值为主元的划分，返回中值在整个数组A[1..len]的位置  
     ///因为主元是数组中的某个元素，划分好是这样的，A[p..q-1] <= f < A[q+1..r]
    int pivot = partition2(A,p,r,f);
      //转换为中值在在数组A[p..r]中的位置
    int k = pivot-p +1;
       //与所寻找的元素相比较
    if(k == i)
        return A[pivot];
    else if( i<k )
        return Select(A,p,pivot-1,i);
    else
        return Select(A,pivot+1,r,i-pivot);
}

void quicksort(int *A,int p,int r)
{
    if(p >= r)
        return;
    else
    {
        int i = (r - p + 1)/2;
        //选择中位数作为划分元
        int mid = Select(A,p,r,i);
        cout<<" mid = "<<mid<<endl;

        int x =partition2(A,p,r,mid);

        quicksort(A,p,x-1);
        quicksort(A,x+1,r);
    }
}


int main()
{
    while(cin>>length_A)
    {
     
       
        int *A = new int[length_A];
        
        for(int i = 0;i < length_A; i++)
            A[i] = rand()%100;
        
        Print(A,length_A);

        quicksort(A,0,length_A-1);

        Print(A,length_A);

       
       
        delete []A;
    }
    return 0;
}
