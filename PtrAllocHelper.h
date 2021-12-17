#ifndef PTRALLOCHELPER_PTRALLOCHELPER_H
#define PTRALLOCHELPER_PTRALLOCHELPER_H

#include <cstdint>

template<typename FinalType>
class PtrAllocHelper
{
public:
    explicit PtrAllocHelper(const std::uint8_t&& everyPtrSize = 1) :
            mEveryPtrSize(everyPtrSize),
            mFinalPtrSize(everyPtrSize)
    {

    }

    explicit PtrAllocHelper(const std::uint8_t&& everyPtrSize,
                            const std::uint8_t&& finalPtrSize) :
            mEveryPtrSize(everyPtrSize),
            mFinalPtrSize(finalPtrSize)
    {

    }

    template<typename PtrType>
    void
    memAlloc(PtrType**& ptr)
    {
        ptr = new PtrType*[mEveryPtrSize];
        for (std::uint8_t numPtr(0); numPtr < mEveryPtrSize; numPtr++)
        {
            memAlloc(ptr[numPtr]);
        }
    }

    template<typename PtrType>
    void
    memAlloc(PtrType*& ptr)
    {
        ptr = new FinalType[mFinalPtrSize];
    }

    template<typename PtrType>
    void
    memFree(PtrType**& ptr)
    {
        for (std::uint8_t numPtr(0); numPtr < mEveryPtrSize; numPtr++)
        {
            memFree(ptr[numPtr]);
        }

        delete[] ptr;
    }

    template<typename PtrType>
    void
    memFree(PtrType*& ptr)
    {
        delete[] ptr;
    }

private:
    const std::uint8_t mEveryPtrSize;
    const std::uint8_t mFinalPtrSize;
};

#endif //PTRALLOCHELPER_PTRALLOCHELPER_H
