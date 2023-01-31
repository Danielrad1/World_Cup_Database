//
// Created by Daniel Masoumirad on 2022-11-28.
//

#ifndef ASSIGNMENT5_WORLDCUP_PLAYERS_H
#define ASSIGNMENT5_WORLDCUP_PLAYERS_H
struct PlayerNode *getPlayer(struct PlayerNode *node, int code);
void insert_player(struct PlayerNode *node);
void search_player(struct PlayerNode *node);
void update_player(struct PlayerNode *node);
void print_player(struct PlayerNode *node);
struct PlayerNode delete_player(struct PlayerNode *node);
#endif //ASSIGNMENT5_WORLDCUP_PLAYERS_H
