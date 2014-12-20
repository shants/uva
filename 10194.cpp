#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
int testCases = 0;
cin >> testCases;
for(int tc=0; tc<testCases; ++tc)
{
string tName;
int teams;
cout << "\n tour name";
cin>> tName;
cout << "\n no of teams";
cin>> teams;
vector<string> tm;
string line;
for(int t=0; t<teams; ++t) {
    cin>>line;
    tm.push_back(line);
}

}
return 0;
}
