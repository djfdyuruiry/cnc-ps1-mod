INPUT(symbols/DEFAULT.txt)
MEMORY
{
    /* RAM locations for injected code */
    debug_strings : ORIGIN = 0x8012DB38, LENGTH = 0x6BC
    main : ORIGIN = 0x800A3878, LENGTH = 0x100000
}

SECTIONS
{
    /* Hook: main */
    .main :
    {
        .config/output/object_files/AutoHook_Main.o(.text)
        .config/output/object_files/AutoHook_Main.o(.rodata)
        .config/output/object_files/AutoHook_Main.o(.rodata*)
        .config/output/object_files/AutoHook_Main.o(.data)
        .config/output/object_files/AutoHook_Main.o(.bss)
    } > main

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
        .config/output/object_files/syscalls.o(.text)
        .config/output/object_files/syscalls.o(.rodata)
        .config/output/object_files/syscalls.o(.rodata*)
        .config/output/object_files/syscalls.o(.data)
        .config/output/object_files/syscalls.o(.bss)
        .config/output/object_files/syscalls.o(.sdata)
        .config/output/object_files/syscalls.o(.sbss)
        .config/output/object_files/syscalls.o(.scommon)
        .config/output/object_files/cnc-types.o(.text)
        .config/output/object_files/cnc-types.o(.rodata)
        .config/output/object_files/cnc-types.o(.rodata*)
        .config/output/object_files/cnc-types.o(.data)
        .config/output/object_files/cnc-types.o(.bss)
        .config/output/object_files/cnc-types.o(.sdata)
        .config/output/object_files/cnc-types.o(.sbss)
        .config/output/object_files/cnc-types.o(.scommon)
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
