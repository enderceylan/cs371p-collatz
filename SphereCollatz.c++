// ----------------------------
// projects/collatz/SphereCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <map>

using namespace std;

//#ifdef CACHE
map<int, int> m;
//#endif

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    if (i > j)
    {
        int temp = i;
        i = j;
        j = temp;
    }
    if (i <= 0)
    {
        return 0;
    }
    int max_cycles = 0;
    while (i <= j)
    {
        int num = i;
        int cycles = 0;

        //#ifdef CACHE
        if (m.find(num) != m.end())
        {
            cycles = m[num];
        }

        else
        {
            //#endif
            while (num >= 1)
            {
                if (num % 2 == 0)
                {
                    num = num / 2;
                }
                else if (num == 1)
                {
                    num = 0;
                }
                else
                {
                    num = (num*3) + 1;
                }
                cycles++;
            }
            //#ifdef CACHE
            m[num] = cycles;
        }
        //#endif
        if (cycles > max_cycles)
        {
            max_cycles = cycles;
        }
        i++;
    }
    return max_cycles;} 

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}