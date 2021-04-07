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
	int lastPos, middlePos, firstPos, i;
	bool isPalindrome;
	static bool palindromeTest(const char sent[SIZE]);
	static char normalize(char sent[SIZE]);

	palindrome()
	{
		i = firstPos = middlePos = lastPos = 0;
		isPalindrome = true;
		
	}

}pal;




int main()
{
	std::cout << "Enter a sentence, and I will check if it is a palindrome\n>>";


	return 0;
}//end method main

bool palindrome::palindromeTest(const char sent[SIZE])
{
	return false;
}

char palindrome::normalize(char sent[SIZE])
{
	int length = strlen(sent);
	for (size_t i = 0; i < length; i++)
	{

	}
	return 0;
}
