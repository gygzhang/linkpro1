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

void strcopy(const char *a, char *b);

List aaaaaaa(char* p);

char* makeup(char* p);

void arr_insert(char *p,char* t);

void arr_add(char* p);

void insert_by_postion(char* p, char t, int pos);

void insert_before_minus(char*p);

int  count(char *p);

void print_int(int a);

void print_2darr(char**);

void print_1darr(char *);

void insert_chars(char*, char*,int pos);

bool isLastNode(char* p);

void test(char* p);



