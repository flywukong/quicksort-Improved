#include<iostream>
#include<cstdlib>
using namespace std;

/**********************最坏情况线性时间的选择*******************/
////9.3-3使用最坏情况线性时间算法作为选择中值算法 
//
int Select(int *A,int p,int r,int i);
//对没一组从start到end插入排序

int Insert(int *A,int start,int end,int k)
{
    for(int i=1; i<=end; i++)
    {
        int t = A[i];
        int j = i -1;
        for(j = i-1; j >=start&&A[j] >t; j++)
            A[j+1] = A[j];
        A[j+1] = t;
    }
    return A[start+k-1];
}
//根据文中算法找到中位数的中位数x
int Find(int *A,int p,int r)
{
    int i,j = 0;
    int len = r -p +1;
    int *B = new int[(len/5)+1];
    int start,end;
    for(int i =1; i <=len;i++)
    {   
        if(i%5 == 1)
            start = p + i -1;
        if(i%5 ==0 || i == len)
        {
            end = p + i -1;
            B[j++] = Insert(A,start,end,(end-start)/2+1);
        }
    }
    int Mid = Select(B,i,j,(j+1)/2);
    return Mid;
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
    return partition(A,p,r);
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
    int length_A,i;
    cin>>length_A;
    int *A = new int[length_A+1];
    for(i=0;i<length_A;i++)
        A[i] = rand() % 100;
    for(i=0;i<length_A;i++)
        cout<<A[i]<<' ';
    cout<<endl;

    quicksort(A,0,length_A-1);
    for(i=0;i<=length_A-1;i++)
        cout<<A[i]<<' ';
    cout<<endl;
    delete []A;
    return 0;
}

