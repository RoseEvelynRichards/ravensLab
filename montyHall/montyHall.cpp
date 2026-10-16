/**
 * @file montyHall.cpp
 * @author Rose Richards (rricha58@skyhawks.utm.edu)
 * @brief The Monty Hall Paradox script
 * @version 0.1
 * @date 2026-10-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */

 #include <iostream>
 #include <vector>
 #include <random>
 #include <chrono>

/**
 * @brief uses libraries random & chrono to choose a number between 1 and 0
 * 
 * @return int 1 or 0
 */
 int oneOrZero(){
   std::mt19937 mt{ static_cast<std::mt19937::result_type>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		) };
   
   std::uniform_int_distribution coinFlip{0,1};
   int x = coinFlip(mt);
   return x;
 }


/**
 * @brief the human interface of the Monty Hall program, 1 = car, 0 = goat
 * 
 */
void humanMontyHall(){
   std::vector<int> doors = {2,2,2};
    

   doors.at(0) = oneOrZero();
   if (doors.at(0) == 1){
      doors.at(1) = 0;
      doors.at(2) = 0;
   } 
   else doors.at(1) = oneOrZero();
   if (doors.at(1) == 1) doors.at(2) = 0;
   if (doors.at(0) == 0 && doors.at(1) == 0)doors.at(2) = 1;
   //std::cout << "Output Test: "<< doors[0] << doors[1] << doors[2]; 

   int prompt;
   std::cout << "Pick a door, 1, 2, or 3: ";
   std::cin >> prompt;
   prompt = prompt - 1;
   char ynprompt;
   
   switch(prompt){
      case 0:
         if (doors.at(1) == 0){
            std::cout << "Door number 2 is a goat! Do you wish to switch doors? (y/n): ";
            std::cin >> ynprompt;
            if (ynprompt == 'y'){
               prompt = 2;
            }
            std::cout << "Revealing the next door! ";
            if (doors.at(2) == 0){
               std::cout << "Door number 3.... is a Goat! Meaning door number 1 is a brand new car! ";
               if (prompt == 0) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            } else{
               std::cout << "Door number 3.... is a Car! Meaning door number 1 is a goat.";
               if (prompt == 2) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            }

            break;
         }
         else {
            std::cout << "Door number 3 is a goat! Do you wish to switch doors? (y/n): ";
            std::cin >> ynprompt;
            if (ynprompt == 'y'){
               prompt = 1;
            }
            std::cout << "Revealing the next door! ";
            if (doors.at(1) == 0){
               std::cout << "Door number 2.... is a Goat! Meaning door number 1 is a brand new car! ";
               if (prompt == 0) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            } else{
               std::cout << "Door number 2.... is a Car! Meaning door number 1 is a goat. ";
               if (prompt == 1) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            }
            break;
         }

      case 1:
         


      case 2:
        
      

      default: 
         std::cout << "Your input is invalid. Rerun the program.";
         break;
   }
   //bloody goats!
   return;
}

int main(){
   int prompt;
   std::cout << "Do you wish to perform the Monty Hall program yourself(0) or simulate it(1)?: ";
   std::cin >> prompt;
   if (prompt == 0) humanMontyHall();
   else {

   }

   std::cout << std::endl;
   return 0;
 }