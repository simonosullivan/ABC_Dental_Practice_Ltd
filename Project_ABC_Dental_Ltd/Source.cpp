#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structs
typedef struct {
	char username[20];
	char password[7];
}login;

// Functions
void menu();
void addPatient();
void displayPatientsDetails();
void displayPatientDetails();
void updatePatientDetails();
void deletePatient();
void generalStats();
void printPatientDetailsToFile();
void listPatientsFromCountries();


void main() {
	FILE* loginFile;
	login user;
	login verify;
	int varRead;

	printf("Username : ");
	scanf("%s", user.username);
	printf("\n");
	printf("Password : ");
	scanf("%s", user.password);
	printf("\n\n");

	loginFile = fopen("LoginFile.txt", "r");

	if (loginFile == NULL)//File was not opened
	{
		printf("Sorry the file was not opened\n");
	}
	else {
		while (!feof(loginFile))
		{
			varRead = fscanf(loginFile, "%s %s", verify.username, verify.password);
			if (varRead == 2)
			{
				if (strcmp(user.username, verify.username) == 0 && strcmp(user.password, verify.password) == 0) {
					printf("%s logged in \n\n", user.username);
					break;
				}
			}
		}
		fclose(loginFile);

		// Menu function
		menu();

	}//end of else : if fail to login
}

void menu() {
	int option = 0;
	bool numValid = false;
	
	while (numValid == false) {
		printf("1) Add patient \n");
		printf("2) Display all patient details to screen \n");
		printf("3) Display patient details \n");
		printf("4) Update a patient details \n");
		printf("5) Delete patient \n");
		printf("6) Generate statistics  \n");
		printf("7) Print all patient details into a report file \n");
		printf("8) List all the patients of the following countries in order of their last appointment \n");
		printf("-1 ) To exit application \n");
		printf("\n");
		printf("Please enter number of the option you want to pick \n");
		scanf("%d", &option);
		if (option > 0 && option < 9) {
			numValid = true;
		}
		else if (option == -1) {
			numValid = true;
		}
		else {
			printf("\n\nNumber you entered is not an option. Please try again \n\n");
		}
	}

	switch (option) {
		case 1:
			addPatient();
			break;
		case 2:
			displayPatientsDetails();
			break;
		case 3:
			displayPatientDetails();
			break;
		case 4:
			updatePatientDetails();
			break;
		case 5:
			deletePatient();
			break;
		case 6:
			generalStats();
			break;
		case 7:
			printPatientDetailsToFile();
			break;
		case 8:
			listPatientsFromCountries();
			break;
		case -1:
			exit(0);
	}

}

void addPatient() {
	printf(" add patient");
	printf("\n\n");
	menu();
}

void displayPatientsDetails() {
	printf("display all patients details");
	printf("\n\n");
	menu();
}

void displayPatientDetails() {
	printf("display patient details");
	printf("\n\n");
	menu();
}

void updatePatientDetails() {
	printf("update patient details");
	printf("\n\n");
	menu();
}

void deletePatient() {
	printf("delete patient");
	printf("\n\n");
	menu();
}

void generalStats() {
	printf("general stats");
	printf("\n\n");
	menu();
}

void printPatientDetailsToFile() {
	printf("print patient details to file");
	printf("\n\n");
	menu();
}

void listPatientsFromCountries() {
	printf("list patients from countires ");
	printf("\n\n");
	menu();
}