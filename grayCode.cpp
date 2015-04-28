#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
// kth grey code is k ^ (k>>1)
// the code below does the regular reflection
int arr[1024] = { 0 };

void reflect(int x) {
int k1 = pow(2, x);
int k2 = pow(2, x+1);
for(int i=0; i < (k1); ++i) {
arr[k2-i-1] = arr[i];
}
}

int main()
{
int n=0;
cout<< "\n give no of bits";
cin>>n;
arr[0] = 0;
arr[1] = 1;
int x=1;
while(x<n) {
reflect(x);
for(int j=0;j<pow(2,x);++j) {
arr[j] = arr[j];
}

for(int j=pow(2,x);j<pow(2,x+1);++j) {
arr[j] = arr[j] | (1<<(x));
}

++x;
}

for(int i=0; i < pow(2, n); ++i) {

cout<< "\n "<<i<<"th grey code " << arr[i];
}

return 0;
}
