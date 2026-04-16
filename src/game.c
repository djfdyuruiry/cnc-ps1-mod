#include <symbols.h>

/**
 * Game engine set's this flag every time the main menu is shown. It
 * is never turned off after that though, so it's a heuristic for if the
 * game has loaded completely. (intro fmvs played etc.)
 */
bool GameHasLoaded()
{
    return _reached_main_menu_flag == 1;
}

void PlayMusicTrack(const unsigned int track_number)
{
    _set_music_track(track_number);
    _start_music_track_playback();
}

bool PauseMenuIsActive()
{
    return _pause_menu_flag != 0;
}

void EnsurePauseMenuShown()
{
    if (PauseMenuIsActive())
    {
        return;
    }

    _pause_menu_flag = 1;
}

void SetPauseMenuMessage(const char* message)
{
    if (message != NULL)
    {
        _strcpy(&_pause_menu_message, message);
    }
}
