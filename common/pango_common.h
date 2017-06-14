#include <pango/pango.h>
#include "common.h"

#ifndef _PANGO_COMMON_H_
#define _PANGO_COMMON_H_

void
pushRect(lua_State *L, const PangoRectangle *rect);

void
loadRect(lua_State *L, PangoRectangle *rect);
#endif /* !_PANGO_COMMON_H_ */
