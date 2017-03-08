
--------------------------------
-- @module ZQPlistManage
-- @parent_module zq

--------------------------------
-- 
-- @function [parent=#ZQPlistManage] alias 
-- @param self
-- @param #cc.Value plist
-- @param #string key
-- @return ZQPlistManage#ZQPlistManage self (return value: zq.ZQPlistManage)
        
--------------------------------
-- 
-- @function [parent=#ZQPlistManage] clear 
-- @param self
-- @return ZQPlistManage#ZQPlistManage self (return value: zq.ZQPlistManage)
        
--------------------------------
-- 
-- @function [parent=#ZQPlistManage] cache 
-- @param self
-- @param #string filename
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Converts the contents of a file to a ValueVector.<br>
-- param filename The filename of the file to gets content.<br>
-- return ValueMap of the file contents.<br>
-- note This method is used internally.
-- @function [parent=#ZQPlistManage] load_array 
-- @param self
-- @param #string filename
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
--  Converts the contents of a file to a Value.<br>
-- This method is used internally.
-- @function [parent=#ZQPlistManage] read_text 
-- @param self
-- @param #string text
-- @return Value#Value ret (return value: cc.Value)
        
--------------------------------
-- 
-- @function [parent=#ZQPlistManage] text_dict 
-- @param self
-- @param #string text
-- @return map_table#map_table ret (return value: map_table)
        
--------------------------------
-- 
-- @function [parent=#ZQPlistManage] exist 
-- @param self
-- @param #string filename
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Converts the contents of a file to a ValueMap.<br>
-- param filename The filename of the file to gets content.<br>
-- return ValueMap of the file contents.<br>
-- note This method is used internally.
-- @function [parent=#ZQPlistManage] load_dict 
-- @param self
-- @param #string filename
-- @return map_table#map_table ret (return value: map_table)
        
--------------------------------
-- Converts the contents of a file to a ValueVector.<br>
-- param filename The filename of the file to gets content.<br>
-- return ValueMap of the file contents.<br>
-- note This method is used internally.
-- @function [parent=#ZQPlistManage] read_file 
-- @param self
-- @param #string filename
-- @return Value#Value ret (return value: cc.Value)
        
--------------------------------
--  Converts the contents of a file to a ValueVector.<br>
-- This method is used internally.
-- @function [parent=#ZQPlistManage] text_array 
-- @param self
-- @param #string text
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- 
-- @function [parent=#ZQPlistManage] getInstance 
-- @param self
-- @return ZQPlistManage#ZQPlistManage ret (return value: zq.ZQPlistManage)
        
return nil
