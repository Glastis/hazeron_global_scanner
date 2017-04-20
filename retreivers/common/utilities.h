//
// Created by Luciano on 20/04/2017.
//

#ifndef HAZERON_GLOBAL_SCANNER_UTILITIES_H
#define HAZERON_GLOBAL_SCANNER_UTILITIES_H

#include "common.h"

e_bool       is_id_existing(t_player **user, char *id);
void         list_players(t_player **all_player);
char         *get_id_from_user_link(char *link);
e_bool       is_player_link(char *all);
void         add_id_to_list(t_player **user, char *id);
#endif //HAZERON_GLOBAL_SCANNER_UTILITIES_H
