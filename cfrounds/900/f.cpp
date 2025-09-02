#include <bits/stdc++.h>

using namespace std;

long long int adddivisors(map a, long long int n, long long int oldtotal){
    long long total = oldtotal;
    long long int e;
    for(int i=2; (long long) i*i <= n; i++){
        if(n%i == 0){
            e=0;
            while(n%i==0){
                e++;
                n/=i;
            }

            if(map[i]==0){
                map[i]=e;
                total*=e+1;
            }
            else{
                total/=map[i]+1;
                map[i]+=e;
                total*=map[i]+1;
            }

        }
    }

    if(n>1){
        if(map[n]!=0){
            total/=map[n]+1;
        }
        map[n]++;
        total*=map[n]+1
    }

}

int main(){
    map<long long int, long long int> ndiv;
    

}