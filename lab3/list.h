#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
/** \func struct List */
struct List
{
	int value;
	List *pNext;
	List *pPrev;
};
List *head; 

/** \func void addpos(int newvalue, int position) */
void addpos(int newvalue, int position)
{
	List  *node = new List; 
	node->value = newvalue;
	if ((head == NULL))
	{
		node->pNext = node; 
		node->pPrev = node;
		head = node; /
	}
	else
	{
		List *p = head;
		for (int i = position; i > 0; i--)
		{
			p = p->pNext;
		}
		p->pPrev->pNext = node;
		node->pPrev = p->pPrev;
		node->pNext = p; 
		p->pPrev = node;
	}
}

/** \func void Delete(int position) */
void Delete(int position)
{
	if (head == NULL) 
		{ 
		cout << "\nÏóñòîé ñïèñîê\n"; 
		}
	if (head->pNext == head) 
	{
		delete head;
		head = NULL;
	}
	else
	{
		List *_del = head;
		for (int i = position; i>0; i--) _del = _del->pNext;
		if (_del == head) head = _del->pNext;
		_del->pPrev->pNext = _del->pNext;
		_del->pNext->pPrev = _del->pPrev;
		delete _del;
	}
}

/** \func int Get(int position) */
int Get(int position)
{
	int ch;
	if (head == NULL) { cout << "\nÑïèñîê ïóñò\n\n"; return 0; }
	else
	{
		List *_get = head;
		for (int i = position; i > 0; i--) _get = _get->pNext;
		ch = _get->value;
	}
	return ch;
}

