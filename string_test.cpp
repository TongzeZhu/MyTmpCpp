#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    const std::string ASTRING = "I will reserve a meal for dinner at 18:15!";
    std::vector<std::string> out;
    auto begin = ASTRING.begin();
    auto index = find(begin, ASTRING.end(), ' ');
    auto iter = out.begin();

    while(index != ASTRING.end())
    {
        out.emplace_back(begin, index);
        begin = ++index;
        index = find(begin, ASTRING.end(), ' ');
    }
    out.emplace_back(begin, index);
    iter = out.begin();
    while(iter != out.end())
        std::cout << *iter++ << std::endl;
    return 0;
}

