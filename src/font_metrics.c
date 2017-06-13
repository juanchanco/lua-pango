#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "font_metrics.h"


/*PangoFontMetrics * 	pango_font_metrics_ref ()*/
/*void 	pango_font_metrics_unref ()*/
/*int 	pango_font_metrics_get_ascent ()*/
/*int 	pango_font_metrics_get_descent ()*/
/*int 	pango_font_metrics_get_approximate_char_width ()*/
/*int 	pango_font_metrics_get_approximate_digit_width ()*/
/*int 	pango_font_metrics_get_underline_thickness ()*/
/*int 	pango_font_metrics_get_underline_position ()*/
/*int 	pango_font_metrics_get_strikethrough_thickness ()*/
/*int 	pango_font_metrics_get_strikethrough_position ()*/

const luaL_Reg FontMetricsFunctions[] = {
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { NULL, NULL }
};

const CommonObject FontMetrics = {
    "Pango.FontMetrics",
    methods,
    metamethods
};

