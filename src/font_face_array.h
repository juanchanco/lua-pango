#ifndef _FONT_FACE_ARRAY_H_
#define _FONT_FACE_ARRAY_H_

#include <common/common.h>

int push_new_font_face_array(lua_State *L, PangoFontFace **families, int length);
#define FontFaceArrayName	FontFaceArray.name

extern const CommonObject FontFaceArray;
#endif /* !_FONT_FACE_ARRAY_H_ */
