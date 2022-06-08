#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<algorithm>
#include<math.h>
#define eps 1e-9

using namespace std;

bool accessible(const char* f){
    ifstream fs(f); // load the file into stream fs
    return fs.good();   // check if fs is accessible
}

/* depth first search to find component of s */
void dfs(int s, vector<int> adj[], bool visited[], bool present[], set<int> &nodes){
    if(visited[s])  return;
    visited[s] = true;
    for(auto u: adj[s]){
        if(present[u]){
            dfs(u, adj, visited, present, nodes);
        }
    }
}

/* check if the graph is connected */
bool isConnected(int n, vector<int> adj[], set<int> &nodes){
    int i, j, cnt = 0, k = (int) nodes.size();
    bool visited[n], present[n];
    for(i=0; i<n; i++){
        visited[i] = false;
        present[i] = false;
    }
    if(nodes.empty()){
        return false;
    }
    else{
        for(auto u: nodes){
            present[u] = true;
        }
        dfs(*(nodes.begin()), adj, visited, present, nodes);
        for(i=0; i<n; i++){
            if(visited[i])  cnt++;
        }
        if(cnt==k){
            return true;
        }
        else{
            return false;
        }
    }
}

/* remove the node with maximum in_deg + out_deg, branch out if multiple found */
int maxDegree(int n, vector<int> adj[], set<int> &nodes){
    if(!isConnected(n, adj, nodes)){
        return 0;
    }
    else{
        int i, u = 0;
        for(i=0; i<n; i++){
            if(nodes.find(i)!=nodes.end() && adj[i].size()>adj[u].size()){
                u = i;
            }
        }
        vector<int> pos, ans;
        for(i=0;  i<n; i++){
            if(nodes.find(i)!=nodes.end() && adj[i].size()==adj[u].size()){
                pos.push_back(i);
            }
        }
        for(auto v: pos){
            nodes.erase(v);
            ans.push_back(1+maxDegree(n, adj, nodes));
            nodes.insert(v);
        }
        if(ans.empty()){
            return 0;
        }
        else{
            int mx = ans[0];
            for(auto x: ans){
                mx = max(mx, x);
            }
            return mx;
        }
    }
}

int maxStrength(int n, vector<vector<double> > &adjM, vector<int> adj[], set<int> &nodes){
     if(!isConnected(n, adj, nodes)){
        return 0;
    }
    else{
        double strength[n], mx = -1;
        int i, j, u = 0;
        for(i=0; i<n; i++){
            strength[i] = 0;
            for(j=0; j<n; j++){
                strength[i] += adjM[i][j] + adjM[j][i]; // no self loops anyways
            }
            if(nodes.find(i)!=nodes.end() && strength[i]>mx){
                mx = strength[i];
                u = i;
            }
        }
        nodes.erase(u);
        cout << u << " " << mx << "\n";
        return 1+maxStrength(n, adjM, adj, nodes);
    }
}

int main(int argc, char** argv){
    if(argc==3){
        int n, i, j, u, v;
        double w;
        vector<vector<double> > adjM;
        if(accessible(argv[2])){
            freopen(argv[2], "r", stdin);
            cin >> n;
            vector<int> adj[n];
            vector<double> tmp;
            vector<pair<int, double> > adjL[n];
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    cin >> w;
                    tmp.push_back(w);
                    if(w>eps){
                        adjL[i].push_back({j, w});
                    }
                }
                adjM.push_back(tmp);
                tmp.clear();
            }
            fclose(stdin);
            set<int> adj_tmp[n];
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    if(adjM[i][j]>eps){
                        adj_tmp[i].insert(j);
                        adj_tmp[j].insert(i);
                    }
                }
            }
            for(i=0; i<n; i++){
                for(auto r: adj_tmp[i]){
                    adj[i].push_back(r);
                }
            }
            set<int> nodes;
            for(i=0; i<n; i++){
                nodes.insert(i);
            }
            cout << n << "\n";
            for(i=0; i<n; i++){
                for(auto u: adj[i]){
                    cout << u << " ";
                }
                cout << endl;
            }
            if(strcasecmp(argv[1], "maxdegree")==0){
                cout << maxDegree(n, adj, nodes) << "\n";
            }
            else if(strcasecmp(argv[1], "maxstrength")==0){
                cout << maxStrength(n, adjM, adj, nodes) << "\n";
            }
            else{
                cout << "Invalid attack name! Recheck the format.\n";
            }

        }
        else{
            cerr << "File not found!\n";
        }
    }
    else{
        cerr << "Invalid command! Recheck the format.\n";
    }
    return 0;
}