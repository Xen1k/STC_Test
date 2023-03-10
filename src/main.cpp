#include <iostream>
#include <ctime>
#include "SmaPerfomanceWriter.h"

int main()
{
    srand(time(0));
    SmaPerfomanceWriter perfomanceWriter;

    for (int i = 4; i <= 128; i *= 2)
    {
        std::cout << "Tesing " << i << " window size" << std::endl;
        perfomanceWriter.WritePerfomanceForDoubleAndFloat(i);
    }
    std::cout << "Perfomace tests completed" << std::endl;
    system("pause");
    return 0;
}