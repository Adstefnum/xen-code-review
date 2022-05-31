# xent-code-review

# CHANGELOG

- lines 58-66 : function strcpy is known to be vulnerable to buffer overflows
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
