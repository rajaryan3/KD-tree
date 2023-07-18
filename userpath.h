#include <dirent.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>

char* main_for_userpath();    //the only fn we need to use to get respective item file to load tree

void user_get_next_folder(char* dir_path );
void user_display_content(char* path );
void user_folder_input(char* dir_path );
void modify_userpath(char* p , int c);
