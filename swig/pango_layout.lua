local pango = require("swig_pango")

local WrapMode = {
    Word = pango.PANGO_WRAP_WORD,
    Char = pango.PANGO_WRAP_CHAR,
    Word_char = pango.PANGO_WRAP_WORD_CHAR,
}

local EllipsizeMode = {
    None = pango.PANGO_ELLIPSIZE_NONE,
    Start = pango.PANGO_ELLIPSIZE_START,
    Middle = pango.PANGO_ELLIPSIZE_MIDDLE,
    End = pango.PANGO_ELLIPSIZE_END,
}

local Alignment = {
    Left = pango.PANGO_ALIGN_LEFT,
    Center = pango.PANGO_ALIGN_CENTER,
    Right = pango.PANGO_ALIGN_RIGHT,
}

local layout_mt = {
  __gc = function(self)
    -- TODO: add g_object_unref to swig
    --pango.g_object_unref(self)
  end,
  __index = {
    setText = function(self, text)
      --print(string.format("text => %s", text))
      pango.pango_layout_set_text(self, text, #text)
    end,
    setFontDescription = function(self, desc)
      pango.pango_layout_set_font_description(self, desc)
    end,
    getSize = function(self)
      return pango.pango_layout_get_size(self)
    end,
  }
}

local function addMetatable(layout)
  pango.setmetatable(layout, layout_mt)
end



return {
  public = {
    WrapMode = WrapMode,
    EllipsizeMode = EllipsizeMode,
    Alignment = Alignment,
  },
  private = {
    addMetatable = addMetatable,
  }
}
