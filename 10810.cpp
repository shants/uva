#include<iostream>
#include<vector>

using namespace std;

int merge(vector<int>& vec, int l, int mid, int r)
{
    int cnt = 0;
    int i=l, j=mid+1;
    while(i <= mid) {
	j=mid+1;
	while(j<=r) {
	    if(vec[i] > vec[j]) {
		cnt++;
	    }
		j++;
	    }
	i++;
    }
    return cnt;
}

int calcInversion(vector<int>& vec, int l, int r)
{
    if(l >= r) 
	return 0;

    int mid = (l+r)/2;
    int ans1 = calcInversion(vec, l, mid);
    int ans2 = calcInversion(vec, mid+1, r);
    int ans3 = merge(vec, l, mid, r);
    return (ans1+ans2+ans3); 
   
}

int main()
{
int testLen = 0;
int val;

vector<int> vec;
cin>> testLen;

int i=0;
while(i<testLen)
{
cin>> val;
vec.push_back(val);
++i;
}

cout<< calcInversion(vec, 0, vec.size()-1) << "\n";
//vec.clear();

return 0;
}
