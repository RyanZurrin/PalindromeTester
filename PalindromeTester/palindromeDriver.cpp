/// file: palindromeDriver.cpp
/// details: Write a bool function that uses recursion to determine if a
/// c-string argument is a palindrome.The function should return true if the
/// argument reads the same forward and backward. Demonstrate the function in a
/// well designed program
/// author: Ryan Zurrin
/// due-date:   4/8/2021


#include <iostream>
#include <cctype>

const int SIZE = 500;
static struct palindrome
{
	char sentence[SIZE];
	bool isPalindrome;
	static bool palindromeTest(const char sent[SIZE], int f, int l);
	static void normalize(char sent[SIZE]);
	static void printSentence(char toPrint[SIZE]);

	palindrome()
	{
		sentence[0] = '\0';
		isPalindrome = false;
	}

};

int main()
{
	bool rerun;
	char pick;
	do
	{
		palindrome* pal = new palindrome;
		pal->isPalindrome = false;
		bool tryAgain = false;
		do
		{
			tryAgain = false;
			std::cin.clear();
			std::cout << "Enter a sentence with no numbers,"
					  << "and I will check if it is a palindrome\n>>";
			std::cin.getline(pal->sentence, SIZE);
			for (int i = 0; i <= strlen(pal->sentence); i++)
			{
				if (std::isdigit(pal->sentence[i]) != false)
				{
					std::cout << "I do not test palindromes with "
							  <<"numbers try again\n";
					tryAgain = true;
				}
			}
		}
		while (tryAgain);
		pal->normalize(pal->sentence);
		pal->isPalindrome = pal->palindromeTest(
			pal->sentence, 0, strlen(pal->sentence)-1);
		if (pal->isPalindrome == true)
		{
			pal->printSentence(pal->sentence);
			std::cout << " is a palindrome!"<<std::endl;
		}
		else if (pal->isPalindrome == false)
		{
			pal->printSentence(pal->sentence);
			std::cout << " is not a palindrome" << std::endl;
		}
		std::cout << "Enter Y or y to enter test another phrase\n>>";
		std::cin >> pick;
		if (pick == 'Y'|| pick =='y')
		{
			rerun = true;
		}
		else
			rerun = false;
		std::cin.clear();
		std::cin.ignore();
		delete pal;
	}
	while (rerun);
	std::cout << "thank you for using the palindrome tester\nGood Bye!\n";
	return 0;
}//end method main

bool palindrome::palindromeTest(const char sent[SIZE],int f, int l)
{
	if (f >= l)
	{
		return true;
	}
	if(sent[f] == sent[l])
	{
		palindromeTest(sent, f+1, l-1);
	}
	else
	{
		return false;
	}

}//end method palindromeTest

void palindrome::normalize(char sent[SIZE])
{
	int i, j;
	for(i = 0, j = 0; i <= strlen(sent); i++)
	{
		if((sent[i] != ' ') && (ispunct(sent[i]) == false))
		{
			sent[j] = tolower(sent[i]);
			j++;
		}
	}
}//end method normalize

void palindrome::printSentence(char toPrint[SIZE])
{
	int len = strlen(toPrint);
	for (int i = 0; i < len; i++)
	{
		if (toPrint[i] != '\0')
		{
			std::cout << toPrint[i];
		}
	}
	std::cout << std::endl;
}//end method printSentence