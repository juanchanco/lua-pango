local pango = require("swig_pango")
local pangocairo = require("swig_pangocairo")

for k,v in pairs(pango) do
  print(string.format("%s = %s", k, v))
  local mt = getmetatable(v)
  if (mt) then
    for x,y in pairs(mt) do
      print(string.format("  %s = %s", x, y))
    end
  end
end
print("================================================")
for k,v in pairs(pangocairo) do
  print(string.format("%s = %s", k, v))
  local mt = getmetatable(v)
  if (mt) then
    for x,y in pairs(mt) do
      print(string.format("  %s = %s", x, y))
    end
  end
end
