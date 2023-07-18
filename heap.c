#include"heap.h"

Heap *CreateHeap(int capacity,int heap_type){
	Heap *h = (Heap * ) malloc(sizeof(Heap)); //one is number of heap
	//check if memory allocation is fails
	if(h == NULL){
        	printf("Memory Error!");
        	exit(1);
    	}
    	h->heap_type = heap_type;
    	h->count=0;
    	h->capacity = capacity;
    	h->arr = (kddata *) malloc(capacity*sizeof(kddata)); //size in bytes

    //check if allocation succeed
    	if ( h->arr == NULL){
        	printf("Memory Error!");
        	exit(1);
    	}
    	return h;
}

void insertheap(Heap *h, double distanceofp ,node p ){
    	if( h->count < h->capacity){
    		kddata nodeofarr;
    		nodeofarr.reqdist = distanceofp;
    		nodeofarr.p = p ;
        	h->arr[h->count] = nodeofarr ;
        	heapify_bottom_top(h, h->count);
        	h->count++;
    	}
}

void heapify_bottom_top(Heap *h,int index){
    	kddata temp;
    	int parent_node = (index-1)/2;

    	if(h->arr[parent_node].reqdist > h->arr[index].reqdist){
        	//swap and recursive call
        	temp = h->arr[parent_node];
        	h->arr[parent_node] = h->arr[index];
        	h->arr[index] = temp;
        	heapify_bottom_top(h,parent_node);
    	}
}

void heapify_top_bottom(Heap *h, int parent_node){
    	int left = parent_node*2+1;
    	int right = parent_node*2+2;
    	int min;
    	kddata temp;

    	if(left >= h->count || left <0)
        	left = -1;
    	if(right >= h->count || right <0)
        	right = -1;

    	if(left != -1 && h->arr[left].reqdist < h->arr[parent_node].reqdist)
        	min=left;
    	else
        	min =parent_node;
    	if(right != -1 && h->arr[right].reqdist < h->arr[min].reqdist)
        	min = right;

    	if(min != parent_node){
        	temp = h->arr[min];
        	h->arr[min] = h->arr[parent_node];
        	h->arr[parent_node] = temp;

        	// recursive  call
        	heapify_top_bottom(h, min);
    	}
}

kddata PopMin(Heap *h){
	kddata pop;
	node x;
    	pop.reqdist = 0;
    	pop.p = x; 
    	if(h->count==0){
        //printf("\n__Heap is Empty__\n");
        	return pop;
    	}
    // replace first node by last and delete last
    	pop = h->arr[0];
    	h->arr[0] = h->arr[h->count-1];
    	h->count--;
    	heapify_top_bottom(h, 0);
    	return pop;
}
void print(Heap *h , int k ){
	int i;
	if(h->count)
    		printf("\n_____________________________________________The nearest shops are :___________________________________________\n");
	else
    		printf("\nSORRY !, No record found\n");
    	int decider;
    	if(k < h->count)
    		decider = k;
    	else
    		decider = h->count;
    	for(i=0;i< decider;i++){
    		kddata pop = PopMin(h);
        	//printf("Distane :%lf\tlatitude :%lf , longitude:%lf\t:Details :%s\n",h->arr[i].reqdist,h->arr[i].p.point[0],h->arr[i].p.point[1],h->arr[i].p.name);
        	printf("Distane :%lf\tlatitude :%lf , longitude:%lf\tDetails :%s\n",pop.reqdist, pop.p.point[0] , pop.p.point[1], pop.p.name );
	}
	printf("\n");
}
