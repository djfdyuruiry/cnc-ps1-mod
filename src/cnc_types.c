#include <cnc_types.h>

CncEnum* GetTypeEnumField(ObjectTypeClass* instance, const ObjectFieldOffset field_offset)
{
    return instance + field_offset;
}

void SetTypeEnumField(ObjectTypeClass* instance, const ObjectFieldOffset field_offset, const CncEnum value)
{
    *(instance + field_offset) = value;
}
