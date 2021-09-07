/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.11
 *
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "main.h"

    char empname[40]; /// string to store name of the employee
 
    long int recsize; /// size of each record of employee
    
     FILE *fp, *ft; /// file pointers
    char another, choice;

 void List_Record(){
     rewind(fp); ///this moves file cursor to start of the file
                while(fread(&e,recsize,1,fp)==1){ /// read the file and fetch the record one record per fetch
                    printf("\n%s %d %.2f\n",e.name,e.age,e.bs); /// print the name, age and basic salary
                }
 }

 void Modify_Record(){
another = 'y';
                while(another == 'y'){
                    printf("Enter the employee name to modify: ");
                    scanf("%s", empname);
                    rewind(fp);
                    while(fread(&e,recsize,1,fp)==1){ /// fetch all record from file
                        if(strcmp(e.name,empname) == 0){ ///if entered name matches with that in file
                            printf("\nEnter new name,age and bs: ");
                            scanf("%s%d%f",e.name,&e.age,&e.bs);
                            fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                            fwrite(&e,recsize,1,fp); /// override the record
                            break;
                        }
                    }
                    printf("\nModify another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }

 }

 void Delete_Record(){
another = 'y';
                while(another == 'y'){
                    flush();
                    printf("\nEnter name of employee to delete: ");
                    fgets(empname,40, stdin);
                    ft = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                    rewind(fp); /// move record to starting of file
                    while(fread(&e,recsize,1,fp) == 1){ /// read all records from file
                        if(strcmp(e.name,empname) != 0){ /// if the entered record match
                            fwrite(&e,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("EMP.DAT"); /// remove the orginal file
                    rename("Temp.dat","EMP.DAT"); /// rename the temp file to original file name
                    fp = fopen("EMP.DAT", "rb+");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
 }

 void Exit(){
             fclose(fp);  /// close the file
                exit(0); /// exit from the program
 }


int main(){

 
    /// sizeo of each record i.e. size of structure variable e
    recsize = sizeof(e);

    /** open the file in binary read and write mode
    * if the file EMP.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL){
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
    }
 
    /// infinite loop continues untile the break statement encounter
    while(1){
        printf("1. Add Record\n"); /// option for add record
        printf("2. List Records\n"); /// option for showing existing record
        printf("3. Modify Records\n"); /// option for editing record
        printf("4. Delete Records\n"); /// option for deleting record
        printf("5. Exit\n"); /// exit from the program
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        scanf("\n%c", &choice); /// get the input from keyboard
        switch(choice){
            case '1':  /// if user press 1
                Add_Record();
                break;
            case '2':
                List_Record();
                break;
 
            case '3':  /// if user press 3 then do editing existing record
                Modify_Record();
                break;
            case '4':
                Delete_Record();
                break;
            case '5':
                Exit();
        }
    }
    return 0;
}