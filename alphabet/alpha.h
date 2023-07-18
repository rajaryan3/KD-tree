#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct nodealpha{
	char name[200];
	int psuedonum;
	struct nodealpha* left ,*right ;
}nodealpha;

typedef nodealpha* alphatree;

void init(alphatree *t);
 
alphatree createnodealpha(char* n , int num);

void insertalpha(alphatree *t , char* n , int num);

void inorderalpha(alphatree t , int *cnt );

int getpsuedonum(alphatree t , int given ,int *a);
