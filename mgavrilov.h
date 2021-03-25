
#include <string>
#include <unordered_map>
#include <algorithm>
#include <execution>
#include <vector>
#include <numeric>

std::string mgavrilov__vowelChange(std::string k)
{
    char* c = const_cast<char*>(k.data());

    while (*c != '\0')
    {
        switch (*c)
        {
        case 'a': case 'A': *c = '1'; break;
        case 'e': case 'E': *c = '2'; break;
        case 'i': case 'I': *c = '3'; break;
        case 'o': case 'O': *c = '4'; break;
        case 'u': case 'U': *c = '5'; break;
        }

        ++c;
    }

    return k;
}

std::string mgavrilov__vowelChange_test_map(std::string k)
{
    static std::unordered_map<char, char> vow{
        { 'a', '1' }, { 'A', '1' },
        { 'e', '2' }, { 'E', '2' },
        { 'i', '3' }, { 'I', '3' },
        { 'o', '4' }, { 'O', '4' },
        { 'u', '5' }, { 'U', '5' },
    };

    for (int i = 0; i < k.length(); ++i)
    {
        const char& c = k[i];
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
        {
            k[i] = vow[c];
        }
    }

    return k;
}

std::string mgavrilov__vowelChange_test_hotPaths(std::string k)
{
    for (char& c : k)
    {
        if (c == 'a' || c == 'A')
            c = '1';
    }

    for (char& c : k)
    {
        if (c == 'e' || c == 'E')
            c = '2';
    }

    for (char& c : k)
    {
        if (c == 'i' || c == 'I')
            c = '3';
    }

    for (char& c : k)
    {
        if (c == 'o' || c == 'O')
            c = '4';
    }

    for (char& c : k)
    {
        if (c == 'u' || c == 'U')
            c = '5';
    }

    return k;
}

std::string mgavrilov__vowelChange_test_stdlib(std::string k)
{
    std::replace_if(k.begin(), k.end(), [](char c) { return c == 'a' || c == 'A'; }, '1');
    std::replace_if(k.begin(), k.end(), [](char c) { return c == 'e' || c == 'E'; }, '2');
    std::replace_if(k.begin(), k.end(), [](char c) { return c == 'i' || c == 'I'; }, '3');
    std::replace_if(k.begin(), k.end(), [](char c) { return c == 'o' || c == 'O'; }, '4');
    std::replace_if(k.begin(), k.end(), [](char c) { return c == 'u' || c == 'U'; }, '5');
    return k;
}
