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

List ploy_resolve(char** k) {
	puts("\nploy_reslove:\n");
	printf("%s", (k[0]));
	printf("%s", (k[1]));
	printf("%s", (k[2]));
	printf("%s", (k[3]));
	double c, e;
	List list;
	char r[300];
	//r = NULL;
	int len = sizeof(k);
	InitializeList(&list);
	int ii = 0;
	int ps = 0;
	/*for (int i = 0; i < len; i++) {
		//puts(s[i]);
		strcopy(s+strlen(s)+1, r);
		lent += strlen(s)+1;
		ploy_getCoeAndExp(s, &c, &e);
		printf("(%g--%g)\n", c, e);
		s = s + lent;
	}*/
	//puts(s[2]);
	//PrintTheList(list);
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

void strcopy(const char *a, char* b) {
	int i = 0;
	int len = strlen(a);
	for (; i < len; i++) {
		*b++ = a[i];
	}
	*b = '\0';
}

bool isLastNode(char* p) {
	return 0;
}

List aaaaaaa(char* p) {
	List list;
	InitializeList(&list);
	double c, e;
	Node node;
	char* fix,*move;
	fix = move = p;
	int sign=1;
	int length = strlen(p);
	if (*move == '-') {
		sign = -1;
		*move = 0;
		fix=move=++move;
	}
	while (*move !='\0') {
		puts(fix+1);
		while (*move != '^') {
			if(*move=='*' || *move=='x')
			*move = '\0';
			move++;
		}
		*move = 0;
		c = sign*charToDouble(fix);
		move = move++;
		fix = move;
		while (*move != '+'&&*move != '-'&&*move != '\0') {
			move++;
		}
		if (*move == '\0') break;
		if (*move == '+')  sign = 1;
		if (*move == '-') sign = -1;
		*move = 0;
		e = charToDouble(fix);
		addNode(&list, c, e);
		 move = move++;
		 fix = move;
	}
	e = charToDouble(fix);
	addNode(&list, c, e);
	return list;
}

char* makeup(char* p) {
	//1+x+x^2+12*x+8*x^5
	char** r = (char**)malloc(6000);
	char* cp=p;
	puts(p);
	while (*cp!='\0') {
		if (*cp == '+') {
			*cp = '\0';
		}
		putchar(*cp);
		cp++;
	}
		puts(p);
		return NULL;
}

void arr_insert(char *p, char* t) {
	
}

void arr_add(char* p) {
	
	char* t =(char*)malloc(1000);
	memset(t, '\0', 1000);
	strcopy(p, t);
	puts(t);
	int len = strlen(t);
	for (int i = 0; i < len; i++) {
		if (t[i] == '-') {
			int j = len;
			for (; j > i; j--) {
				t[j+1] = t[j];
			}
			puts(t);
			printf("%c    %c    and %d\n", t[j], t[j+1], j);
			t[j + 1] = '-';
			t[j] = '-';
		}
		len=strlen(t);
	}
	//printf("lenb---->%d\n",len);
	puts(t);
}

void insert_by_postion(char* p, char t, int pos) {
	int len = strlen(p);
	char o;
	for (int i = len; i >= pos; i--) {
		*(p + i+1) = *(p + i);	
	}
	*(p + pos) = t;
}

void insert_before_minus(char*p) {
	int len = count(p);
	for (int i = 0;*(p+i)!='\0' ; i++) {
		if (*(p + i) == '-') {
			insert_by_postion(p, '+', i);
			i++;
		}
		len = strlen(p);
	}
}

int  count(char *p) {
	int len = 0;
	while (*(p + len) != '\0') {
		len++;
	}
	return len;
}

void print_int(int a) {
	printf("int(%d)\n", a);
}

void print_2darr(char** k) {
	printf("k[0]=%s\n", (*k));
	printf("k[0]=%s\n", (*k));
	printf("k[0]=%s\n", (*k));
	
	/*printf("k[1]=%s\n", (k[1]));
	printf("k[2]=%s\n", (k[2]));
	printf("k[3]=%s\n", (k[3]));*/

	/*for (int i = 0; i < 300; i++) {
		printf("%s",k[0]);
	}*/
}

void print_1darr(char *k) {
	for (int i = 0; i < 50; i++) {
		putchar(*(k + i));
	}
}

void insert_chars(char* p, char* t,int pos) {
	int len1 = strlen(t);
	int len2 = strlen(p);
	print_int(len2);
	puts(p);
	for (int i = len2; i > pos; i--) {
		*(p + i + len1-1) = *(p + i-1);	
	}

	for (int j = pos; j < pos + len1; j++) {
		*(p +j) = *t++;
	}
	print_int(strlen(p));
	puts(p);
}