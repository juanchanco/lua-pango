%module swig_pangocairo
%{
 #include <pango/pangocairo.h>
%}
#define G_BEGIN_DECLS
#define G_END_DECLS
#define G_GNUC_CONST
#define PANGO_DISABLE_DEPRECATED 1
#define __GLIB_GOBJECT_H_INSIDE__
%import <pango/pango-version-macros.h>
/*%include <typemaps.i>*/
/*%apply SWIGTYPE** OUTPUT { pango_text_extents_t **extents };*/
/*%include <carrays.i>*/
/*%array_functions(pango_glyph_t, glyphs)*/
/*%import <glib.h>*/
/*%import <gobject/gobject.h>*/
%include <pango/pangocairo.h>
