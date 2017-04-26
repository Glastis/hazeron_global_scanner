//
// Created by Luciano on 20/04/2017.
//

#ifndef HAZERON_GLOBAL_SCANNER_UTILITIES_H
#define HAZERON_GLOBAL_SCANNER_UTILITIES_H

#include "retreivers/common/common.h"

e_bool              is_id_existing(t_player **user, char *id);
void                list_players(t_player **all_player);
char                *get_id_from_user_link(char *link);
e_bool              is_player_link(char *all);
void                add_id_to_list(t_player **user, char *id);
int                 find_string(const char *ref, const char *str);
e_bool              contain_string(const char *ref, const char *str);

#endif //HAZERON_GLOBAL_SCANNER_UTILITIES_H
