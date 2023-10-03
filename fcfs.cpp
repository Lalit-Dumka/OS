#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> pro(n,vector<int>(6));
    cout<<"Enter Arrival Time:\n";
    for(int i=0;i<n;i++){
        pro[i][0]=i;
        cin>>pro[i][1];
    }
    cout<<"Enter Burst Time:\n";
    for(int i=0;i<n;i++){
        pro[i][0]=i;
        cin>>pro[i][2];
    }
    sort(pro.begin(),pro.end(),[](auto i, auto j){
        return i[1]<j[1];
    });

    int time=0;
    time = pro[0][3] = pro[0][2]-time + (pro[0][1]-time);
    for(int i=1;i<n;i++){
        if(pro[i][1]>time){
            time+=pro[i][1]-time;
        }
        time+=pro[i][2];
        pro[i][3]=time;
    }

    float ac=0, at=0, aw=0;
    for(int i=0;i<n;i++){
        pro[i][4]=pro[i][3]-pro[i][1];
        pro[i][5]=pro[i][4]-pro[i][2];
        ac+=pro[i][3];
        at+=pro[i][4];
        aw+=pro[i][5];
    }
    ac=ac/n;
    at=at/n;
    aw=aw/n;
    
    printf("PID\tA.T.\tB.T.\tC.T.\tT.A.T.\tW.T. \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cout<<pro[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Avg Completion Time: "<<fixed<<setprecision(2)<<ac<<endl;
    cout<<"Avg Turn Around Time: "<<fixed<<setprecision(2)<<at<<endl;
    cout<<"Avg Waiting Time: "<<fixed<<setprecision(2)<<aw<<endl;
}