#include <iostream>
 
using namespace std;
 
int main(){
 
	int n; cin >> n;
	while(n--){
		long long int num = 0;
		bool flag = true;
		string s; cin >> s;
		while(!s.empty()){
			int temp = s.back()-'0';
			s.pop_back();
			if(!s.empty()){
				temp += (s.back()-'0') * 10;
				s.pop_back();
			}
			if(!s.empty()){
				temp += (s.back()-'0') * 100;
				s.pop_back();
			}
			num += (flag? +1: -1) * temp;
			flag = !flag;
		}
		cout << num << ' ';
		if(num < 0) num = -num;
		cout << (num % 13 == 0 ? "YES": "NO") << endl;
	}
 
	return 0;
}