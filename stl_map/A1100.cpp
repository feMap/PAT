#include <cstdio>
#include <map>
using namespace std;

int main()
{
  int n, m, col;
  scanf("%d%d", &n, &m);
  // 这个其实可以把这个看作是字典的替代产物
  map<int, int> count;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      scanf("%d", &col);
      // 当count组中没有col颜色时增加 count[col] = 1
      // find方法可以找到这个map中是否含有这个key值
      if(count.find(col) != count.end())
      {
        count[col]++;
      }
      else
      {
        count[col] = 1;
      }
    }
  }
  
  int k = 0, MAX = 0;
  // 这个迭代器是真的好用！！！
  for(map<int, int>::iterator it = count.begin(); it != count.end(); it++)
  {
    // 这个first和second对应的key和value
    if(it->second > MAX)
    {
      k = it->first;
      MAX = it->second;
    }
  }
  printf("%d\n", k);
  return 0;
}