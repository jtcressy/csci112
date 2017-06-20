# CS2 - Final Project
Write a lexical scanner in C++ to scan a BASIC Program, separating the source code into tokens, classifying the tokens into their appropriate token types. For this task, read in a state table (state.dat) which will help you classify the tokens as their token type (Use enumerated types!!): **newtoken, resword, variable, integer, real,** or **delimiter**. You will also use an action table (action.dat) which will signify the action to take place as each character is read. These tables (see next page) will be covered in more detail in class. The reserved words for the language will also be read in from their own data file (reserve.dat):
```
print
input
end
read
goto
for
if
then
step
rem
to
next
or
and
```

The source code file (prog1.bas) you will scan:
```
10 rem
12 input x1,y
13 if x1 < y then goto 15
14 zee =x1 - y
11 goto 16
15 zee = x1 + 2 *y
16 print x1, y, zee
17 for i = 1 to 16 step 5
18 print i
19 next i
20 input st%
21 print "$", st%
22 input x
23 if y >= x1 then x = y^3
24 print x1, #
25 end
```
Your output file will be: the list of reserved words for the language **in alphabetical order**, the state table with appropriate column and row headers, the aciton table (with appropriate titles, etc) with the explanations of the actions, followed by each token with its appropriate token type.