#include "randomizer.h"
#include <chrono>

Randomizer::Randomizer(double percent, QObject *parent)
    : QObject(parent), distribution(percent)
{
    generator = std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());
}

bool Randomizer::random()
{
    this->distribution.reset();
    return distribution(this->generator);
}

