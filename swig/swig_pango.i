%module swig_pango
%{
 #include <pango/pango.h>
%}
#define G_BEGIN_DECLS
#define G_END_DECLS
#define G_GNUC_CONST
#define G_GNUC_PURE
#define PANGO_DISABLE_DEPRECATED 1
/*%include <typemaps.i>*/
/*%apply SWIGTYPE** OUTPUT { pango_text_extents_t **extents };*/
/*%include <carrays.i>*/
/*%array_functions(pango_glyph_t, glyphs)*/
%import <pango/pango-version-macros.h>
%include <pango/pango-attributes.h>
%include <pango/pango-bidi-type.h>
%include <pango/pango-break.h>
%include <pango/pango-context.h>
%include <pango/pango-coverage.h>
%include <pango/pango-engine.h>
%include <pango/pango-enum-types.h>
%include <pango/pango-features.h>
%include <pango/pango-font.h>
%include <pango/pango-fontmap.h>
%include <pango/pango-fontset.h>
%include <pango/pango-glyph.h>
%include <pango/pango-glyph-item.h>
%include <pango/pango-gravity.h>
%include <pango/pango-item.h>
%include <pango/pango-layout.h>
%include <pango/pango-matrix.h>
%include <pango/pango-renderer.h>
%include <pango/pango-script.h>
%include <pango/pango-tabs.h>
%include <pango/pango-types.h>
/*TODO: different PANGO_DEPRECATED?*/
/*%include <pango/pango-utils.h>*/
%native(setmetatable) int userdata_set_metatable(lua_State *L);
%{
int userdata_set_metatable(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TUSERDATA);
    luaL_checktype(L, 2, LUA_TTABLE);
    lua_pushvalue(L,2);
    lua_setmetatable(L,1);
    return 0;
}
%}
%inline %{
%}
