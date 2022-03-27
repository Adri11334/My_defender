/*
** EPITECH PROJECT, 2022
** defender
** File description:
** audio_manager
*/

#include "my_defender.h"

sfMusic *create_audio(char *music_path, bool loop)
{
    sfMusic *audio = sfMusic_createFromFile(music_path);
    if (loop)
        sfMusic_setLoop(audio, sfTrue);
    return audio;
}

void destroy_audio(sfMusic *music)
{
    if (music) {
        sfMusic_stop(music);
        sfMusic_destroy(music);
    }
}
