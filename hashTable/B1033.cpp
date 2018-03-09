#include <cstdio>
#include <cstring>

const int maxn = 100010;
bool hashTable[256] = {false};
char str[maxn];

int main() {
    memset(hashTable, true, sizeof(hashTable));

    gets(str);
    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        // 相当于作者将所有的字母都降到了小写来比较
        // hashTable[str[i]] = false;
        if(str[i] >= 'A' && str[i] <= 'Z') {
            // 一定主要小写字母在数值上是大于大写字母的，差值为32
            str[i] = str[i] + 32;
        }
        hashTable[str[i]] = false;
    }

    // printf("%d", 'A' - 'a');

    gets(str);
    len = strlen(str);

    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            int low = str[i] + 32;
            if(hashTable[low] == true && hashTable['+'] == true) {
                printf("%c", str[i]);
            }
        }
        else if(hashTable[str[i]] == true) {
            printf("%c", str[i]);
        }
    }

    printf("\n");

    return 0;
}