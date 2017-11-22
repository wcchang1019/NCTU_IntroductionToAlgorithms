#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int ans[a+1];
    for(int i=1;i<=a;i++){
        cin >> ans[i];
    }
    for(int x=0;x<b;x++){
        int s[a+1][a+1];
        for(int i=0;i<=a;i++) s[i][0]=0;
        for(int i=0;i<=a;i++) s[0][i]=0;
        int input[a+1]={0};
        for(int y=1;y<=a;y++){
            cin >> input[y];
        }
        for(int p=1;p<=a;p++){
            for(int k=1;k<=a;k++){
                if(ans[p]==input[k]){
                    s[p][k]=s[p-1][k-1]+1;
                }
                else{
                    s[p][k]=max(s[p-1][k],s[p][k-1]);
                }
            }
        }
        cout << s[a][a] << endl;
    }
    return 0;
}
