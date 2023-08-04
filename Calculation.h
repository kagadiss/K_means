#ifndef KMEANS_CALCULATION_H
#define KMEANS_CALCULATION_H

#include <map>
#include <vector>
#include "Point.h"

enum class ALGORITHM_TYPE {
    K_MEANS,
    GAUSSIAN_MIXTURE_MODEL
};

class Calculation {
public:
    Calculation() = default;

    virtual ~Calculation() = default;

    void init(std::vector<Point>&& vector, int crowdCount);

    virtual void initCrowdPoint(int crowdCount);

    virtual void execute() = 0;

protected:
    std::vector<Point> samplePoint;
    std::map<Point, std::vector<Point>> crowdPoint;

    virtual void displayCrowd() const;
};


#endif //KMEANS_CALCULATION_H
