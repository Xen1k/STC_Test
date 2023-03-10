#pragma once
#include <vector>
#include <algorithm>

namespace DataGenerator {
    /// <summary>
    /// ¬озвращает случайный double
    /// </summary>
    double GetRandomDouble();

    /// <summary>
    /// √енерирует заданное количество чисел с плавающей зап€той
    /// </summary>
    template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
    std::vector<T> GenerateInputData(int numOfElements)
    {
        std::vector<T> v(numOfElements);
        std::generate(v.begin(), v.end(), GetRandomDouble);
        return v;
    }
}