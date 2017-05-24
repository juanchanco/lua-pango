#ifndef _FONT_DESC_H_
#define _FONT_DESC_H_

#include <common/common.h>

#define FontDescriptionName	FontDescription.name

extern const luaL_Reg FontDescriptionFunctions[];

extern const CommonObject FontDescription;

extern const CommonEnum LuaPangoStyle[];
extern const CommonEnum LuaPangoWeight[];
extern const CommonEnum LuaPangoVariant[];
extern const CommonEnum LuaPangoStretch[];
extern const CommonEnum LuaPangoFontMask[];
#endif /* !_FONT_DESC_H_ */

