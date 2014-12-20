#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct item {
int index;
string s;
int measure;
};

bool sortFunc(item i1, item i2)
{
    if (i1.measure < i2.measure)
	return true;
    else
	return false;
}

int func(string s) 
{
int count =0;
int l = s.length();
for(int i=0; i < l-1; ++i) {
    for(int j=i+1; j< l;++j) {
	if(s[i] > s[j])
	    count++;
    } 
}
return count;
}


int main()
{
int test=0;
int len, n;
cin >> test;
for(int i=0; i < test; ++i)
{
    cin>> len >> n;
    vector<item> vec(n);
    for(int j=0; j < n; ++j) {
	string s1;
	cin>>s1;
	vec[j].index = j;
	vec[j].s = s1;
	vec[j].measure = func(s1);
    }
    stable_sort(vec.begin(), vec.end(), sortFunc);
    for(int x=0; x<n; ++x)
	cout << vec[x].s << "\n";    
}

return 0;
}
