#include<iostream>

using namespace std;

int main()
{

long testCase =0;
int val;
cin>>testCase;
while(testCase !=0)
{
    long arr[101] =  { 0 };
    for(long i=0; i < testCase; ++i)
    {
	cin>>val;
	arr[val]++;
    }
    cout<<"\n";
    // print
    for(int i=0; i<=101; ++i){
	if(arr[i] !=0 ) {
	    for(int j=0; j<arr[i]; ++j) {
		cout<< i << " ";
	    }
	}
    }

cin>> testCase;
}

return 0;
}
