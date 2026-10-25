/**
 * @file player.cpp
 * @author Rose Richards (rose.evelyn5550@gmail.com)
 * @brief Implementation of player.h
 * @version 0.1
 * @date 2026-10-25
 * 
 * @copyright Copyright (c) 2026
 * 
*/

#include <iostream>
#include <random>
#include <chrono>
#include "player.h"
#include "enemy.h"

player::player(int hp, int atk, int def, int crit){
    Php = hp;
    Patk = atk;
    Pdef = def;
    Pcrit = crit;
    totalDef = Pdef;
    Alive = true;
}

void player::takeDMG(int amount){
    
    Php = Php - amount;
}

bool player::isAlive(){
    if (Php <= 0) Alive = false;
    if (Alive) return true;
    else return false;
}

int player::getHP(){
    return Php;
}

int player::getDef(){
    return totalDef;
}

void player::turn(enemy& target){
    totalDef = Pdef;
    int prompt;
    std::cout << "===============================\n1.Attack 2.Defend 3.Item 4.Flee\n===============================\n> ";
    while (true) {
        if (!(std::cin >> prompt)) {
            return;
        }
        if (prompt >= 1 && prompt <= 4) {
            break;
        }
        std::cout << "Invalid Choice" << std::endl << "> ";
    }
    
    switch (prompt){
        case 1: player::attack(target); break;
        case 2: player::defend(); break;
        case 3: player::useItem(); break;
        case 4: player::flee(); break;
    }
}


void player::attack(enemy& target){
    std::mt19937 mt{ static_cast<std::mt19937::result_type>(
	std::chrono::steady_clock::now().time_since_epoch().count()
    )};
    int atk = Patk;
    int minAtk = atk/2;
    int maxAtk = atk*2;
    std::uniform_int_distribution rand{minAtk,maxAtk};
    std::uniform_int_distribution critical{1,100};
    int chance = critical(mt);
    int damage =rand(mt);
    if (chance <= Pcrit) {
        damage += maxAtk;
        std::cout << "You dealt a crit!" << std::endl;
    }
    target.takeDMG(damage);
    std::cout << "You dealt " << damage << " damage to " << target.getName() << std::endl;
}

void player::defend(){
    totalDef = totalDef + (Pdef / 2);
    std::cout << "You raised your defense by " << (Pdef / 2) << std::endl;
}

void player::useItem(){
    std::cout << "Items are not implemented yet." << std::endl;
}

void player::flee(){
    std::cout << "Flee is not implemented yet." << std::endl;
}