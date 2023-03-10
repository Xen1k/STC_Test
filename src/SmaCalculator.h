#pragma once
#include <vector>

namespace SmaCalculator {
    /// <summary>
    /// Считает скользящую среднюю
    /// </summary>
    template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
    std::vector<T> GetSMA(std::vector<T>& inputData, int windowWidth)
    {
        if (inputData.size() < windowWidth)
        {
            std::vector<T> empty;
            return empty;
        }
        std::vector<T> smaValues(inputData.size() - windowWidth + 1);
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


}
