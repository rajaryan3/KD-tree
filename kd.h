#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include"heap.h"
/*
typedef struct node{
	double point[2];
	char name[200];
	struct node *left,*right;
}node;

typedef node* kdTree;
*/

void initkd(kdTree *t);

kdTree createnode(double p[] , char* n);

void insert(kdTree *t ,double p[] ,char* n ,int depth);

double distance(double a[],double b[]);

kdTree get_nearest(double *query_pt , kdTree t , int depth , kdTree *near , double *best_dist);

void filetrymain(double pointofloc[]);

void getknearest(kdTree t , double* query , int k , double radius);
