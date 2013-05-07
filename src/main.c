/* 
 * File:   main.c
 * Author: Filip Sergot
 *
 * Created on March 4, 2013, 11:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <math.h>

#include "game.h"
#include "point.h"
#include "config.h"
#include "shooter.h"
#include "asteroid.h"

int main(int argc, char** argv) {
    srand(time(NULL));
    
    // INITIALIZE LISTS {
    first_s = NULL;
    last_s = NULL;
    
    first_a = NULL;
    first_a = NULL;
    // }
    
    read_config();

    int DISPLAY_WIDTH = get_config("display_width") != NULL ? atoi(get_config("display_width")) : 640;
    int DISPLAY_HEIGHT = get_config("display_height") != NULL ? atoi(get_config("display_height")) : 480;
        
    point *screen = calloc(1, sizeof(point));
    screen->x = DISPLAY_WIDTH;
    screen->y = DISPLAY_HEIGHT;
    
    int i, scored, lifed, statused;
    
    game *Game = new_game(screen);
    
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL, *timer_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_KEYBOARD_STATE *keys = calloc(1, sizeof(ALLEGRO_KEYBOARD_STATE));
    
    bool exit = false;
    
    if(!al_init()) {
        fprintf(stderr, "[!!] failed to initialize allegro!\n");
        return 1;
    }
    
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        fprintf(stderr, "[!!] failed to create timer!\n");
        return 1;
    }
    
    if(!al_init_primitives_addon()) {
        fprintf(stderr, "[!!] failed to initialize primitives addon!\n");
        return 1;
    }
    
    if(!al_install_keyboard()) {
        fprintf(stderr, "[!!] failed to install keyboard\n");
        return 1;
    }
    
    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    if(!display) {
        fprintf(stderr, "[!!] failed to create display!\n");
        return 1;
    }

    if (!font()){
        fprintf(stderr, "[!!] failed to initialize fonts.\n");
        return 1;
    }
    
    event_queue = al_create_event_queue();
    timer_queue = al_create_event_queue();
    if(!event_queue | !timer_queue) {
        fprintf(stderr, "[!!] failed to create event queue!\n");
        al_destroy_display(display);
        return 1;
    }
    
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    
    al_register_event_source(timer_queue, al_get_timer_event_source(timer));
    
    al_start_timer(timer);
    
    ALLEGRO_EVENT ev, timerev;
    while(Game->status != Quit) {
        al_get_keyboard_state(keys);
        
        al_wait_for_event(timer_queue, &timerev);
        if(Game->status == Play) {
            if(al_key_down(keys, ALLEGRO_KEY_RIGHT)) {
                turn_right(Game->Ship);
            }
            if(al_key_down(keys, ALLEGRO_KEY_LEFT)) {
                turn_left(Game->Ship);
            }
            if(al_key_down(keys, ALLEGRO_KEY_UP)) {
                move_object(Game->Ship->position, Game->Ship->angle, Game->Ship->speed);
            }            
        }
        
        al_get_next_event(event_queue, &ev);
            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch(ev.keyboard.keycode) {
                    case ALLEGRO_KEY_SPACE:
                        if(Game->status == Play) new_shoot(Game->Ship);
                        break;
                    case ALLEGRO_KEY_ENTER:
                        if(Game->status == Pause)
                            Game->status = Play;
                        else if(Game->status == Lose || Game->status == Win) {
                            scored = Game->score; lifed = Game->Ship->life; statused = Game->status;
                            del_game(Game);
                            Game = new_game(screen);
                            Game->Ship = new_ship(p_times(screen, 0.5));
                            if(statused == Win) {
                                Game->score = scored;
                                Game->Ship->life = lifed;
                            }
                            Game->status = Play;
                        }
                            
                        break;
                    case ALLEGRO_KEY_ESCAPE:
                        if(Game->status == Play || Game->status == Config) {
                            Game->status = Pause;
                        } else if (Game->status != Play) {
                            Game->status = Quit;
                        }
                        break;
                    case ALLEGRO_KEY_C:
                        if(Game->status == Pause || Game->status == Lose || Game->status == Win) {
                            Game->status = Config;
                        }
                        break;
                    case ALLEGRO_KEY_DOWN:
                        if(Game->status == Config)
                            inc_config_pos();
                        break;
                    case ALLEGRO_KEY_UP:
                        if(Game->status == Config)
                            inc_config_pos();
                        break;
                    case ALLEGRO_KEY_LEFT:
                        if(Game->status == Config) {
                            add_to_config(0);
                        }
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        if(Game->status == Config) {
                            add_to_config(1);
                        }
                        break;
                }
            }
        
        if(Game->status == Play) update_game(Game);
        draw_game(Game);
        
        al_flip_display();
        
    }
    
    save_config();
    del_config();
    del_game(Game);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_event_queue(timer_queue);
    free(keys);
    free(screen);

    return (EXIT_SUCCESS);
}
