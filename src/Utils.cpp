#include <cstdlib>

#include "Utils.h"

int
getRandBelow(int Max)
{
    int RandValue = std::rand();
    return RandValue / ((RAND_MAX) / Max);
}
