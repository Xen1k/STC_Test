#include "SmaPerfomanceWriter.h"

using namespace SimpleXlsx;

SmaPerfomanceWriter::SmaPerfomanceWriter()
{
    book = new SimpleXlsx::CWorkbook("Perfomance");
    sheet = &book->AddSheet("Data");
    chartSheet = &(book->AddChartSheet("Line Chart", CHART_LINEAR));
    onSheetChart = &(book->AddChart(*sheet, DrawingPoint(10, 10), DrawingPoint(20, 20)));
    onSheetChart->SetLegendPos(CChart::POS_BOTTOM);
}

void SmaPerfomanceWriter::MeasurePerfomanceForDoubleAndFloat(int windowWidth)
{
    windowWidths.push_back(windowWidth);
    floatPerfomances.push_back(DoPerfomanceTest<float>(windowWidth));
    doublePerfomances.push_back(DoPerfomanceTest<double>(windowWidth));
}

void SmaPerfomanceWriter::AppendPlot(std::string name, int startIndexY, std::vector<SimpleXlsx::CellDataDbl> &data)
{
    CChart::Series series;
    series.valAxisFrom = CellCoord(startIndexY, 1);
    series.valAxisTo = CellCoord(startIndexY, data.size());
    series.valSheet = sheet;
    series.title = name;
    series.JoinType = CChart::Series::joinSmooth;
    chartSheet->Chart().AddSeries(series);
    onSheetChart->AddSeries(series);
}

void SmaPerfomanceWriter::PlotData(std::string fileName)
{
    sheet->AddRow(windowWidths).AddRow(floatPerfomances).AddRow(doublePerfomances);

    AppendPlot("Float", 2, floatPerfomances);
    AppendPlot("Double", 3, doublePerfomances);

    book->Save("Perfomance.xlsx");
}

SmaPerfomanceWriter::~SmaPerfomanceWriter()
{
    delete book;
}
