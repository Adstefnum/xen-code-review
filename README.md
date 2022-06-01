# xent-code-review

# CHANGELOG

## SECURITY OPTIMIZATION
### strcpy() in setString()
- lines 58-66 : function strcpy is known to be vulnerable to buffer overflows-- do something about it,
    - arrange proof of concept not with files but pictures from gdb
    - replace strcpy with .... memcpy
    - is it affecting printValue()

#### Proof of Concept
- Generate a string of 1016 As with python
- Compile the string with the debug(-g) flag
- run with gdb

### printValue() function
- the printValue function is vulnerable to buffer overflow? it breaks at 1016 character
- when %s is changed to %c on line 52, it prints singular characters randomly both printables and non-printables
- backtracking should lead to a problem with the strcpy

#### Proof of Concept
- Generate a string of 1016 As with python
- Compile the string with the debug(-g) flag
- run with gdb

## COST AND BUGS OPTIMIZATION
### QUESTIONS
- Inconsitent naming conventions and bad names-- rename
- should the checksum method be in the classes
- should I use const char pointer or std::string in setString, does it affect printValue?

### STEPS TAKEN
- line 52: using the correct conversion character for the returned long value 
```cpp
		printf("the checksum is %d\n", checksum(_string));
        //changes to

		printf("the checksum is %ld\n", checksum(_string));
```
- line 36-38 changes to allow relational operation between int and type of  std::string::size
    ```cpp
    //just added
    int value_size = (int)value.size();
    
    //from
    for(i=0;i<value.size();i++)

    //to
	for (i = 0; i < value_size; i++)
    ```
- line 69, cpp uses int main not void main
```cpp
//from
void main(int argc, char *argv[])

//to
int main(int argc, char *argv[])
    ```
- return statement added on line 94
```cpp
return 0;
```
- clean up the conditional statements in the main function
- use exit to terminate program instead of throw -1 so that the program resources can be freed. Also this isn't really an error so just exit normally.
    ```cpp

		throw -1;
        std::exit(1);
    ```
- move the other if statement up and actually check if the fourth argument is null before performing operation.
    ```cpp
    if (argc == 4 && argv[3]=="null")
	{
		object->setString(NULL);
		object->printValue(); 
	}
    ```
- line 72. loop variable is now defined in the loop definition at line 87
    ```cpp
    int i;

	for (int i = 0; i < atoi(argv[1]); i++)
    ```
- Line 71 sets up accessing those virtual functions as using the syntax below to achieve runtime polymorphism but these other parts should be added to complete the process or we will run into an undefined behaviour error.
 ```cpp
    BaseClass *object;
    SomeClass someclass;
    object = & someclass;
    object->printValue();
 ```
 we are simply making a pointer(memory address) of the BaseClass and an instance of the SomeClass which is a derived class then we pass the memory address of the object of SomeClass to the pointer to store and reference the memory address when the class is called upon.

- Also the class should be instantiated at every run of the loop, this should be done only one so it is removed on line 81 and it doesn't even achieve runtime polymorphism.
