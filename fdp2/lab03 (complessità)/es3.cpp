#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int *a =new int[n];
    
    for(int i = 0; i < n; ++i) {
        a[i] = 0;
    }
        
    int i = 0;
    bool done =false;
    
    while(not done) {
        for(int k = 0; k < n; ++k) {
            cout << a[i] << " ";
        }
        cout << endl;
        
        if(i >= n) {
            done =true;
        } else {
            if(a[i] < 4) {
                a[i]++;
            } else {
                i++;
            }
        }
    }
        
    delete a;
    return 0;
}