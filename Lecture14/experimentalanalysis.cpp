#include<iostream>
#include<ctime>
using namespace std;

void selectionSort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        swap(a[min],a[i]);
    }
}

void merge(int *a,int *x,int *y ,int s,int e)
{

    int i=s;
    int mid=(s+e)/2;

    int j=mid+1;
    int k=s;

    while(i<=mid && j<=e)
    {
        if(x[i]>y[j])
        {
            a[k]=y[j];
            k++;
            j++;
        }

        else
        {
            a[k]=x[i];
            i++;
            k++;
        }
    }
    
    while(i<=mid)
    {
        a[k]=x[i];
        k++;
        i++;
    }

    while(j<=e)
    {
        a[k]=y[j];
        k++;
        j++;    
    }
}

void mergesort(int *a,int s,int e)
{

    //base case
    if(s>=e)
    {
        return;
    }
    
    int mid=(s+e)/2;

    int x[10000],y[10000];

    for(int i=s;i<=mid;i++)
    {
        x[i]=a[i];
    }

    for(int i=mid+1;i<=e;i++)
    {
        y[i]=a[i];
    }

    //break
    mergesort(x,s,mid);
    mergesort(y,mid+1,e);

    merge(a,x,y,s,e);
}

int main()
{
    int a[10000];
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        a[i]=n-i;
    }

    clock_t t=clock();
    t=clock();
    mergesort(a,0,n-1);
    t=clock()-t;

    cout<<"time taken by mergesort: "<<t<<endl;

    


    for(int i=0;i<n;i++)
    {
        a[i]=n-i;
    }

    
    selectionSort(a,n);
    t=clock()-t;

    cout<<"time taken by selectionSort: "<<t<<endl;

    return 0;
}















