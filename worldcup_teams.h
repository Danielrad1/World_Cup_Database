//
// Created by Daniel Masoumirad on 2022-11-28.
//

#ifndef ASSIGNMENT5_WORLDCUP_TEAMS_H
#define ASSIGNMENT5_WORLDCUP_TEAMS_H
char* getColour(char colour);
struct TeamNode *getTeam(struct TeamNode *node, int code);
void insert_team(struct TeamNode *node);
void search_team(struct TeamNode *node);
void update_team(struct TeamNode *node);
void print_team(struct TeamNode *node);
struct TeamNode delete_team(struct TeamNode *node);

#endif //ASSIGNMENT5_WORLDCUP_TEAMS_H
