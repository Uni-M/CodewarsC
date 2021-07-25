#pragma once

class Automaton
{
public:
    Automaton();
    bool read_commands(const std::vector<char>& commands);
};
