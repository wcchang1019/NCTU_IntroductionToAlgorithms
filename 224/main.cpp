#include<bits/stdc++.h>
using namespace std;
vector<int> station[1000003];
long long int origin[1000003],goal[1000003];
long long int ans[1000003]={0};
void DP(int n)
{
    int times=0;
    int index=1;
    while(times<n-1){
        if(station[index].size()==1){
            long long int cun=goal[index]-origin[index];
            ans[index]=max(ans[index],abs(cun));
            ans[station[index][0]]=max(ans[station[index][0]],abs(cun));
            origin[index]=goal[index];
            origin[station[index][0]]-=cun;
            for(int i=0;i<station[station[index][0]].size();i++){
                if(station[station[index][0]][i]==index){
                    station[station[index][0]][i]=station[station[index][0]][station[station[index][0]].size()-1];
                    station[station[index][0]][station[station[index][0]].size()-1]=index;
                    break;
                }
            }
            station[station[index][0]].pop_back();
            station[index].pop_back();
            times++;
        }else{
            index++;
        }
        if(index>n){
            index=1;
        }
    }
}
int main()
{
    int numbers;
    cin >> numbers;
    for(int i=1;i<=numbers;i++){
        scanf("%lld",&origin[i]);
    }
    for(int i=1;i<=numbers;i++){
        scanf("%lld",&goal[i]);
    }
    for(int i=0;i<numbers-1;i++){
        int tmp,tmp2;
        scanf("%d %d",&tmp,&tmp2);
        station[tmp].push_back(tmp2);
        station[tmp2].push_back(tmp);
    }
    DP(numbers);
    long long int maximum=0;
    for(int i=1;i<=numbers;i++){
        maximum=max(maximum,ans[i]);
    }
    cout << maximum << endl;
    return 0;
}
