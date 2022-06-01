#include "BaseClass.h"
#include "SomeClass.h"

int main(int argc, char *argv[])
{

    BaseClass *object;
    SomeClass someclass;
    object = & someclass;

    if (argc == 2)
	{
		object->SetText(argv[1]);
		object->PrintValue(); 
	}

    else
	{
		printf("Usage: %s <Text>\n", argv[0]);
        std::exit(1);
	}
}
