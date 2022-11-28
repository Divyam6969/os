//first come first serve without arrival time

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Process
{
    float bt;  //burst time
    float wt; //wait time
    float tat; //turn around time
    string name;
};

int main()
{
    cout<<"Enter the number of processes: ";
    int n;
    cin>>n;
    struct Process arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter burst time of process "<<i+1<<":"<<endl;
        cin>>arr[i].bt;
        arr[i].name= "Process" + to_string(i+1);
    }
    
    arr[0].wt=0;
    arr[0].tat=arr[0].bt;
    for(int i=1;i<n;i++)
    {
        arr[i].wt= arr[i-1].wt+arr[i-1].bt;
        arr[i].tat= arr[i].wt+arr[i].bt;
    }

    float totalwaittime;
    float totalTAT;

    for(int i=0;i<n;i++)
    {
        totalwaittime=totalwaittime+arr[i].wt;
        totalTAT=totalTAT+arr[i].tat;
    }

    
    cout<<"Process\tBurst Time\tWaiting Time\tTurn around time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"\t\t"<<arr[i].bt<<"\t\t"<<arr[i].wt<<"\t\t"<<arr[i].tat<<endl;

    }

    cout<<"Average waiting time is: ";
    cout<<(totalwaittime/n)<<endl;
    cout<<"Average turn-around time is: ";
    cout<<(totalTAT/n)<<endl;


    return 0;
}