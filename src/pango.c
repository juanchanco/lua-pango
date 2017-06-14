#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "font.h"
#include "font_desc.h"
#include "font_face.h"
#include "font_face_array.h"
#include "font_family.h"
#include "font_family_array.h"
#include "font_map.h"
#include "font_metrics.h"
#include "font_set.h"
#include "glyph_item.h"
#include "glyph_string.h"
#include "item.h"
#include "layout.h"
#include "matrix.h"

static const luaL_Reg functions[] = {
    { NULL, NULL }
};


static const struct {
    const luaL_Reg *functions;
} libraries[] = {
    { ContextFunctions },
    { FontDescriptionFunctions },
    { GlyphStringFunctions },
    { ItemFunctions },
    { LayoutFunctions },
    { MatrixFunctions },
    { NULL }
};

static const struct {
    const char	*name;
    const CommonEnum *values;
} enums[] = {
    { "WrapMode", LuaPangoWrapMode },
    { "EllipsizeMode", LuaPangoEllipsizeMode },
    { "Alignment", LuaPangoAlignment },
    /*font_desc*/
    { "FontStyle", LuaPangoStyle },
    { "FontWeight", LuaPangoWeight },
    { "FontVariant", LuaPangoVariant },
    { "FontStretch", LuaPangoStretch },
    { "FontMask", LuaPangoFontMask },
    { NULL, NULL }
};

static const struct {
    const CommonObject *object;
} objects[] = {
    { &Context },
    { &Layout },
    { &Font},
    { &FontDescription },
    { &FontMap },
    { &FontFamily },
    { &FontFamilyArray },
    { &FontFace },
    { &FontFaceArray },
    { &FontMetrics },
    { &FontSet },
    { &Font },
    { &GlyphItem },
    { &GlyphString },
    { &Item },
    { NULL }
};



int EXPORT
luaopen_Pango(lua_State *L)
{
    int i;

    /* General functions */
    commonNewLibrary(L, functions);

    /* Library categories */
    for (i = 0; libraries[i].functions != NULL; ++i)
    	commonBindLibrary(L, libraries[i].functions);

    /* Enumerations */
    for (i = 0; enums[i].values != NULL; ++i)
    	commonBindEnum(L, -1, enums[i].name, enums[i].values);

    /* Object oriented data */
    for (i = 0; objects[i].object != NULL; ++i)
        commonBindObject(L, objects[i].object);

    /* Store the version */
    /*cairo_version ver;*/
    /*SDL_GetVersion(&ver);*/

    /*tableSetInt(L, -1, "VERSION_MAJOR", ver.major);*/
    /*tableSetInt(L, -1, "VERSION_MINOR", ver.minor);*/
    /*tableSetInt(L, -1, "VERSION_PATCH", ver.patch);*/

    /*tableSetInt(L, -1, "VERSION_BINDING", 4);*/
    /*tableSetInt(L, -1, "VERSION_BINDING_PATCH", 1);*/

    /*lua_newtable(L);*/
    /*tableSetInt(L, -1, "major", ver.major);*/
    /*tableSetInt(L, -1, "minor", ver.minor);*/
    /*tableSetInt(L, -1, "patch", ver.patch);*/
    /*lua_setfield(L, -2, "version");*/

    /*lua_newtable(L);*/
    /*tableSetInt(L, -1, "major", VERSION_BINDING_MAJOR);*/
    /*tableSetInt(L, -1, "minor", VERSION_BINDING_MINOR);*/
    /*lua_setfield(L, -2, "binding");*/

    return 1;
}
