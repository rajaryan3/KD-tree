#include<stdio.h>
#include"alpha.h"

int main(){
	alphatree t1 ;
	init(&t1);
	insertalpha(&t1 , "grocery" , 1);
	insertalpha(&t1 , "toys" , 2);
	insertalpha(&t1 , "stationary", 3);
	insertalpha(&t1 , "medical", 4);
	insertalpha(&t1 , "jwellery", 5);
	
	int cnt = 1;
	inorderalpha(t1 , &cnt);
	int select ;
	scanf("%d", &select);
	cnt = 0;
	int found = getpsuedonum(t1,select,&cnt);
	printf("%d",found);
}
