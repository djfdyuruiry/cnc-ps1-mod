#include <symbols.h>

void ModifyPlayerCredits(const int credits)
{
    if (credits == 0)
    {
        return;
    }

    int modifier = credits;

    if (credits < 0)
    {
        modifier = -credits;
    }

    _player_credits += modifier;
}

void SetPlayerCredits(const uint credits)
{
    _player_credits += (int)credits;
}

/**
 * Example of how to wait for UI credits to update before making a credits modification (feels more natural)
 */
/*void EnsurePlayerCreditsIsAtLeast5K()
{
    // Reset credits to 5K if player has less than 5K
    ONCE_A_SECOND
    {
        static int previous_credits = -1;
        static bool credits_changing;

        credits_changing = _ui_credits != previous_credits;
        previous_credits = _ui_credits;

        if (!credits_changing && _ui_credits < 5000) {
            SetPlayerCredits(5000);
        }
    }
}*/