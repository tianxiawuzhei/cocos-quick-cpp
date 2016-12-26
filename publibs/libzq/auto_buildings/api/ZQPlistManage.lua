
--------------------------------
-- @module ZQPlistManage
-- @parent_module zq

--------------------------------
-- Converts the contents of a file to a ValueVector.<br>
-- param filename The filename of the file to gets content.<br>
-- return ValueMap of the file contents.<br>
-- note This method is used internally.
-- @function [parent=#ZQPlistManage] getValueFromFile 
-- @param self
-- @param #string filename
-- @return Value#Value ret (return value: cc.Value)
        
--------------------------------
--  Converts the contents of a file to a ValueMap.<br>
-- This method is used internally.
-- @function [parent=#ZQPlistManage] getDictFromText 
-- @param self
-- @param #string text
-- @return map_table#map_table ret (return value: map_table)
        
--------------------------------
-- Converts the contents of a file to a ValueMap.<br>
-- param filename The filename of the file to gets content.<br>
-- return ValueMap of the file contents.<br>
-- note This method is used internally.
-- @function [parent=#ZQPlistManage] getDictFromFile 
-- @param self
-- @param #string filename
-- @return map_table#map_table ret (return value: map_table)
        
--------------------------------
--  Converts the contents of a file to a ValueVector.<br>
-- This method is used internally.
-- @function [parent=#ZQPlistManage] getArrayFromText 
-- @param self
-- @param #string text
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- Converts the contents of a file to a ValueVector.<br>
-- param filename The filename of the file to gets content.<br>
-- return ValueMap of the file contents.<br>
-- note This method is used internally.
-- @function [parent=#ZQPlistManage] getArrayFromFile 
-- @param self
-- @param #string filename
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
--  Converts the contents of a file to a Value.<br>
-- This method is used internally.
-- @function [parent=#ZQPlistManage] getValueFromText 
-- @param self
-- @param #string text
-- @return Value#Value ret (return value: cc.Value)
        
--------------------------------
-- 
-- @function [parent=#ZQPlistManage] getInstance 
-- @param self
-- @return ZQPlistManage#ZQPlistManage ret (return value: zq.ZQPlistManage)
        
return nil
