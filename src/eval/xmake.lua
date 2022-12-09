option("eval")
    set_default(true)
    set_showmenu(true)
    set_description("Build eval")
option_end()

if has_config("eval") then
    add_requires("cxxopts")

    target("eval")
        set_kind("binary")
        set_group("Executables")
        add_deps("calculator")
        add_packages("cxxopts")
        add_files("main.cpp")
end
