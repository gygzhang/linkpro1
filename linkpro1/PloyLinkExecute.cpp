#include"PloyLink.h"
#include"stringFun.h"
#include<string.h>
#include<stdio.h>
#include<Windows.h>
int main(void)
{
	List la, lb, lc;
	//Initialize the list(set la=NULL);
	//because by default,the value is OXCCCCCC in visual stdio
	InitializeList(&la);
	InitializeList(&lb);
	InitializeList(&lc);

	char a[5000];// = "-1234*x^3+22*x^3+44*x^3+36*x^3";
	//char b[] = "-123456";
	memset(a, 0, 5000);
	//print_int(1000);
	
	//char *a = "-1234*x^3+22*x^3+44*x^3+36*x^3";
	strcopy("-1234+22*x^3-x^8+3*x^3+12*x^2+x+9*x^23+x-25+8*x^23+9+1*x^2", a);
	//strcopy("3-9-8+7", a);
	//print_int(count(a));
	char mark[] = "+";
	char mark1[] = "*x^";
	//insert_before_minus(a);
	//insert_by_postion(a, '+', 1);
	//puts(a);

	//arr_add(a);
	//makeup(a);
	//char *bb;
	//aaaaaaa(a);
	double f, g;
	//f = g = NULL;
	/*puts(y);
	ploy_getCoeAndExp(y, &f,& g);
	printf("%g***%g", f, g);*/
	//puts("hello");
	char** k;// = (char**)malloc(5000);
	/*k[0] = (char*)malloc(500);
	k[1] = (char*)malloc(500);
	k[2] = (char*)malloc(500);
	k[3] = (char*)malloc(500);*/
	//puts(a);
	k = spliteByMark(a, mark);
	/*printf("k[0]=%s\n", (k[0]));
	printf("k[1]=%s\n", (k[1]));
	printf("k[2]=%s\n", (k[2]));
	printf("k[3]=%s\n", (k[3]));*/
	print_1darr(k[0]);
	//print_2darr(k);
	//ploy_getCoeAndExp(k[0], &f, &g);
	/*puts(k[0]);
	puts(k[1]);
	puts(k[2]);
	puts(k[3]);*/
	//ploy_resolve(k);
	/*char aa[] = "aaa";
	char *b2;
	b2 = (char *)malloc(300);*/
	//b2 = NULL;
	/*strcopy(aa, b2);
	puts(b2);*/
	//printf("---%s---", 0xcd);
	/*char *p;
	p = (char*)malloc(11);
	*p = 'a';
	for (int i = 0; i < 25; i++)
		puts(&p[i]);*/
		//printf("%\n", &b2[i]);


		/*puts(k[0]);
		puts(k[1]);
		puts(k[2]);
		puts(k[3]);*/
		/*args *ag1;
		ag1 = (args*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ag1);
		ag1->aaaa = a;
		ag1->bbbb = mark1;

		bb = spliteByMark(a, mark);
		puts(bb);
		//printf("---%s---\n", spliteByMark(bb, mark1));

		args *ag;
		ag = (args*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ag);
		ag->aaaa = bb;
		ag->bbbb = mark1;

		hThread[0] = CreateThread(NULL, 0, MyThreadPro,(LPVOID)ag , 0, NULL);*/

		//printf("***%g***\n", charToDouble(a));

		//printf("---%s---\n",spliteByMark(a,mark));
		//printf("---%s---\n", spliteByMark(a, mark));
		//puts(tok);
		//printf("***pos= %d ***\n", pos);




		/*bb = spliteByMark(a, mark);

		printf("---%s---\n", spliteByMark(bb, mark1));*/

		/*printf("---%s---\n", spliteByMark(a, mark));
		printf("***pos= %d ***\n", pos);
		printf("---%s---\n", spliteByMark(a, mark));
		printf("***pos= %d ***\n", pos);*/

		//@Tsest CreatList
		/*CreatList(&la);
		CreatList(&lb);*/

		/*getMenu();
		SelectMethod(la, lb);*/

		//@Test simulate user input
		/*addNode(&la, 3, 1);
		addNode(&la, 2, 2);
		addNode(&la, 1, 3);
		addNode(&la, 0, 5);

		addNode(&lb, 5, 3);
		addNode(&lb, 5, 4);
		addNode(&lb, -1, 5);
		addNode(&lb, 1, 11);
		addNode(&lb, 1, 6);
		addNode(&lb, 1, 7);
		addNode(&lb, 1, 9);
		addNode(&lb, 1, 1);*/

		/*SortList(&la);
		DistingishList(&la);
		printf("Your Frist Input:\n");
		PrintTheList(la);*/


		/*SortList(&lb);
		DistingishList(&lb);
		printf("Your Second Input:\n");
		PrintTheList(lb);
		*/
		/*lc=ExecuteAdd(la, lb);
		printf("The ExecuteAdd Result Is:\n");
		PrintTheList(lc);

		//Union(&la, &lb);
		//printf("PrintTheList(la)");
		//PrintTheList(la);

		/*Node node;
		node.item.coefficient = 2;
		node.item.exponent = 3;
		List ld = SingleNodeMulAList(node, la);
		printf("The SingleNodeMulAList(node, la) Result Is:\n");
		PrintTheList(ld);*/

		/*List lt = ExecuteMul(la, lb);
		printf("The ExecuteMul Result Is:\n");
		PrintTheList(lt);

		//SignReverse(&la);
		//PrintTheList(la);

		List li = ExecuteSub(la, lb);
		PrintTheList(la);
		printf("The ExecuteSub Result Is:\n");
		PrintTheList(li);*/



		//char str[]= "2*x^3+3*x^4";
		//char* strr = str;
		//getNodeAndRemove(str);

		//@Test Copy ok
		/*List ld;
		InitializeList(&ld);
		//DistingishList(&la);
		CopyList(&ld, la);
		PrintTheList(ld);
		*/

		//@Test Distingish() ok
		/*DistingishList(&la);
		PrintTheList(la);
		*/

		//@Test GetTail()
		/*PrintSingalNode(*GetTail(&la));
		PrintTheList(la);
		PrintSingalNode(FindMinAndFree(&la));
		PrintTheList(la);
		PrintSingalNode(*GetTail(&la));
		PrintTheList(la);
		PrintSingalNode(*GetTail(&la));
		PrintTheList(la);
		PrintSingalNode(*GetTail(&la));
		PrintTheList(la);*/

		//@Test CalculateTheResultByX(la, 2)
		//CalculateTheResultByX(la, 2);
		//printf("--%.0lf--\n", CalculateTheResultByX(lb, 2));

	system("PAUSE");
}
