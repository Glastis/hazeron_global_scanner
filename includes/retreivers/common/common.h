//
// Created by glastis on 09/04/17.
//

#ifndef HAZERON_GLOBAL_SCANNER_COMMON_H
#define HAZERON_GLOBAL_SCANNER_COMMON_H

#define UNUSED(X)                       (void)(X)

#define ONLINE_PLAYERS_WEBPAGE          "http://hazeron.com/playerson.html"
#define PLAYER_LINK_REFERENCE           "http://Hazeron.com/EmpireStandings2015/"
#define PLAYER_ID_END                   ".html\"><img"
#define WEB_PAGE_EXTENTION              ".html"
#define PLAYER_IMAGE_EXTENTION          ".png"
#define NUMBER_REF_LINK_BY_PLAYER       3
#define MAX_ID_LEN                      20

#include <stdlib.h>

typedef enum
{
            IMG_LINK,
            PLAYER_LINK,
            UNEXPECTED
}                           e_ret;

typedef enum
{
            false,
            true
}                           e_bool;

struct      s_string
{
    char    *ptr;
    size_t  len;
};

struct      s_player
{
    char    *player_link;
    char    *image_link;
    char    *name;
    char    *empire;
    char    *id;
};

typedef struct s_string     t_string;
typedef struct s_player     t_player;

t_string        *get_page(char *url);

#endif //HAZERON_GLOBAL_SCANNER_COMMON_H
