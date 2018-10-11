#include"stringFun.h"
#include<string.h>
#include"PloyLink.h"

int pos = 0;
int pos1 = 0;

double charToDouble(char p[]) {
	double re = 0;
	int i;
	bool isNegetive = false;
	int sign;
	if (p == NULL) return 0;

	if (p[0] == '-') {
		isNegetive = true;
		i = 1;
		sign = -1;
	}
	else {
		isNegetive = false;
		i = 0;
		sign = 1;
	}

	for (; i < strlen(p); i++) {
		re = re * 10 + p[i] - '0';
	}
	return re * sign;
}

char** spliteByMark(char s[], char mark[]) {
	char *pp[200];
	char *p;
	p = s;
	int len = strlen(mark);
	while (p) {
		int j = 0;

		for (int i = pos; i < strlen(&s[pos]) + pos; i++) {
			p = &s[pos];
			if (_compare(&s[i], mark)) {
				s[i] = '\0';
				pos = i + len;
				pp[j] = p;
				j++;
			}
		}
		pp[j] = p;
		p = NULL;
	}
	return pp;
}

bool _compare(char str1[], char str2[]) {
	int len = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);
	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}

void ploy_getCoeAndExp(char node[], double* coefficient, double* expenent) {
	char mm[] = "*x^";
	char* p = (char*)malloc(300);
	int postion = 0;
	p = node;
	puts(node);
	for (int i = 0; i < strlen(&node[i]); i++) {
		if (_compare(&node[i], mm)) {
			node[i] = '\0';
			*coefficient = charToDouble(p);
			postion = i + strlen(mm) + 1;
			*expenent = charToDouble(&p[i + 3]);
			printf("%g,%g\n", *coefficient, *expenent);
			return;
		}
	}
}

List ploy_resolve(char** s) {
	for (int i = 0; i < 4; i++) {
		//s[i ] = s[i] + 8;
		//printf("address=%p\n", s[i+1]);
	}
	s[1] = s[0] + 8;
	puts(*s++);
	puts(*s++);
	puts(*s++);
	puts(*s++);
	double c, e;
	List list;
	char r[300];
	//r = NULL;
	int len = sizeof(s);
	InitializeList(&list);
	/*for (int i = 0; i < len; i++) {
		//puts(s[i]);
		strcopy(s[i], r);
		ploy_getCoeAndExp(s[i], &c, &e);
		printf("(%g--%g)\n", c, e);
	}*/
	//puts(s[2]);
	PrintTheList(list);
	return list;
}


char* spliteByMark1(char s[], char mark[]) {
	//puts(s);
	char *p;
	p = s;
	int len = strlen(mark);
	p = &s[pos1];
	for (int i = pos; i < strlen(&s[pos1]) + pos1; i++) {
		if (_compare(&s[i], mark)) {
			s[i] = '\0';
			pos1 = i + len;
			return p;
		}
	}
	return NULL;
}

void strcopy(char *a, char* b) {
	int i = 0;
	int len = strlen(a);
	for (; i < len; i++) {
		*b++ = a[i];
	}
	*b = '\0';
}