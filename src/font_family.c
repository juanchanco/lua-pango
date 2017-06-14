#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "font_face_array.h"
#include "font_family.h"


static int _pango_font_family_get_name (lua_State* L) {
    PangoFontFamily *family = commonGetAs(L, 1, FontFamilyName, PangoFontFamily *);
    const char* name = pango_font_family_get_name(family);
    return commonPush(L, "s", name);
}
static int _pango_font_family_is_monospace (lua_State* L) {
    PangoFontFamily *family = commonGetAs(L, 1, FontFamilyName, PangoFontFamily *);
    gboolean is_monospace = pango_font_family_is_monospace(family);
    return commonPush(L, "b", is_monospace);
}
static int _pango_font_family_list_faces (lua_State* L) {
    PangoFontFamily *family = commonGetAs(L, 1, FontFamilyName, PangoFontFamily *);
    PangoFontFace **faces = 0;
    int length;

    pango_font_family_list_faces(family, &faces, &length);
    return push_new_font_face_array(L, faces, length);
}

static int font_family_tostring(lua_State *L) {
    PangoFontFamily *family = commonGetAs(L, 1, FontFamilyName, PangoFontFamily *);
    const char* name = pango_font_family_get_name(family);
    lua_pushfstring(L, "%s: %s", FontFamilyName, name);

    return 1;
}

static const luaL_Reg methods[] = {
    { "listFaces", _pango_font_family_list_faces },
    { "getName", _pango_font_family_get_name },
    { "isMonospace", _pango_font_family_is_monospace },
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__tostring", font_family_tostring },
    { NULL, NULL }
};

const CommonObject FontFamily = {
    "Pango.FontFamily",
    methods,
    metamethods
};

