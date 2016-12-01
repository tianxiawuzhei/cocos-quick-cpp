
--------------------------------
-- @module ZQJsonManage
-- @parent_module zq

--------------------------------
-- Converts the contents of a file to a ValueVector.<br>
-- param filename The filename of the file to gets content.<br>
-- return ValueMap of the file contents.<br>
-- note This method is used internally.
-- @function [parent=#ZQJsonManage] getValueFromFile 
-- @param self
-- @param #string filename
-- @return Value#Value ret (return value: cc.Value)
        
--------------------------------
--  Converts the contents of a file to a ValueMap.<br>
-- This method is used internally.
-- @function [parent=#ZQJsonManage] getDictFromText 
-- @param self
-- @param #string text
-- @return map_table#map_table ret (return value: map_table)
        
--------------------------------
-- Converts the contents of a file to a ValueMap.<br>
-- param filename The filename of the file to gets content.<br>
-- return ValueMap of the file contents.<br>
-- note This method is used internally.
-- @function [parent=#ZQJsonManage] getDictFromFile 
-- @param self
-- @param #string filename
-- @return map_table#map_table ret (return value: map_table)
        
--------------------------------
--  Converts the contents of a file to a ValueVector.<br>
-- This method is used internally.
-- @function [parent=#ZQJsonManage] getArrayFromText 
-- @param self
-- @param #string text
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- Converts the contents of a file to a ValueVector.<br>
-- param filename The filename of the file to gets content.<br>
-- return ValueMap of the file contents.<br>
-- note This method is used internally.
-- @function [parent=#ZQJsonManage] getArrayFromFile 
-- @param self
-- @param #string filename
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
--  Converts the contents of a file to a Value.<br>
-- This method is used internally.
-- @function [parent=#ZQJsonManage] getValueFromText 
-- @param self
-- @param #string text
-- @return Value#Value ret (return value: cc.Value)
        
--------------------------------
-- 
-- @function [parent=#ZQJsonManage] getInstance 
-- @param self
-- @return ZQJsonManage#ZQJsonManage ret (return value: zq.ZQJsonManage)
        
return nil
