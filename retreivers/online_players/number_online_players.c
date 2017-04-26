//
// Created by glastis on 09/04/17.
//

#include "retreivers/online_players/online_players.h"
#include <string.h>

int             get_number_online_players(char *raw_page)
{
    int         nb_players;
    int         i;
    int         page_len;
    int         ref_len;

    i = 0;
    page_len = strlen(raw_page);
    ref_len = sizeof(PLAYER_LINK_REFERENCE) - 1;
    nb_players = 0;
    while (i + ref_len < page_len)
    {
        if (!(strncmp(&raw_page[i], PLAYER_LINK_REFERENCE, ref_len)))
            ++nb_players;
        ++i;
    }
    if (nb_players % NUMBER_REF_LINK_BY_PLAYER)
    {
        return (EXIT_FAILURE);
    }
    return (nb_players / NUMBER_REF_LINK_BY_PLAYER);
}