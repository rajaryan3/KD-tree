#include<stdio.h>
#include<limits.h>
#include"kd.h"
#include<string.h>
#include"userpath.h"

int main(){
	char* hi = main_for_userpath();
	kdTree t;
	initkd(&t);
	//printf("in main : %s\n",hi);
	double pointofloc[2];
	char shopname[200];
	FILE* fp = fopen(hi , "r");
	while(fscanf(fp, "%lf%lf%s", &pointofloc[0],&pointofloc[1], shopname) != EOF){
		insert( &t , pointofloc , shopname,  0);
	}
	double query[2] ;
	printf("Enter latitude of location :");
	scanf("%lf",&query[0]);
	printf("Enter longitude of location :");
	scanf("%lf",&query[1]);
	printf("\nNearest shop :Enter 1 \nRange query : Enter 2\n");
	printf("Enter your choice : ");
	int required = 10;
	while(required){
		scanf("%d",&required);
		if (required == 1){
			double bst_pt[2];bst_pt[0]=0 ;bst_pt[1] = 0;
			double dist= INT_MAX;
			kdTree near;
			near = get_nearest(query , t , 0 , &near , &dist  );
			printf("\nNearest shop is : %f , %f",near->point[0],near->point[1]); 
			printf("\nThe name is :%s\nThe distance is :%f km\n",near->name,dist);
			printf("\n(The distance provided is based on given latitude and longitude , real distance may vary.)\n");
			required = 0;
		}
		else if(required == 2){
			int k ;
			double radius;
			printf("\nEnter no. of records you want :");
			scanf("%d",&k);
			printf("\nEnter radius for search (in km): ");
			scanf("%lf",&radius);
			getknearest( t , query ,k , radius);
			required = 0;
		}
		else
			printf("\nEnter valid input :");
	}
	return 0;
}
