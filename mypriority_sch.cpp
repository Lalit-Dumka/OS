//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//======  ======//
//====== Time Complexity : O() =====//
//===== Space Complexity : O() =====//

#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int bt;
    int priority;
};

bool cmp(process A, process B){
    return A.priority>B.priority;
}

void find_wt(vector<process> &processes, vector<int> &wt){
    wt[0]=0;
    for(int i=0; i<processes.size();i++){
        wt[i]=wt[i-1]+processes[i-1].bt;
    }
}

void find_tat(vector<process> &processes,vector<int> &wt, vector<int> &tat){
    for(int i=0; i<processes.size(); i++){
        tat[i] = wt[i]+processes[i].bt;
    }
}

void find_avg_time(vector<process> &processes){
    int n = processes.size();

    vector<int> wt(n,0);
    vector<int> tat(n,0);

    int total_wt = 0, total_tat = 0;

    find_wt(processes,wt);
    find_tat(processes,wt,tat);

    for(int i=0; i<n; i++){
        total_wt += wt[i];
        total_tat += tat[i];

        cout<<i<<" "<<wt[i]<<" "<<tat[i]<<endl;

    }

    cout<<"Avg WT: "<<(float)total_wt/(float)n<<endl;
    cout<<"Avg Tat: "<<(float)total_tat/(float)n<<endl;
    
}

void priority_scheduling(vector<process> &processes){
    sort(processes.begin(), processes.end(), cmp);
    for(int i=0; processes.size(); i++){
        cout<<processes[i].pid<<" ";
    }
    find_avg_time(processes);

}




int main(){
    
    
    
    return 0;
}