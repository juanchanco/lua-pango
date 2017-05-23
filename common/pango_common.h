#include <pango/pango.h>
#include "common.h"

#ifndef _PANGO_COMMON_H_
#define _PANGO_COMMON_H_

/**
 * Pushes count * nil + the SDL_GetError() message.
 *
 * @param L the Lua state
 * @param count number of nil to pushes before
 * @return count
 */
//int commonPushCairoError(lua_State *L, cairo_status_t status);

#endif /* !_PANGO_COMMON_H_ */
