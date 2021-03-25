# vowel-replacement

Task: Replace AEIOU with 12345 as optimally as possible!

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

# Note

The benchmark utility used in `main.cpp` will run the program for several thousand runs, and (for the long runs) do some pre-validation of inputs, to check whether the submitted functions actually return the correct output. The values output by the benchmark include:

- min: the real minimal time measured with N (=10000) samples
- low: the 100th lowest time - useful to show how many samplings were actually freaks of nature
- avg: average time - useful to show how fast in general our algorithm is
- med: median time - the midpoint of the sorted time results, useful to distinguish when the average times are close
- hi:  the 100th highest time - useful to show how many samplings were actually your CPU dying
- max: the real maximal time measured with N samples

Remember that the submitted code samples **aren't** representative of anything except for that person's will to try out things and experiment with random things. This is a great chance to test out wild theories that just might work, so give it a chance! :)

# Current fastest

```
+------------------------------+
   Testing: fgrujic__vowelChange_test_preinc
+------------------------------+
   Min:   0.0001130000s
   Low:   0.0001132000s
   Avg:   0.0001379598s
   Med:   0.0001217000s
   Hi:    0.0003348000s
   Max:   0.0025183000s
+-----------------------------+
```

# Lessons learnt

Using a pre-built lookup table is the way to go! There are minor edge-cases to the implementation, and the details can be tweaked (we've spent a lot of time playing around with different `fgrujic` variants, go toss a look there!) for optimal performance. The really funky write-code-inside-the-`for`-body was marginally faster than a `while` loop on some compilers -- a single `mov` instruction more!

Going for a non-lookup table _can_ be quite fast, but the compiler can't warm up the codepaths as much, all but guaranteeing a noticable difference.

Exotic solutions usually turn sour really quickly and sometimes you have to remember what your intention really was, so don't leave them over the weekend outside the fridge.

Using a map is _really_ slow, even though it is what most people first think of.
