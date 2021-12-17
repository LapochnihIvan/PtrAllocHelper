#include <unistd.h>

#include <cstring>

#include "PtrAllocHelper.h"

int main()
{
    PtrAllocHelper<char> ptrAllocHelper(2, 14);

    char*** strs;

    ptrAllocHelper.memAlloc(strs);

    for (std::uint8_t numStrPtrPtr(0); numStrPtrPtr < 2; numStrPtrPtr++)
    {
        std::strcpy(strs[numStrPtrPtr][0], "Hello world! ");
        std::strcpy(strs[numStrPtrPtr][1], "Hello world!\n");
    }

    for (std::uint8_t numStrPtrPtr(0); numStrPtrPtr < 2; numStrPtrPtr++)
    {
        for (std::uint8_t numStrPtr(0); numStrPtr < 2; numStrPtr++)
        {
            ::write(1, strs[numStrPtrPtr][numStrPtr], 13);
        }
    }

    ptrAllocHelper.memFree(strs);

    return 0;
}
