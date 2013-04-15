/* 
 * File:   config.h
 * Author: Filip Sergot
 *
 * Created on March 6, 2013, 12:39 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#include <allegro5/allegro.h>

#define FPS 60

#define BACKGROUND_COLOR al_map_rgb(0, 0, 0)

#define SHIP_COLOR al_map_rgb(250, 210, 0)

#define SHOOT_TTL 5
#define SHOOT_SPEED 5
#define SHOOT_TTL_STEP 0.1
#define SHOOT_COLOR al_map_rgb(255, 255, 255)

#define ASTEROID_SPEED 2
#define ASTEROID_MAX_LVL 3
#define ASTEROID_COUNT 2
#define ASTEROID_COLOR al_map_rgb(0,0,255)

typedef struct config {
    char *key, *value;
    struct config *next;
} config;

void push(char *, char *);
config *pop();
char *get_config(char *);
void change_config(char *, int);

void save_config();
void read_config();

#endif	/* CONFIG_H */

