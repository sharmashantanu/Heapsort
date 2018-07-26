#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>

using namespace std;

class heap
{
 int *arr;
 int n;
 int h;
 public :
     heap();
     int log(int n);
     int exp(int n);
     void print();
     void printtree();
     void heapify(int m, int i);
     void heapsort();
};

void heap::printtree()
{

    for(int i=0;i<log(n);i++)
    {
        for(int j=0;j<exp(h-i);j++)
            cout<<" ";
        for(int j=exp(i)-1;j<=exp(i+1)-2;j++)
           {
             if(j<n)
                cout<<arr[j]<<" ";
             for(int j=0;j<exp(h-i+1);j++)
                cout<<" ";
           }
            cout<<"\n";
    }
    Sleep(3000);
}

int heap::exp(int n)
{
    if(n==0)
        return 1;
    else
        return (2*exp(n-1));
}

int heap::log(int n)
{
    int x=0;

    while(n>0)
    {
        n=n/2;
        x++;

    }
    return x;
}
heap::heap()
{
    int d;
    cout<<"\n\n 1. MANUAL"<<"\n\n 2. AUTOMATIC";
    cout<<"\n\n\nEnter your choice : ";
    cin>>d;
    cout<<"\n\nEnter number of elements : ";
    cin>>n;
    arr=new int[n];
    h=log(n);
    switch(d)
    {
    case 1:
        for(int i=0;i<n;i++)
            cin>>arr[i];
        break;
    case 2:
        srand(time(NULL));
        for(int i=0;i<n;i++)
            arr[i]=rand()%10;
    }
    system("cls");
    cout<<"\nTREE :\n";
    printtree();
}

void heap::heapify(int m,int i)
{
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<m && arr[l]>arr[large])
        large=l;
    if(r<m && arr[r]>arr[large])
        large=r;
    if(large!=i)
    {
        swap(arr[i],arr[large]);
        system("cls");
        cout<<"NEXT STEP :\n";
        printtree();
        heapify(m,large);
    }
}

void heap::heapsort()
{
    for(int i=n/2-1;i>=0;i--)
        heapify(n,i);
    for(int i=0;i<n;i++)
        cout<<arr[i];
    Sleep(15000);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        system("cls");
        cout<<"NEXT STEP :\n";
        printtree();
        heapify(i,0);
    }
}

void heap::print()
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
}


int main()
{
    heap h;
    h.heapsort();
    system("cls");
    cout<<"\nSORTED ARRAY IS : ";
    h.print();
    cout<<"\n\nSORTED TREE IS : \n\n\n";
    h.printtree();
    return 0;
}
