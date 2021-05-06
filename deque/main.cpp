#include <iostream>
#include <fstream>
using namespace std;

// pentru foecare subsecventa de lungime k sa se det minimul
// si sa se calculze suma minimelor

ifstream f ("deque.in");
ofstream g ("deque.out");
int dq[5000001], aux[5000001];

int main(){
    long long n, k;
    // n = nr de elem
    // k = lungimea subsecventelor din aux

    f >> n >> k;
    long long suma = 0;
    int frontq = 1, backq = 0;
    // citesc secventa aux
    for (int i = 1; i <= n; i++)
        f>>aux[i];

    for (int i = 1; i <= n; i++){
        // determin la fiecare pas minimul din subsecventa
        // in dq o sa retin pozitia elem minim
        // elimin la fiecare pas elementele din dq mai mari deact aux[i] si dupa il adaug la sf dq
        
        // cat timp mai am elem in deque si elem curent din aux este mai mic decat elem minim din dq
        while (frontq <= backq && aux[i] <= aux[dq[backq]])
            // sterg elem
            backq--;
        // in dq pun pozitia elem curent 
        dq[++backq] = i;
        
        // se elimina minimul (primul elem din dq) de la inceputul dq daca acesta nu mai apartine subsecventei
        if (dq[frontq] == i - k)
            frontq ++;

        // elementul minim se afla la inceputul dq si il adun in suma
        if (i >= k)
            suma+= aux[dq[frontq]];

    }

    g << suma;
    return 0;
}
