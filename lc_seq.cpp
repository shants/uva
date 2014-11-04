#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main()
{
string s1, s2;
int tbl[1000][1000];
while((cin>> s1 >> s2))
{
string s11 = " " + s1;
string s22 = " " + s2;
memset(tbl, 0, 1000*1000);
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
//cout << s1 << "\t "<<s2<<endl;
cout << "\n ans is " << tbl[s11.length()-1][s22.length()-1] << endl;
}

return 0;
}
