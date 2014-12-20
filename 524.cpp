#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int g_max  = 0;

void printV(vector<int>& v){
    for(int i=1;i<g_max;++i) {
	cout<<" " << v[i];
    }
cout<<"\n";
}

bool isPrime(int n) {
bool ans = true;
for(int i=2;i<(pow(n, .5)+1);++i) {
    if( (n%i)== 0) {
	ans = false;
	break;
    }
}
return ans;
}


bool checkValid(vector<int>& v) {
int ans = true;
    for(int i=1;i<=(g_max-1);++i) {
	if(i == g_max-1) {
	    if(!isPrime(v[i]+v[1])) 
		ans = false;
	}else {
	    if(!isPrime(v[i]+v[i+1])) 
		ans = false;
	}
    }
return ans;
}

void place(int i, vector<int>& v, vector<int>& used) {
if(i==g_max) {
    if(checkValid(v)) {
	printV(v);
	return;
    }else{
	return;
    }
}else{
for(int k=2;k<g_max;++k){
    if(used[k] != 1) { 
	v[i]=k;
	used[k] = 1;
	place(i+1,v, used);
	used[k]=0;
    }
	
}

}

}

int main()
{
int n;
cout << "\n give N";
cin>>n;
vector<int> v(n+1,0);
vector<int> used(n+1, 0);
g_max = n+1;
v[1]=1;
used[1]=1;
place(2,v,used);


return 0;
}
