#include <iostream>
#include <string>
using namespace std;

string RE(string s,int L,int R)
{
    if((R-L)%2==1){
        return s;
    }
    int M = (R+L)/2;
    string s1=RE(s.substr(0,(R-L)/2),L,M);
    string s2=RE(s.substr((R-L)/2,(R-L)/2),M,R);
    if(s1>s2){
        return s2+s1;
    }
    else{
        return s1+s2;
    }
}
int main()
{
    int num;
    cin >> num;
    for(int i=0;i<num;i++){
        string input;
        string input2;
        cin >> input >> input2;
        string tmp=RE(input,0,input.size());
        string tmp2=RE(input2,0,input2.size());
        if(tmp==tmp2){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
