#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define root 1

class Heap {
	private:
		vector <int> data;

	public:
		Heap(); // constructor

		void insert(int val) {
			data.push_back(val);

			// refreshing our heap
			int v = data.size() - 1; 
			while (v > 1) {
				if (data[v / 2] > data[v])
					swap(data[v / 2], data[v]);
				v /= 2;
			}
		}

		int getMin() {
			int res = data[root]; // saving min value of the heap
			data[root] = data.back(); // exchanging last node with first node
			data.pop_back(); // deleting last node

			int v = root;
			int size = data.size();
			while (v < size) {
				int l = v * 2, r = v * 2 + 1;
				if (l < size) {
					if (r < size && data[l] > data[r])
						l = r;

					if (data[v] > data[l])
						swap(data[v], data[l]);
					v = l;
				} else 
					break;
			}
			return res;
		}

		void print() {
			for (int i = 0; i < data.size(); i++)
				cout << data[i] << " ";
			cout << endl;
		}
};

Heap::Heap(void) {
	data.push_back(-1);
}


int main() {

	freopen("a.in", "r", stdin);

	Heap h;

	int i, n, a[1000];

	cin >> n;

	for (i = 1; i <= n; i++) {
		cin >> a[i];
		h.insert(a[i]);
	}

	for (i = 1; i <= n; i++) {
		cout << h.getMin() << " ";
	}

	return 0;
}