#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "font_set.h"

/*PangoFont * 	pango_fontset_get_font ()*/
/*PangoFontMetrics * 	pango_fontset_get_metrics ()*/
/*gboolean 	(*PangoFontsetForeachFunc) ()*/
/*void 	pango_fontset_foreach ()*/
/*PangoFontsetSimple * 	pango_fontset_simple_new ()*/
/*void 	pango_fontset_simple_append ()*/
/*int 	pango_fontset_simple_size ()*/


static const luaL_Reg methods[] = {
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { NULL, NULL }
};

const CommonObject FontSet = {
    "Pango.FontSet",
    methods,
    metamethods
};

