add_rules("mode.debug", "mode.release")

set_languages("cxx20")

set_rundir("./build/$(plat)_$(arch)_$(mode)")
set_targetdir("./build/$(plat)_$(arch)_$(mode)")


includes("tests/xmake.lua")
includes("src/**.lua")
includes("xmake/**.lua")
