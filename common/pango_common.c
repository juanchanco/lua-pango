#include <pango/pango.h>
#include "table.h"
#include "pango_common.h"

/*int commonPushPangoError(lua_State *L, cairo_status_t status) {*/
        /*lua_pushnil(L);*/
        /*lua_pushstring(L, cairo_status_to_string(status));*/
        /*return 2;*/
/*}*/
void
pushRect(lua_State *L, const PangoRectangle *rect)
{
	int i;

	lua_createtable(L, 0, 0);
    tableSetInt(L, -1, "x", rect->x);
    tableSetInt(L, -1, "y", rect->y);
    tableSetInt(L, -1, "width", rect->width);
    tableSetInt(L, -1, "height", rect->x);
}
