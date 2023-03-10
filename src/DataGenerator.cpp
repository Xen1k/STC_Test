#pragma once
#include "DataGenerator.h"

double DataGenerator::GetRandomDouble()
{
    double min = DBL_MIN;
    double max = DBL_MAX;
    return min + (double)std::rand() / RAND_MAX * (max - min);
}