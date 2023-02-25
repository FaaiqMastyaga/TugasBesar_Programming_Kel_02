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

Kapal::Kapal(string inputType, double inputHealth, double inputDamage, int inputMaxRange, int* inputPosition){
    this->type = inputType;
    this->health = inputHealth;
    this->damage = inputDamage;
    this->max_range = inputMaxRange;
    this->position[0] = *(inputPosition);
    this->position[1] = *(inputPosition+1);
}

void Kapal::move(char arah){
    switch(arah){
        case 'w':
            this->position[1] += 1;
            break;
        case 's':
            this->position[1] -= 1;
            break;
        case 'd':
            this->position[0] += 1;
            break;
        case 'a':
            this->position[0] -= 1;
            break;
    }
}

double Kapal::distance_to_target(Kapal* &inputTarget){
    return sqrt(pow((double)(this->position[0] - inputTarget->position[0]), 2) + pow((double)(this->position[1] - inputTarget->position[1]), 2)); 
}

void Kapal::attack(Kapal* &inputEnemy){
    double distance = this->distance_to_target(inputEnemy);
        if(distance <= this->max_range){
            inputEnemy->health -= this->damage;
            cout << "\nDamage diberikan: " << this->damage << endl;
            cout << "Enemy health: " << inputEnemy->health << endl;
        }else{
            cout << "\nMaaf, Kapten. Target berada di luar jangkauan" << endl;
        }
}

Kapal::~Kapal(){
    if(this->type == "cakru"){
        cout << "\nKita telah kalah, Kapten. Kapal kita telah dihancurkan" << endl;
    }else{
        cout << "\nKapal musuh telah dihancurkan, Kapten!" << endl;
    }
}

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
    cout << "(a) Kiri" << endl;
    cout << "(d) Kanan" << endl;
}

void show_health(Kapal* &cakru, Kapal* &enemy){
    cout << "Health kapal kita: " << cakru->health << endl;
    cout << "Health kapal musuh: " << enemy->health << endl;
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