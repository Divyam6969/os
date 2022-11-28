//first come first serve with different arrival time

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Process
{
    float bt;  //burst time
    float wt; //wait time
    float tat; //turn around time
    float at; //arrival time
    float ct; //completion time
    string name;
};

int main()
{
    cout<<"Enter the number of processes: ";
    int n;
    cin>>n;
    struct Process arr[n];
    for(int i=0;i<n;i++)
    {   cout<<"Enter arrival time of process "<<i+1<<":"<<endl;
        cin>>arr[i].at;
        cout<<"Enter burst time of process "<<i+1<<":"<<endl;
        cin>>arr[i].bt;
        arr[i].name= "Process" + to_string(i+1);
    }


    for(int i=0;i<n;i++)
    {
        int min=arr[i].at;
        for(int j=i;j<n;j++)
        {
            if(arr[j].at<min)
            {
                struct Process temp = arr[j];
                arr[i]=arr[j];
                arr[j]=temp; 
            }
        }
    }

    arr[0].wt=0;
    arr[0].ct = arr[0].bt+arr[0].at;
    arr[0].tat=arr[0].bt;
    int counter = arr[0].at+arr[0].bt;
    
    for(int i=1;i<n;i++)
    {
        if(arr[i].at>counter)
        {
            arr[i].wt = 0;
        }
        else
        {
            arr[i].wt= counter-arr[i].at;
        }
        
        if(counter<arr[i].at)
        {
            counter = arr[i].at+arr[i].bt;
        }
        else
        {
            counter = arr[i-1].ct+arr[i].bt;
        }
        arr[i].ct = counter;
        arr[i].tat= arr[i].ct-arr[i].at;
        
    }

    float totalwaittime;
    float totalTAT;

    for(int i=0;i<n;i++)
    {
        totalwaittime=totalwaittime+arr[i].wt;
        totalTAT=totalTAT+arr[i].tat;
    }

    
    cout<<"Process\tArrival Time\tBurst Time\tWaiting Time\tTurn around time\tCompletion Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"\t\t"<<arr[i].at<<"\t\t"<<arr[i].bt<<"\t\t"<<arr[i].wt<<"\t\t"<<arr[i].tat<<"\t\t"<<arr[i].ct<<endl;

    }

    cout<<"Average waiting time is: ";
    cout<<(totalwaittime/n)<<endl;
    cout<<"Average turn-around time is: ";
    cout<<(totalTAT/n)<<endl;


    return 0;
}