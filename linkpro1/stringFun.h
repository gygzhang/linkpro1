#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"PloyLink.h"

extern int pos;

double charToDouble(char p[]);

char** spliteByMark(char s[], char mark[]);

bool _compare(char str1[], char str2[]);

void ploy_getCoeAndExp(char node[], double* coefficient, double* expenent);

List ploy_resolve(char **s);

char* spliteByMark1(char s[], char mark[]);

void strcopy(char *a, char *b);



