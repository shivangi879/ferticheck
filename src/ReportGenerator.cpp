

#include "../include/ReportGenerator.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ReportGenerator::generateReport(
    const Fertilizer& fertilizer,
    const QualityTester& tester) {

    ofstream file("reports/test_report.txt");

    if (!file.is_open()) {
        cout << "\nError: Could not create report.\n";
        cout << "Check whether the reports folder exists.\n";
        return;
    }

    file << fixed << setprecision(2);

    file << "============================================\n";
    file << "        FERTICHECK QUALITY TEST REPORT\n";
    file << "============================================\n\n";

    file << "Fertilizer ID : " << fertilizer.getID() << "\n";
    file << "Fertilizer    : " << fertilizer.getName() << "\n";
    file << "Manufacturer  : " << fertilizer.getManufacturer() << "\n\n";

    file << "              TEST RESULTS\n";
    file << "--------------------------------------------\n";

    file << left
         << setw(15) << "Parameter"
         << setw(12) << "Standard"
         << setw(12) << "Tested"
         << setw(12) << "Deviation"
         << setw(12) << "Tolerance"
         << "Result\n";

    file << "--------------------------------------------\n";

    for (const auto& test : tester.getResults()) {

        file << left
             << setw(15) << test.getParameterName()
             << setw(12) << test.getStandardValue()
             << setw(12) << test.getTestedValue()
             << setw(12) << test.getDeviation()
             << setw(12) << test.getTolerance()
             << test.getResult() << "\n";
    }

    file << "\nOVERALL QUALITY: "
         << (tester.isOverallPass() ? "PASS" : "FAIL")
         << "\n";

    file << "\nQUALITY INTERPRETATION:\n";

    if (tester.isOverallPass()) {
        file << "All tested parameters meet their configured limits.\n";
    }
    else {
        file << "One or more tested parameters do not meet their configured limits.\n";
    }

    file << "\nNOTE:\n";
    file << "This report evaluates only the parameters tested.\n";
    file << "Plant and soil suitability requires crop-specific and\n";
    file << "soil-specific agronomic assessment.\n";

    file << "\n============================================\n";
    file << "                END OF REPORT\n";
    file << "============================================\n";

    file.close();

    cout << "\nReport saved successfully!\n";
    cout << "Location: reports/test_report.txt\n";
}
