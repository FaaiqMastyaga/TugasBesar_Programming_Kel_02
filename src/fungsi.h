#include <iostream>
#include <string>

class Kapal{
    public:
        std::string type;
        double health;
        double damage;
        int max_range;
        int position[2] = {0,0};

        Kapal(std::string inputType, double inputHealth, double inputDamage, int inputMaxRange, int* inputPosition);
        void move(char arah);
        double distance_to_target(Kapal* &inputTarget);
        void attack(Kapal* &inputEnemy);
        ~Kapal();
};

int random(int min, int max);

void command_info();

void direction();