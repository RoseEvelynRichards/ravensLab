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
 * @brief Implements a number generator between 0 and int x
 * 
 * @param x the end results, should be -1 of intended result
 * @return int random nuber
 */
 int random(int x){
   std::mt19937 mt{ static_cast<std::mt19937::result_type>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		)};
   
   std::uniform_int_distribution coinFlip{0,x};
   int y = coinFlip(mt);
   return y;
 }


/**
 * @brief the human interface of the Monty Hall program, 1 = car, 0 = goat
 * 
 */
void humanMontyHall(){
   std::vector<int> doors = {2,2,2};
    

   doors.at(0) = random(1);
   if (doors.at(0) == 1){
      doors.at(1) = 0;
      doors.at(2) = 0;
   } 
   else doors.at(1) = random(1);
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
               std::cout << "Door number 3.... is a Car! Meaning door number 1 is a goat. ";
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
         if (doors.at(0) == 0){
            std::cout << "Door number 1 is a goat! Do you wish to switch doors? (y/n): ";
            std::cin >> ynprompt;
            if (ynprompt == 'y'){
               prompt = 3;
            }
            std::cout << "Revealing the next door! ";
            
            if (doors.at(2) == 0){
               std::cout << "Door number 3.... is a Goat! Meaning door number 2 is a brand new car! ";
               if (prompt == 1) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            } else{
               std::cout << "Door number 3.... is a Car! Meaning door number 2 is a goat. ";
               if (prompt == 2) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            }

            break;
         }
         else {
            std::cout << "Door number 3 is a goat! Do you wish to switch doors? (y/n): ";
            std::cin >> ynprompt;
            if (ynprompt == 'y'){
               prompt = 0;
            }
            std::cout << "Revealing the next door! ";

            if (doors.at(2) == 0){
               std::cout << "Door number 3.... is a Goat! Meaning door number 2 is a brand new car! ";
               if (prompt == 1) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            } else{
               std::cout << "Door number 3.... is a Car! Meaning door number 2 is a goat. ";
               if (prompt == 2) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            }
            break;
         }
         
      case 2:
         if (doors.at(1) == 0){
            std::cout << "Door number 2 is a goat! Do you wish to switch doors? (y/n): ";
            std::cin >> ynprompt;
            if (ynprompt == 'y'){
               prompt = 0;
            }
            std::cout << "Revealing the next door! ";
            
            if (doors.at(0) == 0){
               std::cout << "Door number 1.... is a Goat! Meaning door number 3 is a brand new car! ";
               if (prompt == 2) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            } else{
               std::cout << "Door number 1.... is a Car! Meaning door number 3 is a goat. ";
               if (prompt == 0) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            }

            break;
         }
         else {
            std::cout << "Door number 1 is a goat! Do you wish to switch doors? (y/n): ";
            std::cin >> ynprompt;
            if (ynprompt == 'y'){
               prompt = 1;
            }
            std::cout << "Revealing the next door! ";

            if (doors.at(1) == 0){
               std::cout << "Door number 2.... is a Goat! Meaning door number 3 is a brand new car! ";
               if (prompt == 2) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            } else{
               std::cout << "Door number 2.... is a Car! Meaning door number 3 is a goat. ";
               if (prompt == 1) std::cout << "Congrats on your brand new car.";
               else std::cout << "Better luck next time.";
            }
            break;
         }

      default: 
         std::cout << "Your input is invalid. Rerun the program.";
         break;
   }
   //bloody goats!
   return;
}

/**
 * @brief Simulates the monty hall problem num_iterations times and prints the stats with std::cout. The simulation will always switch doors. 
 * 
 * @param num_iterations Amount of times to simulate the program
 */
void simulateMontyHall(int num_iterations){
   double win = 0;
   double lose = 0;
   int prompt;

   for (int i = 0; i < num_iterations; i++){
      prompt = 0;
      std::vector<int> doors = {2,2,2};
      doors.at(0) = random(1);
      if (doors.at(0) == 1){
         doors.at(1) = 0;
         doors.at(2) = 0;
      } 
      else doors.at(1) = random(1);
      if (doors.at(1) == 1) doors.at(2) = 0;
      if (doors.at(0) == 0 && doors.at(1) == 0) doors.at(2) = 1;

      prompt = random(2);
      switch(prompt){
         case 0:
            if (doors.at(1) == 0){
               prompt = 2;

               if (doors.at(2) == 0) lose++;
               else win++;
               break;
            }   
            else {
               prompt = 1;
            
               if (doors.at(1) == 0) lose++;
               else win++;
               break;
            }

         case 1:
            if (doors.at(0) == 0){
               prompt = 3;

               if (doors.at(2) == 0) lose++;
               else win++;
            break;
            }
            else {
               prompt = 0;
            
               if (doors.at(0) == 0) lose++;
               else win++;
               break;
            }
         
         case 2:
            if (doors.at(1) == 0){
               prompt = 0;

               if (doors.at(0) == 0) lose++;
               else win++;
               break;
         }
         else {
            prompt = 1;

            if (doors.at(1) == 0) lose++;
            else win++;
            break;
         }
      }
   }
   double winRate = 0;
   winRate = win / num_iterations + 0.0;
   std::cout << "Simulation Over: \n Wins: " << win << "\n Losses: " << lose << " \n Winrate: " << winRate << std::endl;

}

int main(){
   int prompt;
   std::cout << "Do you wish to perform the Monty Hall program yourself(0) or simulate it(1)?: ";
   std::cin >> prompt;
   if (prompt == 0) humanMontyHall();
   else if (prompt == 1){
      std::cout << "How many times do you wish to simulate it?: ";
      std::cin >> prompt;
      simulateMontyHall(prompt);
   }

   std::cout << std::endl;
   return 0;
 }