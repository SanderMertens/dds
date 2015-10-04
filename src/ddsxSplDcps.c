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

const char *
__ddsx_CortoInvoke__name(void)
{
    return (const char*)"ddsx::CortoInvoke";
}

const char *
__ddsx_CortoInvoke__keys(void)
{
    return (const char*)"";
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

/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 225 */
c_bool
__ddsx_CortoInvoke__copyIn(c_base base, void *_from, void *_to)
{
    c_bool result = TRUE;

    ddsx_CortoInvoke *from = (ddsx_CortoInvoke *)_from;
    struct _ddsx_CortoInvoke *to = (struct _ddsx_CortoInvoke *)_to;
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 508 */
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 314 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->instance) {
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 341 */
        to->instance = c_stringNew(base, from->instance);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'ddsx::CortoInvoke.instance' of type 'c_string' is NULL.");
        result = FALSE;
    }
#else
    to->instance = c_stringNew(base, from->instance);
#endif
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 508 */
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 314 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->method) {
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 341 */
        to->method = c_stringNew(base, from->method);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'ddsx::CortoInvoke.method' of type 'c_string' is NULL.");
        result = FALSE;
    }
#else
    to->method = c_stringNew(base, from->method);
#endif
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 655 */
    {
        static c_type type0 = NULL;
        c_type subtype0;
        c_long length0;
        c_octet *dst0;
        DDS_sequence_octet *src0 = &from->args;

        if (type0 == NULL) {
            subtype0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
            type0 = c_metaSequenceTypeNew(c_metaObject(base),"C_SEQUENCE<c_octet>",subtype0,0);
            c_free(subtype0);
        }
        if(src0 != NULL){
            length0 = (c_long)(*src0)._length;
#ifdef OSPL_BOUNDS_CHECK
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 694 */
            dst0 = (c_octet *)c_newSequence(c_collectionType(type0), length0);
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 1707 */
            memcpy (dst0,(*src0)._buffer,length0* sizeof(*dst0));
            to->args = (c_sequence)dst0;
#else
            dst0 = (c_octet *)c_newSequence(c_collectionType(type0), length0);
/* Code generated in file: /home/erik/OvernightTests/tmp.EfPeTJ5ocF/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 1707 */
        memcpy (dst0,(*src0)._buffer,length0* sizeof(*dst0));
        to->args = (c_sequence)dst0;
#endif
        } else {
            result = FALSE;
        }
    }
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

void
__ddsx_CortoInvoke__copyOut(void *_from, void *_to)
{
    struct _ddsx_CortoInvoke *from = (struct _ddsx_CortoInvoke *)_from;
    ddsx_CortoInvoke *to = (ddsx_CortoInvoke *)_to;
    DDS_string_replace (from->instance ? from->instance : "", &to->instance);
    DDS_string_replace (from->method ? from->method : "", &to->method);
    {
        long size0;
        c_octet *src0 = (c_octet *)from->args;
        DDS_sequence_octet *dst0 = &to->args;

        size0 = c_arraySize((c_sequence)(from->args));
        DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, size0);
        dst0->_length = size0;
        memcpy ((*dst0)._buffer,src0,size0* sizeof(*((*dst0)._buffer)));
    }
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

ddsx_CortoInvoke *ddsx_CortoInvoke__alloc (void)
{
    DDS_boolean ddsx_CortoInvoke__free (void *object);

    return (ddsx_CortoInvoke *)DDS__malloc (ddsx_CortoInvoke__free, 0, sizeof(ddsx_CortoInvoke));
}

DDS_boolean ddsx_CortoInvoke__free (void *object)
{
    ddsx_CortoInvoke *o = (ddsx_CortoInvoke *)object;

    DDS_string_clean (&o->instance);
    DDS_string_clean (&o->method);
    DDS_sequence_clean (&o->args);
    return TRUE;
}

const char * ddsx_CortoDeclare_metaDescriptor[] = {"<MetaData version=\"1.0.0\"><Module name=\"ddsx\"><Struct name=\"CortoDeclare\"><Member name=\"parent\">",
"<String/></Member><Member name=\"name\"><String/></Member><Member name=\"type\"><String/></Member></Struct>",
"</Module></MetaData>"};
const c_ulong  ddsx_CortoDeclare_metaDescriptorArrLength = 3;
const char * ddsx_CortoUpdate_metaDescriptor[] = {"<MetaData version=\"1.0.0\"><Module name=\"ddsx\"><Struct name=\"CortoUpdate\"><Member name=\"id\"><String/>",
"</Member><Member name=\"value\"><String/></Member></Struct></Module></MetaData>"};
const c_ulong  ddsx_CortoUpdate_metaDescriptorArrLength = 2;
const char * ddsx_CortoInvoke_metaDescriptor[] = {"<MetaData version=\"1.0.0\"><Module name=\"ddsx\"><Struct name=\"CortoInvoke\"><Member name=\"instance\">",
"<String/></Member><Member name=\"method\"><String/></Member><Member name=\"args\"><Sequence><Octet/></Sequence>",
"</Member></Struct></Module></MetaData>"};
const c_ulong  ddsx_CortoInvoke_metaDescriptorArrLength = 3;
#if defined (__cplusplus)
}
#endif
