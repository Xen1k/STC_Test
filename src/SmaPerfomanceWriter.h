#pragma once
#include <fstream>
#include <string>
#include "SmaCalculator.h"
#include "DataGenerator.h"
#include <Xlsx/Chart.h>
#include <Xlsx/Chartsheet.h>
#include <Xlsx/Workbook.h>

/// <summary>
/// Запускает тесты произовдительности и записывает в excel файл
/// </summary>
class SmaPerfomanceWriter
{
private:
    // Книга, лист, область диаграммы и построения excel
    SimpleXlsx::CWorkbook *book;
    SimpleXlsx::CWorksheet *sheet;
    SimpleXlsx::CChartsheet *chartSheet;
    SimpleXlsx::CChart *onSheetChart;

    std::vector<SimpleXlsx::CellDataDbl> windowWidths;
    std::vector<SimpleXlsx::CellDataDbl> doublePerfomances;
    std::vector<SimpleXlsx::CellDataDbl> floatPerfomances;
    /// <summary>
    /// Замеряет выполнение функции GetSMA в секундах для 1000000 входных данных с заданной шириной окна
    /// </summary>
    template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
    float DoPerfomanceTest(int windowWidth)
    {
        std::vector<T> input = DataGenerator::GenerateInputData<T>(1000000);
        auto testStartTime = clock();
        SmaCalculator::GetSMA(input, windowWidth);
        return float(clock() - testStartTime) / CLOCKS_PER_SEC;
    }

    /// <summary>
    /// Добавляет новый график по заданным данным
    /// </summary>
    void AppendPlot(std::string name, int startIndexY, std::vector<SimpleXlsx::CellDataDbl> &data);

public:
    SmaPerfomanceWriter();
    void PlotData(std::string fileName = "Perfomance");
    /// <summary>
    /// Запускает и записывает в вектора тест произодительности sma для float и double для заданной ширины окна
    /// </summary>
    void MeasurePerfomanceForDoubleAndFloat(int windowWidth);
    ~SmaPerfomanceWriter();
};
