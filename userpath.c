#include"userpath.h"
#include"./alphabet/alpha.h"

int static decider=0;
double static pt[2];
char pathforuser[400];
alphatree t ;
//init(&t);

void user_get_next_folder(char* path );

void  user_display_content(char* path );

void user_folder_input(char* dir_path ){
	user_display_content(dir_path );
	
	if(!decider)
		user_get_next_folder(dir_path );
	}

void modify_userpath(char* p , int c){
	DIR* da;struct dirent* dira;
	char* f_name_a;
	int cntr = 0;
	da = opendir(p);
	while((dira=readdir(da))){
		int s = strlen(dira->d_name);
		f_name_a = dira->d_name;
		if((s>2) && (f_name_a[s-1]!='~')){
			cntr++;
			if(cntr == c){
				
				strcpy(pathforuser , p);
				strcat(pathforuser , f_name_a);
				closedir(da);
				return ;
			}
		}
	}
	closedir(da);
}

void user_display_content(char* path ){
	DIR* d;struct dirent* dir;
	char* f_name;
	char r_path[500],reqf_path[500]; 
	strcpy(reqf_path , path);
	int cnt,getnum_of_shop,chk=0,p_or_ab;
	cnt =1;
		
	init(&t);
	
	//code to display content
	d=opendir(path);
	while((dir=readdir(d))){
		int s = strlen(dir->d_name);
		f_name = dir->d_name; 				//added later
		if((s>2) && (f_name[s-1]!='~')){
			if(dir->d_type==DT_DIR){
				f_name = dir->d_name;
				//printf("\n%d : %s\n",cnt++,f_name);
				insertalpha(&t , f_name , cnt++);
				chk++;
			}
			if(!chk){
				//printf("%s\thello",dir->d_name);
				f_name = dir->d_name;
				//int length = strlen(f_name);
				f_name = strtok(f_name ,".");
				//printf("\n%d : %s\n",cnt++,f_name);
				insertalpha(&t , f_name , cnt++);
			}
		}
	}
	int j = 1;
	inorderalpha(t , &j );
	closedir(d);
	
	if(!chk){
		decider = 1;
		scanf("%d", &getnum_of_shop);
		while(getnum_of_shop > cnt-1 || getnum_of_shop<=0){
			printf("\nEnter valid input...\n");
			scanf("%d", &getnum_of_shop);
		}
		j = 0;
		int k = getpsuedonum(t , getnum_of_shop , &j );
		modify_userpath(path , k);
	}
	return ;	
}


void user_get_next_folder(char* dir_path ){
	DIR* d;struct dirent* dir;
	char* file_name;
	char req_path[500],reqfolder_path[500]; 
	int cnt,getnum_of_shop;
	cnt =1;
	
	printf("Enter the value:");
	scanf("%d",&getnum_of_shop);
	int j = 0;
	int k = getpsuedonum(t , getnum_of_shop , &j );
	cnt=1;
	d=opendir(dir_path);
	while((dir=readdir(d))){
		file_name = dir->d_name;
		int s = strlen(dir->d_name);
		if((s>2) && (file_name[s-1]!='~')){
			if(dir->d_type==DT_DIR ){
				if(cnt == k  ){
					strcpy(reqfolder_path,dir_path);
					strcat(reqfolder_path,file_name);
					strcat(reqfolder_path,"/");
					break;
				}
				cnt++;
			}
		}
	}
	closedir(d);
	user_folder_input(reqfolder_path );
}



char* main_for_userpath(){
	//char* path ="/home/dell/Desktop/coep/rajdsa/project/shops/";
	char* path = "./shops/";
	user_folder_input(path );
	return pathforuser;
}
