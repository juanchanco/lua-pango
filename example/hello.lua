local Pango = require("Pango");
local Cairo = require("Cairo");
local RADIUS = 200;
local N_WORDS = 8;
local FONT_WITH_MANUAL_SIZE = "Times new roman,Sans";
local FONT_SIZE = 36;
local DEVICE_DPI = 72;
local TWEAKABLE_SCALE = 0.1;
local G_PI = math.pi;
--local draw_text = function(cr)
  --cairo.cairo_translate (cr, RADIUS / TWEAKABLE_SCALE, RADIUS / TWEAKABLE_SCALE);
  --local layout = pangocairo.pango_cairo_create_layout (cr);
  --pango.pango_layout_set_text (layout, "Test\nسَلام", -1);
  --local desc = pango.pango_font_description_from_string (FONT_WITH_MANUAL_SIZE);
  --pango.pango_font_description_set_absolute_size(desc, FONT_SIZE * DEVICE_DPI * pango.PANGO_SCALE / (72.0 * TWEAKABLE_SCALE));

  --pango.pango_layout_set_font_description (layout, desc);
  --pango.pango_font_description_free (desc);

  --for i = 0, N_WORDS do
    --local angle = (360. * i) / N_WORDS;
    --cairo.cairo_save (cr);
    --local red = (1 + math.cos ((angle - 60) * G_PI / 180.)) / 2;
    --cairo.cairo_set_source_rgb (cr, red, 0, 1.0 - red);

    --cairo.cairo_rotate (cr, angle * G_PI / 180.);
    --pangocairo.pango_cairo_update_layout (cr, layout);

    --local w,_ = pango.pango_layout_get_size (layout);
    --cairo.cairo_move_to (cr,( - (w / pango.PANGO_SCALE) / 2.0) , (- RADIUS)  / TWEAKABLE_SCALE);
    --pangocairo.pango_cairo_show_layout (cr, layout);

    --cairo.cairo_restore (cr);
  --end
--end

--local filename = "test.png"
--local surface = cairo.cairo_image_surface_create (cairo.CAIRO_FORMAT_ARGB32, 2 * RADIUS, 2 * RADIUS);
--local cr = cairo.cairo_create (surface);
--cairo.cairo_scale(cr, 1 * TWEAKABLE_SCALE, 1 * TWEAKABLE_SCALE);

--cairo.cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
--cairo.cairo_paint (cr);
--draw_text (cr);
--cairo.cairo_destroy (cr);

--local _ = cairo.cairo_surface_write_to_png (surface, filename);
--cairo.cairo_surface_destroy (surface);
