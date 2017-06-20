## CSCI 112 - Class Assignment 1
### In this assignment, we will write the code using classes and practice the various ways we can use to access classes.

1) Code the class program given in class implementing two classes, **playclass1** and **playclass2**

2. Without changing the main function, make these changes to the class definitions. When they are finished, re-execute the program to make sure all appears to be working.

    A) Add new constructors to each class that will take two numbers and that will set the length and width at the instantiation of any object called with those constructors.

    B) Add print methods to each class. Each should print text noting which class is being used and print the value of each data value. Each print method will require an output file ot be sent to it as an input parameter.

3) Add code to the main function to each of the following tasks (do NOT replace the code already there!). Each step should be **hard coded sequentially** in the main funciton. Also, please identify which step you are working on. Typical data output with sample data will look like this:
    ```
    Step 3A - Print x and y
        The playclass1 object has:  length =  6.25  width =  4.38
        The playclass2 object has:  length = 12.75  width = 10.00
    ```
    A) Declare two new variables using the constructors created in step 2, **x(playclass1)** with a length of 6.25 and a width of 4.38 and **y(playclass2)** with a width of 10.00 and a length of 12.75. After declaration, print the objects using the corresponding print method.

    B) Declare **area**, of type double,  in main. Note that it is NOT a change to the classes themselves. Get the area of x, print the result to the output file. Get the area of y, printing the result to the output file.

    C) Change the length and width of object **a** to 6.50 and 3.33, respectively. Find the area of **a** and output it to the output file with an appropriate message.

    D) Change the length and widht of object **b** to 11.00 and 8.50, respectively. Find the area of **b** and output it to the output file with an appropriate message.

4) Move the class information to the appropriate header and implementation files, and re-execute the program. Determine that the output still works. Print the three files (driver program, header file and implementation file) and the output file and turn in.