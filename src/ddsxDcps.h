#ifndef DDSXDCPS_H
#define DDSXDCPS_H

#include <dds_dcps.h>


#ifndef _ddsx_CortoDeclare_defined
#define _ddsx_CortoDeclare_defined
#ifdef __cplusplus
struct ddsx_CortoDeclare;
#else /* __cplusplus */
typedef struct ddsx_CortoDeclare ddsx_CortoDeclare;
#endif /* __cplusplus */
#endif /* _ddsx_CortoDeclare_defined */
 ddsx_CortoDeclare *ddsx_CortoDeclare__alloc (void);

struct ddsx_CortoDeclare {
    DDS_string parent;
    DDS_string name;
    DDS_string type;
};

#ifndef _ddsx_CortoUpdate_defined
#define _ddsx_CortoUpdate_defined
#ifdef __cplusplus
struct ddsx_CortoUpdate;
#else /* __cplusplus */
typedef struct ddsx_CortoUpdate ddsx_CortoUpdate;
#endif /* __cplusplus */
#endif /* _ddsx_CortoUpdate_defined */
 ddsx_CortoUpdate *ddsx_CortoUpdate__alloc (void);

struct ddsx_CortoUpdate {
    DDS_string id;
    DDS_string value;
};

#endif
