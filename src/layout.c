#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "layout.h"

const CommonEnum LuaPangoWrapMode[] = {
    { "Word", PANGO_WRAP_WORD },
    { "Char", PANGO_WRAP_CHAR },
    { "Word_char", PANGO_WRAP_WORD_CHAR },
    { NULL, -1 }
};

const CommonEnum LuaPangoEllipsizeMode[] = {
    { "None", PANGO_ELLIPSIZE_NONE },
    { "Start", PANGO_ELLIPSIZE_START },
    { "Middle", PANGO_ELLIPSIZE_MIDDLE },
    { "End", PANGO_ELLIPSIZE_END },
    { NULL, -1 }
};

const CommonEnum LuaPangoAlignment[] = {
    { "Left", PANGO_ALIGN_LEFT },
    { "Center", PANGO_ALIGN_CENTER },
    { "Right", PANGO_ALIGN_RIGHT },
    { NULL, -1 }
};


/*PangoLayout *  pango_layout_new ()*/
/*PangoLayout *  pango_layout_copy ()*/
/*PangoContext *  pango_layout_get_context ()*/
/*void  pango_layout_context_changed ()*/
/*guint  pango_layout_get_serial ()*/
static int _pango_layout_set_text (lua_State* L) {
    PangoLayout *layout = commonGetAs(L, 1, LayoutName, PangoLayout *);
    const char* text = luaL_checkstring(L, 2);
    int length = luaL_checkinteger(L, 3);
    pango_layout_set_text(layout, text, length);
    return commonPush(L, "b", 1);
}
/*const char *  pango_layout_get_text ()*/
/*gint  pango_layout_get_character_count ()*/
/*void  pango_layout_set_markup ()*/
/*void  pango_layout_set_markup_with_accel ()*/
/*void  pango_layout_set_attributes ()*/
/*PangoAttrList *  pango_layout_get_attributes ()*/
static int _pango_layout_set_font_description (lua_State* L) {
    PangoLayout *layout = commonGetAs(L, 1, LayoutName, PangoLayout *);
    PangoFontDescription *desc =
        commonGetAs(L, 2, "FontDescription", PangoFontDescription *);
    pango_layout_set_font_description(layout, desc);
    return commonPush(L, "b", 1);
}
/*const PangoFontDescription *  pango_layout_get_font_description ()*/
/*void  pango_layout_set_width ()*/
/*int  pango_layout_get_width ()*/
/*void  pango_layout_set_height ()*/
/*int  pango_layout_get_height ()*/
/*void  pango_layout_set_wrap ()*/
/*PangoWrapMode  pango_layout_get_wrap ()*/
/*gboolean  pango_layout_is_wrapped ()*/
/*void  pango_layout_set_ellipsize ()*/
/*PangoEllipsizeMode  pango_layout_get_ellipsize ()*/
/*gboolean  pango_layout_is_ellipsized ()*/
/*void  pango_layout_set_indent ()*/
/*int  pango_layout_get_indent ()*/
/*int  pango_layout_get_spacing ()*/
/*void  pango_layout_set_spacing ()*/
/*void  pango_layout_set_justify ()*/
/*gboolean  pango_layout_get_justify ()*/
/*void  pango_layout_set_auto_dir ()*/
/*gboolean  pango_layout_get_auto_dir ()*/
/*void  pango_layout_set_alignment ()*/
/*PangoAlignment  pango_layout_get_alignment ()*/
/*void  pango_layout_set_tabs ()*/
/*PangoTabArray *  pango_layout_get_tabs ()*/
/*void  pango_layout_set_single_paragraph_mode ()*/
/*gboolean  pango_layout_get_single_paragraph_mode ()*/
/*int  pango_layout_get_unknown_glyphs_count ()*/
/*void  pango_layout_get_log_attrs ()*/
/*const PangoLogAttr *  pango_layout_get_log_attrs_readonly ()*/
/*void  pango_layout_index_to_pos ()*/
/*void  pango_layout_index_to_line_x ()*/
/*gboolean  pango_layout_xy_to_index ()*/
/*void  pango_layout_get_cursor_pos ()*/
/*void  pango_layout_move_cursor_visually ()*/
/*void  pango_layout_get_extents ()*/
/*void  pango_layout_get_pixel_extents ()*/
static int _pango_layout_get_size (lua_State* L) {
    PangoLayout *layout = commonGetAs(L, 1, LayoutName, PangoLayout *);
    int *width = (int *) 0;
    int *height = (int *) 0;
    pango_layout_get_size(layout, width, height);
    return commonPush(L, "ii", width, height);
}
/*void  pango_layout_get_pixel_size ()*/
/*int  pango_layout_get_baseline ()*/
/*int  pango_layout_get_line_count ()*/
/*PangoLayoutLine *  pango_layout_get_line ()*/
/*PangoLayoutLine *  pango_layout_get_line_readonly ()*/
/*GSList *  pango_layout_get_lines ()*/
/*GSList *  pango_layout_get_lines_readonly ()*/
/*PangoLayoutIter *  pango_layout_get_iter ()*/
/*PangoLayoutIter *  pango_layout_iter_copy ()*/
/*void  pango_layout_iter_free ()*/
/*gboolean  pango_layout_iter_next_run ()*/
/*gboolean  pango_layout_iter_next_char ()*/
/*gboolean  pango_layout_iter_next_cluster ()*/
/*gboolean  pango_layout_iter_next_line ()*/
/*gboolean  pango_layout_iter_at_last_line ()*/
/*int  pango_layout_iter_get_index ()*/
/*int  pango_layout_iter_get_baseline ()*/
/*PangoLayoutRun *  pango_layout_iter_get_run ()*/
/*PangoLayoutRun *  pango_layout_iter_get_run_readonly ()*/
/*PangoLayoutLine *  pango_layout_iter_get_line ()*/
/*PangoLayoutLine *  pango_layout_iter_get_line_readonly ()*/
/*PangoLayout *  pango_layout_iter_get_layout ()*/
/*void  pango_layout_iter_get_char_extents ()*/
/*void  pango_layout_iter_get_cluster_extents ()*/
/*void  pango_layout_iter_get_run_extents ()*/
/*void  pango_layout_iter_get_line_yrange ()*/
/*void  pango_layout_iter_get_line_extents ()*/
/*void  pango_layout_iter_get_layout_extents ()*/
/*PangoLayoutLine *  pango_layout_line_ref ()*/
/*void  pango_layout_line_unref ()*/
/*void  pango_layout_line_get_extents ()*/
/*void  pango_layout_line_get_pixel_extents ()*/
/*void  pango_layout_line_index_to_x ()*/
/*gboolean  pango_layout_line_x_to_index ()*/
/*void  pango_layout_line_get_x_ranges ()*/

static int l_layout_gc(lua_State *L) {
	CommonUserdata *udata = commonGetUserdata(L, 1, LayoutName);

	/*if (udata->mustdelete)*/
	/*TODO: count down to zero?*/
	g_object_unref(udata->data);

	return 0;
}

/*TODO: conditonal include*/
#include "pangocairo.c"

const luaL_Reg LayoutMethods[] = {
	{ "setText", _pango_layout_set_text },
	{ "setFontDescription", _pango_layout_set_font_description },
	{ "getSize", _pango_layout_get_size },
	/*pangocairo.c TODO: conditonal include*/
	{ "createFromCairo", _pango_cairo_create_layout },
	{ "updateCairo", _pango_cairo_update_layout },
	{ "showCairo", _pango_cairo_show_layout },
	{ NULL, NULL }
};

const luaL_Reg LayoutMetamethods[] = {
	/*{ "__eq", l_texture_eq },*/
	{ "__gc", l_layout_gc },
	/*{ "__tostring", l_texture_tostring },*/
	{ NULL, NULL }
};

const CommonObject Layout = {
	"PangoLayout",
	LayoutMethods,
	LayoutMetamethods
};
