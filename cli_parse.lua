local M = {}

M.cli_parse = function (arg_list)
	local flags = {}
	local regular = {}

	local is_flag = function(s)
		if #s < 2 then return false end
		return s:sub(1,1) == '-'
	end

	local make_flag = function(s)
		local p = s:find(':')
		local flag = nil
		if not p then
			flag = {s:sub(2, p), true}
		else
			flag = {s:sub(2, p), s:sub(p+1, #s)}
		end
		return flag
	end

	for _, arg in ipairs(arg_list) do
		if is_flag(arg) then
			flags[#flags+1] = make_flag(arg)
		else
			regular[#regular+1] = arg
		end
	end

	return flags, regular
end

return M
