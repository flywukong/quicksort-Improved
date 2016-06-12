//直接插入排序

#include<iostream>
using namespace std;

void insertsort(int *a,int n)
{
    int i,j,k;
    
    for(i=1 ; i<n ; i++)
    {
        for(j = i-1; j >=0;j--)
        
            if(a[j] < a[i])
                break;
        if(j != i-1)
        {
            int temp = a[i];
            for(k=i-1; k>j; k--)
                a[k+1] = a[k];
            a[k+1]=temp;
        }
    }
}

int main()
{
    int i;
    int a[] = {20,40,30,10,60,50};
    int ilen = (sizeof(a))/(sizeof(a[0]));

    cout<<"before sort";

    for(i=0;i<ilen;i++)
        cout<<a[i]<<endl;

    cout<<endl;

    cout<<"after sort";
    for(i=0; i <ilen;i++)
        cout<<a[i]<<endl;

    cout<<endl;

    return 0;
    
}

