#include <cstdio>
#include <cstring>


bool hashTable[256];
  

int main() {
  char str[100010];
  int len;
  memset(hashTable, true, sizeof(hashTable));

  gets(str);
  len = strlen(str);
  

  // printf("%d", hashTable['D']);

  char c1;
  for(int i = 0; i < len; i++) {
    c1 = str[i];
    // hashTable[c1] = false;
    if(c1 >= 'a' && c1 <= 'z') {
      hashTable[c1] = false;
      c1 = c1 - 32;
    }
    else if(c1 >= 'A' && c1 <= 'Z') {
      hashTable[c1] = false;
      c1 = c1 + 32;
    }
    hashTable[c1] = false;
  }
  
  gets(str);
  len = strlen(str);

  printf("%d\n", hashTable['+']);
  
  char c2;
  for(int i = 0; i < len; i++) {
    c2 = str[i];
    // printf("%d", hashTable['D']);
    if(hashTable[c2] == true) {
      if(hashTable['+'] == false) {
        if(c2 >= 'A' && c2 <= 'Z') {
          continue;
        }
      }
      printf("%c", c2);
    }
  }
  
  printf("\n");
  
  return 0;
}