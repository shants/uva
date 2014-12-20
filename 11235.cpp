#include<iostream>
#include<vector>

using namespace std;

void printSegTree(vector<int>& tree) 
{
for(int i=0; i <(int)(tree.size()); ++i)
    cout<<"\n "<<tree[i];
}

int getSegTreeSize(int n1) 
{
int n=1;
while(n < n1)
    n = n<<1;

return (n<<1);
}

void buildSegmentTree(vector<int>& tree, vector<int>& arr,int node, int left, int right) {
if(left == right) {
    tree[node] = left;
}else{
    int mid = (left+right)/2;
    buildSegmentTree(tree, arr, 2*node, left, mid);
    buildSegmentTree(tree, arr, 2*node+1,mid+1, right);
    int lIdx= node*2;int rIdx = node*2+1;
    int lVal = tree[lIdx]; int rVal = tree[rIdx];
    if(arr[lVal] > arr[rVal])
	tree[node] = lVal;
    else
	tree[node] = rVal;


}
return ;
}

int query(vector<int>& tree, vector<int>& arr, int node, int left, int right, int i, int j) {

if(right < i || left > j)
    return -1;
if(i >= left && j<= right)
    return tree[node];
int mid = (left + right)/2;
int p1 = query(tree, arr, 2*node,left, mid, i, j); 
int p2 = query(tree, arr, 2*node+1,mid+1,right, i, j); 

if (p1==-1) return p2;
if (p2 == -1) return p1;

if(arr[p1] > arr[p2])
    return p1;
else
    return p2;
}

int main()
{
int q, n, no;
cout<< "\n no of elements and query\n";
vector<int> vec;
cin>>n>>q;
for(int i=0;i<n;++i) {
cout<< "\n give number";
cin>>no;
vec.push_back(no);
}

int sz = getSegTreeSize(n);
cout << "\n size is " << sz << "\n";
vector<int> tree(sz);
buildSegmentTree(tree, vec,1,0,n-1);
printSegTree(tree);
int b,e;
for(int j=0;j<q;++j) {
cout << "\n Give left and right for query";
cin>>b>>e;
cout<<"\n For Query "<< b <<":" <<e<<" = "<<vec[tree[query(tree, vec,1, 0, n-1, b, e)]];
}
return 0;
}
