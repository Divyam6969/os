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
    float rt;
    float st;

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

        arr[i].rt = arr[i].bt;
    }
    int is_completed[100]={0};

    int current_time = 0;
    int completed = 0;
    int prev = 0;
    int total_idle_time = 0;
    int total_turnaround_time=0;
    int total_waiting_time=0;
    int total_response_time=0;

    while(completed!=n)
    {
        int idx = -1;
        int mn = 10000000;
        for(int i = 0; i < n; i++) {
            if(arr[i].at <= current_time && is_completed[i] == 0) {
                if(arr[i].rt < mn) {
                    mn = arr[i].rt;
                    idx = i;
                }
                if(arr[i].rt == mn) {
                    if(arr[i].at < arr[idx].at) {
                        mn = arr[i].bt;
                        idx = i;
                    }
                }
            }
        }
        if(idx != -1) {
            if(arr[idx].rt == arr[idx].bt) {
                arr[idx].st= current_time;
                total_idle_time += arr[idx].st - prev;
            }
            arr[idx].rt-= 1;
            current_time++;
            prev = current_time;
            
            if(arr[idx].rt == 0) {
                arr[idx].ct = current_time;
                arr[idx].tat = arr[idx].ct - arr[idx].at;
                arr[idx].wt = arr[idx].tat - arr[idx].bt;
                arr[idx].rt = arr[idx].st - arr[idx].at;

                total_turnaround_time += arr[idx].tat ;
                total_waiting_time += arr[idx].wt;
                total_response_time += arr[idx].rt;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else {
             current_time++;
        }  
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