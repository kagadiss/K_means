#include <fstream>
#include "CalculationFactory.h"

constexpr int NUM_OF_CROWD = 3;

ALGORITHM_TYPE ALGORITHM_CATEGORY = ALGORITHM_TYPE::K_MEANS;

static std::vector<Point> readData()
{
    std::ifstream fin;
    fin.open("./sample.txt");
    std::vector<Point> points;
    double x, y;
    while (fin >> x >> y) {
        Point point({x, y});
        points.emplace_back(point);
    }
    return points;
}

int main()
{
    auto cal = createCalculation(ALGORITHM_CATEGORY);

    cal->init(readData(), NUM_OF_CROWD);

    cal->execute();

    return 0;
}
