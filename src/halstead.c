#include <math.h>
#include "halstead.h"

void initMetrics(struct HalsteadMetric *metric) {
    (*metric).distOpd =
    (*metric).distOpr =
    (*metric).occurOpd =
    (*metric).occurOpr =
    (*metric).progLen =
    (*metric).progVoc = 0;

    (*metric).langLevel =
    (*metric).progDiff =
    (*metric).progEff =
    (*metric).progTime = 
    (*metric).progVol = 0.0;
}

struct HalsteadMetric getHalsteadMetrics(int n1, int n2, int N1, int N2) {
    struct HalsteadMetric metric;

    initMetrics(&metric);
    calcMetrics(&metric, n1, n2, N1, N2);

    return metric;
}

void calcMetrics(struct HalsteadMetric *metric, int n1, int n2, int N1, int N2) {
    (*metric).distOpd = n2;
    (*metric).distOpr = n1;
    (*metric).occurOpd = N2;
    (*metric).occurOpr = N1;

    (*metric).progLen = N1 + N2;
    (*metric).progVoc = n1 + n2;
    (*metric).progVol = (N1 + N2) * log((n1 + n2)) / log(2);
    (*metric).progDiff = ((float)n1 / 2) * ((float)N2 / n2);
    (*metric).progEff = (*metric).progDiff * (*metric).progVol;
    (*metric).langLevel = 1 / (*metric).progDiff;
    (*metric).progTime = (*metric).progEff / 18;
}