#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Book_Management.h"


#define MAX_LINE 256
time_t current_time;


int Borrow_book(char Title[], char username[], char school[]){
  current_time = time(NULL);
  printf("Due date is : next two week.\n");
  
  FILE *Borrowing_book_file;
  Borrowing_book_file = fopen("record.txt", "a");
  
  FILE *history_file;
  history_file = fopen("history.txt", "a");
  
  if ( Borrowing_book_file == NULL || history_file == NULL ){
    perror("Unable to open file.\n");
    return 1;
  }

  fprintf(Borrowing_book_file, "Title: %s\n" , Title);
  fprintf(Borrowing_book_file, "Name: %s\n" , username);
  fprintf(Borrowing_book_file, "School: %s\n" , school);
  fprintf(Borrowing_book_file, "Time: %s\n\n", ctime(&current_time));

  fprintf(history_file, "%s borrowed by %s from the library on %s\n\n", Title, username, ctime(&current_time));
  fclose(Borrowing_book_file);
  fclose(history_file);
  return 0;
}


int Return_book(char Title[], char user_name[]){

  current_time = time(NULL);
  printf("Thank you for returning the book\n");

  FILE *returning_book_file = fopen("record.txt", "r");
  FILE *temp_file = fopen("temp.txt", "w");
  FILE *history_file = fopen("history.txt", "a");

  if (returning_book_file == NULL || temp_file == NULL || history_file == NULL ){
    perror("Unable to open file.\n");
    return 1;
  }

  fprintf(history_file, "%s returned %s on %s\n", user_name, Title, ctime(&current_time));
  char line[MAX_LINE];
  int inBlock = 0;
  int keepBlock = 1;

  while ( fgets(line, MAX_LINE, returning_book_file)){
    if(strncmp(line, "Title:", 6) == 0){
      inBlock = 1;
      keepBlock = !strstr(line, Title);
    }

    if (keepBlock){
      fputs(line, temp_file);
    }

    if (strcmp(line, "\n") == 0){
	inBlock = 0;
      }
  }

  fclose(returning_book_file);
  fclose(temp_file);
  fclose(history_file);
  
  remove("record.txt");
  rename("temp.txt", "record.txt");
      
  return 0;
}


int Add_book( char Title[], char username[]){
  return 0;
}
