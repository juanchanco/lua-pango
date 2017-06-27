local pango = require("swig_pango")
local Style = {
    Normal = pango.PANGO_STYLE_NORMAL,
    Oblique = pango.PANGO_STYLE_OBLIQUE,
    Italic = pango.PANGO_STYLE_ITALIC,
}

local Weight = {
    Thin = pango.PANGO_WEIGHT_THIN,
    Ultralight = pango.PANGO_WEIGHT_ULTRALIGHT,
    Light = pango.PANGO_WEIGHT_LIGHT,
    Semilight = pango.PANGO_WEIGHT_SEMILIGHT,
    Book = pango.PANGO_WEIGHT_BOOK,
    Normal = pango.PANGO_WEIGHT_NORMAL,
    Medium = pango.PANGO_WEIGHT_MEDIUM,
    Semibold = pango.PANGO_WEIGHT_SEMIBOLD,
    Bold = pango.PANGO_WEIGHT_BOLD,
    Ultrabold = pango.PANGO_WEIGHT_ULTRABOLD,
    Heavy = pango.PANGO_WEIGHT_HEAVY,
    Ultraheavy = pango.PANGO_WEIGHT_ULTRAHEAVY,
}

local Variant = {
    Normal = pango.PANGO_VARIANT_NORMAL,
    Small_caps = pango.PANGO_VARIANT_SMALL_CAPS,
}

local Stretch = {
    Ultra_condensed = pango.PANGO_STRETCH_ULTRA_CONDENSED,
    Extra_condensed = pango.PANGO_STRETCH_EXTRA_CONDENSED,
    Condensed = pango.PANGO_STRETCH_CONDENSED,
    Semi_condensed = pango.PANGO_STRETCH_SEMI_CONDENSED,
    Normal = pango.PANGO_STRETCH_NORMAL,
    Semi_expanded = pango.PANGO_STRETCH_SEMI_EXPANDED,
    Expanded = pango.PANGO_STRETCH_EXPANDED,
    Extra_expanded = pango.PANGO_STRETCH_EXTRA_EXPANDED,
    Ultra_expanded = pango.PANGO_STRETCH_ULTRA_EXPANDED,
}

local FontMask = {
    Family = pango.PANGO_FONT_MASK_FAMILY,
    Style = pango.PANGO_FONT_MASK_STYLE,
    Variant = pango.PANGO_FONT_MASK_VARIANT,
    Weight = pango.PANGO_FONT_MASK_WEIGHT,
    Stretch = pango.PANGO_FONT_MASK_STRETCH,
    Size = pango.PANGO_FONT_MASK_SIZE,
    Gravity = pango.PANGO_FONT_MASK_GRAVITY,
}

local font_desc_mt = {
  __gc = function(self)
    pango.pango_font_description_free(self)
  end,
  __index = {
    setSize = function(self, size)
      pango.pango_font_description_set_size(self, size)
    end,
    setAbsoluteSize = function(self, size)
      pango.pango_font_description_set_absolute_size(self, size)
    end,
    toString = function(self)
      return pango.pango_font_desc_tostring(self)
    end,
  }
}

local function fontDescriptionFromString(str)
  local desc = pango.pango_font_description_from_string(str)
  pango.setmetatable(desc, font_desc_mt)
  return desc
end

return {
  public = {
    Style = Style,
    Weight = Weight,
    Variant = Variant,
    Stretch = Stretch,
    FontMask = FontMask,
    fontDescriptionFromString = fontDescriptionFromString,
  }
}
