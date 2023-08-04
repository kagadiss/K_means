#include <fstream>
#include "Calculation.h"

constexpr int NUM_OF_CROWD = 3;

std::vector<Point> readData()
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

int main() {
    Calculation cal(std::move(readData()));

    cal.initCrowdPoint(NUM_OF_CROWD);

    cal.execute();

    return 0;
}
