# xent-code-review

# CHANGELOG

## SECURITY OPTIMIZATION
### strcpy() in setString()
- lines 58-66 : function strcpy is known to be vulnerable to buffer overflows-- do something about it,
    - replace strcpy with .... memcpy
    - it is affecting printValue(), this is where the segfault occurs at the 1016th character.

#### Proof of Concept
- Generate a string of 1016 As with python
[generate 1016 As](pics/pygen)
- Compile the string with the debug(-g) flag
[compile](pics/compile)
- run with gdb
[segfault](pics/segfault)

## COST AND BUGS OPTIMIZATION

### STEPS TAKEN
- line 56- char pointer collects only a single character and we would like more than a character in the checksum usually so we use a const char  array[] or just std::string and rename the string to something better.
    ```cpp

	void setString(char* string)

	void setString(char Text[])
    ```
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

- restructred the conditonals in the main statement

## CLEAN CODE
- BaseClass put in base.h and included in main file and SomeClass.h
- renamed functions with pascal case convention
- checksum function was added inside SomeClass as that is where it is used

## USABILITY
- repeats functionality removed as it just does unnecessary reruns and would confuse the user
- the checksum function doesn't work as a checksum function normally should, it should give a unique number to a unique string but this one gives a seperate number on each run
- Also removed the null functionality, the program just should run and print usage message instead of assigining null values. It would confuse the user
