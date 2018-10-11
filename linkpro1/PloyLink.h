#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct item {
	double coefficient;
	double exponent;
};

typedef struct num {
	int n;
	int length;
}nums;

typedef struct item Item;

typedef struct node {
	Item item;
	struct node * next;
}Node;
typedef Node* List;
//copy an item to a node
static void CopyToNode(Item item, Node* node);

//Initialize the list
void InitializeList(List* plist);

//add an item into a list 
bool AddItem(Item item, List* plist);

//Print all the node of the list with particular way;
void PrintTheList(List list);

void Traverse(const List* plist, List(*pfun)(Node node, List *list));

//Judge if the item is exist in the list
bool ItemExistIn(List l, Item item);

//Input to creat a ploynomial
void CreatList(List *plist);

//add a node into a list by coefficient and exponent
bool addNode(List* plist, double coefficient, double exponent);

//add node into list by node
void addNode(List *list, Node node);

//Sort a list by exponent with ascending 
void SortList(List* list);

//Find the item which its exponent is minimun value 
Node FindMinAndFree(List* list);

//Generate a node by coefficient and exponent
void GenerateANode(Node *node, double coefficient, double exponent);

//Print the coefficient and exponent of a node 
void PrintSingalNode(Node node);

//Judge if the list is empty
bool ListIsEmpty(const List list);

//Get the length of a list
int GetListLength(List list);

//get the last pointer to the last 
Node* GetTail(List *list);

//Concatenate lb to the tail of la
void Union(List* la, List *b);

//Implements  ploynomial multiplication using Pointer to function.
List MutiplicationWithPMethod(List la, List lb, List(*p)(Node node, List lb));

//Calculate a single node multiply a list,and return rhe result
List SingleNodeMulAList(Node node, List list);

//reserse the sign
void SignReverse(List* plist);

//add
List ExecuteAdd(List la, List lb);

//substraction
List ExecuteSub(List la, List lb);

//multiplication
List ExecuteMul(List la, List lb);

//Select a method to execute
void SelectMethod(List la, List lb);

// the the menu
void getMenu();

//List StringToList(char* string);

void DistingishList(List* list);

void CopyList(List*, List);

List GenerateAEmptyList();

double CalculateTheResultByX(List list, double x);

long Factorial(int n);

long Power(double x, int times);
