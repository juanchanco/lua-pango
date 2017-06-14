#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "font_face.h"
#include "font_face_array.h"

typedef struct {
    PangoFontFace **families;
    int length;
} font_face_array;

int push_new_font_face_array(lua_State *L, PangoFontFace **families, int length) {
    /*TODO: should userdata be used here?*/
    /*font_face_array* array = lua_newuserdata(L, sizeof (font_face_array));*/
    font_face_array* array = malloc(sizeof (font_face_array));
    array->families = families;
    array->length = length;

    return commonPush(L, "p", FontFaceArrayName, array);
}

static int font_face_array_get(lua_State *L) {
    font_face_array *array = commonGetAs(L, 1, FontFaceArrayName, font_face_array *);
    int i = luaL_checkinteger (L, 2) - 1;
    if (0 <= i && i < array->length) {
        return commonPush(L, "p", FontFaceName, (array->families)[i]);
    } else {
        return commonPush(L, "n");
    }
}
static int font_face_array_len(lua_State *L) {
    font_face_array *array = commonGetAs(L, 1, FontFaceArrayName, font_face_array *);

    return commonPush(L, "i", array->length);
}
static int font_face_array_gc(lua_State *L) {
    font_face_array *array = commonGetAs(L, 1, FontFaceArrayName, font_face_array *);

    g_free(array->families);
    /*TODO: should userdata be used here?*/
    free(array);

    return 0;
}

/*TODO: how to create a custom pairs/ipairs?*/
static const luaL_Reg metamethods[] = {
    { "__gc", font_face_array_gc },
    { "__index", font_face_array_get },
    { "__len", font_face_array_len },
    { NULL, NULL }
};

const CommonObject FontFaceArray = {
    "Pango.FontFaceArray",
    NULL,
    metamethods
};
