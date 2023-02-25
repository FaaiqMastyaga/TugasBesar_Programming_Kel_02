#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>
#include "fungsi.h"

#define MAP_SIZE 5
#define MIN_HEALTH 100 // minimum health kapal musuh
#define MAX_HEALTH 150 // maksimum health kapal musuh
#define MIN_DAMAGE 10 // minimum damage kapal musuh
#define MAX_DAMAGE 30 // maksimum damage kapal musuh
#define MIN_RANGE 1 // minimum range tembak kapal musuh
#define MAX_RANGE 4 // maksimum range tembak kapal musuh

using namespace std;

class Kapal{
    public:
        string type;
        int health;
        int damage;
        int max_range;
        int *position = (int*)calloc(2, sizeof(int));
        
        Kapal(string inputType, int inputHealth, int inputDamage, int inputMaxRange, int *inputPosition){
            Kapal::type = inputType;
            Kapal::health = inputHealth;
            Kapal::damage = inputDamage;
            Kapal::max_range = inputMaxRange;
            Kapal::position[0] = *(inputPosition);
            Kapal::position[1] = *(inputPosition+1);
        }

        void move(char arah){
            switch(arah){
                case 'w':
                    Kapal::position[1] += 1;
                    break;
                case 's':
                    Kapal::position[1] -= 1;
                    break;
                case 'd':
                    Kapal::position[0] += 1;
                    break;
                case 'a':
                    Kapal::position[0] -= 1;
                    break;
            }
        }

        double distance_to_target(Kapal* &inputTarget){
            return sqrt(pow((double)(Kapal::position[0] - inputTarget->position[0]), 2) + pow((double)(Kapal::position[1] - inputTarget->position[1]), 2));
        }

        void attack(Kapal* &inputEnemy){
            double distance = Kapal::distance_to_target(inputEnemy);
            if(distance <= Kapal::max_range){
                inputEnemy->health -= Kapal::damage;
                cout << "\nDamage diberikan: " << Kapal::damage << endl;
                cout << "Enemy health: " << inputEnemy->health << endl;
            }else{
                cout << "\nMaaf, Kapten. Target berada di luar jangkauan" << endl;
            }
        }

        ~Kapal(){
            if(Kapal::type == "cakru"){
                cout << "\nKita telah kalah, Kapten. Kapal kita telah dihancurkan" << endl;
            }else{
                cout << "\nKapal musuh telah dihancurkan, Kapten!" << endl;
            }
        }
};

int random(int min, int max){
    return (rand()%(max-min+1) + min);
}

void command_info(){
    cout << "\nKami siap menerima perintah, Kapten" << endl;
        cout << "(1) Menembak" << endl; 
        cout << "(2) Bergerak" << endl; 
        cout << "(3) Diam di tempat" << endl;
        cout << "Perintah Anda, Kapten : ";
}

void direction(){
    cout << "\nKapal kita dapat bergerak dalam arah berikut, Kapten" << endl;
    cout << "(w) Maju" << endl;
    cout << "(s) Mundur" << endl;
    cout << "(a) Kanan" << endl;
    cout << "(d) Kiri" << endl;
}

void show_position(Kapal* &cakru, Kapal* &enemy){
    cout << "Posisi kapal kita: (" << cakru->position[0] << ", " << cakru->position[1] << ")" << endl;
    cout << "Posisi kapal musuh: (" << enemy->position[0] << ", " << enemy->position[1] << ")" << endl;
    cout << "Jarak terhadap musuh: " << cakru->distance_to_target(enemy) << endl;
}

void show_shoot_range(Kapal* &cakru, Kapal* &enemy){
    cout << "Range tembak kapal kita: " << cakru->max_range << endl;
    cout << "Range tembak kapal musuh: " << enemy->max_range << endl;
}

void show_info(Kapal* &cakru, Kapal* &enemy){
    cout << "\nInfo, Kapten!" << endl;
    show_health(cakru, enemy);
    show_position(cakru, enemy);
    show_shoot_range(cakru, enemy);
}