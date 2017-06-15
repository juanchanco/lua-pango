#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "font_desc.h"
#include "font_face.h"

static int _pango_font_face_get_face_name(lua_State *L) {
    PangoFontFace* face = commonGetAs(L, 1, FontFaceName, PangoFontFace *);
    const char* result = pango_font_face_get_face_name(face);
    lua_pushstring(L, result);
    return 1;
}
/*void     pango_font_face_list_sizes ()*/
static int _pango_font_face_list_sizes (lua_State* L) {
    PangoFontFace* face = commonGetAs(L, 1, FontFaceName, PangoFontFace *);
    int *sizes;
    int n;
    pango_font_face_list_sizes(face, &sizes, &n);
    if (sizes) {
        lua_createtable(L, n, 0);
        int i;
        for (i = 0; i < n; i++) {
            lua_pushinteger(L, sizes[i]);
            lua_seti(L, 2, i);
        }
    } else {
        lua_pushnil(L);
    }
    return 1;
}
static int _pango_font_face_describe (lua_State* L) {
    PangoFontFace* face = commonGetAs(L, 1, FontFaceName, PangoFontFace *);
    PangoFontDescription* result = pango_font_face_describe(face);
    return commonPush(L, "p", FontDescriptionName, result);
}
static int _pango_font_face_is_synthesized (lua_State* L) {
    PangoFontFace* face = commonGetAs(L, 1, FontFaceName, PangoFontFace *);
    gboolean result = pango_font_face_is_synthesized(face);
    return commonPush(L, "b", result);
}

static int _tostring(lua_State *L) {
    PangoFontFace* face = commonGetAs(L, 1, FontFaceName, PangoFontFace *);
    const char* result = pango_font_face_get_face_name(face);
    lua_pushfstring(L, "%s: %s", FontFaceName, result);

    return 1;
}

static const luaL_Reg methods[] = {
    { "listSizes", _pango_font_face_list_sizes },
    { "isSynthesized", _pango_font_face_is_synthesized },
    { "describe", _pango_font_face_describe },
    { "getFaceName", _pango_font_face_get_face_name },
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__tostring", _tostring},
    { NULL, NULL }
};

const CommonObject FontFace = {
    "Pango.FontFace",
    methods,
    metamethods
};

