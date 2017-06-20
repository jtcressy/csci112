# CSCI 112 - Program 6 
#### Other repo named CSCI112-prog6 is actually prog5. Typo!!

### Our task is ot code several sort techniques. To test our methods, we will create **two** programs.

1. Write a program which will create a data file of 10,000 real numbers (use _four_ digits after the decimal point) using a random number generator (which will be discussed in class) **and** a formula of your own creation to randomize the data even further. Do NOT print the data file to turn in, just the one-page program.
2. Write a program which will use our data file (created in program1) and put these steps in main, using function calls for the steps. Do NOT mix sort functions with printing, etc.
```
Loop
    Read in data
    call the specific sort routine listed along with N
    Print the sort technique used
    Print every 1000th item to verify that the array is sorted, 5 per row
    Print the # copies, # compares done by this sort routine 
    Print the relative # copies, relative # compares by this sort
End Loop
```
#### Sorts
1. Bubble sort - the original version
2. Selection sort
3. Insertion sort
4. Quick sort

Typical output for each sort might look like this:
```
Bubble Sort   N = 5000
  -2228.3442   -1826.0982  -1444.6112  -1006.3933    -561.7534
      4.8774     519.9412    982.8183   1408.4040    1824.7823

     Number of compares = 24990001           Number of moves= 18768783

     Relative # of compares = 4998.0002      Relative # of moves = 3753.7566
```
## Extra Credit
1. Put a timing function in to get the time for each sort routine and print that time as well as the other data
2. Do the improved bubble sort

## Turn in:
1. A copy of the source for program 1
2. A copy of the source for program 2
3. The output file (which should fit on one page)