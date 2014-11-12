#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
while(1) 
{
    int test = 0;
    int n1, n2, temp;
    int tbl[101][101];    
    vector<int> v1, v2;
    cin >> n1 >> n2;

    if((n1 == 0) && (n2 == 0))
	break;
    else
    {
	test++;
	for(int i=0; i<101; ++i) {
	    for(int j=0; j<101; ++j) {
		tbl[i][j] = 0;
	    }
	}
	v1.push_back(0);
	v2.push_back(0);
	for(int i=0; i < n1; ++i){
	    cin>> temp;
	    v1.push_back(temp);
	}
	for(int i=0; i < n2; ++i){
	    cin>> temp;
	    v2.push_back(temp);
	}
	for(int i=1; i<=n1;++i) {
	    for(int j=1; j<=n2; ++j) {
		if(v1[i] == v2[j])
		    tbl[i][j] = 1+tbl[i-1][j-1];
		else
		    tbl[i][j] = max(tbl[i-1][j], tbl[i][j-1]);
	    }
	}
	cout << "Twin Towers #"<<test<<endl;
	cout << "Number of Tiles = "<<tbl[n1][n2]<<"\n\n";//endl;
	v1.clear();v2.clear();
    } 
}

return 0;
}

