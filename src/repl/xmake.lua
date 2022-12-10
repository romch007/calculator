option("repl")
    set_default(true)
    set_showmenu(true)
    set_description("Build REPL")
option_end()

if has_config("repl") then
    target("repl")
        set_kind("binary")
        set_basename("calculator-repl")
        set_group("Executables")
        add_deps("calculator")
        add_files("main.cpp")
end
