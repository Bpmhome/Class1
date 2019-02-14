/*
    Programmer: Grant Ogden
    Date: 2/12/2019
    Filename: lab8Calculator.c
    Reason: Lets do math!
*/
#include <stdio.h>

double add(double a,int b);
double subtract(double a,int b);
double multiply(double a,int b);
double divide(double a,int b);
void input_clear();

int main()
{
    //Variable Decleration
    double userNum1 = 0;        //User Input (Also used for storing the answer)
    int userNum2 = 0;           //User Input 2
    char operator = 0;          //Holds the operator inputted by the user
    char userChoice = 0;        //Users choice on to continue or not

    do
    {
        if(userChoice == 0)         //if the user hasn't input something or decided to reset
        {
            //ask user for input and pull that input in
            fprintf(stdout,"Input Two Numbers Seperated by The Math Operator (/,*,-,+):\n");
            fscanf(stdin,"%lf%c%d",&userNum1,&operator,&userNum2);
        }
        else                        //Ask for operator and one number to continue their math
        {
            //ask user for input and pull that input in
            fprintf(stdout,"%lf Please input an operator and number to perform: \n", userNum1);
            fscanf(stdin,"%c%d",&operator,&userNum2);
        }

        switch(operator)                //Check what the user put in
        {
            case '/':         
                if(userNum2 == 0)   //Make sure we don't divide by zero
                {
                    //notify them they are dumb and start over
                    printf("Divide by 0 Error");
                    continue;
                }
                userNum1 = divide(userNum1,userNum2);       //Divide and save in userNum1
                break;
            case '*':         
                userNum1 = multiply(userNum1,userNum2);     //Multiply and save in userNum1
                break;
            case '-':
                userNum1 = subtract(userNum1,userNum2);     //Subtract and save in userNum1
                break;
            case '+':
                userNum1 = add(userNum1,userNum2);          //Add and save in userNum1
                break;
            default:
                printf("Error");   
                continue;                         //if they input something wrong then tell them error and start over
                break;
        }

        input_clear();          //Make sure there isn't a stray new line damn them

        //Tell the User the answer and get their input on to continue
        fprintf(stdout,"= %lf\n", userNum1);
        fprintf(stdout,"Continue Math Problem (y/n): ");
        fscanf(stdin,"%[yn]c",&userChoice);

        if(userChoice == 'n')   //if the user doesn't want to continue math on that problem
        {
            input_clear();  //Make sure there isn't a stray new line damn them

            //Ask the user if they want to start a new math program
            fprintf(stdout,"Do you want to start a new problem (y/n): ");
            fscanf(stdin,"%[yn]c",&userChoice);

            if(userChoice ==  'y')  //if the user says yes reset the value so it starts over
            {
                userChoice = 0;
            }
        }

        input_clear();      //Make sure there isn't a stray new line damn them

    } while (userChoice == 'y' || userChoice == 0); //while the user wants to continue the problem or start over, loop
    
    return 0;
}


/*
 * FUNCTION: Takes to arguments and adds them
 * ARGUEMENTS:  -a is a double
 *              -b is an integer
 * RETURNS: a double of the two numbers added
 * NOTES: a + b
 */
double add(double a, int b)
{
    return (a + b);
}

/*
 * FUNCTION: Takes to arguments and subtracts them
 * ARGUEMENTS:  -a is a double
 *              -b is an integer
 * RETURNS: a double of the two numbers subtracted
 * NOTES: a - b
 */
double subtract(double a,int b)
{
    return (a - b);
}

/*
 * FUNCTION: Takes to arguments and multiplies them
 * ARGUEMENTS:  -a is a double
 *              -b is an integer
 * RETURNS: a double of the two numbers multiplied
 * NOTES: a * b
 */
double multiply(double a,int b)
{
    return (a * b);
}

/*
 * FUNCTION: Takes to arguments and divides them
 * ARGUEMENTS:  -a is a double
 *              -b is an integer
 * RETURNS: a double of the two numbers divided
 * NOTES: a / b
 */
double divide(double a,int b)
{
    return (a / b);
}

/*
 * FUNCTION:    Loops through stdin ensuring that there is no stray
 *              characters and ends once a newline has been pulled
 *              in from stdin
 * ARGUEMENTS:  
 * RETURNS: void
 * NOTES:
 */
void input_clear()
{
    while(getchar() != '\n');
}