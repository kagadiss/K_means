/**
  ******************************************************************************
  * @file           : GMM.cpp
  * @author         : My opt
  * @brief          : None
  * @attention      : None
  * @date           : 2023/8/3
  ******************************************************************************
  */

#include "GMM.h"


void GMM::initCrowdPoint(int crowdCount) {
    int num = crowdCount;
    double div = 1 / num;
    Calculation::initCrowdPoint(crowdCount);
    alpha.resize(num, div);

    for (auto &[crowdPoint, vec] : crowdPoint) {
        expect.emplace_back(crowdPoint);
    }
}

void GMM::execute() {

}

