
#include <stdio.h>
#include <stdlib.h>
#include "worldcup_players.h"

struct Player{
    int code;
    char name[50];
    int age;
    char club[50];
};

struct PlayerNode{
    struct Player data;
    struct PlayerNode *next;
};


// returns node with given code
struct PlayerNode *getPlayer(struct PlayerNode *node, int code){
    while(node->next != NULL && node->data.code!= code) node = node->next;
    return node;
}


// inserts player in database
void insert_player(struct PlayerNode *node){
    int player_code;
    int player_age;

    printf("\n\tEnter player code: ");
    scanf("%d", &player_code);

    // checks for valid code
    while(player_code < 0 ){
        printf("\n\tInvalid code, enter positive number: ");
        scanf("%d", &player_code);
    }
    struct PlayerNode *curr = getPlayer(node, player_code);

    // checks for already existing code
    while(curr->next != NULL){
        printf("\n\tPlayer already exists, enter new player code: ");
        scanf("%d", &player_code);
        curr = getPlayer(node, player_code);
    }
    curr->data.code = player_code;

    // sets name
    printf("\n\tEnter player name: ");
    scanf(" %[^\n]", curr->data.name);


    //validates age and sets in database
    printf("\n\tEnter player age: ");
    scanf(" %d", &player_age);

    while(player_age < 17 || player_age > 99){
        printf("\n\tInvalid age, enter new age: ");
        scanf(" %d", &player_age);
    }
    curr->data.age = player_age;

    // enters club
    printf("\n\tEnter player club: ");
    scanf(" %[^\n]", curr->data.club);

    // initializes next node
    curr->next = malloc(sizeof(struct PlayerNode));


}

// searches for a team in database
void search_player(struct PlayerNode *node){
    int player_code;
    printf("\n\tEnter Player code: ");
    scanf(" %d", &player_code);


    struct PlayerNode *player = getPlayer(node, player_code);

    if(player->next == NULL){
        printf("\n\tPlayer does not exist.");
        return;
    }

    // prints given player
    printf("%-25s %-50s %-25s %-50s\n", "Player Code", "Player Name", "Age", "Club");
    printf("%-25d %-50.50s %-25d %-50.50s\n",
           player->data.code,
           player->data.name,
           player->data.age ,
           player->data.club);
}

// updates a given player
void update_player(struct PlayerNode *node){
    int player_code;
    int new_player_code;
    int player_age;

    printf("\n\tEnter player code: ");
    scanf("%d", &player_code);

    struct PlayerNode *curr = getPlayer(node, player_code);

    if(curr->next == NULL){
        printf("\n\tPlayer does not exist");
        return;
    }

    // user enters new information
    printf("\n\tEnter new player code: ");
    scanf("%d", &new_player_code);

    while(player_code < 0 ){
        printf("\n\tInvalid code, enter positive number: ");
        scanf("%d", &new_player_code);
    }
    struct PlayerNode *newcurr = getPlayer(node, new_player_code);

    //checks for already existing player
    while(newcurr->next != NULL){
        printf("\n\tPlayer code already exists, enter new player code: ");
        scanf("%d", &new_player_code);
        newcurr = getPlayer(node, new_player_code);
    }
    curr->data.code = new_player_code;

    printf("\n\tEnter new player name: ");
    scanf(" %[^\n]", curr->data.name);


    printf("\n\tEnter player age: ");
    scanf(" %d", &player_age);

    while(player_age < 17 || player_age > 99){
        printf("\n\tInvalid age, enter new age: ");
        scanf(" %d", &player_age);
    }
    curr->data.age = player_age;

    printf("\n\tEnter player club: ");
    scanf(" %[^\n]", curr->data.club);

}

// prints all players
void print_player(struct PlayerNode *node) {
    struct PlayerNode *curr = node;

    printf("%-25s %-50s %-25s %-50s\n", "Player Code", "Player Name", "Age", "Club");

    while(curr->next != NULL){
        printf("%-25d %-50.50s %-25d %-50.50s\n",
               curr->data.code,
               curr->data.name,
               curr->data.age ,
               curr->data.club);
        curr = curr->next;
    }

}

// deletes a given player
struct PlayerNode delete_player(struct PlayerNode *node){
    int team_code;
    printf("\n\tEnter team code to be deleted: ");
    scanf(" %d", &team_code);
    struct PlayerNode *curr =  node;


    // if deleting head
    if(curr->data.code == team_code){
        struct PlayerNode *temp = curr->next;
        curr->next = NULL;
        curr = temp;
        return *curr;
    }


    while(curr->next != NULL && curr->next->data.code != team_code){
        curr = curr->next;
    }
    //checks for invalid code;
    if (curr->next == NULL){
        printf("\n\tinvalid code");
        return *node;
    }

    // if deleting tail;
    if(curr->next->next == NULL){
        free(curr->next);
        curr->next = malloc(sizeof(struct PlayerNode));
        return *node;
    }

        // if deleting node in middle:
    else {
        struct PlayerNode *temp = curr->next->next;
        free(curr->next);
        curr->next = temp;
        return *node;
    }

}
