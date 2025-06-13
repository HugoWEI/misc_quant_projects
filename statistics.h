#ifndef __STATISTICS_H
#define __STATISTICS_H

#include <cmath>
#include <vector>

class StatisticalDistribution {
    public:
    StatisticalDistribution();
    virtual ~StatisticalDistribution();

    virtual double pdf(const double& x) const = 0;
    virtual double cdf(const double& x) const = 0;

    virtual double inv_cdf(const double& quantile) const = 0;

    virtual double mean() const = 0;
    virtual double var() const = 0;
    virtual double stdev() const = 0;

    virtual void random_draws(const std::vector<double>& uniform_draws, std::vector<double>& dist_draws) = 0;
};

#endif

class StandardNormalDistribution : public StatisticalDistribution {
    public:
    StandardNormalDistribution();
    virtual ~StandardNormalDistribution();

    virtual double pdf(const double& x) const;
    virtual double cdf(const double& x) const;

    virtual double inv_cdf(const double& quantile) const;

    virtual double mean() const;
    virtual double var() const;
    virtual double stdev() const;

    virtual void random_draws(const std::vector<double>& uniform_draws, std::vector<double>& dist_draws);
};