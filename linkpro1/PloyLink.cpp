#include"PloyLink.h"

static void CopyToNode(Item item, Node* pnode) {
	pnode->item = item;
}

void InitializeList(List* plist) {
	*plist = NULL;
}

bool AddItem(Item item, List* plist) {
	Node* pnew;
	Node* scan = *plist;

	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL) return false;

	CopyToNode(item, pnew);
	pnew->next = NULL;
	//Èç¹û±íÎª¿Õ·ÅÔÚ¿ªÍ·
	if (scan == NULL) *plist = pnew;
	else {
		//±éÀúÁ´±í£¬µ½´ï×îºóÒ»¸ö½Úµã
		while (scan->next != NULL) scan = scan->next;
		//°ÑÕâ¸ö½ÚµãÁ¬½Óµ½×îºóÒ»¸ö½ÚµãµÄÎ²²¿
		scan->next = pnew;
	}

	return true;
}

void PrintTheList(List list) {
	List scan;
	if (ListIsEmpty(list)) {
		printf("The List Is Empty...\n");
		return;
	}
	//SortList(&list);
	//DistingishList(&list);
	scan = list;
	while (scan != NULL) {
		//
		if (scan != list) {
			if (scan->item.coefficient > 0) {
				printf("+");
			}
			//ÏµÊýÎªÁãÔòºöÂÔ
			else if (scan->item.coefficient == 0) {
				scan = scan->next;
				continue;
			}
		}
		printf("%g*x^%g", scan->item.coefficient, scan->item.exponent);
		scan = scan->next;
	}
	printf("\n");
}

List ExecuteAdd(List la, List lb) {
	Node na, nb;
	List scana, scanb, lc;
	if (ListIsEmpty(la)) return lb;
	if (ListIsEmpty(lb)) return la;
	InitializeList(&lc);
	SortList(&la);
	SortList(&lb);
	InitializeList(&scana);
	InitializeList(&scanb);
	CopyList(&scana, la);
	CopyList(&scana, lb);
	na = FindMinAndFree(&la);
	nb = FindMinAndFree(&lb);
	while (true) {
		//
		if (na.item.exponent > nb.item.exponent) {
			addNode(&lc, nb.item.coefficient, nb.item.exponent);
			addNode(&la, na.item.coefficient, na.item.exponent);
		}
		//Èç¹û½ÚµãA±È½ÚµãBÐ¡£¬ÄÇÃ´½«½ÚµãA²åÈë±íLc
		if (na.item.exponent < nb.item.exponent) {
			addNode(&lc, na.item.coefficient, na.item.exponent);
			addNode(&lb, nb.item.coefficient, nb.item.exponent);
		}
		//Èç¹ûA==B£¬ÄÇÃ´½«½ÚµãA£¬BµÄÏµÊýÏà¼Ó£¬È»ºó½«Ìí¼Óµ½±íLC
		if (na.item.exponent == nb.item.exponent) {
			Item item;
			item.coefficient = na.item.coefficient + nb.item.coefficient;
			item.exponent = na.item.exponent;
			AddItem(item, &lc);
		}
		//Èç¹û±íLA²»Îª¿Õ£¬ÄÇÃ´»ñÈ¡Ò»¸ö×îÐ¡µÄ½Úµã²¢¸³¸ø½Úµãna
		if (!ListIsEmpty(la)) {
			na = FindMinAndFree(&la);
		}
		//Èç¹û±ílaÎª¿Õ£¬ÄÇÃ´Ö±½Ó½«±ílb½Óµ½lcºóÃæ
		else if (ListIsEmpty(la))
		{
			Union(&lc, &lb);
			SortList(&lc);
			DistingishList(&lc);
			CopyList(&la, scana);
			CopyList(&lb, scanb);
			return lc;
		}
		//Èç¹û±íLb²»Îª¿Õ£¬ÄÇÃ´»ñÈ¡Ò»¸ö×îÐ¡µÄ½Úµã²¢¸³¸ø½ÚµãnB
		if (!ListIsEmpty(lb)) {
			nb = FindMinAndFree(&lb);
		}
		//Èç¹û±ílbÎª¿Õ£¬ÄÇÃ´Ö±½Ó½«±íla½Óµ½lcºóÃæ
		else if (ListIsEmpty(lb))
		{
			Union(&lc, &la);
			SortList(&lc);
			DistingishList(&lc);
			CopyList(&la, scana);
			CopyList(&lb, scanb);
			return lc;
		}
	}
}

bool ItemExistIn(List l, Item item) {
	Node* scan = l;
	while (scan != NULL)
	{
		if (scan->item.exponent == item.exponent) return true;
		scan = scan->next;
	}
	return false;
}

void CreatList(List *plist) {
	double coefficient, exponent;
	coefficient = exponent = 0;
	Item item;
	printf("Please Input A Coefficient And The Corresponding"
		"Exponent (enter to continue,q to quit)\n");
	while (scanf_s("%lf%lf", &coefficient, &exponent) == 2) {
		if (coefficient == 0) continue;
		item.coefficient = coefficient;
		item.exponent = exponent;
		AddItem(item, plist);
	}

	getchar();
}

bool addNode(List* plist, double coefficient, double exponent) {
	Node* pnew;
	Node* scan = *plist;

	Item item;
	item.coefficient = coefficient;
	item.exponent = exponent;
	//if the coefficient is zero,then not add
	if (fabs(coefficient) < 1e-9) return false;
	//malloc a memory to the store the node
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL) return false;
	CopyToNode(item, pnew);
	pnew->next = NULL;
	//Judge that wether the scan is empty list,if it is empty ,then set 
	//the pnew as the first node of the list
	if (scan == NULL) *plist = pnew;
	else {
		//get the tail node of the list
		scan = GetTail(plist);
		//concatenate
		scan->next = pnew;
	}
	return true;
}

void SortList(List* list) {
	Node node;
	List temp, cur, nextNode;
	if (ListIsEmpty(*list)) {
		return;
	}
	InitializeList(&temp);
	nextNode = (*list)->next;
	while (true) {
		if (ListIsEmpty(*list)) break;
		node = FindMinAndFree(list);
		addNode(&temp, node.item.coefficient, node.item.exponent);
	}
	//It looks will be wrong down(the varible temp will be destroy atfer 
	//function calling),but in practice it works well,why?
	//
	*list = temp;
}

Node FindMinAndFree(List* list) {
	Node node;
	Node* scan = (*list);
	Node *temp = *list, *prev = NULL;
	int min = (*list)->item.exponent;
	if (!ListIsEmpty(*list)) {
		GenerateANode(&node, (*list)->item.coefficient, (*list)->item.exponent);
		while (scan->next != NULL) {
			double etemp = scan->next->item.exponent;
			if (etemp < min) {
				min = etemp;
				prev = scan;
			}
			scan = scan->next;
		}
		if (prev == NULL) {
			GenerateANode(&node, (*list)->item.coefficient, (*list)->item.exponent);
			*list = (*list)->next;
		}
		else {
			GenerateANode(&node, prev->next->item.coefficient, prev->next->item.exponent);
			prev->next = prev->next->next;
		}
		return node;
	}
}

void GenerateANode(Node *node, double coefficient, double exponent) {
	node->item.coefficient = coefficient;
	node->item.exponent = exponent;
	node->next = NULL;
}

void PrintSingalNode(Node node) {
	printf("%.0lf and %.0lf\n", node.item.coefficient, node.item.exponent);
}

bool ListIsEmpty(const List list) {
	return (GetListLength(list) == 0 ? true : false) || (list->item.coefficient == 0 && GetListLength(list) == 1);
}

int GetListLength(List list) {
	int i = 0;
	List scan = list;
	while (scan != NULL) {
		i++;
		scan = scan->next;
	}
	return i;
}

/**1.Node* prev can work in comparison to Node prev
	   2.This is because Node* prev declare a varible to store the address of
			the Node ,so after the function calling,the varible destroyed,the value of
			the prev(the address of a node) is gloriously returnned to the calling function.
			of course, the prev in the GetTail's stack is certainly be destoryed.

			 That is to say，the prev is point to the original list.
			 if prev is a node ,then it's data will be destroy after exit the function.
	**/
Node* GetTail(List *list) {

	Node *prev = NULL;
	List scan = *list;
	while (scan != NULL) {
		prev = scan;
		scan = scan->next;
	}
	return prev;
}

void Union(List* la, List *lb) {
	List a = *la, b = *lb;
	Node* node = GetTail(la);
	node->next = *lb;
}

List MutiplicationWithPMethod(List la, List lb, List(*p)(Node node, List lb)) {
	List scan, store;
	List a, b;
	InitializeList(&a);
	InitializeList(&b);
	InitializeList(&scan);
	InitializeList(&store);
	//reserve the list to a
	CopyList(&a, la);
	while (la != NULL) {
		scan = p(*la, lb);
		if (ListIsEmpty(store)) {
			store = scan;
		}
		else {
			Union(&store, &scan);
		}
		la = la->next;
	}

	SortList(&store);
	DistingishList(&store);
	//up to now, the la is empty so recover it from a
	CopyList(&la, a);
	return store;
}

List SingleNodeMulAList(Node node, List list) {

	List scan;
	Node tempNode;
	//If not initialize the list,can cause many troubles
	//because vs automatically assign OXCCCCCCC to the uninitialized pointer,not null
	InitializeList(&scan);
	while (list != NULL) {
		tempNode.item.coefficient = list->item.coefficient*node.item.coefficient;
		tempNode.item.exponent = list->item.exponent + node.item.exponent;
		addNode(&scan, tempNode);
		list = list->next;
	}
	return scan;
}

void addNode(List *list, Node node) {
	addNode(list, node.item.coefficient, node.item.exponent);
}

List ExecuteMul(List la, List lb) {
	if (ListIsEmpty(la) || ListIsEmpty(lb)) {
		return NULL;
	}
	else
	{
		return MutiplicationWithPMethod(la, lb, SingleNodeMulAList);
	}
}

List ExecuteSub(List la, List lb) {
	SignReverse(&lb);
	return ExecuteAdd(la, lb);
}

void SignReverse(List* plist) {
	//plistÊÇÒ»¸öÖ¸ÏòÁ´±íµÄÖ¸Õë£¨Ö¸ÏòNodeµÄµØÖ·£©
	//pnodeÊÇÒ»¸öÖ¸ÏòNodeµÄÖ¸Õë£¨ÀàÐÍºÍListÒ»Ñù£©
	//²»ÄÜ½«pnodeÉùÃ÷ÎªÒ»¸öNodeÀàÐÍµÄ±äÁ¿£¨Node pnode;£©£¬ÒòÎªÕâÑù*plistÕâ¸öÁ´±í¸ù±¾Ã»ÓÐ¸Ä±ä¹ý£¡£¡£¡
	//ÎªÊ²Ã´ÄØ£¿ ÒòÎªscanÎªÖ¸ÏòNodeµÄÒ»¸öÖ¸Õë£¬pnode = *scan;Õâ¾äµ÷ÓÃÖ®ºóÏàµ±ÓÚ°ÑÒ»¸ö½Úµã
	//¸³¸ønode£¬ÔÙÔõÃ´¸Ä±änodeÒ²¸ù±¾²»»áÓ°Ïì*plistÕâ¸öÁ´±í£¬
	//¶øÈç¹ûÕâÑùÉùÃ÷£¨Node *pnode;£©£¬ÄÇÃ´Ã¿´ÎÖ´ÐÐpnode = scanÊ±¶¼Ïàµ±ÓÚÖ±½Ó»ñµÃÁËÁ´±íµÄÒ»¸ö
	//½ÚµãµÄµØÖ·£¬¶ø²»ÊÇÒ»·ÝNode½ÚµãµÄ¿½±´£¬ËùÒÔ¿ÉÒÔÍ¨¹ýpnodeÕâ¸öµØÖ··ÃÎÊµ½*plistµÄÃ¿Ò»¸ö½Úµã¡£
	//´Ó¶øÐÞ¸Ä*plist
	Node *pnode;
	List scan = *plist;
	while (scan != NULL) {
		pnode = scan;
		(*pnode).item.coefficient = 0 - ((*pnode).item.coefficient);
		scan = scan->next;
	}
}

void SelectMethod(List la, List lb) {
	int i;
	List lc;
	printf("Please choose a selection that you want to execute(q to quit):\n");
	while (scanf_s("%d", &i) == 1) {
		switch (i)
		{
		case 1:
			lc = ExecuteAdd(la, lb);
			printf("Your choice is ExecuteAdd(la, lb)\n");
			PrintTheList(lc);
			break;
		case 2:
			lc = ExecuteSub(la, lb);
			printf("Your choice is ExecuteSub(la, lb)\n");
			PrintTheList(lc);
			break;
		case 3:
			lc = ExecuteMul(la, lb);
			printf("Your choice is ExecuteMul(la, lb)\n");
			PrintTheList(lc);
			break;
		case 4:
			printf("Your choice is input agina \n");
			goto creat;
			break;
		default:
			printf("Bad Choice");
			break;
		}
	}
	printf("Please choose a selection that you want to execute(q to quit):\n");
	//use label
creat:
	List lw, lq;
	InitializeList(&lw);
	InitializeList(&lq);
	//InitializeList(&lc);
	CreatList(&lw);
	CreatList(&lq);

	SortList(&lw);
	DistingishList(&lw);
	printf("Your Frist Input:\n");
	PrintTheList(lw);


	SortList(&lq);
	DistingishList(&lq);
	printf("Your Second Input:\n");
	PrintTheList(lq);

	getMenu();
	SelectMethod(lw, lq);

}


void getMenu() {
	printf("-----------------Welcome----------------\n");
	printf("     1 to ExecuteAdd(la, lb)\n");
	printf("     2 to ExecuteSub(la, lb)\n");
	printf("     3 to ExecuteMul(la, lb)\n");
	printf("     4 to Input agina\n");
	printf("     q to quit \n");
}
//get rid of the repetitive item in the list
void DistingishList(List* list) {
	Node node, *tail;
	List temp, scan;
	InitializeList(&temp);
	InitializeList(&scan);
	CopyList(&temp, *list);
	node = FindMinAndFree(list);
	addNode(&scan, node);
	tail = GetTail(&scan);
	while (!ListIsEmpty(*list)) {
		node = FindMinAndFree(list);
		if (node.item.exponent == tail->item.exponent && (fabs(node.item.coefficient + tail->item.coefficient) > 1e-9)) {
			tail->item.coefficient += node.item.coefficient;
		}
		else {
			addNode(&scan, node);
		}

		tail = GetTail(&scan);
	}
	CopyList(list, scan);
}

//idea: traverse the list and add every node to list
void CopyList(List* la, List lb) {
	List scan;
	Node node;
	InitializeList(&scan);
	scan = lb;
	while (scan != NULL) {
		addNode(la, *scan);
		scan = scan->next;
	}
}

List GenerateAEmptyList() {
	List l;
	InitializeList(&l);
	Node node;
	node.item.coefficient = 0;
	node.item.exponent = 0;
	addNode(&l, node);
	return l;
}

double CalculateTheResultByX(List list, double x) {
	double fa = 0;
	List scan;
	Node node;
	InitializeList(&scan);
	CopyList(&scan, list);
	PrintTheList(scan);
	while (!ListIsEmpty(scan)) {
		node = FindMinAndFree(&scan);
		fa += node.item.coefficient*Power(x, node.item.exponent);
	}
	return fa;
}

long Factorial(int n) {
	if (n == 1) return 1;
	else return n * Factorial(n - 1);
}

long Power(double x, int times) {
	double re = 1;
	for (int i = 0; i < times; i++) {
		re *= x;
	}
	return re;
}