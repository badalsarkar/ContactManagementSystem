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

#ifndef CONTACTS_H_
#define CONTACTS_H_

/*------------------------------------------------------
 Structure Types
--------------------------------------------------------*/


// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};


// Structure type Address declaration
struct Address {
	unsigned int streetNumber;
	char street[41];
	unsigned int apartmentNumber;
	char postalCode[8];
	char city[41];
};



// Structure type Numbers declaration
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};



// Structure type Contact declaration
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};



/*------------------------------------------------------
 Function Prototypes
--------------------------------------------------------*/

// Get and store from standard input the values for Name
void getName(struct Name*);


// Get and store from standard input the values for Address
void getAddress(struct Address*);


// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers*);


// Get and store from standard input the values for a Contact
void getContact(struct Contact *);


#endif // !CONTACTS_H_
