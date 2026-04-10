#ifndef CNC_TYPES_H
#define CNC_TYPES_H

#include <types.h>

// enum values
#define WEAPON_FLAMETHROWER 5
#define WEAPON_OBELISK_LASER 20

// type fields
#define TechnoTypeClass_Cost 0x20 // int
#define TechnoTypeClass_Primary 0x33 // WeaponType (char)

CncEnum* GetTypeEnumField(ObjectTypeClass* instance, ObjectFieldOffset field_offset);
void SetTypeEnumField(ObjectTypeClass* instance, ObjectFieldOffset field_offset, CncEnum value);

#endif // CNC_TYPES_H
