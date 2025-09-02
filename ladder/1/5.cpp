#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int y; cin >> y;
    
    int a,b,c,d;
    
    int x;
    if(y>=9876) x=10234;
    else{
        y+=1;
        a=(y/1000)%10;
        b=(y/100)%10;
        c=(y/10)%10;
        d=y%10;
        while(not(a!=b and a!=c and a!=d and b!=c and b!=d and c!=d)){
            d+=1;
            if(d==10){
                c+=1;
                d=0;
            }
            if(c==10){
                c=0;
                b+=1;
            }
            if(b==10){
                b=0;
                a+=1;
            }
        }
        x=d+10*c+100*b+1000*a;
    }
    cout << x;
}