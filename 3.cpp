#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
long long pre[1001][1001];
int main(){
    int n,m;
    cin >> n >> m ;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin >> a[i][j];
		}
	}
    int q; cin >> q; 
    pre[1][1]=a[1][1];
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
        }
    }
    while(q--){
        int x1,x2,y1,y2;
        cin >> x1 >> x2 >> y1 >> y2 ; 
        long long ans ; 
        ans = pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1];
        cout << ans << endl;
    }
}
