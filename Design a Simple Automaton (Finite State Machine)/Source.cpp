#include "stdafx.h"
#include "AutomatonClass.h"


using namespace std;

int main() {
   setlocale(LC_ALL, "ru");

   Automaton a;
   vector<char> v = { '1', '0', '0', '1', '0' };
   cout << a.read_commands(v); // ==> false

    system("pause");
}