
--------------------------------
-- @module ZQFileManage
-- @parent_module zq

--------------------------------
-- Checks whether a file exists.<br>
-- note If a relative path was passed in, it will be inserted a default root path at the beginning.<br>
-- param filename The path of the file, it could be a relative or absolute path.<br>
-- return True if the file exists, false if not.
-- @function [parent=#ZQFileManage] isFileExist 
-- @param self
-- @param #string filename
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] file_string 
-- @param self
-- @param #string filename
-- @return string#string ret (return value: string)
        
--------------------------------
-- Removes a directory.<br>
-- param dirPath  The full path of the directory, it must be an absolute path.<br>
-- return True if the directory have been removed successfully, false if not.
-- @function [parent=#ZQFileManage] removeDirectory 
-- @param self
-- @param #string dirPath
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] prepare 
-- @param self
-- @return ZQFileManage#ZQFileManage self (return value: zq.ZQFileManage)
        
--------------------------------
-- Retrieve the file size.<br>
-- note If a relative path was passed in, it will be inserted a default root path at the beginning.<br>
-- param filepath The path of the file, it could be a relative or absolute path.<br>
-- return The file size.
-- @function [parent=#ZQFileManage] getFileSize 
-- @param self
-- @param #string filepath
-- @return long#long ret (return value: long)
        
--------------------------------
-- Removes a file.<br>
-- param filepath The full path of the file, it must be an absolute path.<br>
-- return True if the file have been removed successfully, false if not.
-- @function [parent=#ZQFileManage] removeFile 
-- @param self
-- @param #string filepath
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Renames a file under the given directory.<br>
-- param oldfullpath  The current fullpath of the file. Includes path and name.<br>
-- param newfullpath  The new fullpath of the file. Includes path and name.<br>
-- return True if the file have been renamed successfully, false if not.
-- @function [parent=#ZQFileManage] renameFile 
-- @param self
-- @param #string oldfullpath
-- @param #string newfullpath
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Gets string from a file.
-- @function [parent=#ZQFileManage] getStringFromFile 
-- @param self
-- @param #string filename
-- @return string#string ret (return value: string)
        
--------------------------------
-- Add search path.<br>
-- since v2.1
-- @function [parent=#ZQFileManage] addSearchPath 
-- @param self
-- @param #string path
-- @param #bool front
-- @return ZQFileManage#ZQFileManage self (return value: zq.ZQFileManage)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] load_disk 
-- @param self
-- @param #string filename
-- @return string#string ret (return value: string)
        
--------------------------------
-- Creates a directory.<br>
-- param dirPath The path of the directory, it must be an absolute path.<br>
-- return True if the directory have been created successfully, false if not.
-- @function [parent=#ZQFileManage] createDirectory 
-- @param self
-- @param #string dirPath
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] load_file 
-- @param self
-- @param #string filename
-- @return string#string ret (return value: string)
        
--------------------------------
-- Gets the writable path.<br>
-- return  The path that can be write/read a file in
-- @function [parent=#ZQFileManage] getWritablePath 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] url_for_file 
-- @param self
-- @param #string filename
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] dir_exist 
-- @param self
-- @param #string path
-- @param #bool create
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] file_exist 
-- @param self
-- @param #string path
-- @param #string md5
-- @param #bool remove_if_fail
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] create_folder 
-- @param self
-- @param #string path
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] getInstance 
-- @param self
-- @return ZQFileManage#ZQFileManage ret (return value: zq.ZQFileManage)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] url_for_res 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] dirname_of_path 
-- @param self
-- @param #string path
-- @param #bool with_slash
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] url_for_code 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] append_file 
-- @param self
-- @param #string path
-- @param #unsigned char data
-- @param #unsigned int size
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] basename_of_path 
-- @param self
-- @param #string path
-- @param #bool with_ext
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] temp_path 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] set_url_for_res 
-- @param self
-- @param #string url
-- @return ZQFileManage#ZQFileManage self (return value: zq.ZQFileManage)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] extname_of_path 
-- @param self
-- @param #string path
-- @param #bool with_dot
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] log_path 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] write_file 
-- @param self
-- @param #string path
-- @param #unsigned char data
-- @param #unsigned int size
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] cache_path 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] file_size 
-- @param self
-- @param #string path
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] rename_file 
-- @param self
-- @param #string old_path
-- @param #string new_path
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] rebuild_folder 
-- @param self
-- @param #string path
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] remove_file 
-- @param self
-- @param #string path
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZQFileManage] set_url_for_code 
-- @param self
-- @param #string url
-- @return ZQFileManage#ZQFileManage self (return value: zq.ZQFileManage)
        
return nil
