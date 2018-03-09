#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define Max 40011
const int MAX = 2511;
using namespace std;
vector<int> S[MAX];
char name[Max][5];
bool cmp(int a ,int b)
{
    return strcmp(name[a],name[b])<0;
}
int main()
{
    
    int n,m,k,c;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s %d",name[i],&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&c);
            S[c].push_back(i);
        }
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d %d\n",i,S[i].size());
        sort(S[i].begin(),S[i].end(),cmp);
        for(int j=0;j<S[i].size();j++)
        {
            printf("%s\n",name[S[i][j]]);
        }
    }
    system("pause");
    return 0;
}