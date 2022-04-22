add_rules("mode.debug", "mode.release")

target("calculator")
    set_kind("binary")
    add_includedirs("include")
    add_headerfiles("include/*.hpp")
    add_files("src/*.cpp")
