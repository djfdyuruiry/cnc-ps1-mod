#include <cnc_types.h>
#include <mod.h>
#include <game.h>
#include <player.h>
#include <ps1.h>
#include <symbols.h>
#include <types.h>

static enum CncState PREVIOUS_GAME_STATE = GAME_STATE_UNKNOWN;
static enum CncState GAME_STATE = GAME_STATE_UNKNOWN;

static void HandleGameState(const enum CncState game_state)
{
    switch (game_state)
    {
        case GAME_STATE_FMV:
            {
                // BUG: detection code missing
                break;
            }

        case GAME_STATE_MAIN_MENU:
            {
                break;
            }

        case GAME_STATE_SCENARIO:
            {
                // pause menu function hooking is buggy, so we do detection here instead
                if (PauseMenuIsActive())
                {
                    PREVIOUS_GAME_STATE = game_state;
                    GAME_STATE = GAME_STATE_PAUSE;
                    break;
                }

                if (_buttons_released == SELECT_BUTTON)
                {
                    ModifyPlayerCredits(2500);
                    PlayMusicTrack(MUSIC_TRACK_I_AM);
                }

                break;
            }

        case GAME_STATE_PAUSE:
            {
                break;
            }

        default: break;
    }
}

static void OneTimeSetup()
{
    ONCE
    {
        _covert_ops_flag = 1; // enable covert ops menu by default
        _strcpy(&_passwords_patsux, "EEVEE"); // change secret mission password
    }
}

static void OnGameStateChange(const enum CncState new_state)
{
    switch (new_state)
    {
        case GAME_STATE_FMV:
            {
                // BUG: detection code missing
                break;
            }

        case GAME_STATE_MAIN_MENU:
            {
                OneTimeSetup();
                break;
            }

        case GAME_STATE_SCENARIO:
            {
                // reset any changed rules
                SetTypeEnumField(&_InfantryE1, TechnoTypeClass_Primary, WEAPON_M16);
                SetTypeEnumField(&_InfantryCommando, TechnoTypeClass_Primary, WEAPON_RIFLE);

                // apply scenario specific rules
                if (_scenario_number == 22)
                {
                    SetTypeEnumField(&_InfantryE1, TechnoTypeClass_Primary, WEAPON_FLAMETHROWER);
                }
                else if (_scenario_number == 60)
                {
                    SetTypeEnumField(&_InfantryCommando, TechnoTypeClass_Primary, WEAPON_OBELISK_LASER);
                }

                break;
            }

        case GAME_STATE_PAUSE:
            {
                SetPauseMenuMessage(&_scenario_name);
                break;
            }

        default: break;
    }
}

J_HOOK(0x8006CF2C) // ??? (No-op function called during scenario INI/CEL load)
void OnScenarioLoad(void)
{
    if (_scenario_number > 0)
    {
        PREVIOUS_GAME_STATE = GAME_STATE;
        GAME_STATE = GAME_STATE_SCENARIO;
    }
}

J_HOOK(0x800716FC) // ??? (Main_Menu_Handler sub-function)
void OnMainMenuHandlerCall(void)
{
    if (GameHasLoaded())
    {
        PREVIOUS_GAME_STATE = GAME_STATE;
        GAME_STATE = GAME_STATE_MAIN_MENU;
    }
}

/**
 * If game engine detects a fatal error, it sets the whole screen to a solid colour for debugging:
 *
 *   - Red screen = FUN_8009da24 call failed in FUN_80010018
 *   - Green screen = PTR_DAT_8012fbc8 validation failed in FUN_8008e1ac
 *   - Blue screen = failed to load mix file data into memory
 *
 */
J_HOOK(0x800A3878) // DrawOTag
void OnEveryFrame(void)
{
    if (PREVIOUS_GAME_STATE != GAME_STATE)
    {
        OnGameStateChange(GAME_STATE);
    }
    else
    {
        HandleGameState(GAME_STATE);
    }
}
