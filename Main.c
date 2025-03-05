/**
 * Developer: Joseph prince aniekeme
 * Date: 1 : 3 : 2025
 * Description: This is a mimi library that help student get access to lots of
 *books for learning purpose Assosted by: GOD
 **/

#include "Book_search.h"
#include "Book_Management.h"
#include "User_Management.h"
#include "utility.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char Title[200];
  char user_name[200];
  int action = 1;
  char request[5];

  printf("\n Welcone to mallot book shelf\n");
  printf("This library is free and you do not need to pay for anything, so "
         "this is all you can do with this library\n\n1:Borrow books\n2:Share "
         "books\n3:Searcy for books\n");
  printf("What is your name?\n");
  printf("> ");
  fgets(user_name, sizeof(user_name), stdin);
  remove_newline(user_name);
  // User_Creation(user_name);

  int checker = 0;
  checker = User_Search(user_name);

  if (checker == 2) {
    User_Creation(user_name);
  }

  printf("%d\n", checker);

  if (checker == 2 || checker == 0) {
     while( action <= 4 && action >= 1 ){
        printf("\nWhat do you want to do.");
        printf("\n1:Borrow books\n2:Search book\n3:Return book\n4:Add book.\n");
        printf("> ");

        if(scanf("%d",&action) != 1){ 
	  printf("Invalid input. Please enter a number.\n");
        }
        clear_buffer();
	
        if(action == 1){ // Book borrow
	  printf("\nAll through history knowledge have been consealed in book.\nSo you are making the right decision to seek it.\n");
	  printf("For you to be given the book you need to provide the following information.\n");
	  
	  printf("What is your name?\n");
	  printf("> ");
	  fgets(user_name, sizeof(user_name), stdin);
	  remove_newline(user_name);
	  
	  printf("What is the Title of the book you need?\n");
	  printf("> ");
	  fgets(Title, sizeof(Title), stdin);
	  remove_newline(Title);
	  
	  char school[444];
	  printf("What is the name of your current school?\n");
	  printf("> ");
	  fgets(school, sizeof(school), stdin);
	  remove_newline(school);

	  Borrow_book(Title, user_name, school);
        }
	
        else if( action == 2 ){ //Search book
	  printf("\nWhat is the Title of the book?\n");
	  printf("> ");
	  fgets(Title, sizeof(Title), stdin);
	  remove_newline(Title);
	  checker =  Book_search(Title);
	  if( checker == 0 ){
	    printf("\nDo you want to request for the book?");
	    printf("\nyes or no \n");
	    fgets(request, sizeof(request), stdin);
	    remove_newline(request);
	    if ( strcmp(request, "yes") == 0){
	      Book_Request(Title);
	    }
	  }
        }
	
        else if( action == 3 ){ // Return book
	  printf("\nWhat is the title of the book you want to return?.\n");
	  printf("> ");
	  fgets(Title, sizeof(Title), stdin);
	  remove_newline(Title);
	  Return_book(Title, user_name);
        }
	
        else if( action == 4 ){ // Add book
	  printf("what is the title of the book you want to add\n");
	  printf("> ");
	  fgets(Title, sizeof(Title), stdin);
	  // Book_Add(Title);
        }
    }
  }

  return 0;
}
