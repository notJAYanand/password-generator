#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

string generatePassword(int length)
{
	string capitalLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string smallLetters = "abcdefghijklmnopqrstuvwxyz";
	string numbers = "1234567890";
	string special = "!@#$%^&*_=+-/.?<>)";

	//All the characters at our disposal for password generation.
	string values = capitalLetters + smallLetters + numbers + special;

	//Resultant password string.
	string password = "";

	// srand() sets the seed which is used by rand to generate “random” numbers.
	// If we don’t call srand before our first call to rand, it’s as if you had called srand(1) to set the seed to one.
	// In short, srand() — Set Seed for rand() Function.
	srand(time(0));

	//Taking out characters at random index to form the password.
	for (int i = 0; i < length; i++)
	{
		password.push_back(values[0 + rand() % values.size()]);
	}

	//Finally returning the generated password.
	return password;
}

void savePassword(string password)
{
	// Creation of ofstream class object
	ofstream fout;
	string line = password;

	// by default ios::out mode, automatically deletes
	// the content of file. To append the content, open in ios:app
	// fout.open("password.txt", ios::app)
	fout.open("password.txt");
	
	// Write line in file
	fout << line << endl;

	// Close the File
	fout.close();
}
int main()
{
	char option='x';
	cout << "welcome" << endl;
	cout << "--------------------------------" << endl;

	//Length of the password user requires. 
	int length;

	cout << "enter length :- ";
	cin >> length;
	cout << "--------------------------------" << endl;

	//Resultant Password
	string password;

	//We keep on generating new passwords until user is satisfied. 
	while (option != 'y')
	{
	password = generatePassword(length);
	cout << password << endl;
	cout << "--------------------------------" << endl;
	cout << "Are you satisfied with your password? (y/n): ";
	cin >> option;
	}

	cout << "--------------------------------" << endl;

	//Asking if user wants to save the password locally in a .txt file.
	cout << "Want to save the password locally? (y/n): ";
	cin >> option;
	if (option == 'y')
	{
		savePassword(password);
		cout << "--------------------------------" << endl;
		cout << "Open password.txt to view your  locally saved password. Thank you for using. :)";
	}

	return 0;
}