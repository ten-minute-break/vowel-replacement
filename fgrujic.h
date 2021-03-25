
#include <string>

static constexpr const char* lookup_table = "................................ !\"#$%&'()*+,-./0123456789:;<=>?@1BCD2FGH3JKLMN4PQRST5VWXYZ[\\]^_`1bcd2fgh3jklmn4pqrst5vwxyz{|}~.";

std::string fgrujic__vowelChange(std::string k) {
    char* chr = const_cast<char*>(k.c_str());
    while (*chr != '\0')
    {
        *chr = *(lookup_table + *chr);
        chr++;
    }
    return k;
}

std::string fgrujic__vowelChange_test_data_vs_cstr(std::string k) {
    char* chr = const_cast<char*>(k.data());
    while (*chr != '\0')
    {
        *chr = *(lookup_table + *chr);
        chr++;
    }
    return k;
}

std::string fgrujic__vowelChange_test_preinc(std::string k) {
    char* chr = const_cast<char*>(k.data());
    while (*chr != '\0')
    {
        *chr = *(lookup_table + *chr);
        ++chr;
    }
    return k;
}

std::string fgrujic__vowelChange_test_memcpy(std::string k) {
    char* chr = const_cast<char*>(k.data());
    while (!!(*chr))
    {
        memcpy(chr, lookup_table + *chr, 1);
        ++chr;
    }
    return k;
}

std::string fgrujic__vowelChange_for_body(std::string k) {
    for (
        char* chr = const_cast<char*>(k.data());
        *chr;
        *(chr++) = lookup_table[*chr])
        ;
    return k;
}
