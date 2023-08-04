//
// Created by Administrator on 2023/7/27.
//

#ifndef KMEANS_CALCULATION_H
#define KMEANS_CALCULATION_H

#include <map>
#include <vector>
#include "Point.h"


class Calculation {
public:
    Calculation() = delete;
    Calculation(std::vector<Point> samplePoint) : samplePoint(samplePoint){}
    ~Calculation() = default;

    void initCrowdPoint(int crowdCount);

    void execute();

private:
    std::vector<Point> samplePoint;
    std::map<Point, std::vector<Point>> crowdPoint;

    void sPointClassify();

    bool cPointMove();

    void displayCrowd() const;
};


#endif //KMEANS_CALCULATION_H
