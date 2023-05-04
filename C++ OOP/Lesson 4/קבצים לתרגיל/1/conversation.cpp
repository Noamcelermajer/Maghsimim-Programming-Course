#include "ShiftText.h"
#include "SubstitutionText.h"
#include "CaesarText.h"
#include "FileHelper.h"
#include "BonusText.h"
#include <iostream>

#define SHIFTING_KEY 10
#define SUB_DICTIONARY_FILE_NAME "dictionary.csv"
#define ENCRYPTED_FILE_NAME "encrypted.txt"

using std::cout;
using std::endl;

// local functions
void Alice();
PlainText Bob(SubstitutionText msg);
PlainText Bob(ShiftText msg);
PlainText Bob(CaesarText msg);

/*
This is the main function of the program.
It starts the conversation between Alice and Bob
*/
int main()
{
	Alice();
	return 0;
}

/*
This is Alice's part in the conversation.
It gets a legal string from the user ans sends it to Bob in
three different kinds of encryptions.
It also prints every response from Bob.
*/
void Alice()
{
	std::string str;
	cout << "Alice:" << endl;
	cout << "Enter a message to send to Bob:" << endl;
	std::cin >> str;
	cout << endl;

	PlainText receive("");

	cout << "Sending in Substitution mode..." << endl;
	receive = Bob(SubstitutionText(str, SUB_DICTIONARY_FILE_NAME));
	cout << endl << "Alice:" << endl << "Received back: " << receive.getText() << endl;

	cout << "Sending in Shift mode..." << endl;
	receive = Bob(ShiftText(str, SHIFTING_KEY));
	cout << endl << "Alice:" << endl << "Received back: " << receive.getText() << endl;

	cout << "Sending in Caesar mode..." << endl;
	receive = Bob(CaesarText(str));
	cout << endl << "Alice:" << endl << "Received back: " << receive.getText() << endl;
}

/*
This function handles Bob's part of the conversation 
when he receives a message encrypted in Substitution mode
*/
PlainText Bob(SubstitutionText msg)
{
	cout << endl << "Bob:" << endl;
	cout << "The received message: " << msg.getText() << endl;
	cout << "The decrypted message is: " << msg.decrypt() << endl;
	return PlainText("Thank you Alice!");
}

/*
This function handles Bob's part of the conversation
when he receives a message encrypted in Shift mode
*/
PlainText Bob(ShiftText msg)
{
	cout << endl << "Bob:" << endl;
	cout << "The received message: " << msg.getText() << endl;
	cout << "The decrypted message is: " << msg.decrypt() << endl;
	
	return PlainText("Thank you again Alice!");
}

/*
This function handles Bob's part of the conversation
when he receives a message encrypted in Caesar mode
*/
PlainText Bob(CaesarText msg)
{
	cout << endl << "Bob:" << endl;
	cout << "The received message: " << msg.getText() << endl;
	cout << "The decrypted message is: " << msg.decrypt() << endl;
	return PlainText("Many Thanks Alice!");
}