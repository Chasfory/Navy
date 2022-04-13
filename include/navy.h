/*
** EPITECH PROJECT, 2021
** navy.h
** File description:
** navy
*/

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include "struct_player.h"

//lib
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_get_nbr(char const *str);
int take(char const *str, int i);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int sign(char const *str, int i);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
void my_putchar(char c);

//waiting
void mess_2(player_t *game, char *y);
void mess_1(player_t *game, char *y);
void msg_hit_or_missed(int compt, player_t *game);
void print_mess(char *x, char *y);
void hit_or_missed(int compt_x, int compt_y, player_t *game);

//check_error_maps
int check_other_element(char *boat);
int check_post_boat(char *boat);
int check_boat_number(char *boat);
int check_boat_bis(char *boat);
int check_boat(char *boat);

//check_error
int check_error(char *sms);
int check_long_boat(char *boat);

//signal
char *tony(int i);
void signal_1(int tmp, siginfo_t *play, void *data);
void signal_2(int tmp, siginfo_t *play, void *data);
void hole(int tmp, siginfo_t *game, void *data);
void continu_game(player_t *game);

//maps
int init_struct_player(player_t *game, int ac, char **av);
char **draw_boat_first(char const *av, char **maps);
void display_maps(player_t *game);
char **draw_boat(maps_t *map, char **maps, int tmp);

//create_maps
char **maps_enemy();
char **maps(char *av);
char **map_create(char **maps);

//init
int init_game_player_two(player_t *game, char **av);
void init_struct_maps(maps_t *map);

//global
void init_game_player_one(player_t *game);
void msg_missed(int tmp, siginfo_t *play, void *data);
void glob(int tmp, siginfo_t *game, void *data);
void change_map(char *sms, player_t *game);
void connect(int tmp, siginfo_t *player, void *data);
void msg_hit(int tmp, siginfo_t *play, void *data);

//game
int won_compt(player_t *game);
int lose_compt(player_t *game);
int finish_game(player_t *game);
void lets_go(player_t *game);
void game_waiting(player_t *game);

//connect
void display_connect(player_t *game);
void connect_play_two(int tmp, siginfo_t *player, void *data);

//attack
void kill_sms(char *coord_tmp, player_t *game);
void coordination_of_the_attack(char *sms, player_t *game);
void play_attack(player_t *game, char *sms);
void game_attack_bis(char *sms, player_t *game);
void game_attack(player_t *game);