#include <iostream>
#include <string>

class Kapal{
    public:
        std::string type;
        double health;
        double damage;
        int max_range;
        int position[2] = {0,0};

        Kapal(std::string, double, double, int, int*);
        void move(char);
        double distance_to_target(Kapal*&);
        void attack(Kapal*&);
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