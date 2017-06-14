#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "font_desc.h"

const CommonEnum LuaPangoStyle[] = {
    { "Normal", PANGO_STYLE_NORMAL },
    { "Oblique", PANGO_STYLE_OBLIQUE },
    { "Italic", PANGO_STYLE_ITALIC },
    { NULL, -1 }
};

const CommonEnum LuaPangoWeight[] = {
    { "Thin", PANGO_WEIGHT_THIN },
    { "Ultralight", PANGO_WEIGHT_ULTRALIGHT },
    { "Light", PANGO_WEIGHT_LIGHT },
    { "Semilight", PANGO_WEIGHT_SEMILIGHT },
    { "Book", PANGO_WEIGHT_BOOK },
    { "Normal", PANGO_WEIGHT_NORMAL },
    { "Medium", PANGO_WEIGHT_MEDIUM },
    { "Semibold", PANGO_WEIGHT_SEMIBOLD },
    { "Bold", PANGO_WEIGHT_BOLD },
    { "Ultrabold", PANGO_WEIGHT_ULTRABOLD },
    { "Heavy", PANGO_WEIGHT_HEAVY },
    { "Ultraheavy", PANGO_WEIGHT_ULTRAHEAVY },
    { NULL, -1 }
};

const CommonEnum LuaPangoVariant[] = {
    { "Normal", PANGO_VARIANT_NORMAL },
    { "Small_caps", PANGO_VARIANT_SMALL_CAPS },
    { NULL, -1 }
};

const CommonEnum LuaPangoStretch[] = {
    { "Ultra_condensed", PANGO_STRETCH_ULTRA_CONDENSED },
    { "Extra_condensed", PANGO_STRETCH_EXTRA_CONDENSED },
    { "Condensed", PANGO_STRETCH_CONDENSED },
    { "Semi_condensed", PANGO_STRETCH_SEMI_CONDENSED },
    { "Normal", PANGO_STRETCH_NORMAL },
    { "Semi_expanded", PANGO_STRETCH_SEMI_EXPANDED },
    { "Expanded", PANGO_STRETCH_EXPANDED },
    { "Extra_expanded", PANGO_STRETCH_EXTRA_EXPANDED },
    { "Ultra_expanded", PANGO_STRETCH_ULTRA_EXPANDED },
    { NULL, -1 }
};

const CommonEnum LuaPangoFontMask[] = {
    { "Family", PANGO_FONT_MASK_FAMILY },
    { "Style", PANGO_FONT_MASK_STYLE },
    { "Variant", PANGO_FONT_MASK_VARIANT },
    { "Weight", PANGO_FONT_MASK_WEIGHT },
    { "Stretch", PANGO_FONT_MASK_STRETCH },
    { "Size", PANGO_FONT_MASK_SIZE },
    { "Gravity", PANGO_FONT_MASK_GRAVITY },
    { NULL, -1 }
};


/*PangoFontDescription * 	pango_font_description_new ()*/
/*PangoFontDescription * 	pango_font_description_copy ()*/
/*PangoFontDescription * 	pango_font_description_copy_static ()*/
/*guint 	pango_font_description_hash ()*/
/*gboolean 	pango_font_description_equal ()*/
/*void 	pango_font_description_set_family ()*/
/*void 	pango_font_description_set_family_static ()*/
/*const char * 	pango_font_description_get_family ()*/
/*void 	pango_font_description_set_style ()*/
/*PangoStyle 	pango_font_description_get_style ()*/
/*void 	pango_font_description_set_variant ()*/
/*PangoVariant 	pango_font_description_get_variant ()*/
/*void 	pango_font_description_set_weight ()*/
/*PangoWeight 	pango_font_description_get_weight ()*/
/*void 	pango_font_description_set_stretch ()*/
/*PangoStretch 	pango_font_description_get_stretch ()*/
static int _pango_font_description_set_absolute_size (lua_State* L) {
    PangoFontDescription *desc = commonGetAs(L, 1, FontDescriptionName, PangoFontDescription *);
    double size =  (double) luaL_checknumber(L, 2);
    pango_font_description_set_absolute_size(desc, size);
    return 0;
}
/*gint 	pango_font_description_get_size ()*/
static int _pango_font_description_set_size (lua_State* L) {
    PangoFontDescription *desc = commonGetAs(L, 1, FontDescriptionName, PangoFontDescription *);
    int size = luaL_checkinteger(L, 2);
    pango_font_description_set_size(desc, size);
    return 0;
}
/*gboolean 	pango_font_description_get_size_is_absolute ()*/
/*void 	pango_font_description_set_gravity ()*/
/*PangoGravity 	pango_font_description_get_gravity ()*/
/*PangoFontMask 	pango_font_description_get_set_fields ()*/
/*void 	pango_font_description_unset_fields ()*/
/*void 	pango_font_description_merge ()*/
/*void 	pango_font_description_merge_static ()*/
/*gboolean 	pango_font_description_better_match ()*/
static int _pango_font_description_from_string (lua_State* L) {
    const char* str = luaL_checkstring (L, 1);
    PangoFontDescription* result = pango_font_description_from_string(str);
    return commonPush(L, "p", FontDescriptionName, result);
}
/*char * 	pango_font_description_to_filename ()*/

static int _pango_font_desc_tostring(lua_State *L) {
    PangoFontDescription* desc = commonGetAs(L, 1, FontDescriptionName, PangoFontDescription *);
	char* result = pango_font_description_to_string(desc);
	lua_pushstring(L, result);

	return 1;
}

static int _tostring(lua_State *L) {
    PangoFontDescription* desc = commonGetAs(L, 1, FontDescriptionName, PangoFontDescription *);
	char* result = pango_font_description_to_string(desc);
	lua_pushfstring(L, "%s: %s", FontDescriptionName, result);

	return 1;
}

static int _free(lua_State *L) {
    CommonUserdata *udata = commonGetUserdata(L, 1, FontDescriptionName);

    /*if (udata->mustdelete)*/
    pango_font_description_free(udata->data);

    return 0;
}

const luaL_Reg FontDescriptionFunctions[] = {
    { "fontDescriptionFromString", _pango_font_description_from_string },
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { "setAbsoluteSize", _pango_font_description_set_absolute_size },
    { "setSize", _pango_font_description_set_size },
    { "toString", _pango_font_desc_tostring },
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__tostring", _tostring},
    { "__gc", _free },
    { NULL, NULL }
};

const CommonObject FontDescription = {
    "Pango.FontDescription",
    methods,
    metamethods
};
