/**
 * @file enemy.cpp
 * @author Rose Richards (rose.evelyn5550@gmai.com)
 * @brief Implementation of enemy.h
 * @version 0.1
 * @date 2026-10-25
 * 
 * @copyright Copyright (c) 2026
 * 
*/

#include <iostream>
#include <random>
#include <chrono>
#include "enemy.h"
#include "player.h"

enemy::enemy(std::string name, int hp, int atk, int crit){
    Ename = name;
    Ehp = hp;
    Eatk = atk;
    Ecrit = crit;
}

void enemy::takeDMG(int amount){
    Ehp = Ehp - amount;
}

void enemy::attack(player& target){
    std::mt19937 mt{ static_cast<std::mt19937::result_type>(
	std::chrono::steady_clock::now().time_since_epoch().count()
    )};
    int atk = Eatk;
    int minAtk = atk/2;
    int maxAtk = atk*2;
    std::uniform_int_distribution rand{minAtk,maxAtk};
    std::uniform_int_distribution critical{1,100};
    int chance = critical(mt);
    int damage =rand(mt);
    if (chance <= Ecrit) {
        damage += maxAtk;
        std::cout << Ename <<" dealt a crit!" << std::endl;
    }
    damage = damage - target.getDef();
    if (damage <= 0) std::cout << Ename << " couldn't breach your armor!";
    else{
        target.takeDMG(damage);
        std::cout << Ename <<" dealt " << damage << " damage to you!" << std::endl;
    }
}

bool enemy::isAlive(){
    if (Ehp <= 0) Alive = false;

    if (Alive) return true;
    else return false;
}


int enemy::getHP(){
    return Ehp;
}

std::string enemy::getName(){
    return Ename;
}