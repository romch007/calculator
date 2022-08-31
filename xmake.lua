add_rules("mode.debug", "mode.release")

set_languages("c++20")

set_rundir("./build/$(plat)_$(arch)_$(mode)")
set_targetdir("./build/$(plat)_$(arch)_$(mode)")

add_requires("fast_float", "fmt")

add_headerfiles("examples/*.calc")

target("calculator")
    set_kind("$(kind)")
    set_group("Librairies")
    add_defines("CALCULATOR_BUILD")
    add_headerfiles("include/(calculator/**.hpp)")
    add_includedirs("include", { public = true })
    add_files("src/calculator/**.cpp")
    add_packages("fast_float", "fmt")

    on_load(function (target)
        if target:kind() == "static" then
            target:add("defines", "CALCULATOR_STATIC", { public = true })
        end
    end)

target("repl")
    set_kind("binary")
    set_group("Executables")
    add_deps("calculator")
    add_files("src/repl/*.cpp")

target("eval")
    set_kind("binary")
    set_group("Executables")
    add_deps("calculator")
    add_files("src/eval/*.cpp")


includes("tests/xmake.lua")
includes("xmake/**.lua")
