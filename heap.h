#include<stdio.h>
#include<stdlib.h>
//#include"kd.h"

typedef struct node{
	double point[2];
	char name[200];
	struct node *left,*right;
}node;
typedef node* kdTree;


typedef struct kddata{
	double reqdist; 
	node p; 
}kddata;


struct Heap{
    kddata *arr;
    int count;
    int capacity;
    int heap_type; // for min heap , 1 for max heap
};
typedef struct Heap Heap;


Heap *CreateHeap(int capacity,int heap_type);
void insertheap(Heap *h, double dist , node a);
void print(Heap *h  , int k);
void heapify_bottom_top(Heap *h,int index);
void heapify_top_bottom(Heap *h, int parent_node);
kddata PopMin(Heap *h);
