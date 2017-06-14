#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "font_map.h"
#include "font_family_array.h"


/*PangoContext * 	pango_font_map_create_context ()*/
static int _pango_font_map_create_context (lua_State* L) {
    PangoFontMap *map = commonGetAs(L, 1, FontMapName, PangoFontMap *);
    PangoContext* result = pango_font_map_create_context(map);
    /*TODO: some error checking*/
    return commonPush(L, "p", ContextName, result);
}
/*PangoFont * 	pango_font_map_load_font ()*/
/*PangoFontset * 	pango_font_map_load_fontset ()*/
/*void 	pango_font_map_list_families ()*/
static int _pango_font_map_list_families (lua_State* L) {
    PangoFontMap *map = commonGetAs(L, 1, FontMapName, PangoFontMap *);
    PangoFontFamily ***families = 0;
    int length;

    pango_font_map_list_families(map, families, &length);
    return push_new_font_family_array(L, families, length);
}
/*const char * 	pango_font_map_get_shape_engine_type ()*/
/*guint 	pango_font_map_get_serial ()*/
/*void 	pango_font_map_changed ()*/


const luaL_Reg FontMapFunctions[] = {
    { "listFamilies", _pango_font_map_list_families },
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { "createContext", _pango_font_map_create_context },
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { NULL, NULL }
};

const CommonObject FontMap = {
    "Pango.FontMap",
    methods,
    metamethods
};

