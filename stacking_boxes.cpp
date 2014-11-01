#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>

using namespace std;
bool
greater_v(int i, int j, const vector< vector<int> >& v, int n)
{
bool ans = true;
for(int k1 = 0; k1 < n; ++k1)
{
    if(v[i][k1] < v[j][k1])
    {
	ans = false;
	break;
    }	
}
return ans;
}

int main()
{
ifstream myfile("test.txt");
string line;
vector<vector <int> > v;
int n1, n2;
while(getline(myfile, line))
{
cout << "\n read first line" << endl;
stringstream s(line);
s>>n1>>n2;
cout << "\n "<< n1 << n2;

for(int i=0; i<n1; ++i)
{
    vector<int> v1;
    getline(myfile, line);
    stringstream s1(line);
    for(int j=0;j<n2;++j) {
	int x;
	s1>>x;
	v1.push_back(x);
    }
    v.push_back(v1);
}

/*
for(int i=0; i < (int)v.size();++i)
{
cout << "\n V.size() " << v.size() << endl;
    for(int j=0; j<v[i].size();++j)
    {
	cout << "\n ** " << v[i][j];
    }

	cout << "\n +++ ";// << v[i][j];
}
*/

for(int i=0;i<n1;++i)
{
    sort(v[i].begin(), v[i].end());
}

sort(v.begin(), v.end());
/*
cout << "\n ************************************\n";
cout << " ************************************\n";
for(int i=0; i < (int)v.size();++i)
{
cout << "\n V.size() " << v.size() << endl;
    for(int j=0; j<v[i].size();++j)
    {
	cout << "\n ** " << v[i][j];
    }

	cout << "\n +++ ";// << v[i][j];
}
*/
vector<int> tbl(n1);
tbl[0] = 1;
for(int i=1;i< n1;++i)
{
    for(int j=0;j<i;++j)
    {
	if(greater_v(i,j,v, n2)){
	    tbl[i] = max(tbl[i],tbl[j]+1);
	}
    }
}

cout << "\n ans is " << *max_element(tbl.begin(), tbl.end());
//v.clear();
}
return 0;
}
