#ifndef _FONT_FAMILY_ARRAY_H_
#define _FONT_FAMILY_ARRAY_H_

#include <common/common.h>

int push_new_font_family_array(lua_State *L, PangoFontFamily ***families, int length);
#define FontFamilyArrayName	FontFamilyArray.name

extern const CommonObject FontFamilyArray;
#endif /* !_FONT_FAMILY_ARRAY_H_ */
