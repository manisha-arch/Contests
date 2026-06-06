#include <bits/stdc++.h>
using namespace std;
/* 
Atcoder Heuristic Contest 
A - Macro Controller
*/
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#define AUTHOR "GrimFace"
int N,M,T,b[222][4],dx[]={0,1,0,-1},dy[]={1,0,-1,0};
vector<string>v,h;string ans;

void bfs(int r1,int c1,int r2,int c2,vector<pair<int,int>>&p){
    if(r1==r2&&c1==c2){p.clear();return;}
    static int pr[22][22],pc[22][22],vis[22][22],stamp;
    stamp++;
    queue<pair<int,int>>q;
    q.push({r1,c1});
    vis[r1][c1]=stamp;
    
    while(q.size()){
        auto[r,c]=q.front();q.pop();
        if(r==r2&&c==c2){
            p.clear();
            int cr=r2,cc=c2;
            while(cr!=r1||cc!=c1){
                p.push_back({cr,cc});
                int tr=pr[cr][cc],tc=pc[cr][cc];
                cr=tr;cc=tc;
            }
            p.push_back({r1,c1});
            reverse(p.begin(),p.end());
            return;
        }
        for(int i=0;i<4;i++){
            int nr=r+dx[i],nc=c+dy[i];
            if(nr<0||nr>=N||nc<0||nc>=N||vis[nr][nc]==stamp)continue;
            bool ok=1;
            if(i==0&&c<N-1&&v[r][c]=='1')ok=0;


            if(i==1&&r<N-1&&h[r][c]=='1')ok=0;
            
            if(i==2&&c>0&&v[r][c-1]=='1')ok=0;

            if(i==3&&r>0&&h[r-1][c]=='1')ok=0;
            if(ok){
                vis[nr][nc]=stamp;
                pr[nr][nc]=r;pc[nr][nc]=c;
                q.push({nr,nc});
            }
        }
    }
}

void go(vector<pair<int,int>>&p,int&d){
    for(int i=1;i<p.size();i++){
        int dr=p[i].first-p[i-1].first,dc=p[i].second-p[i-1].second,nd;
        nd=(dr==0)?(dc==1?0:2):(dr==1?1:3);
        int t=(nd-d+4)&3;

        if(t==1)ans+='R',d=nd;

        else if(t==2)ans+="RR",d=nd;
        else if(t==3)ans+='L',d=nd;
        ans+='F';
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M>>T;v.resize(N);h.resize(N-1);
    for(int i=0;i<N;i++)cin>>v[i];
    for(int i=0;i<N-1;i++)cin>>h[i];

    for(int i=0;i<M;i++)cin>>b[i][0]>>b[i][1]>>b[i][2]>>b[i][3];

    int r=0,c=0,d=0;vector<pair<int,int>>p;

    for(int i=0;i<M&&ans.size()<T*0.95;i++){
        bfs(r,c,b[i][0],b[i][1],p);
        go(p,d);r=b[i][0];
        c=b[i][1];ans+='S';
        bfs(r,c,b[i][2],b[i][3],p);
        go(p,d);r=b[i][2];
        c=b[i][3];ans+='S';
    }
    for(char x:ans)cout<<x<<'\n';
}