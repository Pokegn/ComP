#include <bits/stdc++.h>

using namespace std;

int main(){

    int i;

    vector<int> tri(31);
    for (i=0; i<31; i++){
        if (i==0) tri[i] = 0;
        else tri[i] = tri[i-1]+i;
    }

    int t;
    cin >> t;

    for (i=0; i<t; i++){ 
        int n, k;

        cin >> n >> k;
        vector<int> a(n, 2);

        int j = 0;
        bool isBigger = false;
        while (not isBigger){
            if (k >= tri[j]) j+=1;
            else isBigger = true;
        }
        j-=1;

        int x = - 1 - 2*(j + tri[j] - k);
        
        for (int k=0; k<n; k++){
            if (k<n-j-1) a[k] = -1000;
            else if (k==n-j-1) a[k] = x;
        }

        for (int k=0; k<n; k++){
            cout << a[k] << ' ';
        }
        cout << endl;
    }
}
