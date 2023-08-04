//
// Created by Administrator on 2023/7/27.
//

#include <random>
#include <queue>
#include "Calculation.h"

static int iterTimes = 0;

int getRand(int border)
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

void Calculation::sPointClassify() {
    for (auto &sPoint : samplePoint) {
        Point targetPoint;
        double minDistance = 1e18;
        for (auto &[cPoint, vec] : crowdPoint) {
            if (cPoint - sPoint < minDistance) {
                minDistance = cPoint - sPoint;
                targetPoint = cPoint;
            }
        }
        crowdPoint[targetPoint].emplace_back(sPoint);
    }
}

bool Calculation::cPointMove() {
    std::map<Point, std::vector<Point>> tmpCrowd;
    for (auto &[cPoint, vec] : crowdPoint) {
        double avgX = 0;
        double avgY = 0;
        for(auto &point : vec) {
            auto [x, y] = point.getCoordinate();
            avgX += x;
            avgY += y;
        }
        avgX /= vec.size();
        avgY /= vec.size();
        Point tmpPoint({avgX, avgY});
        tmpCrowd[tmpPoint] = {};
    }

    int count = 0;
    for (auto [cPoint, vec] : crowdPoint) {
        if (tmpCrowd.find(cPoint) != tmpCrowd.end()) {
            ++count;
        }
    }
    crowdPoint = std::move(tmpCrowd);
    ++iterTimes;
    return count != crowdPoint.size();
}

void Calculation::displayCrowd() const {
    std::cout << "------------------ " << iterTimes << "th ------------------" << std::endl;
    for (auto& [cPoint, vec] : crowdPoint) {
        std::cout << "Crowd center is: (" << cPoint << ")" << std::endl;
        std::cout << "Sample: ";
        for (auto& sPoint : vec) {
            std::cout << '(' << sPoint << ") ";
        }
        std::cout << std::endl;
    }
}

void Calculation::execute() {
    sPointClassify();
    while (cPointMove()) {
        sPointClassify();
        displayCrowd();
    }
}

