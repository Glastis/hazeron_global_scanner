//
// Created by glastis on 09/04/17.
//

#include <stdio.h>
#include <string.h>
#include "retreivers/online_players/online_players.h"
#include "retreivers/common/utilities.h"

static t_player         **init_player_tab(int nb_players)
{
    t_player            **players;
    t_player            *tmp;
    int                 i;

    i = 0;
    if (!(players = malloc(sizeof(t_player *) * (nb_players + 1))))
        return NULL;
    while (i < nb_players)
    {
        if (!(tmp = malloc(sizeof(t_player))))
            return NULL;
        tmp->player_link = NULL;
        tmp->image_link = NULL;
        tmp->name = NULL;
        tmp->empire = NULL;
        tmp->id = NULL;
        players[i] = tmp;
        ++i;
    }
    players[i] = NULL;
    return players;
}

static void         get_id(t_player **user, char *all, size_t page_len)
{
    unsigned int    i;
    char            *tmp;

    i = 0;
    while (i < page_len - sizeof(PLAYER_LINK_REFERENCE) - sizeof(PLAYER_ID_END))
    {
        if (is_player_link(&all[i]))
        {
            tmp = get_id_from_user_link(&all[i]);
            if (tmp && is_id_existing(user, tmp) == false)
            {
                add_id_to_list(user, tmp);
            }
            else if (tmp)
            {
                free(tmp);
                tmp = NULL;
            }
        }
        ++i;
    }
}

static void         add_player_link(t_player **player)
{
    int             i;
    size_t          len;

    i = 0;
    while (player[i])
    {
        len = strlen(player[i]->id) + sizeof(PLAYER_LINK_REFERENCE) + sizeof(WEB_PAGE_EXTENTION) - 1;
        if (!(player[i]->player_link = malloc(len * sizeof(char))))
        {
            return;
        }
        memcpy(&player[i]->player_link[0], PLAYER_LINK_REFERENCE, sizeof(PLAYER_LINK_REFERENCE) - 1);
        memcpy(&player[i]->player_link[sizeof(PLAYER_LINK_REFERENCE) - 1], player[i]->id, strlen(player[i]->id));
        memcpy(&player[i]->player_link[len - sizeof(WEB_PAGE_EXTENTION)], WEB_PAGE_EXTENTION, sizeof(WEB_PAGE_EXTENTION) - 1);
        player[i]->player_link[len - 1] = '\0';
        ++i;
    }
}

t_player            **get_online_players_infos()
{
    t_player        **player;
    char            *onl_play_page;
    size_t          page_len;

    onl_play_page = get_page(ONLINE_PLAYERS_WEBPAGE)->ptr;
    if (!onl_play_page)
        return NULL;
    page_len = strlen(onl_play_page);
    if (get_number_online_players(onl_play_page) == EXIT_FAILURE ||
        !(player = init_player_tab(get_number_online_players(onl_play_page))))
        return NULL;
    get_id(player, onl_play_page, page_len);
    free(onl_play_page);
    add_player_link(player);
    return (player);
}

int		            main()
{
    printf("Online players: %d\n", get_number_online_players(get_page(ONLINE_PLAYERS_WEBPAGE)->ptr));
    printf("Crawling:\n");
    list_players(get_online_players_infos());
    return (0);
}
