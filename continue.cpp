#include <iostream>
using namespace std;

#include <stdio.h>

int main() {
   const int EMPANADA_COST = 3;
   const int TACO_COST     = 4;
   
   int userMoney;
   int numTacos;
   int numEmpanadas;
   int mealCost;
   int maxEmpanadas;
   int maxTacos;
   int numOptions;
   int numDiners;

   mealCost = 0;
   numOptions = 0;
   
   cout << "Enter money for meal: ";
   cin >> userMoney;
   
   cout << "How many people are eating: ";
   cin >> numDiners;
   
   maxEmpanadas = userMoney / EMPANADA_COST;
   maxTacos     = userMoney / TACO_COST;
   
   numOptions = 0;
   for (numTacos = 0; numTacos <= maxTacos; ++numTacos) {
      for (numEmpanadas = 0; numEmpanadas <= maxEmpanadas; ++numEmpanadas) {
         
         // Total items purchased must be equally 
         // divisible by number of diners
         if ( ((numTacos + numEmpanadas) % numDiners) != 0) {
            continue;
         }
         
         mealCost = (numEmpanadas * EMPANADA_COST) + (numTacos * TACO_COST);
         
         if (mealCost == userMoney) {
            cout << "$" << mealCost << " buys " << numEmpanadas
                 << " empanadas and " << numTacos 
                 << " tacos without change." << endl;
            numOptions = numOptions + 1;
         }
      }
   }
   
   if (numOptions == 0) {
      cout << "You cannot buy a meal without " 
           << "having change left over." << endl;
   }
   
   return 0;
}

// Enter money for meal: 60
// How many people are eating: 3
// $60 buys 12 empanadas and 6 tacos without change.
// $60 buys 0 empanadas and 15 tacos without change.

// ...

// Enter money for meal: 54
// How many people are eating: 2
// $54 buys 18 empanadas and 0 tacos without change.
// $54 buys 10 empanadas and 6 tacos without change.
// $54 buys 2 empanadas and 12 tacos without change.