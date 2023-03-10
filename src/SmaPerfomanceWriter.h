#pragma once
#include <fstream>
#include <string>
#include "SmaCalculator.h"
#include "DataGenerator.h"

/// <summary>
/// ��������� ����� ������������������ � ���������� � excel ����
/// </summary>
class SmaPerfomanceWriter
{
private:
    std::ofstream outData;
    /// <summary>
    /// �������� ���������� ������� GetSMA � �������� ��� 1000000 ������� ������ � �������� ������� ����
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
    /// ��������� � ���������� ���� ����������������� sma ��� float � double ��� �������� ������ ����
    /// </summary>
    void WritePerfomanceForDoubleAndFloat(int windowWidth);
    ~SmaPerfomanceWriter();
};

