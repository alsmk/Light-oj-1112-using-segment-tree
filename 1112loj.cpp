#include<bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define ll long long int
#define pb push_back
#define te(t) int t;cin>>t;while(t--)
#define MOD 1e9+7
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define M 2.5e5
#define clr(a,b) memset(a,b,sizeof(a))
#define m_p make_pair
using namespace std;
int ar[100001];
int t[300003];
void init(int node,int b,int e)
{
    if(b==e){t[node]=ar[b];return;}
    init(node*2,b,(b+e)/2);
    init(node*2 +1,(b+e)/2 +1,e);
    t[node]=t[node*2]+t[node*2 +1];
}
void update(int node,int b,int e,int i)
{
    if(b>i||e<i)return ;
    if(b>=i && e<=i){t[node]=ar[b];return;};
    update(node*2,b,(b+e)/2,i);
    update(node*2 +1,(b+e)/2 +1,e,i);
    t[node]=t[node*2]+t[node*2 +1];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>j ||e<i)return 0;
    if(b>=i && e<=j)return t[node];
    int p1=query(node*2,b,(b+e)/2,i,j);
    int p2=query(node*2 +1,(b+e)/2 +1,e,i,j);
    return p1+p2;
}

int main()
{
    fast
    int te,ca=0;
    cin>>te;
    while(te--)
    {
        clr(ar,0);
        clr(t,0);
        int n,q;
        cin>>n>>q;
        f1(i,n)cin>>ar[i];
        init(1,1,n);
        printf("Case %d:\n",++ca);
        for(int m=1;m<=q;m++)
        {
            int f;
            cin>>f;
            if(f==1)
            {
                int h;
                cin>>h;
                ++h;
                cout<<ar[h]<<endl;
                ar[h]=0;
                update(1,1,n,h);

            }
            else if(f==2)
            {
                int h,g;
                cin>>h>>g;
                h++;
                ar[h]+=g;
                update(1,1,n,h);

            }
            else if(f==3){
                int h,g;
                cin>>h>>g;
                h++,g++;
                int ans=query(1,1,n,h,g);
                cout<<ans<<endl;
            }

        }
    }
    return 0;
}

