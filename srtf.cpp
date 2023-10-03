#include<bits/stdc++.h>
using namespace std;
class cmp{
    public:
    bool operator()(vector<int> i, vector<int> j){
        if(i[2]!=j[2]) return i[2]>j[2];
        return i[1]>j[1]; 
    }
};
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(6));

    cout<<"Enter Arrival Time:\n";
    for(int i=0;i<n;i++){
        v[i][0]=i;
        cin>>v[i][1];
    }

    cout<<"Enter Burst Time:\n";
    for(int i=0;i<n;i++){
        v[i][0]=i;
        cin>>v[i][2];
    }

    sort(v.begin(),v.end(),[](auto i, auto j){
        if(i[1]!=j[1]) return i[1]<j[1];
        return i[2]<j[2]; //acc to burst time if arrival is same
    });

    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    int time=v[0][1]-0;
    int index=0;
    pq.push(v[index++]);
    while(index<n || !pq.empty()){
        if(pq.empty()){
            time++;
            while(index<n && v[index][1]<=time){
                pq.push(v[index++]);
            }
        }
        else{
            auto top=pq.top();
            pq.pop();
            top[2]--;
            time++;
            // for(int i=0;i<6;i++){
            //     cout<<top[i]<<" ";
            // }
            // cout<<"time:"<<time<<endl;
            while(index<n && v[index][1]<=time){
                pq.push(v[index++]);
            }
            if(top[2]==0){
                int pid=top[0];
                for(int i=0;i<n;i++){
                    if(v[i][0]==pid){
                        v[i][3]=time;
                        break;
                    }
                }
            }
            else{
                pq.push(top);
            }
        }
    }

    float ac=0, at=0, aw=0;
    for(int i=0;i<n;i++){
        v[i][4]=v[i][3]-v[i][1];
        v[i][5]=v[i][4]-v[i][2];
        ac+=v[i][3];
        at+=v[i][4];
        aw+=v[i][5];
    }
    ac=ac/n;
    at=at/n;
    aw=aw/n;

    cout<<"PID\tA.T.\tB.T.\tC.T.\tT.A.T.\tW.T. \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cout<<v[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Avg Completion Time: "<<fixed<<setprecision(2)<<ac<<endl;
    cout<<"Avg Turn Around Time: "<<fixed<<setprecision(2)<<at<<endl;
    cout<<"Avg Waiting Time: "<<fixed<<setprecision(2)<<aw<<endl;
}