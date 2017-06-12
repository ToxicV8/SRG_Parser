#pragma once
#include <string>
#include "SRG_File.h"

class SRG_Utilities
{
public:

    static std::string get_obfuscated_method_name( std::string class_name, std::string function_name, SRG_File& file )
    {
        for( size_t pos = class_name.find( '.' ); pos != std::string::npos; pos = class_name.find( '.' ) ) {
            class_name.replace( pos, 1, "/" );
            pos += 1;
        }

        for( std::vector<SRG_Method>::const_iterator iter = file.methods.cbegin(); iter != file.methods.cend(); ++iter ) {
            
            std::string deobfuscated_class = iter->function_name_deobf.substr( 0, iter->function_name_deobf.find_last_of( '/' ) );
            std::string deobfuscated_method = iter->function_name_deobf.substr( iter->function_name_deobf.find_last_of( '/' ) + 1 );

            if( deobfuscated_class == class_name && deobfuscated_method == function_name ) {
                return iter->function_name_obf.substr( iter->function_name_obf.find_last_of( '/' ) + 1 );
            }
        }

        return "";
    }

    static std::string get_obfuscated_field_name( std::string class_name, std::string field_name, SRG_File& file )
    {
        for( size_t pos = class_name.find( '.' ); pos != std::string::npos; pos = class_name.find( '.' ) ) {
            class_name.replace( pos, 1, "/" );
            pos += 1;
        }

        for( std::vector<SRG_Field>::const_iterator iter = file.fields.cbegin(); iter != file.fields.cend(); ++iter ) {

            std::string deobfuscated_class = iter->field_name_deobf.substr( 0, iter->field_name_deobf.find_last_of( '/' ) );
            std::string deobfuscated_field = iter->field_name_deobf.substr( iter->field_name_deobf.find_last_of( '/' ) + 1 );

            if( deobfuscated_class == class_name && deobfuscated_field == field_name ) {
                return iter->field_name_obf.substr( iter->field_name_obf.find_last_of( '/' ) + 1 );
            }
        }

        return "";
    }

    static SRG_Field get_field_by_name( std::string class_name, std::string field_name, SRG_File& file )
    {
        for( size_t pos = class_name.find( '.' ); pos != std::string::npos; pos = class_name.find( '.' ) ) {
            class_name.replace( pos, 1, "/" );
            pos += 1;
        }

        for( std::vector<SRG_Field>::iterator iter = file.fields.begin(); iter != file.fields.end(); ++iter ) {

            std::string deobfuscated_class = iter->field_name_deobf.substr( 0, iter->field_name_deobf.find_last_of( '/' ) );
            std::string deobfuscated_method = iter->field_name_deobf.substr( iter->field_name_deobf.find_last_of( '/' ) + 1 );

            if( deobfuscated_class == class_name && deobfuscated_method == field_name ) {
                return *iter;
            }
        }

        return SRG_Field();
    }

    static SRG_Method get_method_by_name( std::string class_name, std::string function_name, SRG_File& file )
    {
        for( size_t pos = class_name.find( '.' ); pos != std::string::npos; pos = class_name.find( '.' ) ) {
            class_name.replace( pos, 1, "/" );
            pos += 1;
        }

        for( std::vector<SRG_Method>::iterator iter = file.methods.begin(); iter != file.methods.end(); ++iter ) {

            std::string deobfuscated_class = iter->function_name_deobf.substr( 0, iter->function_name_deobf.find_last_of( '/' ) );
            std::string deobfuscated_method = iter->function_name_deobf.substr( iter->function_name_deobf.find_last_of( '/' ) + 1 );

            if( deobfuscated_class == class_name && deobfuscated_method == function_name ) {
                return *iter;
            }
        }

        return SRG_Method();
    }

    static std::string get_obfuscated_class_name( std::string name, SRG_File& file )
    {
        for( size_t pos = name.find( '.' ); pos != std::string::npos; pos = name.find( '.' ) ) {
            name.replace( pos, 1, "/" );
            pos += 1;
        }

        for( std::vector<SRG_Class>::const_iterator iter = file.classes.cbegin(); iter != file.classes.cend(); ++iter ) {
            if( iter->class_name_deobf == name )
                return iter->class_name_obf;
        }

        return "";
    }
};