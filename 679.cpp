#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
typedef vector<int> vi;

int traverse(vi& arr, vi& flag) {
int i1 = 1, i2=arr.size();
int val;
while(i1<i2) {
    val = arr[i1];
    if(flag[i1] == 0) {
	flag[i1] = 1;
	i1=i1*2;
    }else{
	flag[i1] = 0;
	i1 = i1*2 +1;
    }
}

return val;
}

int main() {
int n,i;
cout<< "\n give N and i";
cin>>n>>i;
int sz = pow(2, n); 
vi arr(sz,0);
for(int ii=1;ii<sz;++ii) {
    arr[ii] = ii;
}
cout<<"\n";
for(int k=1;k< sz; ++k) 
    cout<<" " <<arr[k];

vi flag(sz,0);
for(int j=0;j<i;++j) {
    int k = traverse(arr, flag);
    cout<< "\n "<<k;
}
return 0;
}
