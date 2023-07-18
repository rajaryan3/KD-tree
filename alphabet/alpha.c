#include"alpha.h"


void init(alphatree *t){
	*t = NULL;
}

alphatree createnodealpha(char* n ,int num ){	
	nodealpha* nn = ( nodealpha*)malloc(sizeof(nodealpha));
	strcpy(nn->name , n);
	nn->psuedonum = num ; 
	nn->left = nn->right = NULL;
	return nn;
}
void insertalpha(alphatree *t , char* n , int number ){
	if(!*t){
		*t = createnodealpha(n , number);
		return;
	}
	if (strcmp(n , (*t)->name) < 0)
		insertalpha( &((*t)->left) , n , number);
	else
    		insertalpha( &((*t)->right) , n , number);
    	return;
}

void inorderalpha(alphatree t , int *cnt ){
	if(!t)
		return;
	inorderalpha(t->left , (cnt));
	
	//char* nameptr = t->name;
	//char *onlyname = strtok(nameptr ,".txt");
	printf("%d : %s\n" ,(*cnt)++ , t->name );
	
	inorderalpha(t->right , (cnt));
	
}

int getpsuedonum(alphatree t , int given ,int *a){
	if(!t)
		return 0;
	int l =  getpsuedonum( t->left, given , a );
	
	(*a)++;
	if((*a) == given && t)
		return t->psuedonum;
	//else
	//(*a)++;
	
	int r =  getpsuedonum( t->right , given , a );
	
	return l+r;		
}
