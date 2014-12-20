#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void bfs(vector<vector<int> >& tbl, int nodes, vector<int>& comp, int start, int comp_no, vector<int>& visited)
{
queue<int> q;
q.push(start);
while(!q.empty()) {
int ele =  q.front();q.pop();
for(int i=0; i <nodes; ++i) {
    if( (tbl[ele][i] !=0) && (visited[i] == 0)) {
	q.push(i);
	visited[i] = 1;
	comp[i] = comp_no;
    }
}

}

}


int cc(vector<vector<int> >& tbl, int nodes)
{
vector<int> comp(nodes, 0);
vector<int> visited(nodes, 0);
int comp_no = 1;
for(int i=0; i < nodes; ++i) {
    if(comp[i] == 0) {
	bfs(tbl, nodes, comp, i, comp_no, visited);
	comp_no++;
    }
}
return *max_element(comp.begin(), comp.end());

}


void print(vector<vector<int> >& tbl, int maxNodes)
{

for(int i=0; i < maxNodes; ++i)
{
    cout<<"\n";
    for(int j=0; j<maxNodes; ++j) {
	cout<<tbl[i][j] << " ";
	tbl[i][i] = 1;
    }	
}

}
int main()
{
int testN = 0;
cin>>testN;
for(int testC =0; testC < testN; ++testC) 
{
char ch;
cin>>ch;
int maxNodes = ch - 'A' + 1;
cout << "\n maxNodes = " << maxNodes;
vector<vector<int> > tbl(maxNodes, vector<int>(maxNodes, 0));
print(tbl, maxNodes);
string s;
while(cin>>s) {
tbl[(s[0]-'A')][(s[1]-'A')] = 1;
}

print(tbl, maxNodes);
cout << "\n Ans is " <<cc(tbl, maxNodes);
}

return 0;
}
