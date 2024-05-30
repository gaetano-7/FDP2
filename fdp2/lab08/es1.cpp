#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    map<int, pair<bool,int>> is_in;
    vector<int> xs(n);
    for(int i=0;i<n;i++){
        cin>>xs[i];
        is_in[xs[i]].first=true;
        is_in[xs[i]].second=i;
    }

    for(int i=0;i<n;i++){
        int target=m-xs[i];
        if(is_in[target].first and is_in[target].second != i){
            cout<<xs[i]<<" + "<<xs[is_in[target].second]<<" = "<<m<<endl;
        }
    }
    return 0;
}