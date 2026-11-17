

#include "../include/TestResult.h"
#include <cmath>

TestResult::TestResult(NutrientStandard standard, double tested) {

    parameterName = standard.getParameterName();
    standardValue = standard.getStandardValue();
    testedValue = tested;
    tolerance = standard.getTolerance();
    rule = standard.getRule();

    deviation = testedValue - standardValue;
    result = "NOT EVALUATED";
}

void TestResult::evaluate() {

    deviation = testedValue - standardValue;

    if (rule == "MAX") {

        // Tested value must not exceed the maximum limit.
        if (testedValue <= standardValue + tolerance) {
            result = "PASS";
        }
        else {
            result = "FAIL";
        }
    }
    else {

        // Absolute deviation must be within tolerance.
        if (std::abs(deviation) <= tolerance) {
            result = "PASS";
        }
        else {
            result = "FAIL";
        }
    }
}

string TestResult::getParameterName() const {
    return parameterName;
}

double TestResult::getStandardValue() const {
    return standardValue;
}

double TestResult::getTestedValue() const {
    return testedValue;
}

double TestResult::getDeviation() const {
    return deviation;
}

double TestResult::getTolerance() const {
    return tolerance;
}

string TestResult::getResult() const {
    return result;
}
