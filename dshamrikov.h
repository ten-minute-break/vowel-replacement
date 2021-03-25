
#include <numeric>
#include <string>

char* GetMapping()
{
    static char map[256] = { 0 };
    std::iota(map, map + 256, 0);
    map['a'] = '1';
    map['e'] = '2';
    map['i'] = '3';
    map['o'] = '4';
    map['u'] = '5';
    map['A'] = '1';
    map['E'] = '2';
    map['I'] = '3';
    map['O'] = '4';
    map['U'] = '5';
    return map;
}

short* GetMapping2()
{
    const int SIZE = 256 * 256;
    static short map[SIZE] = { 0 };
    std::iota(map, map + SIZE, 0);

    char* singleMap = GetMapping();

    unsigned const char vows[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    for (unsigned char v : vows)
    {
        for (unsigned int i = 0; i < 256; ++i)
        {
            unsigned short key = ((unsigned int)v << 8) | i;
            short value = (singleMap[v] << 8) | singleMap[i];
            map[key] = value;

            key = (i << 8) | v;
            value = (singleMap[i] << 8) | singleMap[v];
            map[key] = value;
        }
    }
    return map;
}

std::string dshamrikov__vowelChange(std::string k)
{
    const static char* vow = GetMapping();
    const static short* vow2 = GetMapping2();

    int len = k.length() >> 1;
    short* buffer = (short*)const_cast<char*>(k.data());
    for (int i = 0; i < len; ++i)
    {
        short& c = buffer[i];
        c = vow2[c];
    }

    len = k.length();
    if (len & 1)
    {
        k[len - 1] = vow[(unsigned char)k[len - 1]];
    }

    return k;
}