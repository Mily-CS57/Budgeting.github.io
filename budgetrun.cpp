#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

class Budgeting{
    public:
        void FiftyThirtyTwenty();
        void FVvalue();
        double InsuranceValid(double var);
        void LifeInsurancePart1();
        void LifeInsurancePart2(double stepOne);
        void BudgetSteps();
        void FinGame();
};

// Creates Budget using 50/30/20 Rule
void Budgeting::FiftyThirtyTwenty(){
    int payDays;
    double amount;
    double needs, wants, savings;

    // User Input
    cout << "Number of pay days per month: ";
    while(!(cin >> payDays)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a whole number: ";
    }

    // User Input
    cout << "Amount per payday: ";
    while(!(cin >> amount)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a decimal value: ";
    }

    // Calculate Needs, Wants, Savings
    needs = 0.5 * ((double)payDays*amount);
    wants = 0.3 * ((double)payDays*amount);
    savings = 0.2 * ((double)payDays*amount);
    cout << "------------------------------------------------------";

    // Outputs resulting Needs, Wants, Savings
    cout << "\nBudgeting Plan:\n";
    cout << "\t$" << fixed << setprecision(2) << needs << " is for your NEEDS\n";
    cout << "\t$" << fixed << setprecision(2) << wants << " is for your WANTS\n";
    cout << "\t$" << fixed << setprecision(2) << savings << " is for your SAVINGS\n";
    cout << "------------------------------------------------------\n";
}

// Calculates Accounts Future Value
void Budgeting::FVvalue(){
    double monthDep;
    double interest;
    int months;
    double futureVal;

    // User Input
    cout << "Monthly Deposit: ";
    while(!(cin >> monthDep)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a decimal value: ";
    }

    // User Input
    cout << "Interest Rate(In Decimal Form): ";
    while(!(cin >> interest)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a decimal value: ";
    }

    // User Input
    cout << "Duration, in months: ";
    while(!(cin >> months)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a whole number: ";
    }

    // Calculate Future Value using Finance Equation
    futureVal = pow(1+(interest/months),months) - 1;
    futureVal = monthDep * (futureVal/(interest/months));
    cout << "-------------------------------------\n";

    // Outputs resulting Future Value
    cout << "End of " << months << " months, account balance: \n$" 
         << fixed << setprecision(2) <<futureVal; 
    cout << "\n------------------------------------------------------\n";
}

// Does User Validation for LifeInsurance method
double Budgeting::InsuranceValid(double var){
    while(!(cin >> var)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a decimal value: ";
    }
    return var;
}

// Calculates Annual Needs
void Budgeting::LifeInsurancePart1(){
    Budgeting I;
    //STEP 1: Financial resources needed after death
    double stepOne = 0;

    //Annual living expenses and other needs:
    cout << "[STEP 1: Annual Living Expenses]\n";
    //a.Monthly living expenses period 1-3
    //c.Number of years in time period period 1-3 USER INPUT
    cout << "Monthly Living Expenses Period 1: ";
    double MLE1 = I.InsuranceValid(MLE1);
    cout << "Time Period(in years) Period 1: ";
    double years1 = I.InsuranceValid(years1);

    cout << "Monthly Living Expenses Period 2: ";
    double MLE2 = I.InsuranceValid(MLE2);
    cout << "Time Period(in years) Period 2: ";
    double years2 = I.InsuranceValid(years2);

    cout << "Monthly Living Expenses Period 3: ";
    double MLE3 = I.InsuranceValid(MLE3);
    cout << "Time Period(in years) Period 3: ";
    double years3 = I.InsuranceValid(years3);
    //b.net yearly income needed (ax12) period 1-3
    MLE1 = MLE1*12;
    MLE2 = MLE2*12;
    MLE3 = MLE3*12;
    //d.total living needed per time period(bxc) period 1-3
    MLE1 = MLE1 * years1;
    MLE2 = MLE2 * years2;
    MLE3 = MLE3 * years3;
    //Total living expenses
    stepOne += MLE1 + MLE2 + MLE3;

    //Special Needs
    //a. Spouse Education Fund
    cout << "Spouse Education Fund: ";
    double spouseFund = I.InsuranceValid(spouseFund);
    //b. Children's college fund
    cout << "Children's College Fund: ";
    double collegeFund = I.InsuranceValid(collegeFund);
    //c. other needs
    cout << "Other needed funds: ";
    double otherFunds = I.InsuranceValid(otherFunds);

    //Final expenses like funeral/estate costs etc USER INPUT
    cout << "Final Expenses(funeral, estate costs, etc): ";
    double finalExpenses = I.InsuranceValid(finalExpenses);

    //Debt liquidation
    //a. House mortgage period 1-3 USER INPUT
    cout << "House mortgage Period 1: ";
    double mortgage1 = I.InsuranceValid(mortgage1);
    cout << "House mortgage Period 2: ";
    double mortgage2 = I.InsuranceValid(mortgage2);
    cout << "House mortgage Period 3: ";
    double mortgage3 = I.InsuranceValid(mortgage3);
    //b. Other loans period 1-3 USER INPUT
    cout << "Other loans Period 1: ";
    double loans1 = I.InsuranceValid(loans1);
    cout << "Other loans Period 2: ";
    double loans2 = I.InsuranceValid(loans2);
    cout << "Other loans Period 3: ";
    double loans3 = I.InsuranceValid(loans3);
    //c. total debt=a+b CALCULATE
    stepOne += mortgage1 + mortgage2 + mortgage3 + loans1 + loans2 + loans3;

    //Other financial needs like contingency fund USER INPUT
    cout << "Other Financial Needs: ";
    double otherFinancial = I.InsuranceValid(otherFinancial);

    //Total financial resources add total, Step 1
    stepOne += spouseFund + collegeFund + otherFunds + finalExpenses + otherFinancial;
    I.LifeInsurancePart2(stepOne);
}

// Calculates Resources Available
void Budgeting::LifeInsurancePart2(double stepOne){
    Budgeting I;
    //STEP2: Financial resources available after death
    cout << "[STEP 2: Resources Available after Death]\n";
    double stepTwo = 0;
    //a. Annual social security survivors benefits 1-3 USER INPUT
    //b. Surviving spouse's annual income 1-3 USER INPUT
    //c. Other annual pensions and social security benefits 1-3 USER INPUT
    //d. ANNUAL INCOME 1-3 USER INPUT
    //e. number of years in time period 1-3 USER INPUT
    cout << "Annual Social Security survivors Benefits Period 1: ";
    double ssb1 = I.InsuranceValid(ssb1);
    cout << "Surviving Spouse's Annual income Period 1: ";
    double annualIncome1 = I.InsuranceValid(annualIncome1);
    cout << "Other Annual Pensions/SS Benefits Period 1: ";
    double otherPB1 = I.InsuranceValid(otherPB1);
    cout << "Annual Income Period 1: ";
    double anInc1 = I.InsuranceValid(anInc1);
    cout << "Time Period(in years) Period 1: ";
    double years1 = I.InsuranceValid(years1);

    cout << "Annual Social Security survivors Benefits Period 2: ";
    double ssb2 = I.InsuranceValid(ssb2);
    cout << "Surviving Spouse's Annual income Period 2: ";
    double annualIncome2 = I.InsuranceValid(annualIncome2);
    cout << "Other Annual Pensions/SS Benefits Period 2: ";
    double otherPB2 = I.InsuranceValid(otherPB2);
    cout << "Annual Income Period 2: ";
    double anInc2 = I.InsuranceValid(anInc2);
    cout << "Time Period(in years) Period 2: ";
    double years2 = I.InsuranceValid(years2);

    cout << "Annual Social Security survivors Benefits Period 3: ";
    double ssb3 = I.InsuranceValid(ssb3);
    cout << "Surviving Spouse's Annual income Period 3: ";
    double annualIncome3 = I.InsuranceValid(annualIncome3);
    cout << "Other Annual Pensions/SS Benefits Period 3: ";
    double otherPB3 = I.InsuranceValid(otherPB3);
    cout << "Annual Income Period 3: ";
    double anInc3 = I.InsuranceValid(anInc3);
    cout << "Time Period(in years) Period 3: ";
    double years3 = I.InsuranceValid(years3);
    //f. total period income dxe 1-3
    anInc1 = anInc1 * years1;
    anInc2 = anInc2 * years2;
    anInc3 = anInc3 * years3;
    //G. total income
    stepTwo += anInc1 + anInc2 + anInc3;

    //savings and investments USER INPUT
    cout << "Savings and Investments: ";
    double savingsInvest = I.InsuranceValid(savingsInvest);

    //other life insurance USER INPUT
    cout << "Other Life Insurance: ";
    double lifeInsurance = I.InsuranceValid(lifeInsurance);

    //other resources available USERINPUT
    cout << "Other Resources: ";
    double otherRes = I.InsuranceValid(otherRes);

    //Total financial resources available, STEP 2
    stepTwo += savingsInvest + lifeInsurance + otherRes;

    //STEP3: ADDITIONAL LIFE INSURANCE NEEDED
    double stepThree = stepOne - stepTwo;
    cout << "\n------------------------------------------------------";
    cout << "\nAdditional Life Insurance Needed: $" << stepThree;
    cout << "\n------------------------------------------------------\n";
}

// Outputs Budgeting Explanation
void Budgeting::BudgetSteps(){
    cout << "A budget compares estimated income with estimated expenses:\n"
         << "STEP 1: Understand Income\n"
         << "\t - Calculate ALL monthly income\n"
         << "\t - Think about after-tax income\n"
         << "STEP 2: Track Expenses\n"
         << "\t - List ALL monthly expenses(mortgages, groceries, etc.)\n"
         << "\t - Categorize expenses (housing, food, etc)\n"
         << "\t - Track spending to identify when to change spending habits\n"
         << "STEP 3: Create Budgeting Plan\n"
         << "\t - Identify financial goals which will guide budgeting plan\n"
         << "\t - Decide how much of income will go towards each expense category\n"
         << "\t - Create plan that shows how money will be spent monthly\n"
         << "\t - Review budget and make adjustments along the way\n"
         << "Note: Your budgeting plan should always align with your financial goals!\n";
    cout << "------------------------------------------------------\n";
}

// Runs True/False Game
void Budgeting::FinGame(){
    char choice;
    int score = 0;
    int q1 = 0;
    int q2 = 0;
    int q3 = 0;
    int q4 = 0;
    int q5 = 0;
    
    // Directions
    cout << "Answer T(true) or F(false):\n";
    cout << "(Note*If you answer with a different character, it will be marked as wrong*)";

    // Question 1
    cout << "\n\tUnderstanding personal finance is not necessary to judge the quality of advice given by a financial adviser: ";
    while(!(cin >> choice)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter T or F (different character = wrong answer): ";
    }
    // Check Question 1 Answer
    if(choice == 'F'){
        score++;
        q1 = 1;
    }

    // Question 2
    cout << "\tNet worth is the value of what you own minus the value of what you owe: ";
    while(!(cin >> choice)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter T or F (different character = wrong answer): ";
    }
    // Check Question 2 Answer
    if(choice == 'T'){
        score++;
        q2 = 1;
    }

    // Question 3
    cout << "\tFinancial goals must be realistic and include a timeline of when you want to accomplish them: ";
    while(!(cin >> choice)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter T or F (different character = wrong answer): ";
    }
    // Check Question 3 Answer
    if(choice == 'T'){
        score++;
        q3 = 1;
    }

    // Question 4
    cout << "\tAn emergency fund does not help in case of catastrophic financial events: ";
    while(!(cin >> choice)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter T or F (different character = wrong answer): ";
    }
    // Check Question 4 Answer
    if(choice == 'F'){
        score++;
        q4 = 1;
    }

    // Question 5
    cout << "\tA large portion of the population is financially illiterate: ";
    while(!(cin >> choice)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter T or F (different character = wrong answer): ";
    }
    // Check Question 5 Answer
    if(choice == 'T'){
        score++;
        q5 = 1;
    }

    // Outputs Use Score
    cout << "Your final score is: " << score << "/5";
    // Outputs Questions with Wrong Answers
    if(q1 == 0  || q2 == 0 || q3 == 0 || q4 == 0 || q5 == 0){
        cout << "\nYou answered question";
        if(q1 == 0){ cout << " 1"; }
        if(q2 == 0){ cout << " 2"; }
        if(q3 == 0){ cout << " 3"; }
        if(q4 == 0){ cout << " 4"; }
        if(q5 == 0){ cout << " 5"; }
        cout << " wrong.\n";
    }
    cout << "------------------------------------------------------\n";  
}

int main(){
    // Keeps Track of User Decision to Quit or Continue
    char decision = 'c';
    // Run while Use Selects Continue
    while(decision == 'c'){
        // Outputs Use Options
        cout << "Select your budgeting option(1-4):" <<
                "\n1 - 50/30/20 Rule" <<
                "\n2 - Future Value of an Account" <<
                "\n3 - Life Insurance Need Analysis" <<
                "\n4 - Three Steps to Budgeting Explained" <<
                "\n5 - Finance T/F game" <<
                "\nYour selection: ";

        int selection = 0;
        // Takes User Option
        while(!(cin >> selection)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a value between 1 and 4: ";
        }

        cout << "------------------------------------------------------";

        Budgeting bud;

        // Runs Method Corresponding to Users Selection
        if(selection == 1){
            cout << "\n50/30/20 Rule:\n";
            bud.FiftyThirtyTwenty();
        }else if(selection == 2){
            cout << "\nFuture Value of an Account:\n";
            bud.FVvalue();
        }else if(selection == 3){
            cout << "\nLife Insurance Need Analysis:\n";
            bud.LifeInsurancePart1();
        }else if(selection == 4){
            cout << "\nSteps to Budgeting Explained:\n";
            bud.BudgetSteps();
        }else if(selection == 5){
            cout << "\nFinance Game:\n";
            bud.FinGame();
        }else{
            // Outputs invalid Message
            cout << "\nYou did not input a valid integer ): You'll have to quit or start over\n";
            cout << "------------------------------------------------------\n"; 
        }

        // Asks User to Quit or Continue
        cout << "Enter q(quit) or c(continue): ";
        cin >> decision;
        cout << "------------------------------------------------------\n";      
    }

    return 0;
}