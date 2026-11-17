

#ifndef TESTRESULT_H
#define TESTRESULT_H

#include "NutrientStandard.h"
#include <string>
using namespace std;

class TestResult {
private:
    string parameterName;
    double standardValue;
    double testedValue;
    double deviation;
    double tolerance;
    string rule;
    string result;

public:
    TestResult(NutrientStandard standard, double tested);

    void evaluate();

    string getParameterName() const;
    double getStandardValue() const;
    double getTestedValue() const;
    double getDeviation() const;
    double getTolerance() const;
    string getResult() const;
};

#endif
