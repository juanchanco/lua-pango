local Pango = require("Pango")
local FONT_WITH_MANUAL_SIZE = "Times new roman,Sans"
local desc = Pango.fontDescriptionFromString(FONT_WITH_MANUAL_SIZE)
print(desc)
