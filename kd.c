#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include"kd.h"
#include"userpath.h"

void initkd(kdTree *t){
	*t = NULL;
}

kdTree createnode(double p[] , char* sname){	
	node* nn = ( node*)malloc(sizeof(node));
	nn->point[0] = p[0];
	nn->point[1] = p[1];
	strcpy(nn->name , sname);
	nn->left = nn->right = NULL;
	return nn;
}
void insert(kdTree *t ,double p[] , char* shopname,int depth){
	if(!*t){
		*t = createnode(p , shopname);
		return;
	}
	int cd = depth % 2 ;
	
	if (p[cd] < ((*t)->point[cd]))
		insert(&((*t)->left), p, shopname ,depth + 1);
	else
    		insert(&((*t)->right), p, shopname ,depth + 1);
    	return;
}

double distance(double a[],double b[] )
{
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    double lat1 = (a[0])*(M_PI/180);
    double long1 = a[1]*(M_PI/180);
    double lat2 = b[0]*(M_PI/180);
    double long2 = b[1]*(M_PI/180);
     /*printf("lat1 diff  is:%Lf \n",lat1);
     printf("long1 diff  is:%Lf \n",long1);
     printf("lat2 diff  is:%Lf \n",lat2);
     printf("long2 diff  is:%Lf \n",long2);
    */
    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
    //printf("dlat diff  is:%Lf \n",dlat);
     
    double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
    //printf("sin(0.0256/2 )=%lf",pow(sin(dlat/2),2));
    //printf("\nans is :%lf\n",ans);
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    double R = 6371;
     
    // Calculate the result
    ans = ans * R;
    //printf("\nans is :%lf\n",ans);
 
    return ans;
}


/*
Here in get_nearest
	query_pt : from user
	t : root node
	depth : depth to decide axis to be used for comparison
	best_pt[] :Initialize the best_pt[0],best_pt[1] to 0 ,outside fn before call & after call still 0 means no empty tree
	best_dist : address of distance variable which is outside initialized to INT_MAX & after call still 0 means no empty tree

*/
kdTree get_nearest(double *query_pt , kdTree t , int depth , kdTree* t_near , double *best_dist){
	if(!t)
		return *t_near;
		
	double d = distance(query_pt , t->point);
	
	kdTree good_side,bad_side;
	
	if(d<*best_dist){
	//	best_pt[0] = t->point[0];
	//	best_pt[1] = t->point[1];
		*t_near = t;
		*best_dist = d;  
	}
	int cd = depth % 2;
	
	if(t->point[cd] > query_pt[cd]){
		good_side = t->left;
		bad_side = t->right;
	}
	else{
		good_side = t->right;
		bad_side = t->left;		
	}
	*t_near = get_nearest(query_pt,  good_side , depth+1 ,  t_near, best_dist);
	//return best_pt;
	int check_for_bad = t->point[cd] - query_pt[cd];
	if(check_for_bad < 0)
		check_for_bad = (-1)*check_for_bad ;
	if(check_for_bad< *best_dist){
		*t_near = get_nearest(query_pt,  bad_side , depth+1 , t_near, best_dist);
	}
	return *t_near;
}

//lattitude , longitude


void getknearesthelp(kdTree t , Heap* h ,int k , double *query_pt ,double radius){
	if(!t)
		return ;
	getknearesthelp(t->left , h ,  k , query_pt , radius);
	
	double dist = distance(t->point , query_pt);
	if(dist < radius ){
		insertheap( h , dist ,*t);
	}
	getknearesthelp(t->right , h ,  k , query_pt , radius);
}

void getknearest(kdTree t , double* query , int k , double radius){
	Heap *h = CreateHeap(1000, 0); //Min Heap
	if( h == NULL ){
		printf("__Memory Issue____\n");
       	exit(1);
    	}
	getknearesthelp(t , h ,  k , query , radius);
	print(h , k);
}
