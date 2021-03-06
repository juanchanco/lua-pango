#ifndef _LAYOUT_H_
#define _LAYOUT_H_

#include <common/common.h>

#define LayoutName	Layout.name

extern const luaL_Reg LayoutFunctions[];

extern const CommonObject Layout;

extern const CommonEnum LuaPangoWrapMode[];
extern const CommonEnum LuaPangoEllipsizeMode[];
extern const CommonEnum LuaPangoAlignment[];

#endif /* !_LAYOUT_H_ */
