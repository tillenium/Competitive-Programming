#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1000010;

int cnt, ans;
int k[MAXN];
//
struct Toy {
    int val;
    int rest;
};
stack<Toy>s;

//
void solve() {
    while (!s.empty())//
        s.pop();
    //
    Toy temp;
    temp.val = k[0];
    temp.rest = abs(k[0]);
    s.push(temp);
    for (int i = 1; i < cnt; i++) {
        if (s.empty())//
            return;
        if (k[i] < 0) {//
            if (abs(k[i]) < s.top().rest) {//k[i]
                Toy temp;
                temp.val = k[i];
                temp.rest = abs(k[i]);
                s.push(temp);//
            } 
            else
                return;
        } 
        if (k[i] > 0) {//0
            if (k[i] + s.top().val == 0) {//0
                if(i != cnt-1){//?
                    s.pop();
                    s.top().rest -= k[i];
                }
                else
                    s.pop();//pop
            } 
            else
                return;
        }
    }
    if(s.empty())//ans1
        ans = 1;
}

//
int main() {
    int x;
    char c;
    //
    while (~scanf("%d%c", &x, &c)) {
        k[0] = x;
        cnt = 1;
        ans = 0;
        if (c != '\n') {
            while (scanf("%d%c", &k[cnt++], &c)) {
                if (c == '\n')
                    break;
            }
        }
        if (cnt % 2 == 0)//solve();
            solve();
        if (ans)
            printf(":-) Matrioshka!\n");
        if (!ans)
            printf(":-( Try again.\n");
    }
    return 0;
}
