#if defined (__cplusplus)
extern "C" {
#endif

#include "os.h"
#include "ddsxSplDcps.h"
#include "ddsxDcps.h"

const char *
__ddsx_CortoDeclare__name(void)
{
    return (const char*)"ddsx::CortoDeclare";
}

const char *
__ddsx_CortoDeclare__keys(void)
{
    return (const char*)"parent,name";
}

const char *
__ddsx_CortoUpdate__name(void)
{
    return (const char*)"ddsx::CortoUpdate";
}

const char *
__ddsx_CortoUpdate__keys(void)
{
    return (const char*)"id";
}

/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 140 */
#include <v_kernel.h>
#include <v_topic.h>
#include <string.h>
#include <os_report.h>

/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 225 */
c_bool
__ddsx_CortoDeclare__copyIn(c_base base, void *_from, void *_to)
{
    c_bool result = TRUE;

    ddsx_CortoDeclare *from = (ddsx_CortoDeclare *)_from;
    struct _ddsx_CortoDeclare *to = (struct _ddsx_CortoDeclare *)_to;
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 508 */
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 314 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->parent) {
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 341 */
        to->parent = c_stringNew(base, from->parent);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'ddsx::CortoDeclare.parent' of type 'c_string' is NULL.");
        result = FALSE;
    }
#else
    to->parent = c_stringNew(base, from->parent);
#endif
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 508 */
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 314 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->name) {
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 341 */
        to->name = c_stringNew(base, from->name);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'ddsx::CortoDeclare.name' of type 'c_string' is NULL.");
        result = FALSE;
    }
#else
    to->name = c_stringNew(base, from->name);
#endif
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 508 */
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 314 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->type) {
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 341 */
        to->type = c_stringNew(base, from->type);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'ddsx::CortoDeclare.type' of type 'c_string' is NULL.");
        result = FALSE;
    }
#else
    to->type = c_stringNew(base, from->type);
#endif
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 260 */
    (void) base;
    return result;
}

/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 225 */
c_bool
__ddsx_CortoUpdate__copyIn(c_base base, void *_from, void *_to)
{
    c_bool result = TRUE;

    ddsx_CortoUpdate *from = (ddsx_CortoUpdate *)_from;
    struct _ddsx_CortoUpdate *to = (struct _ddsx_CortoUpdate *)_to;
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 508 */
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 314 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->id) {
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 341 */
        to->id = c_stringNew(base, from->id);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'ddsx::CortoUpdate.id' of type 'c_string' is NULL.");
        result = FALSE;
    }
#else
    to->id = c_stringNew(base, from->id);
#endif
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 508 */
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 314 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->value) {
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 341 */
        to->value = c_stringNew(base, from->value);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'ddsx::CortoUpdate.value' of type 'c_string' is NULL.");
        result = FALSE;
    }
#else
    to->value = c_stringNew(base, from->value);
#endif
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 260 */
    (void) base;
    return result;
}

#include <dds_dcps_private.h>

void
__ddsx_CortoDeclare__copyOut(void *_from, void *_to)
{
    struct _ddsx_CortoDeclare *from = (struct _ddsx_CortoDeclare *)_from;
    ddsx_CortoDeclare *to = (ddsx_CortoDeclare *)_to;
    DDS_string_replace (from->parent ? from->parent : "", &to->parent);
    DDS_string_replace (from->name ? from->name : "", &to->name);
    DDS_string_replace (from->type ? from->type : "", &to->type);
}

void
__ddsx_CortoUpdate__copyOut(void *_from, void *_to)
{
    struct _ddsx_CortoUpdate *from = (struct _ddsx_CortoUpdate *)_from;
    ddsx_CortoUpdate *to = (ddsx_CortoUpdate *)_to;
    DDS_string_replace (from->id ? from->id : "", &to->id);
    DDS_string_replace (from->value ? from->value : "", &to->value);
}

#include <dds_dcps_private.h>

ddsx_CortoDeclare *ddsx_CortoDeclare__alloc (void)
{
    DDS_boolean ddsx_CortoDeclare__free (void *object);

    return (ddsx_CortoDeclare *)DDS__malloc (ddsx_CortoDeclare__free, 0, sizeof(ddsx_CortoDeclare));
}

DDS_boolean ddsx_CortoDeclare__free (void *object)
{
    ddsx_CortoDeclare *o = (ddsx_CortoDeclare *)object;

    DDS_string_clean (&o->parent);
    DDS_string_clean (&o->name);
    DDS_string_clean (&o->type);
    return TRUE;
}

ddsx_CortoUpdate *ddsx_CortoUpdate__alloc (void)
{
    DDS_boolean ddsx_CortoUpdate__free (void *object);

    return (ddsx_CortoUpdate *)DDS__malloc (ddsx_CortoUpdate__free, 0, sizeof(ddsx_CortoUpdate));
}

DDS_boolean ddsx_CortoUpdate__free (void *object)
{
    ddsx_CortoUpdate *o = (ddsx_CortoUpdate *)object;

    DDS_string_clean (&o->id);
    DDS_string_clean (&o->value);
    return TRUE;
}

const char * ddsx_CortoDeclare_metaDescriptor[] = {"<MetaData version=\"1.0.0\"><Module name=\"ddsx\"><Struct name=\"CortoDeclare\"><Member name=\"parent\">",
"<String/></Member><Member name=\"name\"><String/></Member><Member name=\"type\"><String/></Member></Struct>",
"</Module></MetaData>"};
const c_ulong  ddsx_CortoDeclare_metaDescriptorArrLength = 3;
const char * ddsx_CortoUpdate_metaDescriptor[] = {"<MetaData version=\"1.0.0\"><Module name=\"ddsx\"><Struct name=\"CortoUpdate\"><Member name=\"id\"><String/>",
"</Member><Member name=\"value\"><String/></Member></Struct></Module></MetaData>"};
const c_ulong  ddsx_CortoUpdate_metaDescriptorArrLength = 2;
#if defined (__cplusplus)
}
#endif
