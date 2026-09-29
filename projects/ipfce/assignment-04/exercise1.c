#include <stdio.h>
#include <math.h>
#include <assert.h>

void displayRepaymentPlan(double loanAmount, double monthlyInterestRate, int loanDuration, double monthlyPayment);
double calculateMonthlyPayment(double loanAmount, double monthlyInterestRate, int loanDuration);


int main()
{
    double loanAmount;   // Loan principal amount
    double interestRate; // Annual interest rate (as a decimal)
    int loanDuration;    // Loan duration in months

    // Get user input
    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter the annual interest rate (as a decimal): ");
    scanf("%lf", &interestRate);

    printf("Enter the loan duration in months: ");
    scanf("%d", &loanDuration);

    assert(loanAmount > 0); // Precondition
    assert(interestRate > 0); // precondition 
    assert(loanDuration > 0); // precondition 

    // Calculate monthly interest rate
    double monthlyInterestRate = interestRate / 12;

    // Calculate monthly payment
    double monthlyPayment = calculateMonthlyPayment(loanAmount, monthlyInterestRate, loanDuration);

    displayRepaymentPlan(loanAmount, monthlyInterestRate, loanDuration, monthlyPayment);

    return 0;
}

double calculateMonthlyPayment(double loanAmount, double monthlyInterestRate, int loanDuration) {
    assert(loanAmount > 0); // precondition
    assert(monthlyInterestRate > 0); // precondition
    assert(loanDuration > 0); // precondition
    double MonthlyPayment = loanAmount * (monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -loanDuration)));
    assert(MonthlyPayment > 0); // postcondition
    return MonthlyPayment;
}

void displayRepaymentPlan(double loanAmount, double monthlyInterestRate, int loanDuration, double monthlyPayment){
    // Display repayment plan
    printf("\nRepayment Plan:\n");
    printf("Monthly payment: %.2lf\n",monthlyPayment);
    printf("Month\tPrincipal\tInterest\tTotal Payment\n");

    double remainingBalance = loanAmount;
    double totalPayment = 0.0;

    for (int month = 1; month <= loanDuration; month++)
    {
        double interestPayment = remainingBalance * monthlyInterestRate;
        double principalPayment = monthlyPayment - interestPayment;

        remainingBalance -= principalPayment;
    
        totalPayment = totalPayment + monthlyPayment;

        
        
        printf("%d\t%.2lf\t\t%.2lf\t\t%.2lf\n", month, principalPayment, interestPayment, totalPayment);

        if (remainingBalance <= 0.0)
        {
            assert(monthlyPayment*loanDuration >= loanAmount); // Postcondition
            break;
        }
    }
    assert(monthlyPayment*loanDuration >= loanAmount); // Postcondition

    return;
}