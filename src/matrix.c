#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <pango/pango.h>
#include "common/common.h"
#include "common/table.h"

#include "matrix.h"

static int _pango_units_to_double (lua_State* L) {
    int i = luaL_checkinteger(L, 1);
    double d = pango_units_to_double(i);
    lua_pushnumber(L, d);
    return 1;
}
static int _pango_units_from_double (lua_State* L) {
    double d = luaL_checknumber(L, 1);
    int i = pango_units_from_double(d);
    lua_pushinteger(L, i);
    return 1;
}
/*void 	pango_extents_to_pixels ()*/
static int _pango_matrix_copy(lua_State *L) {
    PangoMatrix* matrix = commonGetAs(L, 1, MatrixName, PangoMatrix *);
    PangoMatrix* copy = pango_matrix_copy(matrix);

    return commonPush(L, "p", MatrixName, copy);
}
static int _pango_matrix_free(lua_State *L) {
    PangoMatrix* matrix = commonGetAs(L, 1, MatrixName, PangoMatrix *);
    pango_matrix_free(matrix);

    return 0;
}

/*TODO: many of these can take a NULL matrix. is that really usefull?*/
/*void 	pango_matrix_translate ()*/
/*void 	pango_matrix_scale ()*/
/*void 	pango_matrix_rotate ()*/
/*void 	pango_matrix_concat ()*/
/*void 	pango_matrix_transform_point ()*/
/*void 	pango_matrix_transform_distance ()*/
/*void 	pango_matrix_transform_rectangle ()*/
/*void 	pango_matrix_transform_pixel_rectangle ()*/
/*double 	pango_matrix_get_font_scale_factor ()*/
/*void 	pango_matrix_get_font_scale_factors ()*/

const luaL_Reg MatrixFunctions[] = {
    { "unitsToDouble", _pango_units_to_double },
    { "unitsFromDouble", _pango_units_from_double },
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { "copy", _pango_matrix_copy },
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__gc", _pango_matrix_free },
    { NULL, NULL }
};

const CommonObject Matrix = {
    "Pango.Matrix",
    methods,
    metamethods
};
