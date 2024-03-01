#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q; 
	cin >> n >> q; 
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int d[n+10];
	d[0]=a[0];
	
	for(int i=1;i<n;i++){
		d[i]=a[i]-a[i-1];
		cout << d[i] << " ";
	}
	cout << endl;

	while(q--){
		int l,r,k;
		cin >> l >> r >> k ;
		d[l]+=k;
		d[r+1]-=k;	
	}
	
	long long pre[n+1];
	pre[0]=d[0];
	for(int i=1;i<n;i++){
		pre[i]=pre[i-1]+d[i];
	}
	for(int i=0;i<n;i++){
		cout << pre[i] << " ";
	}
}
