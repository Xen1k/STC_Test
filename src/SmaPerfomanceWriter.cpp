#include "SmaPerfomanceWriter.h"

SmaPerfomanceWriter::SmaPerfomanceWriter(std::string fileName)
{
    outData.open(fileName);
    outData << "Window;Float;Double" << std::endl;
}

void SmaPerfomanceWriter::WritePerfomanceForDoubleAndFloat(int windowWidth)
{
    outData << std::to_string(windowWidth) << ";" <<
        std::to_string(DoPerfomanceTest<float>(windowWidth)) << ';';
    outData << std::to_string(DoPerfomanceTest<double>(windowWidth)) << std::endl;
}

SmaPerfomanceWriter::~SmaPerfomanceWriter()
{
    outData.close();
}
