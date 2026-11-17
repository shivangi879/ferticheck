

#include "../include/NutrientStandard.h"

NutrientStandard::NutrientStandard() {
    parameterName = "";
    standardValue = 0;
    tolerance = 0;
    rule = "RANGE";
}

NutrientStandard::NutrientStandard(
    string name, double standard,
    double tol, string comparisonRule) {

    parameterName = name;
    standardValue = standard;
    tolerance = tol;
    rule = comparisonRule;
}

string NutrientStandard::getParameterName() const {
    return parameterName;
}

double NutrientStandard::getStandardValue() const {
    return standardValue;
}

double NutrientStandard::getTolerance() const {
    return tolerance;
}

string NutrientStandard::getRule() const {
    return rule;
}
