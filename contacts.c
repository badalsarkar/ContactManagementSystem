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
#include "contactHelpers.h"
#include <string.h>


//Function declarations

/* ++++++++++++++++++++++++++++++++++++++++
 getName:
 This function will get user name details
 ++++++++++++++++++++++++++++++++++++++++++*/

void getName(struct Name* name)
{
	// get first name
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);

	// Clearing the input buffer so that next input is 
	// taken from user in stead of the input buffer
	clearKeyboard();

	// get middle initial
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		// Clearing the input buffer so that next input is 
		// taken from user in stead of the input buffer
		clearKeyboard();
	}

	// get last name
	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", name->lastName);

	// Clearing the input buffer so that next input is 
	// taken from user in stead of the input buffer
	clearKeyboard();
}	






/* +++++++++++++++++++++++++++++++++++
 getAddress:
 this function will get user address
 +++++++++++++++++++++++++++++++++++++*/

void getAddress(struct Address* address)
{
    // variable used to check if the integer is positive or negative
	int positiveInt;	
	// get street number
	// number must be positive integer
	// if user enter negative integer, show error message
	do {
		printf("Please enter the contact's street number: ");
		positiveInt = getInt();
		if (positiveInt > 0) {
			address->streetNumber = positiveInt;
		}
	} while (positiveInt < 0);

	// get street name
	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", address->street);
	// Clearing the input buffer
	clearKeyboard();
	// get apt. number
	// number must be positive integer
	// if user enter negative integer, show error message
	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes() == 1) {
		do {
			printf("Please enter the contact's apartment number: ");
			positiveInt = getInt();
			if (positiveInt > 0) {
				address->apartmentNumber = positiveInt;
			}
		} while (positiveInt < 0);
	}
	// get postal code
	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", address->postalCode);
	// Clearing the input buffer
	clearKeyboard();
	// get city 
	printf("Please enter the contact's city: ");
	scanf("%40[^\n]", address->city);
	// Clearing the input buffer
	clearKeyboard();
}	// End of function







/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 getNumbers:
 this function will get phone numbers from user
 NOTE:  Also modify this function so the cell number is
        mandatory (don't ask to enter the cell number)
 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void getNumbers(struct Numbers* number)
{
	// get cell phone number
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(number->cell);

	// get home phone number
	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(number->home);
	}

	// get business phone number
	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(number->business);
	}
}	








/* +++++++++++++++++++++++++++++++++++++++++++++++
 getContact
 this function wil get contact details from user
 and update the releted constructs
 ++++++++++++++++++++++++++++++++++++++++++++++++*/

void getContact(struct Contact *contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}	

