#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "layout.h"
#include "font_desc.h"


static const luaL_Reg functions[] = {
    { NULL, NULL }
};


static const struct {
    const luaL_Reg *functions;
} libraries[] = {
    /*{ CpuFunctions					},*/
    { NULL						}
};

static const struct {
    const char	*name;
    const CommonEnum *values;
} enums[] = {
	{ "wrapMode", LuaPangoWrapMode },
	{ "ellipsizeMode", LuaPangoEllipsizeMode },
	{ "alignment", LuaPangoAlignment },
    { NULL, NULL }
};

static const struct {
	const CommonObject *object;
} objects[] = {
	{ &Layout },
	{ &FontDescription },
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

    tableSetInt(L, -1, "VERSION_BINDING", 4);
    tableSetInt(L, -1, "VERSION_BINDING_PATCH", 1);

    /*lua_newtable(L);*/
    /*tableSetInt(L, -1, "major", ver.major);*/
    /*tableSetInt(L, -1, "minor", ver.minor);*/
    /*tableSetInt(L, -1, "patch", ver.patch);*/
    /*lua_setfield(L, -2, "version");*/

    lua_newtable(L);
    tableSetInt(L, -1, "major", VERSION_BINDING_MAJOR);
    tableSetInt(L, -1, "minor", VERSION_BINDING_MINOR);
    lua_setfield(L, -2, "binding");

    return 1;
}
