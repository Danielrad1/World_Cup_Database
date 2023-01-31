#include <stdlib.h>
#include <printf.h>
#include "worldcup_teams.h"
#include "worldcup_players.h"
#include "worldcup_DB.h"


int main() {
    struct TeamNode *teamhead = malloc(sizeof(struct TeamNode));
    struct PlayerNode *playerhead = malloc(sizeof(struct PlayerNode));

    //welcome message
    printf("******************\n"
           "* 2211 World Cup *\n"
           "******************");

    // temporary variable
    char user_input;
    char initial_user_input = 'x';

    // keeps asking user for input until quit is specified

    while (initial_user_input != 'q') {
        printf("\n\nEnter command ->"
               " Help: h "
               "Quit: q "
               "Control Teams: t "
               "Control Players: p: " );
        scanf(" %c", &initial_user_input);

        switch (initial_user_input) {
            case 'h':
                printf("Use the the given commands to change database. You can change both the teams and the players."
                       "\ni to insert new team or player, s to search for team or player, u to update, p to print,\n"
                       "and d to delete. choose from teams or players to continue ");
                break;
            case 'q':
                break;
            case 't':
                user_input = 'x';
                while (user_input != 'q') {
                    printf("\nEnter operation code: ");
                    scanf(" %c", &user_input);

                    switch (user_input) {
                        case 'i':
                            insert_team(teamhead);
                            break;
                        case 's':
                            search_team(teamhead);
                            break;
                        case 'u':
                            update_team(teamhead);
                            break;
                        case 'p':
                            print_team(teamhead);
                            break;
                        case 'd':
                            *teamhead = delete_team(teamhead);
                        case 'q':
                            break;
                        default:
                            printf("\nInvalid input. Please try again.");
                            break;
                    }
                    printf("\n");

                }
                break;
            case 'p':
                user_input = 'x';
                while (user_input != 'q') {
                    printf("\nEnter operation code: ");
                    scanf(" %c", &user_input);

                    switch (user_input) {
                        case 'i':
                            insert_player(playerhead);
                            break;
                        case 's':
                            search_player(playerhead);
                            break;
                        case 'u':
                            update_player(playerhead);
                            break;
                        case 'p':
                            print_player(playerhead);
                            break;
                        case 'd':
                            *playerhead = delete_player(playerhead);
                        case 'q':
                            break;
                        default:
                            printf("\nInvalid input. Please try again.");
                            break;

                    }
                    printf("\n");
                }
                break;

            default:
                printf("\nInvalid input. Please try again.");
                break;
        }
    }
}
