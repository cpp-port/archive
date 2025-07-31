cmake_minimum_required(VERSION 3.16)
project(archive C)

#set(VERSION "1.2.11")

#option(ASM686 "Enable building i686 assembly implementation")
#option(AMD64 "Enable building amd64 assembly implementation")

#set(INSTALL_BIN_DIR "${CMAKE_INSTALL_PREFIX}/bin" CACHE PATH "Installation directory for executables")
#set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib" CACHE PATH "Installation directory for libraries")
#set(INSTALL_INC_DIR "${CMAKE_INSTALL_PREFIX}/include" CACHE PATH "Installation directory for headers")
#set(INSTALL_MAN_DIR "${CMAKE_INSTALL_PREFIX}/share/man" CACHE PATH "Installation directory for manual pages")
#set(INSTALL_PKGCONFIG_DIR "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" CACHE PATH "Installation directory for pkgconfig (.pc) files")

#include(CheckTypeSize)
#include(CheckFunctionExists)
#include(CheckIncludeFile)
#include(CheckCSourceCompiles)
#enable_testing()

if(MSVC)
    #set(CMAKE_DEBUG_POSTFIX "d")
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
endif()


#set(ZLIB_PC ${CMAKE_CURRENT_BINARY_DIR}/zlib.pc)
#configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/zlib.pc.cmakein
#		${ZLIB_PC} @ONLY)
#configure_file(	${CMAKE_CURRENT_SOURCE_DIR}/zconf.h.cmakein
#		${CMAKE_CURRENT_BINARY_DIR}/zconf.h @ONLY)
#include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR})


#set(IDN_PUBLIC_HDRS
 #   ${PROJECT_NAME}/idna.h
#)

#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)



set(IDN_PRIVATE_HDRS
        #config.h
        lib/tld.h
)

set(ARCHIVE_SRCS
        archive/libarchive/archive.h
        archive/libarchive/archive_acl.c
        archive/libarchive/archive_acl_private.h
        archive/libarchive/archive_blake2.h
        archive/libarchive/archive_blake2_impl.h
        archive/libarchive/archive_blake2s_ref.c
        archive/libarchive/archive_blake2sp_ref.c
        archive/libarchive/archive_check_magic.c
        archive/libarchive/archive_cmdline.c
        archive/libarchive/archive_cmdline_private.h
        archive/libarchive/archive_crc32.h
        archive/libarchive/archive_cryptor.c
        archive/libarchive/archive_cryptor_private.h
        archive/libarchive/archive_digest.c
        archive/libarchive/archive_digest_private.h
        archive/libarchive/archive_disk_acl_darwin.c
        archive/libarchive/archive_disk_acl_freebsd.c
        archive/libarchive/archive_disk_acl_linux.c
        archive/libarchive/archive_disk_acl_sunos.c
        archive/libarchive/archive_endian.h
        archive/libarchive/archive_entry.3
        archive/libarchive/archive_entry.c
        archive/libarchive/archive_entry.h
        archive/libarchive/archive_entry_acl.3
        archive/libarchive/archive_entry_copy_bhfi.c
        archive/libarchive/archive_entry_copy_stat.c
        archive/libarchive/archive_entry_link_resolver.c
        archive/libarchive/archive_entry_locale.h
        archive/libarchive/archive_entry_private.h
        archive/libarchive/archive_entry_sparse.c
        archive/libarchive/archive_entry_stat.c
        archive/libarchive/archive_entry_strmode.c
        archive/libarchive/archive_entry_xattr.c
        archive/libarchive/archive_hmac.c
        archive/libarchive/archive_hmac_private.h
        archive/libarchive/archive_match.c
        archive/libarchive/archive_openssl_evp_private.h
        archive/libarchive/archive_openssl_hmac_private.h
        archive/libarchive/archive_options.c
        archive/libarchive/archive_options_private.h
        archive/libarchive/archive_pack_dev.c
        archive/libarchive/archive_pack_dev.h
        archive/libarchive/archive_parse_date.c
        archive/libarchive/archive_pathmatch.c
        archive/libarchive/archive_pathmatch.h
        archive/libarchive/archive_platform.h
        archive/libarchive/archive_platform_acl.h
        archive/libarchive/archive_platform_xattr.h
        archive/libarchive/archive_ppmd7.c
        archive/libarchive/archive_ppmd7_private.h
        archive/libarchive/archive_ppmd8.c
        archive/libarchive/archive_ppmd8_private.h
        archive/libarchive/archive_ppmd_private.h
        archive/libarchive/archive_private.h
        archive/libarchive/archive_random.c
        archive/libarchive/archive_random_private.h
        archive/libarchive/archive_rb.c
        archive/libarchive/archive_rb.h
        archive/libarchive/archive_read.c
        archive/libarchive/archive_read_add_passphrase.c
        archive/libarchive/archive_read_append_filter.c
        archive/libarchive/archive_read_data_into_fd.c
        archive/libarchive/archive_read_disk_entry_from_file.c
        archive/libarchive/archive_read_disk_posix.c
        archive/libarchive/archive_read_disk_private.h
        archive/libarchive/archive_read_disk_set_standard_lookup.c
        archive/libarchive/archive_read_disk_windows.c
        archive/libarchive/archive_read_extract.c
        archive/libarchive/archive_read_extract2.c
        archive/libarchive/archive_read_open_fd.c
        archive/libarchive/archive_read_open_file.c
        archive/libarchive/archive_read_open_filename.c
        archive/libarchive/archive_read_open_memory.c
        archive/libarchive/archive_read_private.h
        archive/libarchive/archive_read_set_format.c
        archive/libarchive/archive_read_set_options.c
        archive/libarchive/archive_read_support_filter_all.c
        archive/libarchive/archive_read_support_filter_by_code.c
        archive/libarchive/archive_read_support_filter_bzip2.c
        archive/libarchive/archive_read_support_filter_compress.c
        archive/libarchive/archive_read_support_filter_grzip.c
        archive/libarchive/archive_read_support_filter_gzip.c
        archive/libarchive/archive_read_support_filter_lrzip.c
        archive/libarchive/archive_read_support_filter_lz4.c
        archive/libarchive/archive_read_support_filter_lzop.c
        archive/libarchive/archive_read_support_filter_none.c
        archive/libarchive/archive_read_support_filter_program.c
        archive/libarchive/archive_read_support_filter_rpm.c
        archive/libarchive/archive_read_support_filter_uu.c
        archive/libarchive/archive_read_support_filter_xz.c
        archive/libarchive/archive_read_support_filter_zstd.c
        archive/libarchive/archive_read_support_format_7zip.c
        archive/libarchive/archive_read_support_format_all.c
        archive/libarchive/archive_read_support_format_ar.c
        archive/libarchive/archive_read_support_format_by_code.c
        archive/libarchive/archive_read_support_format_cab.c
        archive/libarchive/archive_read_support_format_cpio.c
        archive/libarchive/archive_read_support_format_empty.c
        archive/libarchive/archive_read_support_format_iso9660.c
        archive/libarchive/archive_read_support_format_lha.c
        archive/libarchive/archive_read_support_format_mtree.c
        archive/libarchive/archive_read_support_format_rar.c
        archive/libarchive/archive_read_support_format_rar5.c
        archive/libarchive/archive_read_support_format_raw.c
        archive/libarchive/archive_read_support_format_tar.c
        archive/libarchive/archive_read_support_format_warc.c
        archive/libarchive/archive_read_support_format_xar.c
        archive/libarchive/archive_read_support_format_zip.c
        archive/libarchive/archive_string.c
        archive/libarchive/archive_string.h
        archive/libarchive/archive_string_composition.h
        archive/libarchive/archive_string_sprintf.c
        archive/libarchive/archive_time.c
        archive/libarchive/archive_time_private.h
        archive/libarchive/archive_util.c
        archive/libarchive/archive_version_details.c
        archive/libarchive/archive_virtual.c
        archive/libarchive/archive_windows.c
        archive/libarchive/archive_windows.h
        archive/libarchive/archive_write.c
        archive/libarchive/archive_write_add_filter.c
        archive/libarchive/archive_write_add_filter_b64encode.c
        archive/libarchive/archive_write_add_filter_by_name.c
        archive/libarchive/archive_write_add_filter_bzip2.c
        archive/libarchive/archive_write_add_filter_compress.c
        archive/libarchive/archive_write_add_filter_grzip.c
        archive/libarchive/archive_write_add_filter_gzip.c
        archive/libarchive/archive_write_add_filter_lrzip.c
        archive/libarchive/archive_write_add_filter_lz4.c
        archive/libarchive/archive_write_add_filter_lzop.c
        archive/libarchive/archive_write_add_filter_none.c
        archive/libarchive/archive_write_add_filter_program.c
        archive/libarchive/archive_write_add_filter_uuencode.c
        archive/libarchive/archive_write_add_filter_xz.c
        archive/libarchive/archive_write_add_filter_zstd.c
        archive/libarchive/archive_write_disk_posix.c
        archive/libarchive/archive_write_disk_private.h
        archive/libarchive/archive_write_disk_set_standard_lookup.c
        archive/libarchive/archive_write_disk_windows.c
        archive/libarchive/archive_write_open_fd.c
        archive/libarchive/archive_write_open_file.c
        archive/libarchive/archive_write_open_filename.c
        archive/libarchive/archive_write_open_memory.c
        archive/libarchive/archive_write_private.h
        archive/libarchive/archive_write_set_format.c
        archive/libarchive/archive_write_set_format_7zip.c
        archive/libarchive/archive_write_set_format_ar.c
        archive/libarchive/archive_write_set_format_by_name.c
        archive/libarchive/archive_write_set_format_cpio.c
        archive/libarchive/archive_write_set_format_cpio_binary.c
        archive/libarchive/archive_write_set_format_cpio_newc.c
        archive/libarchive/archive_write_set_format_cpio_odc.c
        archive/libarchive/archive_write_set_format_filter_by_ext.c
        archive/libarchive/archive_write_set_format_gnutar.c
        archive/libarchive/archive_write_set_format_iso9660.c
        archive/libarchive/archive_write_set_format_mtree.c
        archive/libarchive/archive_write_set_format_pax.c
        archive/libarchive/archive_write_set_format_private.h
        archive/libarchive/archive_write_set_format_raw.c
        archive/libarchive/archive_write_set_format_shar.c
        archive/libarchive/archive_write_set_format_ustar.c
        archive/libarchive/archive_write_set_format_v7tar.c
        archive/libarchive/archive_write_set_format_warc.c
        archive/libarchive/archive_write_set_format_xar.c
        archive/libarchive/archive_write_set_format_zip.c
        archive/libarchive/archive_write_set_options.c
        archive/libarchive/archive_write_set_passphrase.c
        archive/libarchive/archive_xxhash.h
        archive/libarchive/config_freebsd.h
        archive/libarchive/filter_fork.h
        archive/libarchive/filter_fork_posix.c
        archive/libarchive/libarchive.3
        archive/libarchive/xxhash.c
)

if(${WIN32})

    list(APPEND ARCHIVE_SRCS
            archive/libarchive/filter_fork_windows.c
    )
    endif()

add_library(${PROJECT_NAME} SHARED ${ARCHIVE_SRCS} ${ARCHIVE_PUBLIC_HDRS} ${ARCHIVE_PRIVATE_HDRS})
add_library(static_${PROJECT_NAME} STATIC ${ARCHIVE_SRCS} ${ARCHIVE_PUBLIC_HDRS} ${ARCHIVE_PRIVATE_HDRS})


target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_CONFIG_H )
target_compile_definitions(static_${PROJECT_NAME} PRIVATE HAVE_CONFIG_H )

target_link_libraries(${PROJECT_NAME} PRIVATE iconv)

#set_target_properties(${PROJECT_NAME} PROPERTIES DEFINE_SYMBOL IDN_DLL)


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${PLATFORM_NAME}/configuration/${PROJECT_NAME})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${PLATFORM_NAME}/include)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})

