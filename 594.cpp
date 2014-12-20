#include<iostream>
#include<bitset>

using namespace std;

int main()
{
int n;
cin>>n;
int n1=0, n2=0, n3=0,n4=0;
n1 = n & 0x000000FF;
n2 = n & 0x0000FF00;
n3 = n & 0x00FF0000;
n4 = n & 0x7F000000;

int ans =0;
ans = (n1<<24) | (n2<<8) | (n3>>8) | (n4>>24);
cout << "\n ans is " << ans;
return 0;
}
