#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"

/*GList * 	pango_itemize ()*/
/*GList * 	pango_itemize_with_base_dir ()*/
/*void 	pango_item_free ()*/
/*PangoItem * 	pango_item_copy ()*/
/*PangoItem * 	pango_item_new ()*/
/*PangoItem * 	pango_item_split ()*/
/*GList * 	pango_reorder_items ()*/
/*PangoContext * 	pango_context_new ()*/
static int _pango_context_new (lua_State* L) {
    PangoContext* result = pango_context_new();
    return commonPush(L, "p", ContextName, result);
}
/*void 	pango_context_changed ()*/
/*guint 	pango_context_get_serial ()*/
/*void 	pango_context_set_font_map ()*/
/*PangoFontMap * 	pango_context_get_font_map ()*/
/*PangoFontDescription * 	pango_context_get_font_description ()*/
/*void 	pango_context_set_font_description ()*/
/*PangoLanguage * 	pango_context_get_language ()*/
/*void 	pango_context_set_language ()*/
/*PangoDirection 	pango_context_get_base_dir ()*/
/*void 	pango_context_set_base_dir ()*/
/*PangoGravity 	pango_context_get_base_gravity ()*/
/*void 	pango_context_set_base_gravity ()*/
/*PangoGravity 	pango_context_get_gravity ()*/
/*PangoGravityHint 	pango_context_get_gravity_hint ()*/
/*void 	pango_context_set_gravity_hint ()*/
/*const PangoMatrix * 	pango_context_get_matrix ()*/
/*void 	pango_context_set_matrix ()*/
/*PangoFont * 	pango_context_load_font ()*/
/*PangoFontset * 	pango_context_load_fontset ()*/
/*PangoFontMetrics * 	pango_context_get_metrics ()*/
/*void 	pango_context_list_families ()*/
/*void 	pango_break ()*/
/*void 	pango_get_log_attrs ()*/
/*void 	pango_find_paragraph_boundary ()*/
/*void 	pango_default_break ()*/
/*void 	pango_shape ()*/
/*void 	pango_shape_full ()*/

static int l_context_gc(lua_State *L) {
    PangoContext *context = commonGetAs(L, 1, ContextName, PangoContext*);

    /*if (udata->mustdelete)*/
    /*TODO: count down to zero?*/
    g_object_unref(context);

    return 0;
}

const luaL_Reg ContextFunctions[] = {
    { "newContext", _pango_context_new },
    { NULL, NULL }
};
static const luaL_Reg methods[] = {
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__gc", l_context_gc },
    { NULL, NULL }
};

const CommonObject Context = {
    "Context",
    methods,
    metamethods
};
