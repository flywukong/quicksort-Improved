#include<iostream>
#include <cstdlib>
using namespace std;

/* 
 *  * (最大)堆的向下调整算法
 *   *
 *    * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *     *     其中，N为数组下标索引值，如数组中第1个数对应的N为0。
 * *参数说明：
 *    a-- 待排序的数组
 *    start --　被下调节点的起始节点
 *    end --　截至范围
 * 
 */

void  maxheap_down(int a[],int start,int end)
{
    int cur = start;
    int left = 2*cur + 1;
    int temp = a[cur ];
    for( ; left <= end ;cur=left,left = left*2+1)
    {
       if( left<end && a[left] < a[left+1])
              left++;

        if(temp >= a[left])
            break;

        else
        {
            a[cur] = a[left];
            a[left]= temp;
        }
    }
}

void heapSortAsc(int *a,int n)
{
    int i,tmp;
    //从(n/2-1)==>0 逐次遍历
    for( i =n/2-1; i>=0 ; i--)
        maxheap_down(a,i,n-1);
    
    //从最后一个元素开始对序列进行调整,不断缩小调整范围直到第一个元素
    for(i = n-1; i>0;i++)
    {
        swap(a[0],a[i]);
        maxheap_down(a,0,i-1);
    }
}

int main()
{
    int a[] ={20,30,90,40,70,110,60,10,100,50,80};
    int ilen = (sizeof(a))/(sizeof(a[0]));
     
    cout<<"before sort";
    for(int i=0; i <ilen; i++)
        cout<<a[i]<<" " ;

    cout<<endl;

    heapSortAsc(a,ilen);

    cout<<"after sort";
    for(int i=0; i<ilen; i++)
        cout<< a[i]<<" ";
    cout<<endl;

    return 0;
}


