#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int main()
{
int n;
vector<int> v(7490, 0);
vector<int> cents;
cents.push_back(50);
cents.push_back(25);
cents.push_back(10);
cents.push_back(5);
cents.push_back(1);
sort(cents.begin(), cents.end());
while(cin>>n)
{
    memset(&v[0], 0, 7490 * sizeof(int));
    v[0] = 1;

    for(int i=0; i<cents.size() ;++i)
    {
	int val = cents[i];
	for(int j=val; j<=n;++j) 
	{
		v[j] += v[j-val];
	}
    }
    cout << v[n]<<endl;
}

return 0;
}
