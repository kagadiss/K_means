#include <random>
#include <queue>
#include "Calculation.h"

static int getRand(int border)
{
    std::random_device rd;
    std::default_random_engine eng(rd());

    std::uniform_int_distribution<int> distInt(0, border);
    return distInt(eng);
}

void Calculation::initCrowdPoint(int crowdCount) {
    if (crowdCount > samplePoint.size()) {
        std::cout << "Crowd size error" <<  std::endl;
        return;
    }
    std::vector<bool> isUsed(samplePoint.size());
    while (crowdCount) {
        int randPos = getRand(samplePoint.size());
        if (!isUsed[randPos]) {
            crowdPoint[samplePoint[randPos]] = {};
            --crowdCount;
        }
    }
}

void Calculation::init(std::vector<Point>&& points, int crowdCount) {
    samplePoint = std::move(points);

    initCrowdPoint(crowdCount);
}


void Calculation::displayCrowd() const {
    for (auto& [cPoint, vec] : crowdPoint) {
        std::cout << "Crowd center is: (" << cPoint << ")" << std::endl;
        std::cout << "Sample: ";
        for (auto& sPoint : vec) {
            std::cout << '(' << sPoint << ") ";
        }
        std::cout << std::endl;
    }
}
