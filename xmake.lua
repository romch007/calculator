add_rules("mode.debug", "mode.release")

set_allowedarchs("x64")

set_languages("cxx20")

set_rundir(".")
set_targetdir("./build/$(plat)_$(arch)_$(mode)")

add_requires("fast_float", "fmt")

add_headerfiles("examples/*.calc")

if is_plat("wasm") then
  add_defines("__WASM__")
end

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


includes("tests/xmake.lua")
includes("src/**.lua")
