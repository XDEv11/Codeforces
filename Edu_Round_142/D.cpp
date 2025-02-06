//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

struct Node {
	array<Node*, 10> child{};
};

class Tree {
	Node* root;
	void insert(Node* ptr, const vector<int>& p, int idx) {
		if (idx == p.size()) return ;
		if (!ptr->child[p[idx]]) ptr->child[p[idx]] = new Node{};
		insert(ptr->child[p[idx]], p, idx + 1);
	}
	int find(Node* ptr, const vector<int>& p, int idx) {
		if (idx == p.size()) return 0;
		if (!ptr->child[p[idx]]) return 0;
		return find(ptr->child[p[idx]], p, idx + 1) + 1;
	}
	void reset(Node* ptr) {
		for (auto& c : ptr->child) {
			if (c) reset(c);
		}
		delete(ptr);
	}
public:
	Tree() {
		root = new Node{};
	}
	~Tree() {
		reset(root);
	}
	void insert(const vector<int>& p) {
		insert(root, p, 0);
	}
	int find(const vector<int>& p) {
		return find(root, p, 0);
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (auto& p : v)
		for (auto& x : p) cin >> x, --x;

	Tree t{};
	for (auto& p : v) {
		vector<int> opt(m);
		for (int i{0}; i < m; ++i) opt[p[i]] = i;
		t.insert(opt);
	}

	for (auto& p : v) {
		cout << t.find(p) << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
