#include<bits/stdc++.h>
#define pii pair<int,int>
#define MAX 505
#define clr(a) memset(a,0,sizeof(a))
#define ll long long
#define mp(a,b) make_pair(a,b)
using namespace std;

int node, edge;
vector<pii>v[MAX];
int dis[MAX];
void bfs(int src){
    dis[src]=0;
    //if (src==des) return 0;
    queue<int>q;
    q.push(src);
    clr(dis);
    //clr(vis);
    while(!q.empty()){
        int u=q.front();
        //vis[u]=0;
        q.pop();
        for (int i=0;i<v[u].size();i++){
            pii top=v[u][i];
            int n=top.first;
            int cst=top.second;
            int tm=0;
            if (dis[u]>cst)cst=dis[u];
            if (dis[n]>cst){
                    dis[n]=cst;
                    if(n!=src)q.push(n);
            }
            else{
                if (dis[n]==0){
                    dis[n]=cst;
                    if (n!=src)q.push(n);
                }
            }
        }
    }
}
int main()
{
    int test,t=0;
    scanf("%d",&test);
    while(test--){
        int u1,u2,cst;
        clr(v);
        scanf("%d%d",&node,&edge);
        for (int i=1;i<=edge;i++){
            scanf("%d%d%d",&u1,&u2,&cst);
            if (u1!=u2)
            {
                v[u1].push_back(pii(u2,cst));
                v[u2].push_back(pii(u1,cst));
            }

        }
        int q;
        scanf("%d",&q);
        bfs(q);
        printf("Case %d:\n",++t);
        for (int i=0;i<=node-1;i++){
            if (i==q) printf("0\n");
            else if (dis[i]!=0)printf("%d\n",dis[i]);
            else printf("Impossible\n");
        }
    }


}
