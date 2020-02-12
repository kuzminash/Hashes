#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

const long long INF = 1e+9;

set<long long> answer1;
set<long long> answer2;
long long p1 = 41, mod1 = 1000099999;
long long p2 = 43, mod2 = 1000000000 + 9;
vector<long long> pp1;
vector<long long> pp2;


long long get_hesh1(vector<long long> &hesh, int l, int r) {
    if (r < l) return -239;
    return (mod1 + hesh[r + 1] - hesh[l] * pp1[r - l + 1] % mod1) % mod1;
}

long long get_hesh2(vector<long long> &hesh, int l, int r) {
    if (r < l) return -239;
    return (mod2 + hesh[r + 1] - hesh[l] * pp2[r - l + 1] % mod2) % mod2;
}


void make_hesh1(string &s, vector<long long> &hesh) {
    int n = s.size();
    pp1.resize(n + 1, 1);
    hesh.resize(n + 1, 0);
    for (int i = 0; i < n; i++)
        pp1[i + 1] = (pp1[i] * p1) % mod1;
    for (int i = 0; i < n; i++)
        hesh[i + 1] = ((hesh[i] + (s[i] - 'a' + 1)) * p1) % mod1;
}

void make_hesh2(string &s, vector<long long> &hesh) {
    int n = s.size();
    pp2.resize(n + 1, 1);
    hesh.resize(n + 1, 0);
    for (int i = 0; i < n; i++)
        pp2[i + 1] = (pp2[i] * p2) % mod2;
    for (int i = 0; i < n; i++)
        hesh[i + 1] = ((hesh[i] + (s[i] - 'a' + 1)) * p2) % mod2;
}

