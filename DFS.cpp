#include <iostream>
#include <vector>
#define MAX_SIZE 510
using namespace std;
enum {
	BACK, DISCOVER, NOT
};
struct vertex {
	int num;
	int visit = 0;	
};
struct edge {
	vertex* src;
	vertex* dst;
	int state = NOT;
};
vertex* v[MAX_SIZE];
vector<edge*> e;
edge* matrix[MAX_SIZE][MAX_SIZE];
void insert_vertex(int num) {
	v[num] = new vertex({ num });
}
void insert_edge(int src, int dst) {
	if (v[src] == NULL || v[dst] == NULL) return;//this case assume no-graph 
	if (matrix[src][dst] != NULL || matrix[dst][src] != NULL)return;
	edge* tmp = new edge{ v[src],v[dst] };
	matrix[src][dst] = tmp;
	matrix[dst][src] = tmp;
	e.push_back(tmp);
}
void dfs(int start) {
	if (v[start] == NULL || v[start]->visit == 1) return;
	v[start]->visit = 1;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (matrix[start][i] != NULL) {//간선이 있는 경우
			if (matrix[start][i]->state == NOT) {//방문하지 않은 간선인 경우
				if (v[i]->visit == 1) {
					matrix[start][i]->state = BACK;
				}
				else {
					matrix[start][i]->state = DISCOVER;
					dfs(i);
				}
			}
		}
	}
}
void print() {
	for (int i = 0; i < e.size(); i++)
		if (e[i]->state == DISCOVER) cout << i << ' ';
	cout << '\n';
	for (int i = 0; i < e.size(); i++)
		if (e[i]->state == BACK) cout << i << ' ';
}
int main() {
	int n, m, k, s, d, start;
	char c;
	cin >> n >> m >> start;
	for (int i = 0; i < MAX_SIZE; i++) {
		v[i] = NULL;
		for (int j = 0; j < MAX_SIZE; j++) matrix[i][j] = NULL;
	}
	for (int i = 0; i < n; i++) {
		cin >> k;
		insert_vertex(k);
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> d;
		insert_edge(s, d);
	}
	dfs(start);
	print();
	return 0;
}