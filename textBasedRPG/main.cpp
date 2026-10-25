/**
 * @file main.cpp
 * @author Rose Richards (rose.evelyn5550@gmail.com)
 * @brief idk man I'm bored lets make a text rpg
 * @version 0.1
 * @date 2026-10-24
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
#include "player.h"
#include "enemy.h"

/**
 * @brief its the main function man idk
 * 
 * @return int should return 0 if not I guess I've been hacked
 */
int main(){
    system("clear");
    
    player user(100,25,50,25);
    enemy dummy("Dragon",500,50,10);

    while(dummy.isAlive() == true && user.isAlive() == true){
        user.turn(dummy);
        dummy.attack(user);
        std::cout << std::endl << "Your HP: " << user.getHP() << " = Their HP: " << dummy.getHP() << std::endl << std::endl;
    }

    if (dummy.isAlive() == false && user.isAlive() == false) std::cout << "You have both been defeated...";
    else if (dummy.isAlive()) std::cout << "You have been defeated...";
    else std::cout << dummy.getName() << " is defeated!";
    
    return 0;
}
