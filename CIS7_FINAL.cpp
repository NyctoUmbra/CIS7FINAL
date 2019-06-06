//Programer:			Juan José Magaña-Paredes 
//Assignment:			Case 3: Vigenere Cipher Encryption/Decryption
//Filename:				CIS7_FINAL.cpp
//Creation Date:		05/16/2019
//Description:			The purpose of this program is to ...
//						create a C++ program that encrypts and decrypts a message from the user.
//						Also to demonstrate the Vigenere Ciphere square.
//Source Cited:			https://www.geeksforgeeks.org/vigenere-cipher/
//						This site was used to describe the example in the demo portion.

//Preprocessor Directive
#include <iostream>			//Header that defines the standard input and output stream objects
#include <string>			//Utilises string class
#include <iomanip>			//utilises the set class

using namespace std;

string generate_key(string, string);	//Function prototype
string encrypt(string, string);			//Function prototype
string decrypt(string, string);			//Function prototype

//Key computation
string generate_key(string str, string key)
{
	int x = str.size();
	
	for(int i = 0; i< str.size(); i++)
    {	
    //Generates the key in a cyclic manner until
	//it's length is equal to the length of original text  	
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);	
    }
    return key;
}

//Encryption computation
string encrypt(string str, string key)
{
	string encrypt_text;
 
    for(int i = 0, j = 0; i < str.size(); i++)
    {
	//Converting in range 0-25
		int x = (toupper(str[i]) + toupper(key[i])) %26; //toupper turns lowercase letters to capitals

	//Convert into alphabets(ASCII) 
		x += 'A'; 
		encrypt_text.push_back(x);
    }
    return encrypt_text;
}
  
//Decryption computation
string decrypt(string str, string key)
{
    string decrypt_text;

    for(int i = 0, j = 0; i < str.size(); i++)
    {
	//Converting in range 0-25 
		int x = (toupper(str[i]) - toupper(key[i]) + 26) %26; //toupper turns lowercase letters to capitals

	//Convert into alphabets(ASCII) 
		x += 'A'; 
		decrypt_text.push_back(x); 
    }
    return decrypt_text;
}

//This line of code begins a function (module) called main
int main ()			
{
//Variable declaration statements
	int choice,						//"int" is used to enter an integer
		i,
		j;

	string 	str,					//"string" is used to enter a string
			keyword,
			key,
			encrypt_text,
			decrypt_text;
	
//Initiative title of program		
	cout<<"\t _|      _|  _|                                                            "<<endl;
	cout<<"\t _|      _|        _|_|_|    _|_|    _|_|_|      _|_|    _|  _|_|    _|_|  "<<endl;
	cout<<"\t _|      _|  _|  _|    _|  _|_|_|_|  _|    _|  _|_|_|_|  _|_|      _|_|_|_|"<<endl;
	cout<<"\t   _|  _|    _|  _|    _|  _|        _|    _|  _|        _|        _|      "<<endl;
	cout<<"\t     _|      _|    _|_|_|    _|_|_|  _|    _|    _|_|_|  _|          _|_|_|"<<endl;
	cout<<"\t                       _|                                                  "<<endl;
	cout<<"\t                   _|_|                                                    "<<endl<<endl;
	cout<<"\t\t\t  _|_|_|  _|            _|                          "<<endl;
	cout<<"\t\t\t_|            _|_|_|    _|_|_|      _|_|    _|  _|_|"<<endl;
	cout<<"\t\t\t_|        _|  _|    _|  _|    _|  _|_|_|_|  _|_|    "<<endl;
	cout<<"\t\t\t_|        _|  _|    _|  _|    _|  _|        _|      "<<endl;
	cout<<"\t\t\t  _|_|_|  _|  _|_|_|    _|    _|    _|_|_|  _|      "<<endl;
	cout<<"\t\t\t              _|                                    "<<endl;
	cout<<"\t\t\t              _|                                    "<<endl;
	
//Program Control Structure -- Repitition Control
	//Do-While Loop - Post Test Loop (Code for the loop will execute at least once)
	//This one is terminated by a Sentinel Value of Four
	do
	{
	//Display Menu
		cout<<"\n\t\t\t\t\t      Main Menu"<<endl;
		cout<<"\t\t\t\t      *-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"\t\t\t\t      *   1.Encrypt a message   *"<<endl;
		cout<<"\t\t\t\t      *   2.Decrypt a message   *"<<endl;
		cout<<"\t\t\t\t      *   3.What is Vigenere    *"<<endl;
		cout<<"\t\t\t\t      *   4.Quit this program   *"<<endl;
		cout<<"\t\t\t\t      *-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"\t\t\t\t\tEnter your choice (1-4): ";
		
	//Takes in choice
		cin>>choice;
		
	//Validate input
		while (choice<1 || choice>4)										//If choice is not inbetween 1 and 4
		{																	//then the following prompt will be given
			cout<<"\n\t\t\t\t   INVALID INPUT"<<endl;
			cout<<"\t\t\t\t Please enter either a 1, 2, 3, or 4: ";
		
	//Accepts correct choice to continue	
			if (choice < 4 || choice > 1)									//Makes sure choice is inbetween 1 and 4
			cin >> choice;
		
	//If not a number ...
			else if (!(cin>>choice));
			{
				cin.clear();												//Clears the input to prevent crash
				cin.ignore(1000,'\n');										//Skips 1000 characters or skips to
  				cout<< "\t\t\t\t   ONLY DIGITS"<<endl;						//the begining of the next line
			}																//depending on whether a newline character
		}																	//is encountered before 1000 characters
																			//are skipped.
		cout.setf(ios::right);

//Perform the desired operation
		switch (choice)
		{
			case 1://Encryption
			{	
			//Ask for string input
				cout<<"\nEnter text to be encrypted: ";
				cin.ignore();
				getline(cin, str, '\n');
				
			//Validate input before continuing to functions	
				for (i=0; str[i]!='\0'; i++)
				{
				//"isalpha()" it returns non-zero values for ‘a’ to ‘z’ and ‘A’ to ‘Z’ and zero for other characters.
					if (isalpha(str[i]) != 0)
						continue;
						
					else if (!isalpha(str[i]))
						cout<<"\nOnly letters.";
						cout<<"\nType text as a single string, no spaces.";
						cout<<"\nEnter text to be encrypted: ";
						cin>>str;
				}
				
			//Ask for key input	
				cout<<"\nEnter key: ";
				cin>>keyword;
				
			//Recall above functions
				string key = generate_key(str, keyword);
  				string encrypt_text = encrypt(str, key);
 				
 			//Output
  				cout << "\nEncrypted: " << encrypt_text << endl;
			
			break;
			}
			
			case 2://Decryption
			{
			//Ask for string input
				cout<<"\nEnter text to be decrypted: ";
				cin.ignore();
				getline(cin, str, '\n');
				
			//Validate input before continuing to functions	
				for (i=0; str[i]!='\0'; i++)
				{
				//"isalpha()" it returns non-zero values for ‘a’ to ‘z’ and ‘A’ to ‘Z’ and zero for other characters.
					if (isalpha(str[i]) != 0)
						continue;

					else if (!isalpha(str[i]))
						cout<<"\nOnly letters.";
						cout<<"\nType text as a single string, no spaces.";
						cout<<"\nEnter text to be decrypted: ";
						cin>>str;
				}
				
			//Ask for key input	
				cout<<"\nEnter key: ";
				cin>>keyword;
				
			//Recall above functions
				string key = generate_key(str, keyword);
  				string decrypt_text = decrypt(str, key);
 				
 			//Output
  				cout << "\nEncrypted: " << decrypt_text << endl;
			
			break;
			}
			
			case 3://What is Vigenere
			{
			//The Vigenere Square
				cout<<"\n\t\t\t   A B C D E F G H I J K L M N O P Q R S T U V W X Y Z "<<endl;
				cout<<"\t\t\tA [A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z]"<<endl;
				cout<<"\t\t\tB [B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A]"<<endl;
				cout<<"\t\t\tC [C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B]"<<endl;
				cout<<"\t\t\tD [D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C]"<<endl;
				cout<<"\t\t\tE [E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D]"<<endl;
				cout<<"\t\t\tF [F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E]"<<endl;
				cout<<"\t\t\tG [G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F]"<<endl;
				cout<<"\t\t\tH [H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G]"<<endl;
				cout<<"\t\t\tI [I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H]"<<endl;
				cout<<"\t\t\tJ [J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I]"<<endl;
				cout<<"\t\t\tK [K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J]"<<endl;
				cout<<"\t\t\tL [L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K]"<<endl;
				cout<<"\t\t\tM [M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L]"<<endl;
				cout<<"\t\t\tN [N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M]"<<endl;
				cout<<"\t\t\tO [O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N]"<<endl;
				cout<<"\t\t\tP [P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O]"<<endl;
				cout<<"\t\t\tQ [Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P]"<<endl;
				cout<<"\t\t\tR [R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q]"<<endl;
				cout<<"\t\t\tS [S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R]"<<endl;
				cout<<"\t\t\tT [T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S]"<<endl;
				cout<<"\t\t\tU [U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T]"<<endl;
				cout<<"\t\t\tV [V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U]"<<endl;
				cout<<"\t\t\tW [W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V]"<<endl;
				cout<<"\t\t\tX [X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W]"<<endl;
				cout<<"\t\t\tY [Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X]"<<endl;
				cout<<"\t\t\tZ [Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y]"<<endl;
		
				cout<<"\n\t\t\t\t\t  The Vigenere square"<<endl;
			
			//Description of how to use the Vigenere Square
				cout<<"\nVigenere Cipher is a method of encrypting alphabetic text. It uses a simple form of polyalphabetic";
				cout<<"\nsubstitution. A polyalphabetic cipher is any cipher based on substitution, using multiple substitution";
				cout<<"\nalphabets. The encryption of the original text is done using the Vigenere square or Vigenere table.";
				cout<<"\nThe table consists of the alphabets written out 26 times in different rows, each alphabet shifted";
				cout<<"\ncyclically to the left compared to the previous alphabet, corresponding to the 26 possible Caesar";
				cout<<"\nCiphers. At different points in the encryption process, the cipher uses a different alphabet from one";
				cout<<"\nof the rows. The alphabet used at each point depends on a repeating keyword."<<endl<<endl;
			
			//Example
				cout<<"\nEXAMPLE:"<<endl;
				cout<<"\nInput : Plaintext :   GEEKSFORGEEKS";
    			cout<<"\nKeyword :  AYUSH";
				cout<<"\nOutput : Ciphertext :  GCYCZFMLYLEIM"<<endl;
				cout<<"\nFor generating key, the given keyword is repeated in a circular manner until it matches the length of";
				cout<<"\nthe plain text. The keyword ''AYUSH'' generates the key ''AYUSHAYUSHAYU''"<<endl<<endl;
			//Source Cited
				cout<<"\nSource Cited: https://www.geeksforgeeks.org/vigenere-cipher/"<<endl<<endl;
	
			//Pause
				system ("PAUSE");
				
			break;
			}
		}
	}
	
	while (choice !=4); 			//Expression is Tested and program loops if Choice is not equal to 4.
}
