add_rules("mode.debug", "mode.release")

set_languages("c++20")

add_requires("fast_float")

target("calculator")
    set_kind("$(kind)")
    add_defines("CALCULATOR_BUILD")
    add_headerfiles("include/(calculator/**.hpp)")
    add_includedirs("include", { public = true })
    add_files("src/calculator/**.cpp")
    add_packages("fast_float")

    on_load(function (target)
        if target:kind() == "static" then
            target:add("defines", "CALCULATOR_STATIC", { public = true })
        end
    end)

target("repl")
    set_kind("binary")
    add_deps("calculator")
    add_files("src/repl/*.cpp")
