#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utility.h"

int Book_search( char *Author, char *Title){
    char book_tile[200];
    printf("There are a lot of books in here for you to explore.\nA wise man once said if you want to hide anything put it in a book, so you are here to dig out the hiden secret\n");
    FILE *File_search;
    File_search = fopen("books.txt", "a");

    if (File_search == NULL){
        printf("\nUnable to open file\n");
        return 1;
    }
    else{
        while( fgets( book_tile, sizeof(book_tile), File_search)){
	  remove_newline(book_tile);
            if ( strcmp( book_tile, Title) == 0){
                printf("Book found, wow now you don't need to waste time grab this great book and increase your knowledge\n");
		return 0;
            }
        }
    }
    return 0;
}
