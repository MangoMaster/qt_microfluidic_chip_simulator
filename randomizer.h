#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <QObject>
#include <random>

class Randomizer : public QObject
{
    Q_OBJECT
public:
    explicit Randomizer(double percent = 0.5, QObject *parent = nullptr);
    bool random();

signals:

public slots:

private:
    std::mt19937 generator;
    std::bernoulli_distribution distribution;
};

#endif // RANDOMIZER_H
