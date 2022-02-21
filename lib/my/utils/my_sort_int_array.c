/*
** EPITECH PROJECT, 2021
** my str in array
** File description:
** task06 day4: sorts an integer array in ascending order
*/

#include <stdlib.h>

////////////////////////////////////////////////////////////
//
// basic sortinf for an int array
//
// @param array the array to sort
// @param size the array size
////////////////////////////////////////////////////////////
void my_sort_int_array(int *array, int size)
{
    if (array == NULL)
        return 84;
    for (int list_index = 1; list_index <= size; ++list_index) {
        int temp_to_check = array[list_index];
        int index = list_index - 1;
        while (index >= 0 && array[index] > temp_to_check) {
            array[index + 1] = array[index];
            --index;
        }
        array[index + 1] = temp_to_check;
    }
    return 0;
}
