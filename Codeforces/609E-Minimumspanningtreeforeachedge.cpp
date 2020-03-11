/*
	SubmissionId	:	14902035
	ContestId	:	609
	Index	:	E
	ProblemName	:	Minimum spanning tree for each edge
	ProblemTags	:	['data structures', 'dfs and similar', 'dsu', 'graphs', 'trees']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
#define int ll 
// bitch please

typedef pair < int , pair < int , int > > edge ;
const int maxn = 300000;
	int n , m ;

int dis[maxn];


int fin(int a){
	if(dis[a] != a)
		return dis[a] = fin(dis[a]);
	return dis[a];
}
void uni(int a , int b){
	dis[fin(a)] = fin(b);
}

vector < edge > edges ;

edge make(int a , int b , int c){
	return make_pair(a , make_pair(b , c));
}

vector < pair < int ,int > > adj [maxn]; // weight , node
const int BIG_DADDY = 22 ;

int par[BIG_DADDY][maxn];
int mxx[BIG_DADDY][maxn];
int dep[maxn];

int dfs(int node , int dad ,int wei , int depth = 0){
	//cout << node << " dad : " << dad << endl ;
	dep[node]= depth ;
	par[0][node] = dad ;
	mxx[0][node] = wei;
	for(auto it : adj[node]){
		if(it.second != dad)
			dfs(it.second, node , it.first , depth + 1);
	}
}

vector < edge >orig ;

void build(){
	for(int i = 0 ;i < BIG_DADDY -1; i++){
		for(int j = 1 ;j <= n ; j++){
			par[i+1][j] = par[i][par[i][j]];
			mxx[i+1][j] = max(mxx[i][j] , mxx[i][par[i][j]]);
		}
	}
}

int lift(int a , int num, int & mx){
	for(int i = BIG_DADDY - 1 ;i >= 0 ; i--){
		if((num >> i)&1){
			mx = max(mx , mxx[i][a]);
			a = par[i][a];
		}
	}
	return a ;
}

int getToLca(int a , int b){
	// cout << "lca of " << a << " " << b << " : " ;
	if(dep[a] > dep[b])
		swap(a , b);
	int mx = 0 ;
	b = lift(b , dep[b] - dep[a] ,mx);
	if(a == b){
		// cout << a << endl ;
		return mx ;
	}
	for(int i = BIG_DADDY - 1; i >= 0 ; i --){
		if(par[i][a] != par[i][b]){
			mx = max(mx , mxx[i][a]);
			mx = max(mx , mxx[i][b]);
			a = par[i][a];
			b = par[i][b];
		}
	}
	// cout << par[0][a] << endl;
	return max(mx , max(mxx[0][a] , mxx[0][b]));
}
#undef int
int main(){
#define int ll
	scanf("%I64d%I64d" , &n , &m);	
	for(int i = 0 ;i < BIG_DADDY ; i ++){
		for(int j = 1 ;j <= n ; j++){
			par[i][j] = 1;
		}
	}

	for(int i = 1 ;i <= n ;i++){
		dis[i] = i ;
	}
	for(int i = 0 ;i < m ; i++){
		int a , b , w; 
		scanf("%I64d%I64d%I64d" , &a , &b , &w);
		edges.push_back(make(w, a , b ));
		orig.push_back(edges.back());	
	}

	sort(edges.begin(), edges.end());
	int num = n-1 ;
	int val = 0 ;
	for(auto it : edges){
		if(num == 0)
			break ;
		int nodea = it.second.first ;
		int nodeb = it.second.second ;
		if(fin(nodea) != fin(nodeb)){
			uni(nodea , nodeb);
			val += it.first ;
			adj[nodea].push_back(make_pair(it.first , nodeb));
			adj[nodeb].push_back(make_pair(it.first, nodea));
			// cout << "tree : "  << nodea << " " << nodeb << endl ;
		}
	}
	dfs(1 , 1 , 0);
	build();
	for(auto it : orig){
		printf("%I64d\n" , val - getToLca(it.second.first , it.second.second)+ it.first);
	}
	fflush(stdout);
	return 0 ;
}
