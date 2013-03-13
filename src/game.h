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
    status status;
} game;

ALLEGRO_FONT *ttf_font;

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
void draw_win(game *);
void draw_lose(game *);
void draw_ui(game *);

void bound_position(vector *);
void move_object(vector *, float, int);

int count_digits(int);
#endif	/* GAME_H */

