

#include "../include/QualityTester.h"
#include <iostream>
#include <iomanip>

using namespace std;

void QualityTester::addResult(const TestResult& test) {
    results.push_back(test);
}

bool QualityTester::isOverallPass() const {

    if (results.empty()) {
        return false;
    }

    for (const auto& test : results) {

        if (test.getResult() != "PASS") {
            return false;
        }
    }

    return true;
}

const vector<TestResult>& QualityTester::getResults() const {
    return results;
}

void QualityTester::displayResults() const {

    cout << "\n========== FERTILIZER TEST RESULTS ==========\n\n";

    cout << left
         << setw(15) << "Parameter"
         << setw(13) << "Standard"
         << setw(13) << "Tested"
         << setw(13) << "Deviation"
         << setw(13) << "Tolerance"
         << "Result\n";

    cout << string(80, '-') << "\n";

    cout << fixed << setprecision(2);

    for (const auto& test : results) {

        cout << left
             << setw(15) << test.getParameterName()
             << setw(13) << test.getStandardValue()
             << setw(13) << test.getTestedValue()
             << setw(13) << test.getDeviation()
             << setw(13) << test.getTolerance()
             << test.getResult() << "\n";
    }

    cout << "\nOverall Quality: "
         << (isOverallPass() ? "PASS" : "FAIL")
         << "\n";
}
