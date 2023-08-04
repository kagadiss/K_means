//
// Created by Administrator on 2023/7/30.
//

#include "K_means.h"

static int iterTimes = 0;

void K_means::sPointClassify() {
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

bool K_means::cPointMove() {
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


void K_means::execute() {
    sPointClassify();
    while (cPointMove()) {
        sPointClassify();
        displayCrowd();
    }
}

void K_means::displayCrowd() const {
    std::cout << "------------------------ " << iterTimes << "th ------------------------" << std::endl;
    Calculation::displayCrowd();
}

