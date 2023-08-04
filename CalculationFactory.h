#ifndef K_MEANS_CALCULATIONFACTORY_H
#define K_MEANS_CALCULATIONFACTORY_H

#include <memory>
#include <functional>
#include <unordered_map>
#include "Calculation.h"
#include "K_means.h"
#include "GMM.h"

static std::unordered_map<ALGORITHM_TYPE, std::function<std::unique_ptr<Calculation>()>> reflectMap = {{
        ALGORITHM_TYPE::K_MEANS, []()-> std::unique_ptr<Calculation> {
            return std::make_unique<K_means>();
        }}, {
        ALGORITHM_TYPE::GAUSSIAN_MIXTURE_MODEL, []()-> std::unique_ptr<Calculation> {
            return std::make_unique<GMM>();
        }}
};

std::unique_ptr<Calculation> createCalculation(ALGORITHM_TYPE ALGORITHM_CATEGORY)
{
    std::unique_ptr<Calculation> cal = nullptr;
    if (reflectMap.find(ALGORITHM_CATEGORY) != reflectMap.end()) {
        cal = reflectMap[ALGORITHM_CATEGORY]();
    } else {
        std::cout << "Unknown Algorithm" << std::endl;
    }
    return cal;
}


#endif //K_MEANS_CALCULATIONFACTORY_H
