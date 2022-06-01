#pragma once
#include "BaseClass.h"
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>

#define MAX_STR_LENGTH 1000
class SomeClass : public BaseClass
{
	char* OutputText = (char*)malloc(MAX_STR_LENGTH + 1);

long checksum(std::string value)
{
	long checksum;
    int value_size = (int)value.size();

	for (int i = 0; i < value_size; i++)
	{
		checksum += (long)value[i];
	}

	return checksum;
}
	void PrintValue(void)
	{
		printf("the Text is %s\n", OutputText);
		printf("the checksum is %ld\n", checksum(OutputText));
	}

	void SetText(char InputText[])
	{
		if (InputText)
		{
			memcpy(OutputText, InputText,MAX_STR_LENGTH+1 );
		}
		else
		{
			strcpy(OutputText, "NULL");
		}
	}
};
