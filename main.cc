#include <iostream>
#include "user.h"
using namespace std;

int main(){
int f;
string k, g;
cin >> k;

Usuario a, b;
a.SetCpf(k);
g = a.GetCpf();

cout << g;
return 0;
}
