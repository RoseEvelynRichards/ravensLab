#pragma once

class enemy;

class player{
    public:
        /**
         * @brief Sets the stats for the player
         * 
         * @param hp Amount of health player starts with
         * @param atk Average amount of damage the player starts with
         * @param def Amount of defense the player starts with
         * @param crit Critical strike chance the player starts with
         */
        player(int hp, int atk, int def, int crit);

        /**
         * @brief Reduces the players's hp based on amount
         * 
         * @param amount amount of damage taken
         */
        void takeDMG(int amount);

        /**
         * @brief Prompts the user for input
         * 
         */
        void turn(enemy& target);

        /**
         * @brief The player does a psuedo-random damage to target
         * 
         */
        void attack(enemy& target);

        /**
         * @brief The player gains defense for a turn
         * 
         */
        void defend();

        /**
         * @brief Opens the item list
         * 
         */
        void useItem();

        /**
         * @brief Player flees from the fight
         * 
         */
        void flee();

        /**
         * @brief Checks if the player is alive
         * 
         * @return true Php > 0
         * @return false Php <= 0
         */
        bool isAlive();

        /**
         * @brief Returns the player's hp
         * 
         * @return int player's hp
         */
        int getHP();

        /**
         * @brief Get the player's defense
         * 
         * @return int player's defense
         */
        int getDef();

    private:
        int Php;
        int Patk;
        int Pdef;
        int totalDef;
        int Pcrit;
        bool Alive;
};