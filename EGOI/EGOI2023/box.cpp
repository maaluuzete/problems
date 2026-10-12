#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int h, w;
	cin >> h >> w;
	string q="";
	if(w>=2){
		q+=">";
	}
	for(int k=0; k<w-2; k++){
		for(int i=0; i<h; i++){
			q+="><";
			if(i<h-1){
				q+="v";
			}
		}
		for(int i=0; i<h-1; i++){
			q+="^";
		}
		q+=">";
	}
	q+=">";
	for(int i=0; i<h-1; i++){
		q+="v";
	}
	cout << "? " << q << endl;
	int fr, fc;
	cin>>fr>>fc;
	
	if(fr<h-1){
		cout<<"! "<<fr+1<<" "<<fc<<endl;
		return 0;
	}
	if(fc<w-1){
		cout<<"! "<<0<<" "<<fc+1<<endl;
		return 0;
	}
	q="";
	for(int i=0; i<h-1; i++){
		q+="v^";
		q+=">";
		q+="v^";
		q+="<";
		q+="v";
	}
	q+="v>";
	cout << "? " << q << endl;
	cin>>fr>>fc;
	
	int r, c;
	if(fr==h-1 && fc==1){
		r=1;
		c=1;
	}else if(fc==1){
		r=fr+1;
		c=0;
	}else{
		r=fr;
		c=1;
	}
	cout<<"! "<<r<<" "<<c<<endl;
	return 0;
}