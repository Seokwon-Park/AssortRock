﻿#include <iostream>
#include <cstdarg>

const int IntMaxCount = 10;
const int ParameterInter = 8;

int NumberCount(int _Value)
{
    int Result = 0;
    while (_Value)
    {
        Result++;
        _Value /= 10;   
    }
    return Result;
}

void NumberToString(char* Buffer, int BufferSize, int _Value)
{
    int Size = NumberCount(_Value);

    for (int i = Size - 1; i >= 0; i--)
    {
        Buffer[i] = _Value % 10 + '0';
        _Value /= 10;
    }
}

int MyPrintf(const char* const _Ptr, ...)
{
    __int64 FAdd = reinterpret_cast<__int64>(&_Ptr);

    va_list args;
    va_start(args, _Ptr);
    int ChCount = 0;

    while (_Ptr[ChCount])
    {
        char Ch = _Ptr[ChCount];

        if (Ch == '%')
        {
            Ch = _Ptr[ChCount + 1];
            int tmp = 0;
            switch (Ch)
            {
            case 'd':
            {
                //int* Ptr = reinterpret_cast<int*>(FAdd += ParameterInter);
                //int ConvertValue = *Ptr;
                int ConvertValue = va_arg(args, int);
                char Arr[IntMaxCount] = {};
                NumberToString(Arr, IntMaxCount, ConvertValue);
                MyPrintf(Arr);
                break;
            }
            case 'c':
            {

            }
            default:
                break;
            }
            ChCount += 2;
        }

        putchar(_Ptr[ChCount]);
        ChCount++;
    }
    va_end(args);
    return ChCount;
}

int main()
{
    // MyPrintf("AA BB CC");

    MyPrintf("Number : %d %d\n", 1231, 3333);

    return 0;
}
