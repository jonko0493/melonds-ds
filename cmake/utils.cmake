function(dump_cmake_variables)
    get_cmake_property(_variableNames VARIABLES)
    list(SORT _variableNames)
    foreach (_variableName ${_variableNames})
        if (ARGV0)
            unset(MATCHED)
            string(REGEX MATCH ${ARGV0} MATCHED ${_variableName})
            if (NOT MATCHED)
                continue()
            endif ()
        endif ()
        message(DEBUG "${_variableName}=${${_variableName}}")
    endforeach ()
endfunction()

function(embed_file type source_file destination_directory)
    if (type STREQUAL TEXT)
        if (NOT EXISTS source_file)
            message(SEND_ERROR "Source file ${source_file} doesn't exist.")
            return()
        elseif (IS_DIRECTORY source_file)
            message(SEND_ERROR "Source path ${source_file} exists but is a directory.")
            return()
        endif()

        file(MAKE_DIRECTORY destination_directory)
        file(READ source_contents)

        set(generated_header "

        ")
    elseif (type STREQUAL BINARY)
        message(SEND_ERROR "BINARY is not yet implemented.")
    else ()
        message(SEND_ERROR "Expected a type of TEXT or BINARY, got ${type}")
    endif ()
endfunction()

