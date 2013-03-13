/* 
 * File:   game.h
 * Author: Filip Sergot
 *
 * Created on March 5, 2013, 4:38 PM
 */

#ifndef GAME_H
#define	GAME_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <stdbool.h>

#include "ship.h"
#include "shooter.h"
#include "vector.h"
#include "asteroid.h"

typedef enum {
    Quit, Pause, Win, Lose, Play
} status;

typedef struct game {
    int score;
    ship Ship;
    vector Size;
    status status; // status of a game (Play, Pause, Win ...)
} game;

ALLEGRO_FONT *ttf_font; // font to use

game* new_game(vector);
void del_game(game *);
bool font();

void update_game(game *);
void update_collisions(game *);
void update_ship(game *, asteroid *);

void draw_game(game *);
void draw_ship(game *);
void draw_asteroids(game *);
void draw_shoots(game *);
void draw_menu(game *);
void draw_ui(game *);

void bound_position(vector *);
void move_object(vector *, float, int);

int count_digits(int); // count how many digits there is in an integer | params: int number | returns: count of digits in number
#endif	/* GAME_H */

