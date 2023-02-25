#ifndef __KAPAL
#define __KAPAL

#include <string>

class Kapal{
    private:
        std::string type;
        double health;
        double max_health;
        double damage;
        int max_range;
        int position[2] = {0,0};

    public:
        // constructor
        Kapal(std::string, double, double, int, int*);

        // getter
        double getHealth();
        double getDamage();
        double getMaxHealth();
        int getMaxRange();
        int* getPosition();

        // method
        int check_position_to_map(int*);
        int check_position_to_enemy(int*, int*);
        int check_position(int*, int*);
        void move(char, Kapal*&);
        double distance_to_target(Kapal*&);
        void attack(Kapal*&);
        void health_recovery(double);
        void eval_health();     
};

int random(int, int);

void set_coordinate(int*);

void command_info();

void direction();

void show_health(Kapal*&, Kapal*&);

void show_position(Kapal*&, Kapal*&);

void show_shoot_range(Kapal*&, Kapal*&);

void show_info(Kapal*&, Kapal*&);

void command(int, Kapal*, Kapal*);

void delay(int);

void loading();

#endif