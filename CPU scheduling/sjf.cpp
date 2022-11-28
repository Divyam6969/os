#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Process
{
    float at;
    float bt;
    string name;
    float wt;
    float tat;
    float ct;

};

int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    struct Process arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i].name= "Process "+ to_string(i+1);
        cout<<"Enter the arrival time of process: "<<i+1<<endl;
        cin>>arr[i].at;
        cout<<"Enter the burst time of process: "<<i+1<<endl;
        cin>>arr[i].bt;
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


    //when arrival time is same shorter burst time comes first
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr[i].at==arr[j].at)
            {
                if(arr[i].bt>arr[j].bt)
                {
                    struct Process temp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp; 
                }
            }
        }
    }

    arr[0].wt = 0;
    arr[0].tat = arr[0].bt;
    arr[0].ct=arr[0].at+arr[0].bt;
    int counter = arr[0].at + arr[0].bt;
    
    for(int i=1;i<n;i++)
    {

        if(arr[i].at<counter)
        {
            for(int j=i;j<n;j++)
            {   
                if(arr[j].bt<arr[i].bt)
                {
                    struct Process temp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp; 
                }
            }
            arr[i].wt= counter-arr[i].at;
        }
        else
        {
            
            for(int j=i;j<n;j++)
            {   
                if(arr[j].bt<arr[i].bt)
                {
                    struct Process temp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp; 
                }
            }
            arr[i].wt=0;
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

    



    cout<<"Process\t\tArrival Time\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time\t\tCompletion Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].name<<"\t\t"<<arr[i].at<<"\t\t"<<arr[i].bt<<"\t\t\t"<<arr[i].wt<<"\t\t\t"<<arr[i].tat<<"\t\t"<<arr[i].ct<<endl;
    }


    float totalwaittime;
    float totalTAT;

    for(int i=0;i<n;i++)
    {
        totalwaittime=totalwaittime+arr[i].wt;
        totalTAT=totalTAT+arr[i].tat;
    }

    cout<<"Average waiting time is: ";
    cout<<(totalwaittime/n)<<endl;
    cout<<"Average turn-around time is: ";
    cout<<(totalTAT/n)<<endl;

    
    return 0;
}