option("tests")
    set_default(false)
    set_showmenu(true)
    set_description("Build unit tests")
option_end()

if has_config("tests") then
    add_requires("catch2 3")

    target("tests")
        set_kind("binary")
        set_group("Tests")
        add_files("main.cpp")
        add_files("src/**.cpp")

        add_deps("calculator")
        add_packages("catch2")
end
