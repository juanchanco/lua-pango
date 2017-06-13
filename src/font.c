#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "font.h"

/*PangoEngineShape * 	pango_font_find_shaper ()*/
/*PangoFontDescription * 	pango_font_describe ()*/
/*PangoFontDescription * 	pango_font_describe_with_absolute_size ()*/
/*PangoCoverage * 	pango_font_get_coverage ()*/
/*void 	pango_font_get_glyph_extents ()*/
/*PangoFontMetrics * 	pango_font_get_metrics ()*/
/*PangoFontMap * 	pango_font_get_font_map ()*/

const luaL_Reg FontFunctions[] = {
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { NULL, NULL }
};

const CommonObject Font = {
    "Pango.Font",
    methods,
    metamethods
};


