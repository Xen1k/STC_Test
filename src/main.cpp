#include <iostream>
#include <ctime>
#include "SmaPerfomanceWriter.h"

int main() 
{
    srand(time(0));
    SmaPerfomanceWriter perfomanceWriter;

    for (int i = 4; i <= 128; i *= 2)
        perfomanceWriter.WritePerfomanceForDoubleAndFloat(i);

    return 0;
}