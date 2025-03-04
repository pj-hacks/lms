/**
 * Developer: Joseph prince aniekeme
 * Date: 1 : 3 : 2025
 * Description: This is a mimi library that help student get access to lots of books for learning purpose
 *Assosted by: GOD
 **/

#include <stdio.h>
#include "utility.h"
#include "Book_search.h"
#include "User_Management.h"

int main(){
  char *Title;
  char *Author;
  char *user_name;
  int action;
    printf("\n Welcone to mallot book shelf\n");
    printf("This library is free and you do not need to pay for anything, so this is all you can do with this library\n\n1:Borrow books\n2:Share books\n3:Searcy for books\n");
    printf("What is your name: ");
    fgets(user_name, sizeof(user_name), stdin);
    remove_newline(user_name);
    // User_Creation(user_name);

    int checker = 0;
    checker = User_Search( user_name );

    if ( checker == 2 ){
        User_Creation( user_name );
    }

    printf("%d\n", checker);

    if( checker == 2 ){
      printf("\nWhat do you want to do.");
      printf("\n1:Borrow books\n2:Search book\n3:Return book.\n");
      printf("> ");
      if(scanf("%d",&action) != 1){
        printf("Invalid input. Please enter a number.\n");
      }
      clear_buffer();
      if(action == 1){
        printf("Working on it\n");
      }
      else if( action == 2 ){
        printf("\nWhat is the Title of the book? ");
        fgets( Title, sizeof(Title), stdin);
        remove_newline(Title);
        printf("\nWho is the Author of the book? ");
        fgets( Author, sizeof(Author), stdin);
        remove_newline( Author );
        Book_search( Title, Author);
      }
      else if( action == 3 ){
        printf("\nStill working on it");
      }
    }

    return 0;
}
