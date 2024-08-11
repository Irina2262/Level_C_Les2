/*
 ЗАДАЧА 1.
Проблематика: сейчас змейка “наезжает” на свой хвост.
Написать функцию, которая будет проверять корректность выбранного
направления. Змейка не может наступать на хвост, поэтому необходимо
запретить:
● перемещение справа-налево (при движении RIGHT нажатие стрелки
влево),
● перемещение сверху-вниз (при движении UP нажатие стрелки вниз),
● перемещение слева-направо (при движении LEFT нажатие стрелки
вправо),
● перемещение снизу-вверх (при движении DOWN нажатие стрелки
вверх).
Функция должна иметь вид:
int checkDirection(snake_t* snake, int32_t key).

 */

#include <stdint.h>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

typedef struct {
    int32_t direction; 
}   snake_t;
  
int checkDirection(snake_t* snake, int32_t key) 
{
    if ((snake->direction == RIGHT && key == LEFT) ||
    (snake->direction == LEFT && key == RIGHT) ||
    (snake->direction == UP && key == DOWN) ||
    (snake->direction == DOWN && key == UP)) 
    {
        return 0;
    }
        return 1; 
}
