#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "glyph_item.h"


/*PangoGlyphItem * 	pango_glyph_item_split ()*/
/*GSList * 	pango_glyph_item_apply_attrs ()*/
/*void 	pango_glyph_item_letter_space ()*/
/*void 	pango_glyph_item_get_logical_widths ()*/
/*PangoGlyphItemIter * 	pango_glyph_item_iter_copy ()*/
/*void 	pango_glyph_item_iter_free ()*/
/*gboolean 	pango_glyph_item_iter_init_start ()*/
/*gboolean 	pango_glyph_item_iter_init_end ()*/
/*gboolean 	pango_glyph_item_iter_next_cluster ()*/
/*gboolean 	pango_glyph_item_iter_prev_cluster ()*/
static int _pango_glyph_item_copy(lua_State *L) {
    PangoGlyphItem* glyph_item = commonGetAs(L, 1, GlyphItemName, PangoGlyphItem *);
    PangoGlyphItem* copy = pango_glyph_item_copy(glyph_item);

    return commonPush(L, "p", GlyphItemName, copy);
}
static int _pango_glyph_item_free(lua_State *L) {
    PangoGlyphItem* glyph_item = commonGetAs(L, 1, GlyphItemName, PangoGlyphItem *);
    pango_glyph_item_free(glyph_item);

    return 0;
}

const luaL_Reg GlyphItemFunctions[] = {
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { "copy", _pango_glyph_item_copy },
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__gc", _pango_glyph_item_free },
    { NULL, NULL }
};

const CommonObject GlyphItem = {
    "Pango.GlyphItem",
    methods,
    metamethods
};
