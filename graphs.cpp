#include <iostream>
#include <queue>

using namespace std;

struct edgenode {
	edgenode *next;
	int wt;
	int y;
};

static const int MAX_V = 50;

struct graph {
	edgenode *edges[MAX_V + 1];
	int degree[MAX_V + 1];
	int nvertices;
	int nedges;
	bool directed;
};

void init_graph(graph *g, bool directed) {
	int i;
	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;
	for (i = 1; i <= MAX_V; i++) {
		g->degree[i] = 0;
		g->edges[i] = nullptr;
	}
}

void insert_edge(graph *g, int x, int y, bool d) {
	edgenode *p = new edgenode;
	p->wt = 0;
	p->y = y;
	p->next = g->edges[x];
	g->edges[x] = p;
	g->degree[x]++;
	if (!d) {
		insert_edge(g, y, x, true);
	} else {
		g->nedges++;
	}
}

void print_graph(graph *g) {
	int i;
	edgenode *p;
	for (i = 1; i <= g->nvertices; i++) {
		printf("%d:", i);
		p = g->edges[i];
		while (p != nullptr) {
			printf(" %d", p->y);
			p = p->next;
		}
		printf("\n");
	}
}

static bool processed[MAX_V + 1];
static bool discovered[MAX_V + 1];
static int parent[MAX_V + 1];
void init_search(graph *g) {
	for (int i = 0; i <= g->nvertices; i++) {
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}
void process_edge(int x, int y) {
	printf("processed edge (%d,%d)\n", x, y);
}
void bfs(graph *g, int start) {
	queue<int> q;
	int v;
	int y;
	edgenode *p;
	q.push(start);
	discovered[start] = true;
	while (q.size()) {
		v = q.front();
		q.pop();
		processed[v] = true;
		p = g->edges[v];
		while (p != nullptr) {
			y = p->y;
			if ((processed[y] == false) || g->directed) {
				process_edge(v, y);
			}
			if (discovered[y] == false) {
				q.push(y);
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;
		}
	}
}

void find_path(int start, int end, int parents[]) {
	if ((start == end) || (end == -1)) {
		printf("\n%d\n", start);
	} else {
		find_path(start, parents[end], parents);
		printf(" %d\n", end);
	}
}

int main() {
	graph *g = new graph;
	init_graph(g, false);
	g->nvertices = 5;
	insert_edge(g, 1, 2, false);
	insert_edge(g, 1, 3, true);
	insert_edge(g, 2, 3, false);
	insert_edge(g, 2, 4, true);
	insert_edge(g, 4, 5, true);
	insert_edge(g, 4, 2, true);
	insert_edge(g, 3, 1, true);
	print_graph(g);
	bfs(g, 1);
	find_path(5, 1, parent);
	return 0;
}