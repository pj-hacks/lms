#include <stdio.h>
#include <string.h>
#include "utility.h"
#include "User_Management.h"


// int main(){
int User_Creation(char *name){
    printf("\nAn account have been successfully created for you\n");
    char user_name[200] = "";
    strcat(user_name, name);
    strcat(user_name, "\n");
    FILE *user_file;
    user_file = fopen("User.txt", "a");
    if(user_file == NULL){
        printf("\nUnable to open file");
        return 1;
    }
    fprintf(user_file, user_name);
    fclose(user_file);

    return 0;
}


int User_Search(char *namep){
    int flag = 1;
    char user_name[200];
    FILE *user_file;
    user_file = fopen("User.txt", "r");
    if(user_file == NULL){
        printf("\nUnable to open file");
        return 1;
    }
    while(fgets(user_name, sizeof(user_name), user_file)){
        remove_newline(user_name);
        if(strcmp(user_name, namep) == 0){
            printf("\nWelcome back to mallot book shlef\n");
            flag = 0;
            fclose(user_file);
            return 0;
        }
    }
    if (flag == 1){
        fclose(user_file);
        return 2;
    }

}

