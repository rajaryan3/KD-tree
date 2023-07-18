#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

char* gen_random(char*st , const int len) {
    char s[len+1];
    static const char alphanum[] =     "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    //printf("the name is :%s\n",s);
    s[len] = '\0';
    strcpy(st,s);
    return st;
}


double rand_double(){
	return ((double)rand())/((double)RAND_MAX);
}

double generate_random(double l, double r) { //this will generate random number in range l and r
   double rand_num = (rand_double() * (r - l )) + l;
}
int main() {
   double lowerlat = 18.559856, upperlat = 18.587120 ;
   double lowerlong = 73.815272, upperlong = 73.813034;
   srand(time(0)); //current time as seed of random number generator
   double a , b;
   char s[15];
   int i=0;
   FILE* fp = fopen("/home/dell/Desktop/coep/rajdsa/dsa_project/shops/medical/generic/omez.txt","a");
   while(i<10000){
   	a = generate_random(lowerlat, upperlat);
   	b = generate_random(lowerlong, upperlong);
   	fprintf( fp , "%lf\t%lf\t%s\n" ,a,b,gen_random(s ,15));
   	i++;
   }
   //gen_random(15);
   printf("\n");
   return 0;
}
