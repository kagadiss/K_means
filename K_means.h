#ifndef K_MEANS_K_MEANS_H
#define K_MEANS_K_MEANS_H


#include "Calculation.h"

class K_means : public Calculation {
public:
    K_means() = default;

    ~K_means() override = default;

    void execute() override;

private:
    void sPointClassify();

    bool cPointMove();

    void displayCrowd() const override;
};


#endif //K_MEANS_K_MEANS_H
