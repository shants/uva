#include<iostream>
#include<string.h>

using namespace std;

int main()
{

int arr[256] = { 0 };
for(int j=0; j<256; ++j) 
    arr[j] = 0;

//memset(arr, 0, 256);
char ch;
cin>>ch;
//int i= ch;
arr[ch] = 1;

cout << ch << " " << arr[ch] << endl;
return 0;
}
