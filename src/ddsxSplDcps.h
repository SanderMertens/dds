#ifndef DDSXSPLTYPES_H
#define DDSXSPLTYPES_H

#include "ddsxDcps.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __ddsx_ddsx__load (c_base base);

extern const char *ddsx_CortoDeclare_metaDescriptor[];
extern const c_ulong ddsx_CortoDeclare_metaDescriptorArrLength;
extern c_metaObject __ddsx_CortoDeclare__load (c_base base);
extern const char * __ddsx_CortoDeclare__keys (void);
extern const char * __ddsx_CortoDeclare__name (void);
struct _ddsx_CortoDeclare ;
extern  c_bool __ddsx_CortoDeclare__copyIn(c_base base, void *from, void *to);
extern  void __ddsx_CortoDeclare__copyOut(void *_from, void *_to);
struct _ddsx_CortoDeclare {
    c_string parent;
    c_string name;
    c_string type;
};

extern const char *ddsx_CortoUpdate_metaDescriptor[];
extern const c_ulong ddsx_CortoUpdate_metaDescriptorArrLength;
extern c_metaObject __ddsx_CortoUpdate__load (c_base base);
extern const char * __ddsx_CortoUpdate__keys (void);
extern const char * __ddsx_CortoUpdate__name (void);
struct _ddsx_CortoUpdate ;
extern  c_bool __ddsx_CortoUpdate__copyIn(c_base base, void *from, void *to);
extern  void __ddsx_CortoUpdate__copyOut(void *_from, void *_to);
struct _ddsx_CortoUpdate {
    c_string id;
    c_string value;
};

extern const char *ddsx_CortoInvoke_metaDescriptor[];
extern const c_ulong ddsx_CortoInvoke_metaDescriptorArrLength;
extern c_metaObject __ddsx_CortoInvoke__load (c_base base);
extern const char * __ddsx_CortoInvoke__keys (void);
extern const char * __ddsx_CortoInvoke__name (void);
struct _ddsx_CortoInvoke ;
extern  c_bool __ddsx_CortoInvoke__copyIn(c_base base, void *from, void *to);
extern  void __ddsx_CortoInvoke__copyOut(void *_from, void *_to);
struct _ddsx_CortoInvoke {
    c_string instance;
    c_string method;
    c_sequence args;
};

#endif
