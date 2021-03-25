# vowel-replacement
Replace AEIOU with 12345 as optimally as possible!

You've been given this cool function to replace all instances of "AEIOU" (case-insensitive) with the digits "12345":

```cpp
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
        if (c == 'a' || c == 'A' || 
            c == 'e' || c == 'E' || 
            c == 'i' || c == 'I' || 
            c == 'o' || c == 'O' || 
            c == 'u' || c == 'U')
        {
            k[i] = vow[c];
        }
    }

    return k;
}
```

How fast will your version be and what trickery will you use to surpass the awesome speed of the function above?
