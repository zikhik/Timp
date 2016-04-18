#include "stdafx.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
struct stack
{
	int value;
	struct stack *next;
};

stack *st;

/** \func void push(int newvalue) */
void push(int newvalue)
{
	stack *node = new stack;
	if (st == 0)
	{
		node->value = newvalue;
		node->next = 0;
		st = node;
	}
	else
	{
		node->value = newvalue;
		node->next = st;
		st = node;
	}
}
/** \func int top() */
int top()
{
	return st->value;
}
/** \func void del() */
void del()
{
	if (st == NULL)
	{
		cout << "ñòåê ïóñòîé" << endl;
	}
	else
	{
		st = st->next;
	}

}

