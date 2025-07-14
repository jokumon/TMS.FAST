#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100



// FUNCTION DECLARATIONS
int mainmenu();
void manager_menu();
void finance_menu();
void student_menu();
void saveDataToFile();
void loadDataFromFile();
void updateRoutes();




//GLOBAL DECLARATIONS/INITIALIZATIONS
char studentname[MAX][25], studentid[MAX][8], studentpswrd[MAX][4];
int count=0; //counter for number of students
int studentroute[100];
int* routes;



//STRUCTURE DEFINITION
struct feesinfo{
		int fees;
		char status[11];
		float scholarship;
	};
struct feesinfo stdfees[100]= {0};



//SHOWING MAIN SCREEN
int main(){
	int routenums[100];  // Assuming MAX_ROUTES is the maximum number of routes
	int i;
	time_t t;
	time(&t);
	system("cls");   // FOR CLEARING SCREEN
	printf("\n\n\n");
	printf("\t\t\t\t\t\t ========================================================================= \n");
	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|     ---------------------------------------------------------------     |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|      [  T R A N S P O R T    M A N A G E M E N T    S Y S T E M  ]      |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|     ---------------------------------------------------------------     |\n");
 	printf("\t\t\t\t\t\t|                        ___________________                              |\n");
 	printf("\t\t\t\t\t\t|                       | [] [] [] [] [] [] |                             |\n");
 	printf("\t\t\t\t\t\t|                        ====0========0====                               |\n");
	printf("\t\t\t\t\t\t ========================================================================= \n\n\n");


		for(i=0;i<84;i++)
		printf(" -");
	    printf("\n Current date and time : %s\n",ctime(&t));

		for(i=0;i<84;i++)
		printf(" -");

    printf("\n Project Submitted by: 23K-0501 RAMEEN ZEHRA\n");
    printf("                       23K-0790 M. AHMED AMIR\n");
    printf("                       23K-0737 M. HANZALA Jamil\n");
	printf("\t\tClass: 1C \n\t\tGroup: 2\n");
	printf(" Project Submitted to: MS. ZAINAB ASIF ");

	printf("\n \n Press any key to continue:");

	getch();

// delaying opening the menu
	printf("\n Going to login menu in ...");
	sleep(1);
	int s;
     for (s = 3; s > 0; s--) {
        printf("%d...", s);
        Sleep(300); 
    }
    printf("\n");
system("cls");
mainmenu();
	

}



//MAIN MENU
int mainmenu(){
	int i,num=0; //tracking number
    int* numptr=&num; //accesing num = number of routes 
    loadDataFromFile(numptr);
	system("cls");
	int choice, a;
int mpswrd, managerpassword=12345;
int fpswrd, financepassword=678;
printf("**********************************************\n"
       "*       WELCOME TO POINT MANAGEMENT          *\n"
       "*            PORTAL OF FAST NU!              *\n"
       "**********************************************\n\n");

//printing menu
printf("Please choose an option from the following menu: \n1.Manager\n2.Finance Manager\n3.Student\n4.Exit\nYour option: ");
scanf(" %d",&choice);
int c;
while ((c = getchar()) != '\n' && c != EOF);
switch (choice){
	
	case 1: //manager
	{
		system("cls");
	for(a=0;a<3;a++){
		printf("Please enter your password: ");
		scanf("%d",&mpswrd);
		int c;
        while ((c = getchar()) != '\n' && c != EOF);
			int inc=0;
			
			if (mpswrd == managerpassword) {
				;
				 system("cls");
				 manager_menu(numptr);
				 break;
				
			}
			else {
				printf("You entered incorrect password!\n\n");
			}
		
			}
printf("\nYou're out of attempts!! Press any key to go back to main menu ...");
getch();
mainmenu();
		
		
	break;
	} 
	case 2: //finance manager
	{
			system("cls");
	for(a=0;a<3;a++){
		printf("Please enter your password: ");
		scanf("%d",&fpswrd);
			int inc=0;
			int c;
            while ((c = getchar()) != '\n' && c != EOF);
			if (fpswrd == financepassword) {
				 system("cls");
				 finance_menu(numptr);
				 break;
				
			}
			else {
				printf("You entered incorrect password!\n\n");
			}
		
			}
printf("\nYou're out of attempts!! Press any key to go back to main menu ...");
getch();
mainmenu();
		
	break;
	}
	case 3: //student
	{
		system("cls");
		int i,a;
		char Spassword[4];
		char SId[7];
		for(a=0;a<3;a++){
			printf("Enter your Id: ");
			scanf("%s", &SId);
			printf("Enter your 4 character passcode: ");
			scanf("%s", Spassword);
			for(i=0;i<count;i++){
				if(strcmp(SId,studentid[i])==0  &&  strncmp(Spassword,studentpswrd[i],4)==0){

					student_menu(i,numptr);
					break;
				}
			}
			if(i==count){
				printf("Invalid Id or Password. Please enter your id and password again!\n\n");
			}
			else
			break;
			
		}
		if(a==3){
			printf("You are out of attempts. ");
			printf("Press any key to go back to menu...\n");
			getch();
			mainmenu();
		}

	break;
	}
	case 4: //exiting
	{	
		//save data before exitting
	    free(routes);
		exit(0);
	break;
	}
	default: //wrong option
	{
		int c;
	    printf("Enter Valid Options (1-4) Only\nPress any key to continue......");
	    getch();
	    mainmenu();
	}
}
}



//MANAGER MENU ACCESS ACCEPTED
void manager_menu(int* numptr){
	int i=0;
while(1){
	system("cls");
		int choice=0;
		int inputroute=0;
		int check=0;
		managermenu: //Edition/Deletion and Reading of Fees decisions, No. of Buses on a Route, No. of Routes, and Fees check, exit option
	//	printf("%s",studentpswrd[0]);
	printf("Manager menu: \n------------\n1.Students list \n2.Bus Routes \n3.Add a student\n4.Exit \nYour choice: ");
	scanf("%d",&choice);
	int c;
    while ((c = getchar()) != '\n' && c != EOF);  
	switch(choice){
	case 1: {
    // Display student list
    system("cls");
    if (count == 0) {
        printf("No student data has been entered yet! Press any key to go back ..");
        getch();
        break;
    }

    printf("ID\t\tName\t\t\tRoute\n");
    printf("-----------------------------------------------\n");

    for (i = 0; i < count; i++) {
        // Remove the newline character from the student name
        size_t length = strlen(studentname[i]);
        if (length > 0 && studentname[i][length - 1] == '\n') {
            studentname[i][length - 1] = '\0';
        }

        printf("%-10s\t%-20s\t%d\n", studentid[i], studentname[i], studentroute[i]);

    }

    printf("\nPress any key to return to the menu...");
    getch();
    break;
}

		case 2:{
			system("cls");
			int choice1,temp,j;
			
			printf("Bus Info Menu\n-------------\n1.Add/Delete Route\n2.Display\n3.Exit\nYour choice: ");
			scanf("%d",&choice1);
			int c;
            while ((c = getchar()) != '\n' && c != EOF);
			if(choice1==1)
			{
				system("cls");
				choice1=0;
				printf("Please choose an option to proceed:\n1.Add\n2.Delete\nYour choice: ");
				scanf("%d",&choice1);
					int c;
               		while ((c = getchar()) != '\n' && c != EOF);
                if(choice1<1||choice1>2){
                	printf("Invalid input!Press any key to go back...");
                
					getch();
                    manager_menu(numptr);
				}
				routeinput1:
				inputroute=0;
				printf("Route number (not 0): ");
				scanf("%d",&inputroute);
                while ((c = getchar()) != '\n' && c != EOF);
                if(inputroute==0){
                	printf("Error, invalid input\nReminder: A bus route cant be 0");
                	goto routeinput1;
				}
				check=0;
				if(choice1==1)
					{
						//validation of input
							check=0;
							for(i=0;i<(*numptr);i++){
								if(inputroute==routes[i]){
									check=1;
								}
							}
							if(check==1){
								printf("Route is already present! Press any key to go back ...");
								getch();
								manager_menu(numptr);
							}else{
									routes = (int *) realloc(routes, ((*numptr)+1) * sizeof(int));
									routes[(*numptr)]=inputroute;
									*numptr=*numptr+1;
									updateRoutes(numptr);
									printf("Added successfully! Press any key to go back to menu... ");
									getch();
								}
					}
					else if(choice1==2)
					{
	
							//validation of input
							check=0;
							for(i=0;i<(*numptr);i++){
								if(inputroute==routes[i]){
									check=1;
								}
							}
							if(check==0){
								printf("Route not found, press:\n1 to re-enter route\n2 to go back\nYour choice: ");
								scanf("%d",&choice);
								int c;
	                            while ((c = getchar()) != '\n' && c != EOF);
								if(choice==1){
									system("cls");
									goto routeinput1;}
									else
									manager_menu(numptr);}
							//end
						for(i=0;i<*numptr;i++)
						{
							if(routes[i]==inputroute)
							{
								int j;
								for(j=i;j<(*numptr)-1;j++)
								{
									temp=routes[j+1];
									routes[j+1]=routes[j];
									routes[j]=temp;
								}
							}
						}
						routes = (int *) realloc(routes, ((*numptr)-1) * sizeof(int));
						*numptr=*numptr-1;
						updateRoutes(numptr);
						printf("Removed successfully! Press any key to go back to menu... ");
						getch();
					}
			}
			else if(choice1==2) //not to be confused with the one above, this is the else of the first main if
			{
				system("cls");
				printf("Bus Routes:\n------------\n1.Display All\n2.Search a bus route\n3.Exit\n------------\nYour Choice: ");
				scanf("%d",&choice1);
				int c;
                while ((c = getchar()) != '\n' && c != EOF);
				switch(choice1){
					case 1:{
						system("cls");
						for(i=0;i<*numptr;i++)
						{
							printf("Route %d:\n",routes[i]);
							printf("----------\n");
							printf("Students:\n");
							check=0;
							for(j=0;j<count;j++)
							{
								if(studentroute[j]==routes[i])
								{
									printf("\t\t%s---%s\n",studentid[j],studentname[j]);
									check=1;
								}
							}
							if(check==0)
								printf("\t\t No student");
								
							printf("\n\n");
							 
						}
						printf("\n-------------------\nPress any key to go back");
						getch();
						break;
					}
					case 2:{
						int check1=0;
						printf("Enter route number to display students: ");
						scanf("%d",&inputroute);
						int c;
                        while ((c = getchar()) != '\n' && c != EOF);
						for(i=0;i<*numptr;i++)
						{
							if(routes[i]==inputroute)
							{
								printf("\t\t  Route %d:\n",routes[i]);
								printf("\t\t ----------\n");
								printf("\t\t  Students:\n");
								check1=1;
								check=0;
								for(j=0;j<count;j++)
								{
									if(studentroute[j]==routes[i])
									{
										printf("\t%s---%s\n",studentid[j],studentname[j]);
										check=1;
									}
								}
								if(check==0)
									printf("\t\t No student");
									
								printf("\n\n");
							 }
							 
						}
						if(check1==0){
							printf("No such route found");
						}
                            printf("\n-------------------\nPress any key to go back");
							getch();
							break;
					}//inner switch case 2
					case 3:{
						mainmenu();
						break;
					}
					default:{
						printf("Input valid option...\nPress any key to continue...");
                        getch();
						mainmenu();
					}
					}//inner switch
				}//else if of choice1==2
		

			break;
		}//main switch case 2
		case 3:{
			// add student
			system("cls");
			char input[25],input1[8];
//tag1234
			int inputroute;
			printf("Enter student ID: ");
			scanf("%8s",studentid[count]);
//			strcpy(studentid[count],input1);
//			while(getchar() != '\n');
			//fflush(stdin);
			
			strcpy(studentpswrd[count],  studentid[count] + strlen(studentid[count]) - 4);
		
			printf("Enter student name: ");
			scanf(" %[^\n]",studentname[count]);
			
//			fgets(input, sizeof(input), stdin);
//			strcpy(studentname[count],input);
			
			routeinput:
			printf("Which route number bus is the student taking: ");
			scanf("%d", &inputroute);
			int c;
            while ((c = getchar()) != '\n' && c != EOF);
			//check if that route is avalaible 
			check=0;
			for(i=0;i<*numptr;i++){
				if(inputroute==routes[i]){
					check=1;
				}
			}
			if(check==1){
				studentroute[count]=inputroute;
				
				printf("Student successfully added. Press any key to continue...");
			}
			else{
				printf("Route not found, press:\n1.Re-enter route\n2.Return to menu\nYour choice: ");
				scanf("%d",&choice);
				int c;
                while ((c = getchar()) != '\n' && c != EOF);
				if(choice==1)
					goto routeinput;
				else
					manager_menu(numptr);
			}
			
			count++;
			saveDataToFile();
			getch();
			break;
		}
		case 4:{
			mainmenu();
			break;
		}
		default:{
			printf("Enter valid option...\nPress any key to continue...");  
            getch();
            manager_menu(numptr);
			break;
		}
			
	}
}
	
}



//FINANCE MANAGER MENU
void finance_menu(int* numptr){
	
	while(1){
	system("cls");
		int choice;
		int choice1,i,j;
//Edition/Deletion and Reading of Fees decisions and Fees check, exit option
	printf("Finance Manager menu: \n--------------------\n1.Students list \n2.Fees statistics\n3.Exit \nYour choice: ");
	scanf("%d",&choice);
	int c;
    while ((c = getchar()) != '\n' && c != EOF);
	switch(choice){
		case 1:{
			
				FILE *finances = fopen("finances.txt", "r");
if (finances != NULL) {
    int i = 0;
    while (fscanf(finances, "%s %d %f %s", studentid[i], &stdfees[i].fees, &stdfees[i].scholarship, stdfees[i].status) != EOF) {
        i++; // Move to the next index for the next student's data
    }
    fclose(finances);
} else {
    printf("Error opening finances file for reading.\n");
}
			system("cls");
			if(count==0){
				printf("No student data has been entered yet! Press any key to go back ..");
				getch();
				break;
			}
			int i=0;
			for(i=0;i<count;i++){
				printf("\n\nStudent %d\n", i + 1);
			    printf("----------\n");
			    printf("Id: %s\n", studentid[i]);
			    printf("Name: %s\n", studentname[i]);
				printf("Fees: %d scholarship: %.2f status:%s",stdfees[i].fees,(stdfees[i].scholarship)*100,stdfees[i].status);					
			}
			printf("\n-------------------\nPress any key to go back");
			getch();
			system("cls");

			break;
		}
		case 2:{
			system("cls");
			printf("1.Edit fees\n2.View Fees\n3.Exit\nour Choice: ");
			scanf("%d",&choice1);
			int c;
            while ((c = getchar()) != '\n' && c != EOF);
			switch(choice1){
				case 1:{
					system("cls");
					printf("Editing fees - Enter student ID to edit fees: ");
		            char input[7];
		            scanf("%s", input);

		            for (i = 0; i < count; i++) {
		                if (strcmp(studentid[i], input) == 0) {
		                    printf("Enter fees for %s-%s: ", studentname[i],studentid[i]);
		                    scanf("%d", &stdfees[i].fees);
		                    int c;
                            while ((c = getchar()) != '\n' && c != EOF);
		                    printf("Enter the scholarship in form (0.xx): ");
		                    scanf("%f", &stdfees[i].scholarship);
                            while ((c = getchar()) != '\n' && c != EOF);
		                    printf("Enter status (paid/due/late): ");
		                    scanf("%s", stdfees[i].status);
		                    
		                    
						     FILE *finances = fopen("finances.txt", "a");
				            if (finances != NULL) {
				                fprintf(finances, "%s %d %.2f %s\n", studentid[i], stdfees[i].fees, stdfees[i].scholarship, stdfees[i].status);
				                fclose(finances);
				            } else {
				                printf("Error opening finances file.\n");
				            }

		                    
		                    
		                    printf("Fees info updated\n");
		                    break;
		                }
		            }
		
		            if (i == count) {
		                printf("Student not found.\n");
		            }//if end
		            
		            	FILE *finances = fopen("finances.txt", "w"); // Use "w" to overwrite existing content
if (finances != NULL) {
	int i;
    for ( i = 0; i < count; i++) {
        fprintf(finances, "%s %d %.2f %s\n", studentid[i], stdfees[i].fees, stdfees[i].scholarship, stdfees[i].status);
    }
    fclose(finances);
    printf("Fees info updated\n");
} else {
    printf("Error opening finances file for writing.\n");
}
	
			            getch();
			            break;
						}//case 1 inside
					case 2:
					{
						
							FILE *finances = fopen("finances.txt", "r");
if (finances != NULL) {
    int i = 0;
    while (fscanf(finances, "%s %d %f %s", studentid[i], &stdfees[i].fees, &stdfees[i].scholarship, stdfees[i].status) != EOF) {
        i++; // Move to the next index for the next student's data
    }
    fclose(finances);
} else {
    printf("Error opening finances file for reading.\n");
}
						    
						    
						system("cls");
						if(count==0){
						printf("No student data has been entered yet! Press any key to go back ..");
						getch();
						break;
						}else
						{

						printf("1. Ascending order\n2. Descending order\nYour choice: ");
   						scanf("%d", &choice1);
   						int c;
                        while ((c = getchar()) != '\n' && c != EOF);
   						//creating temporary storage
   						struct feesinfo* tempstdfees = (struct feesinfo*) malloc(count * sizeof(struct feesinfo));
   						//2d DMAs
					    char(**tempstudentid) = (char**)malloc(count * sizeof(char*));
					    
						for (i=0;i<count;i++) 
						{
						   tempstudentid[i]=(char*) malloc(7 * sizeof(char));
						}
					    char(**tempstudentname)= (char**)malloc(count * sizeof(char*));
					    
						for (i = 0; i<count;i++) 
						{
						   tempstudentname[i] = (char*) malloc(25*sizeof(char));
						}
						//
					    int* tempstudentroute=(int*) malloc(count*sizeof(int));
					
					    // Copy values from OG arrays to temp DMA arrays
					    for (i=0;i<count;i++) {
					        tempstdfees[i] = stdfees[i];
					        strcpy(tempstudentid[i], studentid[i]);
					        strcpy(tempstudentname[i], studentname[i]);
					        tempstudentroute[i] = studentroute[i];
					    }
					
					    // Sorting on temporary arrays
					    for (i=0;i<count;i++) {
					        for (j=i;j<count;j++) {
					            if (choice1 == 1 && (tempstdfees[i].fees)> tempstdfees[j].fees) {
					                struct feesinfo temp1;
					                temp1 = tempstdfees[i];
					                tempstdfees[i] = tempstdfees[j];
					                tempstdfees[j] = temp1;
					
					                // Swap student information
					                char temp2[25];
					                strcpy(temp2, tempstudentid[i]);
					                strcpy(tempstudentid[i], tempstudentid[j]);
					                strcpy(tempstudentid[j], temp2);
					
					                strcpy(temp2, tempstudentname[i]);
					                strcpy(tempstudentname[i], tempstudentname[j]);
					                strcpy(tempstudentname[j], temp2);
					
					                int temp3 = tempstudentroute[i];
					                tempstudentroute[i] = tempstudentroute[j];
					                tempstudentroute[j] = temp3;
					            }
					
					            if (choice1 == 2 && tempstdfees[i].fees < tempstdfees[j].fees) {
					                struct feesinfo temp1;
					                temp1 = tempstdfees[i];
					                tempstdfees[i] = tempstdfees[j];
					                tempstdfees[j] = temp1;
					
					                // Swap student information
					                char temp2[25];
					                strcpy(temp2, tempstudentid[i]);
					                strcpy(tempstudentid[i], tempstudentid[j]);
					                strcpy(tempstudentid[j], temp2);
					
					                strcpy(temp2, tempstudentname[i]);
					                strcpy(tempstudentname[i], tempstudentname[j]);
					                strcpy(tempstudentname[j], temp2);
					
					                int temp3 = tempstudentroute[i];
					                tempstudentroute[i] = tempstudentroute[j];
					                tempstudentroute[j] = temp3;
					            }
					        }
					    }
					
					    // Print sorted values from temporary arrays
					    for (i = 0; i < count; i++) {
					        printf("\nStudent %d\n", i + 1);
					        printf("----------\n");
					        printf("Id: %s\n", tempstudentid[i]);
					        printf("Name: %s\n", tempstudentname[i]);
					        printf("Fees: %d scholarship: %.2lf%% - %s\n", tempstdfees[i].fees, (tempstdfees[i].scholarship * 100), tempstdfees[i].status);

					    }
					    printf("\n\npress any key to go back to menu ...");
					getch();
					    // Free dynamically allocated memory
					    free(tempstdfees);
					    free(tempstudentid);
					    free(tempstudentname);
					    free(tempstudentroute);
					}//else end
						break;
					}//case 2 inside
					
					case 3:{
						mainmenu();
						break;
					}
					default:{
						printf("Wrong input, rediracting to main menu.........");
						mainmenu();
					}
        			}//switch inside
				break;
				}//case 2 switch outside
			
		case 3:{
			mainmenu();
			break;
		}
		default:
			{
				printf("Wrong option");
				finance_menu(numptr);
			}
	}
	
}
}



//STUDENT ACCESS
void student_menu(int pos,int* numptr){
	int choice;
	system("cls");
	printf("Student Menu\n------------\n1.Check my details\n2.Edition in My Route Number\n3.Change Password\n4.Exit\nYour Option: ");
	scanf("%d",&choice);
	int c;
    while ((c = getchar()) != '\n' && c != EOF);
	switch(choice){
		case 1://Displaying Details
		{
			system("cls");
			printf("Student Name: %s\n", studentname[pos]);
			printf("Student ID: %d\n", studentid[pos]);
			printf("Current Route Number: %d\n", studentroute[pos]);
			printf("Press any key to go back to menu\n");
			getch();
			student_menu(pos,numptr);
			break;
		}
		case 2:
		{
			int NewChoice,check=0;
			printf("Your Current Route Number: %d\n", studentroute[pos]);
			printf("Your new route number: ");
			scanf("%d", &NewChoice);
			int c;
            while ((c = getchar()) != '\n' && c != EOF);
            int i;
			for(i=0;i<*numptr;i++){
				if(NewChoice==routes[i]){
					check=1;
				}	
			}
			if(check==0){
					printf("Route not found, redirecting to menu...");
					sleep(1);
					student_menu(pos,numptr);
				}
			studentroute[pos]= NewChoice;//Assigning new Route Number
			
			printf("------Edited successfully-------\n");
			saveDataToFile();
			printf("Your New Route Number: %d",studentroute[pos]);
			check=0;
			printf("\nPress any key to go back to menu\n");
			getch();
			student_menu(pos,numptr);
			break;
			
		}
		case 3:{
		    int j;
		    char New_Pass[4];
		    printf("Enter New Password: ");
		    scanf("%4s",&New_Pass);
		    for(j=0;j<MAX;j++){

		    }
		    if(j==MAX){
		        strncpy(studentpswrd[pos],New_Pass,4);
		        printf("Your New Password is: %s", New_Pass);
		    }
		    else{
		        printf("Entered Password is Already Taken.... Try Another");
		        student_menu(pos,numptr);
		    }
		    printf("\nPassword successfully changed. Press any key to continue...");
		    saveDataToFile();
		    getch();
			student_menu(pos,numptr);
			break;
		}
		case 4:{
		    mainmenu();
		}
			
	}
}



//SAVING ALL DATA TO FILE
void saveDataToFile() {
    FILE *fp = fopen("student_data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    //savin gcount first
    fprintf(fp, "%d\n\n", count);

    //saving students data
    int i;
    for (i = 0; i < count; i++) {
    fprintf(fp, "Id: %s\n", studentid[i]);
    fputs("Name: ", fp);
    fputs(studentname[i], fp);
    fprintf(fp, "\nRoute: %d\n\n", studentroute[i]);
}


    fclose(fp);
    // saving passwords in another file so passwords are not visible to everyone
    FILE *fcode = fopen("student_passwords.txt", "w");
if (fcode == NULL) {
    printf("Error opening file!\n");
    return;
}
for (i = 0; i < count; i++) {
    fprintf(fcode, "%.4s\n", studentpswrd[i]);
}
fclose(fcode);

}



//RETRIEVING ALL DATA FROM FILE
void loadDataFromFile(int* numptr) {
FILE *fp = fopen("student_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // getting count
    fscanf(fp, "%d", &count);
    int i;
    char idLabel[10], nameLabel[10], routeLabel[10];

    for (i = 0; i < count; i++) {
        fscanf(fp, "%s %s %s", idLabel, studentid[i], nameLabel);
        // Check if the labels are correct
        if (strcmp(idLabel, "Id:") != 0 || strcmp(nameLabel, "Name:") != 0) {
            printf("Error reading data from file!\n");
            fclose(fp);
            return;
        }
      
		fgetc(fp);
        // Read the name using fgets
        fgets(studentname[i], sizeof(studentname[i]), fp);
        // Remove the trailing newline character if present
        studentname[i][strcspn(studentname[i], "\n")] = '\0';

        fscanf(fp, "%s %d", routeLabel, &studentroute[i]);

        // Check if the label is correct
        if (strcmp(routeLabel, "Route:") != 0) {
            printf("Error reading data from file!\n");
            fclose(fp);
            return;
        }
        // Consume the trailing newline
        fgetc(fp);
    }

    fclose(fp);

    
    FILE *fcode = fopen("student_passwords.txt", "r");
    if (fcode == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        if (fscanf(fcode, "%s", studentpswrd[i]) != 1) {
            printf("Error reading password from file!\n");
           sleep(1000);
            return;
        }
    }
     fclose(fcode);
    //load routes
   FILE *fproutes = fopen("routes.txt", "r");
    if (fproutes == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fscanf(fproutes,"%d",numptr); // Read the number of routes first
    routes = (int*)calloc(*numptr, sizeof(int));

    for (i = 0;i<*numptr;i++) {
        fscanf(fproutes, "%d", &routes[i]);
      
    }

    fclose(fproutes);
}



//UPDATING ROUTES FILE
void updateRoutes(int* numptr) {
	int i;
    	FILE *fp = fopen("routes.txt", "w");
	    if (fp == NULL)
		{
	        printf("Error opening routes file!\n");
	        return;
	    }
	    fprintf(fp, "%d\n", *numptr);
	    for(i=0;i<*numptr;i++)
		{
	    	fprintf(fp, "%d\n", routes[i]);
		}
		fclose(fp);
    
}



