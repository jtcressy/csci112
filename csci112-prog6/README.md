# CS2: Data Structures
## Program #6

#### Develop a class for rational numbers. The class should include members:
 - A: Constructors
   - A default constructor setting the number to 0/1
   - A second constructor where the user will supply **num** and **den**, the two **private** data members of the class
 - B: The gets and sets for **num** and **den**
 - C: **printem** - a method that has a file variable sent to it, where a rational number will be output as: ``Numerator = <num> and Denominator = <den>``
 - D: Overloaded **operators** for adding (+), subtracting (-), multiplying (*), dividing (/) two rational numbers sent to it, with a rational number returned as the solution.
 - E: **reducem** - a method that will reduce the rational number to its lowest form (i.e. 13/52 will be output as 1/4). Also, it should handle negative numbers so that 1/-3 would be output as -1/3; -2/-5 would be output as 2/5, etc. This method will be called at the end of each operator overloading method (in **that** method!) to ensure final answers are stored in correct form.

Your final program will test your rational number class. Have your program read in a series of rational number pairs (each should also be printed to the output file) using ``>>``. For each, the program will output the sum, difference, product and quotient of the pair using the ``>>`` operator.

  1. 1/2    1/2
  2. -5/3   2/3
  3. 6/-4   0/1
  4. 12/23  3/5
  5. 1/5    -2/10

This program should:
1. Use separate files for the header and implementation files
2. Use the friend function version for the operator overloading (see page 886 [in textbook]).
3. Use the following version for rational numbers: **num/den**. These should be used for ``>>`` and ``<<``, but NOT printem. You may adjust the data file appropriately.