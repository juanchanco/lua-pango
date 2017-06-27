local pangocairo = require("swig_pangocairo")
local pango_layout = require("pango_layout")

local function createPangoLayout(cr)
  local layout = pangocairo.pango_cairo_create_layout(cr)
  pango_layout.private.addMetatable(layout)
  return layout
end

local function updatePangoLayout(cr, layout)
  pangocairo.pango_cairo_update_layout(cr, layout)
end

local function showPangoLayout(cr, layout)
  pangocairo.pango_cairo_show_layout(cr, layout)
end


return {
  public = {
    createPangoLayout = createPangoLayout,
    updatePangoLayout = updatePangoLayout,
    showPangoLayout = showPangoLayout,
  }
}
