#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;



int main(){


	int tt;
	cin >> tt;
	while(tt--){
		int n, m; cin >> n >> m;
		int a[n];
		int non_lost = -1;
		for(int i = 0 ; i < n; i++){
			cin >> a[i];
			if(a[i] != -1){
				non_lost = i;
			}
		}

		for(int i = non_lost-1; i >= 0; i--)
			a[i] = (((a[i+1]-1) % m) + m) % m;

		for(int i = non_lost+1; i < n; i++)
			a[i] = (a[i-1]+1) % m;

		for(int i = 0; i < n; i++) cout << a[i] << ' ';
		cout << endl;


	}

	



	return 0;
}
