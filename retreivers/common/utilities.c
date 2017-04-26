//
// Created by Luciano on 20/04/2017.
//

#include <string.h>
#include <stdio.h>
#include "retreivers/common/utilities.h"

void                add_id_to_list(t_player **user, char *id)
{
    int             i;

    i = 0;
    while (user[i] && user[i]->id)
    {
        ++i;
    }
    if (user[i] && (user[i]->id = malloc((strlen(id) + 1) * sizeof(char))))
    {
        strcpy(user[i]->id, id);
    }
}

e_bool              is_id_existing(t_player **user, char *id)
{
    int             i;

    i = 0;
    while (user[i] && user[i]->id)
    {
        if (strlen(id) == strlen(user[i]->id) && !(strcmp(user[i]->id, id)))
        {
            return true;
        }
        ++i;
    }
    return false;
}

void                list_players(t_player **all_player)
{
    int         i;

    i = 0;
    while (all_player[i])
    {
        printf("player_link: %s\n", (all_player[i]->player_link) ? all_player[i]->player_link : "NONE");
        printf("image_link: %s\n", (all_player[i]->image_link) ? all_player[i]->image_link : "NONE");
        printf("name: %s\n", (all_player[i]->name) ? all_player[i]->name : "NONE");
        printf("empire: %s\n", (all_player[i]->empire) ? all_player[i]->empire : "NONE");
        printf("id: %s\n", (all_player[i]->id) ? all_player[i]->id : "NONE");
        printf("\n");
        ++i;
    }
}

char                *get_id_from_user_link(char *link)
{
    char            *id;
    unsigned int    id_len;
    unsigned int    id_beg;
    unsigned int    i;

    i = 0;
    if (link[0] != PLAYER_LINK_REFERENCE[0])
        return NULL;
    while (link[i] && i < sizeof(PLAYER_LINK_REFERENCE) - 1)
    {
        if (link[i] != PLAYER_LINK_REFERENCE[i])
        {
            return NULL;
        }
        ++i;
    }
    id_beg = i;
    while (link[i] && link[i] != '.')
        ++i;
    id_len = i - id_beg;
    if (link[i] && !strncmp(&link[i], PLAYER_ID_END, sizeof(PLAYER_ID_END) - 1))
    {
        if ((id = malloc((id_len + 1) * sizeof(char))))
        {
            i = 0;
            while (link[id_beg + i] != '.')
            {
                id[i] = link[id_beg + i];
                ++i;
            }
            id[i] = '\0';
            return (id);
        }
    }
    return NULL;
}

e_bool              is_player_link(char *all)
{
    unsigned int    i;

    i = 0;
    if (all[0] != PLAYER_LINK_REFERENCE[0])
        return false;
    while (all[i] && i < sizeof(PLAYER_LINK_REFERENCE) - 1)
    {
        if (all[i] != PLAYER_LINK_REFERENCE[i])
        {
            return false;
        }
        ++i;
    }
    while (all[i] && all[i] != '.')
        ++i;
    if (all[i] && !strncmp(&all[i], PLAYER_ID_END, sizeof(PLAYER_ID_END) - 1))
    {
        return true;
    }
    return false;
}

e_bool              contain_string(const char *ref, const char *str)
{
    int             i;
    size_t          ref_len;
    size_t          str_len;

    i = 0;
    ref_len = strlen(ref);
    str_len = strlen(str);
    while ((i + ref_len) < str_len)
    {
        if (!strncmp(ref, str, ref_len))
        {
            return (true);
        }
        ++i;
    }
    return (false);
}

int                 find_string(const char *ref, const char *str)
{
    int             i;
    size_t          ref_len;
    size_t          str_len;

    i = 0;
    ref_len = strlen(ref);
    str_len = strlen(str);
    while ((i + ref_len) < str_len)
    {
        if (!strncmp(ref, str, ref_len))
        {
            return (i);
        }
        ++i;
    }
    return (-1);
}