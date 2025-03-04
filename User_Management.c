#include <stdio.h>
#include <string.h>
#include "utility.h"

int User_Creation(char name[]) {
    printf("\nAn account have been successfully created for you\n");
    printf("\nname = %s ", name);

    FILE *user_file;
    user_file = fopen("User.txt", "a");
    if (user_file == NULL) {
        printf("\nUnable to open file");
        return 1;
    }

    fprintf(user_file, "%s\n", name); // Use fprintf() with a format string
    fclose(user_file);

    return 0;
}

int User_Search(char *namep){
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
            fclose(user_file);
            return 0;
        }
    }
    return 2;

}

