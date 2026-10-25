#pragma once

#include <string>

class player;

class enemy{
    public:
        /**
         * @brief Sets the stats for the enemy
         * 
         * @param name Name of the enemy
         * @param hp Amount of health points to start with
         * @param atk Average damage amount
         * @param crit Critical strike chance, max damage + another roll
         */
        enemy(std::string name, int hp, int atk, int crit);

        /**
         * @brief Reduces the enemy's hp based on amount
         * 
         * @param amount amount of damage taken
         */
        void takeDMG(int amount);

        /**
         * @brief The enemy does a psuedo-random damage to target
         * 
         * 
         */
        void attack(player& target);

        /**
         * @brief Checks if the enemy is alive
         * 
         * @return true Ehp > 0
         * @return false Ehp <= 0
         */
        bool isAlive();

        /**
         * @brief Returns the enemy's hp
         * 
         * @return int Enemy's hp
         */
        int getHP();

        /**
         * @brief Get the enemy's name
         * 
         * @return std::string Enemy's name
         */
        std::string getName();


    private:
        std::string Ename = "";
        int Ehp;
        int Eatk;
        int Ecrit;
        bool Alive = true;
};
