#include <string>

std::string mjovanovic__vowelChange_test_base(std::string k)
{
    int duzina = k.length();
    for (int i = 0; i < duzina; ++i)
    {
        char& c = k[i];

        switch (c)
        {
        case 'A':
        case 'a':
            c = '1';
            break;
        case 'E':
        case 'e':
            c = '2';
            break;
        case 'I':
        case 'i':
            c = '3';
            break;
        case 'O':
        case 'o':
            c = '4';
            break;
        case 'U':
        case 'u':
            c = '5';
            break;
        }
    }

    return k;
}