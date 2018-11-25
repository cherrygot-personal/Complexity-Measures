#ifndef HALSTEAD_HEADER_H
#define HALSTEAD_HEADER_H

struct HalsteadMetric {
    unsigned int distOpr;
    unsigned int distOpd;
    unsigned int occurOpr;
    unsigned int occurOpd;

    unsigned int progLen;
    unsigned int progVoc;
    double progVol;
    double progDiff;
    double progEff;
    double langLevel;
    double progTime;
};

void initMetrics(struct HalsteadMetric*);

void calcMetrics(struct HalsteadMetric*, int, int, int, int);

struct HalsteadMetric getHalsteadMetrics(int, int, int, int);

#endif