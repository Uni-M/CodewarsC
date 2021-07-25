#include "stdafx.h"

using namespace std;


string range_extraction(vector<int> args) {

    string ans;
    string tmp;
    int count = 1;

    for (unsigned long i = 0; i < args.size(); i++)
    {
        if (args[i] == args[args.size() - 1])
        {
            if (tmp.length() == 0)
            {
                ans += to_string(args[i]);
                return ans;
            }
            else if (args[i - 2] == args[i] - 2)
            {
                ans += tmp + to_string(args[i]);
                return ans;
            }
            else
            {
                ans += to_string(args[i - 1]) + ',';
                ans += to_string(args[i]);
                return ans;
            }
        }

        if (args[i] + 1 != args[i + 1] && tmp.length() == 0) ans += to_string(args[i]) + ',';
        else if (args[i] + 1 == args[i + 1] && tmp.length() == 0)
        {
            tmp += to_string(args[i]) + '-';
            count++;
        }
        else if (args[i] + 1 != args[i + 1] && tmp.length() > 0 && count <= 2)
        {
            ans += to_string(args[i - 1]) + ',';
            ans += to_string(args[i]) + ',';
            tmp.clear();
            count = 1;
        }
        else if (args[i] + 1 != args[i + 1] && tmp.length() > 0 && count >= 3)
        {
            ans += tmp + to_string(args[i]) + ',';
            tmp.clear();
            count = 1;
        }
        else count++;
    }

    return ans;
}

int main() {
   setlocale(LC_ALL, "ru");

   cout << range_extraction({ -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20 });
   // returns "-6,-3-1,3-5,7-11,14,15,17-20"

    system("pause");
}