#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "font_family.h"
#include "font_family_array.h"

typedef struct {
    PangoFontFamily **families;
    int length;
} font_family_array;

int push_new_font_family_array(lua_State *L, PangoFontFamily **families, int length) {
    /*TODO: should userdata be used here?*/
    /*font_family_array* array = lua_newuserdata(L, sizeof (font_family_array));*/
    font_family_array* array = malloc(sizeof (font_family_array));
    array->families = families;
    array->length = length;

    return commonPush(L, "p", FontFamilyArrayName, array);
}

static int font_family_array_get(lua_State *L) {
    font_family_array *array = commonGetAs(L, 1, FontFamilyArrayName, font_family_array *);
    int i = luaL_checkinteger (L, 2);
    luaL_argcheck(L, 0 <= i && i < array->length, 2, "index out of bounds");

    return commonPush(L, "p", FontFamilyName, (array->families)[i]);
}
static int font_family_array_len(lua_State *L) {
    font_family_array *array = commonGetAs(L, 1, FontFamilyArrayName, font_family_array *);

    return commonPush(L, "i", array->length);
}
static int font_family_array_gc(lua_State *L) {
    font_family_array *array = commonGetAs(L, 1, FontFamilyArrayName, font_family_array *);

    g_free(array->families);
    /*TODO: should userdata be used here?*/
    free(array);

    return 0;
}

/*TODO: how to create a custom pairs/ipairs?*/
static const luaL_Reg metamethods[] = {
    { "__gc", font_family_array_gc },
    { "__index", font_family_array_get },
    { "__len", font_family_array_len },
    { NULL, NULL }
};

const CommonObject FontFamilyArray = {
    "Pango.FontFamilyArray",
    NULL,
    metamethods
};
