//
//  main.cpp
//  PRG-4-14-Bank-Charges
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A bank charges $10 per month plus the following check fees for a commercial checking
//  account:
//
//  $.10 each for fewer than 20 checks
//  $.08 each for 20-39 checks
//  $.06 each for 40-59 checks
//  $.04 each for 60 or more checks
//
//  The bank also charges an extra $15 if the balance of the account falls below $400
//  (before any check fees are applied). Write a program that asks for the beginning balance
//  and the number of checks written. Compute and display the bank's service fees
//  for the month.
//
//  Input validation: Do not accept a negative value for the number of checks written. If a
//  negative value is given for the beginning balance, display an urgent message indicating
//  the account is overdrawn.



#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int intChecks;
    
    float fltAccountBalance,
          fltCheckFee,
          fltServiceFees;
    
    float const FLT_LOW_BALANCE_FEE = 15.0f;
    
    cout << "Please enter your balance for this month:\n";
    cin >> fltAccountBalance;
    
    if(fltAccountBalance < 0.0f)
    {
        cout << "*URGENT MESSAGE* Your account is overdrawn!";
    }
    
    cout << "Please enter the number of checks used this month:\n";
    cin >> intChecks;
    while(!cin || intChecks < 0 || intChecks > 1000)
    {
        cout << "Please enter a valid number of checks (0-1000):\n";
        cin.clear();
        cin.ignore();
        cin >> intChecks;
    }
    
    if(intChecks < 20)
    {
        fltCheckFee = intChecks * 0.10f;
    }
    else if(intChecks >= 20 && intChecks < 40)
    {
        fltCheckFee = intChecks * 0.08f;
    }
    else if(intChecks >= 40 && intChecks < 60)
    {
        fltCheckFee = intChecks * 0.06f;
    }
    else if(intChecks >= 60)
    {
        fltCheckFee = intChecks * 0.04f;
    }
    else
    {
        cout << "ERROR CALCULATING CHECK FEE\n";
        return 0;
    }
    
    if(fltAccountBalance >= 0.0f && fltAccountBalance < 400.0f)
    {
        fltServiceFees = fltCheckFee + FLT_LOW_BALANCE_FEE;
        fltAccountBalance = fltAccountBalance - fltServiceFees;
    }
    else if(fltAccountBalance >= 400.0f)
    {
        fltServiceFees = fltCheckFee;
        fltAccountBalance = fltAccountBalance - fltServiceFees;
    }
    else
    {
        cout << "ERROR CALCULATING SERVICE FEE\n";
        return 0;
    }
    
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "Your banking fees for this month are:\n"
         << "$" << fltServiceFees << endl
         << "And your updated balance will be:\n"
         << "$" << fltAccountBalance;
    
    return 0;
}




