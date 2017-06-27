local pangocairo = require("swig_pangocairo")
local layout = require("pango_layout")

local function createPangoLayout(cr)
  local layout = pangocairo.pango_cairo_create_layout(cr)
  layout.private.addMetatable(layout)
  return layout
end


return {
  public = {
    createPangoLayout = createPangoLayout,
  }
}
