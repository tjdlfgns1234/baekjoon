#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
using namespace std;

// Beware of MAX & MIN value!
// Beware of floating point Error!

struct edge {
	int p1, p2;
	double w;
};

bool compare(edge a, edge b);
double dist(pair<double, double>& p1, pair<double, double>& p2);  // Distance is edge's cost!!
double kruskal(int n,vector <edge> & edges);
int find(vector<int>& p, int a);
bool _union(vector<int>& p, int a, int b);



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	double a, b;
	cin >> n;
	vector <pair<double, double>> p(n);
	vector <edge> edges;

	for (int i = 0; i < n; i++)
		cin >> a >> b, p[i].first = a, p[i].second = b;
	
	// Make edges with time complexity O(n^2)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			edges.push_back({i,j,dist(p[i],p[j])});

	sort(all(edges),compare);
	cout << fixed;
	cout.precision(2);
	cout << kruskal(n,edges);

	return 0;
}
double dist(pair<double, double>& p1, pair<double, double>& p2){
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
bool compare(edge a, edge b) {
	return a.w < b.w;
}
double kruskal(int n,vector <edge>& edges) {
	vector <int> parent(n);
	double ret = 0.0;
	// init
	for(int i = 0; i < n; i++)
		parent[i] = i;

	for (unsigned int i = 0; i < edges.size(); i++)
	{
		if (_union(parent,edges[i].p1, edges[i].p2))
		{
			ret += edges[i].w;
		}
	}
	return ret;
}
int find(vector<int>& p, int a) {
	if (p[a] == a)
		return a;
	else
		return p[a] = find(p,p[a]);
}
bool _union(vector<int>& p, int a, int b) {
	a = find(p, a);
	b = find(p, b);
	if (a == b)
		return false;
	else if (a < b)
		p[b] = a;
	else
		p[a] = b;

	return true;
}