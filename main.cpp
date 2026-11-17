
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "include/Fertilizer.h"
#include "include/NutrientStandard.h"
#include "include/TestResult.h"
#include "include/QualityTester.h"
#include "include/ReportGenerator.h"

using namespace std;

int main() {

    cout << "============================================\n";
    cout << "       FERTICHECK FERTILIZER TESTING\n";
    cout << "============================================\n";

    // 1. Enter fertilizer details

    string id, name, manufacturer;

    cout << "\nEnter Fertilizer ID: ";
    getline(cin, id);

    cout << "Enter Fertilizer Name: ";
    getline(cin, name);

    cout << "Enter Manufacturer Name: ";
    getline(cin, manufacturer);

    if (id.empty() || name.empty() || manufacturer.empty()) {
        cout << "\nError: Details cannot be empty.\n";
        return 1;
    }

    Fertilizer fertilizer(id, name, manufacturer);

    // 2. Load standards from file

    ifstream standardFile("data/standards.txt");

    if (!standardFile.is_open()) {
        cout << "\nError: Cannot open standards.txt\n";
        return 1;
    }

    vector<NutrientStandard> standards;

    string line, parameter, rule;
    double standardValue, tolerance;

    while (getline(standardFile, line)) {

        if (line.empty() || line[0] == '#') {
            continue;
        }

        istringstream row(line);

        if (!(row >> parameter >> standardValue
                   >> tolerance >> rule)) {

            cout << "\nInvalid line in standards.txt:\n"
                 << line << "\n";

            return 1;
        }

        if (standardValue < 0 || tolerance < 0 ||
            (rule != "RANGE" && rule != "MAX")) {

            cout << "\nInvalid standard for "
                 << parameter << "\n";

            return 1;
        }

        standards.emplace_back(
            parameter, standardValue, tolerance, rule
        );
    }

    standardFile.close();

    if (standards.empty()) {
        cout << "\nNo standards available.\n";
        return 1;
    }

    // 3. Enter laboratory test values

    QualityTester tester;

    cout << "\n========== LABORATORY TESTING ==========\n";

    for (const auto& standard : standards) {

        double testedValue;

        cout << "\nParameter: "
             << standard.getParameterName();

        cout << "\nStandard Value: "
             << standard.getStandardValue() << "%";

        cout << "\nEnter Tested Value (%): ";

        if (!(cin >> testedValue) || testedValue < 0) {
            cout << "\nInvalid test value.\n";
            return 1;
        }

        // 4. Calculate and evaluate

        TestResult test(standard, testedValue);

        test.evaluate();

        tester.addResult(test);
    }

    // 5. Display final results

    tester.displayResults();

    // 6. Generate report

    ReportGenerator::generateReport(fertilizer, tester);

    cout << "\nFertiCheck testing completed successfully.\n";

    return 0;
}

