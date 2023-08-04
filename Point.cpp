//
// Created by Administrator on 2023/7/27.
//

#include "Point.h"

std::pair<double, double> Point::getCoordinate() const {
    return std::pair<double, double>(pointX, pointY);
}