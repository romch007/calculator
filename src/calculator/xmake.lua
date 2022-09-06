add_requires("fast_float", "fmt")

add_headerfiles("examples/*.calc")

target("calculator")
    set_kind("$(kind)")
    set_group("Librairies")
    add_defines("CALCULATOR_BUILD")
    add_headerfiles("../../include/(calculator/**.hpp)")
    add_includedirs("../../include", { public = true })
    add_files("**.cpp")
    add_packages("fast_float", "fmt")

    on_load(function (target)
        if target:kind() == "static" then
            target:add("defines", "CALCULATOR_STATIC", { public = true })
        end
    end)
