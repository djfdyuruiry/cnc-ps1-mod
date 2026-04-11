#include <cnc-types.h>
#include <symbols.h>
#include <syscalls.h>
#include <types.h>

static void EnsurePlayerCreditsIsAtLeast5K()
{
    // Reset credits to 5K if player has less than 5K
    ONCE_A_SECOND {
        static int previous_credits = -1;
        static bool credits_changing;

        credits_changing = _ui_credits != previous_credits;
        previous_credits = _ui_credits;

        if (!credits_changing && _ui_credits < 5000) {
            _player_credits = 5000;
        }
    }
}

void ModMain(void) {
    ONCE {
        _strcpy(&_passwords_patsux, "EEVEE");

        SetTypeEnumField(&_InfantryE1, TechnoTypeClass_Primary, WEAPON_FLAMETHROWER);
        SetTypeEnumField(&_UnitJeep, TechnoTypeClass_Primary, WEAPON_OBELISK_LASER);
    }

    //EnsurePlayerCreditsIsAtLeast5K();

    _ui_music_track = _music_track = 10;

    return;
}
