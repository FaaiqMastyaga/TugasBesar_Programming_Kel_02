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

    if(this->type == "enemy"){
        cout << "\nInfo, Kapten! Kapal musuh terdeteksi" << endl;
    }
}

int Kapal::check_position_to_map(int* cakruPosition){
    int x = (cakruPosition[0] >= -MAP_SIZE) && (cakruPosition[0] <= MAP_SIZE);
    int y = (cakruPosition[1] >= -MAP_SIZE) && (cakruPosition[1] <= MAP_SIZE);
    return x && y;
}

int Kapal::check_position_to_enemy(int* cakruPosition, int* enemyPosition){
    int x = (cakruPosition[0] == enemyPosition[0]);
    int y = (cakruPosition[1] == enemyPosition[1]);
    return !(x && y);
}

int Kapal::check_position(int* cakruPosition, int* enemyPosition){
    return check_position_to_map(cakruPosition) && check_position_to_enemy(cakruPosition, enemyPosition);
}

void Kapal::move(char arah, Kapal* &inputEnemy){
    if((arah == 'w') || (arah == 's') || (arah == 'd') || (arah == 'a')){
        switch(arah){
            case 'w':
                this->position[1] += 1;
                if(!(this->check_position(this->position, inputEnemy->position))){
                    cout << "\nMaaf, Kapten. Kapal kita tidak bisa bergerak ke arah tersebut" << endl;
                    this->position[1] -= 1;
                }
                break;
            case 's':
                this->position[1] -= 1;
                if(!(this->check_position(this->position, inputEnemy->position))){
                    cout << "\nMaaf, Kapten. Kapal kita tidak bisa bergerak ke arah tersebut" << endl;
                    this->position[1] += 1;
                }
                break;
            case 'd':
                this->position[0] += 1;
                if(!(this->check_position(this->position, inputEnemy->position))){
                    cout << "\nMaaf, Kapten. Kapal kita tidak bisa bergerak ke arah tersebut" << endl;
                    this->position[0] -= 1;
                }
                break;
            case 'a':
                this->position[0] -= 1;
                if(!(this->check_position(this->position, inputEnemy->position))){
                    cout << "\nMaaf, Kapten. Kapal kita tidak bisa bergerak ke arah tersebut" << endl;
                    this->position[0] += 1;
                }
                break;
        }
    }else{
        cout << "\nKami tidak mengerti maksud Anda, Kapten" << endl;
    }
}

double Kapal::distance_to_target(Kapal* &inputTarget){
    return sqrt(pow((double)(this->position[0] - inputTarget->position[0]), 2) + pow((double)(this->position[1] - inputTarget->position[1]), 2)); 
}

void Kapal::attack(Kapal* &inputEnemy){
    double distance = this->distance_to_target(inputEnemy);
    if(this->type == "cakru"){
        if(distance <= this->max_range){
            inputEnemy->health -= this->damage;
            cout << "\nInfo, Kapten! Kita telah menyerang kapal lawan" << endl;
            cout << "Damage diberikan: " << this->damage << endl;
            cout << "Enemy health: " << inputEnemy->health << endl;
        }else{
            cout << "\nMaaf, Kapten. Target berada di luar jangkauan" << endl;
        }
    }else{
        if(distance <= this->max_range){
            inputEnemy->health -= this->damage;
            cout << "\nGawat, Kapten! Kapal kita telah diserang" << endl;
            cout << "Damage diterima: " << this->damage << endl;
            cout << "Health kapal kita: " << inputEnemy->health << endl;
        }
    }
}

int random(int min, int max){
    return (rand()%(max-min+1) + min);
}

void set_coordinate(int* coordinate){
    coordinate[0] = random(-MAP_SIZE, MAP_SIZE);
    coordinate[1] = random(-MAP_SIZE, MAP_SIZE);
};

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

void command(int perintah, Kapal* cakru, Kapal* enemy){
    char arah;
    if((perintah == '1') || (perintah == '2') || (perintah == '3')){
        switch(perintah){
            case '1':
                cakru->attack(enemy);
                enemy->attack(cakru);
                break;
            case '2':
                show_info(cakru, enemy);
                direction();
                cout << "Ke mana kita akan bergerak, Kapten? : ";
                cin >> arah;
                cakru->move(arah, enemy);
                enemy->attack(cakru);
                break;
            case '3':
                cout << "\nKapal kita berdiam di tempat sesuai arahan, Kapten." << endl;
                enemy->attack(cakru);
                break;
        }
    }else{
        cout << "\nKami tidak mengerti maksud Anda, Kapten" << endl;
    }
}