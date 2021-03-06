#include<iostream>
#include<vector>


using namespace std;
//int arr[] = { 8,7,3 };//,9,5,1,10 };

struct segTreeNode {
int left;
int right;
int value;
segTreeNode(): left(0), right(0), value(0) {}
~segTreeNode() {}
};

void printSegTree(vector<segTreeNode>& tree, int sz) {
    for(int i=0; i < sz; ++i)
	cout << "\n Node " <<i << " Value " <<tree[i].value << " left " <<tree[i].left << " right " <<tree[i].right;

    cout<< "\n";
}

// build tree
void buildSegTree(vector<segTreeNode>& tree, int* arr, int node, int left, int right) 
{
    int sz = 17;
    if(left == right) {
	tree[node].left = left;
	tree[node].right = right;
	tree[node].value = left;
    }else {
	int lIdx = 2*node; int rIdx = 2*node+1;
	int mid =  (left + right)/2;
	buildSegTree(tree, arr, lIdx, left, mid);
	buildSegTree(tree, arr, rIdx, mid+1, right);
	int lIdxVal = tree[lIdx].value;int rIdxVal = tree[rIdx].value;
	
	tree[node].left = left;
	tree[node].right = right;
	if(arr[lIdxVal] <= arr[rIdxVal])
	    tree[node].value = lIdxVal;
	else 
	    tree[node].value= rIdxVal;
    }
}

// query
int query(vector<segTreeNode>& tree, int* arr, int node, int left, int right, int i, int j)
{

if(i>right || j < left) //left i  j  ||  right i j clearly not in line
    return -1;
if(left >= i && right <= j)   // i left  right  j  , subset of query
    return tree[node].value; 

int mid = (left + right)/2;
int p1 = query(tree, arr, 2*node, left, mid, i, j);
int p2 = query(tree, arr, 2*node+1, mid+1, right, i, j);
if(p1 == -1) return p2;
if(p2 == -1) return p1;

if(arr[p1] < arr[p2])
    return p1;
else
    return p2;

}

int getSegmentTreeSize(int N) 
{
int size = 1;
for (; size < N; size <<= 1);
return size << 1;
}
 
int main()
{

int arr[] = { 8,7,3,9,5,1,10 };
int sz = getSegmentTreeSize(sizeof(arr)/sizeof(int));
cout << "\n size of tree " << sz << endl;
vector<segTreeNode> tree(sz);
buildSegTree(tree,arr, 1,0, 6);
printSegTree(tree,sz);
cout << "\n ans to query  = " << query(tree, arr, 1, 0, 6, 2, 5) << "\n";
return 0;
}
