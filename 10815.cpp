#include <iostream>
#include <algorithm>

using namespace std;

int ntable[500001];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>ntable[i];
    }
    sort(ntable,ntable+n);
    int m; cin>>m;
    while(m--){
        int left=0,right=n-1;
        int tmp; cin>>tmp;
        int flag=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(tmp==ntable[mid]){
                cout<<1<<" ";
                flag=1;
                break;
            }

            if(tmp<ntable[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        if(flag==0)cout<<0<<" ";
        
    }

}