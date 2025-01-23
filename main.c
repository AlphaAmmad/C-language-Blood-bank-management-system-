#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct login
{
	char username[30];
	char password[30];
	int us5erType;
};

struct donor
{
	int donorID;
	char donorName[30];
	char donorBloodType[3];
};

struct patient
{
	int patientID;
	char patientName[30];
	char patientBloodType[3];
};

struct bloodBank
{
	int bloodID;
	char bloodType[3];
	int numberOfUnits;
};



void login();
void registration();
void donorList();
void patientList();
void bloodBankList();
void addDonor();
void addPatient();
void addBlood();


struct login user[100];
struct donor donors[100];
struct patient patients[100];
struct bloodBank bloodBanks[100];



int main()
{
    FILE *fp;
fp = fopen("donors.txt", "w");
fwrite(donors, sizeof(struct donor), 100, fp);
fclose(fp);
	int choice;
	printf("Welcome to the Blood Bank Management System\n\n");
	printf("1. Login\n");
	printf("2. Registration\n");
	printf("3. Donor List\n");
	printf("4. Patient List\n");
	printf("5. Blood Bank List\n");
	printf("6. Add Donor\n");
	printf("7. Add Patient\n");
	printf("8. Add Blood\n");
	printf("9. Exit\n");
	printf("\nPlease enter your choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			donorList();
			break;
		case 4:
			patientList();
			break;
		case 5:
			bloodBankList();
			break;
		case 6:
			addDonor();
			break;
		case 7:
			addPatient();
			break;
		case 8:
			addBlood();
			break;
		case 9:
			printf("Thank you for using our system.\n");
			exit(0);
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			main();
			break;
	}

	return 0;
}


void login()
{
	char username[30];
	char password[30];
	int flag = 0;
	int i;

	printf("\nPlease enter your username: ");
	scanf("%s", username);
	printf("Please enter your password: ");
	scanf("%s", password);

	for(i=0; i<100; i++)
	{
		if(strcmp(user[i].username, username) == 0 && strcmp(user[i].password, password) == 0)
		{
			flag = 1;
			if(user[i].userType == 0)
			{
				printf("\nWelcome, Admin!\n\n");
			}
			else
			{
				printf("\nWelcome, User!\n\n");
			}
			break;
		}
	}
	if(flag == 0)
	{
		printf("\nInvalid username or password. Please try again.\n\n");
		login();
	}
	else
		main();
}

void registration()
{
	char username[30];
	char password[30];
	int userType;
	int i;

	printf("\nPlease enter your desired username: ");
	scanf("%s", username);
	printf("Please enter your desired password: ");
	scanf("%s", password);
	printf("Are you an admin (0) or a user (1)? ");
	scanf("%d", &userType);

	for(i=0; i<100; i++)
	{
		if(strcmp(user[i].username, username) == 0 && strcmp(user[i].password, password) == 0)
		{
			printf("\nUsername and password already exist. Please try again.\n\n");
			registration();
		}
		else
		{
			strcpy(user[i].username, username);
			strcpy(user[i].password, password);
			user[i].userType = userType;
			printf("\nRegistration successful!\n\n");
			break;
		}
	}
	main();
}

void donorList()
{
	int i;

	printf("\nDonor List\n\n");
	printf("ID\tName\t\tBlood Type\n");
	for(i=0; i<100; i++)
	{
		if(donors[i].donorID != 0)
		{
			printf("%d\t%s\t\t%s\n", donors[i].donorID, donors[i].donorName, donors[i].donorBloodType);
		}
	}

	main();
}

void patientList()
{
	int i;

	printf("\nPatient List\n\n");
	printf("ID\tName\t\tBlood Type\n");
	for(i=0; i<100; i++)
	{
		if(patients[i].patientID != 0)
		{
			printf("%d\t%s\t\t%s\n", patients[i].patientID, patients[i].patientName, patients[i].patientBloodType);
		}
	}

	main();
}

void bloodBankList()
{
	int i;

	printf("\nBlood Bank List\n\n");
	printf("ID\tBlood Type\tNumber of Units\n");
	for(i=0; i<100; i++)
	{
		if(bloodBanks[i].bloodID != 0)
		{
			printf("%d\t%s\t\t%d\n", bloodBanks[i].bloodID, bloodBanks[i].bloodType, bloodBanks[i].numberOfUnits);
		}
	}

	main();
}

void addDonor()
{
	int i;
	int donorID;
	char donorName[30];
	char donorBloodType[3];

	printf("\nPlease enter the donor ID: ");
	scanf("%d", &donorID);
	printf("Please enter the donor name: ");
	scanf("%s", donorName);
	printf("Please enter the donor blood type: ");
	scanf("%s", donorBloodType);

	for(i=0; i<100; i++)
	{
		if(donors[i].donorID == 0)
		{
			donors[i].donorID = donorID;
			strcpy(donors[i].donorName, donorName);
			strcpy(donors[i].donorBloodType, donorBloodType);
			printf("\nDonor added successfully!\n\n");
			break;
		}
	}

	main();
}

void addPatient()
{
	int i;
	int patientID;
	char patientName[30];
	char patientBloodType[3];

	printf("\nPlease enter the patient ID: ");
	scanf("%d", &patientID);
	printf("Please enter the patient name: ");
	scanf("%s", patientName);
	printf("Please enter the patient blood type: ");
	scanf("%s", patientBloodType);

	for(i=0; i<100; i++)
	{
		if(patients[i].patientID == 0)
		{
			patients[i].patientID = patientID;
			strcpy(patients[i].patientName, patientName);
			strcpy(patients[i].patientBloodType, patientBloodType);
			printf("\nPatient added successfully!\n\n");
			break;
		}
	}

	main();
}

void addBlood()
{
	int i;
	int bloodID;
	char bloodType[3];
	int numberOfUnits;

	printf("\nPlease enter the blood ID: ");
	scanf("%d", &bloodID);
	printf("Please enter the blood type: ");
	scanf("%s", bloodType);
	printf("Please enter the number of units: ");
	scanf("%d", &numberOfUnits);

	for(i=0; i<100; i++)
	{
		if(bloodBanks[i].bloodID == 0)
		{
			bloodBanks[i].bloodID = bloodID;
			strcpy(bloodBanks[i].bloodType, bloodType);
			bloodBanks[i].numberOfUnits = numberOfUnits;
			printf("\nBlood added successfully!\n\n");
			break;
		}
	}

	main();
}
