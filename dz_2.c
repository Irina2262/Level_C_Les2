/*
 ЗАДАЧА 2
Управление WASD
Добавить возможность управления змейкой клавишами WSAD (вне
зависимости от раскладки и регистра).
Зависимости от регистра в соответствии с таблицей.
W, w Вверх
S, s Вниз
A, a Влево
D, d Вправо
Для решения предлагается сделать массив кодов управления struct
control_buttons default_controls[CONTROLS]. CONTROLS – определяем
количество элементов массива.
В необходимых функциях в цикле необходимо сравнивать с каждым типом
управления в цикле: for (int i = 0; i < CONTROLS; i++)
 */

#include <stdio.h>
#include <stdint.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define CONTROLS 8

typedef struct {
    char key;
    int32_t direction;
} control_buttons;

control_buttons default_controls[CONTROLS] = {
    {'W', UP}, {'w', UP},
    {'S', DOWN}, {'s', DOWN},
    {'A', LEFT}, {'a', LEFT},
    {'D', RIGHT}, {'d', RIGHT}
};

int32_t getDirectionFromKey(char key) {
    for (int i = 0; i < CONTROLS; i++) {
        if (default_controls[i].key == key) {
            return default_controls[i].direction;
        }
    }
    return -1; 
}

int main() {
    char inputKey;
    printf("Введите клавишу управления (WASD): ");
    scanf(" %c", &inputKey);

    int32_t direction = getDirectionFromKey(inputKey);

    if (direction != -1) {
        switch (direction) {
            case UP: printf("Направление: Вверх\n"); break;
            case DOWN: printf("Направление: Вниз\n"); break;
            case LEFT: printf("Направление: Влево\n"); break;
            case RIGHT: printf("Направление: Вправо\n"); break;
        }
    } else {
        printf("Неверная клавиша!\n");
    }

    return 0;
}
