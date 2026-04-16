INPUT(symbols/DEFAULT.txt)
MEMORY
{
    /* RAM locations for injected code */
    debug_strings : ORIGIN = 0x8012C12C, LENGTH = 0xABA
    AutoHook_OnScenarioLoad_1 : ORIGIN = 0x8006CF2C, LENGTH = 0x100000
    AutoHook_OnMainMenuHandlerCall_2 : ORIGIN = 0x800716FC, LENGTH = 0x100000
    AutoHook_OnEveryFrame_3 : ORIGIN = 0x800A3878, LENGTH = 0x100000
}

SECTIONS
{
    /* Hook: AutoHook_OnScenarioLoad_1 */
    .AutoHook_OnScenarioLoad_1 :
    {
        .config/output/object_files/AutoHook_OnScenarioLoad_1.o(.text)
        .config/output/object_files/AutoHook_OnScenarioLoad_1.o(.rodata)
        .config/output/object_files/AutoHook_OnScenarioLoad_1.o(.rodata*)
        .config/output/object_files/AutoHook_OnScenarioLoad_1.o(.data)
        .config/output/object_files/AutoHook_OnScenarioLoad_1.o(.bss)
    } > AutoHook_OnScenarioLoad_1

    /* Hook: AutoHook_OnMainMenuHandlerCall_2 */
    .AutoHook_OnMainMenuHandlerCall_2 :
    {
        .config/output/object_files/AutoHook_OnMainMenuHandlerCall_2.o(.text)
        .config/output/object_files/AutoHook_OnMainMenuHandlerCall_2.o(.rodata)
        .config/output/object_files/AutoHook_OnMainMenuHandlerCall_2.o(.rodata*)
        .config/output/object_files/AutoHook_OnMainMenuHandlerCall_2.o(.data)
        .config/output/object_files/AutoHook_OnMainMenuHandlerCall_2.o(.bss)
    } > AutoHook_OnMainMenuHandlerCall_2

    /* Hook: AutoHook_OnEveryFrame_3 */
    .AutoHook_OnEveryFrame_3 :
    {
        .config/output/object_files/AutoHook_OnEveryFrame_3.o(.text)
        .config/output/object_files/AutoHook_OnEveryFrame_3.o(.rodata)
        .config/output/object_files/AutoHook_OnEveryFrame_3.o(.rodata*)
        .config/output/object_files/AutoHook_OnEveryFrame_3.o(.data)
        .config/output/object_files/AutoHook_OnEveryFrame_3.o(.bss)
    } > AutoHook_OnEveryFrame_3

    /* Codecave: debug_strings */
    .debug_strings :
    {
        .config/output/object_files/main.o(.text)
        .config/output/object_files/main.o(.rodata)
        .config/output/object_files/main.o(.rodata*)
        .config/output/object_files/main.o(.data)
        .config/output/object_files/main.o(.bss)
        .config/output/object_files/main.o(.sdata)
        .config/output/object_files/main.o(.sbss)
        .config/output/object_files/main.o(.scommon)
        .config/output/object_files/cnc_types.o(.text)
        .config/output/object_files/cnc_types.o(.rodata)
        .config/output/object_files/cnc_types.o(.rodata*)
        .config/output/object_files/cnc_types.o(.data)
        .config/output/object_files/cnc_types.o(.bss)
        .config/output/object_files/cnc_types.o(.sdata)
        .config/output/object_files/cnc_types.o(.sbss)
        .config/output/object_files/cnc_types.o(.scommon)
        .config/output/object_files/game.o(.text)
        .config/output/object_files/game.o(.rodata)
        .config/output/object_files/game.o(.rodata*)
        .config/output/object_files/game.o(.data)
        .config/output/object_files/game.o(.bss)
        .config/output/object_files/game.o(.sdata)
        .config/output/object_files/game.o(.sbss)
        .config/output/object_files/game.o(.scommon)
        .config/output/object_files/player.o(.text)
        .config/output/object_files/player.o(.rodata)
        .config/output/object_files/player.o(.rodata*)
        .config/output/object_files/player.o(.data)
        .config/output/object_files/player.o(.bss)
        .config/output/object_files/player.o(.sdata)
        .config/output/object_files/player.o(.sbss)
        .config/output/object_files/player.o(.scommon)
        .config/output/object_files/syscalls.o(.text)
        .config/output/object_files/syscalls.o(.rodata)
        .config/output/object_files/syscalls.o(.rodata*)
        .config/output/object_files/syscalls.o(.data)
        .config/output/object_files/syscalls.o(.bss)
        .config/output/object_files/syscalls.o(.sdata)
        .config/output/object_files/syscalls.o(.sbss)
        .config/output/object_files/syscalls.o(.scommon)
        *(.text)
        *(.branch_lt)
    } > debug_strings

    /DISCARD/ :
    {
        *(.comment)
        *(.pdr)
        *(.mdebug)
        *(.reginfo)
        *(.MIPS.abiflags)
        *(.eh_frame)
        *(.gnu.attributes)
    }
}
