#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct tree 
{
	int numero;
	struct tree* esq;
	struct tree* dir;
} Tree;

Tree* createTree ()
{
	return NULL;
}

int treeIsEmpty(Tree* arvore)
{
	return arvore == NULL;
}

void showTree(Tree* arvore)
{
	printf("\n < ");
	if (!treeIsEmpty(arvore))
	{
		printf("%d", arvore->numero);
		showTree(arvore->esq);
		showTree(arvore->dir);
	}
}

void insertTree(Tree** arvore, int numero)
{
	if(*arvore == NULL)
	{
		(*arvore) = (Tree*)malloc(sizeof(Tree));
		(*arvore)->esq = NULL;
		(*arvore)->dir = NULL;
		(*arvore)->numero = numero;
	}
	
	else
	{
		if (numero < (*arvore)->numero)
		{
			insertTree(&(*arvore)->esq, numero);
		}
		
		if (numero > (*arvore)->numero)
		{
			insertTree(&(*arvore)->dir, numero);
		}
	}
}

int buscar(Tree* arvore, int numero)
{
	if(treeIsEmpty(arvore))
	{
		return 0;
	}
	
	return arvore->numero == numero || buscar(arvore->esq, numero) || buscar(arvore->dir, numero);
}

int main(int argc, char** argv)
{
	printf("<<< Arvore Binaria >>>");
	Tree* arvore = createTree();
	
	insertTree(&arvore, 4);
	insertTree(&arvore, 71);
	insertTree(&arvore, 18);
	insertTree(&arvore, 35);
	insertTree(&arvore, 42);
	insertTree(&arvore, 12);
	
	showTree(arvore);
	return 0;
}
