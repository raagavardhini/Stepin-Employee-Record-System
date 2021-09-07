/**
 * @file function.c
 * @author raaga.vardhini@ltts.com
 * @brief 
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "main.h"
void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
    long int recsize; /// size of each record of employee
     FILE *fp, *ft; /// file pointers
    char another, choice;
    struct emp{
        char name[40]; ///name of employee
        int age; /// age of employee
        float bs; /// basic salary of employee
    };
    struct emp e; /// structure variable creation
 
 void  Add_Record(){
     fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
                                        /// here 0 indicates moving 0 distance from the end of the file
                another = 'y';
                while(another == 'y'){ /// if user want to add another record
                    flush();
                    printf("\nEnter name: ");
                    fgets(e.name, 40, stdin);
                    printf("\nEnter age: ");
                    scanf("%d", &e.age);
                    printf("\nEnter basic salary: ");
                    scanf("%f", &e.bs);
 
                    fwrite(&e,recsize,1,fp); /// write the record in the file
 
                    printf("\nAdd another record(y/n) ");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
 }
 