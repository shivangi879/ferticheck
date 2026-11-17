

#ifndef QUALITYTESTER_H
#define QUALITYTESTER_H

#include "TestResult.h"
#include <vector>
using namespace std;

class QualityTester {
private:
    vector<TestResult> results;

public:
    void addResult(const TestResult& test);

    bool isOverallPass() const;

    void displayResults() const;

    const vector<TestResult>& getResults() const;
};

#endif
