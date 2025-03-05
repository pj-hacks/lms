#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utility.h"

int Book_search( char *Title){
    char book_tile[200];
    printf("\nThere are a lot of books in here for you to explore.\nA wise man once said if you want to hide anything put it in a book, so you are here to dig out the hiden secret\n");
    FILE *File_search;
    File_search = fopen("books.txt", "r");

    if (File_search == NULL){
        printf("\nUnable to open file\n");
        return 1;
    }
    else{
        while( fgets( book_tile, sizeof(book_tile), File_search)){
	  remove_newline(book_tile);
            if ( strcmp( book_tile, Title) == 0){
                printf("Book found, wow now you don't need to waste time grab this great book and increase your knowledge\n");
		return 2;
            }
        }
    }
    printf("\nBook not found..... Try again later you can as well apply for the book\n");
    return 0;
}

int Book_Request(char Title[]){
  printf("\nYou have successfully requested for a book and you will get an email shortly.\n");

  FILE *Book_request_file;
  Book_request_file = fopen("Book_request.txt", "a");
  if ( Book_request_file == NULL){
    printf("\nUnable to open file\n");
    return 1;
  }
  if ( fprintf(Book_request_file, "%s\n", Title) < 0){
    perror("\nUnable to open file.\n");
  }
  return 0;
}
