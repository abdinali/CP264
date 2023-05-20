JobID: cp264oc-a1-lab1
Name: Abdinasir Ali
ID: 210974610

Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Grade_Item_ID [self-evaluation/total/marker-evaluation] Description

Lab1

T1 Install and test GCC compiler
T1.1 [1/1/*] Utlity programs
T1.2 [1/1/*] Visual Studio Code
T1.3 [2/2/*] Install GNU GCC compiler
T1.4 [1/1/*] Test GCC compiler

T2 Programming using IDE
T2.1 [1/1/*] VS code for C
T2.2 [1/1/*] C project on Eclipse

T3 Explore C programs
T3.1 [1/1/*] Basics data types and variables
T3.2 [1/1/*] Arithmetic operations, casting
T3.3 [1/1/*] Bit operations
T3.4 [1/1/*] Flow control examples
T3.5 [1/1/*] Function examples

A1

Q1 Interactive program
Q1.1 [3/3/*] prompt for input                        
Q1.2 [3/3/*] input upper/lower case                  
Q1.3 [2/2/*] input digit characters                  
Q1.4 [2/2/*] others, quit                            

Q2 Computing and overflow
Q2.1 [3/3/*] command line argument                   
Q2.2 [4/4/*] correctness of computing                
Q2.3 [3/3/*] overflow testing                        

Q3 Solving quadratic equation
Q3.1 [6/6/*] correctness of computing                
Q3.2 [2/2/*] robust for invalid input                
Q3.3 [2/2/*] output format                           

Total: [0/40/*]

Copy and paste the console output of your public test in the following. 
This will help markers to evaluate your program if it fails the marking tests.  

Q1 output:

Please enter a character
A
A:65,a,97
Please enter a character
d
d:100,D,68
Please enter a character
4
4:52,4,16
Please enter a character
$
$:invalid
Please enter a character
!
!:quit

Q2 output:

./overflow 2 1
powersum(2 1):3

./overflow 2 31
powersum(2 31):overflow

./overflow 2 3
powersum(2 3):15

Q3 output:

./quadratic 1,-4,4
(1.00)x^2+(-4.00)x+(4.00)=0: 2.00 2.00

./quadratic 1,2,2
(1.00)x^2+(2.00)x+(2.00)=0: -1.00+1.00i, -1.00-1.00i

./quadratic a,b,c
input:invalid

./quadratic 0,1,2
(0.00)x^2+(1.00)x+(2.00)=0: not a quadratic equation

