#include<iostream>
#include<vector>

using namespace std;
int N = 0;
int E = 0;
int count=0;
vector<int> v;
vector<int> ans;
typedef vector<int> vi;

void place(int idx, int sum,vi& used) {
if(sum>N ){ 
    return;
} else {
    for(int k=0;k<E;++k) {
	if(used[k] != 1) {
	    used[k] = 1;
	    sum+=v[k];
	    place(idx+1, sum, used);
	    if(sum>count && sum<=N) {
		count=sum;
		ans = used;
	    }

	    used[k] = 0;
	    sum-=v[k];
	}
    }

}

}

int main() {
int n, e, no;
cout<< "\n Input Ni and no of elements";
cin>>n>>e;
N = n;
E=e;
for(int i=0;i<e;++i) {
cin>>no;
v.push_back(no);
}
vector<int> used(E, 0);
place(0,0,used);
cout <<"\n sum is " << count;
for(int i=0;i<e;++i) {
cout<<"\n "<< ans[i] << " ";
}
}
