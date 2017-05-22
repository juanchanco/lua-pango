find_package(Cairo REQUIRED)
#find_package(GLIB REQUIRED)

set(
	PANGOCAIRO_SOURCES
	src/pangocairo.c
)

include_directories(
	"${Pango_SOURCE_DIR}/src"
	${CAIRO_INCLUDE_DIRS}
	${GLIB_INCLUDE_DIRS}
	${PANGO_INCLUDE_DIRS}
)

add_library(
	PangoCairo
	MODULE
	${PANGOCAIRO_SOURCES}
)

set_target_properties(
	PangoCairo
	PROPERTIES
	PREFIX ""
)

target_link_libraries(
	PangoCairo
	common
	${CAIRO_LIBRARIES}
	${GLIB_LIBRARIES}
	${PANGO_LIBRARIES}
)

install(
	TARGETS PangoCairo
	DESTINATION ${LUA_LIBDIR}
)
