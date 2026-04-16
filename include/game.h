#ifndef GAME_H
#define GAME_H

#include <types.h>

bool GameHasLoaded();

void PlayMusicTrack(unsigned int track_number);

bool PauseMenuIsActive();

void EnsurePauseMenuShown();

void SetPauseMenuMessage(const char* message);

#endif //GAME_H
