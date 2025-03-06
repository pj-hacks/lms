#include <stdio.h>
#include <string.h>
#include "utility.h"


int File_exists(const char *filename){
  FILE *file = fopen(filename, "r");
  if(file){
    fclose(file);
    return 1;
  }
  return 0;
}

void create_file(const char *filename){
  if(!File_exists(filename)){
    FILE *file = fopen(filename, "w");
    if(file){
      printf("Created missing file: %s\n",filename);
      fclose(file);
    }
    else {
      printf("Failed to create file: %s\n", filename);
    }
  }
}

int User_Creation(char name[]) {
    printf("\nAn account have been successfully created for you\n");
    printf("\nname = %s ", name);

    FILE *user_file;
    user_file = fopen("User.txt", "a");
    if (user_file == NULL) {
        perror("\nUnable to open file");
        return 1;
    }

    if ( fprintf(user_file, "%s\n", name) < 0){
      perror("Unable to open file.\n");// Use fprintf() with a format string
    }
    fclose(user_file);

    return 0;
}

int User_Search(char *namep){
    char user_name[200];
    FILE *user_file;
    user_file = fopen("User.txt", "r");
    if(user_file == NULL){
        perror("\nUnable to open file");
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

