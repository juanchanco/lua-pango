local pango = require("pango")
local FONT_WITH_MANUAL_SIZE = "Times new roman,Sans"
local desc = pango.Font.fontDescriptionFromString(FONT_WITH_MANUAL_SIZE)
print(desc)
