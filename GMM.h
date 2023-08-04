/**
  ******************************************************************************
  * @file           : GMM.h
  * @author         : My opt
  * @brief          : None
  * @attention      : None
  * @date           : 2023/8/3
  ******************************************************************************
**/

#ifndef KMEANS_GMM_H
#define KMEANS_GMM_H

#include "Calculation.h"


class GMM : public Calculation {
public:
    GMM() = default;

    virtual ~GMM() override = default;

    void initCrowdPoint(int crowdCount) override;

    void execute() override;

private:
    std::vector<double> alpha;
    std::vector<Point> expect;
    std::vector<std::pair<std::pair<double, double>, std::pair<double, double>>> variance;

    double getProbabilityDensity();

    void sPointClassify();

    bool cPointMove();

    void displayCrowd() const override;
};


#endif //KMEANS_GMM_H
