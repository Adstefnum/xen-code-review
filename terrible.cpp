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

	for (i = 0; i < value.size(); i++)
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
		printf("the string is %s\n", _string);
		printf("the checksum is %d\n", checksum(_string));
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

void main(int argc, char *argv[])
{
	BaseClass* object;
	int i;

	if (argc < 3)
	{
		printf("Usage: %s <repeats> <string> [null]\n", argv[0]);
		throw -1;
	}

	for (i = 0; i < atoi(argv[1]); i++)
	{
		object = new SomeClass;

		object->setString(argv[2]);
		object->printValue();
	}

	if (argc == 4)
	{
		object->setString(NULL);
		object->printValue();
	}
}
