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
    Quit, Pause, Win, Lose, Play, Config
} status;

typedef struct game {
    int score;
    ship Ship;
    vector Size;
    status status; // status of a game (Play, Pause, Win ...)
} game;

game* new_game(vector); // creates a new game | param: vector - size of a screen | return address to a game
void del_game(game *); // deletes a game | params: pointer to a game
bool font(); // run allegro font and ttf addons | returns: true if ran font and ttf correctly, false else

void update_game(game *); // updates all the game (bullets, asteroids) | params: address to a game
void update_collisions(game *); // checks if there is an collision somewhere | params: address to a game
void update_ship(game *, asteroid *); // updates ship's information | params: address to a game, address to an asteroid to start looking for collision with

// drawing functions
void draw_game(game *);
void draw_ship(game *);
void draw_asteroids(game *);
void draw_shoots(game *);
void draw_menu(game *);
void draw_ui(game *);
void draw_config(game *);

void bound_position(vector *); // limits positions to those given while creating a new game
void move_object(vector *, float, int); // moves a object (asteroid, ship, bullet) | params: address to position, float direction, int speed

int count_digits(int); // count how many digits there is in an integer | params: int number | returns: count of digits in number

void inc_config_pos();
void add_to_config(int);

#endif	/* GAME_H */

