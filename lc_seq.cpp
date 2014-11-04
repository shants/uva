#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
string s1, s2;
int tbl[1001][1001];
while(getline(cin,s1))
{
getline(cin,s2);
string s11 = " " + s1;
string s22 = " " + s2;
memset(tbl, 0, 1001*1001);
for(int i=1; i <(unsigned int)s11.length(); ++i)
{
    for(int j=1; j<(unsigned int)s22.length();++j)
    {
	if(s11[i] == s22[j]) 
	{
	    tbl[i][j] = 1+tbl[i-1][j-1];
	}
	else
	{
	    tbl[i][j] = max(tbl[i-1][j], tbl[i][j-1]);
	}
    }
}
cout<<tbl[s11.length()-1][s22.length()-1] << endl;
s1="";s2="";
}

return 0;
}
