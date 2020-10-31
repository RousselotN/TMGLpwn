#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


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
void play(Player** players, double* map1, double* map2, double* map3, double* map4, double* map5, double* map6);
double min(int a, int b, int c, int d, int e, int f);
double max(int a, int b, int c, int d, int e, int f);

/* Main */
int main() {
    srand(time(NULL));
    char** players_name = create_playerlist();
    Player** players = create_players(players_name, 16);
    double map1 = 0;
    double map2 = 0;
    double map3 = 0;
    double map4 = 0;
    double map5 = 0;
    double map6 = 0;
    double* p1 = &map1;
    double* p2 = &map2;
    double* p3 = &map3;
    double* p4 = &map4;
    double* p5 = &map5;
    double* p6 = &map6;
    int* steps = malloc(6*sizeof(int));
    int i = 0;
    int balanced1 = 0;
    int unbalanced1 = 0;
    int balanced5 = 0;
    int unbalanced5 = 0;
    int balanced10 = 0;
    int unbalanced10 = 0;
    int balanced15 = 0;
    int unbalanced15 = 0;
    int balanced25 = 0;
    int unbalanced25 = 0;
    int balanced50 = 0;
    int unbalanced50 = 0;
    double balanceratio = 0;
    int j = 0;
    while (j < 10000) {
        while (i < 6) {
            play(players, p1, p2, p3, p4, p5, p6);
            steps[i] = map1 + map2 + map3 + map4 + map5 + map6;
            map1 = 0;
            map2 = 0;
            map3 = 0;
            map4 = 0;
            map5 = 0;
            map6 = 0;

            i++;
        }
        balanceratio += 1-(min(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]) / max(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]));
        /*if (1-(min(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]) /
            max(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5])) > 0.01) {
            unbalanced1++;
        } else {
            balanced1++;
        }
        if (1-(min(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]) /
               max(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5])) > 0.05) {
            unbalanced5++;
        } else {
            balanced5++;
        }
        if (1-(min(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]) /
               max(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5])) > 0.1) {
            unbalanced10++;
        } else {
            balanced10++;
        }
        if (1-(min(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]) /
               max(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5])) > 0.15) {
            unbalanced15++;
        } else {
            balanced15++;
        }
        if (1-(min(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]) /
               max(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5])) > 0.25) {
            unbalanced25++;
        } else {
            balanced25++;
        }
        if (1-(min(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]) /
               max(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5])) > 0.5) {
            unbalanced50++;
        } else {
            balanced50++;
        }
        //double test = min(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]) / max(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]);
        //printf("\n%lf\n%lf\n%lf\n", test, min(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]), max(steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]));
        */
        i = 0;
        j++;
    }
    /*double ratio1 = 100*balanced1/(balanced1+unbalanced1);
    double ratio5 = 100*balanced1/(balanced5+unbalanced5);
    double ratio10 = 100*balanced1/(balanced10+unbalanced10);
    double ratio15 = 100*balanced1/(balanced15+unbalanced15);
    double ratio25 = 100*balanced1/(balanced25+unbalanced25);
    double ratio50 = 100*balanced1/(balanced50+unbalanced50);
    printf("\n1%% Tolerance\n====\nBalanced: %d\nUnbalanced: %d\nRatio Balanced/Total: %lf%%\n", balanced1, unbalanced1, ratio1);
    printf("\n5%% Tolerance\n====\nBalanced: %d\nUnbalanced: %d\nRatio Balanced/Total: %lf%%\n", balanced5, unbalanced5, ratio5);
    printf("\n10%% Tolerance\n====\nBalanced: %d\nUnbalanced: %d\nRatio Balanced/Total: %lf%%\n", balanced10, unbalanced10, ratio10);
    printf("\n15%% Tolerance\n====\nBalanced: %d\nUnbalanced: %d\nRatio Balanced/Total: %lf%%\n", balanced15, unbalanced15, ratio15);
    printf("\n25%% Tolerance\n====\nBalanced: %d\nUnbalanced: %d\nRatio Balanced/Total: %lf%%\n", balanced25, unbalanced25, ratio25);
    printf("\n50%% Tolerance\n====\nBalanced: %d\nUnbalanced: %d\nRatio Balanced/Total: %lf%%\n", balanced50, unbalanced50, ratio50);*/
    balanceratio = balanceratio / 10000;
    printf("%lf", balanceratio);


    /*double mean1 = (100.0f * map1) / (map1 + map2 + map3 + map4 + map5 + map6);
    double mean2 = (100.0f * map2) / (map1 + map2 + map3 + map4 + map5 + map6);
    double mean3 = (100.0f * map3) / (map1 + map2 + map3 + map4 + map5 + map6);
    double mean4 = (100.0f * map4) / (map1 + map2 + map3 + map4 + map5 + map6);
    double mean5 = (100.0f * map5) / (map1 + map2 + map3 + map4 + map5 + map6);
    double mean6 = (100.0f * map6) / (map1 + map2 + map3 + map4 + map5 + map6);
    printf("\nMap 1 contribution:%lf\nMap 2 contribution:%lf\nMap 3 contribution:%lf\nMap 4 contribution:%lf\nMap 5 contribution:%lf\nMap 6 contribution:%lf\n", mean1, mean2, mean3, mean4, mean5, mean6);
*/
  //  printf("\nStep1: %lf\nStep2: %lf\nStep3: %lf\nStep4: %lf\nStep5: %lf\nStep6: %lf\n", steps[0], steps[1], steps[2], steps[3], steps[4], steps[5]);
    free(steps);
    return 0;
}

double max(int a, int b, int c, int d, int e, int f){
    int max = a;
    if (max < b){
        max = b;
    }
    if (max < c){
        max = c;
    }
    if (max < d){
        max = d;
    }
    if (max < e){
        max = e;
    }
    if (max < f){
        max = f;
    }
    return max;
}

double min(int a, int b, int c, int d, int e, int f){
    int min = a;
    if (min > b){
        min = b;
    }
    if (min > c){
        min = c;
    }
    if (min > d){
        min = d;
    }
    if (min > e){
        min = e;
    }
    if (min > f){
        min = f;
    }
    return min;
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
    free(player->name);
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

double factor(int i){
    if (i == 9){
        return 0.9;
    }
    if (i == 10){
        return 0.8;
    }
    if (i == 11){
        return 0.7;
    }
    if (i == 12){
        return 0.6;
    }
    if (i == 13){
        return 0.5;
    }
    if (i == 14){
        return 0.4;
    }
    if (i == 15){
        return 0.2;
    }
    if (i == 16){
        return 0;
    }
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
                players[i]->map4 = points[i];
            }
            else {
                players[i]->map1 *= factor(ranks[i]);
                players[i]->map2 *= factor(ranks[i]);
                players[i]->map3 *= factor(ranks[i]);
                players[i]->map4 = points[i];
            }
        }
        else if (map == 5){
            if (ranks[i] <= 8){
                players[i]->map5 = points[i];
            }
            else {
                players[i]->map1 *= factor(ranks[i]);
                players[i]->map2 *= factor(ranks[i]);
                players[i]->map3 *= factor(ranks[i]);
                players[i]->map4 *= factor(ranks[i]);
                players[i]->map5 = points[i];
            }
        }
        else {
            if (ranks[i] <= 8){
                players[i]->map6 = points[i];
            }
            else {
                players[i]->map1 *= factor(ranks[i]);
                players[i]->map2 *= factor(ranks[i]);
                players[i]->map3 *= factor(ranks[i]);
                players[i]->map4 *= factor(ranks[i]);
                players[i]->map5 *= factor(ranks[i]);
                players[i]->map6 = points[i];
            }
        }
        i++;
    }
    free(points);
}

void play(Player** players, double* map1, double* map2, double* map3, double* map4, double* map5, double* map6){
    //FILE* ftotal = fopen("totalpoints.txt", "a");
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
        //int total = players[i]->map1 + players[i]->map2 + players[i]->map3 + players[i]->map4 + players[i]->map5 + players[i]->map6;
        //fprintf(ftotal, "%d\n", total);
        i++;
    }
    //fclose(ftotal);
    free(ranks);
}
