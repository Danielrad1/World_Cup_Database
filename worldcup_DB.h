//
// Created by Daniel Masoumirad on 2022-11-28.
//

#ifndef ASSIGNMENT5_WORLDCUP_DB_H
#define ASSIGNMENT5_WORLDCUP_DB_H
struct Player{
    int code;
    char name[50];
    int age;
    char club[50];
};

struct Team{
    int code;
    char name[25];
    char groupSeed[2];
    char kit;
};
struct TeamNode{
    struct Team data;
    struct TeamNode *next;
};
struct PlayerNode{
    struct Player data;
    struct PlayerNode *next;
};
#endif //ASSIGNMENT5_WORLDCUP_DB_H
