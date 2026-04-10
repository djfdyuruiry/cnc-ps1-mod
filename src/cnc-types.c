#include <cnc-types.h>

CncEnum* GetTypeEnumField(ObjectTypeClass* instance, ObjectFieldOffset field_offset)
{
    return (CncEnum*)(instance + field_offset);
}

void SetTypeEnumField(ObjectTypeClass* instance, ObjectFieldOffset field_offset, CncEnum value)
{
    *(instance + field_offset) = value;
}
