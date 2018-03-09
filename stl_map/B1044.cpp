#include <cstdio>
#include <map>
#include <iostream>
#include <string>
using namespace std;

string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may",
                         "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou",
                       "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string numToStr[170];
map<string, int> strToNum;

void init()
{
    // 一位数的情况
    for(int i = 0; i < 13; i++)
    {
        numToStr[i] = unitDigit[i];
        strToNum[unitDigit[i]] = i;

        numToStr[i * 13] = tenDigit[i];
        strToNum[tenDigit[i]] = i * 13;
    }

    // 两位数的情况
    for(int i = 1; i < 13; i++)
    {
        for(int j = 1; j < 13; j++)
        {
            string str = tenDigit[i] + " " + unitDigit[j];
            numToStr[13 * i + j] = str;
            strToNum[str] = 13 * i + j;
        }
    }

}

int main()
{
    init();
    int T;
    // 这个地方诡异的字符是什么意思呀？
    scanf("%d%*c", &T);
    while(T--)
    {
        string str;
        // getline的用法需要学习一下
        getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9')
        {
            int num = 0;
            for(int i = 0; i < str.length(); i++)
            {
                num = num * 10 + (str[i] - '0');
            }
            cout << numToStr[num] << endl;
        }
        else
        {
            cout << strToNum[str] << endl;
        }
    }

    return 0;
}