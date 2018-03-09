#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 40001;
const int maxc = 2510;

char name[maxn][5];
vector<int> course[maxc];

bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    int n, k, c, courseID;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        // 又是个低级错误，除了数组一定要接取址符号
        scanf("%s %d", name[i], &c);
        for(int j = 0; j < c; j++) {
            scanf("%d", &courseID);
            course[courseID].push_back(i);
        }
    }

    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        // for循环之间是；千万不要犯低级错误！
        for(int j = 0; j < course[i].size(); j++) {
            printf("%s\n", name[course[i][j]]);
        }
    }

    return 0;
}