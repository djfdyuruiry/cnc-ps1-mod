#ifndef PLAYER_H
#define PLAYER_H

void ModifyPlayerCredits(int credits);

void SetPlayerCredits(unsigned int credits);

/**
 * Example of how to wait for UI credits to update before making a credits modification (feels more natural)
 */
void EnsurePlayerCreditsIsAtLeast5K();

#endif //PLAYER_H
