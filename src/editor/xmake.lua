option("editor")
    set_default(false)
    set_showmenu(true)
    set_description("Build editor")
option_end()

if has_config("editor") then
    target("editor")
        set_kind("binary")
        set_group("Executables")
        add_rules("qt.console")
        add_frameworks("QtCore", "QtGui", "QtWidgets")
        add_deps("calculator")
        add_files("**.cpp")
        add_files("*.hpp") -- for Q_OBJECT
        add_headerfiles("**.hpp")
        add_includedirs(".")
        if is_plat("windows") then
            add_cxxflags("/Zc:__cplusplus")
        end
end
