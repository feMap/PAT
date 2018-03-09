#include <iostream>
#include <string>
using namespace std;
int n;

string deal(string s, int& e) {
    int k = 0;
    // 这里还可能出现空的字符串么？
    while(s.length() > 0 && s[0] == '0') {
        s.erase(s.begin());
    }

    // 第一种情况
    if(s[0] == '.') {
        s.erase(s.begin());
        while(s.length > 0 && s[0] == '0') {
            s.erase(s.begin())
            e--;
        }
    } 
    else {
        while(k < e.length() && s[0] != '.') {
            k++;
            e++;
        }
        if(k < s.length()) {
            // 擦除小数点
            s.erase(s.begin() + k);
        }
    }

    // 为何要这个？
    // 去除前导0，之后如果s.length()仍然为0，则说明这个数为0
    if(s.length() == 0) {
        e = 0;
    }

    int num = 0;
    k = 0;
    string res;
    while(num < n) {
        if(k < s.length()) res += s[k++];
        else res += '0';
        num++;
    }

    return res;
}

int main() {
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);

    if(s3 == s4 && e1 == e2) {
        cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
    } else {
        cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
    }
    return 0;
}