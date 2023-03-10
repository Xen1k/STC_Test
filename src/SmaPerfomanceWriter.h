#pragma once
#include <fstream>
#include <string>
#include "SmaCalculator.h"
#include "DataGenerator.h"

/// <summary>
/// Запускает тесты произовдительности и записывает в excel файл
/// </summary>
class SmaPerfomanceWriter
{
private:
    std::ofstream outData;
    /// <summary>
    /// Замеряет выполнение функции GetSMA в секундах для 1000000 входных данных с заданной шириной окна
    /// </summary>
    template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
    float DoPerfomanceTest(int windowWidth)
    {
        std::vector<T> input = DataGenerator::GenerateInputData<T>(1000000);
        auto testStartTime = clock();
        SmaCalculator::GetSMA(input, windowWidth);
        return float(clock() - testStartTime) / CLOCKS_PER_SEC;
    }
public:
    SmaPerfomanceWriter(std::string fileName = "perfomance.csv");
    /// <summary>
    /// Запускает и записывает тест произодительности sma для float и double для заданной ширины окна
    /// </summary>
    void WritePerfomanceForDoubleAndFloat(int windowWidth);
    ~SmaPerfomanceWriter();
};

