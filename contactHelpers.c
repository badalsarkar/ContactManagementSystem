/* -------------------------------------------
Name:Badal Sarkar
Student number:<137226189>
Email:bsarkar2@myseneca.ca
Section:Q
Date:December 01, 2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include <string.h>
#include "contactHelpers.h"

#define MAXCONTACTS 5

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------



/* ++++++++++++++++++++++++++++++++
 function: clearKeyboard
 Clear the standard input buffer
 ++++++++++++++++++++++++++++++++++*/
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}	




/* ++++++++++++++++++++++++++++++++++++++++++
 function: pause
 this function pause the program untill user 
 press enter button
 +++++++++++++++++++++++++++++++++++++++++++*/
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
	printf("\n");
}	




/* +++++++++++++++++++++++++++++++++++++++++++++
 function: getInt
 this function get an integer input from user
 any value except integer is invalid
 ++++++++++++++++++++++++++++++++++++++++++++++*/

int getInt(void)
{
	char NL = 'x';
	int value;
	do {
		scanf("%d%c", &value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (NL != '\n');
	return value;
}	




/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++
 function: getIntInRange
 this function get an integer within a range
 non-integer value and value outside range are invalid
 ++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int getIntInRange(int lowerBound, int upperBound)
{
	int value;
	do {
		value = getInt();
		if (value < lowerBound || value > upperBound) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lowerBound, upperBound);
		}
	} while (value < lowerBound || value > upperBound);
	return value;
}	






/* +++++++++++++++++++++++++++++++++++++++++++++++++++++
 function: yes
 this function accept only one character for yes/ no 
 any value except 'Y', 'y', 'N', 'n' are invalid
 +++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int yes(void)
{
	char input;
	int result;
	char NL, validInput;
	// accept input from buffer
	// check if the input meet the requirement
	// repeat unless input requirement is met
	do {
		scanf(" %c%c", &input, &NL);
		//check if user entered more than one character
		// if one character is entered
		// check if user entered valid character and update the resut
		if (NL == '\n') {
			if (input == 'Y' || input == 'y') {
				result = 1;
				validInput = 'y';
			}
			else if (input == 'n' || input == 'N') {
				result = 0;
				validInput = 'y';
			}
			else {
				validInput = 'n';
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			}
		}
		// if user entered more than one character,
		// clear keyboard
		// print error message
		else {
			clearKeyboard();
			validInput = 'n';
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	} while (validInput == 'n');
	return result;
}	








/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 function: menu
 this function prints the menu to user
 and get user choice and validate user choice against the range
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int menu(void)
{
	int option;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	option = getIntInRange(0, 6);
	printf("\n");
	return option;
}	







// ++++++++++++++++++++++++++++++++++++++++++++++++++++++
// function: contactManagerSystem
// this function perform action based 
// on user selected choice and displays relevent menue item 
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++
void contactManagerSystem(void)
{
	int option;
	int quit;
	struct Contact contact[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
												{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
												{ "4161112222", "4162223333", "4163334444" } },
											{
												{ "Maggie", "R.", "Greene" },
												{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
												{ "9051112222", "9052223333", "9053334444" } },
											{
												{ "Morgan", "A.", "Jones" },
												{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
												{ "7051112222", "7052223333", "7053334444" } },
											{
												{ "Sasha", {'\0'}, "Williams" },
												{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
												{ "9052223333", "9052223333", "9054445555" } },
											};
	do {
		switch (option = menu()) {
		case 1:
			displayContacts(contact, MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(contact, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(contact, MAXCONTACTS);
			pause();
			break;
		case 4:
			deleteContact(contact, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(contact, MAXCONTACTS);
			pause();
			break;
		case 6:
			sortContacts(contact, MAXCONTACTS);
			pause();
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			quit = yes();
			printf("\n");
			if (quit == 1)
				printf("Contact Management System: terminated\n");
		}
	} while (option != 0 || (option == 0 && quit == 0));
}	










/* ++++++++++++++++++++++++++++++++++++++++++++++++++++
 function: getTenDigitPhone
 this function accept 10 digit entered by user
 shows error message if user enter non-numeric value
/ +++++++++++++++++++++++++++++++++++++++++++++++++++*/

void getTenDigitPhone(char telNum[])
{
	int needInput = 1;
	// only accept numeric value
	while (needInput == 1) {
		scanf("%10[0-9]", telNum);
		// clear input buffer
		clearKeyboard();
		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}	







/* +++++++++++++++++++++++++++++++++++++++++++
 findContactIndex:
 this function finds a cell phone number
 in the contact structure and returns the index number
 +++++++++++++++++++++++++++++++++++++++++++++*/
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
    // this will hold the search result
	int result=-1;	
	// iterate through all items 
	// match the cell phone number
	// return -1 if not found
	for (i = 0; i < size; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
			result = i;
			break;
		}
	}
	return result;
}	









/* ++++++++++++++++++++++++++++++++
 displayContactHeader
 this function prints the header 
 ++++++++++++++++++++++++++++++++++*/
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}	








/* +++++++++++++++++++++++++++++++++++++
 displayContactFooter
 this function prints the footer
 ++++++++++++++++++++++++++++++++++++++*/
void displayContactFooter(int a)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", a);
}	









/* ++++++++++++++++++++++++++++++++++++++++
 displayContact:
 this function prints the contact details
 for a specific contact
 ++++++++++++++++++++++++++++++++++++++++++*/
void displayContact(const struct Contact* contact){
	// check for middle initial
	// print contact name
	if (contact->name.middleInitial[0] == '\0')
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	else
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);

	// print contact numbers
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	// print contact address
	// check first if there is apt. number 

	if (contact->address.apartmentNumber > 0)
		printf("       %u %s, Apt# %u, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, 
												  contact->address.city, contact->address.postalCode);
	else
		printf("       %u %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
}	











/* +++++++++++++++++++++++++++++++
 displayContacts:
 this function displays all
 contacts with cell phone number
 +++++++++++++++++++++++++++++++*/
void displayContacts(const struct Contact contact[], int a)
{
	int i;
	int totalValidContact=0;
	displayContactHeader();
	// iterate through all element and check if there is cell number
	// print the details of contact if there is cell number
	for (i = 0; i < a; i++) {
		if (contact[i].numbers.cell[0] > 0) {
			displayContact(&contact[i]);
			totalValidContact++;
		}
	}
	displayContactFooter(totalValidContact);
}	








/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 searchContacts:
 This function search a contact based on cell phone number
 user enter the cell phone number
 if the match is found it prints details of the contact in screen
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void searchContacts(const struct Contact contact[], int a)
{
	char cellNumber[11];
	int index;
	// get cell phone number from user
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	// find the cell phone in the contact database
	index=findContactIndex(contact, a, cellNumber);
	// display contact details if found
	if (index != -1) {
		printf("\n");
		displayContact(&contact[index]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n\n");
}	







/* +++++++++++++++++++++++++++++++++++++++++++++++++
 addContact
 this function looks for empty slots in the array
 if there is empty slot, it accept user input 
 and add it in the contact
 +++++++++++++++++++++++++++++++++++++++++++++++++*/
void addContact(struct Contact contact[], int index)
{
	int i;
	int emptySlot = 0;
	// iterate through each array element to find empty slot
	for (i = 0; i<index; i++) {
		// if there is empty slot add the contact details
		// and exit the loop
		if (strlen(contact[i].numbers.cell) == 0) {
			getContact(&contact[i]);
			emptySlot = 1;
			printf("--- New contact added! ---\n\n");
			break;
		}
	}
	// if there is no empty slot show the error message
	if (emptySlot == 0)
		printf("*** ERROR: The contact list is full! ***\n\n");

}	








/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 updateContact:
 this function find a contact based on cell phone number
 if contact is found, it ask if user wants to update it
 user can update the contact details within the function
 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void updateContact(struct Contact contact[], int a)
{
	char cellNumber[11];	// array to hold user entered cell phone number
	int index;				// variable to hold the position where a match is found

	// get cell phone number from user
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	// find the cell phone number in the database
	index = findContactIndex(contact, a, cellNumber);
	// print to user if not found
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n\n");
	}
	// if found display the contact details
	// update contact details
	else {
		printf("\nContact found:\n");
		displayContact(&contact[index]);
		printf("\n");
		// update contact name
		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1) {
			// empty the existing record
			contact[index].name = (struct Name) { {'\0'} };
			// get new name
			getName(&contact[index].name);
		}
		// update contact address
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) {
			// empty existing record
			contact[index].address = (struct Address) { 0, { '\0' }, 0, { '\0' }, { '\0' } };
			// get new address
			getAddress(&contact[index].address);
		}
		// update numbers
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			//empty existing record
			contact[index].numbers = (struct Numbers) { {'\0'} };
			// get new number
			getNumbers(&contact[index].numbers);
		}
		printf("--- Contact Updated! ---\n\n");
	}
}










/* +++++++++++++++++++++++++++++++++++
 deleteContact:
 this function deletes contact info
 +++++++++++++++++++++++++++++++++++*/
void deleteContact(struct Contact contact[], int a){
	char cellNumber[11];
	int index;

	// get cell phone number from user
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	// find the cell phone number in the database
	index = findContactIndex(contact, a, cellNumber);
	// print to user if not found
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	// if found, display the contact details
	// then delete contact details
	else {
		printf("\nContact found:\n");
		displayContact(&contact[index]);
		printf("\n");
		// delete the contact details
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1) {
			contact[index] = (struct Contact)
			{ { { '\0' } },
			{ 0, {'\0'}, 0, {'\0'}, {'\0'} },
			{ {'\0'} }
			};
			printf("--- Contact deleted! ---\n");
		}
		printf("\n");
	}
}	









/* +++++++++++++++++++++++++++++++++++++++
 sortContacts:
 this function sorts the contact in 
 ascending order by cell phone number
 +++++++++++++++++++++++++++++++++++++++*/
void sortContacts(struct Contact contact[], int a)
{
	int i, j;
	struct Contact tempContact;
	int lowestIndex;
	// take one element and compare it with all other element
	// change position to put the smaller one at the front
	for (i = 0; i < (a-1); i++) {
		lowestIndex = i;
		for (j = i+1; j < a; j++) {
			// if the first element is bigger than second element
			// swap position
			if (strcmp(contact[lowestIndex].numbers.cell, contact[j].numbers.cell) > 0) {
				// swap position
				lowestIndex = j;
			}
		}
		tempContact = contact[i];
		contact[i] = contact[lowestIndex];
		contact[lowestIndex] = tempContact;
	}
	printf("--- Contacts sorted! ---\n\n");
}	
