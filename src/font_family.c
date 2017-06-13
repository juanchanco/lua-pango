#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "font_family.h"


/*const char * 	pango_font_family_get_name ()*/
/*gboolean 	pango_font_family_is_monospace ()*/
/*void 	pango_font_family_list_faces ()*/

const luaL_Reg FontFamilyFunctions[] = {
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { NULL, NULL }
};

const CommonObject FontFamily = {
    "Pango.FontFamily",
    methods,
    metamethods
};

