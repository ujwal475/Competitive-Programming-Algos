//Quick sort
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<chrono>
using namespace std;
using namespace std::chrono;
class quick{
int temp,low, high;
public:
    int part(int*,int,int);
    void qsort(int*,int,int);
};

void quick::qsort(int a[],int low,int high){
if(low<high){
    int j = part(a,low,high);
    qsort(a,low,j-1);
    qsort(a,j+1,high);
}
}

int quick::part(int a[],int low,int high)
{
	int i = low+1;
	int j = high;
	int key = a[low];
	while(1)
	{
	    while(i<high && a[i]<=key)
	        i++;
	    while(j>=low && a[j]>key)
	        j--;
	    if(i<j)
		{
	        temp = a[i];
	        a[i] = a[j];
	        a[j] = temp;
        }
	    else
		{
	        temp = a[low];
    	    a[low] = a[j];
   		    a[j] = temp;
	        return j;
	    }
	}
}
int main()
{
	int *a,n,i;
	quick q;
	cout<<"\n Enter the number of elements: ";
	cin>>n;
	a=new int[n];
	srand(time(0));
	cout<<"\n Enter the elements:\n";
	for(i=0;i<n;i++)
	{
	
	    a[i]=rand()%100;
		cout<<a[i]<<" ";
	}
	auto start=high_resolution_clock::now();
	q.qsort(a,0,n-1);
	auto end=high_resolution_clock::now();
	cout<<"\n Sorted elements are: \n";
	for(i=0;i<n;i++)
	    cout<<a[i]<<" ";
	cout<<"\n ANALYSIS: ";
	cout<<"\n Time taken: "<<duration_cast<nanoseconds>(end-start).count()<<"nanoseconds";
	cout<<"\n Space consumed: "<<sizeof(n)+(n*sizeof(a))+sizeof(i)+sizeof(q)<<" bytes"<<endl;
	return 0;
	getch();
}
