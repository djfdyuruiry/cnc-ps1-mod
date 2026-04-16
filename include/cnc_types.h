#ifndef CNC_TYPES_H
#define CNC_TYPES_H

// cnc game engine type aliases for readability
typedef unsigned int ObjectFieldOffset;
typedef char CncEnum;
typedef char ObjectTypeClass;
typedef ObjectTypeClass TechnoTypeClass;
typedef TechnoTypeClass InfantryTypeClass;
typedef TechnoTypeClass UnitTypeClass;

// enum values
#define WEAPON_RIFLE 0
#define WEAPON_M16 3
#define WEAPON_FLAMETHROWER 5
#define WEAPON_OBELISK_LASER 20

// type fields
#define TechnoTypeClass_Cost 0x20 // int
#define TechnoTypeClass_Primary 0x33 // WeaponType (char)

CncEnum* GetTypeEnumField(ObjectTypeClass* instance, ObjectFieldOffset field_offset);
void SetTypeEnumField(ObjectTypeClass* instance, ObjectFieldOffset field_offset, CncEnum value);

enum MusicTrack
{
    MUSIC_TRACK_I_AM = 13,
    MUSIC_TRACK_MENU = 15
};

#endif // CNC_TYPES_H
