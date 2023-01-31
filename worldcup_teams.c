#include "worldcup_teams.h"
#include <stdio.h>
#include <stdlib.h>
int database_size;
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


// returns the colour when given the character form
char* getColour(char colour) {
    switch (colour) {
        case 'R':
            return "Red";
        case 'O':
            return "Orange";
        case 'Y':
            return "yellow";
        case 'G':
            return "Green";
        case 'B':
            return "Blue";
        case 'I':
            return "Indigo";
        case 'V':
            return "Violet";
    }

}

// returns the node with the given code, else returns last node.
struct TeamNode *getTeam(struct TeamNode *node, int code){
    while(node->next != NULL && node->data.code!= code) node = node->next;
    return node;
}


// inserts team into database
void insert_team(struct TeamNode *node){
    int team_code;
    char team_group_seed[2];
    char team_kit;

    printf("\n\tEnter team code: ");
    scanf("%d", &team_code);

    //checks for invalid code
    while(team_code < 0 ){
        printf("\n\tInvalid code, enter positive number: ");
        scanf("%d", &team_code);
    }
    struct TeamNode *curr = getTeam(node, team_code);

    // checks for duplicate code
    while(curr->next != NULL){
        printf("\n\tTeam already exists, enter new team code: ");
        scanf("%d", &team_code);
        curr = getTeam(node, team_code);
    }
    //sets the code
    curr->data.code = team_code;

    printf("\n\tEnter team name: ");
    scanf(" %[^\n]", curr->data.name);


    printf("\n\tEnter team seed: ");
    scanf(" %s", &team_group_seed);


    //checks for a valid seed
    while(team_group_seed[0] < 'A'
          || team_group_seed[0] > 'H'
          || team_group_seed[1] < 49
          || team_group_seed[1] > 52){

        printf("\n\tInvalid seed. Enter a new seed: ");
        scanf(" %s", &team_group_seed);
    }
    // adds the letter and the number of the seed to the array
    curr->data.groupSeed[0] = team_group_seed[0];
    curr->data.groupSeed[1] = team_group_seed[1];

    printf("\n\tEnter the kit colour: ");
    scanf(" %c", &team_kit);

    //checks for valid colour
    while ((team_kit != 'R' && team_kit != 'O' && team_kit != 'Y'
            && team_kit != 'G' && team_kit != 'B' && team_kit != 'I'
            && team_kit != 'V')){

        printf("\n\tInvalid kit, enter a new kit colour: ");
        scanf(" %c", &team_kit);
    }
    // if check passes, adds colour to array
    curr->data.kit = team_kit;

    curr->next = malloc(sizeof(struct TeamNode));

    //increases database size by 1 every time a new team is added
    database_size++;

}

// searches for a team in database
void search_team(struct TeamNode *node){
    int team_code;
    printf("\n\tEnter team code: ");
    scanf(" %d", &team_code);


    struct TeamNode *team = getTeam(node, team_code);

    // checks if team does not exist
    if(team->next == NULL){
        printf("\n\tTeam does not exist.");
        return;
    }

    // prints the team at given index
    printf("%-25s %-25s %-25s %-25s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");
    printf("%-25d %-25.25s %c%-25c %-25s\n",
           team->data.code,
           team->data.name,
           team->data.groupSeed[0],team->data.groupSeed[1] ,
           getColour(team->data.kit));
}

//updates and existing team
void update_team(struct TeamNode *node){
    int team_code;
    int new_team_code;
    char team_group_seed[2];
    char team_kit;


    printf("\n\tEnter team code: ");
    scanf("%d", &team_code);

    //checks for invalid code
    while(team_code < 0 ){
        printf("\n\tInvalid code, enter positive number: ");
        scanf("%d", &team_code);
    }
    struct TeamNode *curr = getTeam(node, team_code);

    // checks for non existant code
    if(curr->next == NULL){
        printf("\n\tTeam does not exist");
        return;
    }

    //user enters new information
    printf("\n\tEnter new team code: ");
    scanf("%d", &new_team_code);

    while(team_code < 0 ){
        printf("\n\tInvalid code, enter positive number: ");
        scanf("%d", &new_team_code);
    }
    struct TeamNode *newcurr = getTeam(node, new_team_code);

    while(newcurr->next != NULL){
        printf("\n\tTeam code already exists, enter new team code: ");
        scanf("%d", &team_code);
        newcurr = getTeam(node, team_code);
    }
    curr->data.code = new_team_code;

    printf("\n\tEnter new team name: ");
    scanf(" %[^\n]", curr->data.name);


    printf("\n\tEnter team seed: ");
    scanf(" %s", &team_group_seed);


    //checks for a valid seed
    while(team_group_seed[0] < 'A'
          || team_group_seed[0] > 'H'
          || team_group_seed[1] < 49
          || team_group_seed[1] > 52){

        printf("\n\tInvalid seed. Enter a new seed: ");
        scanf(" %s", &team_group_seed);
    }
    // adds the letter and the number of the seed to the array
    curr->data.groupSeed[0] = team_group_seed[0];
    curr->data.groupSeed[1] = team_group_seed[1];

    printf("\n\tEnter the kit colour: ");
    scanf(" %c", &team_kit);

    //checks for valid colour
    while ((team_kit != 'R' && team_kit != 'O' && team_kit != 'Y'
            && team_kit != 'G' && team_kit != 'B' && team_kit != 'I'
            && team_kit != 'V')){

        printf("\n\tInvalid kit, enter a new kit colour: ");
        scanf(" %c", &team_kit);
    }
    // if check passes, adds colour to array
    curr->data.kit = team_kit;

}

// Prints information of all teams
void print_team(struct TeamNode *node) {
    struct TeamNode *curr = node;

    printf("%-25s %-25s %-25s %-25s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");
    while(curr->next != NULL){
        printf("%-25d %-25.25s %c%-25c %-25s\n",
               curr->data.code,
               curr->data.name,
               curr->data.groupSeed[0],curr->data.groupSeed[1] ,
               getColour(curr->data.kit));
        curr = curr->next;
    }

}

// deletes a given team
struct TeamNode delete_team(struct TeamNode *node){
    int team_code;
    printf("\n\tEnter team code to be deleted: ");
    scanf(" %d", &team_code);
    struct TeamNode *curr =  node;


    // if deleting head
    if(curr->data.code == team_code){
        struct TeamNode *temp = curr->next;
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
        curr->next = malloc(sizeof(struct TeamNode));
        return *node;
    }

        // if deleting node in middle;
    else {
        struct TeamNode *temp = curr->next->next;
        free(curr->next);
        curr->next = temp;
        return *node;
    }

}


