#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;


// sir de n paranteze sa se determine  lungimea maxima a unei secvente parantezate corect


int n;
string paranteze;
stack <int> s;
int nr;
int lungimemax;
int l;
ifstream f("paranteze.in");
ofstream g("paranteze.out");

int main(){
    f >> n;
    f >> paranteze;

    // adaug in stiva primul caracter
    if (s.empty() == true){
        s.push(paranteze[0]);
    }
    
    // in stiva o sa pastrez doar indicele parantezelor la care nu am gasit pereche 
    for (int i = 0; i < n; i++){
        // daca la sfarsitul stivei am ( si elem curent e ) sau [ si elem curent e ] sau { si elem curent e } 
        if((paranteze[s.top()] == '(' && paranteze[i] == ')') || (paranteze[s.top()] == '[' && paranteze[i] == ']') || (paranteze[s.top()] == '{' && paranteze[i] == '}'))
            {
                // il scot din stiva
            s.pop();
                 // daca lungimea maxima este mai mica decat diferenta indicilor 
                 if(lungimemax < i - s.top())
                {
                    lungimemax = i - s.top();
                }
        }
        else
            // daca nu i-am gasit perechea in varful stevei atunci adaug caracterul in stiva (fie ii gasesc perechea mai tarziu fie el nu este parantezat corect) 
            s.push(i);
    }

    // daca stiva este goala atunci lungimea maxima este lungimea sirului
    if (s.empty() == true)
        g << n;
    else
        // altfel afisez lungimea maxima gasita 
        g << lungimemax;
    return 0;
}