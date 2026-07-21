
#include <iostream>
#include <chrono>
#include "StringUtils/StringUtils.h"

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
using fSec = std::chrono::duration<float>;

std::string GenerateString(const std::string& InWordTemplate,
                           const std::string& InDelim,
                           int InNumWords);

int main()
{
    const int numOfWords = 1000000;
    std::string wordTemplate{"VeryLongWordBecauseWhyNot"};
    std::string sequence = std::move(GenerateString(wordTemplate, " ", 1000000));

    TimePoint tpStart = std::chrono::high_resolution_clock::now();

    auto array = StringUtils::Tokenize(sequence, " ");

    TimePoint tpEnd = std::chrono::high_resolution_clock::now();

    fSec seconds = tpEnd - tpStart;

    std::cout << seconds.count() << " s" << std::endl;

    return 0;
}

std::string GenerateString(const std::string& InWordTemplate,
                           const std::string& InDelim,
                           int InNumWords)
{
    if (InNumWords <= 0 || InWordTemplate.length() == 0 || InDelim.length() == 0)
    {
        return {};
    }

    std::string sequence{};
    sequence.reserve(InNumWords * (InWordTemplate.length() + InDelim.length()) - InDelim.length());

    for(int i = 0; i < InNumWords; i++)
    {
        sequence += InWordTemplate;

        if (i != InNumWords -1)
        {
            sequence += InDelim;
        }
    }

    return sequence;
}
