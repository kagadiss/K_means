//
// Created by Administrator on 2023/7/27.
//

#ifndef KMEANS_POINT_H
#define KMEANS_POINT_H


#include <utility>
#include <cmath>
#include <iostream>

class Point {
public:
    Point() = default;
    Point(std::pair<double, double> point) : pointX(point.first), pointY(point.second) {}
    ~Point() = default;

    std::pair<double, double> getCoordinate() const;

    friend std::ostream& operator << (std::ostream& os, const Point& point) {
        os << point.pointX << " " << point.pointY;
        return os;
    }

    bool operator < (const Point& other) const {
        return this->pointX < other.pointX;
    }

    //欧拉距离
    double operator - (const Point& other) const {
        double disX = this->pointX - other.pointX;
        double disY = this->pointY - other.pointY;
        return sqrt(disX * disX + disY * disY);
    }

private:
    double pointX{0};
    double pointY{0};
};


#endif //KMEANS_POINT_H
