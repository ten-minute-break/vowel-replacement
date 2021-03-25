
#include <string>
#include <unordered_map>

std::string azdravkovic__vowelChange_test_swap(std::string k)
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
        char& c = k[i];
        if (vow.find(c) != vow.end())
        {
            std::string newString(1, vow[c]);
            k.swap(newString);
            //c = vow[c];
        }
    }

    return k;
}
