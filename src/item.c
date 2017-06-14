#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "item.h"

static int _pango_item_new(lua_State *L) {
    PangoItem* new = pango_item_new();

    return commonPush(L, "p", ItemName, new);
}

static int _pango_item_copy(lua_State *L) {
    PangoItem* item = commonGetAs(L, 1, ItemName, PangoItem *);
    PangoItem* copy = pango_item_copy(item);

    return commonPush(L, "p", ItemName, copy);
}

/*PangoItem * 	pango_item_split ()*/

static int _pango_item_free(lua_State *L) {
    PangoItem* item = commonGetAs(L, 1, ItemName, PangoItem *);
    pango_item_free(item);

    return 0;
}

const luaL_Reg ItemFunctions[] = {
    { "itemNew", _pango_item_new },
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { "copy", _pango_item_copy },
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__gc", _pango_item_free },
    { NULL, NULL }
};

const CommonObject Item = {
    "Pango.Item",
    methods,
    metamethods
};
