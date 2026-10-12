#include<bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

vector<int> filhos[MAXN];
vector<int> medal[MAXN];
int dono[MAXN];
int ultdia[MAXN];
int pai[MAXN];
int atual[200005];
int resp[200005];

int sz;
long long val[200005];
vector<int> seg;

bool melhor(int a, int b){
	if(val[a]!=val[b]){
		return val[a]>val[b];
	}
	return a<b;
}

void att(int p){
	int pos=p+sz;
	pos/=2;
	while(pos>=1){
		int a=seg[2*pos], b=seg[2*pos+1];
		if(melhor(a, b)){
			seg[pos]=a;
		}else{
			seg[pos]=b;
		}
		pos/=2;
	}
}

void soma(int p, long long v){
	val[p]+=v;
	att(p);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	if(!(cin>>n>>m)){
		return 0;
	}
	int nos=n;
	for(int i=0; i<n; i++){
		dono[i]=i;
		atual[i]=i;
		pai[i]=-1;
		ultdia[i]=m;
	}
	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		int ny=atual[y];
		ultdia[ny]=i;
		pai[ny]=atual[x];
		filhos[atual[x]].push_back(ny);
		
		dono[nos]=y;
		pai[nos]=-1;
		ultdia[nos]=m;
		atual[y]=nos;
		
		nos++;
		medal[atual[x]].push_back(i);
	}
	
	sz=1;
	while(sz<n){
		sz*=2;
	}
	val[n]=-(1LL<<60);
	seg.assign(2*sz, 0);
	for(int i=0; i<sz; i++){
		if(i<n){
			seg[sz+i]=i;
		}else{
			seg[sz+i]=n;
		}
	}
	for(int i=sz-1; i>=1; i--){
		if(melhor(seg[2*i], seg[2*i+1])){
			seg[i]=seg[2*i];
		}else{
			seg[i]=seg[2*i+1];
		}
	}
	
	vector<int> id(nos, 0);
	for(int r=0; r<nos; r++){
		if(pai[r]!=-1){
			continue;
		}
		vector<int> pilha;
		pilha.push_back(r);
		while(!pilha.empty()){
			int u=pilha.back();
			if(id[u]==0){
				for(int med : medal[u]){
					long long ganho=ultdia[u]-med;
					soma(dono[u], ganho);
					resp[seg[1]]++;
					soma(dono[u], -ganho);
				}
			}
			if(id[u]<(int)filhos[u].size()){
				int c=filhos[u][id[u]];
				id[u]++;
				soma(dono[u], ultdia[u]-ultdia[c]);
				pilha.push_back(c);
			}else{
				pilha.pop_back();
				if(!pilha.empty()){
					int v=pilha.back();
					soma(dono[v], -(long long)(ultdia[v]-ultdia[u]));
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		cout << resp[i] << " ";
	}
	cout << endl;
	return 0;
}