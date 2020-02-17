#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct node {
	shared_ptr<const node> left, right;
	int val;
};

struct PST {
	const int null_val = 0;

	vector<shared_ptr<const node>> states;
	int size;

	int merge(int a, int b) {
		return a+b;
	}

	PST(const vector<int>& values) {
		states.push_back(create_tree(values, 0, values.size()));
		size= values.size();
	}

	shared_ptr<const node> create_tree(const vector<int>& values, int l, int r) {
		int mid = (l+r)/2;
		if (r == l + 1)
			return shared_ptr<const node>(new node{nullptr, nullptr, values[l]});
		auto left = create_tree(values, l, mid);
		auto right = create_tree(values, mid, r);
		return shared_ptr<const node>(new node{left, right, merge(left->val, right->val)});
	}

	int query(int l, int r, int s) {
		return query(l, r, 0, size, states[s]);
	}

	int query(int l, int r, int nl, int nr, shared_ptr<const node> n) {
		if(n == nullptr || r <= nl || l >= nr)
			return null_val;
		if(l <= nl && r >= nr)
			return n->val;
		int mid = (nl+nr)/2;
		return merge(query(l, r, nl, mid, n->left), query(l, r, mid, nr, n->right));
	}

	pair<int, int> search(int val, int nl, int nr, shared_ptr<const node> n){
		int mid = (nl+nr)/2;
		if(n->left != nullptr && n->left->val >= val){
			return search(val, nl, mid, n->left);
		} else if(n->right != nullptr){
			return search(val-n->left->val, mid,  nr, n->right);
		} else{
			return {nl, n->val};
		}
	}

	int update(int val, int i, int s) {
		auto pos = search(i, 0, size, states[s]);
		auto old = update(pos.second-1, pos.first, 0, size, states[s]);
		int nnew = query(val, val+1, 0, size, old);
		states.push_back(update(nnew+1, val, 0, size, old));
		if(states.back()->val != states[0]->val){
			cout <<" alla";
			exit(1);
		}
		return states.size() -1;
	}

	shared_ptr<const node> update(int val, int i, int nl, int nr, shared_ptr<const node> n) {
		if(nl == i && nr == i+1) {
			return shared_ptr<const node>(new node({n->left, n->right, val}));
		}
		int mid = (nl+nr)/2;
		if(i < mid) {
			auto nn = update(val, i, nl, mid, n->left);
			return shared_ptr<const node>(new node({nn, n->right, merge(nn->val, n->right->val)}));
		} else {
			auto nn = update(val, i, mid, nr, n->right);
			return shared_ptr<const node>(new node({n->left, nn, merge(n->left->val, nn->val)}));
		}
	}
};

int main() {
	int n; cin>>n;
	vector<int> vals(1e6);
	for(int i = 0; i < n; i++){
		int a;
		cin>>a;
		vals[a]++;
	}
	PST tree(vals);
	int q; cin>>q;
	int e = 0;
	int nu = 0;
	while(q--) {
		int a;
		cin>>a;
		if(a == 1) {
			int a, b, c;
			cin>>a>>b>>c;
			a = ((a - e) % (nu+1) + nu+1)% (nu+1) + 1;
			c = ((c - e) % int(1e6) + int(1e6)) % int(1e6-1) + 1;
			tree.update(c, b, a-1);
			nu++;
		} else {
			int a,b; cin>>a>>b;
			a = ((a - e) % (nu+1) + nu+1)% (nu+1) + 1;
			b = ((b - e) % int(1e6) + int(1e6)) % int(1e6-1) + 1;
			e = tree.query(0, b+1, a-1);
			cout<<e<<'\n';
		}
	}
}
