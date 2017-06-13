#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "font_face.h"

/*const char * 	pango_font_face_get_face_name ()*/
/*void 	pango_font_face_list_sizes ()*/
/*PangoFontDescription * 	pango_font_face_describe ()*/
/*gboolean 	pango_font_face_is_synthesized ()*/

const luaL_Reg FontFaceFunctions[] = {
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { NULL, NULL }
};

const CommonObject FontFace = {
    "Pango.FontFace",
    methods,
    metamethods
};

