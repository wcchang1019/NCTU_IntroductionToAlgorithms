#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;
int LIS(vector<int> vec) // find the length of LIS,but the element is incorrect
{
    vector<int> ends;
    ends.push_back(vec[0]);
    for(int i=1;i<vec.size();i++){
        if(vec[i]<ends[0]){
            ends[0]=vec[i];
        }
        else if(vec[i]>ends[ends.size()-1]){
            ends.push_back(vec[i]);
        }
        else{
            int left=0,right=ends.size();
            while(left<right){
                int mid=(left+right)/2;
                if(ends[mid]<vec[i]){
                    left=mid+1;
                }
                else{
                    right=mid;
                }
            }
            ends[right]=vec[i];
        }
    }
    return ends.size();
}

vector<int> LIS2(vector<int> vec, int n) //find the element
{
    vector<int> tail(n, 0);
    vector<int> prev(n, -1);
    int len = 1;
    for (int i = 1; i < n; i++){
        if (vec[i] < vec[tail[0]]){
            tail[0] = i;
        }
        else if (vec[i] > vec[tail[len-1]]){
            prev[i] = tail[len-1];
            tail[len++] = i;
        }
        else{
            int left=-1,right=len-1;
            while(right-left>1){
                int mid=left+(right-left)/2;
                if(vec[tail[mid]]>=vec[i]){
                    right=mid;
                }
                else{
                    left=mid;
                }
            }
            int pos = right;
            prev[i] = tail[pos-1];
            tail[pos] = i;
        }
    }
    vector<int> ans;
    for (int i = tail[len-1]; i >= 0; i = prev[i]){
        ans.push_back(vec[i]);
    }
    return ans;
}

int main()
{
    int question,student;
    cin >> question >> student;
    map<int,int> questionmap;
    map<int,int> questionmap2;
    for(int i=0;i<question;i++){
        int tmp;
        cin >> tmp;
        questionmap[tmp]=i;
        questionmap2[i]=tmp;
    }
    for(int s=0;s<student;s++){
        vector<int> ans;
        for(int x=0;x<question;x++){
            int tmp;
            cin >> tmp;
            ans.push_back(questionmap[tmp]);
        }
        vector<int> finalans=LIS2(ans,question);
        for(int i=finalans.size()-1;i>=0;i--){
            cout << questionmap2[finalans[i]] << " " ;
        }
        cout << endl;
        ans.clear();
    }
    return 0;
}
