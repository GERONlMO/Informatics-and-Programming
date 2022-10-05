#ifndef _FUNC_H
#define _FUNC_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

struct Answer
{
    double result;
    double difference;
    double etalon;
    int count;
};

struct Answer finalResult;

long long Factorial(int N);

struct Answer sinTalor(double x, double eps, int N, int i);
struct Answer cosTalor(double x, double eps, int N, int i);
struct Answer expTalor(double x, double eps, int N, int i);
struct Answer arcctgTalor(double x, double eps, int N, int i);

#endif