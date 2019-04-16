#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structs
typedef struct {
	char username[20];
	char password[7];
}login;

struct patient {
	int ppsNum;
	char firstName[15];
	char surname[15];
	int yearBorn;
	char gender [8];
	char email[40];
	char nextKinFirst[15];
	char nextKinSurname[15];
	char lastAppointment[20];
	float weight;
	float height;
	char allergiesMeds[50];
	char cigPerDay[50];
	char alcholUnitsPerWeek[50];
	char exercise[50];

	struct patient* NEXT;
};

// Functions
void menu(struct patient* top);
void addPatientAtStart(struct patient** top);
void addPatient(struct patient* top);
void displayPatientsDetails(struct patient* top);
void displayPatientDetails(struct patient* top);
void updatePatientDetails(struct patient* top);
void deletePatientAtStart(struct patient** top);
void deletePatient(struct patient* top);
void generalStats(struct patient* top);
void printPatientDetailsToFile(struct patient* top);
void listPatientsFromCountries(struct patient* top);
bool verifyPPSNumber(struct patient* top, int verifyPPS);


void main() {
	FILE* loginFile;
	login user;
	login verify;
	int varRead;
	struct patient* headPtr = NULL;

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
		menu(headPtr);

	}//end of else : if fail to login
}

void menu(struct patient* top) {
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
			if (top == NULL)
				addPatientAtStart(&top);
			else{
				addPatient(top);
			}
			break;
		case 2:
			displayPatientsDetails(top);
			break;
		case 3:
			displayPatientDetails(top);
			break;
		case 4:
			updatePatientDetails(top);
			break;
		case 5:
			deletePatient(top);
			break;
		case 6:
			generalStats(top);
			break;
		case 7:
			printPatientDetailsToFile(top);
			break;
		case 8:
			listPatientsFromCountries(top);
			break;
		case -1:
			exit(0);
	}

}

void addPatientAtStart(struct patient** top) {
	struct patient* newPatient;
	char fName[15], sName[15];
	newPatient = (struct patient*)malloc(sizeof(struct patient));

	printf("New Patient\n_______________\n");
	printf("PPS Number : ");
	scanf("%d", &newPatient->ppsNum);
	printf("\n");
	printf("First Name :");
	scanf("%s", newPatient->firstName);
	printf("\n");
	printf("Surname : ");
	scanf("%s", newPatient->surname);
	printf("\n");
	printf("Year Born : ");
	scanf("%d", &newPatient->yearBorn);
	printf("\n");
	printf("Gender : ");
	scanf("%s", newPatient->gender);
	printf("\n");
	printf("Email Address : ");
	scanf("%s", newPatient->email);
	printf("\n");
	printf("Next of Kin Name : ");
	scanf("%s %s", newPatient->nextKinFirst, newPatient->nextKinSurname);
	printf("\n");
	printf("Last Appointment : ");
	scanf("%s", newPatient->lastAppointment);
	printf("\n");
	printf("Weight : ");
	scanf("%f", &newPatient->weight);
	printf("\n");
	printf("Height : ");
	scanf("%f", &newPatient->height);
	printf("\n");
	printf("Does the patient have any allergies to medication ? \n");
	scanf("%s", newPatient->allergiesMeds);
	printf("\n");
	printf("How many cigarettes would you smoke per day? \n");
	scanf("%s", newPatient->cigPerDay);
	printf("\n");
	printf("How much alcohol would you drink per week? \n");
	scanf("%s", newPatient->alcholUnitsPerWeek);
	printf("\n");
	printf("How often do you exercise? \n");
	scanf("%s", newPatient->exercise);
	printf("\n");

	newPatient->NEXT = *top;
	*top = newPatient;
	menu(*top);
}

void addPatient(struct patient* top) {
	struct patient* temp = top;
	struct patient* newPatient;
	int verifyPPS;
	bool uniquePPS = false;

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	printf("New Patient\n_______________\n");
	printf("PPS Number : ");
	scanf("%d", &verifyPPS);
	printf("\n");
	// boolean method to verify pps
	uniquePPS = verifyPPSNumber(top, verifyPPS);

	// unique pps check
	if (uniquePPS == true) {
		newPatient = (struct patient*)malloc(sizeof(struct patient));
		newPatient->ppsNum = verifyPPS;

		printf("First Name :");
		scanf("%s", newPatient->firstName);
		printf("\n");
		printf("Surname : ");
		scanf("%s", newPatient ->surname );
		printf("\n");
		printf("Year Born : ");
		scanf("%d", &newPatient ->yearBorn );
		printf("\n");
		printf("Gender (M or F) : ");
		scanf("%s", newPatient ->gender );
		printf("\n");
		printf("Email Address : ");
		scanf("%s", newPatient ->email );
		printf("\n");
		printf("Next of Kin Name : ");
		scanf("%s %s", newPatient ->nextKinFirst, newPatient->nextKinSurname);
		printf("\n");
		printf("Last Appointment : ");
		scanf("%s", newPatient ->lastAppointment );
		printf("\n");
		printf("Weight : ");
		scanf("%f", &newPatient ->weight );
		printf("\n");
		printf("Height : ");
		scanf("%f", &newPatient ->height );
		printf("\n");
		printf("Does the patient have any allergies to medication ? \n");
		scanf("%s", newPatient ->allergiesMeds );
		printf("\n");
		printf("How many cigarettes would you smoke per day? \n");
		scanf("%s", newPatient ->cigPerDay);
		printf("\n");
		printf("How much alcohol would you drink per week? \n");
		scanf("%s", newPatient ->alcholUnitsPerWeek );
		printf("\n");
		printf("How often do you exercise? \n"); 
		scanf("%s", newPatient ->exercise );

		newPatient->NEXT = NULL;
		temp->NEXT = newPatient;
	}
	else {
		printf("Not unique PPS Number");
	}

	printf("\n");
	menu(top);
}

void displayPatientsDetails(struct patient* top) {
	struct patient* temp = top;
	int counter = 0;
	while (temp != NULL)
	{
		counter++;
		printf("Patient : %d\n______________\n",counter);
		printf("PPS Number : %d", temp->ppsNum);
		printf("\n");
		printf("First Name : %s", temp->firstName);
		printf("\n");
		printf("Surname : %s", temp->surname);
		printf("\n");
		printf("Year Born : %d", temp->yearBorn);
		printf("\n");
		printf("Gender (M or F) : %s", temp->gender);
		printf("\n");
		printf("Email Address : %s", temp->email);
		printf("\n");
		printf("Next of Kin Name : %s %s", temp->nextKinFirst, temp->nextKinSurname);
		printf("\n");
		printf("Last Appointment : %s", temp->lastAppointment);
		printf("\n");
		printf("Weight : %.2f Kg", temp->weight);
		printf("\n");
		printf("Height : %.2f cm", temp->height);
		printf("\n");
		printf("Does the patient have any allergies to medication ? \n %s", temp->allergiesMeds);
		printf("\n");
		printf("How many cigarettes would you smoke per day? \n %s", temp->cigPerDay);
		printf("\n");
		printf("How much alcohol would you drink per week? \n %s", temp->alcholUnitsPerWeek);
		printf("\n");
		printf("How often do you exercise? \n %s", temp->exercise);
		printf("\n\n");

		temp = temp->NEXT;
	}

	printf("\n");
	menu(top);
}

void displayPatientDetails(struct patient* top) {
	int option;
	bool found = false;
	struct patient* temp = top;

	printf("Press   1) For entering Patient PPS or \nPress  2) For entering Name to search details \n");
	scanf("%d", &option);

	switch (option) {
	case 1:
		int PPS;

		printf("Enter PPS Number : ");
		scanf("%d", &PPS);

		while (temp->NEXT != NULL)
		{
			if (PPS == temp->ppsNum) {
				found = true;

				printf("PPS Number : %d", temp->ppsNum);
				printf("First Name : %s", temp->firstName);
				printf("Surname : %s", temp->surname);
				printf("Year Born : %d", temp->yearBorn);
				printf("Gender (M or F) : %s", temp->gender);
				printf("Email Address : %s", temp->email);
				printf("Next of Kin Name : %s %s", temp->nextKinFirst, temp->nextKinSurname);
				printf("Last Appointment : %s", temp->lastAppointment);
				printf("Weight : %f", temp->weight);
				printf("Height : %f", temp->height);
				printf("Does the patient have any allergies to medication ? \n %s", temp->allergiesMeds);
				printf("How many cigarettes would you smoke per day? \n %s", temp->cigPerDay);				printf("How much alcohol would you drink per week? \n %s", temp->alcholUnitsPerWeek);
				printf("How often do you exercise? \n %s", temp->exercise);
				printf("\n\n");
			}
			temp = temp->NEXT;
		}
		if (found == false) {
			printf("Patient not found!");
		}
		break;
	case 2: 
		char fName[18];
		char sName[18];
		

		printf("Enter Patient First Name and Surname : ");
		scanf("%s %s", fName, sName);

		while (temp != NULL)
		{
			if (strcmp(fName, temp->firstName) == 0 && strcmp(sName, temp->surname) == 0) {
				found = true;

				printf("PPS Number : %d", temp->ppsNum);
				printf("First Name : %s", temp->firstName);
				printf("Surname : %s", temp->surname);
				printf("Year Born : %d", temp->yearBorn);
				printf("Gender (M or F) : %s", temp->gender);
				printf("Email Address : %s", temp->email);
				printf("Next of Kin Name : %s %s", temp->nextKinFirst, temp->nextKinSurname);
				printf("Last Appointment : %s", temp->lastAppointment);
				printf("Weight : %f", temp->weight);
				printf("Height : %f", temp->height);
				printf("Does the patient have any allergies to medication ? \n %s", temp->allergiesMeds);
				printf("How many cigarettes would you smoke per day? \n %s", temp->cigPerDay);
				printf("How much alcohol would you drink per week? \n %s", temp->alcholUnitsPerWeek);
				printf("How often do you exercise? \n %s", temp->exercise);
				printf("\n\n");
			}
			temp = temp->NEXT;
		}
		if (found == false) {
			printf("Patient not found!");
		}
		break;
	}
	

	printf("\n");
	menu(top);
}

void updatePatientDetails(struct patient* top) {
	int option;
	bool found = false;
	struct patient* temp = top;

	printf("Press   1) For entering Patient PPS or \nPress  2) For entering Name to Update patient details \n");
	scanf("%d", &option);

	switch (option) {
	case 1:
		int PPS;

		printf("Enter PPS Number : ");
		scanf("%d", &PPS);

		while (temp->NEXT != NULL)
		{
			if (PPS == temp->ppsNum) {
				int verifyPPS;
				bool uniquePPS;
				printf("Update Patient Details\n_______________\n");
				printf("PPS Number : ");
				scanf("%d", &verifyPPS);
				printf("\n");
				// boolean method to verify pps
				uniquePPS = verifyPPSNumber(top, verifyPPS);

				// unique pps check
				if (uniquePPS == true) {
					temp->ppsNum = verifyPPS;

					printf("First Name :");
					scanf("%s", temp->firstName);
					printf("\n");
					printf("Surname : ");
					scanf("%s", temp->surname);
					printf("\n");
					printf("Year Born : ");
					scanf("%d", &temp->yearBorn);
					printf("\n");
					printf("Gender (M or F) : ");
					scanf("%s", temp->gender);
					printf("\n");
					printf("Email Address : ");
					scanf("%s", temp->email);
					printf("\n");
					printf("Next of Kin Name : ");
					scanf("%s %s", temp->nextKinFirst, temp->nextKinSurname);
					printf("\n");
					printf("Last Appointment : ");
					scanf("%s", temp->lastAppointment);
					printf("\n");
					printf("Weight : ");
					scanf("%f", &temp->weight);
					printf("\n");
					printf("Height : ");
					scanf("%f", &temp->height);
					printf("\n");
					printf("Does the patient have any allergies to medication ? \n");
					scanf("%s", temp->allergiesMeds);
					printf("\n");
					printf("How many cigarettes would you smoke per day? \n");
					scanf("%s", temp->cigPerDay);
					printf("\n");
					printf("How much alcohol would you drink per week? \n");
					scanf("%s", temp->alcholUnitsPerWeek);
					printf("\n");
					printf("How often do you exercise? \n");
					scanf("%s", temp->exercise);
				}
				else {
					printf("Not unique PPS Number");
				}
			}
		}
		if (found == false) {
			printf("Patient not found!");
		}
		break;
	case 2:
		char fName[18];
		char sName[18];


		printf("Enter Patient First Name and Surname : ");
		scanf("%s %s", fName, sName);

		while (temp->NEXT != NULL)
		{
			if (strcmp(fName, temp->firstName) == 0 && strcmp(sName, temp->surname) == 0) {
				int verifyPPS;
				bool uniquePPS;
				printf("Update Patient Details\n_______________\n");
				printf("PPS Number : ");
				scanf("%d", &verifyPPS);
				printf("\n");
				// boolean method to verify pps
				uniquePPS = verifyPPSNumber(top, verifyPPS);

				// unique pps check
				if (uniquePPS == true) {
					temp->ppsNum = verifyPPS;

					printf("First Name :");
					scanf("%s", temp->firstName);
					printf("\n");
					printf("Surname : ");
					scanf("%s", temp->surname);
					printf("\n");
					printf("Year Born : ");
					scanf("%d", &temp->yearBorn);
					printf("\n");
					printf("Gender (M or F) : ");
					scanf("%s", temp->gender);
					printf("\n");
					printf("Email Address : ");
					scanf("%s", temp->email);
					printf("\n");
					printf("Next of Kin Name : ");
					scanf("%s %s", temp->nextKinFirst, temp->nextKinSurname);
					printf("\n");
					printf("Last Appointment : ");
					scanf("%s", temp->lastAppointment);
					printf("\n");
					printf("Weight : ");
					scanf("%f", &temp->weight);
					printf("\n");
					printf("Height : ");
					scanf("%f", &temp->height);
					printf("\n");
					printf("Does the patient have any allergies to medication ? \n");
					scanf("%s", temp->allergiesMeds);
					printf("\n");
					printf("How many cigarettes would you smoke per day? \n");
					scanf("%s", temp->cigPerDay);
					printf("\n");
					printf("How much alcohol would you drink per week? \n");
					scanf("%s", temp->alcholUnitsPerWeek);
					printf("\n");
					printf("How often do you exercise? \n");
					scanf("%s", temp->exercise);
				}
				else {
					printf("Not unique PPS Number");
				}
			}
		}
		if (found == false) {
			printf("Patient not found!");
		}
		break;
	}


	printf("\n");
	menu(top);
}

void deletePatientAtStart(struct patient** top) {
	struct patient* temp = *top;
	
	*top = temp->NEXT;
	free(temp);
	printf("Successful deletion");

	printf("\n");
	menu(*top);
}

void deletePatient(struct patient* top) {
	struct patient* temp = top;
	struct patient* prev_temp = NULL;
	int deletePPS;

	printf("Delete Patient\n_______________");
	printf("Enter PPS number of Patient to Delete : ");
	scanf("%d", &deletePPS);
	printf("\n");

	while (temp->NEXT != NULL)
	{
		if (deletePPS == temp->ppsNum) {
			if (prev_temp == NULL) {
				deletePatientAtStart(&top);
			}

			prev_temp->NEXT = temp->NEXT;
			free(temp);
			printf("Successful deletion");
		}
		prev_temp = temp;
		temp = temp->NEXT;
	}

	printf("\n");
	menu(top);
}

void generalStats(struct patient* top) {
	printf("general stats");
	printf("\n");
	menu(top);
}

void printPatientDetailsToFile(struct patient* top) {
	printf("print patient details to file");
	printf("\n");
	menu(top);
}

void listPatientsFromCountries(struct patient* top) {
	printf("list patients from countires ");
	printf("\n");
	menu(top);
}

bool verifyPPSNumber(struct patient* top, int verifyPPS) {
	struct patient* temp = top;

	while (temp->NEXT != NULL)
	{
		if (verifyPPS == temp->ppsNum) {
			return false;
		}
		temp = temp->NEXT;
	}

	return true;
}