# Command & Conquer PS1 Mod

This repo contains a mod for the PlayStation 1 version of Command & Conquer (AKA Tiberian Dawn). It was built using the [C/C++ Game Modding Utility](https://github.com/C0mposer/C-Game-Modding-Utility) by [C0mposer](https://github.com/C0mposer).

This mod is a space for me to learn about PS1 modding and reverse engineering. 

What the mod can do so far:

- Game state tracking, with the ability to detect:
  - Main menu being shown (`GAME_STATE_MAIN_MENU`)
  - New scenario being loaded (`GAME_STATE_SCENARIO`)
  - Pause menu being shown (`GAME_STATE_PAUSE`)
- Access game flags for controller button presses (ex. do something when SELECT is pressed)
- Modify player credits
- Change properties for game types (Infantry, Units etc.)
  - Change a units weapon, change the cost of a building etc.

## Building

Do the following first:

- Download and unpack the latest release of the [C/C++ Game Modding Utility](https://github.com/C0mposer/C-Game-Modding-Utility)
- Obtain a bin/cue of the Command & Conquer GDI Disc (NTSC-U release) - save this to `Command & Conquer (USA) (Disc 1) (GDI).cue`
- Install bash and python for your system (Windows users can leverage WSL or Git Bash)
- If you are on Linux, install wine for your system (the mod tool is a Windows App)

To build:

- Open a terminal in this directory and run `scripts/generate-symbol-code.sh` (use Git Bash on Windows)
- Open the project in the [C/C++ Game Modding Utility](https://github.com/C0mposer/C-Game-Modding-Utility) (install PS1 tools if prompted)
- Click `Choose PS1 BIN` and select your `cue` file
- Extract game files when prompted
- Select the `Build Project` tab and click `Compile` 
- You can then click `Build ISO`
- Open the `build` directory
- The modded version of the game is `ModdedGame_DEFAULT.cue`

## Code Map

All symbols that have been reverse engineered from the code are stored in [gdi-code-map.yml](git-code-map.yml) as yaml config data. This means we are not managing symbols in two places when needing to make changes (`symbols/DEFAULT.txt` and `include/symbols.h`).

The `scripts/generate-symbol-code.py` script uses [Jinja](https://jinja.palletsprojects.com/en/stable/) templating to generate these two files.

## Ghidra

- A Ghidra project is included in this repo that was used to reverse engineer the PS1 game code.
- Labels have been added to identified variables
- Functions that have been successfully reversed engineered are labeled
- Various constructors and object instances that match what is seen in the PC source code have been identified (`UnitTypeClass`, `ObjectTypeClass` etc.)

Open `ghidra/cnc-psx.gpr` in Ghidra to get started.

> Note: You will need the `ghidra_psx_ldr` Ghidra extension - get it [here](https://github.com/lab313ru/ghidra_psx_ldr)
