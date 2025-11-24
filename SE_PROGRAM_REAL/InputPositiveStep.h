#pragma once

double ValidatenPositiveStep(double step) {
    if (step <= 0) {
        throw std::invalid_argument ("Input step which is > 0");
    }
    return step;
}