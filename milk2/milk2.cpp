/*
ID: liu.enz1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}

