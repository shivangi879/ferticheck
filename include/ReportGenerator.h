

#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "Fertilizer.h"
#include "QualityTester.h"

class ReportGenerator {
public:
    static void generateReport(
        const Fertilizer& fertilizer,
        const QualityTester& tester
    );
};

#endif
