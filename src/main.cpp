#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <ctime>


/// <summary>
/// Возвращает случайное число с плавающей запятой
/// </summary>
template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
T GetRandomFloatingNumber()
{
    T min = FLT_MIN;
    T max = FLT_MAX;
    return min + (T)std::rand() / RAND_MAX * (max - min);
}

/// <summary>
/// Генерирует заданное количество чисел с плавающей запятой
/// </summary>
template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
std::vector<T> GenerateInputData(int numOfElements)
{
    std::vector<T> v(numOfElements);
    std::generate(v.begin(), v.end(), GetRandomFloatingNumber<T>);
    return v;
}


/// <summary>
/// Считает скользящую среднюю
/// </summary>
template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
std::vector<T> GetSMA(std::vector<T>& inputData, int windowWidth)
{
    if (inputData.size() < windowWidth)
    {
        std::vector<double> empty;
        return empty;
    }
    std::vector<double> smaValues(inputData.size() - windowWidth + 1);
    double periodSum = 0.f;
    int index = 0;
    int outputIndex = 0;
    for (; index < windowWidth; ++index)
    {
        periodSum += inputData[index];
    }
    for (; index < inputData.size(); ++index, ++outputIndex)
    {
        smaValues[outputIndex] = periodSum / windowWidth;
        periodSum -= inputData[index - windowWidth];
        periodSum += inputData[index];
    }
    smaValues[outputIndex] = periodSum / windowWidth;
    return smaValues;
}

int main()
{

    std::srand(unsigned(std::time(nullptr)));
    std::vector<double> input = GenerateInputData<double>(1000000);
    std::vector<double> res = GetSMA(input, 2);

    return 0;
}