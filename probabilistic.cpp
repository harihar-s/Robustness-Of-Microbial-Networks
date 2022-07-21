#include<bits/stdc++.h>
#define eps 1e-9

using namespace std;

void dfs(int s, vector<vector<double> > &adjM, bool vis[], set<int> &nodes){
	vis[s] = true;
	for(int j=0; j<adjM[s].size(); j++){
		if(abs(adjM[s][j])>eps && !vis[j] && nodes.find(j)!=nodes.end())
			dfs(j, adjM, vis, nodes);
	}
}

int f(int s, set<int> &nodes, vector<vector<double> > &adjM, vector<double> &p, int len){
	int N = adjM[0].size();
	bool vis[N];
	for(int i=0; i<N; i++){
		vis[i] = false;
	}
	nodes.erase(s);
	if(nodes.size()==0)
		return len;
	dfs(*nodes.begin(), adjM, vis, nodes);
	int cnt = 0;
	for(int i=0; i<N; i++)
		if(vis[i]) cnt++;
	if(cnt<nodes.size())
		return len;
	double mx = 0, st = 0;
	for(int i=0; i<adjM[s].size(); i++){
		st += abs(adjM[s][i]);
	}
	for(int i=0; i<adjM[s].size(); i++){
		if(adjM[s][i]>0 && nodes.find(i)!=nodes.end())
			p[i] += (adjM[s][i]/st)*(1-p[i])/2;
		else
			p[i] += (adjM[s][i]/st)*(p[i]/2);
	}
	p[s] = 0;
	nodes.erase(s);
	int nxt = -1;
	for(auto u: nodes){
		if(p[u]>mx){
			mx = p[u];
			nxt = u;
		}
	}
	return f(nxt, nodes, adjM, p, 1 + len);
}

int main(){
	int N, i, j;
	cin >> N;
	vector<vector<double> > adjM(N, vector<double> (N));
	vector<double> p(N, 0.5);
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			cin >> adjM[i][j];
		}
	}
	double len = 0;
	for(i=0; i<N; i++){
		set<int> nodes;
		for(j=0; j<N; j++){
			nodes.insert(j);
			p[j] = 0.5;
		}
		len += f(i, nodes, adjM, p, 1);
	}
	cout << len/N;
	return 0;
}
