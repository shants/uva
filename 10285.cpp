#include<iostream>
#include<vector>
#include<algorithm>

// g++ -std=c++0x
using namespace std;
int tbl[10][5] = {{56, 14, 51, 58, 88},
		 {26, 94, 24, 39, 41},
		 {24, 16, 8, 51, 51},
		 {76, 72, 77, 43, 10},
		 {38, 50, 59, 84, 81},
		 {5, 23, 37, 71, 77},
		 {96, 10, 93, 53, 82},
		 {94, 15, 96, 69, 9},
		 {74, 0, 62, 38, 96},
		 {37, 54, 55, 82, 38}};


int _length = 0;
int N=5;
int R=0;
int C=0;

int travel(int r, int c) {
    int l1=0, l2=0,l3=0,l4=0;
    if(r>=R || c>=C || c<0 || r<0 ) {
	return 0;
    }else{
	if( (r-1>=0) && (tbl[r-1][c] < tbl[r][c]) )
	    l1 = travel(r-1,c);
	if( (c-1>=0) && (tbl[r][c-1] < tbl[r][c] )) 
	    l2 = travel(r,c-1);
	if((r+1<R) && (tbl[r+1][c] < tbl[r][c])) 
	    l3 = travel(r+1,c);
	if(((c+1<C)) && (tbl[r][c+1] < tbl[r][c])) 
	    l4 = travel(r,c+1);
    }
    return (1+max( {l1,l2,l3,l4}));
}


int main() {
R=10, C=5;
//cout<< "\n give row, column";
//cin>> r>>c;
for(int i=0;i<R;++i) {
    for(int j=0;j<C;++j) {
	int l =0;
	l = travel(i,j);
	if(l>_length) {
	    _length = l;
	}
    }
}

cout<<"\n ans is " <<_length <<"\n";
return 0;
}

