
#include <string>

std::string mvidakovic__vowelChange(std::string k)
{
    unsigned int i, inLength = k.length();
    for (i = 0; i < inLength; ++i)
    {
        char& c = k[i];
        switch (c)
        {
        case 'a': case 'A': c = '1'; break;
        case 'e': case 'E': c = '2'; break;
        case 'i': case 'I': c = '3'; break;
        case 'o': case 'O': c = '4'; break;
        case 'u': case 'U': c = '5'; break;
        default: break;
        }
    }
    return k;
}
