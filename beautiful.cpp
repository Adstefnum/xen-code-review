/*
This is terrible code.

We want this code to be clean, modern C++ code. Find all the problems in this code, including:

- bugs
- bad style
- obsolete constructs
- perfomace problems
- security flaws
- usablility issues
- anything else you don't like

For extra credit, write better code that does the same thing.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <string>

#define MAX_STR_LENGTH 1000

class BaseClass
{
public:
	virtual void printValue(void) = 0;
	virtual void setString(char* string) = 0;
};

long checksum(std::string value)
{
	int i;
	long checksum;
    int value_size = (int)value.size();

	for (i = 0; i < value_size; i++)
	{
		checksum += (long)value[i];
	}

	return checksum;
}

class SomeClass : public BaseClass
{
	char _string[MAX_STR_LENGTH + 1];

	void printValue(void)
	{
		printf("the string is %c\n", _string);
		printf("the checksum is %ld\n", checksum(_string));
	}

	void setString(char* string)
	{
		if (string)
		{
			strcpy(_string, string);
		}
		else
		{
			strcpy(_string, "NULL");
		}
	}
};

int main(int argc, char *argv[])
{

    BaseClass *object;
    SomeClass someclass;
    object = & someclass;
	if (argc < 3)
	{
		printf("Usage: %s <repeats> <string> [null]\n", argv[0]);
        std::exit(1);
	}

    if (argc == 4 && argv[3]=="null")
	{
		object->setString(NULL);
		object->printValue(); 
	}

	for (int i = 0; i < atoi(argv[1]); i++)
	{
		object->setString(argv[2]);
		object->printValue();
	}

}
