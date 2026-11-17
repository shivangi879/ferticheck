

#ifndef NUTRIENTSTANDARD_H
#define NUTRIENTSTANDARD_H

#include <string>
using namespace std;

class NutrientStandard {
private:
    string parameterName;
    double standardValue;
    double tolerance;
    string rule;

public:
    NutrientStandard();
    NutrientStandard(string name, double standard,
                     double tol, string comparisonRule);

    string getParameterName() const;
    double getStandardValue() const;
    double getTolerance() const;
    string getRule() const;
};

#endif
