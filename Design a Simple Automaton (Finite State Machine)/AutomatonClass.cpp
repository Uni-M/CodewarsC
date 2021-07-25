#include "stdafx.h"
#include "AutomatonClass.h"

Automaton::Automaton() {}

bool Automaton::read_commands(const std::vector<char>& commands)
{
    int state = 1;

    for (auto ch : commands)
    {
        switch (state)
        {
        case 1:
            if (ch == '1')
            {
                state = 2;
            }
            break;
        case 2:
            if (ch == '0')
            {
                state = 3;
            }
            break;
        case 3:
            if (ch == '0' || ch == '1')
            {
                state = 2;
            }
            break;
        }
    }
    return (state == 2) ? true : false;
}