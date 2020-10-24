#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Structures */
typedef struct Player{
    char* name;
    int total_points;
    int map1;
    int map2;
    int map3;
    int map4;
    int map5;
    int map6;
}Player;


/* Prototypes */
Player* create_player(char* name);
Player** create_players(char** name, int length);
void free_player(Player* player);
void shuffle(int *array, size_t n);
void print_array(int* array, int size);
int* create_rank_array();
int* create_points_array(int* ranks);
char** create_playerlist();
void print_players(char** names);
void simulate_map(Player** players, int* ranks, int map);
void play(Player** players, int* map1, int* map2, int* map3, int* map4, int* map5, int* map6);

/* Main */
int main() {
    srand(time(NULL));
    char** players_name = create_playerlist();
    Player** players = create_players(players_name, 16);
    int map1 = 0;
    int map2 = 0;
    int map3 = 0;
    int map4 = 0;
    int map5 = 0;
    int map6 = 0;
    int* p1 = &map1;
    int* p2 = &map2;
    int* p3 = &map3;
    int* p4 = &map4;
    int* p5 = &map5;
    int* p6 = &map6;
    int i = 0;
    while (i < 1000000){
        play(players, p1, p2, p3, p4, p5, p6);
        i++;
    }
    float mean1 = (100.0f * map1) / (map1 + map2 + map3 + map4 + map5 + map6);
    float mean2 = (100.0f * map2) / (map1 + map2 + map3 + map4 + map5 + map6);
    float mean3 = (100.0f * map3) / (map1 + map2 + map3 + map4 + map5 + map6);
    float mean4 = (100.0f * map4) / (map1 + map2 + map3 + map4 + map5 + map6);
    float mean5 = (100.0f * map5) / (map1 + map2 + map3 + map4 + map5 + map6);
    float mean6 = (100.0f * map6) / (map1 + map2 + map3 + map4 + map5 + map6);
    printf("\nMap 1 contribution:%f\nMap 2 contribution:%f\nMap 3 contribution:%f\nMap 4 contribution:%f\nMap 5 contribution:%f\nMap 6 contribution:%f\n", mean1, mean2, mean3, mean4, mean5, mean6);
    return 0;
}

/* Functions */
Player* create_player(char* name){
    Player* player = malloc(sizeof(Player));
    player->name = name;
    player->total_points = 0;
    player->map1 = 0;
    player->map2 = 0;
    player->map3 = 0;
    player->map4 = 0;
    player->map5 = 0;
    player->map6 = 0;
    return player;
}

char** create_playerlist(){
    char** names = malloc(16*sizeof(char*));
    names[0] = "Affi";
    names[1] = "Aurel";
    names[2] = "Bren";
    names[3] = "Carljr";
    names[4] = "Gwen";
    names[5] = "evoN";
    names[6] = "Kappa";
    names[7] = "Massa";
    names[8] = "matt";
    names[9] = "Pac";
    names[10] = "Papou";
    names[11] = "riolu";
    names[12] = "Scrapie";
    names[13] = "Spam";
    names[14] = "tween";
    names[15] = "Yannex";
    return names;
}

void print_players(char** names){
    int i = 0;
    while (i < 16){
        printf("%s ", names[i]);
        i++;
    }
}

Player** create_players(char** names, int length){
    int i = 0;
    Player** players = malloc(length * sizeof(Player*));
    while (i < length){
        players[i] = create_player(names[i]);
        i++;
    }
    return players;
}

void free_player(Player* player){
    free(player);
}

void shuffle(int *array, size_t n){
    if (n > 1){
        size_t i;
        for (i = 0; i < n - 1; i++){
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void print_array(int* array, int size){
    int i = 0;
    printf("\n");
    while (i < size){
        printf("%d ", array[i]);
        i++;
    }
}

int* create_rank_array(){
    int i = 0;
    int* ranks = malloc(16*sizeof(int));
    while (i < 16){
        ranks[i] = i + 1;
        i++;
    }
    return ranks;
}

int* create_points_array(int* ranks){
    int* points = malloc((16*sizeof(int)));
    int i = 0;
    while (i < 16){
        switch (ranks[i]) {
            case 1:
                points[i] = 20;
                break;
            case 2:
                points[i] = 14;
                break;
            case 3:
                points[i] = 12;
                break;
            case 4:
                points[i] = 10;
                break;
            case 5:
                points[i] = 9;
                break;
            case 6:
                points[i] = 8;
                break;
            case 7:
                points[i] = 7;
                break;
            case 8:
                points[i] = 6;
                break;
            case 9:
            case 10:
                points[i] = 5;
                break;
            case 11:
            case 12:
                points[i] = 4;
                break;
            case 13:
            case 14:
                points[i] = 3;
                break;
            case 15:
                points[i] = 2;
                break;
            case 16:
                points[i] = 1;
        }
        i++;
    }
    return points;
}

void simulate_map(Player** players, int* ranks, int map){
    int* points = create_points_array(ranks);
    int i = 0;
    while (i < 16){
        if (map == 1){
            players[i]->map1 = points[i];
        }
        else if (map == 2){
            players[i]->map2 = points[i];
        }
        else if (map == 3){
            if (ranks[i] <= 8){
                players[i]->map3 = points[i];
            }
            else {
                players[i]->map1 *= 1;
                players[i]->map2 *= 1;
                players[i]->map3 = points[i];
            }
        }
        else if (map == 4){
            if (ranks[i] <= 8) {
                players[i]->map4 += points[i];
            }
            else {
                players[i]->map1 *= 0;
                players[i]->map2 *= 0;
                players[i]->map3 *= 0;
                players[i]->map4 = points[i];
            }
        }
        else if (map == 5){
            if (ranks[i] <= 8){
                players[i]->map5 += points[i];
            }
            else {
                players[i]->map1 *= 0;
                players[i]->map2 *= 0;
                players[i]->map3 *= 0;
                players[i]->map4 *= 0;
                players[i]->map5 = points[i];
            }
        }
        else {
            if (ranks[i] <= 8){
                players[i]->map6 = points[i];
            }
            else {
                players[i]->map1 *= 0;
                players[i]->map2 *= 0;
                players[i]->map3 *= 0;
                players[i]->map4 *= 0;
                players[i]->map5 *= 0;
                players[i]->map6 = points[i];
            }
        }
        i++;
    }
    free(points);
}

void play(Player** players, int* map1, int* map2, int* map3, int* map4, int* map5, int* map6){
    int i = 0;
    int* ranks = create_rank_array();
    while (i < 6){
        shuffle(ranks, 16);
        simulate_map(players, ranks, i + 1);
        i++;
    }

    i = 0;
    while (i < 16) {
        players[i]->total_points = players[i]->map1 + players[i]->map2 + players[i]->map3 + players[i]->map4 + players[i]->map5 + players[i]->map6;
        i++;
    }
    i = 0;
    while (i < 16){
        *map1 += players[i]->map1;
        *map2 += players[i]->map2;
        *map3 += players[i]->map3;
        *map4 += players[i]->map4;
        *map5 += players[i]->map5;
        *map6 += players[i]->map6;
        i++;
    }
    free(ranks);
}