
#include "bench.h"

#define SHORT_TEST    1

#if defined(SHORT_TEST)
    #define VOWEL_MEASURE(fn)      { \
        auto measurement = MEASURE(fn, "", "", "hello-world.txt"); \
        std::cout << measurement << std::endl; \
    }
#else
    #define VOWEL_MEASURE(fn)      { \
        auto measurement = MEASURE(fn, \
          "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam quis mi arcu. Sed efficitur, justo in eleifend vestibulum", \
          "L4r2m 3ps5m d4l4r s3t 1m2t, c4ns2ct2t5r 1d3p3sc3ng 2l3t. N5ll1m q53s m3 1rc5. S2d 2ff3c3t5r, j5st4 3n 2l23f2nd v2st3b5l5m", \
          "lorem.txt"); \
        std::cout << measurement << std::endl; \
    }
#endif

#include "azdravkovic.h"
#include "dshamrikov.h"
#include "fgrujic.h"
#include "mgavrilov.h"
#include "mjovanovic.h"
#include "mvidakovic.h"

int main()
{
    VOWEL_MEASURE(azdravkovic__vowelChange_test_swap);

    // todo: there's a small glitch in this one that makes it 
    // sometimes return the wrong value, we should wait for a fix :)
    VOWEL_MEASURE(dshamrikov__vowelChange);

    VOWEL_MEASURE(fgrujic__vowelChange);
    VOWEL_MEASURE(fgrujic__vowelChange_test_data_vs_cstr);
    VOWEL_MEASURE(fgrujic__vowelChange_test_memcpy);
    VOWEL_MEASURE(fgrujic__vowelChange_for_body);
    VOWEL_MEASURE(fgrujic__vowelChange_test_preinc);

    VOWEL_MEASURE(mgavrilov__vowelChange);
    VOWEL_MEASURE(mgavrilov__vowelChange_test_hotPaths);
    VOWEL_MEASURE(mgavrilov__vowelChange_test_map);
    VOWEL_MEASURE(mgavrilov__vowelChange_test_stdlib);

    VOWEL_MEASURE(mjovanovic__vowelChange_test_base);

    VOWEL_MEASURE(mvidakovic__vowelChange);

    return 0;
}
