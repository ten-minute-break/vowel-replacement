#pragma once

#include <chrono> 
#include <iostream>
#include <iomanip>
#include <functional>
#include <cassert>
#include <limits>
#include <algorithm>
#include <string>
#include <fstream>
#include <streambuf>
#include <thread>
#include <string>
#include <vector>

using namespace std;

template<typename ResultType>
struct Measurement
{
    std::string name;
    ResultType result;

    double averageTime;
    double medianTime;
    double minTime;
    double lowOutTime;
    double maxTime;
    double hiOutTime;

    Measurement(std::string name, ResultType result, double average, double median, double min, double lowOut, double max, double hiOut)
        : name{ name }
        , result{ result }
        , averageTime{ average }
        , medianTime{ median }
        , minTime{ min }
        , lowOutTime{ lowOut }
        , maxTime{ max }
        , hiOutTime{ hiOut }
    {}

    template<typename ResultTypeT>
    friend std::ostream& operator<<(std::ostream& os, Measurement<ResultTypeT>& self);
};

void labelTime(std::ostream& os, std::string label, double dt)
{
    os << label << "  " << std::fixed << std::setprecision(10) << dt << "s" << std::endl;
}

template<typename ResultType>
std::ostream& operator<<(std::ostream& os, Measurement<ResultType>& self)
{
    os << "+------------------------------+" << std::endl;
    os << "   Testing: " << self.name << std::endl;
    os << "+------------------------------+" << std::endl;
    labelTime(os, "   Min: ", self.minTime);
    labelTime(os, "   Low: ", self.lowOutTime);
    labelTime(os, "   Avg: ", self.averageTime);
    labelTime(os, "   Med: ", self.medianTime);
    labelTime(os, "   Hi:  ", self.hiOutTime);
    labelTime(os, "   Max: ", self.maxTime);
    os << "+-----------------------------+" << std::endl;
    os << std::endl;
    return os;
}

template<typename ResultType>
Measurement<ResultType> measure(const char* name, const std::function<ResultType(std::string)>& fn, std::string input, std::string test, ResultType result, const int samples = 10000)
{
    std::ifstream t(input);
    std::string fullTest;

    t.seekg(0, std::ios::end);
    fullTest.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    fullTest.assign((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());

    assert(samples >= 1000);
    if (fn(test) != result)
    {
        std::cout << name << " failed:\n INPUT  [" << test << "]\n OUTPUT [" << fn(test) << "]\n EXPECT [" << result << "]" << std::endl;
        return Measurement<ResultType>{name, result, 0, 0, 0, 0, 0, 0 };
    }

    std::ios_base::sync_with_stdio(false);

    std::vector<double> entries{};
    entries.resize(samples);
    double midtime{ 0.0 };
    double mintime{ std::numeric_limits<double>::max() };
    double maxtime{ std::numeric_limits<double>::min() };

    for (int i = 0; i < samples; ++i)
    {
        auto start = chrono::high_resolution_clock::now();
        fn(fullTest);
        auto end = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<chrono::nanoseconds>(end - start).count() * 1e-9;

        midtime += time;
        if (time < mintime) mintime = time;
        if (time > maxtime) maxtime = time;
        entries[i] = time;

        std::this_thread::yield();
    }

    std::sort(entries.begin(), entries.end());
    auto q1 = entries[samples / 100];
    auto q3 = entries[99 * samples / 100];

    std::ios_base::sync_with_stdio(true);
    return Measurement<ResultType>{name, result, midtime / (double)samples, entries[samples / 2], mintime, q1, maxtime, q3};
}

#define MEASURE(func, test, result, input) measure<std::string>(#func, func, input, test, result)
