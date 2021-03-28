#include <iostream>
#include <string>
#include <fstream>
#include <deque>
using namespace std;

ifstream f("alibaba.in");
ofstream g("alibaba.out");

int main(){
    deque<char> dq; // o sa aiba lungimea n - k
    int n,k;
    string s;
    f >> n >> k;
    // n = nr de cifre
    // k = nr de diamante
    f >> s;
    int aux = 0;
    // '0' = 48

    dq.push_back(s[0]);
    for (int i = 1; i < n; i++){
        while (dq.size() > 0 && s[i] > dq.back() && aux < k ){
            dq.pop_back();
            aux++;
        }
        if (dq.size() < n-k)
            dq.push_back(s[i]);
    }

    while(dq.size() > 0){
        g << dq.front();
        dq.pop_front();
    }

    return 0;
}
