#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	int n;
	cin >> n ;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int d[n];
	d[0]=a[0];
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		cout << d[i] << " ";
	}
}
