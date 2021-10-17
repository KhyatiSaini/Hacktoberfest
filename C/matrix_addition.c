/* matrix addition
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{ int  a[20][20],b[20][20],c[20][20];
  int r1 , r2, c1;                              // variables are initialized
 int  c2 ,i,j;
  printf("input order of first matrix , first no of rows(R)  then no of columns(M) as R M\n");
  scanf("%d%d" , &r1,&c1);
  printf("input order of  matrix 2, , first no of rows(R)  then no of columns(M) as R M\n");
    scanf("%d%d" , &r2,&c2);
    if(r1!=r2 || c1!=c2){
        printf("invalid\n");
    }
  else {
      printf("input elements of matrix 1\n");
       
  for(i=0 ; i<r1; i++)
  {

      for(j=0;j<c1;j++){
          scanf("%d" , &a[i][j]);                   // scanning values of matrix 1
          printf("%d" , a[i][j]);                  // printing values of matrix 1
      }
      printf("\n");
  }
   
     printf("input elements of matrix 2\n");
     
     for(i=0 ; i<r2; i++)
  {
      for(j=0;j<c2;j++){
          scanf("%d" , &b[i][j]);         // scanning values of matrix 2
          printf("%d" , b[i][j]);        // printing values of matrix 2
      
      }
      printf("\n");
  }
    printf("Matrix after addition is:\n");             // adding both the matrices
     for(i=0 ; i<r2; i++)                             // loop will execute equal to no of rows
  {
      for(j=0;j<c2;j++){                              // loop will execute equal to no of columns
          c[i][j]= a[i][j]+b[i][j];                     //adding both the matrices
          printf("%d" , c[i][j]);                    // printing the final matrix
      }
      printf("\n");                                // for adding line break
  }
}
    return 0;
}

