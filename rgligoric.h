
#include <string>
#include <algorithm>

std::string rgligoric__vowelChange_test_stdlib(std::string k) {
    std::replace_if(k.begin(), k.end(), [](char c) { return c == 'a' || c == 'A'; }, '1');
    std::replace_if(k.begin(), k.end(), [](char c) { return c == 'e' || c == 'E'; }, '2');
    std::replace_if(k.begin(), k.end(), [](char c) { return c == 'i' || c == 'I'; }, '3');
    std::replace_if(k.begin(), k.end(), [](char c) { return c == 'o' || c == 'O'; }, '4');
    std::replace_if(k.begin(), k.end(), [](char c) { return c == 'u' || c == 'U'; }, '5');
    return k;
}
