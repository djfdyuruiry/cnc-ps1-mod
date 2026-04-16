# Command & Conquer (PS1) Startup Flow

This document outlines the observed startup sequence of the PlayStation version of Command & Conquer, as seen in an emulator, and details the corresponding code logic discovered through reverse engineering.

## 1. Playstation Boots
The console initializes its hardware and prepares to load the game executable from the disc.

## 2. Game Code Starts
The `main` function is executed. This involves:
- Initializing hardware (Graphics, Controller, Sound/SPU).
- Detecting the disc language (GDI, NOD, etc.) by searching for specific file offsets.
- Initializing the engine via `FUN_8006bb58`.

## 3. Loading Animation
An animation counts through the bytes (e.g., 0-2000kb) as data is prepared for the game.

## 4. Intro Movies
The game plays two introductory movies. Based on code analysis, this sequence is orchestrated as follows:

### Implementation Details
The intro sequence is managed through a tiered dispatch system:

1.  **Orchestration (`FUN_8006bf70`)**: A high-level function determines which sequence to play. If a specific mode is requested, it sequences through the "WWLOGO" animation and then proceeds to the `s_INTRO2` sequence.
2.  **Asset Dispatching (`FUN_8006d540`)**: This function takes asset identifiers (like `s_WWLOGO` or `s_INTRO2`) and resolves them into full playback parameters. It performs string comparisons to set specific durations and flags (e.g., handling GDI vs NOD final assets).
3.  **Media Playback Loop (`FUN_800896fc`)**: The heavy-lifting function that manages the hardware-level playback. It:
    *   Configures the PlayStation's Display and Drawing environments (`SetDefDispEnv`, `SetDefDrawEnv`).
    *   Runs a synchronized loop using `VSync` to ensure smooth playback.
    *   Interacts with the CD-ROM drive via `CdControlB` to stream the video/audio data.
    *   Updates the screen and handles various playback states/modes.

## 5. Main Menu Animation
The game enters the main menu, featuring an animation accompanied by a voice-over stating the disc name (GDI or NOD).

## 6. 'Press Start' Menu
A prompt is presented to the player to continue.

## 7. Main Menu
The final menu provides four primary options, which lead to the launch of various game scenarios.
