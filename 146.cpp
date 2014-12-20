#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include<string>

using namespace std;
int main () {
string s;
while(true)
{
cin>>s;
if(s.compare("#") == 0)
    break;
bool b = next_permutation(s.begin(), s.end());
if(b)
    cout<< s << endl;
else
    cout<<"No Successor"<< endl;    

}

  return 0;
}
