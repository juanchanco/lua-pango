#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "glyph_string.h"


/*void 	pango_glyph_string_set_size ()*/
/*void 	pango_glyph_string_free ()*/
/*void 	pango_glyph_string_extents ()*/
/*void 	pango_glyph_string_extents_range ()*/
/*int 	pango_glyph_string_get_width ()*/
/*void 	pango_glyph_string_index_to_x ()*/
/*void 	pango_glyph_string_x_to_index ()*/
/*void 	pango_glyph_string_get_logical_widths ()*/
static int _pango_glyph_string_new(lua_State *L) {
    PangoGlyphString* new = pango_glyph_string_new();

    return commonPush(L, "p", GlyphStringName, new);
}
static int _pango_glyph_string_copy(lua_State *L) {
    PangoGlyphString* glyph_string = commonGetAs(L, 1, GlyphStringName, PangoGlyphString *);
    PangoGlyphString* copy = pango_glyph_string_copy(glyph_string);

    return commonPush(L, "p", GlyphStringName, copy);
}
static int _pango_glyph_string_free(lua_State *L) {
    PangoGlyphString* glyph_string = commonGetAs(L, 1, GlyphStringName, PangoGlyphString *);
    pango_glyph_string_free(glyph_string);

    return 0;
}


const luaL_Reg GlyphStringFunctions[] = {
    { "glyphStringNew", _pango_glyph_string_new },
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { "copy", _pango_glyph_string_copy },
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__gc", _pango_glyph_string_free },
    { NULL, NULL }
};

const CommonObject GlyphString = {
    "Pango.GlyphString",
    methods,
    metamethods
};
