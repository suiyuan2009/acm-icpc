const int maxn=40;
const int maxm=maxn*maxn;
const ll mod=1000000007;

ll c[maxm][maxm],f[maxn][maxm];

class LISNumber
{
public:
    int count(vector <int>a, int m)
    {
        int n=a.size();
        for(int i=0; i<maxm; i++)c[i][i]=c[i][0]=1;
        for(int i=1; i<maxm; i++)
            for(int j=1; j<maxm; j++)
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        int sum=a[0];
        f[0][a[0]]=1;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(f[i-1][j]==0LL)continue;
                for(int k=0; k<=m; k++)
                {
                    int left=a[i]-k;
                    if(left<0)continue;
                    ll tmp=(f[i-1][j]*c[sum-j+a[i]][left])%mod*c[j][k]%mod;
                    f[i][j+left]+=tmp;
                    f[i][j+left]%=mod;
                }
            }
            sum+=a[i];
        }
        return f[n-1][m];
    }
};
